// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhart__pch.h"

//============================================================
// Constructors

Vhart::Vhart(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhart__Syms(contextp(), _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , i_rst{vlSymsp->TOP.i_rst}
    , o_dmem_ren{vlSymsp->TOP.o_dmem_ren}
    , o_dmem_wen{vlSymsp->TOP.o_dmem_wen}
    , o_dmem_mask{vlSymsp->TOP.o_dmem_mask}
    , o_retire_valid{vlSymsp->TOP.o_retire_valid}
    , o_retire_trap{vlSymsp->TOP.o_retire_trap}
    , o_retire_halt{vlSymsp->TOP.o_retire_halt}
    , o_retire_rs1_raddr{vlSymsp->TOP.o_retire_rs1_raddr}
    , o_retire_rs2_raddr{vlSymsp->TOP.o_retire_rs2_raddr}
    , o_retire_rd_waddr{vlSymsp->TOP.o_retire_rd_waddr}
    , o_imem_raddr{vlSymsp->TOP.o_imem_raddr}
    , i_imem_rdata{vlSymsp->TOP.i_imem_rdata}
    , o_dmem_addr{vlSymsp->TOP.o_dmem_addr}
    , o_dmem_wdata{vlSymsp->TOP.o_dmem_wdata}
    , i_dmem_rdata{vlSymsp->TOP.i_dmem_rdata}
    , o_retire_inst{vlSymsp->TOP.o_retire_inst}
    , o_retire_rs1_rdata{vlSymsp->TOP.o_retire_rs1_rdata}
    , o_retire_rs2_rdata{vlSymsp->TOP.o_retire_rs2_rdata}
    , o_retire_rd_wdata{vlSymsp->TOP.o_retire_rd_wdata}
    , o_retire_pc{vlSymsp->TOP.o_retire_pc}
    , o_retire_next_pc{vlSymsp->TOP.o_retire_next_pc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhart::Vhart(const char* _vcname__)
    : Vhart(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhart::~Vhart() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhart___024root___eval_debug_assertions(Vhart___024root* vlSelf);
#endif  // VL_DEBUG
void Vhart___024root___eval_static(Vhart___024root* vlSelf);
void Vhart___024root___eval_initial(Vhart___024root* vlSelf);
void Vhart___024root___eval_settle(Vhart___024root* vlSelf);
void Vhart___024root___eval(Vhart___024root* vlSelf);

void Vhart::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhart::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhart___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhart___024root___eval_static(&(vlSymsp->TOP));
        Vhart___024root___eval_initial(&(vlSymsp->TOP));
        Vhart___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhart___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhart::eventsPending() { return false; }

uint64_t Vhart::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vhart::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhart___024root___eval_final(Vhart___024root* vlSelf);

VL_ATTR_COLD void Vhart::final() {
    contextp()->executingFinal(true);
    Vhart___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhart::hierName() const { return vlSymsp->name(); }
const char* Vhart::modelName() const { return "Vhart"; }
unsigned Vhart::threads() const { return 1; }
void Vhart::prepareClone() const { contextp()->prepareClone(); }
void Vhart::atClone() const {
    contextp()->threadPoolpOnClone();
}
