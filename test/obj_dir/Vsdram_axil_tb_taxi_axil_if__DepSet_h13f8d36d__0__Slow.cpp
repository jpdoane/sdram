// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_axil_tb.h for the primary calling header

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb_taxi_axil_if.h"

VL_ATTR_COLD void Vsdram_axil_tb_taxi_axil_if___ctor_var_reset(Vsdram_axil_tb_taxi_axil_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsdram_axil_tb_taxi_axil_if___ctor_var_reset\n"); );
    // Body
    vlSelf->awaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__awprot = VL_RAND_RESET_I(3);
    vlSelf->__PVT__awuser = VL_RAND_RESET_I(1);
    vlSelf->awvalid = VL_RAND_RESET_I(1);
    vlSelf->wdata = VL_RAND_RESET_I(32);
    vlSelf->wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__wuser = VL_RAND_RESET_I(1);
    vlSelf->wvalid = VL_RAND_RESET_I(1);
    vlSelf->bready = VL_RAND_RESET_I(1);
    vlSelf->araddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__arprot = VL_RAND_RESET_I(3);
    vlSelf->__PVT__aruser = VL_RAND_RESET_I(1);
    vlSelf->arvalid = VL_RAND_RESET_I(1);
    vlSelf->arready = VL_RAND_RESET_I(1);
    vlSelf->rready = VL_RAND_RESET_I(1);
}
