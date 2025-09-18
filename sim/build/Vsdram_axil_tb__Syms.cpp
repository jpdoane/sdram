// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb.h"
#include "Vsdram_axil_tb___024root.h"
#include "Vsdram_axil_tb_sdram_ctrl_if.h"
#include "Vsdram_axil_tb_sdram_dev_if.h"

// FUNCTIONS
Vsdram_axil_tb__Syms::~Vsdram_axil_tb__Syms()
{
}

Vsdram_axil_tb__Syms::Vsdram_axil_tb__Syms(VerilatedContext* contextp, const char* namep, Vsdram_axil_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__sdram_axil_tb__DOT__sdram_ctrl_if{this, Verilated::catName(namep, "sdram_axil_tb.sdram_ctrl_if")}
    , TOP__sdram_axil_tb__DOT__sdram_dev_if{this, Verilated::catName(namep, "sdram_axil_tb.sdram_dev_if")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__sdram_axil_tb__DOT__sdram_ctrl_if = &TOP__sdram_axil_tb__DOT__sdram_ctrl_if;
    TOP.__PVT__sdram_axil_tb__DOT__sdram_dev_if = &TOP__sdram_axil_tb__DOT__sdram_dev_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__sdram_axil_tb__DOT__sdram_ctrl_if.__Vconfigure(true);
    TOP__sdram_axil_tb__DOT__sdram_dev_if.__Vconfigure(true);
}
