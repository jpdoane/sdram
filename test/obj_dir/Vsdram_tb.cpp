// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsdram_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsdram_tb::Vsdram_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsdram_tb__Syms(contextp(), _vcname__, this)}
    , __PVT__sdram_tb__DOT__sdram_ctrl_if{vlSymsp->TOP.__PVT__sdram_tb__DOT__sdram_ctrl_if}
    , __PVT__sdram_tb__DOT__sdram_dev_if{vlSymsp->TOP.__PVT__sdram_tb__DOT__sdram_dev_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsdram_tb::Vsdram_tb(const char* _vcname__)
    : Vsdram_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsdram_tb::~Vsdram_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsdram_tb___024root___eval_debug_assertions(Vsdram_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vsdram_tb___024root___eval_static(Vsdram_tb___024root* vlSelf);
void Vsdram_tb___024root___eval_initial(Vsdram_tb___024root* vlSelf);
void Vsdram_tb___024root___eval_settle(Vsdram_tb___024root* vlSelf);
void Vsdram_tb___024root___eval(Vsdram_tb___024root* vlSelf);

void Vsdram_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsdram_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsdram_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsdram_tb___024root___eval_static(&(vlSymsp->TOP));
        Vsdram_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vsdram_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsdram_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vsdram_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vsdram_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vsdram_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vsdram_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsdram_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsdram_tb___024root___eval_final(Vsdram_tb___024root* vlSelf);

VL_ATTR_COLD void Vsdram_tb::final() {
    Vsdram_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsdram_tb::hierName() const { return vlSymsp->name(); }
const char* Vsdram_tb::modelName() const { return "Vsdram_tb"; }
unsigned Vsdram_tb::threads() const { return 1; }
void Vsdram_tb::prepareClone() const { contextp()->prepareClone(); }
void Vsdram_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsdram_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsdram_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsdram_tb___024root__trace_init_top(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsdram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsdram_tb___024root*>(voidSelf);
    Vsdram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsdram_tb___024root__trace_decl_types(tracep);
    Vsdram_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsdram_tb___024root__trace_register(Vsdram_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsdram_tb::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsdram_tb::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsdram_tb___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
