// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSDRAM_AXIL_TB__SYMS_H_
#define VERILATED_VSDRAM_AXIL_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsdram_axil_tb.h"

// INCLUDE MODULE CLASSES
#include "Vsdram_axil_tb___024root.h"
#include "Vsdram_axil_tb_sdram_ctrl_if.h"
#include "Vsdram_axil_tb_sdram_dev_if.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsdram_axil_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsdram_axil_tb* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsdram_axil_tb___024root       TOP;
    Vsdram_axil_tb_sdram_ctrl_if   TOP__sdram_axil_tb__DOT__sdram_ctrl_if;
    Vsdram_axil_tb_sdram_dev_if    TOP__sdram_axil_tb__DOT__sdram_dev_if;

    // CONSTRUCTORS
    Vsdram_axil_tb__Syms(VerilatedContext* contextp, const char* namep, Vsdram_axil_tb* modelp);
    ~Vsdram_axil_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
