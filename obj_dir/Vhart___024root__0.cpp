// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhart.h for the primary calling header

#include "Vhart__pch.h"

void Vhart___024root___eval_triggers_vec__ico(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_triggers_vec__ico\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vhart___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___trigger_anySet__ico\n"); );
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

void Vhart___024root___ico_sequent__TOP__0(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___ico_sequent__TOP__0\n"); );
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
    vlSelfRef.o_retire_inst = vlSelfRef.i_imem_rdata;
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

void Vhart___024root___eval_ico(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_ico\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vhart___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhart___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vhart___024root___eval_phase__ico(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_phase__ico\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vhart___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vhart___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vhart___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vhart___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vhart___024root___eval_triggers_vec__act(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_triggers_vec__act\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.i_clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__i_clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__i_clk__0 = vlSelfRef.i_clk;
}

bool Vhart___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___trigger_anySet__act\n"); );
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

void Vhart___024root___nba_sequent__TOP__0(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___nba_sequent__TOP__0\n"); );
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
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_14;
    __VdfgRegularize_h6e95ff9d_0_14 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_15;
    __VdfgRegularize_h6e95ff9d_0_15 = 0;
    CData/*0:0*/ __VdlySet__hart__DOT__rf__DOT__mem__v0;
    __VdlySet__hart__DOT__rf__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__hart__DOT__rf__DOT__mem__v32;
    __VdlyVal__hart__DOT__rf__DOT__mem__v32 = 0;
    CData/*4:0*/ __VdlyDim0__hart__DOT__rf__DOT__mem__v32;
    __VdlyDim0__hart__DOT__rf__DOT__mem__v32 = 0;
    CData/*0:0*/ __VdlySet__hart__DOT__rf__DOT__mem__v32;
    __VdlySet__hart__DOT__rf__DOT__mem__v32 = 0;
    // Body
    __VdlySet__hart__DOT__rf__DOT__mem__v0 = 0U;
    __VdlySet__hart__DOT__rf__DOT__mem__v32 = 0U;
    if (vlSelfRef.i_rst) {
        __VdlySet__hart__DOT__rf__DOT__mem__v0 = 1U;
        vlSelfRef.hart__DOT__pc = 0U;
    } else {
        if ((0U != (IData)(vlSelfRef.o_retire_rd_waddr))) {
            __VdlyVal__hart__DOT__rf__DOT__mem__v32 
                = vlSelfRef.hart__DOT__rd_wdata;
            __VdlyDim0__hart__DOT__rf__DOT__mem__v32 
                = vlSelfRef.o_retire_rd_waddr;
            __VdlySet__hart__DOT__rf__DOT__mem__v32 = 1U;
        }
        vlSelfRef.hart__DOT__pc = vlSelfRef.o_retire_next_pc;
    }
    if (__VdlySet__hart__DOT__rf__DOT__mem__v0) {
        vlSelfRef.hart__DOT__rf__DOT__mem[0U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[1U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[2U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[3U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[4U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[5U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[6U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[7U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[8U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[9U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[10U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[11U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[12U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[13U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[14U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[15U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[16U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[17U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[18U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[19U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[20U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[21U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[22U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[23U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[24U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[25U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[26U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[27U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[28U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[29U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[30U] = 0U;
        vlSelfRef.hart__DOT__rf__DOT__mem[31U] = 0U;
    }
    if (__VdlySet__hart__DOT__rf__DOT__mem__v32) {
        vlSelfRef.hart__DOT__rf__DOT__mem[__VdlyDim0__hart__DOT__rf__DOT__mem__v32] 
            = __VdlyVal__hart__DOT__rf__DOT__mem__v32;
    }
    vlSelfRef.o_retire_rs1_rdata = (vlSelfRef.hart__DOT__rf__DOT__mem
                                    [vlSelfRef.o_retire_rs1_raddr] 
                                    & (- (IData)((0U 
                                                  != (IData)(vlSelfRef.o_retire_rs1_raddr)))));
    vlSelfRef.o_retire_rs2_rdata = (vlSelfRef.hart__DOT__rf__DOT__mem
                                    [vlSelfRef.o_retire_rs2_raddr] 
                                    & (- (IData)((0U 
                                                  != (IData)(vlSelfRef.o_retire_rs2_raddr)))));
    vlSelfRef.o_imem_raddr = vlSelfRef.hart__DOT__pc;
    vlSelfRef.o_retire_pc = vlSelfRef.hart__DOT__pc;
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

void Vhart___024root___eval_nba(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_nba\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vhart___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vhart___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhart___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vhart___024root___eval_phase__act(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_phase__act\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vhart___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vhart___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vhart___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vhart___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vhart___024root___eval_phase__nba(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_phase__nba\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vhart___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vhart___024root___eval_nba(vlSelf);
        Vhart___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vhart___024root___eval(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vhart___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/boi/Projects/CompArchReup/Binarytesting/submission/hart.v", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vhart___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vhart___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/boi/Projects/CompArchReup/Binarytesting/submission/hart.v", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vhart___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/boi/Projects/CompArchReup/Binarytesting/submission/hart.v", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vhart___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vhart___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vhart___024root___eval_debug_assertions(Vhart___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhart___024root___eval_debug_assertions\n"); );
    Vhart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.i_clk & 0xfeU)))) {
        Verilated::overWidthError("i_clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.i_rst & 0xfeU)))) {
        Verilated::overWidthError("i_rst");
    }
}
#endif  // VL_DEBUG
