// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmd5.h for the primary calling header

#include "Vmd5___024unit.h"
#include "Vmd5__Syms.h"

//==========

VL_CTOR_IMP(Vmd5___024unit) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vmd5___024unit::__Vconfigure(Vmd5__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmd5___024unit::~Vmd5___024unit() {
}

void Vmd5___024unit::_initial__TOP____024unit__1(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vmd5___024unit::_initial__TOP____024unit__1\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP____024unit.S[0U] = 7U;
    vlSymsp->TOP____024unit.S[1U] = 0xcU;
    vlSymsp->TOP____024unit.S[2U] = 0x11U;
    vlSymsp->TOP____024unit.S[3U] = 0x16U;
    vlSymsp->TOP____024unit.S[4U] = 7U;
    vlSymsp->TOP____024unit.S[5U] = 0xcU;
    vlSymsp->TOP____024unit.S[6U] = 0x11U;
    vlSymsp->TOP____024unit.S[7U] = 0x16U;
    vlSymsp->TOP____024unit.S[8U] = 7U;
    vlSymsp->TOP____024unit.S[9U] = 0xcU;
    vlSymsp->TOP____024unit.S[0xaU] = 0x11U;
    vlSymsp->TOP____024unit.S[0xbU] = 0x16U;
    vlSymsp->TOP____024unit.S[0xcU] = 7U;
    vlSymsp->TOP____024unit.S[0xdU] = 0xcU;
    vlSymsp->TOP____024unit.S[0xeU] = 0x11U;
    vlSymsp->TOP____024unit.S[0xfU] = 0x16U;
    vlSymsp->TOP____024unit.S[0x10U] = 5U;
    vlSymsp->TOP____024unit.S[0x11U] = 9U;
    vlSymsp->TOP____024unit.S[0x12U] = 0xeU;
    vlSymsp->TOP____024unit.S[0x13U] = 0x14U;
    vlSymsp->TOP____024unit.S[0x14U] = 5U;
    vlSymsp->TOP____024unit.S[0x15U] = 9U;
    vlSymsp->TOP____024unit.S[0x16U] = 0xeU;
    vlSymsp->TOP____024unit.S[0x17U] = 0x14U;
    vlSymsp->TOP____024unit.S[0x18U] = 5U;
    vlSymsp->TOP____024unit.S[0x19U] = 9U;
    vlSymsp->TOP____024unit.S[0x1aU] = 0xeU;
    vlSymsp->TOP____024unit.S[0x1bU] = 0x14U;
    vlSymsp->TOP____024unit.S[0x1cU] = 5U;
    vlSymsp->TOP____024unit.S[0x1dU] = 9U;
    vlSymsp->TOP____024unit.S[0x1eU] = 0xeU;
    vlSymsp->TOP____024unit.S[0x1fU] = 0x14U;
    vlSymsp->TOP____024unit.S[0x20U] = 4U;
    vlSymsp->TOP____024unit.S[0x21U] = 0xbU;
    vlSymsp->TOP____024unit.S[0x22U] = 0x10U;
    vlSymsp->TOP____024unit.S[0x23U] = 0x17U;
    vlSymsp->TOP____024unit.S[0x24U] = 4U;
    vlSymsp->TOP____024unit.S[0x25U] = 0xbU;
    vlSymsp->TOP____024unit.S[0x26U] = 0x10U;
    vlSymsp->TOP____024unit.S[0x27U] = 0x17U;
    vlSymsp->TOP____024unit.S[0x28U] = 4U;
    vlSymsp->TOP____024unit.S[0x29U] = 0xbU;
    vlSymsp->TOP____024unit.S[0x2aU] = 0x10U;
    vlSymsp->TOP____024unit.S[0x2bU] = 0x17U;
    vlSymsp->TOP____024unit.S[0x2cU] = 4U;
    vlSymsp->TOP____024unit.S[0x2dU] = 0xbU;
    vlSymsp->TOP____024unit.S[0x2eU] = 0x10U;
    vlSymsp->TOP____024unit.S[0x2fU] = 0x17U;
    vlSymsp->TOP____024unit.S[0x30U] = 6U;
    vlSymsp->TOP____024unit.S[0x31U] = 0xaU;
    vlSymsp->TOP____024unit.S[0x32U] = 0xfU;
    vlSymsp->TOP____024unit.S[0x33U] = 0x15U;
    vlSymsp->TOP____024unit.S[0x34U] = 6U;
    vlSymsp->TOP____024unit.S[0x35U] = 0xaU;
    vlSymsp->TOP____024unit.S[0x36U] = 0xfU;
    vlSymsp->TOP____024unit.S[0x37U] = 0x15U;
    vlSymsp->TOP____024unit.S[0x38U] = 6U;
    vlSymsp->TOP____024unit.S[0x39U] = 0xaU;
    vlSymsp->TOP____024unit.S[0x3aU] = 0xfU;
    vlSymsp->TOP____024unit.S[0x3bU] = 0x15U;
    vlSymsp->TOP____024unit.S[0x3cU] = 6U;
    vlSymsp->TOP____024unit.S[0x3dU] = 0xaU;
    vlSymsp->TOP____024unit.S[0x3eU] = 0xfU;
    vlSymsp->TOP____024unit.S[0x3fU] = 0x15U;
    vlSymsp->TOP____024unit.K[0U] = 0xd76aa478U;
    vlSymsp->TOP____024unit.K[1U] = 0xe8c7b756U;
    vlSymsp->TOP____024unit.K[2U] = 0x242070dbU;
    vlSymsp->TOP____024unit.K[3U] = 0xc1bdceeeU;
    vlSymsp->TOP____024unit.K[4U] = 0xf57c0fafU;
    vlSymsp->TOP____024unit.K[5U] = 0x4787c62aU;
    vlSymsp->TOP____024unit.K[6U] = 0xa8304613U;
    vlSymsp->TOP____024unit.K[7U] = 0xfd469501U;
    vlSymsp->TOP____024unit.K[8U] = 0x698098d8U;
    vlSymsp->TOP____024unit.K[9U] = 0x8b44f7afU;
    vlSymsp->TOP____024unit.K[0xaU] = 0xffff5bb1U;
    vlSymsp->TOP____024unit.K[0xbU] = 0x895cd7beU;
    vlSymsp->TOP____024unit.K[0xcU] = 0x6b901122U;
    vlSymsp->TOP____024unit.K[0xdU] = 0xfd987193U;
    vlSymsp->TOP____024unit.K[0xeU] = 0xa679438eU;
    vlSymsp->TOP____024unit.K[0xfU] = 0x49b40821U;
    vlSymsp->TOP____024unit.K[0x10U] = 0xf61e2562U;
    vlSymsp->TOP____024unit.K[0x11U] = 0xc040b340U;
    vlSymsp->TOP____024unit.K[0x12U] = 0x265e5a51U;
    vlSymsp->TOP____024unit.K[0x13U] = 0xe9b6c7aaU;
    vlSymsp->TOP____024unit.K[0x14U] = 0xd62f105dU;
    vlSymsp->TOP____024unit.K[0x15U] = 0x2441453U;
    vlSymsp->TOP____024unit.K[0x16U] = 0xd8a1e681U;
    vlSymsp->TOP____024unit.K[0x17U] = 0xe7d3fbc8U;
    vlSymsp->TOP____024unit.K[0x18U] = 0x21e1cde6U;
    vlSymsp->TOP____024unit.K[0x19U] = 0xc33707d6U;
    vlSymsp->TOP____024unit.K[0x1aU] = 0xf4d50d87U;
    vlSymsp->TOP____024unit.K[0x1bU] = 0x455a14edU;
    vlSymsp->TOP____024unit.K[0x1cU] = 0xa9e3e905U;
    vlSymsp->TOP____024unit.K[0x1dU] = 0xfcefa3f8U;
    vlSymsp->TOP____024unit.K[0x1eU] = 0x676f02d9U;
    vlSymsp->TOP____024unit.K[0x1fU] = 0x8d2a4c8aU;
    vlSymsp->TOP____024unit.K[0x20U] = 0xfffa3942U;
    vlSymsp->TOP____024unit.K[0x21U] = 0x8771f681U;
    vlSymsp->TOP____024unit.K[0x22U] = 0x6d9d6122U;
    vlSymsp->TOP____024unit.K[0x23U] = 0xfde5380cU;
    vlSymsp->TOP____024unit.K[0x24U] = 0xa4beea44U;
    vlSymsp->TOP____024unit.K[0x25U] = 0x4bdecfa9U;
    vlSymsp->TOP____024unit.K[0x26U] = 0xf6bb4b60U;
    vlSymsp->TOP____024unit.K[0x27U] = 0xbebfbc70U;
    vlSymsp->TOP____024unit.K[0x28U] = 0x289b7ec6U;
    vlSymsp->TOP____024unit.K[0x29U] = 0xeaa127faU;
    vlSymsp->TOP____024unit.K[0x2aU] = 0xd4ef3085U;
    vlSymsp->TOP____024unit.K[0x2bU] = 0x4881d05U;
    vlSymsp->TOP____024unit.K[0x2cU] = 0xd9d4d039U;
    vlSymsp->TOP____024unit.K[0x2dU] = 0xe6db99e5U;
    vlSymsp->TOP____024unit.K[0x2eU] = 0x1fa27cf8U;
    vlSymsp->TOP____024unit.K[0x2fU] = 0xc4ac5665U;
    vlSymsp->TOP____024unit.K[0x30U] = 0xf4292244U;
    vlSymsp->TOP____024unit.K[0x31U] = 0x432aff97U;
    vlSymsp->TOP____024unit.K[0x32U] = 0xab9423a7U;
    vlSymsp->TOP____024unit.K[0x33U] = 0xfc93a039U;
    vlSymsp->TOP____024unit.K[0x34U] = 0x655b59c3U;
    vlSymsp->TOP____024unit.K[0x35U] = 0x8f0ccc92U;
    vlSymsp->TOP____024unit.K[0x36U] = 0xffeff47dU;
    vlSymsp->TOP____024unit.K[0x37U] = 0x85845dd1U;
    vlSymsp->TOP____024unit.K[0x38U] = 0x6fa87e4fU;
    vlSymsp->TOP____024unit.K[0x39U] = 0xfe2ce6e0U;
    vlSymsp->TOP____024unit.K[0x3aU] = 0xa3014314U;
    vlSymsp->TOP____024unit.K[0x3bU] = 0x4e0811a1U;
    vlSymsp->TOP____024unit.K[0x3cU] = 0xf7537e82U;
    vlSymsp->TOP____024unit.K[0x3dU] = 0xbd3af235U;
    vlSymsp->TOP____024unit.K[0x3eU] = 0x2ad7d2bbU;
    vlSymsp->TOP____024unit.K[0x3fU] = 0xeb86d391U;
}

void Vmd5___024unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vmd5___024unit::_ctor_var_reset\n"); );
    // Body
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            S[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            K[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
