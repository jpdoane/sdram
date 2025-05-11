// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsdram_tb.h for the primary calling header

#ifndef VERILATED_VSDRAM_TB___024ROOT_H_
#define VERILATED_VSDRAM_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vsdram_tb_sdram_ctrl_if;
class Vsdram_tb_sdram_dev_if;


class Vsdram_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsdram_tb___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsdram_tb_sdram_ctrl_if* __PVT__sdram_tb__DOT__sdram_ctrl_if;
    Vsdram_tb_sdram_dev_if* __PVT__sdram_tb__DOT__sdram_dev_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ sdram_tb__DOT__clk;
        CData/*0:0*/ sdram_tb__DOT__sdram_clk;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Sys_clk;
        CData/*0:0*/ sdram_tb__DOT__rst;
        CData/*2:0*/ sdram_tb__DOT__u_sdram_controller__DOT__state;
        CData/*2:0*/ sdram_tb__DOT__u_sdram_controller__DOT__state_next;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__new_state;
        CData/*3:0*/ sdram_tb__DOT__u_sdram_controller__DOT__cnt;
        CData/*3:0*/ sdram_tb__DOT__u_sdram_controller__DOT__state_delay;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__first_cycle;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__last_cycle;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__boot_delay;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__booting;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__rw;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__rdy;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__rvalid;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__req;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__valid_req;
        CData/*2:0*/ sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd;
        CData/*1:0*/ sdram_tb__DOT__u_sdram_controller__DOT__bank;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__byte_misalign;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__sd_wr;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__sd_rd;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_reg;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas;
        CData/*3:0*/ sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg;
        CData/*1:0*/ sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0;
        CData/*1:0*/ sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg1;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Act_b0;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Act_b1;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Act_b2;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Act_b3;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Pc_b0;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Pc_b1;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Pc_b2;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Pc_b3;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable;
        CData/*1:0*/ sdram_tb__DOT__u_sdram_model__DOT__Bank;
        CData/*1:0*/ sdram_tb__DOT__u_sdram_model__DOT__Previous_bank;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__CkeZ;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Read_enable;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Write_enable;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT__Write_burst_mode;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_hed09cbba__0;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_heb50aace__0;
        CData/*0:0*/ sdram_tb__DOT__u_sdram_model__DOT____VdfgTmp_h43c0b825__0;
        CData/*0:0*/ __VassignWtmp_sdram_tb__DOT__sdram_clk__0;
        CData/*0:0*/ __Vintraval_h8e9d4ac7__0;
        CData/*0:0*/ __Vdlyvset__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__sdram_tb__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__sdram_tb__DOT__u_sdram_model__DOT__Sys_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__sdram_tb__DOT__sdram_clk__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
    };
    struct {
        SData/*15:0*/ sdram_tb__DOT__u_sdram_controller__DOT__cnt2;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_controller__DOT__row;
        SData/*8:0*/ sdram_tb__DOT__u_sdram_controller__DOT__col;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_model__DOT__Mode_reg;
        SData/*15:0*/ sdram_tb__DOT__u_sdram_model__DOT__Dq_reg;
        SData/*15:0*/ sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm;
        SData/*8:0*/ sdram_tb__DOT__u_sdram_model__DOT__Col_temp;
        SData/*8:0*/ sdram_tb__DOT__u_sdram_model__DOT__Burst_counter;
        SData/*11:0*/ sdram_tb__DOT__u_sdram_model__DOT__Row;
        SData/*8:0*/ sdram_tb__DOT__u_sdram_model__DOT__Col;
        SData/*8:0*/ sdram_tb__DOT__u_sdram_model__DOT__Col_brst;
        SData/*15:0*/ __Vintraval_h69ef25c5__0;
        SData/*15:0*/ __Vintraval_h9edf9348__0;
        SData/*15:0*/ __Vdlyvval__sdram_tb__DOT__u_sdram_model__DOT__Dq_reg__v0;
        IData/*31:0*/ sdram_tb__DOT__randint;
        IData/*31:0*/ sdram_tb__DOT__bytenum;
        IData/*31:0*/ sdram_tb__DOT__u_sdram_controller__DOT__data_reg;
        IData/*31:0*/ sdram_tb__DOT__u_sdram_model__DOT__MRD_chk;
        IData/*31:0*/ __Vtrigprevexpr_h7fb8c6b6__0;
        IData/*31:0*/ __Vtrigprevexpr_h7fb8c6f5__0;
        IData/*31:0*/ __Vtrigprevexpr_h7fb8c738__0;
        IData/*31:0*/ __Vtrigprevexpr_h7fb8c55c__0;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RC_chk;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RRD_chk;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RP_chk0;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RP_chk1;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RP_chk2;
        QData/*63:0*/ sdram_tb__DOT__u_sdram_model__DOT__RP_chk3;
        VlUnpacked<SData/*15:0*/, 2097152> sdram_tb__DOT__u_sdram_model__DOT__Bank0;
        VlUnpacked<SData/*15:0*/, 2097152> sdram_tb__DOT__u_sdram_model__DOT__Bank1;
        VlUnpacked<SData/*15:0*/, 2097152> sdram_tb__DOT__u_sdram_model__DOT__Bank2;
        VlUnpacked<SData/*15:0*/, 2097152> sdram_tb__DOT__u_sdram_model__DOT__Bank3;
        VlUnpacked<CData/*1:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Bank_addr;
        VlUnpacked<SData/*8:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Col_addr;
        VlUnpacked<CData/*3:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Command;
        VlUnpacked<CData/*1:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge;
        VlUnpacked<CData/*0:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__A10_precharge;
        VlUnpacked<CData/*0:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge;
        VlUnpacked<CData/*0:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Read_precharge;
        VlUnpacked<CData/*0:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Write_precharge;
        VlUnpacked<IData/*31:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__Count_precharge;
        VlUnpacked<CData/*0:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read;
        VlUnpacked<CData/*0:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write;
        VlUnpacked<IData/*31:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__WR_counter;
        VlUnpacked<QData/*63:0*/, 4> sdram_tb__DOT__u_sdram_model__DOT__WR_chk;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlTriggerScheduler __VtrigSched_hee8b7033__0;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h825eefb7__0;
    VlTriggerScheduler __VtrigSched_h825ef06a__0;
    VlTriggerScheduler __VtrigSched_hefdf76e7__0;
    VlTriggerScheduler __VtrigSched_he77f00c4__0;
    VlTriggerScheduler __VtrigSched_he77eff83__0;
    VlTriggerScheduler __VtrigSched_he77eff4a__0;
    VlTriggerScheduler __VtrigSched_he77ff96e__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<10> __VactTriggered;
    VlTriggerVec<10> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsdram_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsdram_tb___024root(Vsdram_tb__Syms* symsp, const char* v__name);
    ~Vsdram_tb___024root();
    VL_UNCOPYABLE(Vsdram_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
