// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_rx.h for the primary calling header

#include "Vuart_rx.h"
#include "Vuart_rx__Syms.h"

//==========

VL_CTOR_IMP(Vuart_rx) {
    Vuart_rx__Syms* __restrict vlSymsp = __VlSymsp = new Vuart_rx__Syms(this, name());
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vuart_rx::__Vconfigure(Vuart_rx__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vuart_rx::~Vuart_rx() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vuart_rx::_initial__TOP__1(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_initial__TOP__1\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->uart_rx__DOT__dataReady = 0U;
    vlTOPp->uart_rx__DOT__state = 0U;
    vlTOPp->uart_rx__DOT__bit_index = 0U;
    vlTOPp->uart_rx__DOT__data_buffer = 0U;
    vlTOPp->uart_rx__DOT__counter = 0U;
    vlTOPp->uart_rx__DOT__rx = 1U;
    vlTOPp->uart_rx__DOT__rx_buffer = 1U;
}

void Vuart_rx::_settle__TOP__3(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_settle__TOP__3\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data_ready = vlTOPp->uart_rx__DOT__dataReady;
}

void Vuart_rx::_eval_initial(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_eval_initial\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vuart_rx::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::final\n"); );
    // Variables
    Vuart_rx__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vuart_rx::_eval_settle(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_eval_settle\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vuart_rx::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_ctor_var_reset\n"); );
    // Body
    i_rx = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    data_out = VL_RAND_RESET_I(8);
    data_ready = VL_RAND_RESET_I(1);
    uart_rx__DOT__state = VL_RAND_RESET_I(2);
    uart_rx__DOT__bit_index = VL_RAND_RESET_I(3);
    uart_rx__DOT__data_buffer = VL_RAND_RESET_I(8);
    uart_rx__DOT__dataReady = VL_RAND_RESET_I(1);
    uart_rx__DOT__counter = VL_RAND_RESET_I(16);
    uart_rx__DOT__rx_buffer = VL_RAND_RESET_I(1);
    uart_rx__DOT__rx = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
