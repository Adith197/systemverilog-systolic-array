// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsys_systolic_controller_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsys_systolic_controller_tb::Vsys_systolic_controller_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsys_systolic_controller_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsys_systolic_controller_tb::Vsys_systolic_controller_tb(const char* _vcname__)
    : Vsys_systolic_controller_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsys_systolic_controller_tb::~Vsys_systolic_controller_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsys_systolic_controller_tb___024root___eval_debug_assertions(Vsys_systolic_controller_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vsys_systolic_controller_tb___024root___eval_static(Vsys_systolic_controller_tb___024root* vlSelf);
void Vsys_systolic_controller_tb___024root___eval_initial(Vsys_systolic_controller_tb___024root* vlSelf);
void Vsys_systolic_controller_tb___024root___eval_settle(Vsys_systolic_controller_tb___024root* vlSelf);
void Vsys_systolic_controller_tb___024root___eval(Vsys_systolic_controller_tb___024root* vlSelf);

void Vsys_systolic_controller_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsys_systolic_controller_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsys_systolic_controller_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsys_systolic_controller_tb___024root___eval_static(&(vlSymsp->TOP));
        Vsys_systolic_controller_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vsys_systolic_controller_tb___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsys_systolic_controller_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vsys_systolic_controller_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vsys_systolic_controller_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vsys_systolic_controller_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vsys_systolic_controller_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsys_systolic_controller_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsys_systolic_controller_tb___024root___eval_final(Vsys_systolic_controller_tb___024root* vlSelf);

VL_ATTR_COLD void Vsys_systolic_controller_tb::final() {
    contextp()->executingFinal(true);
    Vsys_systolic_controller_tb___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsys_systolic_controller_tb::hierName() const { return vlSymsp->name(); }
const char* Vsys_systolic_controller_tb::modelName() const { return "Vsys_systolic_controller_tb"; }
unsigned Vsys_systolic_controller_tb::threads() const { return 1; }
void Vsys_systolic_controller_tb::prepareClone() const { contextp()->prepareClone(); }
void Vsys_systolic_controller_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsys_systolic_controller_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vsys_systolic_controller_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsys_systolic_controller_tb___024root__trace_init_top(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsys_systolic_controller_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsys_systolic_controller_tb___024root*>(voidSelf);
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vsys_systolic_controller_tb___024root__trace_decl_types(tracep);
    Vsys_systolic_controller_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsys_systolic_controller_tb___024root__trace_register(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsys_systolic_controller_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsys_systolic_controller_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 17);
    Vsys_systolic_controller_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
