#include <verilated.h>
#include "Vhart.h"

#include <array>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <vector>

struct RetireEvent {
    bool valid{};
    uint32_t inst{};
    bool trap{};
    bool halt{};
    uint8_t rs1_addr{}, rs2_addr{}, rd_addr{};
    uint32_t rs1_data{}, rs2_data{}, rd_data{};
    uint32_t pc{}, next_pc{};
};

struct DmemEvent {
    bool ren{};
    bool wen{};
    uint32_t addr{};
    uint32_t wdata{};
    uint8_t mask{};
    uint32_t rdata{};
};

struct ExpectedEvent {
    bool valid = true;
    uint32_t pc{};
    uint32_t inst{};
    uint32_t next_pc{};
    bool trap{};
    bool halt{};
    bool rs1_used{}, rs2_used{};
    uint8_t rs1_addr{}, rs2_addr{}, rd_addr{};
    uint32_t rs1_data{}, rs2_data{}, rd_data{};
    DmemEvent dmem{};
};

struct Mem {
    std::vector<uint8_t> bytes;
    explicit Mem(size_t n = 1 << 20) : bytes(n, 0) {}

    uint8_t read8(uint32_t addr) const {
        if (addr >= bytes.size()) return 0;
        return bytes[addr];
    }

    uint32_t read32(uint32_t addr) const {
        uint32_t a = addr & ~0x3u;
        return (uint32_t)read8(a) |
               ((uint32_t)read8(a + 1) << 8) |
               ((uint32_t)read8(a + 2) << 16) |
               ((uint32_t)read8(a + 3) << 24);
    }

    uint32_t read_masked32(uint32_t addr, uint8_t mask) const {
        uint32_t a = addr & ~0x3u;
        uint32_t out = 0;
        for (int i = 0; i < 4; i++) {
            if (mask & (1u << i)) out |= (uint32_t)read8(a + i) << (8 * i);
        }
        return out;
    }

    void write_masked32(uint32_t addr, uint32_t data, uint8_t mask) {
        uint32_t a = addr & ~0x3u;
        for (int i = 0; i < 4; i++) {
            if ((mask & (1u << i)) && a + i < bytes.size()) {
                bytes[a + i] = (data >> (8 * i)) & 0xff;
            }
        }
    }
};

struct RefState {
    uint32_t pc = 0;
    std::array<uint32_t, 32> x{};
    bool halted = false;
};

static uint32_t bits(uint32_t x, int hi, int lo) {
    return (x >> lo) & ((1u << (hi - lo + 1)) - 1u);
}

static uint32_t bit(uint32_t x, int n) {
    return (x >> n) & 1u;
}

static uint32_t sign_extend(uint32_t x, int width) {
    uint32_t m = 1u << (width - 1);
    return (x ^ m) - m;
}

static int32_t s32(uint32_t x) {
    return static_cast<int32_t>(x);
}

static std::string hex32(uint32_t x) {
    std::ostringstream os;
    os << "0x" << std::hex << std::setw(8) << std::setfill('0') << x;
    return os.str();
}

static uint32_t imm_i(uint32_t inst) {
    return sign_extend(bits(inst, 31, 20), 12);
}

static uint32_t imm_s(uint32_t inst) {
    return sign_extend((bits(inst, 31, 25) << 5) | bits(inst, 11, 7), 12);
}

static uint32_t imm_b(uint32_t inst) {
    uint32_t raw = (bit(inst, 31) << 12) |
                   (bit(inst, 7) << 11) |
                   (bits(inst, 30, 25) << 5) |
                   (bits(inst, 11, 8) << 1);
    return sign_extend(raw, 13);
}

static uint32_t imm_u(uint32_t inst) {
    return inst & 0xfffff000u;
}

static uint32_t imm_j(uint32_t inst) {
    uint32_t raw = (bit(inst, 31) << 20) |
                   (bits(inst, 19, 12) << 12) |
                   (bit(inst, 20) << 11) |
                   (bits(inst, 30, 21) << 1);
    return sign_extend(raw, 21);
}

