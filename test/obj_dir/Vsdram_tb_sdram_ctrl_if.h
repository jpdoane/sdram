// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsdram_tb.h for the primary calling header

#ifndef VERILATED_VSDRAM_TB_SDRAM_CTRL_IF_H_
#define VERILATED_VSDRAM_TB_SDRAM_CTRL_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsdram_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsdram_tb_sdram_ctrl_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*3:0*/ wr;
        CData/*0:0*/ rd;
        CData/*0:0*/ __Vdlyvset__write_data__v0;
        CData/*0:0*/ __Vdlyvset__addr__v0;
        CData/*0:0*/ __Vdlyvset__wr__v0;
        CData/*0:0*/ __Vdlyvset__rd__v0;
        CData/*0:0*/ __Vdlyvset__addr__v1;
        CData/*0:0*/ __Vdlyvset__write_data__v1;
        CData/*0:0*/ __Vdlyvset__wr__v1;
        CData/*0:0*/ __Vdlyvset__wr__v2;
        CData/*0:0*/ __Vdlyvset__write_data__v2;
        CData/*0:0*/ __Vdlyvset__rd__v1;
        CData/*0:0*/ __Vdlyvset__rd__v2;
        CData/*0:0*/ __Vdlyvset__write_data__v3;
        CData/*0:0*/ __Vdlyvset__addr__v2;
        CData/*0:0*/ __Vdlyvset__wr__v3;
        CData/*0:0*/ __Vdlyvset__rd__v3;
        CData/*0:0*/ __Vdlyvset__addr__v3;
        CData/*0:0*/ __Vdlyvset__write_data__v4;
        CData/*0:0*/ __Vdlyvset__wr__v4;
        CData/*0:0*/ __Vdlyvset__wr__v5;
        CData/*0:0*/ __Vdlyvset__write_data__v5;
        CData/*0:0*/ __Vdlyvset__rd__v4;
        CData/*0:0*/ __Vdlyvset__rd__v5;
        CData/*0:0*/ __Vdlyvset__write_data__v6;
        CData/*0:0*/ __Vdlyvset__addr__v4;
        CData/*0:0*/ __Vdlyvset__wr__v6;
        CData/*0:0*/ __Vdlyvset__rd__v6;
        CData/*0:0*/ __Vdlyvset__addr__v5;
        CData/*0:0*/ __Vdlyvset__write_data__v7;
        CData/*0:0*/ __Vdlyvset__wr__v7;
        CData/*0:0*/ __Vdlyvset__wr__v8;
        CData/*0:0*/ __Vdlyvset__write_data__v8;
        CData/*0:0*/ __Vdlyvset__rd__v7;
        CData/*0:0*/ __Vdlyvset__rd__v8;
        CData/*0:0*/ __Vdlyvset__write_data__v9;
        CData/*0:0*/ __Vdlyvset__addr__v6;
        CData/*0:0*/ __Vdlyvset__wr__v9;
        CData/*0:0*/ __Vdlyvset__rd__v9;
        CData/*0:0*/ __Vdlyvset__addr__v7;
        CData/*0:0*/ __Vdlyvset__write_data__v10;
        CData/*0:0*/ __Vdlyvset__wr__v10;
        CData/*0:0*/ __Vdlyvset__wr__v11;
        CData/*0:0*/ __Vdlyvset__write_data__v11;
        CData/*0:0*/ __Vdlyvset__rd__v10;
        CData/*0:0*/ __Vdlyvset__rd__v11;
        CData/*0:0*/ __Vdlyvset__write_data__v12;
        CData/*0:0*/ __Vdlyvset__addr__v8;
        CData/*0:0*/ __Vdlyvset__wr__v12;
        CData/*0:0*/ __Vdlyvset__rd__v12;
        CData/*0:0*/ __Vdlyvset__addr__v9;
        CData/*0:0*/ __Vdlyvset__write_data__v13;
        CData/*0:0*/ __Vdlyvset__wr__v13;
        CData/*0:0*/ __Vdlyvset__wr__v14;
        CData/*0:0*/ __Vdlyvset__write_data__v14;
        CData/*0:0*/ __Vdlyvset__rd__v13;
        CData/*0:0*/ __Vdlyvset__rd__v14;
        CData/*0:0*/ __Vdlyvset__write_data__v15;
        CData/*0:0*/ __Vdlyvset__addr__v10;
        CData/*0:0*/ __Vdlyvset__wr__v15;
        CData/*0:0*/ __Vdlyvset__rd__v15;
        CData/*0:0*/ __Vdlyvset__addr__v11;
        CData/*0:0*/ __Vdlyvset__write_data__v16;
        CData/*0:0*/ __Vdlyvset__wr__v16;
    };
    struct {
        CData/*0:0*/ __Vdlyvset__wr__v17;
        CData/*0:0*/ __Vdlyvset__write_data__v17;
        CData/*0:0*/ __Vdlyvset__rd__v16;
        CData/*0:0*/ __Vdlyvset__rd__v17;
        CData/*0:0*/ __Vdlyvset__write_data__v18;
        CData/*0:0*/ __Vdlyvset__addr__v12;
        CData/*0:0*/ __Vdlyvset__wr__v18;
        CData/*0:0*/ __Vdlyvset__rd__v18;
        CData/*0:0*/ __Vdlyvset__addr__v13;
        CData/*0:0*/ __Vdlyvset__write_data__v19;
        CData/*0:0*/ __Vdlyvset__wr__v19;
        CData/*0:0*/ __Vdlyvset__wr__v20;
        CData/*0:0*/ __Vdlyvset__write_data__v20;
        CData/*0:0*/ __Vdlyvset__rd__v19;
        CData/*0:0*/ __Vdlyvset__rd__v20;
        CData/*0:0*/ __Vdlyvset__write_data__v21;
        CData/*0:0*/ __Vdlyvset__addr__v14;
        CData/*0:0*/ __Vdlyvset__wr__v21;
        CData/*0:0*/ __Vdlyvset__rd__v21;
        CData/*0:0*/ __Vdlyvset__addr__v15;
        CData/*0:0*/ __Vdlyvset__write_data__v22;
        CData/*0:0*/ __Vdlyvset__wr__v22;
        CData/*0:0*/ __Vdlyvset__wr__v23;
        CData/*0:0*/ __Vdlyvset__write_data__v23;
        CData/*0:0*/ __Vdlyvset__rd__v22;
        CData/*0:0*/ __Vdlyvset__rd__v23;
        CData/*0:0*/ __Vdlyvset__write_data__v24;
        CData/*0:0*/ __Vdlyvset__addr__v16;
        CData/*0:0*/ __Vdlyvset__wr__v24;
        CData/*0:0*/ __Vdlyvset__rd__v24;
        CData/*0:0*/ __Vdlyvset__addr__v17;
        CData/*0:0*/ __Vdlyvset__write_data__v25;
        CData/*0:0*/ __Vdlyvset__wr__v25;
        CData/*0:0*/ __Vdlyvset__wr__v26;
        CData/*0:0*/ __Vdlyvset__write_data__v26;
        CData/*0:0*/ __Vdlyvset__rd__v25;
        CData/*0:0*/ __Vdlyvset__rd__v26;
        CData/*0:0*/ __Vdlyvset__write_data__v27;
        CData/*0:0*/ __Vdlyvset__addr__v18;
        CData/*0:0*/ __Vdlyvset__wr__v27;
        CData/*0:0*/ __Vdlyvset__rd__v27;
        CData/*0:0*/ __Vdlyvset__addr__v19;
        CData/*0:0*/ __Vdlyvset__write_data__v28;
        CData/*0:0*/ __Vdlyvset__wr__v28;
        CData/*0:0*/ __Vdlyvset__wr__v29;
        CData/*0:0*/ __Vdlyvset__write_data__v29;
        CData/*0:0*/ __Vdlyvset__rd__v28;
        CData/*0:0*/ __Vdlyvset__rd__v29;
        IData/*31:0*/ addr;
        IData/*31:0*/ write_data;
        IData/*31:0*/ read_data;
        IData/*31:0*/ __Vdlyvval__addr__v1;
        IData/*31:0*/ __Vdlyvval__write_data__v1;
        IData/*31:0*/ __Vdlyvval__addr__v3;
        IData/*31:0*/ __Vdlyvval__write_data__v4;
        IData/*31:0*/ __Vdlyvval__addr__v5;
        IData/*31:0*/ __Vdlyvval__write_data__v7;
        IData/*31:0*/ __Vdlyvval__addr__v7;
        IData/*31:0*/ __Vdlyvval__write_data__v10;
        IData/*31:0*/ __Vdlyvval__addr__v9;
        IData/*31:0*/ __Vdlyvval__write_data__v13;
        IData/*31:0*/ __Vdlyvval__addr__v11;
        IData/*31:0*/ __Vdlyvval__write_data__v16;
        IData/*31:0*/ __Vdlyvval__addr__v13;
    };
    struct {
        IData/*31:0*/ __Vdlyvval__write_data__v19;
        IData/*31:0*/ __Vdlyvval__addr__v15;
        IData/*31:0*/ __Vdlyvval__write_data__v22;
        IData/*31:0*/ __Vdlyvval__addr__v17;
        IData/*31:0*/ __Vdlyvval__write_data__v25;
        IData/*31:0*/ __Vdlyvval__addr__v19;
        IData/*31:0*/ __Vdlyvval__write_data__v28;
    };

    // INTERNAL VARIABLES
    Vsdram_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsdram_tb_sdram_ctrl_if(Vsdram_tb__Syms* symsp, const char* v__name);
    ~Vsdram_tb_sdram_ctrl_if();
    VL_UNCOPYABLE(Vsdram_tb_sdram_ctrl_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsdram_tb_sdram_ctrl_if* obj);

#endif  // guard
