// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmd5.h for the primary calling header

#ifndef _VMD5___024UNIT_H_
#define _VMD5___024UNIT_H_  // guard

#include "verilated.h"

//==========

class Vmd5__Syms;

//----------

VL_MODULE(Vmd5___024unit) {
  public:
    
    // LOCAL SIGNALS
    IData/*31:0*/ S[64];
    IData/*31:0*/ K[64];
    
    // INTERNAL VARIABLES
  private:
    Vmd5__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmd5___024unit);  ///< Copying not allowed
  public:
    Vmd5___024unit(const char* name = "TOP");
    ~Vmd5___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vmd5__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP____024unit__1(Vmd5__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
