// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsdram_axil_tb.h for the primary calling header

#ifndef VERILATED_VSDRAM_AXIL_TB_TAXI_AXIL_IF_H_
#define VERILATED_VSDRAM_AXIL_TB_TAXI_AXIL_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsdram_axil_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsdram_axil_tb_taxi_axil_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*2:0*/ __PVT__awprot;
    CData/*0:0*/ __PVT__awuser;
    CData/*0:0*/ awvalid;
    CData/*3:0*/ wstrb;
    CData/*0:0*/ __PVT__wuser;
    CData/*0:0*/ wvalid;
    CData/*0:0*/ bready;
    CData/*2:0*/ __PVT__arprot;
    CData/*0:0*/ __PVT__aruser;
    CData/*0:0*/ arvalid;
    CData/*0:0*/ arready;
    CData/*0:0*/ rready;
    IData/*31:0*/ awaddr;
    IData/*31:0*/ wdata;
    IData/*31:0*/ araddr;

    // INTERNAL VARIABLES
    Vsdram_axil_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsdram_axil_tb_taxi_axil_if(Vsdram_axil_tb__Syms* symsp, const char* v__name);
    ~Vsdram_axil_tb_taxi_axil_if();
    VL_UNCOPYABLE(Vsdram_axil_tb_taxi_axil_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsdram_axil_tb_taxi_axil_if* obj);

#endif  // guard
