// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vuart_rx__Syms.h"


//======================

void Vuart_rx::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vuart_rx::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vuart_rx::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vuart_rx::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vuart_rx::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+8,"i_rx", false,-1);
        tracep->declBit(c+9,"clk", false,-1);
        tracep->declBus(c+10,"data_out", false,-1, 7,0);
        tracep->declBit(c+11,"data_ready", false,-1);
        tracep->declBus(c+12,"uart_rx CLKS_PER_BIT", false,-1, 31,0);
        tracep->declBit(c+8,"uart_rx i_rx", false,-1);
        tracep->declBit(c+9,"uart_rx clk", false,-1);
        tracep->declBus(c+10,"uart_rx data_out", false,-1, 7,0);
        tracep->declBit(c+11,"uart_rx data_ready", false,-1);
        tracep->declBus(c+13,"uart_rx Idle", false,-1, 31,0);
        tracep->declBus(c+14,"uart_rx start", false,-1, 31,0);
        tracep->declBus(c+15,"uart_rx datarcv", false,-1, 31,0);
        tracep->declBus(c+16,"uart_rx stop", false,-1, 31,0);
        tracep->declBus(c+1,"uart_rx state", false,-1, 1,0);
        tracep->declBus(c+2,"uart_rx bit_index", false,-1, 2,0);
        tracep->declBus(c+3,"uart_rx data_buffer", false,-1, 7,0);
        tracep->declBit(c+4,"uart_rx dataReady", false,-1);
        tracep->declBus(c+5,"uart_rx counter", false,-1, 15,0);
        tracep->declBit(c+6,"uart_rx rx_buffer", false,-1);
        tracep->declBit(c+7,"uart_rx rx", false,-1);
    }
}

void Vuart_rx::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vuart_rx::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vuart_rx::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vuart_rx__Syms* __restrict vlSymsp = static_cast<Vuart_rx__Syms*>(userp);
    Vuart_rx* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->uart_rx__DOT__state),2);
        tracep->fullCData(oldp+2,(vlTOPp->uart_rx__DOT__bit_index),3);
        tracep->fullCData(oldp+3,(vlTOPp->uart_rx__DOT__data_buffer),8);
        tracep->fullBit(oldp+4,(vlTOPp->uart_rx__DOT__dataReady));
        tracep->fullSData(oldp+5,(vlTOPp->uart_rx__DOT__counter),16);
        tracep->fullBit(oldp+6,(vlTOPp->uart_rx__DOT__rx_buffer));
        tracep->fullBit(oldp+7,(vlTOPp->uart_rx__DOT__rx));
        tracep->fullBit(oldp+8,(vlTOPp->i_rx));
        tracep->fullBit(oldp+9,(vlTOPp->clk));
        tracep->fullCData(oldp+10,(vlTOPp->data_out),8);
        tracep->fullBit(oldp+11,(vlTOPp->data_ready));
        tracep->fullIData(oldp+12,(0x10U),32);
        tracep->fullIData(oldp+13,(0U),32);
        tracep->fullIData(oldp+14,(1U),32);
        tracep->fullIData(oldp+15,(2U),32);
        tracep->fullIData(oldp+16,(3U),32);
    }
}
