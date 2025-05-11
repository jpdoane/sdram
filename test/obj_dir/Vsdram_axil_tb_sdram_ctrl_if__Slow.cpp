// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_axil_tb.h for the primary calling header

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb__Syms.h"
#include "Vsdram_axil_tb_sdram_ctrl_if.h"

void Vsdram_axil_tb_sdram_ctrl_if___ctor_var_reset(Vsdram_axil_tb_sdram_ctrl_if* vlSelf);

Vsdram_axil_tb_sdram_ctrl_if::Vsdram_axil_tb_sdram_ctrl_if(Vsdram_axil_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsdram_axil_tb_sdram_ctrl_if___ctor_var_reset(this);
}

void Vsdram_axil_tb_sdram_ctrl_if::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsdram_axil_tb_sdram_ctrl_if::~Vsdram_axil_tb_sdram_ctrl_if() {
}
