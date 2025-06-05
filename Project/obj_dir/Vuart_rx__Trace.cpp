// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vuart_rx__Syms.h"


void Vuart_rx::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vuart_rx::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->uart_rx__DOT__state),2);
            tracep->chgCData(oldp+1,(vlTOPp->uart_rx__DOT__bit_index),3);
            tracep->chgCData(oldp+2,(vlTOPp->uart_rx__DOT__data_buffer),8);
            tracep->chgBit(oldp+3,(vlTOPp->uart_rx__DOT__dataReady));
            tracep->chgSData(oldp+4,(vlTOPp->uart_rx__DOT__counter),16);
            tracep->chgBit(oldp+5,(vlTOPp->uart_rx__DOT__rx_buffer));
            tracep->chgBit(oldp+6,(vlTOPp->uart_rx__DOT__rx));
        }
        tracep->chgBit(oldp+7,(vlTOPp->i_rx));
        tracep->chgBit(oldp+8,(vlTOPp->clk));
        tracep->chgCData(oldp+9,(vlTOPp->data_out),8);
        tracep->chgBit(oldp+10,(vlTOPp->data_ready));
    }
}

void Vuart_rx::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
