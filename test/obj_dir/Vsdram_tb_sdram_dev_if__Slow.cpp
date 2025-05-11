// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb__Syms.h"
#include "Vsdram_tb_sdram_dev_if.h"

void Vsdram_tb_sdram_dev_if___ctor_var_reset(Vsdram_tb_sdram_dev_if* vlSelf);

Vsdram_tb_sdram_dev_if::Vsdram_tb_sdram_dev_if(Vsdram_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsdram_tb_sdram_dev_if___ctor_var_reset(this);
}

void Vsdram_tb_sdram_dev_if::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsdram_tb_sdram_dev_if::~Vsdram_tb_sdram_dev_if() {
}
