// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VMD5__SYMS_H_
#define _VMD5__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmd5.h"
#include "Vmd5___024unit.h"

// SYMS CLASS
class Vmd5__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmd5*                          TOPp;
    Vmd5___024unit                 TOP____024unit;
    
    // CREATORS
    Vmd5__Syms(Vmd5* topp, const char* namep);
    ~Vmd5__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
