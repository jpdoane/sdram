// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb_sdram_dev_if.h"

VL_ATTR_COLD void Vsdram_tb_sdram_dev_if___ctor_var_reset(Vsdram_tb_sdram_dev_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsdram_tb_sdram_dev_if___ctor_var_reset\n"); );
    // Body
    vlSelf->dqm = VL_RAND_RESET_I(2);
    vlSelf->addr = VL_RAND_RESET_I(12);
    vlSelf->ba = VL_RAND_RESET_I(2);
    vlSelf->write_data = VL_RAND_RESET_I(16);
}
