// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsys_systolic_controller_tb.h for the primary calling header

#include "Vsys_systolic_controller_tb__pch.h"

VlCoroutine Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__0(Vsys_systolic_controller_tb___024root* vlSelf);
VlCoroutine Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__1(Vsys_systolic_controller_tb___024root* vlSelf);
VlCoroutine Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__2(Vsys_systolic_controller_tb___024root* vlSelf);

void Vsys_systolic_controller_tb___024root___eval_initial(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_initial\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSymsp->_vm_contextp__->dumpfile("sys_systolic_controller.vcd"s);
        vlSymsp->_traceDumpOpen();
    }
    Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971850__0(Vsys_systolic_controller_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__0(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sys_systolic_controller_tb__DOT__clk = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__rst = 1U;
    vlSelfRef.sys_systolic_controller_tb__DOT__start = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "tb\\sys_systolic_controller_tb.sv", 
                                         54);
    vlSelfRef.sys_systolic_controller_tb__DOT__rst = 0U;
    Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971850__0(vlSelf, 
                                                                      "@(negedge sys_systolic_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h45971850__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge sys_systolic_controller_tb.clk)", 
                                                         "tb\\sys_systolic_controller_tb.sv", 
                                                         58);
    vlSelfRef.sys_systolic_controller_tb__DOT__start = 1U;
    Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971850__0(vlSelf, 
                                                                      "@(negedge sys_systolic_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h45971850__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge sys_systolic_controller_tb.clk)", 
                                                         "tb\\sys_systolic_controller_tb.sv", 
                                                         61);
    vlSelfRef.sys_systolic_controller_tb__DOT__start = 0U;
    co_return;
}

VlCoroutine Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__1(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb\\sys_systolic_controller_tb.sv", 
                                             37);
        vlSelfRef.sys_systolic_controller_tb__DOT__clk 
            = (1U & (~ (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk)));
    }
    co_return;
}

void Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971781__0(Vsys_systolic_controller_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__2(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971781__0(vlSelf, 
                                                                          "@(posedge sys_systolic_controller_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h45971781__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sys_systolic_controller_tb.clk)", 
                                                             "tb\\sys_systolic_controller_tb.sv", 
                                                             85);
        if (VL_UNLIKELY((vlSelfRef.sys_systolic_controller_tb__DOT__done))) {
            VL_WRITEF_NX("Controller DONE at TIME=%0t\n",2, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                                 nullptr, 
                                                 "tb\\sys_systolic_controller_tb.sv", 
                                                 89);
            VL_FINISH_MT("tb\\sys_systolic_controller_tb.sv", 90, "");
        }
    }
    co_return;
}

bool Vsys_systolic_controller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*1:0*/, 256> Vsys_systolic_controller_tb__ConstPool__TABLE_hff976f7a_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vsys_systolic_controller_tb__ConstPool__TABLE_hc1f2d01b_0;
extern const VlUnpacked<CData/*3:0*/, 256> Vsys_systolic_controller_tb__ConstPool__TABLE_h16876aa3_0;

