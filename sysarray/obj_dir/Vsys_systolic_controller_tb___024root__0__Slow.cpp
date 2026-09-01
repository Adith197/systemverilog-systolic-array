// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsys_systolic_controller_tb.h for the primary calling header

#include "Vsys_systolic_controller_tb__pch.h"

void Vsys_systolic_controller_tb___024root___timing_ready(Vsys_systolic_controller_tb___024root* vlSelf);

VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___eval_static(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_static\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0 
        = vlSelfRef.sys_systolic_controller_tb__DOT__clk;
    Vsys_systolic_controller_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___eval_final(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_final\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsys_systolic_controller_tb___024root___eval_phase__stl(Vsys_systolic_controller_tb___024root* vlSelf);

VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___eval_settle(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_settle\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsys_systolic_controller_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb\\sys_systolic_controller_tb.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vsys_systolic_controller_tb___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vsys_systolic_controller_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsys_systolic_controller_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsys_systolic_controller_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD bool Vsys_systolic_controller_tb___024root___eval_phase__stl(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___eval_phase__stl\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsys_systolic_controller_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vsys_systolic_controller_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
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
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vsys_systolic_controller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsys_systolic_controller_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge sys_systolic_controller_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(negedge sys_systolic_controller_tb.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsys_systolic_controller_tb___024root___ctor_var_reset(Vsys_systolic_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root___ctor_var_reset\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->sys_systolic_controller_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4898552119159441644ull);
    vlSelf->sys_systolic_controller_tb__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5454921099502762094ull);
    vlSelf->sys_systolic_controller_tb__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18190154031620325451ull);
    vlSelf->sys_systolic_controller_tb__DOT__cycle = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12311022335070447242ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sys_systolic_controller_tb__DOT__valid_a[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12764048724786449360ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sys_systolic_controller_tb__DOT__valid_b[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10160136206093191749ull);
    }
    vlSelf->sys_systolic_controller_tb__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1455511271741697667ull);
    vlSelf->sys_systolic_controller_tb__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17367776265639478649ull);
    vlSelf->sys_systolic_controller_tb__DOT__dut__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2040310925880053038ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__sys_systolic_controller_tb__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
