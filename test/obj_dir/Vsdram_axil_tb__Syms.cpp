// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsdram_axil_tb__pch.h"
#include "Vsdram_axil_tb.h"
#include "Vsdram_axil_tb___024root.h"
#include "Vsdram_axil_tb_sdram_ctrl_if.h"
#include "Vsdram_axil_tb_sdram_dev_if.h"
#include "Vsdram_axil_tb_taxi_axil_if.h"

// FUNCTIONS
Vsdram_axil_tb__Syms::~Vsdram_axil_tb__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vsdram_axil_tb__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vsdram_axil_tb__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vsdram_axil_tb__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vsdram_axil_tb__Syms::Vsdram_axil_tb__Syms(VerilatedContext* contextp, const char* namep, Vsdram_axil_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__sdram_axil_tb__DOT__axi_if{this, Verilated::catName(namep, "sdram_axil_tb.axi_if")}
    , TOP__sdram_axil_tb__DOT__sdram_ctrl_if{this, Verilated::catName(namep, "sdram_axil_tb.sdram_ctrl_if")}
    , TOP__sdram_axil_tb__DOT__sdram_dev_if{this, Verilated::catName(namep, "sdram_axil_tb.sdram_dev_if")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__sdram_axil_tb__DOT__axi_if = &TOP__sdram_axil_tb__DOT__axi_if;
    TOP.__PVT__sdram_axil_tb__DOT__sdram_ctrl_if = &TOP__sdram_axil_tb__DOT__sdram_ctrl_if;
    TOP.__PVT__sdram_axil_tb__DOT__sdram_dev_if = &TOP__sdram_axil_tb__DOT__sdram_dev_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__sdram_axil_tb__DOT__axi_if.__Vconfigure(true);
    TOP__sdram_axil_tb__DOT__sdram_ctrl_if.__Vconfigure(true);
    TOP__sdram_axil_tb__DOT__sdram_dev_if.__Vconfigure(true);
    // Setup scopes
    __Vscope_sdram_axil_tb.configure(this, name(), "sdram_axil_tb", "sdram_axil_tb", -9, VerilatedScope::SCOPE_OTHER);
}
