// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsdram_tb.h for the primary calling header

#ifndef VERILATED_VSDRAM_TB_SDRAM_DEV_IF_H_
#define VERILATED_VSDRAM_TB_SDRAM_DEV_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsdram_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsdram_tb_sdram_dev_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*1:0*/ dqm;
    CData/*1:0*/ ba;
    SData/*11:0*/ addr;
    SData/*15:0*/ write_data;

    // INTERNAL VARIABLES
    Vsdram_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsdram_tb_sdram_dev_if(Vsdram_tb__Syms* symsp, const char* v__name);
    ~Vsdram_tb_sdram_dev_if();
    VL_UNCOPYABLE(Vsdram_tb_sdram_dev_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsdram_tb_sdram_dev_if* obj);

#endif  // guard
