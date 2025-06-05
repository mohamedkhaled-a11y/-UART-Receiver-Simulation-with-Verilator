// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_rx.h for the primary calling header

#include "Vuart_rx.h"
#include "Vuart_rx__Syms.h"

//==========

void Vuart_rx::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vuart_rx::eval\n"); );
    Vuart_rx__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("uart_rx.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vuart_rx::_eval_initial_loop(Vuart_rx__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("uart_rx.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vuart_rx::_sequent__TOP__2(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_sequent__TOP__2\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__uart_rx__DOT__data_buffer;
    CData/*2:0*/ __Vdly__uart_rx__DOT__bit_index;
    CData/*1:0*/ __Vdly__uart_rx__DOT__state;
    SData/*15:0*/ __Vdly__uart_rx__DOT__counter;
    // Body
    __Vdly__uart_rx__DOT__state = vlTOPp->uart_rx__DOT__state;
    __Vdly__uart_rx__DOT__bit_index = vlTOPp->uart_rx__DOT__bit_index;
    __Vdly__uart_rx__DOT__counter = vlTOPp->uart_rx__DOT__counter;
    __Vdly__uart_rx__DOT__data_buffer = vlTOPp->uart_rx__DOT__data_buffer;
    if ((0U == (IData)(vlTOPp->uart_rx__DOT__state))) {
        __Vdly__uart_rx__DOT__data_buffer = 0U;
        vlTOPp->uart_rx__DOT__dataReady = 0U;
        __Vdly__uart_rx__DOT__counter = 0U;
        __Vdly__uart_rx__DOT__bit_index = 0U;
        if ((1U & (~ (IData)(vlTOPp->uart_rx__DOT__rx)))) {
            __Vdly__uart_rx__DOT__state = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->uart_rx__DOT__state))) {
            if ((7U == (IData)(vlTOPp->uart_rx__DOT__counter))) {
                if (vlTOPp->uart_rx__DOT__rx) {
                    __Vdly__uart_rx__DOT__state = 0U;
                } else {
                    __Vdly__uart_rx__DOT__counter = 0U;
                    __Vdly__uart_rx__DOT__state = 2U;
                }
            } else {
                __Vdly__uart_rx__DOT__counter = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlTOPp->uart_rx__DOT__counter)));
            }
        } else {
            if ((2U == (IData)(vlTOPp->uart_rx__DOT__state))) {
                if ((0xfU > (IData)(vlTOPp->uart_rx__DOT__counter))) {
                    __Vdly__uart_rx__DOT__counter = 
                        (0xffffU & ((IData)(1U) + (IData)(vlTOPp->uart_rx__DOT__counter)));
                } else {
                    __Vdly__uart_rx__DOT__data_buffer 
                        = (((~ ((IData)(1U) << (IData)(vlTOPp->uart_rx__DOT__bit_index))) 
                            & (IData)(__Vdly__uart_rx__DOT__data_buffer)) 
                           | ((IData)(vlTOPp->uart_rx__DOT__rx) 
                              << (IData)(vlTOPp->uart_rx__DOT__bit_index)));
                    __Vdly__uart_rx__DOT__counter = 0U;
                    if ((7U == (IData)(vlTOPp->uart_rx__DOT__bit_index))) {
                        __Vdly__uart_rx__DOT__state = 3U;
                    } else {
                        __Vdly__uart_rx__DOT__bit_index 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->uart_rx__DOT__bit_index)));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->uart_rx__DOT__state))) {
                    if ((0xfU > (IData)(vlTOPp->uart_rx__DOT__counter))) {
                        __Vdly__uart_rx__DOT__counter 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlTOPp->uart_rx__DOT__counter)));
                    } else {
                        vlTOPp->uart_rx__DOT__dataReady = 1U;
                        vlTOPp->data_out = vlTOPp->uart_rx__DOT__data_buffer;
                        __Vdly__uart_rx__DOT__counter = 0U;
                        __Vdly__uart_rx__DOT__state = 0U;
                    }
                } else {
                    __Vdly__uart_rx__DOT__state = 0U;
                }
            }
        }
    }
    vlTOPp->uart_rx__DOT__state = __Vdly__uart_rx__DOT__state;
    vlTOPp->uart_rx__DOT__counter = __Vdly__uart_rx__DOT__counter;
    vlTOPp->uart_rx__DOT__bit_index = __Vdly__uart_rx__DOT__bit_index;
    vlTOPp->uart_rx__DOT__data_buffer = __Vdly__uart_rx__DOT__data_buffer;
    vlTOPp->data_ready = vlTOPp->uart_rx__DOT__dataReady;
    vlTOPp->uart_rx__DOT__rx = vlTOPp->uart_rx__DOT__rx_buffer;
    vlTOPp->uart_rx__DOT__rx_buffer = vlTOPp->i_rx;
}

void Vuart_rx::_eval(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_eval\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vuart_rx::_change_request(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_change_request\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vuart_rx::_change_request_1(Vuart_rx__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_change_request_1\n"); );
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vuart_rx::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_rx::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_rx & 0xfeU))) {
        Verilated::overWidthError("i_rx");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
