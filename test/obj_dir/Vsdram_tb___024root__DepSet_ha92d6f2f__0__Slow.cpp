// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb___024root.h"

VL_ATTR_COLD void Vsdram_tb___024root___eval_static(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsdram_tb___024root___eval_final(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__stl(Vsdram_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsdram_tb___024root___eval_phase__stl(Vsdram_tb___024root* vlSelf);

VL_ATTR_COLD void Vsdram_tb___024root___eval_settle(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsdram_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("sdram_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsdram_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__stl(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsdram_tb___024root___stl_sequent__TOP__0(Vsdram_tb___024root* vlSelf);

VL_ATTR_COLD void Vsdram_tb___024root___eval_stl(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsdram_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vsdram_tb___024root___eval_triggers__stl(Vsdram_tb___024root* vlSelf);

VL_ATTR_COLD bool Vsdram_tb___024root___eval_phase__stl(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsdram_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsdram_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__act(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge sdram_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge sdram_tb.u_sdram_model.Sys_clk or [true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge sdram_tb.sdram_clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge sdram_tb.sdram_clk)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge sdram_tb.u_sdram_model.Sys_clk)\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h0]))\n");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h1]))\n");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h2]))\n");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h3]))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__nba(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge sdram_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge sdram_tb.u_sdram_model.Sys_clk or [true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge sdram_tb.sdram_clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge sdram_tb.sdram_clk)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge sdram_tb.u_sdram_model.Sys_clk)\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h0]))\n");
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h1]))\n");
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h2]))\n");
    }
    if ((0x200ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @([changed] (sdram_tb.u_sdram_model.WR_counter[2'h3]))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsdram_tb___024root___ctor_var_reset(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sdram_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__sdram_clk = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__randint = 0;
    vlSelf->sdram_tb__DOT__bytenum = 0;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = VL_RAND_RESET_I(3);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__new_state = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt = VL_RAND_RESET_I(4);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = VL_RAND_RESET_I(4);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2 = VL_RAND_RESET_I(16);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = VL_RAND_RESET_I(3);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank = VL_RAND_RESET_I(2);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col = VL_RAND_RESET_I(9);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__byte_misalign = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_reg = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg = VL_RAND_RESET_I(32);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 2097152; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank0[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2097152; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank1[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2097152; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank2[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2097152; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank3[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[__Vi0] = VL_RAND_RESET_I(9);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[__Vi0] = VL_RAND_RESET_I(4);
    }
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0 = VL_RAND_RESET_I(2);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg1 = VL_RAND_RESET_I(2);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg = VL_RAND_RESET_I(16);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm = VL_RAND_RESET_I(16);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp = VL_RAND_RESET_I(9);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter = VL_RAND_RESET_I(9);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank = VL_RAND_RESET_I(2);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Previous_bank = VL_RAND_RESET_I(2);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row = VL_RAND_RESET_I(12);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col = VL_RAND_RESET_I(9);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst = VL_RAND_RESET_I(9);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__CkeZ = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3 = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_burst_mode = VL_RAND_RESET_I(1);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RRD_chk = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3 = VL_RAND_RESET_Q(64);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0 = 0;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0 = 0;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0 = 0;
    vlSelf->__VassignWtmp_sdram_tb__DOT__sdram_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vintraval_h8e9d4ac7__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vintraval_h69ef25c5__0 = VL_RAND_RESET_I(16);
    vlSelf->__Vintraval_h9edf9348__0 = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvval__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvset__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__u_sdram_model__DOT__Sys_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__sdram_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h7fb8c6b6__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr_h7fb8c6f5__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr_h7fb8c738__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr_h7fb8c55c__0 = VL_RAND_RESET_I(32);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
