// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VHART__SYMS_H_
#define VERILATED_VHART__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vhart.h"

// INCLUDE MODULE CLASSES
#include "Vhart___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vhart__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vhart* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vhart___024root                TOP;

    // CONSTRUCTORS
    Vhart__Syms(VerilatedContext* contextp, const char* namep, Vhart* modelp);
    ~Vhart__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
