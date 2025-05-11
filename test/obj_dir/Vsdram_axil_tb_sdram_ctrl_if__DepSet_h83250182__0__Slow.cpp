// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_axil_tb.h for the primary calling header

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb_sdram_ctrl_if.h"

VL_ATTR_COLD void Vsdram_axil_tb_sdram_ctrl_if___ctor_var_reset(Vsdram_axil_tb_sdram_ctrl_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_axil_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsdram_axil_tb_sdram_ctrl_if___ctor_var_reset\n"); );
    // Body
    vlSelf->wr = VL_RAND_RESET_I(4);
    vlSelf->rd = VL_RAND_RESET_I(1);
    vlSelf->addr = VL_RAND_RESET_I(32);
    vlSelf->write_data = VL_RAND_RESET_I(32);
}
