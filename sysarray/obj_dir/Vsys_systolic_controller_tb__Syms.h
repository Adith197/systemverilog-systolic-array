// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSYS_SYSTOLIC_CONTROLLER_TB__SYMS_H_
#define VERILATED_VSYS_SYSTOLIC_CONTROLLER_TB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vsys_systolic_controller_tb.h"

// INCLUDE MODULE CLASSES
#include "Vsys_systolic_controller_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vsys_systolic_controller_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsys_systolic_controller_tb* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsys_systolic_controller_tb___024root TOP;

    // CONSTRUCTORS
    Vsys_systolic_controller_tb__Syms(VerilatedContext* contextp, const char* namep, Vsys_systolic_controller_tb* modelp);
    ~Vsys_systolic_controller_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