static uint32_t load_value(uint32_t word, uint32_t addr, uint8_t mask, uint32_t funct3) {
    uint32_t shift = (addr & 0x3u) * 8;
    uint32_t lane = word >> shift;

    switch (funct3) {
        case 0x0: return sign_extend(lane & 0xffu, 8);   // lb
        case 0x1: return sign_extend(lane & 0xffffu, 16); // lh
        case 0x2: return word;                            // lw
        case 0x4: return lane & 0xffu;                    // lbu
        case 0x5: return lane & 0xffffu;                  // lhu
        default:  (void)mask; return 0;
    }
}

static uint8_t mem_mask(uint32_t addr, uint32_t funct3) {
    uint32_t lane = addr & 0x3u;
    switch (funct3 & 0x3u) {
        case 0x0: return 1u << lane;
        case 0x1: return 0x3u << (lane & 0x2u);
        case 0x2: return 0xfu;
        default:  return 0;
    }
}

static uint32_t store_wdata(uint32_t rs2, uint32_t addr, uint32_t funct3) {
    uint32_t lane = addr & 0x3u;
    switch (funct3 & 0x3u) {
        case 0x0: return (rs2 & 0xffu) << (lane * 8);
        case 0x1: return (rs2 & 0xffffu) << ((lane & 0x2u) * 8);
        case 0x2: return rs2;
        default:  return 0;
    }
}

