// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb___024root.h"

VL_ATTR_COLD void Vsdram_tb___024root___eval_initial__TOP(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__0(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__1(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__2(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__3(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__4(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__5(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__6(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__7(Vsdram_tb___024root* vlSelf);
VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__8(Vsdram_tb___024root* vlSelf);

void Vsdram_tb___024root___eval_initial(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial\n"); );
    // Body
    Vsdram_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__3(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__4(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__5(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__6(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__7(vlSelf);
    Vsdram_tb___024root___eval_initial__TOP__Vtiming__8(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__clk__0 
        = vlSelf->sdram_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__u_sdram_model__DOT__Sys_clk__0 
        = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk;
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__sdram_clk__0 
        = vlSelf->sdram_tb__DOT__sdram_clk;
    vlSelf->__Vtrigprevexpr_h7fb8c6b6__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [0U];
    vlSelf->__Vtrigprevexpr_h7fb8c6f5__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [1U];
    vlSelf->__Vtrigprevexpr_h7fb8c738__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [2U];
    vlSelf->__Vtrigprevexpr_h7fb8c55c__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [3U];
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__0(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->sdram_tb__DOT__clk = 0U;
    vlSelf->sdram_tb__DOT__rst = 1U;
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sdram_tb.clk)", 
                                                       "sdram_tb.sv", 
                                                       43);
    vlSelf->sdram_tb__DOT__rst = 0U;
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__1(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h825eefb7__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.sdram_clk)", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           181);
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__CkeZ;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__CkeZ = 1U;
        co_await vlSelf->__VtrigSched_h825ef06a__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge sdram_tb.sdram_clk)", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           185);
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk = 0U;
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__3(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__3\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x2710ULL, 
                                           nullptr, 
                                           "sdram_tb.sv", 
                                           48);
        vlSelf->sdram_tb__DOT__clk = (1U & (~ (IData)(vlSelf->sdram_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__4____Vfork_2__1(Vsdram_tb___024root* vlSelf, SData/*15:0*/ __Vintraval_h69ef25c5__0) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__4____Vfork_2__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xa8cULL, nullptr, 
                                       "../models/MT48LC8M16A2.v", 
                                       710);
    vlSelf->__Vdlyvval__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 
        = __Vintraval_h69ef25c5__0;
    vlSelf->__Vdlyvset__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 = 1U;
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__5(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__5\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_he77f00c4__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h0]))", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           804);
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [0U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge
             [0U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                   >= 42.0) & ((((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [0U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [0U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [0U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [0U])))) 
                 | (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [0U] & VL_LTES_III(32, 2U, vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [0U])))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[0U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[0U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "../models/MT48LC8M16A2.v", 
                                                   815);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__6(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__6\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_he77eff83__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h1]))", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           823);
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [1U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge
             [1U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                   >= 42.0) & ((((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [1U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [1U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [1U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [1U])))) 
                 | (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [1U] & VL_LTES_III(32, 2U, vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [1U])))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[1U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[1U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "../models/MT48LC8M16A2.v", 
                                                   834);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__7(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__7\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_he77eff4a__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h2]))", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           842);
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [2U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge
             [2U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                   >= 42.0) & ((((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [2U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [2U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [2U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [2U])))) 
                 | (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [2U] & VL_LTES_III(32, 2U, vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [2U])))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[2U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[2U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "../models/MT48LC8M16A2.v", 
                                                   853);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__8(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__8\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_he77ff96e__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h3]))", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           861);
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [3U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge
             [3U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                   >= 42.0) & ((((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [3U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [3U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [3U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [3U])))) 
                 | (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [3U] & VL_LTES_III(32, 2U, vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [3U])))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[3U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[3U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "../models/MT48LC8M16A2.v", 
                                                   872);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT void Vsdram_tb___024root___act_comb__TOP__0(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_burst_mode 
        = (1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                 >> 9U));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0 
        = (IData)((0U == (6U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0 
        = (IData)((2U == (6U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0 
        = (IData)((0x20U == (0x60U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1 
        = ((~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg)) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4 
        = ((~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg)) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0) 
           & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
              >> 4U));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2 
        = ((~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
               >> 4U)) & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0));
}

VlCoroutine Vsdram_tb___024root___act_comb__TOP__1____Vfork_1__0(Vsdram_tb___024root* vlSelf, CData/*0:0*/ __Vintraval_h8e9d4ac7__0);

VL_INLINE_OPT void Vsdram_tb___024root___act_comb__TOP__1(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___act_comb__TOP__1\n"); );
    // Body
    Vsdram_tb___024root___act_comb__TOP__1____Vfork_1__0(vlSelf, vlSelf->__Vintraval_h8e9d4ac7__0);
    vlSelf->sdram_tb__DOT__sdram_clk = vlSelf->__VassignWtmp_sdram_tb__DOT__sdram_clk__0;
}

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___act_comb__TOP__1____Vfork_1__0(Vsdram_tb___024root* vlSelf, CData/*0:0*/ __Vintraval_h8e9d4ac7__0) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___act_comb__TOP__1____Vfork_1__0\n"); );
    // Body
    __Vintraval_h8e9d4ac7__0 = vlSelf->sdram_tb__DOT__clk;
    co_await vlSelf->__VdlySched.delay(0x1388ULL, nullptr, 
                                       "sdram_tb.sv", 
                                       52);
    vlSelf->__VassignWtmp_sdram_tb__DOT__sdram_clk__0 
        = __Vintraval_h8e9d4ac7__0;
}

void Vsdram_tb___024root___eval_act(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_act\n"); );
    // Body
    if ((0x30ULL & vlSelf->__VactTriggered.word(0U))) {
        Vsdram_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((0x11ULL & vlSelf->__VactTriggered.word(0U))) {
        Vsdram_tb___024root___act_comb__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vsdram_tb___024root___nba_sequent__TOP__1(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->__Vdlyvset__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0) {
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg 
            = vlSelf->__Vdlyvval__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0;
        vlSelf->__Vdlyvset__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 = 0U;
    }
}

void Vsdram_tb___024root___nba_sequent__TOP__0(Vsdram_tb___024root* vlSelf);

void Vsdram_tb___024root___eval_nba(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((0x30ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((0x11ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_tb___024root___act_comb__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vsdram_tb___024root___timing_resume(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hee8b7033__0.resume("@(posedge sdram_tb.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h825eefb7__0.resume("@(posedge sdram_tb.sdram_clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h825ef06a__0.resume("@(negedge sdram_tb.sdram_clk)");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hefdf76e7__0.resume("@(posedge sdram_tb.u_sdram_model.Sys_clk)");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he77f00c4__0.resume("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h0]))");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he77eff83__0.resume("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h1]))");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he77eff4a__0.resume("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h2]))");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he77ff96e__0.resume("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h3]))");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vsdram_tb___024root___timing_commit(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hee8b7033__0.commit("@(posedge sdram_tb.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h825eefb7__0.commit("@(posedge sdram_tb.sdram_clk)");
    }
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h825ef06a__0.commit("@(negedge sdram_tb.sdram_clk)");
    }
    if ((! (0x20ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hefdf76e7__0.commit("@(posedge sdram_tb.u_sdram_model.Sys_clk)");
    }
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he77f00c4__0.commit("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h0]))");
    }
    if ((! (0x80ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he77eff83__0.commit("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h1]))");
    }
    if ((! (0x100ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he77eff4a__0.commit("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h2]))");
    }
    if ((! (0x200ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he77ff96e__0.commit("@([changed] (sdram_tb.u_sdram_model.WR_counter[2'h3]))");
    }
}

void Vsdram_tb___024root___eval_triggers__act(Vsdram_tb___024root* vlSelf);

bool Vsdram_tb___024root___eval_phase__act(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<10> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsdram_tb___024root___eval_triggers__act(vlSelf);
    Vsdram_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsdram_tb___024root___timing_resume(vlSelf);
        Vsdram_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsdram_tb___024root___eval_phase__nba(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsdram_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__nba(Vsdram_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__act(Vsdram_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsdram_tb___024root___eval(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsdram_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sdram_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsdram_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sdram_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsdram_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsdram_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsdram_tb___024root___eval_debug_assertions(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
