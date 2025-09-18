// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vsdram_axil_tb__Syms.h"


VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+157,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"sdram_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+160,0,"awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"awprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+162,0,"awuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+163,0,"awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+167,0,"wuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+168,0,"wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+170,0,"bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+171,0,"buser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+172,0,"bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+174,0,"araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"arprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+176,0,"aruser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+177,0,"arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+181,0,"ruser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+182,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_axil_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+220,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+221,0,"STRB_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"AWUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"AWUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"WUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"WUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"BUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"BUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"ARUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"ARUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"RUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"RUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+224,0,"FREQ_MHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+157,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"sdram_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+160,0,"awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"awprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+162,0,"awuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+163,0,"awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+167,0,"wuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+168,0,"wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+170,0,"bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+171,0,"buser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+172,0,"bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+174,0,"araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"arprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+176,0,"aruser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+177,0,"arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+181,0,"ruser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+182,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_ctrl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_axil_sdram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+157,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("axi_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_ctrl", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+226,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+226,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+177,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"rd_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"wr_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+108,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sdram_controller", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+224,0,"FREQ_MHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+227,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+228,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+229,0,"BANK_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+229,0,"CAS_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+230,0,"STARTUP_US",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+232,0,"tRC_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+234,0,"tRAS_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+236,0,"tRCD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+236,0,"tRP_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+238,0,"tXSR_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+240,0,"tREF_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+229,0,"DELAY_WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+229,0,"DELAY_RRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+229,0,"DELAY_RSC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+157,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ctrl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+242,0,"DEV_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+243,0,"N_BANKS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+226,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+226,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+243,0,"WORD_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+243,0,"CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+244,0,"CNTRST_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+245,0,"CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+247,0,"DELAY_STARTUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+248,0,"DELAY_REF_INTERVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+249,0,"DELAY_RC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+250,0,"DELAY_RCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+250,0,"DELAY_RP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+251,0,"CTRL_ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+252,0,"CTRL_PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+253,0,"CTRL_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+254,0,"CTRL_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+255,0,"CTRL_MODE_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+256,0,"CTRL_NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+257,0,"CTRL_BURST_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+258,0,"CTRL_AUTO_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+259,0,"STATE_BOOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+260,0,"STATE_PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+261,0,"STATE_MODESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+262,0,"STATE_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+263,0,"STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+264,0,"STATE_ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+265,0,"STATE_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+266,0,"STATE_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+267,0,"STATE_READ2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+268,0,"STATE_WRITE2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+255,0,"SDMODE_BURST1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+258,0,"SDMODE_BURST2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+252,0,"SDMODE_BURST4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+251,0,"SDMODE_BURST8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+256,0,"SDMODE_BURSTPAGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+269,0,"SDMODE_SEQUENTIAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+270,0,"SDMODE_INTERLEAVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+229,0,"BURST_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+258,0,"BURST_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+271,0,"sdmode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+109,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+86,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+272,0,"state_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+273,0,"new_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+111,0,"state_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+112,0,"first_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"last_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+114,0,"cnt_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+115,0,"trigger_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"refresh_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"boot_complete",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"open_row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"close_row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"close_all_rows",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+123,0,"wr_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+124,0,"rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"set_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"set_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"valid_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"sd_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+130,0,"bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+90,0,"bank_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+131,0,"sd_ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+132,0,"row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+91,0,"row_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+133,0,"sd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+134,0,"col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+92,0,"col_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+135,0,"byte_misalign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"byte_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"row_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"row_open",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("active_row", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+138+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+142,0,"sd_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+185,0,"read_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+143,0,"read_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+144,0,"running",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"ctrl_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+145,0,"wr_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+146,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+147,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("genblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+148,0,"sd_wr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_sdram_model", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+274,0,"Debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+275,0,"IO_LATENCY_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+277,0,"tAC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+279,0,"tHZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+281,0,"tOH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+283,0,"tMRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+285,0,"tRAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+287,0,"tRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+245,0,"tRCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+245,0,"tRP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+236,0,"tRRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+289,0,"tWRa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+236,0,"tWRp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+159,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdram_dev_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+291,0,"dev_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"dev_ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+293,0,"dev_BANK_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+294,0,"dev_COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+295,0,"BANK_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declDouble(c+296,0,"READ_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+187,0,"dev_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+144,0,"dev_cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"dev_cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"dev_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+149,0,"dev_dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+133,0,"dev_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+131,0,"dev_ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+146,0,"dev_write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+147,0,"dev_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    tracep->declBus(c+15,0,"B0_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+16,0,"B1_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+17,0,"B2_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+18,0,"B3_row_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+19,0,"Mode_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+187,0,"Dq_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"Dq_dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"Col_temp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+22,0,"Burst_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+188,0,"Act_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"Act_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"Act_b2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"Act_b3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"Pc_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"Pc_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"Pc_b2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"Pc_b3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
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
        tracep->declBit(c+196+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Read_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("Write_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+200+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
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
        tracep->declBit(c+204+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+43,0,"Data_in_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"Data_out_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"Bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+46,0,"Previous_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+47,0,"Row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+48,0,"Col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+49,0,"Col_brst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+208,0,"CkeZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"Sys_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"Active_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"Aref_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"Burst_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"Mode_reg_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"Prech_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"Read_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"Write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"Burst_length_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"Burst_length_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"Burst_length_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"Burst_length_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"Cas_latency_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"Cas_latency_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"Write_burst_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"Dq_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    tracep->declQuad(c+211,0,"RP_chk0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+213,0,"RP_chk1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+215,0,"RP_chk2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->declQuad(c+217,0,"RP_chk3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, false,-1, 63,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_ctrl_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+226,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+226,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+243,0,"WORD_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+97,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+124,0,"rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+219,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__sdram_dev_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+291,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+293,0,"BANK_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+294,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+144,0,"cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+149,0,"dqm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+133,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+131,0,"ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+186,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+146,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+147,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_sub__TOP__sdram_axil_tb__DOT__axi_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+220,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+221,0,"STRB_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"AWUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"AWUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"WUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"WUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"BUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"BUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"ARUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"ARUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"RUSER_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"RUSER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"awprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+162,0,"awuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+163,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+167,0,"wuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+168,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+298,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+222,0,"buser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+106,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+174,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"arprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+176,0,"aruser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+177,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+108,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+298,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+222,0,"ruser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+107,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_init_top(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_init_top\n"); );
    // Body
    Vsdram_axil_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vsdram_axil_tb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vsdram_axil_tb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_register(Vsdram_axil_tb___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsdram_axil_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsdram_axil_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsdram_axil_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsdram_axil_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_const_0\n"); );
    // Init
    Vsdram_axil_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_axil_tb___024root*>(voidSelf);
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsdram_axil_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_const_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+220,(0x20U),32);
    bufp->fullIData(oldp+221,(4U),32);
    bufp->fullBit(oldp+222,(0U));
    bufp->fullIData(oldp+223,(1U),32);
    bufp->fullDouble(oldp+224,(50.0));
    bufp->fullIData(oldp+226,(0x20U),32);
    bufp->fullIData(oldp+227,(9U),32);
    bufp->fullIData(oldp+228,(0xdU),32);
    bufp->fullIData(oldp+229,(2U),32);
    bufp->fullDouble(oldp+230,(1.0));
    bufp->fullDouble(oldp+232,(60.0));
    bufp->fullDouble(oldp+234,(42.0));
    bufp->fullDouble(oldp+236,(15.0));
    bufp->fullDouble(oldp+238,(72.0));
    bufp->fullDouble(oldp+240,(6.40000000000000000e+07));
    bufp->fullIData(oldp+242,(0x18U),32);
    bufp->fullIData(oldp+243,(4U),32);
    bufp->fullIData(oldp+244,(0x10U),32);
    bufp->fullDouble(oldp+245,(20.0));
    bufp->fullIData(oldp+247,(0x96U),32);
    bufp->fullIData(oldp+248,(0x187U),32);
    bufp->fullIData(oldp+249,(3U),32);
    bufp->fullIData(oldp+250,(1U),32);
    bufp->fullCData(oldp+251,(3U),3);
    bufp->fullCData(oldp+252,(2U),3);
    bufp->fullCData(oldp+253,(4U),3);
    bufp->fullCData(oldp+254,(5U),3);
    bufp->fullCData(oldp+255,(0U),3);
    bufp->fullCData(oldp+256,(7U),3);
    bufp->fullCData(oldp+257,(6U),3);
    bufp->fullCData(oldp+258,(1U),3);
    bufp->fullCData(oldp+259,(0U),4);
    bufp->fullCData(oldp+260,(1U),4);
    bufp->fullCData(oldp+261,(2U),4);
    bufp->fullCData(oldp+262,(3U),4);
    bufp->fullCData(oldp+263,(4U),4);
    bufp->fullCData(oldp+264,(5U),4);
    bufp->fullCData(oldp+265,(6U),4);
    bufp->fullCData(oldp+266,(7U),4);
    bufp->fullCData(oldp+267,(8U),4);
    bufp->fullCData(oldp+268,(9U),4);
    bufp->fullBit(oldp+269,(0U));
    bufp->fullBit(oldp+270,(1U));
    bufp->fullSData(oldp+271,(0x21U),13);
    bufp->fullCData(oldp+272,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_req),4);
    bufp->fullBit(oldp+273,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__new_state));
    bufp->fullIData(oldp+274,(0U),32);
    bufp->fullDouble(oldp+275,(5.0));
    bufp->fullDouble(oldp+277,(6.0));
    bufp->fullDouble(oldp+279,(7.0));
    bufp->fullDouble(oldp+281,(2.70000000000000018e+00));
    bufp->fullDouble(oldp+283,(2.0));
    bufp->fullDouble(oldp+285,(44.0));
    bufp->fullDouble(oldp+287,(66.0));
    bufp->fullDouble(oldp+289,(7.50000000000000000e+00));
    bufp->fullIData(oldp+291,(0x18U),32);
    bufp->fullIData(oldp+292,(0xdU),32);
    bufp->fullIData(oldp+293,(2U),32);
    bufp->fullIData(oldp+294,(9U),32);
    bufp->fullIData(oldp+295,(0x400000U),32);
    bufp->fullDouble(oldp+296,(10.0));
    bufp->fullCData(oldp+298,(0U),2);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_full_0\n"); );
    // Init
    Vsdram_axil_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_axil_tb___024root*>(voidSelf);
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsdram_axil_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsdram_axil_tb___024root__trace_full_0_sub_0(Vsdram_axil_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_axil_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[0]),2);
    bufp->fullCData(oldp+2,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[1]),2);
    bufp->fullCData(oldp+3,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[2]),2);
    bufp->fullCData(oldp+4,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_addr[3]),2);
    bufp->fullSData(oldp+5,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[0]),9);
    bufp->fullSData(oldp+6,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[1]),9);
    bufp->fullSData(oldp+7,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[2]),9);
    bufp->fullSData(oldp+8,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_addr[3]),9);
    bufp->fullCData(oldp+9,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[0]),4);
    bufp->fullCData(oldp+10,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[1]),4);
    bufp->fullCData(oldp+11,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[2]),4);
    bufp->fullCData(oldp+12,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Command[3]),4);
    bufp->fullCData(oldp+13,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg0),2);
    bufp->fullCData(oldp+14,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dqm_reg1),2);
    bufp->fullSData(oldp+15,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B0_row_addr),13);
    bufp->fullSData(oldp+16,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B1_row_addr),13);
    bufp->fullSData(oldp+17,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B2_row_addr),13);
    bufp->fullSData(oldp+18,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__B3_row_addr),13);
    bufp->fullSData(oldp+19,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg),13);
    bufp->fullSData(oldp+20,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_dqm),16);
    bufp->fullSData(oldp+21,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_temp),9);
    bufp->fullSData(oldp+22,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_counter),9);
    bufp->fullCData(oldp+23,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[0]),2);
    bufp->fullCData(oldp+24,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[1]),2);
    bufp->fullCData(oldp+25,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[2]),2);
    bufp->fullCData(oldp+26,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank_precharge[3]),2);
    bufp->fullBit(oldp+27,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[0]));
    bufp->fullBit(oldp+28,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[1]));
    bufp->fullBit(oldp+29,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[2]));
    bufp->fullBit(oldp+30,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__A10_precharge[3]));
    bufp->fullBit(oldp+31,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[0]));
    bufp->fullBit(oldp+32,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[1]));
    bufp->fullBit(oldp+33,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[2]));
    bufp->fullBit(oldp+34,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Read_precharge[3]));
    bufp->fullIData(oldp+35,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[0]),32);
    bufp->fullIData(oldp+36,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[1]),32);
    bufp->fullIData(oldp+37,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[2]),32);
    bufp->fullIData(oldp+38,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Count_precharge[3]),32);
    bufp->fullBit(oldp+39,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0]));
    bufp->fullBit(oldp+40,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1]));
    bufp->fullBit(oldp+41,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2]));
    bufp->fullBit(oldp+42,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3]));
    bufp->fullBit(oldp+43,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable));
    bufp->fullBit(oldp+44,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_out_enable));
    bufp->fullCData(oldp+45,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Bank),2);
    bufp->fullCData(oldp+46,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Previous_bank),2);
    bufp->fullSData(oldp+47,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Row),13);
    bufp->fullSData(oldp+48,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col),9);
    bufp->fullSData(oldp+49,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Col_brst),9);
    bufp->fullBit(oldp+50,((1U & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Mode_reg) 
                                  >> 9U))));
    bufp->fullIData(oldp+51,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__MRD_chk),32);
    bufp->fullIData(oldp+52,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[0]),32);
    bufp->fullIData(oldp+53,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[1]),32);
    bufp->fullIData(oldp+54,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[2]),32);
    bufp->fullIData(oldp+55,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_counter[3]),32);
    bufp->fullQData(oldp+56,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[0]),64);
    bufp->fullQData(oldp+58,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[1]),64);
    bufp->fullQData(oldp+60,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[2]),64);
    bufp->fullQData(oldp+62,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__WR_chk[3]),64);
    bufp->fullQData(oldp+64,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RC_chk),64);
    bufp->fullQData(oldp+66,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RRD_chk),64);
    bufp->fullQData(oldp+68,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk0),64);
    bufp->fullQData(oldp+70,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk1),64);
    bufp->fullQData(oldp+72,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk2),64);
    bufp->fullQData(oldp+74,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RAS_chk3),64);
    bufp->fullQData(oldp+76,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk0),64);
    bufp->fullQData(oldp+78,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk1),64);
    bufp->fullQData(oldp+80,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk2),64);
    bufp->fullQData(oldp+82,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RCD_chk3),64);
    bufp->fullBit(oldp+84,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rd_ack));
    bufp->fullBit(oldp+85,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__wr_ack));
    bufp->fullCData(oldp+86,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_next),4);
    bufp->fullBit(oldp+87,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd) 
                            | ((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe)) 
                               | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req)))));
    bufp->fullBit(oldp+88,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__req));
    bufp->fullBit(oldp+89,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__valid_req));
    bufp->fullCData(oldp+90,((3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                    >> 0xaU))),2);
    bufp->fullSData(oldp+91,((0x1fffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                         >> 0xcU))),13);
    bufp->fullSData(oldp+92,((0x1ffU & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                        >> 1U))),9);
    bufp->fullBit(oldp+93,((1U & vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr)));
    bufp->fullBit(oldp+94,((vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row
                            [(3U & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                    >> 0xaU))] == (0x1fffU 
                                                   & (vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr 
                                                      >> 0xcU)))));
    bufp->fullIData(oldp+95,((0x1ffffffU & vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr)),25);
    bufp->fullCData(oldp+96,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.wr),4);
    bufp->fullBit(oldp+97,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.rd));
    bufp->fullIData(oldp+98,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.addr),32);
    bufp->fullIData(oldp+99,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_ctrl_if.write_data),32);
    bufp->fullBit(oldp+100,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_1));
    bufp->fullBit(oldp+101,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_2));
    bufp->fullBit(oldp+102,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_4));
    bufp->fullBit(oldp+103,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Burst_length_8));
    bufp->fullBit(oldp+104,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_2));
    bufp->fullBit(oldp+105,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Cas_latency_3));
    bufp->fullBit(oldp+106,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__bvalid));
    bufp->fullBit(oldp+107,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rvalid));
    bufp->fullIData(oldp+108,(vlSelf->sdram_axil_tb__DOT__u_axil_sdram__DOT__rdata),32);
    bufp->fullCData(oldp+109,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state),4);
    bufp->fullCData(oldp+110,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt),4);
    bufp->fullCData(oldp+111,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__state_delay),4);
    bufp->fullBit(oldp+112,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__first_cycle));
    bufp->fullBit(oldp+113,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__last_cycle));
    bufp->fullSData(oldp+114,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__cnt_reset),16);
    bufp->fullBit(oldp+115,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__trigger_refresh));
    bufp->fullBit(oldp+116,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__refresh_ack));
    bufp->fullBit(oldp+117,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__boot_complete));
    bufp->fullBit(oldp+118,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__open_row));
    bufp->fullBit(oldp+119,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_row));
    bufp->fullBit(oldp+120,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__close_all_rows));
    bufp->fullBit(oldp+121,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rd));
    bufp->fullBit(oldp+122,((0U != (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))));
    bufp->fullCData(oldp+123,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe),4);
    bufp->fullBit(oldp+124,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rdy));
    bufp->fullBit(oldp+125,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_wvalid));
    bufp->fullBit(oldp+126,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__set_rvalid));
    bufp->fullBit(oldp+127,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid));
    bufp->fullBit(oldp+128,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wvalid));
    bufp->fullCData(oldp+129,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd),3);
    bufp->fullCData(oldp+130,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__bank),2);
    bufp->fullCData(oldp+131,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_ba),2);
    bufp->fullSData(oldp+132,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row),13);
    bufp->fullSData(oldp+133,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_addr),13);
    bufp->fullSData(oldp+134,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__col),9);
    bufp->fullBit(oldp+135,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__byte_misalign));
    bufp->fullIData(oldp+136,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data),32);
    bufp->fullCData(oldp+137,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__row_open),4);
    bufp->fullSData(oldp+138,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[0]),13);
    bufp->fullSData(oldp+139,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[1]),13);
    bufp->fullSData(oldp+140,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[2]),13);
    bufp->fullSData(oldp+141,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__active_row[3]),13);
    bufp->fullBit(oldp+142,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr));
    bufp->fullSData(oldp+143,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r),16);
    bufp->fullBit(oldp+144,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__running));
    bufp->fullCData(oldp+145,((3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                         ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                            >> 2U) : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))),2);
    bufp->fullSData(oldp+146,((0xffffU & ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                           ? (vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data 
                                              >> 0x10U)
                                           : vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__write_data))),16);
    bufp->fullBit(oldp+147,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                             | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))));
    bufp->fullBit(oldp+148,(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2));
    bufp->fullCData(oldp+149,((((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2) 
                                | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_wr))
                                ? (3U & (~ ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__genblk2__DOT__sd_wr2)
                                             ? ((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe) 
                                                >> 2U)
                                             : (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__wr_strobe))))
                                : 0U)),2);
    bufp->fullBit(oldp+150,((3U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+151,((1U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+152,((6U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+153,((0U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+154,((2U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+155,((5U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+156,((4U == (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__sd_cmd))));
    bufp->fullBit(oldp+157,(vlSelf->clk));
    bufp->fullBit(oldp+158,(vlSelf->rst));
    bufp->fullBit(oldp+159,(vlSelf->sdram_clk));
    bufp->fullIData(oldp+160,(vlSelf->awaddr),32);
    bufp->fullCData(oldp+161,(vlSelf->awprot),3);
    bufp->fullBit(oldp+162,(vlSelf->awuser));
    bufp->fullBit(oldp+163,(vlSelf->awvalid));
    bufp->fullBit(oldp+164,(vlSelf->awready));
    bufp->fullIData(oldp+165,(vlSelf->wdata),32);
    bufp->fullCData(oldp+166,(vlSelf->wstrb),4);
    bufp->fullBit(oldp+167,(vlSelf->wuser));
    bufp->fullBit(oldp+168,(vlSelf->wvalid));
    bufp->fullBit(oldp+169,(vlSelf->wready));
    bufp->fullCData(oldp+170,(vlSelf->bresp),2);
    bufp->fullBit(oldp+171,(vlSelf->buser));
    bufp->fullBit(oldp+172,(vlSelf->bvalid));
    bufp->fullBit(oldp+173,(vlSelf->bready));
    bufp->fullIData(oldp+174,(vlSelf->araddr),32);
    bufp->fullCData(oldp+175,(vlSelf->arprot),3);
    bufp->fullBit(oldp+176,(vlSelf->aruser));
    bufp->fullBit(oldp+177,(vlSelf->arvalid));
    bufp->fullBit(oldp+178,(vlSelf->arready));
    bufp->fullIData(oldp+179,(vlSelf->rdata),32);
    bufp->fullCData(oldp+180,(vlSelf->rresp),2);
    bufp->fullBit(oldp+181,(vlSelf->ruser));
    bufp->fullBit(oldp+182,(vlSelf->rvalid));
    bufp->fullBit(oldp+183,(vlSelf->rready));
    bufp->fullBit(oldp+184,(((IData)(vlSelf->awvalid) 
                             & (IData)(vlSelf->wvalid))));
    bufp->fullIData(oldp+185,((((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data) 
                                << 0x10U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r))),32);
    bufp->fullSData(oldp+186,(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data),16);
    bufp->fullSData(oldp+187,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Dq_reg),16);
    bufp->fullBit(oldp+188,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b0));
    bufp->fullBit(oldp+189,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b1));
    bufp->fullBit(oldp+190,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b2));
    bufp->fullBit(oldp+191,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Act_b3));
    bufp->fullBit(oldp+192,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b0));
    bufp->fullBit(oldp+193,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b1));
    bufp->fullBit(oldp+194,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b2));
    bufp->fullBit(oldp+195,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Pc_b3));
    bufp->fullBit(oldp+196,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[0]));
    bufp->fullBit(oldp+197,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[1]));
    bufp->fullBit(oldp+198,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[2]));
    bufp->fullBit(oldp+199,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Auto_precharge[3]));
    bufp->fullBit(oldp+200,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[0]));
    bufp->fullBit(oldp+201,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[1]));
    bufp->fullBit(oldp+202,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[2]));
    bufp->fullBit(oldp+203,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Write_precharge[3]));
    bufp->fullBit(oldp+204,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[0]));
    bufp->fullBit(oldp+205,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[1]));
    bufp->fullBit(oldp+206,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[2]));
    bufp->fullBit(oldp+207,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[3]));
    bufp->fullBit(oldp+208,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__CkeZ));
    bufp->fullBit(oldp+209,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk));
    bufp->fullBit(oldp+210,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                             & (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__Sys_clk))));
    bufp->fullQData(oldp+211,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk0),64);
    bufp->fullQData(oldp+213,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk1),64);
    bufp->fullQData(oldp+215,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk2),64);
    bufp->fullQData(oldp+217,(vlSelf->sdram_axil_tb__DOT__u_sdram_model__DOT__RP_chk3),64);
    bufp->fullIData(oldp+219,(((IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__rvalid)
                                ? (((IData)(vlSymsp->TOP__sdram_axil_tb__DOT__sdram_dev_if.read_data) 
                                    << 0x10U) | (IData)(vlSelf->sdram_axil_tb__DOT__u_sdram_controller__DOT__read_data_r))
                                : 0U)),32);
}
