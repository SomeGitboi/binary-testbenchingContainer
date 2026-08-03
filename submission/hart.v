`default_nettype none

module hart #(
    // After reset, the program counter (PC) should be initialized to this
    // address and start executing instructions from there.
    parameter RESET_ADDR = 32'h00000000
) (
    // Global clock.
    input  wire        i_clk,
    // Synchronous active-high reset.
    input  wire        i_rst,
    // Instruction fetch goes through a read only instruction memory (imem)
    // port. The port accepts a 32-bit address (e.g. from the program counter)
    // per cycle and combinationally returns a 32-bit instruction word. This
    // is not representative of a realistic memory interface; it has been
    // modeled as more similar to a DFF or SRAM to simplify phase 3. In
    // later phases, you will replace this with a more realistic memory.
    //
    // 32-bit read address for the instruction memory. This is expected to be
    // 4 byte aligned - that is, the two LSBs should be zero.
    output wire [31:0] o_imem_raddr,
    // Instruction word fetched from memory, available on the same cycle.
    input  wire [31:0] i_imem_rdata,
    // Data memory accesses go through a separate read/write data memory (dmem)
    // that is shared between read (load) and write (stored). The port accepts
    // a 32-bit address, read or write enable, and mask (explained below) each
    // cycle. Reads are combinational - values are available immediately after
    // updating the address and asserting read enable. Writes occur on (and
    // are visible at) the next clock edge.
    //
    // Read/write address for the data memory. This should be 32-bit aligned
    // (i.e. the two LSB should be zero). See `o_dmem_mask` for how to perform
    // half-word and byte accesses at unaligned addresses.
    output wire [31:0] o_dmem_addr,
    // When asserted, the memory will perform a read at the aligned address
    // specified by `i_addr` and return the 32-bit word at that address
    // immediately (i.e. combinationally). It is illegal to assert this and
    // `o_dmem_wen` on the same cycle.
    output wire        o_dmem_ren,
    // When asserted, the memory will perform a write to the aligned address
    // `o_dmem_addr`. When asserted, the memory will write the bytes in
    // `o_dmem_wdata` (specified by the mask) to memory at the specified
    // address on the next rising clock edge. It is illegal to assert this and
    // `o_dmem_ren` on the same cycle.
    output wire        o_dmem_wen,
    // The 32-bit word to write to memory when `o_dmem_wen` is asserted. When
    // write enable is asserted, the byte lanes specified by the mask will be
    // written to the memory word at the aligned address at the next rising
    // clock edge. The other byte lanes of the word will be unaffected.
    output wire [31:0] o_dmem_wdata,
    // The dmem interface expects word (32 bit) aligned addresses. However,
    // WISC-25 supports byte and half-word loads and stores at unaligned and
    // 16-bit aligned addresses, respectively. To support this, the access
    // mask specifies which bytes within the 32-bit word are actually read
    // from or written to memory.
    //
    // To perform a half-word read at address 0x00001002, align `o_dmem_addr`
    // to 0x00001000, assert `o_dmem_ren`, and set the mask to 0b1100 to
    // indicate that only the upper two bytes should be read. Only the upper
    // two bytes of `i_dmem_rdata` can be assumed to have valid data; to
    // calculate the final value of the `lh[u]` instruction, shift the rdata
    // word right by 16 bits and sign/zero extend as appropriate.
    //
    // To perform a byte write at address 0x00002003, align `o_dmem_addr` to
    // `0x00002003`, assert `o_dmem_wen`, and set the mask to 0b1000 to
    // indicate that only the upper byte should be written. On the next clock
    // cycle, the upper byte of `o_dmem_wdata` will be written to memory, with
    // the other three bytes of the aligned word unaffected. Remember to shift
    // the value of the `sb` instruction left by 24 bits to place it in the
    // appropriate byte lane.
    output wire [ 3:0] o_dmem_mask,
    // The 32-bit word read from data memory. When `o_dmem_ren` is asserted,
    // this will immediately reflect the contents of memory at the specified
    // address, for the bytes enabled by the mask. When read enable is not
    // asserted, or for bytes not set in the mask, the value is undefined.
    input  wire [31:0] i_dmem_rdata,
    // The output `retire` interface is used to signal to the testbench that
    // the CPU has completed and retired an instruction. A single cycle
    // implementation will assert this every cycle; however, a pipelined
    // implementation that needs to stall (due to internal hazards or waiting
    // on memory accesses) will not assert the signal on cycles where the
    // instruction in the writeback stage is not retiring.
    //
    // Asserted when an instruction is being retired this cycle. If this is
    // not asserted, the other retire signals are ignored and may be left invalid.
    output wire        o_retire_valid,
    // The 32 bit instruction word of the instrution being retired. This
    // should be the unmodified instruction word fetched from instruction
    // memory.
    output wire [31:0] o_retire_inst,
    // Asserted if the instruction produced a trap, due to an illegal
    // instruction, unaligned data memory access, or unaligned instruction
    // address on a taken branch or jump.
    output wire        o_retire_trap,
    // Asserted if the instruction is an `ebreak` instruction used to halt the
    // processor. This is used for debugging and testing purposes to end
    // a program.
    output wire        o_retire_halt,
    // The first register address read by the instruction being retired. If
    // the instruction does not read from a register (like `lui`), this
    // should be 5'd0.
    output wire [ 4:0] o_retire_rs1_raddr,
    // The second register address read by the instruction being retired. If
    // the instruction does not read from a second register (like `addi`), this
    // should be 5'd0.
    output wire [ 4:0] o_retire_rs2_raddr,
    // The first source register data read from the register file (in the
    // decode stage) for the instruction being retired. If rs1 is 5'd0, this
    // should also be 32'd0.
    output wire [31:0] o_retire_rs1_rdata,
    // The second source register data read from the register file (in the
    // decode stage) for the instruction being retired. If rs2 is 5'd0, this
    // should also be 32'd0.
    output wire [31:0] o_retire_rs2_rdata,
    // The destination register address written by the instruction being
    // retired. If the instruction does not write to a register (like `sw`),
    // this should be 5'd0.
    output wire [ 4:0] o_retire_rd_waddr,
    // The destination register data written to the register file in the
    // writeback stage by this instruction. If rd is 5'd0, this field is
    // ignored and can be treated as a don't care.
    output wire [31:0] o_retire_rd_wdata,
    // The current program counter of the instruction being retired - i.e.
    // the instruction memory address that the instruction was fetched from.
    output wire [31:0] o_retire_pc,
    // the next program counter after the instruction is retired. For most
    // instructions, this is `o_retire_pc + 4`, but must be the branch or jump
    // target for *taken* branches and jumps.
    output wire [31:0] o_retire_next_pc

`ifdef RISCV_FORMAL
    ,`RVFI_OUTPUTS,
`endif
);
    // Reference implementation, do not distribute.

    // Because this is a single cycle implementation, there is a single source
    // of truth for the program counter (PC). The PC is updated on every cycle,
    // either by incrementing by 4 or jumping to a new address for branches or
    // jumps. The next PC is also used to read from instruction memory.
    reg  [31:0] pc;
    wire [31:0] next_pc;
    always @(posedge i_clk) begin
        if (i_rst)
            pc <= RESET_ADDR;
        else
            pc <= next_pc;
    end

    // Read from the instruction memory at the next PC address, which will
    // arrive after the clock in time to be used in the next cycle.
    assign o_imem_raddr = pc;
    wire [31:0] inst = i_imem_rdata;

    // The register file is effectively an SRAM with two read ports and
    // 1 write port. It is read from here based on the instruction decoder
    // output (source registers) and written to in the writeback "stage".
    wire [ 4:0] rs1_addr, rs2_addr, rd_addr;
    wire [31:0] rs1_rdata, rs2_rdata;
    reg  [31:0] rd_wdata;
    rf #(.BYPASS_EN(0)) rf (
        .i_clk       (i_clk    ),
        .i_rst       (i_rst    ),
        .i_rs1_raddr (rs1_addr ),
        .o_rs1_rdata (rs1_rdata),
        .i_rs2_raddr (rs2_addr ),
        .o_rs2_rdata (rs2_rdata),
        .i_rd_waddr  (rd_addr  ),
        .i_rd_wdata  (rd_wdata )
    );

    // The instruction decoder is responsible for decoding the source
    // registers and immediate as well as generating control signals.
    wire        legal, halt;
    wire [31:0] immediate;
    wire        op1_sel, op2_sel;
    wire [ 2:0] alu_opsel;
    wire        alu_sub, alu_unsigned, alu_arith;
    wire        branch, jump;
    wire        branch_equal, branch_unsigned, branch_invert;
    wire        dmem_ren, dmem_wen;
    wire [ 1:0] dmem_align;
    wire        dmem_memb, dmem_memh, dmem_memw, dmem_memu;
    wire [ 3:0] rd_sel;
    wire        pc_sel;
    decoder decoder (
        .i_inst(inst),
        .o_legal(legal),
        .o_halt(halt),
        .o_rs1(rs1_addr),
        .o_rs2(rs2_addr),
        .o_rd(rd_addr),
        .o_op1_sel(op1_sel),
        .o_op2_sel(op2_sel),
        .o_immediate(immediate),
        .o_alu_opsel(alu_opsel),
        .o_alu_sub(alu_sub),
        .o_alu_unsigned(alu_unsigned),
        .o_alu_arith(alu_arith),
        .o_branch(branch),
        .o_jump(jump),
        .o_branch_equal(branch_equal),
        .o_branch_unsigned(branch_unsigned),
        .o_branch_invert(branch_invert),
        .o_dmem_ren(dmem_ren),
        .o_dmem_wen(dmem_wen),
        .o_dmem_align(dmem_align),
        .o_dmem_memb(dmem_memb),
        .o_dmem_memh(dmem_memh),
        .o_dmem_memw(dmem_memw),
        .o_dmem_memu(dmem_memu),
        .o_rd_sel(rd_sel),
        .o_pc_sel(pc_sel)
    );

    // The ALU is the core unit in this datapath and performs almost all
    // arithmetic operations including branch comparisons. The only exceptions
    // are the adders required for branch target calculation and PC increment.
    wire [31:0] alu_op1 = op1_sel ? pc        : rs1_rdata;
    wire [31:0] alu_op2 = op2_sel ? immediate : rs2_rdata;
    wire [31:0] alu_result;
    wire        eq, slt;
    alu alu (
        .i_opsel(alu_opsel),
        .i_sub(alu_sub),
        .i_unsigned(alu_unsigned),
        .i_arith(alu_arith),
        .i_op1(alu_op1),
        .i_op2(alu_op2),
        .o_result(alu_result),
        .o_eq(eq),
        .o_slt(slt)
    );

    // Branch comparison is done by the ALU but the result needs to be
    // combined to determine if the branch should be taken, which is also done
    // in the "EX" stage.
    wire cond  = (branch_equal ? eq : slt) ^ branch_invert;
    wire taken = (branch & cond) | jump;

    wire [31:0] dmem_addr = alu_result;
    wire [ 1:0] dmem_lsb  = dmem_addr[1:0];
    wire [31:0] dmem_addr_aligned = {dmem_addr[31:2], 2'b00};

    wire half0 = dmem_memh & ~dmem_lsb[1];
    wire half1 = dmem_memh &  dmem_lsb[1];
    wire byte0 = dmem_memb & ~dmem_lsb[1] & ~dmem_lsb[0];
    wire byte1 = dmem_memb & ~dmem_lsb[1] &  dmem_lsb[0];
    wire byte2 = dmem_memb &  dmem_lsb[1] & ~dmem_lsb[0];
    wire byte3 = dmem_memb &  dmem_lsb[1] &  dmem_lsb[0];

    wire [ 3:0] dmem_mask;
    assign dmem_mask[3] = dmem_memw | half1 | byte3;
    assign dmem_mask[2] = dmem_memw | half1 | byte2;
    assign dmem_mask[1] = dmem_memw | half0 | byte1;
    assign dmem_mask[0] = dmem_memw | half0 | byte0;

    wire [31:0] dmem_wdataw = rs2_rdata;
    wire [31:0] dmem_wdatah = dmem_lsb[1] ? {dmem_wdataw[15:0], 16'h0} : dmem_wdataw;
    wire [31:0] dmem_wdatab = dmem_lsb[0] ? {dmem_wdatah[24:0],  8'h0} : dmem_wdatah;
    wire [31:0] dmem_wdata  = dmem_wdatab;

    wire [31:0] dmem_rdataw = i_dmem_rdata;
    wire [31:0] dmem_rdatah = dmem_lsb[1] ? {16'h0, dmem_rdataw[31:16]} : dmem_rdataw;
    wire [31:0] dmem_rdatab = dmem_lsb[0] ? { 8'h0, dmem_rdatah[31: 8]} : dmem_rdatah;

    wire        dmem_sign    = dmem_memw ? dmem_rdataw[31] :
                               dmem_memh ? dmem_rdatah[15] :
                                           dmem_rdatab[ 7];
    wire [31:0] dmem_ext_mask = {{16{dmem_memw}}, {8{dmem_memh | dmem_memw}}, 8'hff};
    wire [31:0] dmem_sext     = {{32{dmem_sign & ~dmem_memu}}};
    wire [31:0] dmem_rdata    = (dmem_rdatab & dmem_ext_mask) | (dmem_sext & ~dmem_ext_mask);

    assign o_dmem_addr  = dmem_addr_aligned;
    assign o_dmem_ren   = dmem_ren;
    assign o_dmem_wen   = dmem_wen;
    assign o_dmem_wdata = dmem_wdata;
    assign o_dmem_mask  = dmem_mask;

    // The next PC is either the incremented PC or the branch/jump target.
    wire [31:0] branch_target = pc + immediate;
    wire [31:0] jalr_target   = {alu_result[31:1], 1'b0};
    wire [31:0] pc_jump       = pc_sel ? jalr_target : branch_target;
    wire [31:0] pc_increment  = pc + 32'd4;
    assign next_pc = taken ? pc_jump : pc_increment;

    // Trap if the instruction is illegal or next PC is not aligned to 4 bytes.
    wire pc_aligned  = next_pc[1:0] == 2'b00;
    wire mem_aligned = ~(dmem_ren | dmem_wen) | ((dmem_lsb & dmem_align) == 2'b00);
    wire trap        = ~i_rst & (~legal | ~pc_aligned | ~mem_aligned);

    always @(*) begin
        rd_wdata = 32'hx;

        case (1'b1)
            rd_sel[0]: rd_wdata = alu_result;
            rd_sel[1]: rd_wdata = immediate;
            rd_sel[2]: rd_wdata = pc_increment;
            rd_sel[3]: rd_wdata = dmem_rdata;
        endcase
    end

    assign o_retire_valid = 1'b1;
    assign o_retire_inst  = inst;
    assign o_retire_trap  = trap;
    assign o_retire_halt  = halt;

    assign o_retire_rs1_raddr = rs1_addr;
    assign o_retire_rs2_raddr = rs2_addr;
    assign o_retire_rs1_rdata = rs1_rdata;
    assign o_retire_rs2_rdata = rs2_rdata;

    assign o_retire_rd_waddr = rd_addr;
    assign o_retire_rd_wdata = rd_wdata;

    assign o_retire_pc       = pc;
    assign o_retire_next_pc  = next_pc;

`ifdef RISCV_FORMAL
    reg  [63:0] rvfm_order;
    always @(posedge i_clk) begin
        if (i_rst)
            rvfm_order <= 64'h0;
        else
            rvfm_order <= rvfm_order + 64'h1;
    end

    assign rvfi_valid = 1'b1;
    assign rvfi_order = rvfm_order;
    assign rvfi_insn  = inst;
    assign rvfi_trap  = trap;
    assign rvfi_halt  = trap | halt;
    assign rvfi_intr  = 1'b0;
    assign rvfi_mode  = 2'd3; // M-mode
    assign rvfi_ixl   = 2'd1; // XLEN = 32

    assign rvfi_rs1_addr  = rs1_addr;
    assign rvfi_rs2_addr  = rs2_addr;
    assign rvfi_rs1_rdata = rs1_rdata;
    assign rvfi_rs2_rdata = rs2_rdata;

    assign rvfi_rd_addr  = rd_addr;
    assign rvfi_rd_wdata = (rd_addr == 5'd0) ? 32'h0 : rd_wdata;

    assign rvfi_pc_rdata = pc;
    assign rvfi_pc_wdata = next_pc;

    assign rvfi_mem_addr = dmem_addr_aligned;
    assign rvfi_mem_rmask = dmem_mask & {4{dmem_ren}};
    assign rvfi_mem_wmask = dmem_mask & {4{dmem_wen}};
    assign rvfi_mem_rdata = i_dmem_rdata;
    assign rvfi_mem_wdata = o_dmem_wdata;
`endif
endmodule

`default_nettype wire
