// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vsdram_axil_tb__Syms.h"


void Vsdram_axil_tb___024root__trace_chg_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vsdram_axil_tb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_chg_0\n"); );
    // Init
    Vsdram_axil_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_axil_tb___024root*>(voidSelf);
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsdram_axil_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsdram_axil_tb___024root__trace_chg_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[0]),2);
        bufp->chgCData(oldp+1,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[1]),2);
        bufp->chgCData(oldp+2,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[2]),2);
        bufp->chgCData(oldp+3,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[3]),2);
        bufp->chgSData(oldp+4,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[0]),9);
        bufp->chgSData(oldp+5,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[1]),9);
        bufp->chgSData(oldp+6,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[2]),9);
        bufp->chgSData(oldp+7,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[3]),9);
        bufp->chgCData(oldp+8,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[0]),4);
        bufp->chgCData(oldp+9,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1]),4);
        bufp->chgCData(oldp+10,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2]),4);
        bufp->chgCData(oldp+11,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[3]),4);
        bufp->chgCData(oldp+12,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg0),2);
        bufp->chgCData(oldp+13,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg1),2);
        bufp->chgSData(oldp+14,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B0_row_addr),13);
        bufp->chgSData(oldp+15,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B1_row_addr),13);
        bufp->chgSData(oldp+16,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B2_row_addr),13);
        bufp->chgSData(oldp+17,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B3_row_addr),13);
        bufp->chgSData(oldp+18,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg),13);
        bufp->chgSData(oldp+19,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm),16);
        bufp->chgSData(oldp+20,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp),9);
        bufp->chgSData(oldp+21,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter),9);
        bufp->chgCData(oldp+22,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[0]),2);
        bufp->chgCData(oldp+23,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[1]),2);
        bufp->chgCData(oldp+24,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[2]),2);
        bufp->chgCData(oldp+25,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[3]),2);
        bufp->chgBit(oldp+26,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[0]));
        bufp->chgBit(oldp+27,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[1]));
        bufp->chgBit(oldp+28,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[2]));
        bufp->chgBit(oldp+29,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[3]));
        bufp->chgBit(oldp+30,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[0]));
        bufp->chgBit(oldp+31,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[1]));
        bufp->chgBit(oldp+32,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[2]));
        bufp->chgBit(oldp+33,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[3]));
        bufp->chgIData(oldp+34,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[0]),32);
        bufp->chgIData(oldp+35,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[1]),32);
        bufp->chgIData(oldp+36,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[2]),32);
        bufp->chgIData(oldp+37,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[3]),32);
        bufp->chgBit(oldp+38,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0]));
        bufp->chgBit(oldp+39,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1]));
        bufp->chgBit(oldp+40,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2]));
        bufp->chgBit(oldp+41,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3]));
        bufp->chgBit(oldp+42,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable));
        bufp->chgBit(oldp+43,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable));
        bufp->chgCData(oldp+44,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank),2);
        bufp->chgCData(oldp+45,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Previous_bank),2);
        bufp->chgSData(oldp+46,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row),13);
        bufp->chgSData(oldp+47,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col),9);
        bufp->chgSData(oldp+48,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst),9);
        bufp->chgBit(oldp+49,((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                     >> 9U))));
        bufp->chgIData(oldp+50,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk),32);
        bufp->chgIData(oldp+51,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[0]),32);
        bufp->chgIData(oldp+52,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[1]),32);
        bufp->chgIData(oldp+53,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[2]),32);
        bufp->chgIData(oldp+54,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[3]),32);
        bufp->chgQData(oldp+55,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[0]),64);
        bufp->chgQData(oldp+57,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[1]),64);
        bufp->chgQData(oldp+59,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[2]),64);
        bufp->chgQData(oldp+61,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[3]),64);
        bufp->chgQData(oldp+63,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk),64);
        bufp->chgQData(oldp+65,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RRD_chk),64);
        bufp->chgQData(oldp+67,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0),64);
        bufp->chgQData(oldp+69,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1),64);
        bufp->chgQData(oldp+71,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2),64);
        bufp->chgQData(oldp+73,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3),64);
        bufp->chgQData(oldp+75,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk0),64);
        bufp->chgQData(oldp+77,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk1),64);
        bufp->chgQData(oldp+79,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk2),64);
        bufp->chgQData(oldp+81,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk3),64);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+83,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack));
        bufp->chgBit(oldp+84,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_ack));
        bufp->chgCData(oldp+85,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next),4);
        bufp->chgBit(oldp+86,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                               | ((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)) 
                                  | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req)))));
        bufp->chgBit(oldp+87,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req));
        bufp->chgBit(oldp+88,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req));
        bufp->chgCData(oldp+89,((3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                       >> 0xaU))),2);
        bufp->chgSData(oldp+90,((0x1fffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                            >> 0xcU))),13);
        bufp->chgSData(oldp+91,((0x1ffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                           >> 1U))),9);
        bufp->chgBit(oldp+92,((1U & vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr)));
        bufp->chgBit(oldp+93,((vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row
                               [(3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                       >> 0xaU))] == 
                               (0x1fffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                           >> 0xcU)))));
        bufp->chgIData(oldp+94,((0x1ffffffU & vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr)),25);
        bufp->chgCData(oldp+95,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr),4);
        bufp->chgBit(oldp+96,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd));
        bufp->chgIData(oldp+97,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr),32);
        bufp->chgIData(oldp+98,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[4U] 
                     | vlSelf->__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+99,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1));
        bufp->chgBit(oldp+100,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2));
        bufp->chgBit(oldp+101,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4));
        bufp->chgBit(oldp+102,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8));
        bufp->chgBit(oldp+103,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2));
        bufp->chgBit(oldp+104,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+105,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid));
        bufp->chgBit(oldp+106,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid));
        bufp->chgIData(oldp+107,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata),32);
        bufp->chgCData(oldp+108,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state),4);
        bufp->chgCData(oldp+109,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt),4);
        bufp->chgCData(oldp+110,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay),4);
        bufp->chgBit(oldp+111,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle));
        bufp->chgBit(oldp+112,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle));
        bufp->chgSData(oldp+113,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset),16);
        bufp->chgBit(oldp+114,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh));
        bufp->chgBit(oldp+115,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__refresh_ack));
        bufp->chgBit(oldp+116,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__boot_complete));
        bufp->chgBit(oldp+117,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__open_row));
        bufp->chgBit(oldp+118,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_row));
        bufp->chgBit(oldp+119,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_all_rows));
        bufp->chgBit(oldp+120,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd));
        bufp->chgBit(oldp+121,((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))));
        bufp->chgCData(oldp+122,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe),4);
        bufp->chgBit(oldp+123,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
        bufp->chgBit(oldp+124,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_wvalid));
        bufp->chgBit(oldp+125,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_rvalid));
        bufp->chgBit(oldp+126,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid));
        bufp->chgBit(oldp+127,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wvalid));
        bufp->chgCData(oldp+128,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd),3);
        bufp->chgCData(oldp+129,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank),2);
        bufp->chgCData(oldp+130,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba),2);
        bufp->chgSData(oldp+131,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row),13);
        bufp->chgSData(oldp+132,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr),13);
        bufp->chgSData(oldp+133,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__col),9);
        bufp->chgBit(oldp+134,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__byte_misalign));
        bufp->chgIData(oldp+135,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data),32);
        bufp->chgCData(oldp+136,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open),4);
        bufp->chgSData(oldp+137,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[0]),13);
        bufp->chgSData(oldp+138,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[1]),13);
        bufp->chgSData(oldp+139,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[2]),13);
        bufp->chgSData(oldp+140,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[3]),13);
        bufp->chgBit(oldp+141,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr));
        bufp->chgSData(oldp+142,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r),16);
        bufp->chgBit(oldp+143,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__running));
        bufp->chgCData(oldp+144,((3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                            ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                               >> 2U)
                                            : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))),2);
        bufp->chgSData(oldp+145,((0xffffU & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                              ? (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data 
                                                 >> 0x10U)
                                              : vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data))),16);
        bufp->chgBit(oldp+146,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                                | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))));
        bufp->chgBit(oldp+147,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2));
        bufp->chgCData(oldp+148,((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                                   | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))
                                   ? (3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                                ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                                   >> 2U)
                                                : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))
                                   : 0U)),2);
        bufp->chgBit(oldp+149,((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgBit(oldp+150,((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgBit(oldp+151,((6U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgBit(oldp+152,((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgBit(oldp+153,((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgBit(oldp+154,((5U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgBit(oldp+155,((4U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    }
    bufp->chgBit(oldp+156,(vlSelf->clk));
    bufp->chgBit(oldp+157,(vlSelf->rst));
    bufp->chgBit(oldp+158,(vlSelf->sdram_clk));
    bufp->chgIData(oldp+159,(vlSelf->awaddr),32);
    bufp->chgCData(oldp+160,(vlSelf->awprot),3);
    bufp->chgBit(oldp+161,(vlSelf->awuser));
    bufp->chgBit(oldp+162,(vlSelf->awvalid));
    bufp->chgBit(oldp+163,(vlSelf->awready));
    bufp->chgIData(oldp+164,(vlSelf->wdata),32);
    bufp->chgCData(oldp+165,(vlSelf->wstrb),4);
    bufp->chgBit(oldp+166,(vlSelf->wuser));
    bufp->chgBit(oldp+167,(vlSelf->wvalid));
    bufp->chgBit(oldp+168,(vlSelf->wready));
    bufp->chgCData(oldp+169,(vlSelf->bresp),2);
    bufp->chgBit(oldp+170,(vlSelf->buser));
    bufp->chgBit(oldp+171,(vlSelf->bvalid));
    bufp->chgBit(oldp+172,(vlSelf->bready));
    bufp->chgIData(oldp+173,(vlSelf->araddr),32);
    bufp->chgCData(oldp+174,(vlSelf->arprot),3);
    bufp->chgBit(oldp+175,(vlSelf->aruser));
    bufp->chgBit(oldp+176,(vlSelf->arvalid));
    bufp->chgBit(oldp+177,(vlSelf->arready));
    bufp->chgIData(oldp+178,(vlSelf->rdata),32);
    bufp->chgCData(oldp+179,(vlSelf->rresp),2);
    bufp->chgBit(oldp+180,(vlSelf->ruser));
    bufp->chgBit(oldp+181,(vlSelf->rvalid));
    bufp->chgBit(oldp+182,(vlSelf->rready));
    bufp->chgBit(oldp+183,(((IData)(vlSelf->awvalid) 
                            & (IData)(vlSelf->wvalid))));
    bufp->chgIData(oldp+184,((((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data) 
                               << 0x10U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r))),32);
    bufp->chgSData(oldp+185,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data),16);
    bufp->chgSData(oldp+186,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg),16);
    bufp->chgBit(oldp+187,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0));
    bufp->chgBit(oldp+188,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1));
    bufp->chgBit(oldp+189,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2));
    bufp->chgBit(oldp+190,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3));
    bufp->chgBit(oldp+191,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0));
    bufp->chgBit(oldp+192,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1));
    bufp->chgBit(oldp+193,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2));
    bufp->chgBit(oldp+194,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3));
    bufp->chgBit(oldp+195,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[0]));
    bufp->chgBit(oldp+196,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[1]));
    bufp->chgBit(oldp+197,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[2]));
    bufp->chgBit(oldp+198,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[3]));
    bufp->chgBit(oldp+199,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[0]));
    bufp->chgBit(oldp+200,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[1]));
    bufp->chgBit(oldp+201,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[2]));
    bufp->chgBit(oldp+202,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[3]));
    bufp->chgBit(oldp+203,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0]));
    bufp->chgBit(oldp+204,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1]));
    bufp->chgBit(oldp+205,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2]));
    bufp->chgBit(oldp+206,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3]));
    bufp->chgBit(oldp+207,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__CkeZ));
    bufp->chgBit(oldp+208,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk));
    bufp->chgBit(oldp+209,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                            & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk))));
    bufp->chgQData(oldp+210,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0),64);
    bufp->chgQData(oldp+212,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1),64);
    bufp->chgQData(oldp+214,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2),64);
    bufp->chgQData(oldp+216,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3),64);
    bufp->chgIData(oldp+218,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid)
                               ? (((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data) 
                                   << 0x10U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r))
                               : 0U)),32);
}

void Vsdram_axil_tb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_cleanup\n"); );
    // Init
    Vsdram_axil_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_axil_tb___024root*>(voidSelf);
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
