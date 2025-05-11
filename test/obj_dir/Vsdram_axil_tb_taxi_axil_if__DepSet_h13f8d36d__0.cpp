// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_axil_tb.h for the primary calling header

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb_taxi_axil_if.h"

std::string VL_TO_STRING(const Vsdram_axil_tb_taxi_axil_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsdram_axil_tb_taxi_axil_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
