// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb_sdram_ctrl_if.h"

std::string VL_TO_STRING(const Vsdram_tb_sdram_ctrl_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsdram_tb_sdram_ctrl_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
