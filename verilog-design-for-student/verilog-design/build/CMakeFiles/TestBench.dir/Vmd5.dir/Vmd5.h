// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMD5_H_
#define _VMD5_H_  // guard

#include "verilated.h"

//==========

class Vmd5__Syms;
class Vmd5___024unit;


//----------

VL_MODULE(Vmd5) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vmd5___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(in_valid,0,0);
    VL_OUT8(out_valid,0,0);
    VL_OUT8(ready,0,0);
    VL_INW(in,127,0,4);
    VL_OUTW(out,127,0,4);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ md5__DOT__phase;
    CData/*7:0*/ md5__DOT__state;
    CData/*7:0*/ md5__DOT__next_state;
    CData/*0:0*/ md5__DOT__out_r;
    CData/*4:0*/ md5__DOT__r_s;
    CData/*1:0*/ md5__DOT__r_r;
    IData/*31:0*/ md5__DOT__A;
    IData/*31:0*/ md5__DOT__B;
    IData/*31:0*/ md5__DOT__C;
    IData/*31:0*/ md5__DOT__D;
    IData/*31:0*/ md5__DOT__AA;
    IData/*31:0*/ md5__DOT__BB;
    IData/*31:0*/ md5__DOT__CC;
    IData/*31:0*/ md5__DOT__DD;
    IData/*31:0*/ md5__DOT__next_A;
    IData/*31:0*/ md5__DOT__next_B;
    IData/*31:0*/ md5__DOT__next_C;
    IData/*31:0*/ md5__DOT__next_D;
    WData/*511:0*/ md5__DOT__msg[16];
    IData/*31:0*/ md5__DOT__r_a;
    IData/*31:0*/ md5__DOT__r_b;
    IData/*31:0*/ md5__DOT__r_c;
    IData/*31:0*/ md5__DOT__r_d;
    IData/*31:0*/ md5__DOT__r_m;
    IData/*31:0*/ md5__DOT__r_t;
    IData/*31:0*/ md5__DOT__r_out;
    IData/*31:0*/ md5__DOT__cya;
    IData/*31:0*/ md5__DOT__cyb;
    IData/*31:0*/ md5__DOT__cyc;
    IData/*31:0*/ md5__DOT__cyd;
    IData/*31:0*/ md5__DOT__round__DOT__res;
    WData/*127:0*/ md5__DOT__round__DOT__FGHI[4];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmd5__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmd5);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmd5(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmd5();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmd5__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmd5__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmd5__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vmd5__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmd5__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmd5__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmd5__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vmd5__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vmd5__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
