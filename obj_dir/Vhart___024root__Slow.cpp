// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhart.h for the primary calling header

#include "Vhart__pch.h"

void Vhart___024root___ctor_var_reset(Vhart___024root* vlSelf);

Vhart___024root::Vhart___024root(Vhart__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vhart___024root___ctor_var_reset(this);
}

void Vhart___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vhart___024root::~Vhart___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
