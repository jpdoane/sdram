// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_axil_tb.h for the primary calling header

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb__Syms.h"
#include "Vsdram_axil_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_axil_tb___024root___dump_triggers__ico(Vsdram_axil_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsdram_axil_tb___024root___eval_triggers__ico(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsdram_axil_tb___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsdram_axil_tb___024root___ico_sequent__TOP__0(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_ack 
        = (((IData)(vlSelf->awvalid) & (IData)(vlSelf->wvalid)) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
    vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack 
        = ((IData)(vlSelf->arvalid) & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
    if (vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_ack) {
        vlSelf->awready = 1U;
        vlSelf->wready = 1U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSelf->arready = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data 
            = vlSelf->wdata;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr 
            = vlSelf->wstrb;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
            = vlSelf->awaddr;
    } else {
        vlSelf->awready = 0U;
        vlSelf->wready = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSelf->arready = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr = 0U;
    }
    vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd = 0U;
    if (vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack) {
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
            = vlSelf->araddr;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd = 1U;
    }
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req 
        = ((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd) 
           | (0U != (IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr)));
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req 
        = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req));
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state;
    if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next = 4U;
            } else if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd)
                        ? 6U : 7U);
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open))
                        ? 1U : 3U);
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open) 
                              >> (3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                        >> 0xaU))))
                        ? ((vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row
                            [(3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                    >> 0xaU))] == (0x1fffU 
                                                   & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                                      >> 0xcU)))
                            ? ((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd)
                                ? 6U : 7U) : 1U) : 5U);
            }
        } else if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                        | ((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)) 
                           | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req)))
                        ? 5U : 4U);
            }
        } else {
            vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                = ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))
                    ? (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                        | (0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)))
                        ? 5U : 3U) : ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh)
                                       ? 4U : 0U));
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_axil_tb___024root___dump_triggers__act(Vsdram_axil_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsdram_axil_tb___024root___eval_triggers__act(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk__0))) 
                                     | vlSelf->__VdlySched.awaitingCurrentTime()));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->sdram_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_clk__0))));
    vlSelf->__VactTriggered.set(4U, ((~ (IData)(vlSelf->sdram_clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_clk__0)));
    vlSelf->__VactTriggered.set(5U, ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk__0))));
    vlSelf->__VactTriggered.set(6U, (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [0U] != vlSelf->__Vtrigprevexpr_hb1eda87f__0));
    vlSelf->__VactTriggered.set(7U, (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [1U] != vlSelf->__Vtrigprevexpr_hb1eda6c0__0));
    vlSelf->__VactTriggered.set(8U, (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [2U] != vlSelf->__Vtrigprevexpr_hb1eda6fd__0));
    vlSelf->__VactTriggered.set(9U, (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [3U] != vlSelf->__Vtrigprevexpr_hb1eda941__0));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk__0 
        = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk;
    vlSelf->__Vtrigprevexpr___TOP__sdram_clk__0 = vlSelf->sdram_clk;
    vlSelf->__Vtrigprevexpr_hb1eda87f__0 = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
        [0U];
    vlSelf->__Vtrigprevexpr_hb1eda6c0__0 = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
        [1U];
    vlSelf->__Vtrigprevexpr_hb1eda6fd__0 = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
        [2U];
    vlSelf->__Vtrigprevexpr_hb1eda941__0 = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
        [3U];
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(6U, 1U);
        vlSelf->__VactTriggered.set(7U, 1U);
        vlSelf->__VactTriggered.set(8U, 1U);
        vlSelf->__VactTriggered.set(9U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsdram_axil_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VlCoroutine Vsdram_axil_tb___024root___act_comb__TOP__0____Vfork_1__0(Vsdram_axil_tb___024root* vlSelf, SData/*15:0*/ __Vintraval_h408bddc2__0);

VL_INLINE_OPT void Vsdram_axil_tb___024root___act_comb__TOP__0(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_burst_mode 
        = (1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                 >> 9U));
    Vsdram_axil_tb___024root___act_comb__TOP__0____Vfork_1__0(vlSelf, vlSelf->__Vintraval_h408bddc2__0);
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0 
        = (IData)((0U == (6U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0 
        = (IData)((2U == (6U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0 
        = (IData)((0x20U == (0x60U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data 
        = vlSelf->__VassignWtmp_read_data__0;
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1 
        = ((~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg)) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2 
        = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4 
        = ((~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg)) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8 
        = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3 
        = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0) 
           & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
              >> 4U));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2 
        = ((~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
               >> 4U)) & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0));
}

VL_INLINE_OPT void Vsdram_axil_tb___024root___nba_sequent__TOP__0(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset;
    __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset = 0;
    CData/*1:0*/ __Vdlyvdim0__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0;
    __Vdlyvdim0__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 = 0;
    SData/*12:0*/ __Vdlyvval__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0;
    __Vdlyvval__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0;
    __Vdlyvset__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 = 0;
    // Body
    __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset 
        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset;
    __Vdlyvset__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt)));
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2 
        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr;
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__boot_complete) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__running = 1U;
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle = 1U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next;
    } else {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle = 0U;
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wvalid) {
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid = 1U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe = 0U;
    } else if (vlSelf->bready) {
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid = 0U;
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid) {
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid = 1U;
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata 
            = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid)
                ? (((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data) 
                    << 0x10U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r))
                : 0U);
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd = 0U;
    } else if (vlSelf->rready) {
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid = 0U;
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata = 0U;
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__open_row) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open 
            = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open) 
               | (0xfU & ((IData)(1U) << (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank))));
        __Vdlyvval__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row;
        __Vdlyvset__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 = 1U;
        __Vdlyvdim0__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank;
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_row) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open 
            = ((~ ((IData)(1U) << (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank))) 
               & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open));
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data 
            = vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__byte_misalign 
            = (1U & vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr);
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__col 
            = (0x1ffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                         >> 1U));
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe 
            = vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd 
            = vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank 
            = (3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                     >> 0xaU));
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row 
            = (0x1fffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                          >> 0xcU));
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_all_rows) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open = 0U;
    }
    if ((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh = 1U;
        __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset = 0x187U;
    } else {
        __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset 
            = (0xffffU & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset) 
                          - (IData)(1U)));
    }
    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__refresh_ack) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh = 0U;
    }
    if (__Vdlyvset__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[__Vdlyvdim0__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0] 
            = __Vdlyvval__sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row__v0;
    }
    if (vlSelf->rst) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2 = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__running = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__byte_misalign = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__col = 0U;
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid = 0U;
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid = 0U;
        vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open = 0U;
        __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset = 0x96U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset 
            = __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset;
        vlSelf->bvalid = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid;
        vlSelf->rvalid = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid;
        vlSelf->rdata = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r 
            = vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wvalid 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_wvalid;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_rvalid;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wvalid = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row = 0U;
    } else {
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset 
            = __Vdly__sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset;
        vlSelf->bvalid = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid;
        vlSelf->rvalid = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid;
        vlSelf->rdata = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r 
            = vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wvalid 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_wvalid;
        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_rvalid;
    }
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__open_row = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__refresh_ack = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__boot_complete = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd = 7U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_row = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_all_rows = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy = 0U;
    if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__open_row = 1U;
                }
            }
            if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr = 1U;
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd = 4U;
                    }
                } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd = 5U;
                }
                if ((1U & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state)))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay = 2U;
                }
            } else if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd = 3U;
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay = 1U;
            }
        } else if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd = 1U;
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay = 2U;
            }
        } else if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd = 2U;
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay = 1U;
        } else if ((0x32U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd 
                = ((0x28U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))
                    ? 2U : ((0x1eU == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))
                             ? 1U : ((0x14U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))
                                      ? 1U : ((0xaU 
                                               == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))
                                               ? 0U
                                               : 7U))));
        }
        if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__refresh_ack = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state)))) {
                    if ((0x32U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__boot_complete = 1U;
                    }
                }
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    if (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                         | (0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_row = 1U;
                    }
                    if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                                  | (0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)))))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_all_rows = 1U;
                    }
                }
            }
        }
    }
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle 
        = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt) 
           == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay));
    if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state)))) {
                    if ((1U & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh)))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy = 1U;
                    }
                }
            }
        }
    }
    vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_ack 
        = (((IData)(vlSelf->awvalid) & (IData)(vlSelf->wvalid)) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
    vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack 
        = ((IData)(vlSelf->arvalid) & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_wvalid = 0U;
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_rvalid = 0U;
    if (vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_ack) {
        vlSelf->awready = 1U;
        vlSelf->wready = 1U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSelf->arready = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data 
            = vlSelf->wdata;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr 
            = vlSelf->wstrb;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
            = vlSelf->awaddr;
    } else {
        vlSelf->awready = 0U;
        vlSelf->wready = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSelf->arready = vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr = 0U;
    }
    vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd = 0U;
    if (vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack) {
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
            = vlSelf->araddr;
        vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd = 1U;
    }
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req 
        = ((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd) 
           | (0U != (IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr)));
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req 
        = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy) 
           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req));
    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state;
    if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank;
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr 
                    = ((0x1e00U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr)) 
                       | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__col));
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_wvalid 
                        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle;
                }
                if ((1U & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state)))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_rvalid 
                        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle;
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next = 4U;
            } else if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank;
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row;
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd)
                        ? 6U : 7U);
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open))
                        ? 1U : 3U);
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open) 
                              >> (3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                        >> 0xaU))))
                        ? ((vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row
                            [(3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                    >> 0xaU))] == (0x1fffU 
                                                   & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                                      >> 0xcU)))
                            ? ((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd)
                                ? 6U : 7U) : 1U) : 5U);
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    if (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                         | (0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba 
                            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank;
                    }
                    if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                                  | (0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)))))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr 
                            = (0x400U | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr));
                    }
                } else if ((0x32U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
                    if ((0x28U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
                        vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr 
                            = (0x400U | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr));
                    } else if ((0x1eU != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
                        if ((0x14U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
                            if ((0xaU == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset))) {
                                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr = 0x21U;
                            }
                        }
                    }
                }
            }
            if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                        = (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                            | ((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)) 
                               | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req)))
                            ? 5U : 4U);
                }
            } else {
                vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next 
                    = ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state))
                        ? (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                            | (0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)))
                            ? 5U : 3U) : ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh)
                                           ? 4U : 0U));
            }
        }
    }
}

VL_INLINE_OPT void Vsdram_axil_tb___024root___nba_comb__TOP__1(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___nba_comb__TOP__1\n"); );
    // Body
    Vsdram_axil_tb___024root___act_comb__TOP__0____Vfork_1__0(vlSelf, vlSelf->__Vintraval_h408bddc2__0);
    vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data 
        = vlSelf->__VassignWtmp_read_data__0;
}
