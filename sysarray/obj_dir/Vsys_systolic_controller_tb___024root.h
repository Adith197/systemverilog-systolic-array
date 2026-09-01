// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsys_systolic_controller_tb.h for the primary calling header

#ifndef VERILATED_VSYS_SYSTOLIC_CONTROLLER_TB___024ROOT_H_
#define VERILATED_VSYS_SYSTOLIC_CONTROLLER_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsys_systolic_controller_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsys_systolic_controller_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ sys_systolic_controller_tb__DOT__clk;
    CData/*0:0*/ sys_systolic_controller_tb__DOT__rst;
    CData/*0:0*/ sys_systolic_controller_tb__DOT__start;
    CData/*3:0*/ sys_systolic_controller_tb__DOT__cycle;
    CData/*0:0*/ sys_systolic_controller_tb__DOT__busy;
    CData/*0:0*/ sys_systolic_controller_tb__DOT__done;
    CData/*1:0*/ sys_systolic_controller_tb__DOT__dut__DOT__state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*0:0*/, 4> sys_systolic_controller_tb__DOT__valid_a;
    VlUnpacked<CData/*0:0*/, 4> sys_systolic_controller_tb__DOT__valid_b;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h45971850__0;
    VlTriggerScheduler __VtrigSched_h45971781__0;

    // INTERNAL VARIABLES
    Vsys_systolic_controller_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vsys_systolic_controller_tb___024root(Vsys_systolic_controller_tb__Syms* symsp, const char* namep);
    ~Vsys_systolic_controller_tb___024root();
    VL_UNCOPYABLE(Vsys_systolic_controller_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
