// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhart.h for the primary calling header

#ifndef VERILATED_VHART___024ROOT_H_
#define VERILATED_VHART___024ROOT_H_  // guard

#include "verilated.h"


class Vhart__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhart___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rst,0,0);
    VL_OUT8(o_dmem_ren,0,0);
    VL_OUT8(o_dmem_wen,0,0);
    VL_OUT8(o_dmem_mask,3,0);
    VL_OUT8(o_retire_valid,0,0);
    VL_OUT8(o_retire_trap,0,0);
    VL_OUT8(o_retire_halt,0,0);
    VL_OUT8(o_retire_rs1_raddr,4,0);
    VL_OUT8(o_retire_rs2_raddr,4,0);
    VL_OUT8(o_retire_rd_waddr,4,0);
    CData/*0:0*/ hart__DOT__dmem_memb;
    CData/*0:0*/ hart__DOT__dmem_memh;
    CData/*0:0*/ hart__DOT__dmem_memu;
    CData/*0:0*/ hart__DOT__decoder__DOT__inst_branch;
    CData/*2:0*/ hart__DOT__decoder__DOT__alu_opsel;
    CData/*0:0*/ hart__DOT__decoder__DOT__alu_sub;
    CData/*0:0*/ hart__DOT__decoder__DOT__jump;
    CData/*3:0*/ hart__DOT__decoder__DOT__rd_sel;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_12;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUT(o_imem_raddr,31,0);
    VL_IN(i_imem_rdata,31,0);
    VL_OUT(o_dmem_addr,31,0);
    VL_OUT(o_dmem_wdata,31,0);
    VL_IN(i_dmem_rdata,31,0);
    VL_OUT(o_retire_inst,31,0);
    VL_OUT(o_retire_rs1_rdata,31,0);
    VL_OUT(o_retire_rs2_rdata,31,0);
    VL_OUT(o_retire_rd_wdata,31,0);
    VL_OUT(o_retire_pc,31,0);
    VL_OUT(o_retire_next_pc,31,0);
    IData/*31:0*/ hart__DOT__pc;
    IData/*31:0*/ hart__DOT__rd_wdata;
    IData/*31:0*/ hart__DOT__dmem_ext_mask;
    IData/*31:0*/ hart__DOT__decoder__DOT__immediate;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> hart__DOT__rf__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhart__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vhart___024root(Vhart__Syms* symsp, const char* namep);
    ~Vhart___024root();
    VL_UNCOPYABLE(Vhart___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
