// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsdram_axil_tb__Syms.h"


VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("sdram_axil_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+148,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+187,0,"DEBUG_SDRAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+188,0,"SDRAM_MHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+190,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+192,0,"HALF_CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+194,0,"QTR_CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+150,0,"sdram_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_ctrl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+1,0,"rnd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("u_axil_sdram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+148,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("s_axil_wr", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("s_axil_rd", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_ctrl", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+2,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+111,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sdram_controller", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+188,0,"SDRAM_MHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+196,0,"CAS_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"STARTUP_US",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+198,0,"tRC_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+200,0,"tRAS_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+202,0,"tRCD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+202,0,"tRP_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+204,0,"tXSR_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+206,0,"tREF_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+196,0,"DELAY_WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+196,0,"DELAY_RRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+196,0,"DELAY_RSC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+148,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_ctrl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+208,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+209,0,"DEV_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+210,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+211,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+213,0,"CNT2_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+190,0,"CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+214,0,"DELAY_STARTUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+215,0,"DELAY_REF_INTERVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+216,0,"DELAY_RC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+217,0,"DELAY_RCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+217,0,"DELAY_RP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+216,0,"DELAY_DAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+218,0,"SDRAM_ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+219,0,"SDRAM_PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+220,0,"SDRAM_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+221,0,"SDRAM_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+222,0,"SDRAM_MODE_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+223,0,"SDRAM_NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+224,0,"SDRAM_BURST_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+225,0,"SDRAM_AUTO_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+225,0,"SDRAM_SELF_REFRESH_ENTRY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+224,0,"SDRAM_SELF_REFRESH_EXIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+224,0,"SDRAM_ACTIVE_POWER_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+224,0,"SDRAM_POWER_DOWN_EXIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+226,0,"BOOT_DURATION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+222,0,"STATE_BOOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+225,0,"STATE_PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+219,0,"STATE_MODESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+218,0,"STATE_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+220,0,"STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+221,0,"STATE_ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+224,0,"STATE_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+223,0,"STATE_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+222,0,"SDMODE_BURST1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+225,0,"SDMODE_BURST2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+219,0,"SDMODE_BURST4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+218,0,"SDMODE_BURST8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+223,0,"SDMODE_BURSTPAGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+227,0,"SDMODE_SEQUENTIAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+228,0,"SDMODE_INTERLEAVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+229,0,"BURST_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+225,0,"BURST_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+230,0,"sdmode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+112,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+101,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+231,0,"new_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+114,0,"state_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+115,0,"first_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"last_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+118,0,"trigger_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"refresh_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"boot_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"booting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"valid_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"sd_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+125,0,"bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+126,0,"row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+127,0,"col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+128,0,"byte_misalign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"sd_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"sd_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"sd_rd_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"sd_rd_cas",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+232,0,"DATA_REG_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+233,0,"DATA_REG_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"dqm_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sdram_model", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+187,0,"Debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+234,0,"tAC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+236,0,"tHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+238,0,"tOH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+240,0,"tMRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+242,0,"tRAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+244,0,"tRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+190,0,"tRCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+190,0,"tRP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+202,0,"tRRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+246,0,"tWRa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+202,0,"tWRp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+150,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+248,0,"BANK_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("Bank_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 1,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("Col_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 8,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("Command", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+19+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+23,0,"Dqm_reg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+24,0,"Dqm_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+25,0,"B0_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+26,0,"B1_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+27,0,"B2_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+28,0,"B3_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+29,0,"Mode_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+152,0,"Dq_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+30,0,"Dq_dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+31,0,"Col_temp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+32,0,"Burst_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+153,0,"Act_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"Act_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"Act_b2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"Act_b3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"Pc_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"Pc_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"Pc_b2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,0,"Pc_b3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("Bank_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+33+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 1,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("A10_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+37+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Auto_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+161+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Read_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+41+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Write_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+165+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Count_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+45+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("RW_interrupt_read", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+49+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("RW_interrupt_write", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+169+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+53,0,"Data_in_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"Data_out_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"Bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+56,0,"Previous_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+57,0,"Row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+58,0,"Col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+59,0,"Col_brst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+173,0,"CkeZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"Sys_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"Active_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"Aref_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"Burst_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"Mode_reg_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"Prech_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"Read_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"Write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"Burst_length_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"Burst_length_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"Burst_length_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"Burst_length_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"Cas_latency_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"Cas_latency_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"Write_burst_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"Dq_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"MRD_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("WR_counter", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+62+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("WR_chk", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+66+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declQuad(c+74,0,"RC_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+76,0,"RRD_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+78,0,"RAS_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+80,0,"RAS_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+82,0,"RAS_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+84,0,"RAS_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+86,0,"RCD_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+88,0,"RCD_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+90,0,"RCD_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+92,0,"RCD_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+176,0,"RP_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+178,0,"RP_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+180,0,"RP_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+182,0,"RP_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+208,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+208,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"WORD_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+104,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+105,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+123,0,"rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+250,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+251,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+253,0,"cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"ras",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"cas",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+145,0,"dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+146,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+147,0,"ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+152,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+185,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+129,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+232,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+232,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+233,0,"STRB_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+249,0,"AWUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"AWUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+249,0,"WUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"WUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+249,0,"BUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"BUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+249,0,"ARUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"ARUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+249,0,"RUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"RUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"awprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+255,0,"awuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+4,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+256,0,"wuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+7,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+257,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+249,0,"buser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+109,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"arprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+259,0,"aruser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+2,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+111,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+257,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+249,0,"ruser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+110,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_top(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_top\n"); );
    // Body
    Vsdram_axil_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsdram_axil_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsdram_axil_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_register(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsdram_axil_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsdram_axil_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsdram_axil_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsdram_axil_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_const_0\n"); );
    // Init
    Vsdram_axil_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_axil_tb___024root*>(voidSelf);
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsdram_axil_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+187,(0U),32);
    bufp->fullDouble(oldp+188,(50.0));
    bufp->fullDouble(oldp+190,(20.0));
    bufp->fullDouble(oldp+192,(10.0));
    bufp->fullDouble(oldp+194,(5.0));
    bufp->fullIData(oldp+196,(2U),32);
    bufp->fullIData(oldp+197,(1U),32);
    bufp->fullDouble(oldp+198,(60.0));
    bufp->fullDouble(oldp+200,(42.0));
    bufp->fullDouble(oldp+202,(15.0));
    bufp->fullDouble(oldp+204,(72.0));
    bufp->fullDouble(oldp+206,(6.40000000000000000e+07));
    bufp->fullIData(oldp+208,(0x20U),32);
    bufp->fullIData(oldp+209,(0x18U),32);
    bufp->fullIData(oldp+210,(9U),32);
    bufp->fullIData(oldp+211,(0xcU),32);
    bufp->fullIData(oldp+212,(4U),32);
    bufp->fullIData(oldp+213,(0x10U),32);
    bufp->fullIData(oldp+214,(0x32U),32);
    bufp->fullIData(oldp+215,(0x187U),32);
    bufp->fullIData(oldp+216,(3U),32);
    bufp->fullIData(oldp+217,(1U),32);
    bufp->fullCData(oldp+218,(3U),3);
    bufp->fullCData(oldp+219,(2U),3);
    bufp->fullCData(oldp+220,(4U),3);
    bufp->fullCData(oldp+221,(5U),3);
    bufp->fullCData(oldp+222,(0U),3);
    bufp->fullCData(oldp+223,(7U),3);
    bufp->fullCData(oldp+224,(6U),3);
    bufp->fullCData(oldp+225,(1U),3);
    bufp->fullIData(oldp+226,(0x33U),32);
    bufp->fullBit(oldp+227,(0U));
    bufp->fullBit(oldp+228,(1U));
    bufp->fullIData(oldp+229,(2U),32);
    bufp->fullSData(oldp+230,(0x21U),12);
    bufp->fullBit(oldp+231,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__new_state));
    bufp->fullIData(oldp+232,(0x20U),32);
    bufp->fullIData(oldp+233,(4U),32);
    bufp->fullDouble(oldp+234,(6.0));
    bufp->fullDouble(oldp+236,(7.0));
    bufp->fullDouble(oldp+238,(2.70000000000000018e+00));
    bufp->fullDouble(oldp+240,(2.0));
    bufp->fullDouble(oldp+242,(44.0));
    bufp->fullDouble(oldp+244,(66.0));
    bufp->fullDouble(oldp+246,(7.50000000000000000e+00));
    bufp->fullIData(oldp+248,(0x200000U),32);
    bufp->fullBit(oldp+249,(0U));
    bufp->fullIData(oldp+250,(0x18U),32);
    bufp->fullIData(oldp+251,(9U),32);
    bufp->fullIData(oldp+252,(0xcU),32);
    bufp->fullBit(oldp+253,(1U));
    bufp->fullCData(oldp+254,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.__PVT__awprot),3);
    bufp->fullBit(oldp+255,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.__PVT__awuser));
    bufp->fullBit(oldp+256,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.__PVT__wuser));
    bufp->fullCData(oldp+257,(0U),2);
    bufp->fullCData(oldp+258,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.__PVT__arprot),3);
    bufp->fullBit(oldp+259,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.__PVT__aruser));
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_full_0\n"); );
    // Init
    Vsdram_axil_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_axil_tb___024root*>(voidSelf);
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsdram_axil_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->sdram_axil_tb__DOT__rnd),32);
    bufp->fullBit(oldp+2,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.arvalid));
    bufp->fullIData(oldp+3,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.awaddr),32);
    bufp->fullBit(oldp+4,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.awvalid));
    bufp->fullIData(oldp+5,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.wdata),32);
    bufp->fullCData(oldp+6,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.wstrb),4);
    bufp->fullBit(oldp+7,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.wvalid));
    bufp->fullBit(oldp+8,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.bready));
    bufp->fullIData(oldp+9,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.araddr),32);
    bufp->fullBit(oldp+10,(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.rready));
    bufp->fullCData(oldp+11,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[0]),2);
    bufp->fullCData(oldp+12,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[1]),2);
    bufp->fullCData(oldp+13,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[2]),2);
    bufp->fullCData(oldp+14,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[3]),2);
    bufp->fullSData(oldp+15,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[0]),9);
    bufp->fullSData(oldp+16,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[1]),9);
    bufp->fullSData(oldp+17,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[2]),9);
    bufp->fullSData(oldp+18,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[3]),9);
    bufp->fullCData(oldp+19,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[0]),4);
    bufp->fullCData(oldp+20,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1]),4);
    bufp->fullCData(oldp+21,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2]),4);
    bufp->fullCData(oldp+22,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[3]),4);
    bufp->fullCData(oldp+23,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg0),2);
    bufp->fullCData(oldp+24,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg1),2);
    bufp->fullSData(oldp+25,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B0_row_addr),12);
    bufp->fullSData(oldp+26,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B1_row_addr),12);
    bufp->fullSData(oldp+27,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B2_row_addr),12);
    bufp->fullSData(oldp+28,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B3_row_addr),12);
    bufp->fullSData(oldp+29,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg),12);
    bufp->fullSData(oldp+30,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm),16);
    bufp->fullSData(oldp+31,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp),9);
    bufp->fullSData(oldp+32,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter),9);
    bufp->fullCData(oldp+33,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[0]),2);
    bufp->fullCData(oldp+34,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[1]),2);
    bufp->fullCData(oldp+35,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[2]),2);
    bufp->fullCData(oldp+36,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[3]),2);
    bufp->fullBit(oldp+37,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[0]));
    bufp->fullBit(oldp+38,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[1]));
    bufp->fullBit(oldp+39,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[2]));
    bufp->fullBit(oldp+40,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[3]));
    bufp->fullBit(oldp+41,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[0]));
    bufp->fullBit(oldp+42,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[1]));
    bufp->fullBit(oldp+43,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[2]));
    bufp->fullBit(oldp+44,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[3]));
    bufp->fullIData(oldp+45,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[0]),32);
    bufp->fullIData(oldp+46,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[1]),32);
    bufp->fullIData(oldp+47,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[2]),32);
    bufp->fullIData(oldp+48,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[3]),32);
    bufp->fullBit(oldp+49,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0]));
    bufp->fullBit(oldp+50,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1]));
    bufp->fullBit(oldp+51,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2]));
    bufp->fullBit(oldp+52,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3]));
    bufp->fullBit(oldp+53,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable));
    bufp->fullBit(oldp+54,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable));
    bufp->fullCData(oldp+55,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank),2);
    bufp->fullCData(oldp+56,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Previous_bank),2);
    bufp->fullSData(oldp+57,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row),12);
    bufp->fullSData(oldp+58,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col),9);
    bufp->fullSData(oldp+59,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst),9);
    bufp->fullBit(oldp+60,((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                  >> 9U))));
    bufp->fullIData(oldp+61,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk),32);
    bufp->fullIData(oldp+62,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[0]),32);
    bufp->fullIData(oldp+63,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[1]),32);
    bufp->fullIData(oldp+64,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[2]),32);
    bufp->fullIData(oldp+65,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[3]),32);
    bufp->fullQData(oldp+66,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[0]),64);
    bufp->fullQData(oldp+68,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[1]),64);
    bufp->fullQData(oldp+70,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[2]),64);
    bufp->fullQData(oldp+72,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[3]),64);
    bufp->fullQData(oldp+74,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk),64);
    bufp->fullQData(oldp+76,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RRD_chk),64);
    bufp->fullQData(oldp+78,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0),64);
    bufp->fullQData(oldp+80,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1),64);
    bufp->fullQData(oldp+82,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2),64);
    bufp->fullQData(oldp+84,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3),64);
    bufp->fullQData(oldp+86,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk0),64);
    bufp->fullQData(oldp+88,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk1),64);
    bufp->fullQData(oldp+90,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk2),64);
    bufp->fullQData(oldp+92,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk3),64);
    bufp->fullBit(oldp+94,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1));
    bufp->fullBit(oldp+95,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2));
    bufp->fullBit(oldp+96,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4));
    bufp->fullBit(oldp+97,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8));
    bufp->fullBit(oldp+98,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2));
    bufp->fullBit(oldp+99,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3));
    bufp->fullBit(oldp+100,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_req));
    bufp->fullCData(oldp+101,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next),3);
    bufp->fullBit(oldp+102,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req));
    bufp->fullBit(oldp+103,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req));
    bufp->fullCData(oldp+104,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr),4);
    bufp->fullBit(oldp+105,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd));
    bufp->fullIData(oldp+106,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr),32);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data),32);
    bufp->fullBit(oldp+108,(((IData)(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_req) 
                             & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy))));
    bufp->fullBit(oldp+109,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid));
    bufp->fullBit(oldp+110,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid));
    bufp->fullIData(oldp+111,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata),32);
    bufp->fullCData(oldp+112,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state),3);
    bufp->fullCData(oldp+113,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt),4);
    bufp->fullCData(oldp+114,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay),4);
    bufp->fullBit(oldp+115,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle));
    bufp->fullBit(oldp+116,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle));
    bufp->fullSData(oldp+117,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt2),16);
    bufp->fullBit(oldp+118,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh));
    bufp->fullBit(oldp+119,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__refresh_ack));
    bufp->fullBit(oldp+120,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__boot_delay));
    bufp->fullBit(oldp+121,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__booting));
    bufp->fullBit(oldp+122,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rw));
    bufp->fullBit(oldp+123,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
    bufp->fullCData(oldp+124,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd),3);
    bufp->fullCData(oldp+125,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank),2);
    bufp->fullSData(oldp+126,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row),12);
    bufp->fullSData(oldp+127,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__col),9);
    bufp->fullBit(oldp+128,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__byte_misalign));
    bufp->fullBit(oldp+129,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr));
    bufp->fullBit(oldp+130,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_rd));
    bufp->fullBit(oldp+131,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_rd_reg));
    bufp->fullBit(oldp+132,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_rd_cas));
    bufp->fullIData(oldp+133,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__data_reg),32);
    bufp->fullCData(oldp+134,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__dqm_reg),4);
    bufp->fullBit(oldp+135,((IData)((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+136,((IData)((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+137,((IData)((6U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+138,((IData)((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+139,((IData)((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+140,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_enable));
    bufp->fullBit(oldp+141,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_enable));
    bufp->fullBit(oldp+142,((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd) 
                                   >> 2U))));
    bufp->fullBit(oldp+143,((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd) 
                                   >> 1U))));
    bufp->fullBit(oldp+144,((1U & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullCData(oldp+145,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.dqm),2);
    bufp->fullSData(oldp+146,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.addr),12);
    bufp->fullCData(oldp+147,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.ba),2);
    bufp->fullBit(oldp+148,(vlSelf->sdram_axil_tb__DOT__clk));
    bufp->fullBit(oldp+149,(vlSelf->sdram_axil_tb__DOT__rst));
    bufp->fullBit(oldp+150,(vlSelf->sdram_axil_tb__DOT__sdram_clk));
    bufp->fullBit(oldp+151,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid));
    bufp->fullSData(oldp+152,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg),16);
    bufp->fullBit(oldp+153,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0));
    bufp->fullBit(oldp+154,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1));
    bufp->fullBit(oldp+155,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2));
    bufp->fullBit(oldp+156,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3));
    bufp->fullBit(oldp+157,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0));
    bufp->fullBit(oldp+158,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1));
    bufp->fullBit(oldp+159,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2));
    bufp->fullBit(oldp+160,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3));
    bufp->fullBit(oldp+161,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[0]));
    bufp->fullBit(oldp+162,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[1]));
    bufp->fullBit(oldp+163,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[2]));
    bufp->fullBit(oldp+164,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[3]));
    bufp->fullBit(oldp+165,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[0]));
    bufp->fullBit(oldp+166,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[1]));
    bufp->fullBit(oldp+167,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[2]));
    bufp->fullBit(oldp+168,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[3]));
    bufp->fullBit(oldp+169,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0]));
    bufp->fullBit(oldp+170,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1]));
    bufp->fullBit(oldp+171,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2]));
    bufp->fullBit(oldp+172,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3]));
    bufp->fullBit(oldp+173,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__CkeZ));
    bufp->fullBit(oldp+174,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk));
    bufp->fullBit(oldp+175,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                             & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk))));
    bufp->fullQData(oldp+176,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0),64);
    bufp->fullQData(oldp+178,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1),64);
    bufp->fullQData(oldp+180,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2),64);
    bufp->fullQData(oldp+182,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3),64);
    bufp->fullIData(oldp+184,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid)
                                ? vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__data_reg
                                : 0U)),32);
    bufp->fullSData(oldp+185,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.write_data),16);
    bufp->fullBit(oldp+186,(((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__axi_if.arvalid) 
                             & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy))));
}
