// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsdram_tb.h for the primary calling header

#include "Vsdram_tb__pch.h"
#include "Vsdram_tb__Syms.h"
#include "Vsdram_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__2(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        while (vlSelf->sdram_tb__DOT__rst) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               60);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v0 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v0 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v0 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v0 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v1 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v1 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v1 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v1 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v1 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v2 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v2 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v1 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v2 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v3 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v2 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v3 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v3 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v3 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v3 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v4 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v4 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v4 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v5 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v5 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v4 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v5 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v6 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v4 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v6 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v6 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v5 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v5 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v7 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v7 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v7 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v8 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v8 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v7 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v8 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v9 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v6 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v9 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v9 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v7 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v7 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v10 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v10 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v10 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v11 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v11 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v10 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v11 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v12 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v8 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v12 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v12 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v9 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v9 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v13 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v13 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v13 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v14 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v14 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v13 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v14 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v15 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v10 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v15 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v15 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v11 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v11 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v16 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v16 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v16 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v17 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v17 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v16 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v17 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v18 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v12 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v18 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v18 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v13 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v13 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v19 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v19 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v19 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v20 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v20 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v19 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v20 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v21 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v14 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v21 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v21 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v15 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v15 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v22 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v22 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v22 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v23 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v23 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v22 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v23 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v24 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v16 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v24 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v24 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v17 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v17 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v25 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v25 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v25 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v26 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v26 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v25 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v26 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v27 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v18 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v27 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v27 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           67);
        vlSelf->sdram_tb__DOT__randint = VL_RANDOM_I();
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v19 
            = (0xfffffffcU & vlSelf->sdram_tb__DOT__randint);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v19 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           71);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v28 
            = vlSelf->sdram_tb__DOT__randint;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v28 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v28 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           76);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               77);
        }
        VL_WRITEF("at time %t Wrote 0x%0x to 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr,
                  32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v29 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v29 = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v28 = 1U;
        co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.clk)", 
                                                           "sdram_tb.sv", 
                                                           84);
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               85);
        }
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v29 = 1U;
        while ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)))) {
            co_await vlSelf->__VtrigSched_hee8b7033__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge sdram_tb.clk)", 
                                                               "sdram_tb.sv", 
                                                               87);
        }
        if ((vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
             == vlSelf->sdram_tb__DOT__randint)) {
            VL_WRITEF("at time  %t: Read correct value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        } else {
            VL_WRITEF("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data,
                      32,vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        }
        VL_FINISH_MT("sdram_tb.sv", 113, "");
    }
}

VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__4____Vfork_2__1(Vsdram_tb___024root* vlSelf, SData/*15:0*/ __Vintraval_h69ef25c5__0);