static ExpectedEvent ref_step(RefState& s, const Mem& imem, const Mem& dmem) {
    ExpectedEvent e;
    e.pc = s.pc;
    e.inst = imem.read32(s.pc);
    e.next_pc = s.pc + 4;

    uint32_t inst = e.inst;
    uint32_t opcode = bits(inst, 6, 0);
    uint32_t funct3 = bits(inst, 14, 12);
    uint32_t funct7 = bits(inst, 31, 25);
    uint8_t rd = bits(inst, 11, 7);
    uint8_t rs1 = bits(inst, 19, 15);
    uint8_t rs2 = bits(inst, 24, 20);

    auto use_rs1 = [&]() {
        e.rs1_used = true;
        e.rs1_addr = rs1;
        e.rs1_data = s.x[rs1];
        return s.x[rs1];
    };
    auto use_rs2 = [&]() {
        e.rs2_used = true;
        e.rs2_addr = rs2;
        e.rs2_data = s.x[rs2];
        return s.x[rs2];
    };
    auto write_rd = [&](uint32_t value) {
        e.rd_addr = rd;
        e.rd_data = value;
        if (rd != 0) s.x[rd] = value;
    };
    auto illegal = [&]() {
        e.trap = true;
        e.next_pc = s.pc + 4;
        s.halted = true;
    };

    if (s.pc & 0x3u) {
        illegal();
    } else if (inst == 0x00100073u) {
        e.halt = true;
        s.halted = true;
    } else {
        switch (opcode) {
            case 0x37: // lui
                write_rd(imm_u(inst));
                break;
            case 0x17: // auipc
                write_rd(s.pc + imm_u(inst));
                break;
            case 0x6f: // jal
                write_rd(s.pc + 4);
                e.next_pc = s.pc + imm_j(inst);
                break;
            case 0x67: { // jalr
                if (funct3 != 0) {
                    illegal();
                    break;
                }
                uint32_t a = use_rs1();
                write_rd(s.pc + 4);
                e.next_pc = (a + imm_i(inst)) & ~1u;
                break;
            }
            case 0x63: { // branch
                uint32_t a = use_rs1();
                uint32_t b = use_rs2();
                bool take = false;
                switch (funct3) {
                    case 0x0: take = a == b; break;
                    case 0x1: take = a != b; break;
                    case 0x4: take = s32(a) < s32(b); break;
                    case 0x5: take = s32(a) >= s32(b); break;
                    case 0x6: take = a < b; break;
                    case 0x7: take = a >= b; break;
                    default: illegal(); break;
                }
                if (!e.trap && take) e.next_pc = s.pc + imm_b(inst);
                break;
            }
            case 0x03: { // load
                uint32_t a = use_rs1() + imm_i(inst);
                uint8_t mask = mem_mask(a, funct3);
                bool aligned = (funct3 == 0x0 || funct3 == 0x4) ||
                               ((funct3 == 0x1 || funct3 == 0x5) && ((a & 0x1u) == 0)) ||
                               (funct3 == 0x2 && ((a & 0x3u) == 0));
                bool legal = funct3 == 0x0 || funct3 == 0x1 || funct3 == 0x2 ||
                             funct3 == 0x4 || funct3 == 0x5;
                if (!legal || !aligned) {
                    illegal();
                    break;
                }
                e.dmem.ren = true;
                e.dmem.addr = a & ~0x3u;
                e.dmem.mask = mask;
                e.dmem.rdata = dmem.read_masked32(a, mask);
                write_rd(load_value(e.dmem.rdata, a, mask, funct3));
                break;
            }
            case 0x23: { // store
                uint32_t base = use_rs1();
                uint32_t data = use_rs2();
                uint32_t a = base + imm_s(inst);
                uint8_t mask = mem_mask(a, funct3);
                bool aligned = (funct3 == 0x0) ||
                               (funct3 == 0x1 && ((a & 0x1u) == 0)) ||
                               (funct3 == 0x2 && ((a & 0x3u) == 0));
                bool legal = funct3 == 0x0 || funct3 == 0x1 || funct3 == 0x2;
                if (!legal || !aligned) {
                    illegal();
                    break;
                }
                e.dmem.wen = true;
                e.dmem.addr = a & ~0x3u;
                e.dmem.mask = mask;
                e.dmem.wdata = store_wdata(data, a, funct3);
                break;
            }
            case 0x13: { // op-imm
                uint32_t a = use_rs1();
                uint32_t imm = imm_i(inst);
                uint32_t shamt = bits(inst, 24, 20);
                switch (funct3) {
                    case 0x0: write_rd(a + imm); break;
                    case 0x2: write_rd(s32(a) < s32(imm)); break;
                    case 0x3: write_rd(a < imm); break;
                    case 0x4: write_rd(a ^ imm); break;
                    case 0x6: write_rd(a | imm); break;
                    case 0x7: write_rd(a & imm); break;
                    case 0x1:
                        if (funct7 == 0x00) write_rd(a << shamt);
                        else illegal();
                        break;
                    case 0x5:
                        if (funct7 == 0x00) write_rd(a >> shamt);
                        else if (funct7 == 0x20) write_rd((uint32_t)(s32(a) >> shamt));
                        else illegal();
                        break;
                    default: illegal(); break;
                }
                break;
            }
            case 0x33: { // op
                uint32_t a = use_rs1();
                uint32_t b = use_rs2();
                switch ((funct7 << 3) | funct3) {
                    case 0x000: write_rd(a + b); break;                    // add
                    case 0x100: write_rd(a - b); break;                    // sub
                    case 0x001: write_rd(a << (b & 0x1f)); break;          // sll
                    case 0x002: write_rd(s32(a) < s32(b)); break;          // slt
                    case 0x003: write_rd(a < b); break;                    // sltu
                    case 0x004: write_rd(a ^ b); break;                    // xor
                    case 0x005: write_rd(a >> (b & 0x1f)); break;          // srl
                    case 0x105: write_rd((uint32_t)(s32(a) >> (b & 0x1f))); break; // sra
                    case 0x006: write_rd(a | b); break;                    // or
                    case 0x007: write_rd(a & b); break;                    // and
                    default: illegal(); break;
                }
                break;
            }
            case 0x0f: // fence is a no-op in this harness
                if (funct3 != 0) illegal();
                break;
            case 0x73: // system: only ebreak is the intended halt
                illegal();
                break;
            default:
                illegal();
                break;
        }
    }

    if (!e.trap && !e.halt && (e.next_pc & 0x3u)) {
        e.trap = true;
        s.halted = true;
    }

    s.pc = e.next_pc;
    s.x[0] = 0;
    return e;
}

