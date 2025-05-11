// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb__Syms.h"
#include "Vsdram_tb___024root.h"

VL_ATTR_COLD void Vsdram_tb___024root___eval_initial__TOP(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6472616dU;
    __Vtemp_1[2U] = 0x73U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[0U] = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[1U] = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[2U] = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[3U] = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[0U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[1U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[2U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[3U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3U] = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RRD_chk = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2 = 0ULL;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3 = 0ULL;
    VL_TIMEFORMAT_IINI(0xfffffff7U, 0U, std::string{" ns"}, 0xcU, vlSymsp->_vm_contextp__);
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__stl(Vsdram_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsdram_tb___024root___eval_triggers__stl(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsdram_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VlCoroutine Vsdram_tb___024root___act_comb__TOP__1____Vfork_1__0(Vsdram_tb___024root* vlSelf, CData/*0:0*/ __Vintraval_h8e9d4ac7__0);

VL_ATTR_COLD void Vsdram_tb___024root___stl_sequent__TOP__0(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay = 0U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data 
        = (0xffffU & vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg);
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_burst_mode 
        = (1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                 >> 9U));
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba = 0U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm = 0U;
    if ((1U & (~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay = 1U;
                vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm = 3U;
            }
        }
    }
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr = 0x400U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm = 
        ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw)
          ? 0U : (3U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg)));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = 0U;
    if ((4U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr = 1U;
            }
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba 
                = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank;
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr 
                = ((0xe00U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr)) 
                   | (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col));
        } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba 
                = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank;
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr 
                = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row;
        }
        if ((1U & (~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = 1U;
                if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh) {
                    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = 0U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba = 0U;
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr = 0x21U;
        }
    }
    Vsdram_tb___024root___act_comb__TOP__1____Vfork_1__0(vlSelf, vlSelf->__Vintraval_h8e9d4ac7__0);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 7U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0 
        = (IData)((0U == (6U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0 
        = (IData)((2U == (6U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0 
        = (IData)((0x20U == (0x60U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req 
        = ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd) 
           | (0U != (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr)));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
    vlSelf->sdram_tb__DOT__sdram_clk = vlSelf->__VassignWtmp_sdram_tb__DOT__sdram_clk__0;
    if ((4U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
                if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 4U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 5U;
            }
        } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 3U;
            }
        }
    } else if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 1U;
            }
        } else if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 0U;
        }
    } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 2U;
        }
    }
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable 
        = (IData)((5U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable 
        = (IData)((4U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)));
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
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state;
    if ((4U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd = 1U;
            }
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay 
                = ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))
                    ? 2U : 3U);
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 4U;
        } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
                = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw)
                    ? 6U : 7U);
        } else {
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 5U;
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 3U;
            }
        }
    } else if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 2U;
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 4U;
        } else {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 3U;
        }
    } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
            = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting)
                ? 2U : 4U);
    } else if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 1U;
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt) 
           == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle));
    vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)
            ? vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg
            : 0U);
}
