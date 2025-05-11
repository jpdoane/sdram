// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsdram_tb__Syms.h"


VL_ATTR_COLD void Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_ctrl_if__0(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_dev_if__0(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsdram_tb___024root__trace_init_sub__TOP__0(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("sdram_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+134,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+172,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+173,0,"SDRAM_MHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+172,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+175,0,"SDADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+176,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+177,0,"CAS_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+178,0,"DEBUG_SDRAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+179,0,"tRC_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+181,0,"tRAS_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tRCD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tRP_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+185,0,"tXSR_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+187,0,"tREF_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+177,0,"DELAY_RRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+177,0,"DELAY_WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+177,0,"DELAY_RSC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+189,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+191,0,"HALF_CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+193,0,"QTR_CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+136,0,"sdram_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_ctrl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+195,0,"ADDRMASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"randint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+196,0,"bytenum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("u_sdram_controller", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+173,0,"SDRAM_MHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+197,0,"CAS_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"STARTUP_US",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+179,0,"tRC_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+181,0,"tRAS_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tRCD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tRP_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+185,0,"tXSR_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+187,0,"tREF_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+197,0,"DELAY_WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"DELAY_RRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"DELAY_RSC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+134,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_ctrl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+172,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+175,0,"DEV_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+176,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+199,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+201,0,"CNT2_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+189,0,"CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+202,0,"DELAY_STARTUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+203,0,"DELAY_REF_INTERVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+204,0,"DELAY_RC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"DELAY_RCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"DELAY_RP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+204,0,"DELAY_DAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+206,0,"SDRAM_ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+207,0,"SDRAM_PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+208,0,"SDRAM_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+209,0,"SDRAM_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+210,0,"SDRAM_MODE_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+211,0,"SDRAM_NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"SDRAM_BURST_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+213,0,"SDRAM_AUTO_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+213,0,"SDRAM_SELF_REFRESH_ENTRY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"SDRAM_SELF_REFRESH_EXIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"SDRAM_ACTIVE_POWER_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"SDRAM_POWER_DOWN_EXIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+214,0,"BOOT_DURATION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"STATE_BOOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+213,0,"STATE_PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+207,0,"STATE_MODESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+206,0,"STATE_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+208,0,"STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+209,0,"STATE_ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"STATE_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+211,0,"STATE_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+210,0,"SDMODE_BURST1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+213,0,"SDMODE_BURST2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+207,0,"SDMODE_BURST4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+206,0,"SDMODE_BURST8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+211,0,"SDMODE_BURSTPAGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+215,0,"SDMODE_SEQUENTIAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+216,0,"SDMODE_INTERLEAVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+177,0,"BURST_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+213,0,"BURST_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+217,0,"sdmode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+90,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+91,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+218,0,"new_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+93,0,"state_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+94,0,"first_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"last_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+97,0,"trigger_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"refresh_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"boot_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"booting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"valid_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"sd_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+106,0,"bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+107,0,"row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+108,0,"col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+109,0,"byte_misalign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"sd_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"sd_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"sd_rd_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"sd_rd_cas",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+219,0,"DATA_REG_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"DATA_REG_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"dqm_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sdram_model", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+178,0,"Debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+221,0,"tAC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+223,0,"tHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+225,0,"tOH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+227,0,"tMRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+181,0,"tRAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+179,0,"tRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tRCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tRP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+227,0,"tRRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+229,0,"tWRa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+183,0,"tWRp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+136,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+231,0,"BANK_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("Bank_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 1,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("Col_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 8,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("Command", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+9+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+13,0,"Dqm_reg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+14,0,"Dqm_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+15,0,"B0_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+16,0,"B1_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+17,0,"B2_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+18,0,"B3_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+19,0,"Mode_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+139,0,"Dq_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"Dq_dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"Col_temp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+22,0,"Burst_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+140,0,"Act_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"Act_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"Act_b2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"Act_b3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"Pc_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"Pc_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"Pc_b2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"Pc_b3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("Bank_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+23+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 1,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("A10_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+27+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Auto_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+148+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Read_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Write_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+152+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Count_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+35+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("RW_interrupt_read", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+39+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("RW_interrupt_write", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+156+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+43,0,"Data_in_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"Data_out_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"Bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+46,0,"Previous_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+47,0,"Row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+48,0,"Col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+49,0,"Col_brst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+160,0,"CkeZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"Sys_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"Active_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"Aref_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"Burst_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"Mode_reg_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"Prech_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"Read_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"Write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"Burst_length_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"Burst_length_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"Burst_length_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"Burst_length_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"Cas_latency_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"Cas_latency_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"Write_burst_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"Dq_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"MRD_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("WR_counter", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+52+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("WR_chk", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+56+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declQuad(c+64,0,"RC_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+66,0,"RRD_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+68,0,"RAS_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+70,0,"RAS_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+72,0,"RAS_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+74,0,"RAS_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+76,0,"RCD_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+78,0,"RCD_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+80,0,"RCD_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+82,0,"RCD_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+163,0,"RP_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+165,0,"RP_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+167,0,"RP_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+169,0,"RP_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_ctrl_if__0(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_ctrl_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+172,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+172,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"WORD_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+123,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+124,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+125,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+102,0,"rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_dev_if__0(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_init_sub__TOP__sdram_tb__DOT__sdram_dev_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+233,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+235,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+236,0,"cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"ras",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"cas",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+132,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+133,0,"ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+139,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+171,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+110,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_init_top(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_init_top\n"); );
    // Body
    Vsdram_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsdram_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsdram_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsdram_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsdram_tb___024root__trace_register(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsdram_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsdram_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsdram_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsdram_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_const_0_sub_0(Vsdram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsdram_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_const_0\n"); );
    // Init
    Vsdram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_tb___024root*>(voidSelf);
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsdram_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_const_0_sub_0(Vsdram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+172,(0x20U),32);
    bufp->fullDouble(oldp+173,(50.0));
    bufp->fullIData(oldp+175,(0x18U),32);
    bufp->fullIData(oldp+176,(9U),32);
    bufp->fullIData(oldp+177,(2U),32);
    bufp->fullIData(oldp+178,(0U),32);
    bufp->fullDouble(oldp+179,(60.0));
    bufp->fullDouble(oldp+181,(42.0));
    bufp->fullDouble(oldp+183,(15.0));
    bufp->fullDouble(oldp+185,(72.0));
    bufp->fullDouble(oldp+187,(6.40000000000000000e+07));
    bufp->fullDouble(oldp+189,(20.0));
    bufp->fullDouble(oldp+191,(10.0));
    bufp->fullDouble(oldp+193,(5.0));
    bufp->fullIData(oldp+195,(0xfffffffcU),32);
    bufp->fullIData(oldp+196,(vlSelf->sdram_tb__DOT__bytenum),32);
    bufp->fullIData(oldp+197,(2U),32);
    bufp->fullIData(oldp+198,(1U),32);
    bufp->fullIData(oldp+199,(0xcU),32);
    bufp->fullIData(oldp+200,(4U),32);
    bufp->fullIData(oldp+201,(0x10U),32);
    bufp->fullIData(oldp+202,(0x32U),32);
    bufp->fullIData(oldp+203,(0x187U),32);
    bufp->fullIData(oldp+204,(3U),32);
    bufp->fullIData(oldp+205,(1U),32);
    bufp->fullCData(oldp+206,(3U),3);
    bufp->fullCData(oldp+207,(2U),3);
    bufp->fullCData(oldp+208,(4U),3);
    bufp->fullCData(oldp+209,(5U),3);
    bufp->fullCData(oldp+210,(0U),3);
    bufp->fullCData(oldp+211,(7U),3);
    bufp->fullCData(oldp+212,(6U),3);
    bufp->fullCData(oldp+213,(1U),3);
    bufp->fullIData(oldp+214,(0x33U),32);
    bufp->fullBit(oldp+215,(0U));
    bufp->fullBit(oldp+216,(1U));
    bufp->fullSData(oldp+217,(0x21U),12);
    bufp->fullBit(oldp+218,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__new_state));
    bufp->fullIData(oldp+219,(0x20U),32);
    bufp->fullIData(oldp+220,(4U),32);
    bufp->fullDouble(oldp+221,(6.0));
    bufp->fullDouble(oldp+223,(7.0));
    bufp->fullDouble(oldp+225,(2.70000000000000018e+00));
    bufp->fullDouble(oldp+227,(40.0));
    bufp->fullDouble(oldp+229,(7.50000000000000000e+00));
    bufp->fullIData(oldp+231,(0x200000U),32);
    bufp->fullBit(oldp+232,(0U));
    bufp->fullIData(oldp+233,(0x18U),32);
    bufp->fullIData(oldp+234,(9U),32);
    bufp->fullIData(oldp+235,(0xcU),32);
    bufp->fullBit(oldp+236,(1U));
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_full_0_sub_0(Vsdram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsdram_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_full_0\n"); );
    // Init
    Vsdram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_tb___024root*>(voidSelf);
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsdram_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_full_0_sub_0(Vsdram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[0]),2);
    bufp->fullCData(oldp+2,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[1]),2);
    bufp->fullCData(oldp+3,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[2]),2);
    bufp->fullCData(oldp+4,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[3]),2);
    bufp->fullSData(oldp+5,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[0]),9);
    bufp->fullSData(oldp+6,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[1]),9);
    bufp->fullSData(oldp+7,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[2]),9);
    bufp->fullSData(oldp+8,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[3]),9);
    bufp->fullCData(oldp+9,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[0]),4);
    bufp->fullCData(oldp+10,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[1]),4);
    bufp->fullCData(oldp+11,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[2]),4);
    bufp->fullCData(oldp+12,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[3]),4);
    bufp->fullCData(oldp+13,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0),2);
    bufp->fullCData(oldp+14,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg1),2);
    bufp->fullSData(oldp+15,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr),12);
    bufp->fullSData(oldp+16,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr),12);
    bufp->fullSData(oldp+17,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr),12);
    bufp->fullSData(oldp+18,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr),12);
    bufp->fullSData(oldp+19,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg),12);
    bufp->fullSData(oldp+20,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm),16);
    bufp->fullSData(oldp+21,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp),9);
    bufp->fullSData(oldp+22,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter),9);
    bufp->fullCData(oldp+23,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[0]),2);
    bufp->fullCData(oldp+24,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[1]),2);
    bufp->fullCData(oldp+25,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[2]),2);
    bufp->fullCData(oldp+26,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[3]),2);
    bufp->fullBit(oldp+27,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[0]));
    bufp->fullBit(oldp+28,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[1]));
    bufp->fullBit(oldp+29,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[2]));
    bufp->fullBit(oldp+30,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[3]));
    bufp->fullBit(oldp+31,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[0]));
    bufp->fullBit(oldp+32,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[1]));
    bufp->fullBit(oldp+33,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[2]));
    bufp->fullBit(oldp+34,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[3]));
    bufp->fullIData(oldp+35,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[0]),32);
    bufp->fullIData(oldp+36,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[1]),32);
    bufp->fullIData(oldp+37,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[2]),32);
    bufp->fullIData(oldp+38,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[3]),32);
    bufp->fullBit(oldp+39,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0]));
    bufp->fullBit(oldp+40,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1]));
    bufp->fullBit(oldp+41,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2]));
    bufp->fullBit(oldp+42,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3]));
    bufp->fullBit(oldp+43,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable));
    bufp->fullBit(oldp+44,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable));
    bufp->fullCData(oldp+45,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank),2);
    bufp->fullCData(oldp+46,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Previous_bank),2);
    bufp->fullSData(oldp+47,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row),12);
    bufp->fullSData(oldp+48,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col),9);
    bufp->fullSData(oldp+49,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst),9);
    bufp->fullBit(oldp+50,((1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                  >> 9U))));
    bufp->fullIData(oldp+51,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk),32);
    bufp->fullIData(oldp+52,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[0]),32);
    bufp->fullIData(oldp+53,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[1]),32);
    bufp->fullIData(oldp+54,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[2]),32);
    bufp->fullIData(oldp+55,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[3]),32);
    bufp->fullQData(oldp+56,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[0]),64);
    bufp->fullQData(oldp+58,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[1]),64);
    bufp->fullQData(oldp+60,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[2]),64);
    bufp->fullQData(oldp+62,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[3]),64);
    bufp->fullQData(oldp+64,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk),64);
    bufp->fullQData(oldp+66,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RRD_chk),64);
    bufp->fullQData(oldp+68,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0),64);
    bufp->fullQData(oldp+70,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1),64);
    bufp->fullQData(oldp+72,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2),64);
    bufp->fullQData(oldp+74,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3),64);
    bufp->fullQData(oldp+76,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0),64);
    bufp->fullQData(oldp+78,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1),64);
    bufp->fullQData(oldp+80,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2),64);
    bufp->fullQData(oldp+82,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3),64);
    bufp->fullBit(oldp+84,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1));
    bufp->fullBit(oldp+85,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2));
    bufp->fullBit(oldp+86,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4));
    bufp->fullBit(oldp+87,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8));
    bufp->fullBit(oldp+88,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2));
    bufp->fullBit(oldp+89,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3));
    bufp->fullCData(oldp+90,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state),3);
    bufp->fullCData(oldp+91,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next),3);
    bufp->fullCData(oldp+92,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt),4);
    bufp->fullCData(oldp+93,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay),4);
    bufp->fullBit(oldp+94,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle));
    bufp->fullBit(oldp+95,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle));
    bufp->fullSData(oldp+96,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2),16);
    bufp->fullBit(oldp+97,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh));
    bufp->fullBit(oldp+98,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack));
    bufp->fullBit(oldp+99,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay));
    bufp->fullBit(oldp+100,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting));
    bufp->fullBit(oldp+101,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw));
    bufp->fullBit(oldp+102,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy));
    bufp->fullBit(oldp+103,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req));
    bufp->fullBit(oldp+104,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req));
    bufp->fullCData(oldp+105,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd),3);
    bufp->fullCData(oldp+106,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank),2);
    bufp->fullSData(oldp+107,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row),12);
    bufp->fullSData(oldp+108,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col),9);
    bufp->fullBit(oldp+109,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__byte_misalign));
    bufp->fullBit(oldp+110,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr));
    bufp->fullBit(oldp+111,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd));
    bufp->fullBit(oldp+112,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_reg));
    bufp->fullBit(oldp+113,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas));
    bufp->fullIData(oldp+114,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg),32);
    bufp->fullCData(oldp+115,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg),4);
    bufp->fullBit(oldp+116,((IData)((3U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+117,((IData)((1U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+118,((IData)((6U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+119,((IData)((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+120,((IData)((2U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))));
    bufp->fullBit(oldp+121,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable));
    bufp->fullBit(oldp+122,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable));
    bufp->fullCData(oldp+123,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr),4);
    bufp->fullBit(oldp+124,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd));
    bufp->fullIData(oldp+125,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr),32);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data),32);
    bufp->fullIData(oldp+127,(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data),32);
    bufp->fullBit(oldp+128,((1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd) 
                                   >> 2U))));
    bufp->fullBit(oldp+129,((1U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd) 
                                   >> 1U))));
    bufp->fullBit(oldp+130,((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullCData(oldp+131,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm),2);
    bufp->fullSData(oldp+132,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr),12);
    bufp->fullCData(oldp+133,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba),2);
    bufp->fullBit(oldp+134,(vlSelf->sdram_tb__DOT__clk));
    bufp->fullBit(oldp+135,(vlSelf->sdram_tb__DOT__rst));
    bufp->fullBit(oldp+136,(vlSelf->sdram_tb__DOT__sdram_clk));
    bufp->fullIData(oldp+137,(vlSelf->sdram_tb__DOT__randint),32);
    bufp->fullBit(oldp+138,(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid));
    bufp->fullSData(oldp+139,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg),16);
    bufp->fullBit(oldp+140,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0));
    bufp->fullBit(oldp+141,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1));
    bufp->fullBit(oldp+142,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2));
    bufp->fullBit(oldp+143,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3));
    bufp->fullBit(oldp+144,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0));
    bufp->fullBit(oldp+145,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1));
    bufp->fullBit(oldp+146,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2));
    bufp->fullBit(oldp+147,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3));
    bufp->fullBit(oldp+148,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[0]));
    bufp->fullBit(oldp+149,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[1]));
    bufp->fullBit(oldp+150,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[2]));
    bufp->fullBit(oldp+151,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[3]));
    bufp->fullBit(oldp+152,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[0]));
    bufp->fullBit(oldp+153,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[1]));
    bufp->fullBit(oldp+154,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[2]));
    bufp->fullBit(oldp+155,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[3]));
    bufp->fullBit(oldp+156,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0]));
    bufp->fullBit(oldp+157,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1]));
    bufp->fullBit(oldp+158,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2]));
    bufp->fullBit(oldp+159,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3]));
    bufp->fullBit(oldp+160,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__CkeZ));
    bufp->fullBit(oldp+161,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk));
    bufp->fullBit(oldp+162,(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                             & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk))));
    bufp->fullQData(oldp+163,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0),64);
    bufp->fullQData(oldp+165,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1),64);
    bufp->fullQData(oldp+167,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2),64);
    bufp->fullQData(oldp+169,(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3),64);
    bufp->fullSData(oldp+171,(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data),16);
}
