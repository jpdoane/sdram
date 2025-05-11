// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsdram_axil_tb.h for the primary calling header

#ifndef VERILATED_VSDRAM_AXIL_TB_SDRAM_CTRL_IF_H_
#define VERILATED_VSDRAM_AXIL_TB_SDRAM_CTRL_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsdram_axil_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsdram_axil_tb_sdram_ctrl_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*3:0*/ wr;
    CData/*0:0*/ rd;
    IData/*31:0*/ addr;
    IData/*31:0*/ write_data;

    // INTERNAL VARIABLES
    Vsdram_axil_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsdram_axil_tb_sdram_ctrl_if(Vsdram_axil_tb__Syms* symsp, const char* v__name);
    ~Vsdram_axil_tb_sdram_ctrl_if();
    VL_UNCOPYABLE(Vsdram_axil_tb_sdram_ctrl_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsdram_axil_tb_sdram_ctrl_if* obj);

#endif  // guard
