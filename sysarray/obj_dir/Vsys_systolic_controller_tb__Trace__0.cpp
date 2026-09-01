// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vsys_systolic_controller_tb__Syms.h"


void Vsys_systolic_controller_tb___024root__trace_chg_0_sub_0(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsys_systolic_controller_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root__trace_chg_0\n"); );
    // Body
    Vsys_systolic_controller_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsys_systolic_controller_tb___024root*>(voidSelf);
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vsys_systolic_controller_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsys_systolic_controller_tb___024root__trace_chg_dtype____0(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 4>& __VdtypeVar);
void Vsys_systolic_controller_tb___024root__trace_chg_dtype____1(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 4>& __VdtypeVar);

void Vsys_systolic_controller_tb___024root__trace_chg_0_sub_0(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root__trace_chg_0_sub_0\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.sys_systolic_controller_tb__DOT__cycle),4);
        Vsys_systolic_controller_tb___024root__trace_chg_dtype____0(vlSelf, bufp, 1, vlSelfRef.sys_systolic_controller_tb__DOT__valid_a);
        Vsys_systolic_controller_tb___024root__trace_chg_dtype____1(vlSelf, bufp, 5, vlSelfRef.sys_systolic_controller_tb__DOT__valid_b);
        bufp->chgBit(oldp+9,(vlSelfRef.sys_systolic_controller_tb__DOT__busy));
        bufp->chgBit(oldp+10,(vlSelfRef.sys_systolic_controller_tb__DOT__done));
        bufp->chgCData(oldp+11,(vlSelfRef.sys_systolic_controller_tb__DOT__dut__DOT__state),2);
    }
    bufp->chgBit(oldp+12,(vlSelfRef.sys_systolic_controller_tb__DOT__clk));
    bufp->chgBit(oldp+13,(vlSelfRef.sys_systolic_controller_tb__DOT__rst));
    bufp->chgBit(oldp+14,(vlSelfRef.sys_systolic_controller_tb__DOT__start));
}

void Vsys_systolic_controller_tb___024root__trace_chg_dtype____0(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root__trace_chg_dtype____0\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,(__VdtypeVar[0]));
    bufp->chgBit(oldp+1,(__VdtypeVar[1]));
    bufp->chgBit(oldp+2,(__VdtypeVar[2]));
    bufp->chgBit(oldp+3,(__VdtypeVar[3]));
}

void Vsys_systolic_controller_tb___024root__trace_chg_dtype____1(Vsys_systolic_controller_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root__trace_chg_dtype____1\n"); );
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,(__VdtypeVar[0]));
    bufp->chgBit(oldp+1,(__VdtypeVar[1]));
    bufp->chgBit(oldp+2,(__VdtypeVar[2]));
    bufp->chgBit(oldp+3,(__VdtypeVar[3]));
}

void Vsys_systolic_controller_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsys_systolic_controller_tb___024root__trace_cleanup\n"); );
    // Body
    Vsys_systolic_controller_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsys_systolic_controller_tb___024root*>(voidSelf);
    Vsys_systolic_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