void Vsys_systolic_controller_tb___024root___nba_sequent__TOP__0(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___nba_sequent__TOP__0\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    VL_WRITEF_NX("TIME=%0t | CYCLE=%0d | BUSY=%b DONE=%b | VA=%b%b%b%b VB=%b%b%b%b\n",13, 'T',-9
                 , '#',64,VL_TIME_UNITED_Q(1000), '#',4,(IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__busy
                 , '#',1,(IData)(vlSelfRef.sys_systolic_controller_tb__DOT__done)
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[0U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[1U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[2U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[3U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[0U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[1U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[2U]
                 , '#',1,vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[3U]);
    __Vtableidx1 = (((IData)(vlSelfRef.sys_systolic_controller_tb__DOT__start) 
                     << 7U) | (((IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle) 
                                << 3U) | (((IData)(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state) 
                                           << 1U) | (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__rst))));
    if ((1U & Vsys_systolic_controller_tb__ConstPool__TABLE_hff976f7a_0
         [__Vtableidx1])) {
        vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state 
            = Vsys_systolic_controller_tb__ConstPool__TABLE_hc1f2d01b_0
            [__Vtableidx1];
    }
    if ((2U & Vsys_systolic_controller_tb__ConstPool__TABLE_hff976f7a_0
         [__Vtableidx1])) {
        vlSelfRef.sys_systolic_controller_tb__DOT__cycle 
            = Vsys_systolic_controller_tb__ConstPool__TABLE_h16876aa3_0
            [__Vtableidx1];
    }
    vlSelfRef.sys_systolic_controller_tb__DOT__done = 0U;
    if ((1U != (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state))) {
            if ((3U == (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state))) {
                vlSelfRef.sys_systolic_controller_tb__DOT__done = 1U;
            }
        }
    }
    vlSelfRef.sys_systolic_controller_tb__DOT__busy = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[0U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[1U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[2U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[3U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[0U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[1U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[2U] = 0U;
    vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[3U] = 0U;
    if ((1U == (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state))) {
        vlSelfRef.sys_systolic_controller_tb__DOT__busy = 1U;
        if ((4U > (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle))) {
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[0U] = 1U;
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[0U] = 1U;
        }
        if (((1U <= (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)) 
             & (5U > (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)))) {
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[1U] = 1U;
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[1U] = 1U;
        }
        if (((2U <= (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)) 
             & (6U > (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)))) {
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[2U] = 1U;
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[2U] = 1U;
        }
        if (((3U <= (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)) 
             & (7U > (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__cycle)))) {
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_b[3U] = 1U;
            vlSelfRef.sys_systolic_controller_tb__DOT__valid_a[3U] = 1U;
        }
    } else if ((2U == (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state))) {
        vlSelfRef.sys_systolic_controller_tb__DOT__busy = 1U;
    }
}

void Vsys_systolic_controller_tb___024root___timing_ready(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___timing_ready\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h45971850__0.ready("@(negedge sys_systolic_controller_tb.clk)");
    }
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h45971781__0.ready("@(posedge sys_systolic_controller_tb.clk)");
    }
}

void Vsys_systolic_controller_tb___024root___timing_resume(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___timing_resume\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h45971850__0.moveToResumeQueue(
                                                          "@(negedge sys_systolic_controller_tb.clk)");
    vlSelfRef.__VtrigSched_h45971781__0.moveToResumeQueue(
                                                          "@(posedge sys_systolic_controller_tb.clk)");
    vlSelfRef.__VtrigSched_h45971850__0.resume("@(negedge sys_systolic_controller_tb.clk)");
    vlSelfRef.__VtrigSched_h45971781__0.resume("@(posedge sys_systolic_controller_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsys_systolic_controller_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vsys_systolic_controller_tb___024root___eval_phase__act(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_phase__act\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0)) 
                                                          << 2U) 
                                                         | ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0 
            = vlSelfRef.sys_systolic_controller_tb__DOT__clk;
    }
    Vsys_systolic_controller_tb___024root___timing_ready(vlSelf);
    Vsys_systolic_controller_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsys_systolic_controller_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vsys_systolic_controller_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vsys_systolic_controller_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vsys_systolic_controller_tb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vsys_systolic_controller_tb___024root___eval_phase__inact(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_phase__inact\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb\\sys_systolic_controller_tb.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vsys_systolic_controller_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsys_systolic_controller_tb___024root___eval_phase__nba(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_phase__nba\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsys_systolic_controller_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vsys_systolic_controller_tb___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
            }
        }
        Vsys_systolic_controller_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vsys_systolic_controller_tb___024root___eval(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsys_systolic_controller_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb\\sys_systolic_controller_tb.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb\\sys_systolic_controller_tb.sv", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vsys_systolic_controller_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb\\sys_systolic_controller_tb.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vsys_systolic_controller_tb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vsys_systolic_controller_tb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vsys_systolic_controller_tb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971850__0(Vsys_systolic_controller_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971850__0\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0)) 
                                   << 2U) | ((IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0 
        = vlSelfRef.sys_systolic_controller_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h45971781__0.ready(__VeventDescription);
    }
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h45971850__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h45971850__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971781__0(Vsys_systolic_controller_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root____VbeforeTrig_h45971781__0\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0)) 
                                   << 2U) | ((IData)(vlSelfRef.sys_systolic_controller_tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0 
        = vlSelfRef.sys_systolic_controller_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h45971781__0.ready(__VeventDescription);
    }
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h45971850__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h45971850__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vsys_systolic_controller_tb___024root___eval_debug_assertions(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_debug_assertions\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
