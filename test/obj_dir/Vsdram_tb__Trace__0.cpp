// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsdram_tb__Syms.h"


void Vsdram_tb___024root__trace_chg_0_sub_0(Vsdram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsdram_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_chg_0\n"); );
    // Init
    Vsdram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_tb___024root*>(voidSelf);
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsdram_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsdram_tb___024root__trace_chg_0_sub_0(Vsdram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[0]),2);
        bufp->chgCData(oldp+1,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[1]),2);
        bufp->chgCData(oldp+2,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[2]),2);
        bufp->chgCData(oldp+3,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[3]),2);
        bufp->chgSData(oldp+4,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[0]),9);
        bufp->chgSData(oldp+5,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[1]),9);
        bufp->chgSData(oldp+6,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[2]),9);
        bufp->chgSData(oldp+7,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[3]),9);
        bufp->chgCData(oldp+8,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[0]),4);
        bufp->chgCData(oldp+9,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[1]),4);
        bufp->chgCData(oldp+10,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[2]),4);
        bufp->chgCData(oldp+11,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[3]),4);
        bufp->chgCData(oldp+12,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0),2);
        bufp->chgCData(oldp+13,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg1),2);
        bufp->chgSData(oldp+14,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr),12);
        bufp->chgSData(oldp+15,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr),12);
        bufp->chgSData(oldp+16,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr),12);
        bufp->chgSData(oldp+17,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr),12);
        bufp->chgSData(oldp+18,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg),12);
        bufp->chgSData(oldp+19,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm),16);
        bufp->chgSData(oldp+20,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp),9);
        bufp->chgSData(oldp+21,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter),9);
        bufp->chgCData(oldp+22,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[0]),2);
        bufp->chgCData(oldp+23,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[1]),2);
        bufp->chgCData(oldp+24,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[2]),2);
        bufp->chgCData(oldp+25,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[3]),2);
        bufp->chgBit(oldp+26,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[0]));
        bufp->chgBit(oldp+27,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[1]));
        bufp->chgBit(oldp+28,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[2]));
        bufp->chgBit(oldp+29,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[3]));
        bufp->chgBit(oldp+30,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[0]));
        bufp->chgBit(oldp+31,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[1]));
        bufp->chgBit(oldp+32,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[2]));
        bufp->chgBit(oldp+33,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[3]));
        bufp->chgIData(oldp+34,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[0]),32);
        bufp->chgIData(oldp+35,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[1]),32);
        bufp->chgIData(oldp+36,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[2]),32);
        bufp->chgIData(oldp+37,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[3]),32);
        bufp->chgBit(oldp+38,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0]));
        bufp->chgBit(oldp+39,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1]));
        bufp->chgBit(oldp+40,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2]));
        bufp->chgBit(oldp+41,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3]));
        bufp->chgBit(oldp+42,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable));
        bufp->chgBit(oldp+43,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable));
        bufp->chgCData(oldp+44,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank),2);
        bufp->chgCData(oldp+45,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Previous_bank),2);
        bufp->chgSData(oldp+46,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row),12);
        bufp->chgSData(oldp+47,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col),9);
        bufp->chgSData(oldp+48,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst),9);
        bufp->chgBit(oldp+49,((1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                     >> 9U))));
        bufp->chgIData(oldp+50,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk),32);
        bufp->chgIData(oldp+51,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[0]),32);
        bufp->chgIData(oldp+52,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[1]),32);
        bufp->chgIData(oldp+53,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[2]),32);
        bufp->chgIData(oldp+54,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[3]),32);
        bufp->chgQData(oldp+55,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[0]),64);
        bufp->chgQData(oldp+57,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[1]),64);
        bufp->chgQData(oldp+59,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[2]),64);
        bufp->chgQData(oldp+61,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[3]),64);
        bufp->chgQData(oldp+63,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk),64);
        bufp->chgQData(oldp+65,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RRD_chk),64);
        bufp->chgQData(oldp+67,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0),64);
        bufp->chgQData(oldp+69,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1),64);
        bufp->chgQData(oldp+71,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2),64);
        bufp->chgQData(oldp+73,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3),64);
        bufp->chgQData(oldp+75,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0),64);
        bufp->chgQData(oldp+77,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1),64);
        bufp->chgQData(oldp+79,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2),64);
        bufp->chgQData(oldp+81,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3),64);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+83,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1));
        bufp->chgBit(oldp+84,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2));
        bufp->chgBit(oldp+85,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4));
        bufp->chgBit(oldp+86,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8));
        bufp->chgBit(oldp+87,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2));
        bufp->chgBit(oldp+88,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+89,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state),3);
        bufp->chgCData(oldp+90,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next),3);
        bufp->chgCData(oldp+91,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt),4);
        bufp->chgCData(oldp+92,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay),4);
        bufp->chgBit(oldp+93,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle));
        bufp->chgBit(oldp+94,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle));
        bufp->chgSData(oldp+95,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2),16);
        bufp->chgBit(oldp+96,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh));
        bufp->chgBit(oldp+97,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack));
        bufp->chgBit(oldp+98,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay));
        bufp->chgBit(oldp+99,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting));
        bufp->chgBit(oldp+100,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw));
        bufp->chgBit(oldp+101,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy));
        bufp->chgBit(oldp+102,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req));
        bufp->chgBit(oldp+103,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req));
        bufp->chgCData(oldp+104,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd),3);
        bufp->chgCData(oldp+105,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank),2);
        bufp->chgSData(oldp+106,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row),12);
        bufp->chgSData(oldp+107,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col),9);
        bufp->chgBit(oldp+108,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__byte_misalign));
        bufp->chgBit(oldp+109,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr));
        bufp->chgBit(oldp+110,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd));
        bufp->chgBit(oldp+111,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_reg));
        bufp->chgBit(oldp+112,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas));
        bufp->chgIData(oldp+113,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg),32);
        bufp->chgCData(oldp+114,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg),4);
        bufp->chgBit(oldp+115,((IData)((3U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
        bufp->chgBit(oldp+116,((IData)((1U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
        bufp->chgBit(oldp+117,((IData)((6U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
        bufp->chgBit(oldp+118,((IData)((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
        bufp->chgBit(oldp+119,((IData)((2U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
        bufp->chgBit(oldp+120,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable));
        bufp->chgBit(oldp+121,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable));
        bufp->chgCData(oldp+122,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr),4);
        bufp->chgBit(oldp+123,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd));
        bufp->chgIData(oldp+124,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr),32);
        bufp->chgIData(oldp+125,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data),32);
        bufp->chgIData(oldp+126,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data),32);
        bufp->chgBit(oldp+127,((1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd) 
                                      >> 2U))));
        bufp->chgBit(oldp+128,((1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd) 
                                      >> 1U))));
        bufp->chgBit(oldp+129,((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
        bufp->chgCData(oldp+130,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm),2);
        bufp->chgSData(oldp+131,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr),12);
        bufp->chgCData(oldp+132,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba),2);
    }
    bufp->chgBit(oldp+133,(vlSelf->sdram_tb__DOT__clk));
    bufp->chgBit(oldp+134,(vlSelf->sdram_tb__DOT__rst));
    bufp->chgBit(oldp+135,(vlSelf->sdram_tb__DOT__sdram_clk));
    bufp->chgIData(oldp+136,(vlSelf->sdram_tb__DOT__randint),32);
    bufp->chgBit(oldp+137,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid));
    bufp->chgSData(oldp+138,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg),16);
    bufp->chgBit(oldp+139,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0));
    bufp->chgBit(oldp+140,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1));
    bufp->chgBit(oldp+141,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2));
    bufp->chgBit(oldp+142,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3));
    bufp->chgBit(oldp+143,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0));
    bufp->chgBit(oldp+144,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1));
    bufp->chgBit(oldp+145,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2));
    bufp->chgBit(oldp+146,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3));
    bufp->chgBit(oldp+147,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[0]));
    bufp->chgBit(oldp+148,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[1]));
    bufp->chgBit(oldp+149,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[2]));
    bufp->chgBit(oldp+150,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[3]));
    bufp->chgBit(oldp+151,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[0]));
    bufp->chgBit(oldp+152,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[1]));
    bufp->chgBit(oldp+153,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[2]));
    bufp->chgBit(oldp+154,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[3]));
    bufp->chgBit(oldp+155,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0]));
    bufp->chgBit(oldp+156,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1]));
    bufp->chgBit(oldp+157,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2]));
    bufp->chgBit(oldp+158,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3]));
    bufp->chgBit(oldp+159,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__CkeZ));
    bufp->chgBit(oldp+160,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk));
    bufp->chgBit(oldp+161,(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                            & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk))));
    bufp->chgQData(oldp+162,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0),64);
    bufp->chgQData(oldp+164,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1),64);
    bufp->chgQData(oldp+166,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2),64);
    bufp->chgQData(oldp+168,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3),64);
    bufp->chgSData(oldp+170,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data),16);
}

void Vsdram_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_cleanup\n"); );
    // Init
    Vsdram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_tb___024root*>(voidSelf);
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