VL_INLINE_OPT VlCoroutine Vsdram_tb___024root___eval_initial__TOP__Vtiming__4(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_initial__TOP__Vtiming__4\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_hefdf76e7__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sdram_tb.u_sdram_model.Sys_clk)", 
                                                           "../models/MT48LC8M16A2.v", 
                                                           190);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[0U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
            [1U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[1U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
            [2U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[2U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
            [3U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[3U] = 1U;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[0U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
            [1U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[1U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
            [2U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[2U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
            [3U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[3U] = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[0U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
            [1U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[1U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
            [2U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[2U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
            [3U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[3U] = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[0U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge
            [1U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[1U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge
            [2U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[2U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge
            [3U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[3U] = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[0U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge
            [1U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[1U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge
            [2U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[2U] 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge
            [3U];
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[3U] = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0 
            = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg1;
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg1 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm;
        if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [0U]) {
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[0U] 
                = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [0U]);
        }
        if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [1U]) {
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[1U] 
                = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [1U]);
        }
        if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [2U]) {
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[2U] 
                = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [2U]);
        }
        if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
            [3U]) {
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[3U] 
                = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                   [3U]);
        }
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk 
            = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk);
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[0U] 
            = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
               [0U]);
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[1U] 
            = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
               [1U]);
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[2U] 
            = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
               [2U]);
        vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[3U] 
            = ((IData)(1U) + vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
               [3U]);
        if ((IData)((1U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))) {
            if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                              - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk)) 
                             < 60.0))) {
                VL_WRITEF("at time %t ERROR: tRC violation during Auto Refresh\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY(((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0)) 
                                < 15.0) | (VL_ITOR_D_Q(64, 
                                                       ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                        - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1)) 
                                           < 15.0)) 
                              | (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2)) 
                                 < 15.0)) | (VL_ITOR_D_Q(64, 
                                                         ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                          - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3)) 
                                             < 15.0)))) {
                VL_WRITEF("at time %t ERROR: tRP violation during Auto Refresh\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((1U & ((((~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0)) 
                                     | (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1))) 
                                    | (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2))) 
                                   | (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3)))))) {
                VL_WRITEF("at time %t ERROR: All banks must be Precharge before Auto Refresh\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk 
                = VL_TIME_UNITED_Q(1000);
        }
        if ((IData)((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))) {
            if (VL_LIKELY(((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0) 
                             & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1)) 
                            & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2)) 
                           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3)))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr;
            } else {
                VL_WRITEF("at time %t ERROR: all banks must be Precharge before Load Mode Register\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                              - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk)) 
                             < 60.0))) {
                VL_WRITEF("at time %t ERROR: tRC violation during Load Mode Register\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((VL_ISTOR_D_I(32, vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk) 
                             < 40.0))) {
                VL_WRITEF("at time %t ERROR: tMRD violation during Load Mode Register\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk = 0U;
        }
        if ((IData)((3U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))) {
            if (((0U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                 & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0)) 
                                 < 15.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 0\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0 
                    = VL_TIME_UNITED_Q(1000);
            } else if (((1U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                        & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1)) 
                                 < 15.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 1\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1 
                    = VL_TIME_UNITED_Q(1000);
            } else if (((2U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                        & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2)) 
                                 < 15.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 2\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2 
                    = VL_TIME_UNITED_Q(1000);
            } else if (((3U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                        & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3))) {
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3)) 
                                 < 15.0))) {
                    VL_WRITEF("at time %t ERROR: tRP violation during Activate bank 3\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3 
                    = VL_TIME_UNITED_Q(1000);
            } else if (VL_UNLIKELY(((0U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                    & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0))))) {
                VL_WRITEF("at time %t ERROR: Bank 0 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            } else if (VL_UNLIKELY(((1U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                    & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1))))) {
                VL_WRITEF("at time %t ERROR: Bank 1 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            } else if (VL_UNLIKELY(((2U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                    & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2))))) {
                VL_WRITEF("at time %t ERROR: Bank 2 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            } else if (VL_UNLIKELY(((3U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                    & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3))))) {
                VL_WRITEF("at time %t ERROR: Bank 3 is not Precharged.\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Previous_bank) 
                              != (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RRD_chk)) 
                                < 40.0)))) {
                VL_WRITEF("at time %t ERROR: tRRD violation during Activate bank = %1#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba));
            }
            if (VL_UNLIKELY((VL_ISTOR_D_I(32, vlSelf->sdram_tb__DOT__u_sdram_model__DOT__MRD_chk) 
                             < 40.0))) {
                VL_WRITEF("at time %t ERROR: tMRD violation during Activate bank = %1#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba));
            }
            if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                              - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RC_chk)) 
                             < 60.0))) {
                VL_WRITEF("at time %t ERROR: tRC violation during Activate bank = %1#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba));
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RRD_chk 
                = VL_TIME_UNITED_Q(1000);
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Previous_bank 
                = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba;
        }
        if ((IData)((2U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))) {
            if ((0x400U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3 
                    = VL_TIME_UNITED_Q(1000);
                if (VL_UNLIKELY(((((VL_ITOR_D_Q(64, 
                                                ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                                    < 42.0) | (VL_ITOR_D_Q(64, 
                                                           ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                            - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                                               < 42.0)) 
                                  | (VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                                     < 42.0)) | (VL_ITOR_D_Q(64, 
                                                             ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                              - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                                                 < 42.0)))) {
                    VL_WRITEF("at time %t ERROR: tRAS violation during Precharge all bank\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
                if (VL_UNLIKELY(((((VL_ITOR_D_Q(64, 
                                                ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk
                                                 [0U])) 
                                    < 15.0) | (VL_ITOR_D_Q(64, 
                                                           ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                            - 
                                                            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk
                                                            [1U])) 
                                               < 15.0)) 
                                  | (VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk
                                                  [2U])) 
                                     < 15.0)) | (VL_ITOR_D_Q(64, 
                                                             ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                              - 
                                                              vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk
                                                              [3U])) 
                                                 < 15.0)))) {
                    VL_WRITEF("at time %t ERROR: tWR violation during Precharge all bank\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                }
            } else if ((1U & (~ ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr) 
                                 >> 0xaU)))) {
                if ((0U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                                     < 42.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 0\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0 
                        = VL_TIME_UNITED_Q(1000);
                } else if ((1U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                                     < 42.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 1\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1 
                        = VL_TIME_UNITED_Q(1000);
                } else if ((2U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                                     < 42.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 2\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2 
                        = VL_TIME_UNITED_Q(1000);
                } else if ((3U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba))) {
                    if (VL_UNLIKELY((VL_ITOR_D_Q(64, 
                                                 ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                                     < 42.0))) {
                        VL_WRITEF("at time %t ERROR: tRAS violation during Precharge bank 3\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3 
                        = VL_TIME_UNITED_Q(1000);
                }
                if (VL_UNLIKELY((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                  - 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk
                                                  [vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba])) 
                                 < 15.0))) {
                    VL_WRITEF("at time %t ERROR: tWR violation during Precharge bank %1#\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9,2,(IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba));
                }
            }
            if (((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) 
                 & (((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank) 
                     == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                    | ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr) 
                       >> 0xaU)))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[2U] = 6U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[2U] 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[2U] 
                    = (1U & ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr) 
                             >> 0xaU));
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[1U] = 6U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge[1U] 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge[1U] 
                    = (1U & ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr) 
                             >> 0xaU));
            }
        }
        if ((IData)((6U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)))) {
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[2U] = 8U;
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[1U] = 8U;
            }
        }
        if (((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable) 
             | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable))) {
            if (VL_UNLIKELY((((((0U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0)) 
                               | ((1U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                  & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1))) 
                              | ((2U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                 & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2))) 
                             | ((3U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                                & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3))))) {
                VL_WRITEF("at time %t ERROR: Cannot Read or Write - Bank %1# is not Activated (%1#)\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,2,(IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba),
                          1,vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0);
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable) {
                if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                }
                if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_3) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[2U] 
                        = ((0x400U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr))
                            ? 3U : 2U);
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[2U] 
                        = (0x1ffU & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr));
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[2U] 
                        = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba;
                } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Cas_latency_2) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[1U] 
                        = ((0x400U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr))
                            ? 3U : 2U);
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[1U] 
                        = (0x1ffU & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr));
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[1U] 
                        = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable) {
                if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                }
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command[0U] 
                    = ((0x400U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr))
                        ? 5U : 4U);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr[0U] 
                    = (0x1ffU & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr));
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr[0U] 
                    = vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba;
                if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
            if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
                 [vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank] 
                 & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge
                 [vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_write[vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank] = 1U;
            }
            if (VL_UNLIKELY(((0U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk0)) 
                                < 15.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 0\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
                 [vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank] 
                 & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge
                 [vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank] = 1U;
            }
            if (VL_UNLIKELY(((1U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk1)) 
                                < 15.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 1\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if (VL_UNLIKELY(((2U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk2)) 
                                < 15.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 2\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
            if ((0x400U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba] = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge[vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba] = 0U;
                if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba] = 1U;
                } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_precharge[vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba] = 1U;
                }
            }
            if (VL_UNLIKELY(((3U == (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba)) 
                             & (VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                                 - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RCD_chk3)) 
                                < 15.0)))) {
                VL_WRITEF("at time %t ERROR: tRCD violation during Read or Write to Bank 3\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9);
            }
        }
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [0U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge
             [0U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk0)) 
                   >= 42.0) & (((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [0U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [0U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [0U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [0U])))) 
                 | vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b0 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b0 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk0 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[0U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[0U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[0U] = 0U;
            }
        }
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [1U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge
             [1U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk1)) 
                   >= 42.0) & (((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [1U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [1U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [1U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [1U])))) 
                 | vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [1U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b1 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b1 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk1 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[1U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[1U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[1U] = 0U;
            }
        }
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [2U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge
             [2U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk2)) 
                   >= 42.0) & (((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [2U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [2U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [2U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [2U])))) 
                 | vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [2U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b2 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b2 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk2 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[2U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[2U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[2U] = 0U;
            }
        }
        if ((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge
             [3U] & vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge
             [3U])) {
            if ((((VL_ITOR_D_Q(64, ((QData)(VL_TIME_UNITED_Q(1000)) 
                                    - vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RAS_chk3)) 
                   >= 42.0) & (((((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) 
                                  & VL_LTES_III(32, 1U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [3U])) 
                                 | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) 
                                    & VL_LTES_III(32, 2U, 
                                                  vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                  [3U]))) 
                                | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) 
                                   & VL_LTES_III(32, 4U, 
                                                 vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                 [3U]))) 
                               | ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) 
                                  & VL_LTES_III(32, 8U, 
                                                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Count_precharge
                                                [3U])))) 
                 | vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read
                 [3U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Pc_b3 = 1U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Act_b3 = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RP_chk3 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Auto_precharge[3U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_precharge[3U] = 0U;
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__RW_interrupt_read[3U] = 0U;
            }
        }
        if ((6U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
             [0U])) {
            if (((vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_precharge
                  [0U] == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank)) 
                 | vlSelf->sdram_tb__DOT__u_sdram_model__DOT__A10_precharge
                 [0U])) {
                if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
        } else if ((8U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
                    [0U])) {
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
            }
        }
        if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable)))) {
            vlSelf->__Vintraval_h69ef25c5__0 = 0U;
            Vsdram_tb___024root___eval_initial__TOP__Vtiming__4____Vfork_2__1(vlSelf, vlSelf->__Vintraval_h69ef25c5__0);
        }
        if (((2U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
              [0U]) | (3U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
                       [0U]))) {
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank 
                = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                [0U];
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col 
                = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst 
                = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            if ((0U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                 [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr;
            } else if ((1U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr;
            } else if ((2U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr;
            } else if ((3U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr;
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter = 0U;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 1U;
        } else if (((4U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
                     [0U]) | (5U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Command
                              [0U]))) {
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank 
                = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                [0U];
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col 
                = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst 
                = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_addr
                [0U];
            if ((0U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                 [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B0_row_addr;
            } else if ((1U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B1_row_addr;
            } else if ((2U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B2_row_addr;
            } else if ((3U == vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank_addr
                        [0U])) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__B3_row_addr;
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter = 0U;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 1U;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
        }
        if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable) {
            if ((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank0
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank1
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((2U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank2
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((3U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank3
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U & (~ (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm)))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = ((0xff00U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm)) 
                       | (0xffU & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data)));
            }
            if ((1U & (~ ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm) 
                          >> 1U)))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = ((0xffU & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm)) 
                       | (0xff00U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data)));
            }
            if ((3U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank3[(
                                                                  ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((2U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank2[(
                                                                  ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((1U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank1[(
                                                                  ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank0[(
                                                                  ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))] 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            }
            if ((3U != (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_chk[vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank] 
                    = VL_TIME_UNITED_Q(1000);
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter[vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank] = 0U;
            }
            co_await vlSelf->__VdlySched.delay(0x1b58ULL, 
                                               nullptr, 
                                               "../models/MT48LC8M16A2.v", 
                                               777);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter)));
            if ((8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                if ((8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp 
                        = ((0x1f8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)) 
                           | (7U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter) 
                                    ^ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst))));
                }
            } else {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)));
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col 
                = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2)
                    ? ((0x1feU & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)) 
                       | (1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)))
                    : ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4)
                        ? ((0x1fcU & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)) 
                           | (3U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)))
                        : ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8)
                            ? ((0x1f8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)) 
                               | (7U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)))
                            : (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp))));
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_burst_mode) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) {
                if ((1U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) {
                if ((2U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) {
                if ((4U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) {
                if ((8U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
        } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable) {
            if ((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank0
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank1
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((2U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank2
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((3U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Bank3
                    [(((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Row) 
                       << 9U) | (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col))];
            }
            if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = (0xff00U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm));
            }
            if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dqm_reg0))) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm 
                    = (0xffU & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm));
            }
            vlSelf->__Vintraval_h9edf9348__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_dqm;
            co_await vlSelf->__VdlySched.delay(0x1770ULL, 
                                               nullptr, 
                                               "../models/MT48LC8M16A2.v", 
                                               788);
            vlSelf->__Vm_traceActivity[2U] = 1U;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg 
                = vlSelf->__Vintraval_h9edf9348__0;
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter)));
            if ((8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                if ((8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Mode_reg))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp 
                        = ((0x1f8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)) 
                           | (7U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter) 
                                    ^ (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_brst))));
                }
            } else {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)));
            }
            vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col 
                = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2)
                    ? ((0x1feU & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)) 
                       | (1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)))
                    : ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4)
                        ? ((0x1fcU & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)) 
                           | (3U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)))
                        : ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8)
                            ? ((0x1f8U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col)) 
                               | (7U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp)))
                            : (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Col_temp))));
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_burst_mode) {
                vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_1) {
                if ((1U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_2) {
                if ((2U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_4) {
                if ((4U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_length_8) {
                if ((8U <= (IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Burst_counter))) {
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_in_enable = 0U;
                    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Data_out_enable = 0U;
                }
            }
        }
    }
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsdram_tb___024root___dump_triggers__act(Vsdram_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsdram_tb___024root___eval_triggers__act(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->sdram_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__u_sdram_model__DOT__Sys_clk__0))) 
                                     | vlSelf->__VdlySched.awaitingCurrentTime()));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->sdram_tb__DOT__sdram_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__sdram_clk__0))));
    vlSelf->__VactTriggered.set(3U, ((~ (IData)(vlSelf->sdram_tb__DOT__sdram_clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__sdram_clk__0)));
    vlSelf->__VactTriggered.set(4U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(5U, ((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__u_sdram_model__DOT__Sys_clk__0))));
    vlSelf->__VactTriggered.set(6U, (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [0U] != vlSelf->__Vtrigprevexpr_h7fb8c6b6__0));
    vlSelf->__VactTriggered.set(7U, (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [1U] != vlSelf->__Vtrigprevexpr_h7fb8c6f5__0));
    vlSelf->__VactTriggered.set(8U, (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [2U] != vlSelf->__Vtrigprevexpr_h7fb8c738__0));
    vlSelf->__VactTriggered.set(9U, (vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
                                     [3U] != vlSelf->__Vtrigprevexpr_h7fb8c55c__0));
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__clk__0 
        = vlSelf->sdram_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__u_sdram_model__DOT__Sys_clk__0 
        = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Sys_clk;
    vlSelf->__Vtrigprevexpr___TOP__sdram_tb__DOT__sdram_clk__0 
        = vlSelf->sdram_tb__DOT__sdram_clk;
    vlSelf->__Vtrigprevexpr_h7fb8c6b6__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [0U];
    vlSelf->__Vtrigprevexpr_h7fb8c6f5__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [1U];
    vlSelf->__Vtrigprevexpr_h7fb8c738__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [2U];
    vlSelf->__Vtrigprevexpr_h7fb8c55c__0 = vlSelf->sdram_tb__DOT__u_sdram_model__DOT__WR_counter
        [3U];
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(6U, 1U);
        vlSelf->__VactTriggered.set(7U, 1U);
        vlSelf->__VactTriggered.set(8U, 1U);
        vlSelf->__VactTriggered.set(9U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsdram_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsdram_tb___024root___nba_sequent__TOP__0(Vsdram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsdram_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting = 0;
    SData/*15:0*/ __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2 = 0;
    IData/*31:0*/ __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg = 0;
    CData/*3:0*/ __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg = 0;
    // Body
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg;
    __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt)));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_reg 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd;
    if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle = 1U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state 
            = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next;
    } else {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle = 0U;
    }
    if ((0U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2))) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh = 1U;
        if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay) {
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting = 1U;
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2 = 0x33U;
        } else {
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting = 0U;
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2 = 0x187U;
        }
    } else {
        __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2 
            = (0xffffU & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2) 
                          - (IData)(1U)));
    }
    if (((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack) 
         & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting)))) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh = 0U;
    }
    if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__byte_misalign 
            = (1U & vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr);
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank 
            = (3U & (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
                     >> 0x16U));
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row 
            = (0xfffU & (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
                         >> 0xaU));
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col 
            = (0x1ffU & (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
                         >> 1U));
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd;
    }
    if (vlSelf->sdram_tb__DOT__rst) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt = 0U;
        __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg = 0U;
    } else {
        if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req) {
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg 
                = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data;
        }
        if (((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr) 
             | (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas))) {
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg 
                = (((IData)(vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Dq_reg) 
                    << 0x10U) | (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg 
                                 >> 0x10U));
        }
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg 
        = __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__data_reg;
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v0) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v0 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v1) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v1;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v1 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v2) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v2 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v3) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v3 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v4) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v4;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v4 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v5) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v5 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v6) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v6 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v7) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v7;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v7 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v8) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v8 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v9) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v9 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v10) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v10;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v10 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v11) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v11 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v12) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v12 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v13) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v13;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v13 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v14) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v14 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v15) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v15 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v16) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v16;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v16 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v17) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v17 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v18) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v18 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v19) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v19;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v19 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v20) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v20 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v21) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v21 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v22) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v22;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v22 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v23) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v23 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v24) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v24 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v25) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v25;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v25 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v26) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v26 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v27) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v27 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v28) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__write_data__v28;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v28 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v29) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.write_data = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__write_data__v29 = 0U;
    }
    if (vlSelf->sdram_tb__DOT__rst) {
        __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg = 0U;
    } else {
        if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req) {
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg 
                = (0xfU & (~ (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr)));
        }
        if (((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr) 
             | (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas))) {
            __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg 
                = (0xcU | (3U & ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg) 
                                 >> 2U)));
        }
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg 
        = __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg;
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v0) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v0 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v1) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v1 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v2) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v2 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v3) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v3 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v4) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v4 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v5) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v5 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v6) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v6 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v7) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v7 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v8) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v8 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v9) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v9 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v10) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v10 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v11) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v11 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v12) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v12 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v13) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v13 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v14) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v14 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v15) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v15 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v16) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v16 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v17) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v17 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v18) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v18 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v19) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v19 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v20) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v20 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v21) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v21 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v22) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v22 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v23) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v23 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v24) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v24 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v25) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v25 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v26) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v26 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v27) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v27 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v28) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0xfU;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v28 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v29) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__wr__v29 = 0U;
    }
    if (vlSelf->sdram_tb__DOT__rst) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_reg = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle = 0U;
        __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2 = 0x32U;
        __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh = 0U;
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt2 
        = __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__cnt2;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting 
        = __Vdly__sdram_tb__DOT__u_sdram_controller__DOT__booting;
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v0) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v0 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v2) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v2 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v4) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v4 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v6) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v6 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v8) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v8 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v10) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v10 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v12) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v12 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v14) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v14 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v16) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v16 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v18) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v18 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v1) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v1;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v1 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v3) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v3;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v3 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v5) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v5;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v5 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v7) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v7;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v7 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v9) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v9;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v9 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v11) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v11;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v11 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v13) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v13;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v13 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v15) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v15;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v15 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v17) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v17;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v17 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v19) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.addr 
            = vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvval__addr__v19;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__addr__v19 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v0) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v0 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v1) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v1 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v2) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v2 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v3) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v3 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v4) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v4 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v5) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v5 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v6) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v6 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v7) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v7 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v8) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v8 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v9) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v9 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v10) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v10 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v11) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v11 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v12) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v12 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v13) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v13 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v14) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v14 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v15) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v15 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v16) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v16 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v17) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v17 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v18) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v18 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v19) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v19 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v20) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v20 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v21) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v21 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v22) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v22 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v23) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v23 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v24) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v24 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v25) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v25 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v26) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v26 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v27) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v27 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v28) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 1U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v28 = 0U;
    }
    if (vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v29) {
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd = 0U;
        vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.__Vdlyvset__rd__v29 = 0U;
    }
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.write_data 
        = (0xffffU & vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg);
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd;
    if (vlSelf->sdram_tb__DOT__rst) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__byte_misalign = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw = 0U;
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd_cas = 0U;
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay = 0U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm = 0U;
    if ((1U & (~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__refresh_ack = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__boot_delay = 1U;
                vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm = 3U;
            }
        }
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = 0U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 7U;
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba = 0U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr = 0x400U;
    vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.dqm = 
        ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw)
          ? 0U : (3U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__dqm_reg)));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req 
        = ((IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.rd) 
           | (0U != (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.wr)));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd = 0U;
    if ((4U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_wr = 1U;
                if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 4U;
                }
            } else if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 5U;
            }
        } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 3U;
            }
        }
        if ((1U & (~ ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = 1U;
                if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh) {
                    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy = 0U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 1U;
            }
        } else if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 0U;
        }
    } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__first_cycle) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd = 2U;
        }
    }
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Read_enable 
        = (IData)((5U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)));
    vlSelf->sdram_tb__DOT__u_sdram_model__DOT__Write_enable 
        = (IData)((4U == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_cmd)));
    if ((4U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay 
                = ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))
                    ? 2U : 3U);
        } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
        }
    } else if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay 
            = ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))
                ? 2U : 0U);
    } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay = 0U;
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__cnt) 
           == (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_delay));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__valid_req 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rdy) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req));
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
        = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state;
    if ((4U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba 
                = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank;
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr 
                = ((0xe00U & (IData)(vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr)) 
                   | (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__col));
            if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd = 1U;
            }
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 4U;
        } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba 
                = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__bank;
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr 
                = vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__row;
            vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
                = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rw)
                    ? 6U : 7U);
        } else {
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__req) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 5U;
            }
            if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__trigger_refresh) {
                vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 3U;
            }
        }
    } else if ((2U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        if ((1U & (~ (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state)))) {
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.ba = 0U;
            vlSymsp->TOP__sdram_tb__DOT__sdram_dev_if.addr = 0x21U;
        }
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
            = ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))
                ? 4U : 3U);
    } else if ((1U & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state))) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next 
            = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting)
                ? 2U : 4U);
    } else if (vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__booting) {
        vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__state_next = 1U;
    }
    vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__sd_rd) 
           & (IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__last_cycle));
    vlSymsp->TOP__sdram_tb__DOT__sdram_ctrl_if.read_data 
        = ((IData)(vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__rvalid)
            ? vlSelf->sdram_tb__DOT__u_sdram_controller__DOT__data_reg
            : 0U);
}