static RetireEvent sample_retire(Vhart* d) {
    RetireEvent r;
    r.valid    = d->o_retire_valid;
    r.inst     = d->o_retire_inst;
    r.trap     = d->o_retire_trap;
    r.halt     = d->o_retire_halt;
    r.rs1_addr = d->o_retire_rs1_raddr;
    r.rs2_addr = d->o_retire_rs2_raddr;
    r.rd_addr  = d->o_retire_rd_waddr;
    r.rs1_data = d->o_retire_rs1_rdata;
    r.rs2_data = d->o_retire_rs2_rdata;
    r.rd_data  = d->o_retire_rd_wdata;
    r.pc       = d->o_retire_pc;
    r.next_pc  = d->o_retire_next_pc;
    return r;
}

static DmemEvent sample_dmem(Vhart* d) {
    DmemEvent m;
    m.ren = d->o_dmem_ren;
    m.wen = d->o_dmem_wen;
    m.addr = d->o_dmem_addr;
    m.wdata = d->o_dmem_wdata;
    m.mask = d->o_dmem_mask & 0xfu;
    m.rdata = d->i_dmem_rdata;
    return m;
}

static void drive_memory(Vhart* dut, const Mem& imem, const Mem& dmem) {
    dut->i_imem_rdata = imem.read32(dut->o_imem_raddr);
    if (dut->o_dmem_ren) {
        dut->i_dmem_rdata = dmem.read_masked32(dut->o_dmem_addr, dut->o_dmem_mask & 0xfu);
    } else {
        dut->i_dmem_rdata = 0;
    }
}

static void settle(Vhart* dut, const Mem& imem, const Mem& dmem) {
    for (int i = 0; i < 3; i++) {
        dut->eval();
        drive_memory(dut, imem, dmem);
    }
    dut->eval();
}

static void rising_edge(Vhart* dut) {
    dut->i_clk = 1;
    dut->eval();
    dut->i_clk = 0;
    dut->eval();
}

static uint32_t enc_i(int32_t imm, uint32_t rs1, uint32_t funct3, uint32_t rd, uint32_t opcode) {
    return ((uint32_t)imm & 0xfffu) << 20 | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode;
}

