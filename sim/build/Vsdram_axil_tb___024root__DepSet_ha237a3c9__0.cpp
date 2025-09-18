// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_axil_tb.h for the primary calling header

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb___024root.h"

VL_ATTR_COLD void Vsdram_axil_tb___024root___eval_initial__TOP(Vsdram_axil_tb___024root* vlSelf);
VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__0(Vsdram_axil_tb___024root* vlSelf);
VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1(Vsdram_axil_tb___024root* vlSelf);
VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__2(Vsdram_axil_tb___024root* vlSelf);
VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__3(Vsdram_axil_tb___024root* vlSelf);
VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__4(Vsdram_axil_tb___024root* vlSelf);
VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__5(Vsdram_axil_tb___024root* vlSelf);

void Vsdram_axil_tb___024root___eval_initial(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial\n"); );
    // Body
    Vsdram_axil_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__3(vlSelf);
    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__4(vlSelf);
    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__5(vlSelf);
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
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__0(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h893c956e__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_clk)", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           205);
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__CkeZ;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__CkeZ 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__running;
        co_await vlSelf->__VtrigSched_h893c972b__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge sdram_clk)", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           209);
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk = 0U;
    }
}

VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1(Vsdram_axil_tb___024root* vlSelf, SData/*15:0*/ __Vintraval_hb161b5f4__0);

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h2f144528__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_axil_tb.u_sdram_model.Sys_clk)", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           214);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[0U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
            [1U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
            [2U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
            [3U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[3U] = 1U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[0U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
            [1U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[1U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
            [2U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[2U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
            [3U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[3U] = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[0U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
            [1U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[1U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
            [2U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[2U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
            [3U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[3U] = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[0U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge
            [1U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[1U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge
            [2U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[2U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge
            [3U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[3U] = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[0U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge
            [1U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[1U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge
            [2U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[2U] 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge
            [3U];
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[3U] = 0U;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg0 
            = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg1;
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg1 
            = (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))
                ? (3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                             ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                >> 2U) : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))
                : 0U);
        if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [0U]) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[0U] 
                = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [0U]);
        }
        if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [1U]) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[1U] 
                = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [1U]);
        }
        if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [2U]) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[2U] 
                = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [2U]);
        }
        if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [3U]) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[3U] 
                = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [3U]);
        }
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk 
            = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk);
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[0U] 
            = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
               [0U]);
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[1U] 
            = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
               [1U]);
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[2U] 
            = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
               [2U]);
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[3U] 
            = ((IData)(1U) + vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
               [3U]);
        if ((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
            if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                              - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk)) 
                             < 66.0))) {
                VL_WRITEF("at time %t ERROR: tRC violation during Auto Refresh\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY(((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0)) 
                                < 20.0) | (VL_ITOR_D_Q(64, 
                                                       ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                        - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1)) 
                                           < 20.0)) 
                              | (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2)) 
                                 < 20.0)) | (VL_ITOR_D_Q(64, 
                                                         ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                          - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3)) 
                                             < 20.0)))) {
                VL_WRITEF("at time %t ERROR: tRP violation during Auto Refresh\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((1U & ((((~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0)) 
                                     | (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1))) 
                                    | (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2))) 
                                   | (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3)))))) {
                VL_WRITEF("at time %t ERROR: All banks must be Precharge before Auto Refresh\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk 
                = VL_TIME_UNITED_Q(1000);
        }
        if ((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
            if (VL_LIKELY(((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0) 
                             & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1)) 
                            & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2)) 
                           & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3)))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr;
            } else {
                VL_WRITEF("at time %t ERROR: all banks must be Precharge before Load Mode Register\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                              - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk)) 
                             < 66.0))) {
                VL_WRITEF("at time %t ERROR: tRC violation during Load Mode Register\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((VL_ISTOR_D_I(32, vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk) 
                             < 2.0))) {
                VL_WRITEF("at time %t ERROR: tMRD violation during Load Mode Register\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk = 0U;
        }
        if ((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
            if (((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                 & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0)) 
                                 < 20.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 0\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B0_row_addr 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk0 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0 
                    = VL_TIME_UNITED_Q(1000);
            } else if (((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                        & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1)) 
                                 < 20.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 1\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B1_row_addr 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk1 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1 
                    = VL_TIME_UNITED_Q(1000);
            } else if (((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                        & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2)) 
                                 < 20.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 2\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B2_row_addr 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk2 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2 
                    = VL_TIME_UNITED_Q(1000);
            } else if (((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                        & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3)) 
                                 < 20.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 3\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B3_row_addr 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk3 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3 
                    = VL_TIME_UNITED_Q(1000);
            } else if (VL_UNLIKELY(((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                    & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0))))) {
                VL_WRITEF("at time %t ERROR: Bank 0 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            } else if (VL_UNLIKELY(((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                    & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1))))) {
                VL_WRITEF("at time %t ERROR: Bank 1 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            } else if (VL_UNLIKELY(((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                    & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2))))) {
                VL_WRITEF("at time %t ERROR: Bank 2 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            } else if (VL_UNLIKELY(((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                    & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3))))) {
                VL_WRITEF("at time %t ERROR: Bank 3 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Previous_bank) 
                              != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RRD_chk)) 
                                < 15.0)))) {
                VL_WRITEF("at time %t ERROR: tRRD violation during Activate bank = %1#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba));
            }
            if (VL_UNLIKELY((VL_ISTOR_D_I(32, vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk) 
                             < 2.0))) {
                VL_WRITEF("at time %t ERROR: tMRD violation during Activate bank = %1#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba));
            }
            if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                              - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk)) 
                             < 66.0))) {
                VL_WRITEF("at time %t ERROR: tRC violation during Activate bank = %1#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba));
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RRD_chk 
                = VL_TIME_UNITED_Q(1000);
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Previous_bank 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba;
        }
        if ((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
            if ((0x400U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3 
                    = VL_TIME_UNITED_Q(1000);
                if (VL_UNLIKELY(((((VL_ITOR_D_Q(64, 
                                                ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                                    < 44.0) | (VL_ITOR_D_Q(64, 
                                                           ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                            - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                                               < 44.0)) 
                                  | (VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                                     < 44.0)) | (VL_ITOR_D_Q(64, 
                                                             ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                              - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                                                 < 44.0)))) {
                    VL_WRITEF("at time %t ERROR: tRAS violation during Precharge all bank\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                if (VL_UNLIKELY(((((VL_ITOR_D_Q(64, 
                                                ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk
                                                 [0U])) 
                                    < 15.0) | (VL_ITOR_D_Q(64, 
                                                           ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                            - 
                                                            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk
                                                            [1U])) 
                                               < 15.0)) 
                                  | (VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk
                                                  [2U])) 
                                     < 15.0)) | (VL_ITOR_D_Q(64, 
                                                             ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                              - 
                                                              vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk
                                                              [3U])) 
                                                 < 15.0)))) {
                    VL_WRITEF("at time %t ERROR: tWR violation during Precharge all bank\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
            } else if ((1U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr) 
                                 >> 0xaU)))) {
                if ((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                                     < 44.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 0\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0 
                        = VL_TIME_UNITED_Q(1000);
                } else if ((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                                     < 44.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 1\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1 
                        = VL_TIME_UNITED_Q(1000);
                } else if ((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                                     < 44.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 2\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2 
                        = VL_TIME_UNITED_Q(1000);
                } else if ((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                                     < 44.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 3\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3 
                        = VL_TIME_UNITED_Q(1000);
                }
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk
                                                  [vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba])) 
                                 < 15.0))) {
                    VL_WRITEF("at time %t ERROR: tWR violation during Precharge bank %1#\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9,2,(IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba));
                }
            }
            if (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                 & (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank) 
                     == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                    | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr) 
                       >> 0xaU)))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2U] = 6U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[2U] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[2U] 
                    = (1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr) 
                             >> 0xaU));
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1U] = 6U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[1U] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[1U] 
                    = (1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr) 
                             >> 0xaU));
            }
        }
        if ((6U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2U] = 8U;
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1U] = 8U;
            }
        }
        if (((5U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)) 
             | (4U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)))) {
            if (VL_UNLIKELY((((((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0)) 
                               | ((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                  & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1))) 
                              | ((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                 & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2))) 
                             | ((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                                & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3))))) {
                VL_WRITEF("at time %t ERROR: Cannot Read or Write - Bank %1# is not Activated (%1#)\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba),
                          1,vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0);
            }
            if ((5U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                }
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2U] 
                        = ((0x400U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr))
                            ? 3U : 2U);
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[2U] 
                        = (0x1ffU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr));
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[2U] 
                        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba;
                } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1U] 
                        = ((0x400U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr))
                            ? 3U : 2U);
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[1U] 
                        = (0x1ffU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr));
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[1U] 
                        = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba;
                }
            } else if ((4U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                }
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[0U] 
                    = ((0x400U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr))
                        ? 5U : 4U);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[0U] 
                    = (0x1ffU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr));
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[0U] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba;
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
            if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
                 [vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank] 
                 & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge
                 [vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank] = 1U;
            }
            if (VL_UNLIKELY(((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk0)) 
                                < 20.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 0\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
                 [vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank] 
                 & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge
                 [vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank] = 1U;
            }
            if (VL_UNLIKELY(((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk1)) 
                                < 20.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 1\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY(((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk2)) 
                                < 20.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 2\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if ((0x400U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba] = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba] = 0U;
                if ((5U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba] = 1U;
                } else if ((4U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba] = 1U;
                }
            }
            if (VL_UNLIKELY(((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk3)) 
                                < 20.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 3\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
        }
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [0U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge
             [0U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                   >= 44.0) & (((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [0U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [0U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [0U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [0U])))) 
                 | vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[0U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[0U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0U] = 0U;
            }
        }
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [1U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge
             [1U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                   >= 44.0) & (((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [1U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [1U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [1U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [1U])))) 
                 | vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [1U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[1U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[1U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1U] = 0U;
            }
        }
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [2U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge
             [2U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                   >= 44.0) & (((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [2U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [2U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [2U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [2U])))) 
                 | vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [2U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[2U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[2U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2U] = 0U;
            }
        }
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [3U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge
             [3U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                   >= 44.0) & (((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [3U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [3U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [3U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [3U])))) 
                 | vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [3U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[3U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[3U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3U] = 0U;
            }
        }
        if ((6U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
             [0U])) {
            if (((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge
                  [0U] == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank)) 
                 | vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge
                 [0U])) {
                if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
        } else if ((8U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
                    [0U])) {
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
            }
        }
        if ((1U & (~ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable)))) {
            vlSelf->__Vintraval_hb161b5f4__0 = 0U;
            Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1(vlSelf, vlSelf->__Vintraval_hb161b5f4__0);
        }
        if (((2U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
              [0U]) | (3U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
                       [0U]))) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                [0U];
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            if ((0U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                 [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B0_row_addr;
            } else if ((1U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B1_row_addr;
            } else if ((2U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B2_row_addr;
            } else if ((3U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B3_row_addr;
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter = 0U;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 1U;
        } else if (((4U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
                     [0U]) | (5U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command
                              [0U]))) {
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                [0U];
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst 
                = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            if ((0U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                 [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B0_row_addr;
            } else if ((1U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B1_row_addr;
            } else if ((2U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B2_row_addr;
            } else if ((3U == vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B3_row_addr;
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter = 0U;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 1U;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
        }
        if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
            if ((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank0
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank1
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank2
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank3
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U & (~ (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                           | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))
                           ? (3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                        ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                           >> 2U) : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))
                           : 0U)))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = ((0xff00U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm)) 
                       | (0xffU & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                    ? (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data 
                                       >> 0x10U) : vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data)));
            }
            if ((1U & (~ ((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                            | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))
                            ? (3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                         ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                            >> 2U) : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))
                            : 0U) >> 1U)))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = ((0xffU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm)) 
                       | (0xff00U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                      ? (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data 
                                         >> 0x10U) : vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data)));
            }
            if ((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank3[(
                                                                       ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                                                                        << 9U) 
                                                                       | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank2[(
                                                                       ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                                                                        << 9U) 
                                                                       | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank1[(
                                                                       ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                                                                        << 9U) 
                                                                       | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank0[(
                                                                       ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                                                                        << 9U) 
                                                                       | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((3U != (((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                         | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))
                         ? (3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                      ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                         >> 2U) : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))
                         : 0U))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank] 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank] = 0U;
            }
            co_await vlSelf->__VdlySched.delay(0x1b58ULL, 
                                               nullptr, 
                                               "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                               802);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter)));
            if ((8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                if ((8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp 
                        = ((0x1f8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)) 
                           | (7U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter) 
                                    ^ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst))));
                }
            } else {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)));
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col 
                = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2)
                    ? ((0x1feU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)) 
                       | (1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)))
                    : ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4)
                        ? ((0x1fcU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)) 
                           | (3U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)))
                        : ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8)
                            ? ((0x1f8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)) 
                               | (7U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)))
                            : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp))));
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_burst_mode) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) {
                if ((1U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) {
                if ((2U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) {
                if ((4U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) {
                if ((8U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
        } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
            if ((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank0
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank1
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank2
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank3
                    [(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg0))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = (0xff00U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm));
            }
            if ((2U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg0))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = (0xffU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm));
            }
            vlSelf->__Vintraval_h40b10aef__0 = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            co_await vlSelf->__VdlySched.delay(0x1770ULL, 
                                               nullptr, 
                                               "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                               813);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg 
                = vlSelf->__Vintraval_h40b10aef__0;
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter)));
            if ((8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                if ((8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp 
                        = ((0x1f8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)) 
                           | (7U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter) 
                                    ^ (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst))));
                }
            } else {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)));
            }
            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col 
                = ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2)
                    ? ((0x1feU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)) 
                       | (1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)))
                    : ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4)
                        ? ((0x1fcU & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)) 
                           | (3U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)))
                        : ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8)
                            ? ((0x1f8U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col)) 
                               | (7U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp)))
                            : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp))));
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_burst_mode) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) {
                if ((1U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) {
                if ((2U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) {
                if ((4U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) {
                if ((8U <= (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
        }
    }
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1(Vsdram_axil_tb___024root* vlSelf, SData/*15:0*/ __Vintraval_hb161b5f4__0) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xa8cULL, nullptr, 
                                       "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                       735);
    vlSelf->__Vdlyvval__sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 
        = __Vintraval_hb161b5f4__0;
    vlSelf->__Vdlyvset__sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 = 1U;
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__2(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h35dadf11__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h0]))", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           829);
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [0U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge
             [0U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                   >= 44.0) & ((((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [0U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [0U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [0U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [0U])))) 
                 | (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [0U] & VL_LTES_III(32, 2U, vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [0U])))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[0U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[0U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                   840);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__3(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__3\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h35dae0d2__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h1]))", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           848);
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [1U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge
             [1U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                   >= 44.0) & ((((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [1U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [1U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [1U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [1U])))) 
                 | (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [1U] & VL_LTES_III(32, 2U, vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [1U])))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[1U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[1U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                   859);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__4(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__4\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h35dadf8b__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h2]))", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           867);
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [2U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge
             [2U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                   >= 44.0) & ((((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [2U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [2U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [2U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [2U])))) 
                 | (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [2U] & VL_LTES_III(32, 2U, vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [2U])))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[2U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[2U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                   878);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__5(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_initial__TOP__Vtiming__5\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h35dadd9f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h3]))", 
                                                           "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                           886);
        if ((vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [3U] & vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge
             [3U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                   >= 44.0) & ((((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                   | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                      >> 9U)) & VL_LTES_III(32, 1U, 
                                                            vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                            [3U])) 
                                 | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [3U]))) 
                                | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [3U]))) 
                               | ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [3U])))) 
                 | (vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write
                    [3U] & VL_LTES_III(32, 2U, vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter
                                       [3U])))) {
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[3U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[3U] = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3U] = 0U;
                co_await vlSelf->__VdlySched.delay(0x1d4cULL, 
                                                   nullptr, 
                                                   "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                                   897);
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3 
                    = VL_TIME_UNITED_Q(1000);
            }
        }
    }
}

void Vsdram_axil_tb___024root___ico_sequent__TOP__0(Vsdram_axil_tb___024root* vlSelf);

void Vsdram_axil_tb___024root___eval_ico(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsdram_axil_tb___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vsdram_axil_tb___024root___eval_triggers__ico(Vsdram_axil_tb___024root* vlSelf);

bool Vsdram_axil_tb___024root___eval_phase__ico(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsdram_axil_tb___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsdram_axil_tb___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

VL_INLINE_OPT VlCoroutine Vsdram_axil_tb___024root___act_comb__TOP__0____Vfork_1__0(Vsdram_axil_tb___024root* vlSelf, SData/*15:0*/ __Vintraval_h408bddc2__0) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___act_comb__TOP__0____Vfork_1__0\n"); );
    // Body
    __Vintraval_h408bddc2__0 = vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg;
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "/home/jpdoane/sdram/sim2/../models/MT48LC8M16A2.sv", 
                                       86);
    vlSelf->__VassignWtmp_read_data__0 = __Vintraval_h408bddc2__0;
}

void Vsdram_axil_tb___024root___act_comb__TOP__0(Vsdram_axil_tb___024root* vlSelf);

void Vsdram_axil_tb___024root___eval_act(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_act\n"); );
    // Body
    if ((0x24ULL & vlSelf->__VactTriggered.word(0U))) {
        Vsdram_axil_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

VL_INLINE_OPT void Vsdram_axil_tb___024root___nba_comb__TOP__0(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_burst_mode 
        = (1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                 >> 9U));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0 
        = (IData)((0U == (6U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0 
        = (IData)((2U == (6U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0 
        = (IData)((0x20U == (0x60U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg))));
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

VL_INLINE_OPT void Vsdram_axil_tb___024root___nba_sequent__TOP__1(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->__Vdlyvset__sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg__v0) {
        vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg 
            = vlSelf->__Vdlyvval__sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg__v0;
        vlSelf->__Vdlyvset__sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg__v0 = 0U;
    }
}

void Vsdram_axil_tb___024root___nba_sequent__TOP__0(Vsdram_axil_tb___024root* vlSelf);
void Vsdram_axil_tb___024root___nba_comb__TOP__1(Vsdram_axil_tb___024root* vlSelf);

void Vsdram_axil_tb___024root___eval_nba(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_axil_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((0x24ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_axil_tb___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_axil_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x26ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsdram_axil_tb___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vsdram_axil_tb___024root___timing_resume(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___timing_resume\n"); );
    // Body
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h893c956e__0.resume("@(posedge sdram_clk)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h893c972b__0.resume("@(negedge sdram_clk)");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h2f144528__0.resume("@(posedge sdram_axil_tb.u_sdram_model.Sys_clk)");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h35dadf11__0.resume("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h0]))");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h35dae0d2__0.resume("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h1]))");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h35dadf8b__0.resume("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h2]))");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h35dadd9f__0.resume("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h3]))");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vsdram_axil_tb___024root___timing_commit(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___timing_commit\n"); );
    // Body
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h893c956e__0.commit("@(posedge sdram_clk)");
    }
    if ((! (0x10ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h893c972b__0.commit("@(negedge sdram_clk)");
    }
    if ((! (0x20ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h2f144528__0.commit("@(posedge sdram_axil_tb.u_sdram_model.Sys_clk)");
    }
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h35dadf11__0.commit("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h0]))");
    }
    if ((! (0x80ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h35dae0d2__0.commit("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h1]))");
    }
    if ((! (0x100ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h35dadf8b__0.commit("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h2]))");
    }
    if ((! (0x200ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h35dadd9f__0.commit("@([changed] (sdram_axil_tb.u_sdram_model.WR_counter[2'h3]))");
    }
}

void Vsdram_axil_tb___024root___eval_triggers__act(Vsdram_axil_tb___024root* vlSelf);

bool Vsdram_axil_tb___024root___eval_phase__act(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<10> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsdram_axil_tb___024root___eval_triggers__act(vlSelf);
    Vsdram_axil_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsdram_axil_tb___024root___timing_resume(vlSelf);
        Vsdram_axil_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsdram_axil_tb___024root___eval_phase__nba(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsdram_axil_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_axil_tb___024root___dump_triggers__ico(Vsdram_axil_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_axil_tb___024root___dump_triggers__nba(Vsdram_axil_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_axil_tb___024root___dump_triggers__act(Vsdram_axil_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsdram_axil_tb___024root___eval(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsdram_axil_tb___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/jpdoane/sdram/sim2/sdram_axil_tb.sv", 4, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsdram_axil_tb___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsdram_axil_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/jpdoane/sdram/sim2/sdram_axil_tb.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsdram_axil_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/jpdoane/sdram/sim2/sdram_axil_tb.sv", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsdram_axil_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsdram_axil_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsdram_axil_tb___024root___eval_debug_assertions(Vsdram_axil_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->sdram_clk & 0xfeU))) {
        Verilated::overWidthError("sdram_clk");}
    if (VL_UNLIKELY((vlSelf->awprot & 0xf8U))) {
        Verilated::overWidthError("awprot");}
    if (VL_UNLIKELY((vlSelf->awuser & 0xfeU))) {
        Verilated::overWidthError("awuser");}
    if (VL_UNLIKELY((vlSelf->awvalid & 0xfeU))) {
        Verilated::overWidthError("awvalid");}
    if (VL_UNLIKELY((vlSelf->wstrb & 0xf0U))) {
        Verilated::overWidthError("wstrb");}
    if (VL_UNLIKELY((vlSelf->wuser & 0xfeU))) {
        Verilated::overWidthError("wuser");}
    if (VL_UNLIKELY((vlSelf->wvalid & 0xfeU))) {
        Verilated::overWidthError("wvalid");}
    if (VL_UNLIKELY((vlSelf->bready & 0xfeU))) {
        Verilated::overWidthError("bready");}
    if (VL_UNLIKELY((vlSelf->arprot & 0xf8U))) {
        Verilated::overWidthError("arprot");}
    if (VL_UNLIKELY((vlSelf->aruser & 0xfeU))) {
        Verilated::overWidthError("aruser");}
    if (VL_UNLIKELY((vlSelf->arvalid & 0xfeU))) {
        Verilated::overWidthError("arvalid");}
    if (VL_UNLIKELY((vlSelf->rready & 0xfeU))) {
        Verilated::overWidthError("rready");}
}
#endif  // VL_DEBUG
