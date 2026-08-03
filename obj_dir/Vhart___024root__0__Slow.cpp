// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhart.h for the primary calling header

#include "Vhart__pch.h"

VL_ATTR_COLD void Vhart___024root___eval_static(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_static\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__i_clk__0 = vlSelfRef.i_clk;
}

VL_ATTR_COLD void Vhart___024root___eval_initial(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_initial\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.o_retire_valid = 1U;
}

VL_ATTR_COLD void Vhart___024root___eval_initial__TOP(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_initial__TOP\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.o_retire_valid = 1U;
}

VL_ATTR_COLD void Vhart___024root___eval_final(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_final\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhart___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vhart___024root___eval_phase__stl(Vhart___024root* vlSelf);

VL_ATTR_COLD void Vhart___024root___eval_settle(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_settle\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vhart___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/boi/Projects/CompArchReup/Binarytesting/submission/hart.v", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vhart___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vhart___024root___eval_triggers_vec__stl(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_triggers_vec__stl\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vhart___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhart___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vhart___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vhart___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vhart___024root___stl_sequent__TOP__0(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___stl_sequent__TOP__0\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ hart__DOT__alu_op2;
    hart__DOT__alu_op2 = 0;
    IData/*31:0*/ hart__DOT__dmem_wdatah;
    hart__DOT__dmem_wdatah = 0;
    IData/*31:0*/ hart__DOT__dmem_rdatah;
    hart__DOT__dmem_rdatah = 0;
    IData/*31:0*/ hart__DOT__dmem_rdatab;
    hart__DOT__dmem_rdatab = 0;
    CData/*0:0*/ hart__DOT__decoder__DOT__inst_sltu;
    hart__DOT__decoder__DOT__inst_sltu = 0;
    CData/*0:0*/ hart__DOT__decoder__DOT__inst_sltiu;
    hart__DOT__decoder__DOT__inst_sltiu = 0;
    CData/*0:0*/ hart__DOT__decoder__DOT__format_i;
    hart__DOT__decoder__DOT__format_i = 0;
    CData/*0:0*/ hart__DOT__decoder__DOT__format_u;
    hart__DOT__decoder__DOT__format_u = 0;
    QData/*32:0*/ hart__DOT__alu__DOT__sum;
    hart__DOT__alu__DOT__sum = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__xor_result;
    hart__DOT__alu__DOT__xor_result = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__shift_result;
    hart__DOT__alu__DOT__shift_result = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__result;
    hart__DOT__alu__DOT__result = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sli;
    hart__DOT__alu__DOT__barrel__DOT__sli = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sl4;
    hart__DOT__alu__DOT__barrel__DOT__sl4 = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sl3;
    hart__DOT__alu__DOT__barrel__DOT__sl3 = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sl2;
    hart__DOT__alu__DOT__barrel__DOT__sl2 = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sl1;
    hart__DOT__alu__DOT__barrel__DOT__sl1 = 0;
    CData/*0:0*/ hart__DOT__alu__DOT__barrel__DOT__sign;
    hart__DOT__alu__DOT__barrel__DOT__sign = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sr4;
    hart__DOT__alu__DOT__barrel__DOT__sr4 = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sr3;
    hart__DOT__alu__DOT__barrel__DOT__sr3 = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sr2;
    hart__DOT__alu__DOT__barrel__DOT__sr2 = 0;
    IData/*31:0*/ hart__DOT__alu__DOT__barrel__DOT__sr1;
    hart__DOT__alu__DOT__barrel__DOT__sr1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_10;
    __VdfgRegularize_h6e95ff9d_0_10 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_11;
    __VdfgRegularize_h6e95ff9d_0_11 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_14;
    __VdfgRegularize_h6e95ff9d_0_14 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_15;
    __VdfgRegularize_h6e95ff9d_0_15 = 0;
    // Body
    vlSelfRef.o_imem_raddr = vlSelfRef.hart__DOT__pc;
    vlSelfRef.o_retire_inst = vlSelfRef.i_imem_rdata;
    vlSelfRef.o_retire_pc = vlSelfRef.hart__DOT__pc;
    vlSelfRef.o_retire_halt = (IData)((0x00100070U 
                                       == (0xfff0707cU 
                                           & vlSelfRef.i_imem_rdata)));
    vlSelfRef.hart__DOT__dmem_memb = ((0U == (7U & 
                                              (vlSelfRef.i_imem_rdata 
                                               >> 0x0000000cU))) 
                                      | (4U == (7U 
                                                & (vlSelfRef.i_imem_rdata 
                                                   >> 0x0000000cU))));
    __VdfgRegularize_h6e95ff9d_0_10 = (IData)((0x40005000U 
                                               == (0xfe007000U 
                                                   & vlSelfRef.i_imem_rdata)));
    vlSelfRef.hart__DOT__decoder__DOT__jump = ((0x19U 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.i_imem_rdata 
                                                    >> 2U))) 
                                               | (0x1bU 
                                                  == 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.i_imem_rdata 
                                                      >> 2U))));
    vlSelfRef.hart__DOT__dmem_memh = ((1U == (7U & 
                                              (vlSelfRef.i_imem_rdata 
                                               >> 0x0000000cU))) 
                                      | (5U == (7U 
                                                & (vlSelfRef.i_imem_rdata 
                                                   >> 0x0000000cU))));
    __VdfgRegularize_h6e95ff9d_0_11 = (IData)((0x40000000U 
                                               == (0xfe007000U 
                                                   & vlSelfRef.i_imem_rdata)));
    hart__DOT__decoder__DOT__inst_sltu = (IData)((0x00003030U 
                                                  == 
                                                  (0xfe00707cU 
                                                   & vlSelfRef.i_imem_rdata)));
    hart__DOT__decoder__DOT__inst_sltiu = (IData)((0x00003010U 
                                                   == 
                                                   (0x0000707cU 
                                                    & vlSelfRef.i_imem_rdata)));
    __VdfgRegularize_h6e95ff9d_0_4 = ((6U == (7U & 
                                              (vlSelfRef.i_imem_rdata 
                                               >> 0x0000000cU))) 
                                      | (7U == (7U 
                                                & (vlSelfRef.i_imem_rdata 
                                                   >> 0x0000000cU))));
    vlSelfRef.hart__DOT__dmem_memu = ((5U == (7U & 
                                              (vlSelfRef.i_imem_rdata 
                                               >> 0x0000000cU))) 
                                      | (4U == (7U 
                                                & (vlSelfRef.i_imem_rdata 
                                                   >> 0x0000000cU))));
    __VdfgRegularize_h6e95ff9d_0_3 = ((0U == (7U & 
                                              (vlSelfRef.i_imem_rdata 
                                               >> 0x0000000cU))) 
                                      | (1U == (7U 
                                                & (vlSelfRef.i_imem_rdata 
                                                   >> 0x0000000cU))));
    vlSelfRef.o_retire_rs1_raddr = (0x0000001fU & (vlSelfRef.i_imem_rdata 
                                                   >> 0x0000000fU));
    vlSelfRef.o_retire_rs2_raddr = (0x0000001fU & (vlSelfRef.i_imem_rdata 
                                                   >> 0x00000014U));
    hart__DOT__decoder__DOT__format_i = ((4U == (0x0000001fU 
                                                 & (vlSelfRef.i_imem_rdata 
                                                    >> 2U))) 
                                         | ((0U == 
                                             (0x0000001fU 
                                              & (vlSelfRef.i_imem_rdata 
                                                 >> 2U))) 
                                            | (0x19U 
                                               == (0x0000001fU 
                                                   & (vlSelfRef.i_imem_rdata 
                                                      >> 2U)))));
    hart__DOT__decoder__DOT__format_u = ((5U == (0x0000001fU 
                                                 & (vlSelfRef.i_imem_rdata 
                                                    >> 2U))) 
                                         | (0x0dU == 
                                            (0x0000001fU 
                                             & (vlSelfRef.i_imem_rdata 
                                                >> 2U))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((2U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.i_imem_rdata 
                                                      >> 0x0000000cU))) 
                                                 | (IData)(vlSelfRef.hart__DOT__dmem_memh));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5 = ((IData)(
                                                        ((0x00000030U 
                                                          == 
                                                          (0x0000007cU 
                                                           & vlSelfRef.i_imem_rdata)) 
                                                         & ((0U 
                                                             == 
                                                             (vlSelfRef.i_imem_rdata 
                                                              >> 0x00000019U)) 
                                                            | ((IData)(__VdfgRegularize_h6e95ff9d_0_10) 
                                                               | (IData)(__VdfgRegularize_h6e95ff9d_0_11))))) 
                                                | (IData)(
                                                          ((0x00000010U 
                                                            == 
                                                            (0x0000007cU 
                                                             & vlSelfRef.i_imem_rdata)) 
                                                           & ((IData)(__VdfgRegularize_h6e95ff9d_0_10) 
                                                              | ((~ (IData)(vlSelfRef.hart__DOT__dmem_memh)) 
                                                                 | ((0U 
                                                                     == 
                                                                     (vlSelfRef.i_imem_rdata 
                                                                      >> 0x00000019U)) 
                                                                    & (IData)(vlSelfRef.hart__DOT__dmem_memh)))))));
    vlSelfRef.hart__DOT__decoder__DOT__inst_branch 
        = (IData)(((0x00000060U == (0x0000007cU & vlSelfRef.i_imem_rdata)) 
                   & ((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
                      | ((4U == (7U & (vlSelfRef.i_imem_rdata 
                                       >> 0x0000000cU))) 
                         | ((5U == (7U & (vlSelfRef.i_imem_rdata 
                                          >> 0x0000000cU))) 
                            | (IData)(__VdfgRegularize_h6e95ff9d_0_4))))));
    __VdfgRegularize_h6e95ff9d_0_9 = ((2U == (7U & 
                                              (vlSelfRef.i_imem_rdata 
                                               >> 0x0000000cU))) 
                                      | (IData)(__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.o_retire_rs1_rdata = (vlSelfRef.hart__DOT__rf__DOT__mem
                                    [vlSelfRef.o_retire_rs1_raddr] 
                                    & (- (IData)((0U 
                                                  != (IData)(vlSelfRef.o_retire_rs1_raddr)))));
    vlSelfRef.o_retire_rs2_rdata = (vlSelfRef.hart__DOT__rf__DOT__mem
                                    [vlSelfRef.o_retire_rs2_raddr] 
                                    & (- (IData)((0U 
                                                  != (IData)(vlSelfRef.o_retire_rs2_raddr)))));
    vlSelfRef.hart__DOT__decoder__DOT__immediate = 
        ((((0x00000800U & (vlSelfRef.i_imem_rdata >> 0x00000014U)) 
           | (0x000007ffU & ((IData)(hart__DOT__decoder__DOT__format_u)
                              ? (vlSelfRef.i_imem_rdata 
                                 >> 0x00000014U) : 
                             (- (IData)((vlSelfRef.i_imem_rdata 
                                         >> 0x0000001fU)))))) 
          << 0x00000014U) | ((((0x000001feU & ((((0x1bU 
                                                  == 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.i_imem_rdata 
                                                      >> 2U))) 
                                                 | (IData)(hart__DOT__decoder__DOT__format_u))
                                                 ? 
                                                (vlSelfRef.i_imem_rdata 
                                                 >> 0x0000000cU)
                                                 : 
                                                (- (IData)(
                                                           (vlSelfRef.i_imem_rdata 
                                                            >> 0x0000001fU)))) 
                                               << 1U)) 
                               | (1U & ((0x18U == (0x0000001fU 
                                                   & (vlSelfRef.i_imem_rdata 
                                                      >> 2U)))
                                         ? (vlSelfRef.i_imem_rdata 
                                            >> 7U) : 
                                        ((0x1bU == 
                                          (0x0000001fU 
                                           & (vlSelfRef.i_imem_rdata 
                                              >> 2U)))
                                          ? (vlSelfRef.i_imem_rdata 
                                             >> 0x00000014U)
                                          : ((~ (IData)(hart__DOT__decoder__DOT__format_u)) 
                                             & (vlSelfRef.i_imem_rdata 
                                                >> 0x0000001fU)))))) 
                              << 0x0000000bU) | ((0x000007e0U 
                                                  & (((- (IData)(
                                                                 (1U 
                                                                  & (~ (IData)(hart__DOT__decoder__DOT__format_u))))) 
                                                      << 5U) 
                                                     & (vlSelfRef.i_imem_rdata 
                                                        >> 0x00000014U))) 
                                                 | ((0x0000001eU 
                                                     & ((((- (IData)(
                                                                     ((8U 
                                                                       == 
                                                                       (0x0000001fU 
                                                                        & (vlSelfRef.i_imem_rdata 
                                                                           >> 2U))) 
                                                                      | (0x18U 
                                                                         == 
                                                                         (0x0000001fU 
                                                                          & (vlSelfRef.i_imem_rdata 
                                                                             >> 2U)))))) 
                                                          & (vlSelfRef.i_imem_rdata 
                                                             >> 8U)) 
                                                         | ((- (IData)(
                                                                       ((0x1bU 
                                                                         == 
                                                                         (0x0000001fU 
                                                                          & (vlSelfRef.i_imem_rdata 
                                                                             >> 2U))) 
                                                                        | (IData)(hart__DOT__decoder__DOT__format_i)))) 
                                                            & (vlSelfRef.i_imem_rdata 
                                                               >> 0x00000015U))) 
                                                        << 1U)) 
                                                    | ((IData)(
                                                               (0x000000a0U 
                                                                == 
                                                                (0x000000fcU 
                                                                 & vlSelfRef.i_imem_rdata))) 
                                                       | ((vlSelfRef.i_imem_rdata 
                                                           >> 0x00000014U) 
                                                          & (IData)(hart__DOT__decoder__DOT__format_i)))))));
    vlSelfRef.hart__DOT__dmem_ext_mask = (0xffU | (
                                                   ((- (IData)(
                                                               (2U 
                                                                == 
                                                                (7U 
                                                                 & (vlSelfRef.i_imem_rdata 
                                                                    >> 0x0000000cU))))) 
                                                    << 0x00000010U) 
                                                   | (0x0000ff00U 
                                                      & ((- (IData)((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))) 
                                                         << 8U))));
    vlSelfRef.hart__DOT__decoder__DOT__alu_sub = ((IData)(vlSelfRef.hart__DOT__decoder__DOT__inst_branch) 
                                                  | ((IData)(hart__DOT__decoder__DOT__inst_sltu) 
                                                     | ((IData)(
                                                                ((0x00000030U 
                                                                  == 
                                                                  (0x0000007cU 
                                                                   & vlSelfRef.i_imem_rdata)) 
                                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_11))) 
                                                        | ((IData)(
                                                                   (0x00002030U 
                                                                    == 
                                                                    (0xfe00707cU 
                                                                     & vlSelfRef.i_imem_rdata))) 
                                                           | ((IData)(
                                                                      (0x00002010U 
                                                                       == 
                                                                       (0x0000707cU 
                                                                        & vlSelfRef.i_imem_rdata))) 
                                                              | (IData)(hart__DOT__decoder__DOT__inst_sltiu))))));
    vlSelfRef.o_dmem_wen = (IData)(((0x00000020U == 
                                     (0x0000007cU & vlSelfRef.i_imem_rdata)) 
                                    & (IData)(__VdfgRegularize_h6e95ff9d_0_9)));
    vlSelfRef.o_dmem_ren = (IData)(((0U == (0x0000007cU 
                                            & vlSelfRef.i_imem_rdata)) 
                                    & ((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                                       | (IData)(vlSelfRef.hart__DOT__dmem_memu))));
    hart__DOT__alu__DOT__barrel__DOT__sli = (((5U == 
                                               (0x0000001fU 
                                                & (vlSelfRef.i_imem_rdata 
                                                   >> 2U))) 
                                              | (0x1bU 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.i_imem_rdata 
                                                     >> 2U))))
                                              ? vlSelfRef.hart__DOT__pc
                                              : vlSelfRef.o_retire_rs1_rdata);
    hart__DOT__alu_op2 = (((4U == (0x0000001fU & (vlSelfRef.i_imem_rdata 
                                                  >> 2U))) 
                           | ((0U == (0x0000001fU & 
                                      (vlSelfRef.i_imem_rdata 
                                       >> 2U))) | (
                                                   (8U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.i_imem_rdata 
                                                        >> 2U))) 
                                                   | ((5U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.i_imem_rdata 
                                                           >> 2U))) 
                                                      | (0x19U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (vlSelfRef.i_imem_rdata 
                                                             >> 2U)))))))
                           ? vlSelfRef.hart__DOT__decoder__DOT__immediate
                           : vlSelfRef.o_retire_rs2_rdata);
    vlSelfRef.o_retire_rd_waddr = (0x0000001fU & ((vlSelfRef.i_imem_rdata 
                                                   >> 7U) 
                                                  & (- (IData)(
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.o_dmem_wen) 
                                                                    | (IData)(vlSelfRef.hart__DOT__decoder__DOT__inst_branch))))))));
    vlSelfRef.hart__DOT__decoder__DOT__rd_sel = ((((IData)(vlSelfRef.o_dmem_ren) 
                                                   << 3U) 
                                                  | ((IData)(vlSelfRef.hart__DOT__decoder__DOT__jump) 
                                                     << 2U)) 
                                                 | (((0x0dU 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSelfRef.i_imem_rdata 
                                                          >> 2U))) 
                                                     << 1U) 
                                                    | ((5U 
                                                        == 
                                                        (0x0000001fU 
                                                         & (vlSelfRef.i_imem_rdata 
                                                            >> 2U))) 
                                                       | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.o_dmem_ren) 
                                                | (IData)(vlSelfRef.o_dmem_wen));
    hart__DOT__alu__DOT__barrel__DOT__sign = ((0x20U 
                                               == (vlSelfRef.i_imem_rdata 
                                                   >> 0x00000019U)) 
                                              & (hart__DOT__alu__DOT__barrel__DOT__sli 
                                                 >> 0x0000001fU));
    if ((0x00000010U & hart__DOT__alu_op2)) {
        hart__DOT__alu__DOT__barrel__DOT__sl4 = VL_SHIFTL_III(32,32,32, hart__DOT__alu__DOT__barrel__DOT__sli, 0x00000010U);
        hart__DOT__alu__DOT__barrel__DOT__sr4 = (((- (IData)((IData)(hart__DOT__alu__DOT__barrel__DOT__sign))) 
                                                  << 0x00000010U) 
                                                 | (hart__DOT__alu__DOT__barrel__DOT__sli 
                                                    >> 0x00000010U));
    } else {
        hart__DOT__alu__DOT__barrel__DOT__sl4 = hart__DOT__alu__DOT__barrel__DOT__sli;
        hart__DOT__alu__DOT__barrel__DOT__sr4 = hart__DOT__alu__DOT__barrel__DOT__sli;
    }
    hart__DOT__alu__DOT__xor_result = (hart__DOT__alu__DOT__barrel__DOT__sli 
                                       ^ hart__DOT__alu_op2);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8 = ((5U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.i_imem_rdata 
                                                     >> 2U))) 
                                                | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2));
    if ((8U & hart__DOT__alu_op2)) {
        hart__DOT__alu__DOT__barrel__DOT__sl3 = VL_SHIFTL_III(32,32,32, hart__DOT__alu__DOT__barrel__DOT__sl4, 8U);
        hart__DOT__alu__DOT__barrel__DOT__sr3 = (((- (IData)((IData)(hart__DOT__alu__DOT__barrel__DOT__sign))) 
                                                  << 0x00000018U) 
                                                 | (hart__DOT__alu__DOT__barrel__DOT__sr4 
                                                    >> 8U));
    } else {
        hart__DOT__alu__DOT__barrel__DOT__sl3 = hart__DOT__alu__DOT__barrel__DOT__sl4;
        hart__DOT__alu__DOT__barrel__DOT__sr3 = hart__DOT__alu__DOT__barrel__DOT__sr4;
    }
    vlSelfRef.hart__DOT__decoder__DOT__alu_opsel = 
        (7U & ((vlSelfRef.i_imem_rdata >> 0x0000000cU) 
               & (- (IData)((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8)))))));
    if ((4U & hart__DOT__alu_op2)) {
        hart__DOT__alu__DOT__barrel__DOT__sl2 = VL_SHIFTL_III(32,32,32, hart__DOT__alu__DOT__barrel__DOT__sl3, 4U);
        hart__DOT__alu__DOT__barrel__DOT__sr2 = (((- (IData)((IData)(hart__DOT__alu__DOT__barrel__DOT__sign))) 
                                                  << 0x0000001cU) 
                                                 | (hart__DOT__alu__DOT__barrel__DOT__sr3 
                                                    >> 4U));
    } else {
        hart__DOT__alu__DOT__barrel__DOT__sl2 = hart__DOT__alu__DOT__barrel__DOT__sl3;
        hart__DOT__alu__DOT__barrel__DOT__sr2 = hart__DOT__alu__DOT__barrel__DOT__sr3;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7 = (1U 
                                                & (~ 
                                                   ((IData)(hart__DOT__decoder__DOT__inst_sltu) 
                                                    | ((IData)(hart__DOT__decoder__DOT__inst_sltiu) 
                                                       | ((IData)(
                                                                  ((0x00000060U 
                                                                    == 
                                                                    (0x0000007cU 
                                                                     & vlSelfRef.i_imem_rdata)) 
                                                                   & (IData)(__VdfgRegularize_h6e95ff9d_0_4))) 
                                                          | (3U 
                                                             == (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel)))))));
    if ((2U & hart__DOT__alu_op2)) {
        hart__DOT__alu__DOT__barrel__DOT__sl1 = VL_SHIFTL_III(32,32,32, hart__DOT__alu__DOT__barrel__DOT__sl2, 2U);
        hart__DOT__alu__DOT__barrel__DOT__sr1 = (((- (IData)((IData)(hart__DOT__alu__DOT__barrel__DOT__sign))) 
                                                  << 0x0000001eU) 
                                                 | (hart__DOT__alu__DOT__barrel__DOT__sr2 
                                                    >> 2U));
    } else {
        hart__DOT__alu__DOT__barrel__DOT__sl1 = hart__DOT__alu__DOT__barrel__DOT__sl2;
        hart__DOT__alu__DOT__barrel__DOT__sr1 = hart__DOT__alu__DOT__barrel__DOT__sr2;
    }
    hart__DOT__alu__DOT__sum = (0x00000001ffffffffULL 
                                & ((((QData)((IData)(
                                                     ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7) 
                                                      & (hart__DOT__alu__DOT__barrel__DOT__sli 
                                                         >> 0x0000001fU)))) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(hart__DOT__alu__DOT__barrel__DOT__sli))) 
                                   + (((((QData)((IData)(
                                                         ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7) 
                                                          & (hart__DOT__alu_op2 
                                                             >> 0x0000001fU)))) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(hart__DOT__alu_op2))) 
                                       ^ (- (QData)((IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_sub)))) 
                                      + (QData)((IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_sub)))));
    if ((4U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel))) {
        hart__DOT__alu__DOT__shift_result = ((1U & hart__DOT__alu_op2)
                                              ? (((IData)(hart__DOT__alu__DOT__barrel__DOT__sign) 
                                                  << 0x0000001fU) 
                                                 | (hart__DOT__alu__DOT__barrel__DOT__sr1 
                                                    >> 1U))
                                              : hart__DOT__alu__DOT__barrel__DOT__sr1);
        hart__DOT__alu__DOT__result = ((2U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel))
                                        ? ((1U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel))
                                            ? (hart__DOT__alu__DOT__barrel__DOT__sli 
                                               & hart__DOT__alu_op2)
                                            : (hart__DOT__alu__DOT__barrel__DOT__sli 
                                               | hart__DOT__alu_op2))
                                        : ((1U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel))
                                            ? hart__DOT__alu__DOT__shift_result
                                            : hart__DOT__alu__DOT__xor_result));
    } else {
        hart__DOT__alu__DOT__shift_result = ((1U & hart__DOT__alu_op2)
                                              ? VL_SHIFTL_III(32,32,32, hart__DOT__alu__DOT__barrel__DOT__sl1, 1U)
                                              : hart__DOT__alu__DOT__barrel__DOT__sl1);
        hart__DOT__alu__DOT__result = ((2U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel))
                                        ? (1U & (IData)(
                                                        (hart__DOT__alu__DOT__sum 
                                                         >> 0x00000020U)))
                                        : ((1U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__alu_opsel))
                                            ? hart__DOT__alu__DOT__shift_result
                                            : (IData)(hart__DOT__alu__DOT__sum)));
    }
    vlSelfRef.o_dmem_addr = (0xfffffffcU & hart__DOT__alu__DOT__result);
    if ((2U & hart__DOT__alu__DOT__result)) {
        hart__DOT__dmem_wdatah = VL_SHIFTL_III(32,32,32, vlSelfRef.o_retire_rs2_rdata, 0x00000010U);
        hart__DOT__dmem_rdatah = VL_SHIFTR_III(32,32,32, vlSelfRef.i_dmem_rdata, 0x00000010U);
    } else {
        hart__DOT__dmem_wdatah = vlSelfRef.o_retire_rs2_rdata;
        hart__DOT__dmem_rdatah = vlSelfRef.i_dmem_rdata;
    }
    __VdfgRegularize_h6e95ff9d_0_13 = ((~ (hart__DOT__alu__DOT__result 
                                           >> 1U)) 
                                       & (IData)(vlSelfRef.hart__DOT__dmem_memb));
    __VdfgRegularize_h6e95ff9d_0_14 = ((2U == (7U & 
                                               (vlSelfRef.i_imem_rdata 
                                                >> 0x0000000cU))) 
                                       | ((IData)(vlSelfRef.hart__DOT__dmem_memh) 
                                          & (hart__DOT__alu__DOT__result 
                                             >> 1U)));
    __VdfgRegularize_h6e95ff9d_0_15 = ((2U == (7U & 
                                               (vlSelfRef.i_imem_rdata 
                                                >> 0x0000000cU))) 
                                       | ((~ (hart__DOT__alu__DOT__result 
                                              >> 1U)) 
                                          & (IData)(vlSelfRef.hart__DOT__dmem_memh)));
    vlSelfRef.o_retire_next_pc = (((IData)(((0x00000060U 
                                             == (0x0000007cU 
                                                 & vlSelfRef.i_imem_rdata)) 
                                            & ((vlSelfRef.i_imem_rdata 
                                                >> 0x0000000cU) 
                                               ^ ((0x00004000U 
                                                   & vlSelfRef.i_imem_rdata)
                                                   ? (IData)(
                                                             (hart__DOT__alu__DOT__sum 
                                                              >> 0x00000020U))
                                                   : 
                                                  (0U 
                                                   == hart__DOT__alu__DOT__xor_result))))) 
                                   | (IData)(vlSelfRef.hart__DOT__decoder__DOT__jump))
                                   ? ((0x19U == (0x0000001fU 
                                                 & (vlSelfRef.i_imem_rdata 
                                                    >> 2U)))
                                       ? (0xfffffffeU 
                                          & hart__DOT__alu__DOT__result)
                                       : (vlSelfRef.hart__DOT__pc 
                                          + vlSelfRef.hart__DOT__decoder__DOT__immediate))
                                   : ((IData)(4U) + vlSelfRef.hart__DOT__pc));
    if ((1U & hart__DOT__alu__DOT__result)) {
        vlSelfRef.o_dmem_wdata = VL_SHIFTL_III(32,32,32, hart__DOT__dmem_wdatah, 8U);
        hart__DOT__dmem_rdatab = VL_SHIFTR_III(32,32,32, hart__DOT__dmem_rdatah, 8U);
    } else {
        vlSelfRef.o_dmem_wdata = hart__DOT__dmem_wdatah;
        hart__DOT__dmem_rdatab = hart__DOT__dmem_rdatah;
    }
    vlSelfRef.o_dmem_mask = ((((((IData)(vlSelfRef.hart__DOT__dmem_memb) 
                                 & (3U == (3U & hart__DOT__alu__DOT__result))) 
                                | (IData)(__VdfgRegularize_h6e95ff9d_0_14)) 
                               << 3U) | (((IData)((
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & hart__DOT__alu__DOT__result)) 
                                                   & (IData)(vlSelfRef.hart__DOT__dmem_memb))) 
                                          | (IData)(__VdfgRegularize_h6e95ff9d_0_14)) 
                                         << 2U)) | 
                             ((((hart__DOT__alu__DOT__result 
                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_13)) 
                                | (IData)(__VdfgRegularize_h6e95ff9d_0_15)) 
                               << 1U) | (((~ hart__DOT__alu__DOT__result) 
                                          & (IData)(__VdfgRegularize_h6e95ff9d_0_13)) 
                                         | (IData)(__VdfgRegularize_h6e95ff9d_0_15))));
    vlSelfRef.o_retire_trap = (1U & (~ ((IData)(vlSelfRef.i_rst) 
                                        | (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5) 
                                            | ((0x0dU 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.i_imem_rdata 
                                                    >> 2U))) 
                                               | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8) 
                                                  | ((IData)(vlSelfRef.hart__DOT__decoder__DOT__inst_branch) 
                                                     | ((0x1bU 
                                                         == 
                                                         (0x0000001fU 
                                                          & (vlSelfRef.i_imem_rdata 
                                                             >> 2U))) 
                                                        | ((0x19U 
                                                            == 
                                                            (0x0000001fU 
                                                             & (vlSelfRef.i_imem_rdata 
                                                                >> 2U))) 
                                                           | (IData)(vlSelfRef.o_retire_halt))))))) 
                                           & ((0U == 
                                               (3U 
                                                & vlSelfRef.o_retire_next_pc)) 
                                              & ((~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)) 
                                                 | (0U 
                                                    == 
                                                    (hart__DOT__alu__DOT__result 
                                                     & (((2U 
                                                          == 
                                                          (7U 
                                                           & (vlSelfRef.i_imem_rdata 
                                                              >> 0x0000000cU))) 
                                                         << 1U) 
                                                        | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))))))))));
    vlSelfRef.hart__DOT__rd_wdata = 0U;
    if ((1U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__rd_sel))) {
        vlSelfRef.hart__DOT__rd_wdata = hart__DOT__alu__DOT__result;
    } else if ((2U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__rd_sel))) {
        vlSelfRef.hart__DOT__rd_wdata = vlSelfRef.hart__DOT__decoder__DOT__immediate;
    } else if ((4U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__rd_sel))) {
        vlSelfRef.hart__DOT__rd_wdata = ((IData)(4U) 
                                         + vlSelfRef.hart__DOT__pc);
    } else if ((8U & (IData)(vlSelfRef.hart__DOT__decoder__DOT__rd_sel))) {
        vlSelfRef.hart__DOT__rd_wdata = ((hart__DOT__dmem_rdatab 
                                          & vlSelfRef.hart__DOT__dmem_ext_mask) 
                                         | ((~ vlSelfRef.hart__DOT__dmem_ext_mask) 
                                            & (- (IData)(
                                                         (1U 
                                                          & ((~ (IData)(vlSelfRef.hart__DOT__dmem_memu)) 
                                                             & ((2U 
                                                                 == 
                                                                 (7U 
                                                                  & (vlSelfRef.i_imem_rdata 
                                                                     >> 0x0000000cU)))
                                                                 ? 
                                                                (vlSelfRef.i_dmem_rdata 
                                                                 >> 0x0000001fU)
                                                                 : 
                                                                ((IData)(vlSelfRef.hart__DOT__dmem_memh)
                                                                  ? 
                                                                 (hart__DOT__dmem_rdatah 
                                                                  >> 0x0000000fU)
                                                                  : 
                                                                 (hart__DOT__dmem_rdatab 
                                                                  >> 7U)))))))));
    }
    vlSelfRef.o_retire_rd_wdata = vlSelfRef.hart__DOT__rd_wdata;
}