static uint32_t enc_r(uint32_t funct7, uint32_t rs2, uint32_t rs1, uint32_t funct3, uint32_t rd) {
    return (funct7 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | 0x33u;
}

static uint32_t enc_s(int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t funct3) {
    uint32_t u = (uint32_t)imm & 0xfffu;
    return (bits(u, 11, 5) << 25) | (rs2 << 20) | (rs1 << 15) |
           (funct3 << 12) | (bits(u, 4, 0) << 7) | 0x23u;
}

static uint32_t enc_b(int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t funct3) {
    uint32_t u = (uint32_t)imm & 0x1fffu;
    return (bit(u, 12) << 31) | (bits(u, 10, 5) << 25) | (rs2 << 20) |
           (rs1 << 15) | (funct3 << 12) | (bits(u, 4, 1) << 8) |
           (bit(u, 11) << 7) | 0x63u;
}

static uint32_t enc_u(uint32_t imm20, uint32_t rd, uint32_t opcode) {
    return (imm20 << 12) | (rd << 7) | opcode;
}

static uint32_t enc_j(int32_t imm, uint32_t rd) {
    uint32_t u = (uint32_t)imm & 0x1fffffu;
    return (bit(u, 20) << 31) | (bits(u, 10, 1) << 21) | (bit(u, 11) << 20) |
           (bits(u, 19, 12) << 12) | (rd << 7) | 0x6fu;
}

static std::vector<uint32_t> gen_program(uint32_t seed) {
    std::mt19937 rng(seed);
    std::vector<uint32_t> p;

    p.push_back(enc_i(5, 0, 0x0, 1, 0x13));          // addi x1, x0, 5
    p.push_back(enc_i(123, 0, 0x0, 0, 0x13));        // addi x0, x0, 123
    p.push_back(enc_i(1, 0, 0x0, 23, 0x13));         // addi x23, x0, 1
    p.push_back(enc_i(-3, 0, 0x0, 2, 0x13));         // addi x2, x0, -3
    p.push_back(enc_r(0x00, 2, 1, 0x0, 3));          // add x3, x1, x2
    p.push_back(enc_r(0x20, 2, 1, 0x0, 4));          // sub x4, x1, x2
    p.push_back(enc_i(1, 3, 0x1, 5, 0x13));          // slli x5, x3, 1
    p.push_back(enc_i(0x40f, 4, 0x7, 6, 0x13));      // andi x6, x4, 0x40f
    p.push_back(enc_i(128, 0, 0x0, 10, 0x13));       // addi x10, x0, 128
    p.push_back(enc_s(0, 4, 10, 0x2));               // sw x4, 0(x10)
    p.push_back(enc_i(0, 10, 0x2, 11, 0x03));        // lw x11, 0(x10)
    p.push_back(enc_s(4, 1, 10, 0x0));               // sb x1, 4(x10)
    p.push_back(enc_i(4, 10, 0x4, 12, 0x03));        // lbu x12, 4(x10)
    p.push_back(enc_b(8, 12, 1, 0x0));               // beq x12, x1, +8
    p.push_back(enc_i(99, 0, 0x0, 31, 0x13));        // skipped on correct branch
    p.push_back(enc_u(0x12345, 13, 0x37));           // lui x13, 0x12345
    p.push_back(enc_i(7, 13, 0x6, 14, 0x13));        // ori x14, x13, 7

    for (int i = 0; i < 32; i++) {
        uint32_t rd = 15 + (rng() % 8);
        uint32_t rs1 = rng() % 15;
        int32_t imm = (int32_t)(rng() % 63) - 31;
        p.push_back(enc_i(imm, rs1, 0x0, rd, 0x13));
    }

    p.push_back(enc_j(8, 20));                       // jal x20, +8
    p.push_back(enc_i(77, 0, 0x0, 31, 0x13));        // skipped
    p.push_back(enc_i(1, 20, 0x0, 21, 0x13));        // addi x21, x20, 1
    p.push_back(0x00100073u);                        // ebreak
    return p;
}

static void load_imem(Mem& imem, const std::vector<uint32_t>& prog, uint32_t base = 0) {
    for (size_t i = 0; i < prog.size(); i++) {
        uint32_t a = base + (uint32_t)(i * 4);
        uint32_t w = prog[i];
        imem.write_masked32(a, w, 0xf);
    }
}

static bool same_u32(uint32_t got, uint32_t exp) {
    return got == exp;
}

static bool compare(uint32_t cycle, const RetireEvent& got, const DmemEvent& gm,
                    const ExpectedEvent& exp, std::string& reason) {
    auto fail = [&](const std::string& what, uint32_t g, uint32_t e) {
        std::ostringstream os;
        os << what << " at cycle " << cycle;
        if (std::getenv("HART_CHECKER_VERBOSE")) {
            os << " got " << hex32(g) << " expected " << hex32(e);
        }
        reason = os.str();
        return false;
    };

    if (!got.valid) {
        reason = "missing retire at cycle " + std::to_string(cycle);
        return false;
    }
    if (got.pc != exp.pc) return fail("pc mismatch", got.pc, exp.pc);
    if (got.inst != exp.inst) return fail("instruction mismatch", got.inst, exp.inst);
    if (got.next_pc != exp.next_pc) return fail("next_pc mismatch", got.next_pc, exp.next_pc);
    if (got.trap != exp.trap) return fail("trap mismatch", got.trap, exp.trap);
    if (got.halt != exp.halt) return fail("halt mismatch", got.halt, exp.halt);

    if (exp.rs1_used && got.rs1_addr != exp.rs1_addr) return fail("rs1 address mismatch", got.rs1_addr, exp.rs1_addr);
    if (exp.rs2_used && got.rs2_addr != exp.rs2_addr) return fail("rs2 address mismatch", got.rs2_addr, exp.rs2_addr);
    if (exp.rs1_used && got.rs1_data != exp.rs1_data) return fail("rs1 data mismatch", got.rs1_data, exp.rs1_data);
    if (exp.rs2_used && got.rs2_data != exp.rs2_data) return fail("rs2 data mismatch", got.rs2_data, exp.rs2_data);
    if (got.rd_addr != exp.rd_addr) return fail("rd address mismatch", got.rd_addr, exp.rd_addr);
    if (exp.rd_addr != 0 && !same_u32(got.rd_data, exp.rd_data)) {
        return fail("rd data mismatch", got.rd_data, exp.rd_data);
    }
    if (got.rd_addr == 0 && got.rd_data != 0 && exp.rd_addr != 0) {
        return fail("x0 violation", got.rd_data, 0);
    }

    if (gm.ren && gm.wen) {
        reason = "dmem read/write both asserted at cycle " + std::to_string(cycle);
        return false;
    }
    if (gm.ren != exp.dmem.ren) return fail("dmem read enable mismatch", gm.ren, exp.dmem.ren);
    if (gm.wen != exp.dmem.wen) return fail("dmem write enable mismatch", gm.wen, exp.dmem.wen);
    if ((gm.ren || gm.wen) && gm.addr != exp.dmem.addr) return fail("dmem address mismatch", gm.addr, exp.dmem.addr);
    if ((gm.ren || gm.wen) && gm.mask != exp.dmem.mask) return fail("dmem mask mismatch", gm.mask, exp.dmem.mask);
    if (gm.wen && gm.wdata != exp.dmem.wdata) return fail("store data mismatch", gm.wdata, exp.dmem.wdata);
    if (gm.ren && gm.rdata != exp.dmem.rdata) return fail("load memory response mismatch", gm.rdata, exp.dmem.rdata);
    return true;
}

int main(int argc, char** argv) {
    uint32_t seed = 12345;
    if (argc >= 2) seed = (uint32_t)std::stoul(argv[1]);

    Verilated::commandArgs(argc, argv);
    auto dut = std::make_unique<Vhart>();

    Mem imem(1 << 20), dmem(1 << 20);
    auto prog = gen_program(seed);
    load_imem(imem, prog, 0);

    RefState ref{};
    constexpr uint32_t RESET_CYCLES = 2;
    constexpr uint32_t MAX_CYCLES = 40000;

    dut->i_clk = 0;
    dut->i_rst = 1;
    dut->i_imem_rdata = 0;
    dut->i_dmem_rdata = 0;

    for (uint32_t i = 0; i < RESET_CYCLES; i++) {
        settle(dut.get(), imem, dmem);
        rising_edge(dut.get());
    }
    dut->i_rst = 0;

    bool pass = true;
    std::string fail_reason = "ok";
    uint32_t cycles = 0;

    for (; cycles < MAX_CYCLES; cycles++) {
        settle(dut.get(), imem, dmem);

        ExpectedEvent exp = ref_step(ref, imem, dmem);
        RetireEvent got = sample_retire(dut.get());
        DmemEvent gm = sample_dmem(dut.get());

        if (!compare(cycles, got, gm, exp, fail_reason)) {
            pass = false;
            break;
        }

        if (gm.wen) dmem.write_masked32(gm.addr, gm.wdata, gm.mask);
        rising_edge(dut.get());

        if (got.halt || got.trap) break;
    }

    if (cycles == MAX_CYCLES) {
        pass = false;
        fail_reason = "timeout";
    }

    std::ofstream("result.json")
        << "{\n"
        << "  \"pass\": " << (pass ? "true" : "false") << ",\n"
        << "  \"seed\": " << seed << ",\n"
        << "  \"cycles\": " << cycles << ",\n"
        << "  \"reason\": \"" << fail_reason << "\"\n"
        << "}\n";

    std::cout << (pass ? "PASSED\n" : "FAILED: " + fail_reason + "\n");
    return pass ? 0 : 1;
}
