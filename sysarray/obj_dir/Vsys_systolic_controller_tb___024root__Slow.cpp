// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsys_systolic_controller_tb.h for the primary calling header

#include "Vsys_systolic_controller_tb__pch.h"

void Vsys_systolic_controller_tb___024root___ctor_var_reset(Vsys_systolic_controller_tb___024root* vlSelf);

Vsys_systolic_controller_tb___024root::Vsys_systolic_controller_tb___024root(Vsys_systolic_controller_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vsys_systolic_controller_tb___024root___ctor_var_reset(this);
}

void Vsys_systolic_controller_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsys_systolic_controller_tb___024root::~Vsys_systolic_controller_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