VL_ATTR_COLD void Vhart___024root___eval_stl(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_stl\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vhart___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vhart___024root___eval_phase__stl(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_phase__stl\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vhart___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vhart___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vhart___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vhart___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vhart___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhart___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vhart___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vhart___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhart___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vhart___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge i_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhart___024root___ctor_var_reset(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___ctor_var_reset\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->i_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15925868812496733354ull);
    vlSelf->i_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9693334148897220726ull);
    vlSelf->o_imem_raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14286189294889629539ull);
    vlSelf->i_imem_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11521664675351583267ull);
    vlSelf->o_dmem_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 274581538545503949ull);
    vlSelf->o_dmem_ren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6521837553432634162ull);
    vlSelf->o_dmem_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1015424699925816671ull);
    vlSelf->o_dmem_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12607450708364042141ull);
    vlSelf->o_dmem_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12744964878886449966ull);
    vlSelf->i_dmem_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18272911861978324434ull);
    vlSelf->o_retire_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8506190543217626990ull);
    vlSelf->o_retire_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2826371444809811489ull);
    vlSelf->o_retire_trap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11040107452441922664ull);
    vlSelf->o_retire_halt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13778993953298468402ull);
    vlSelf->o_retire_rs1_raddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11034560911691399514ull);
    vlSelf->o_retire_rs2_raddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6833974198341972205ull);
    vlSelf->o_retire_rs1_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1526530069187617084ull);
    vlSelf->o_retire_rs2_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15757879771796596014ull);
    vlSelf->o_retire_rd_waddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18250097824604250983ull);
    vlSelf->o_retire_rd_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11470845915367264473ull);
    vlSelf->o_retire_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7224921383684586421ull);
    vlSelf->o_retire_next_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10043180277681343509ull);
    vlSelf->hart__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6072098345291593167ull);
    vlSelf->hart__DOT__rd_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9664656122982867461ull);
    vlSelf->hart__DOT__dmem_memb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12495720038418864213ull);
    vlSelf->hart__DOT__dmem_memh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2464371041028486999ull);
    vlSelf->hart__DOT__dmem_memu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2764155992642526381ull);
    vlSelf->hart__DOT__dmem_ext_mask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18091940677820560653ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->hart__DOT__rf__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 331512932502598960ull);
    }
    vlSelf->hart__DOT__decoder__DOT__inst_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10935986445229039427ull);
    vlSelf->hart__DOT__decoder__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11911610200144362769ull);
    vlSelf->hart__DOT__decoder__DOT__alu_opsel = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15325492339268592149ull);
    vlSelf->hart__DOT__decoder__DOT__alu_sub = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15953146081745732407ull);
    vlSelf->hart__DOT__decoder__DOT__jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14394383393474413178ull);
    vlSelf->hart__DOT__decoder__DOT__rd_sel = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4069404997110225660ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_5 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_7 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_8 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_12 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
