// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmd5.h for the primary calling header

#include "Vmd5.h"
#include "Vmd5__Syms.h"

//==========

VL_CTOR_IMP(Vmd5) {
    Vmd5__Syms* __restrict vlSymsp = __VlSymsp = new Vmd5__Syms(this, name());
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, Vmd5___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmd5::__Vconfigure(Vmd5__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmd5::~Vmd5() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vmd5::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmd5::eval\n"); );
    Vmd5__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("md5.v", 14, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmd5::_eval_initial_loop(Vmd5__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
            VL_FATAL_MT("md5.v", 14, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vmd5::_sequent__TOP__1(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_sequent__TOP__1\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__md5__DOT__phase;
    // Body
    __Vdly__md5__DOT__phase = vlTOPp->md5__DOT__phase;
    if (vlTOPp->rst) {
        vlTOPp->md5__DOT__AA = 0U;
        vlTOPp->md5__DOT__BB = 0U;
        vlTOPp->md5__DOT__CC = 0U;
        vlTOPp->md5__DOT__DD = 0U;
        __Vdly__md5__DOT__phase = 0U;
        vlTOPp->md5__DOT__msg[0U] = 0U;
        vlTOPp->md5__DOT__msg[1U] = 0U;
        vlTOPp->md5__DOT__msg[2U] = 0U;
        vlTOPp->md5__DOT__msg[3U] = 0U;
        vlTOPp->md5__DOT__msg[4U] = 0U;
        vlTOPp->md5__DOT__msg[5U] = 0U;
        vlTOPp->md5__DOT__msg[6U] = 0U;
        vlTOPp->md5__DOT__msg[7U] = 0U;
        vlTOPp->md5__DOT__msg[8U] = 0U;
        vlTOPp->md5__DOT__msg[9U] = 0U;
        vlTOPp->md5__DOT__msg[0xaU] = 0U;
        vlTOPp->md5__DOT__msg[0xbU] = 0U;
        vlTOPp->md5__DOT__msg[0xcU] = 0U;
        vlTOPp->md5__DOT__msg[0xdU] = 0U;
        vlTOPp->md5__DOT__msg[0xeU] = 0U;
        vlTOPp->md5__DOT__msg[0xfU] = 0U;
        vlTOPp->md5__DOT__out_r = 0U;
    } else {
        __Vdly__md5__DOT__phase = ((1U & (((IData)(vlTOPp->md5__DOT__next_state) 
                                           >> 1U) & (IData)(vlTOPp->md5__DOT__state)))
                                    ? 0U : (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->md5__DOT__phase))));
        vlTOPp->md5__DOT__out_r = (1U & ((IData)(vlTOPp->md5__DOT__state) 
                                         >> 5U));
        if ((1U & (IData)(vlTOPp->md5__DOT__next_state))) {
            vlTOPp->md5__DOT__AA = 0U;
            vlTOPp->md5__DOT__BB = 0U;
            vlTOPp->md5__DOT__CC = 0U;
            vlTOPp->md5__DOT__DD = 0U;
        } else {
            if ((1U & (((IData)(vlTOPp->md5__DOT__next_state) 
                        >> 1U) & (IData)(vlTOPp->md5__DOT__state)))) {
                vlTOPp->md5__DOT__AA = vlTOPp->md5__DOT__A;
                vlTOPp->md5__DOT__BB = vlTOPp->md5__DOT__B;
                vlTOPp->md5__DOT__CC = vlTOPp->md5__DOT__C;
                vlTOPp->md5__DOT__DD = vlTOPp->md5__DOT__D;
            }
        }
        if ((1U & (IData)(vlTOPp->md5__DOT__next_state))) {
            vlTOPp->md5__DOT__msg[0U] = 0U;
            vlTOPp->md5__DOT__msg[1U] = 0U;
            vlTOPp->md5__DOT__msg[2U] = 0U;
            vlTOPp->md5__DOT__msg[3U] = 0U;
            vlTOPp->md5__DOT__msg[4U] = 0U;
            vlTOPp->md5__DOT__msg[5U] = 0U;
            vlTOPp->md5__DOT__msg[6U] = 0U;
            vlTOPp->md5__DOT__msg[7U] = 0U;
            vlTOPp->md5__DOT__msg[8U] = 0U;
            vlTOPp->md5__DOT__msg[9U] = 0U;
            vlTOPp->md5__DOT__msg[0xaU] = 0U;
            vlTOPp->md5__DOT__msg[0xbU] = 0U;
            vlTOPp->md5__DOT__msg[0xcU] = 0U;
            vlTOPp->md5__DOT__msg[0xdU] = 0U;
            vlTOPp->md5__DOT__msg[0xeU] = 0U;
            vlTOPp->md5__DOT__msg[0xfU] = 0U;
        } else {
            if ((1U & (((IData)(vlTOPp->md5__DOT__next_state) 
                        >> 1U) & (IData)(vlTOPp->md5__DOT__state)))) {
                vlTOPp->md5__DOT__msg[0U] = vlTOPp->in[0U];
                vlTOPp->md5__DOT__msg[1U] = vlTOPp->in[1U];
                vlTOPp->md5__DOT__msg[2U] = vlTOPp->in[2U];
                vlTOPp->md5__DOT__msg[3U] = vlTOPp->in[3U];
                vlTOPp->md5__DOT__msg[4U] = vlTOPp->in[0U];
                vlTOPp->md5__DOT__msg[5U] = vlTOPp->in[1U];
                vlTOPp->md5__DOT__msg[6U] = vlTOPp->in[2U];
                vlTOPp->md5__DOT__msg[7U] = vlTOPp->in[3U];
                vlTOPp->md5__DOT__msg[8U] = vlTOPp->in[0U];
                vlTOPp->md5__DOT__msg[9U] = vlTOPp->in[1U];
                vlTOPp->md5__DOT__msg[0xaU] = vlTOPp->in[2U];
                vlTOPp->md5__DOT__msg[0xbU] = vlTOPp->in[3U];
                vlTOPp->md5__DOT__msg[0xcU] = vlTOPp->in[0U];
                vlTOPp->md5__DOT__msg[0xdU] = vlTOPp->in[1U];
                vlTOPp->md5__DOT__msg[0xeU] = vlTOPp->in[2U];
                vlTOPp->md5__DOT__msg[0xfU] = vlTOPp->in[3U];
            }
        }
    }
    vlTOPp->md5__DOT__phase = __Vdly__md5__DOT__phase;
    vlTOPp->out_valid = vlTOPp->md5__DOT__out_r;
    vlTOPp->md5__DOT__A = ((IData)(vlTOPp->rst) ? 0x67452301U
                            : ((1U & (IData)(vlTOPp->md5__DOT__next_state))
                                ? 0x67452301U : vlTOPp->md5__DOT__next_A));
    vlTOPp->md5__DOT__B = ((IData)(vlTOPp->rst) ? 0xefcdab89U
                            : ((1U & (IData)(vlTOPp->md5__DOT__next_state))
                                ? 0xefcdab89U : vlTOPp->md5__DOT__next_B));
    vlTOPp->md5__DOT__C = ((IData)(vlTOPp->rst) ? 0x98badcfeU
                            : ((1U & (IData)(vlTOPp->md5__DOT__next_state))
                                ? 0x98badcfeU : vlTOPp->md5__DOT__next_C));
    vlTOPp->md5__DOT__D = ((IData)(vlTOPp->rst) ? 0x10325476U
                            : ((1U & (IData)(vlTOPp->md5__DOT__next_state))
                                ? 0x10325476U : vlTOPp->md5__DOT__next_D));
    vlTOPp->md5__DOT__state = ((IData)(vlTOPp->rst)
                                ? 1U : (IData)(vlTOPp->md5__DOT__next_state));
    vlTOPp->out[0U] = vlTOPp->md5__DOT__D;
    vlTOPp->out[1U] = vlTOPp->md5__DOT__C;
    vlTOPp->out[2U] = (IData)((((QData)((IData)(vlTOPp->md5__DOT__A)) 
                                << 0x20U) | (QData)((IData)(vlTOPp->md5__DOT__B))));
    vlTOPp->out[3U] = (IData)(((((QData)((IData)(vlTOPp->md5__DOT__A)) 
                                 << 0x20U) | (QData)((IData)(vlTOPp->md5__DOT__B))) 
                               >> 0x20U));
    vlTOPp->ready = (1U & (IData)(vlTOPp->md5__DOT__state));
    vlTOPp->md5__DOT__r_s = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [vlTOPp->md5__DOT__phase]);
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [(0x10U | (IData)(vlTOPp->md5__DOT__phase))]);
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [(0x20U | (IData)(vlTOPp->md5__DOT__phase))]);
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [(0x30U | (IData)(vlTOPp->md5__DOT__phase))]);
    }
    vlTOPp->md5__DOT__r_r = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 0U;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 1U;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 2U;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 3U;
    }
    vlTOPp->md5__DOT__r_m = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   << 5U)))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & (IData)(vlTOPp->md5__DOT__phase)))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 5U))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & (IData)(vlTOPp->md5__DOT__phase))] 
                                    >> (0x1fU & ((IData)(vlTOPp->md5__DOT__phase) 
                                                 << 5U))));
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & (
                                                   (0x100U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 8U)) 
                                                   | (0xe0U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 4U)))))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & ((8U 
                                                   & ((IData)(vlTOPp->md5__DOT__phase) 
                                                      << 3U)) 
                                                  | (7U 
                                                     & ((IData)(vlTOPp->md5__DOT__phase) 
                                                        >> 1U)))))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((0x100U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 8U)) 
                                                     | (0xe0U 
                                                        & ((IData)(vlTOPp->md5__DOT__phase) 
                                                           << 4U))))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & ((8U & 
                                              ((IData)(vlTOPp->md5__DOT__phase) 
                                               << 3U)) 
                                             | (7U 
                                                & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   >> 1U))))] 
                                    >> (0x1fU & ((0x100U 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 8U)) 
                                                 | (0xe0U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 4U))))));
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & (
                                                   (0x180U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 7U)) 
                                                   | (0x60U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 3U)))))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & ((0xcU 
                                                   & ((IData)(vlTOPp->md5__DOT__phase) 
                                                      << 2U)) 
                                                  | (3U 
                                                     & ((IData)(vlTOPp->md5__DOT__phase) 
                                                        >> 2U)))))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((0x180U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 7U)) 
                                                     | (0x60U 
                                                        & ((IData)(vlTOPp->md5__DOT__phase) 
                                                           << 3U))))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & ((0xcU 
                                              & ((IData)(vlTOPp->md5__DOT__phase) 
                                                 << 2U)) 
                                             | (3U 
                                                & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   >> 2U))))] 
                                    >> (0x1fU & ((0x180U 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 7U)) 
                                                 | (0x60U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 3U))))));
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & (
                                                   (0x1c0U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 6U)) 
                                                   | (0x20U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 2U)))))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & ((0xeU 
                                                   & ((IData)(vlTOPp->md5__DOT__phase) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & ((IData)(vlTOPp->md5__DOT__phase) 
                                                        >> 3U)))))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((0x1c0U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 6U)) 
                                                     | (0x20U 
                                                        & ((IData)(vlTOPp->md5__DOT__phase) 
                                                           << 2U))))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & ((0xeU 
                                              & ((IData)(vlTOPp->md5__DOT__phase) 
                                                 << 1U)) 
                                             | (1U 
                                                & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   >> 3U))))] 
                                    >> (0x1fU & ((0x1c0U 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 6U)) 
                                                 | (0x20U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 2U))))));
    }
    vlTOPp->md5__DOT__r_t = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [vlTOPp->md5__DOT__phase];
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [(0x10U | (IData)(vlTOPp->md5__DOT__phase))];
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [(0x20U | (IData)(vlTOPp->md5__DOT__phase))];
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [(0x30U | (IData)(vlTOPp->md5__DOT__phase))];
    }
    vlTOPp->md5__DOT__r_a = 0U;
    vlTOPp->md5__DOT__cya = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__A;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__D;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__C;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__B;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    vlTOPp->md5__DOT__r_c = 0U;
    vlTOPp->md5__DOT__cyc = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__C;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__B;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__A;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__D;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    vlTOPp->md5__DOT__r_d = 0U;
    vlTOPp->md5__DOT__cyd = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__D;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__C;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__B;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__A;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    vlTOPp->md5__DOT__r_b = 0U;
    vlTOPp->md5__DOT__cyb = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__B;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__A;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__D;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__C;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    vlTOPp->md5__DOT__round__DOT__FGHI[0U] = ((vlTOPp->md5__DOT__r_b 
                                               & vlTOPp->md5__DOT__r_c) 
                                              | ((~ vlTOPp->md5__DOT__r_b) 
                                                 & vlTOPp->md5__DOT__r_d));
    vlTOPp->md5__DOT__round__DOT__FGHI[1U] = ((vlTOPp->md5__DOT__r_b 
                                               & vlTOPp->md5__DOT__r_d) 
                                              | (vlTOPp->md5__DOT__r_c 
                                                 & (~ vlTOPp->md5__DOT__r_d)));
    vlTOPp->md5__DOT__round__DOT__FGHI[2U] = ((vlTOPp->md5__DOT__r_b 
                                               ^ vlTOPp->md5__DOT__r_c) 
                                              ^ vlTOPp->md5__DOT__r_d);
    vlTOPp->md5__DOT__round__DOT__FGHI[3U] = (vlTOPp->md5__DOT__r_c 
                                              ^ (vlTOPp->md5__DOT__r_b 
                                                 | (~ vlTOPp->md5__DOT__r_d)));
    if ((0U == (IData)(vlTOPp->md5__DOT__r_r))) {
        vlTOPp->md5__DOT__round__DOT__res = (((vlTOPp->md5__DOT__r_a 
                                               + vlTOPp->md5__DOT__round__DOT__FGHI[0U]) 
                                              + vlTOPp->md5__DOT__r_m) 
                                             + vlTOPp->md5__DOT__r_t);
    } else {
        if ((1U == (IData)(vlTOPp->md5__DOT__r_r))) {
            vlTOPp->md5__DOT__round__DOT__res = (((vlTOPp->md5__DOT__r_a 
                                                   + 
                                                   vlTOPp->md5__DOT__round__DOT__FGHI[1U]) 
                                                  + vlTOPp->md5__DOT__r_m) 
                                                 + vlTOPp->md5__DOT__r_t);
        } else {
            if ((2U == (IData)(vlTOPp->md5__DOT__r_r))) {
                vlTOPp->md5__DOT__round__DOT__res = 
                    (((vlTOPp->md5__DOT__r_a + vlTOPp->md5__DOT__round__DOT__FGHI[2U]) 
                      + vlTOPp->md5__DOT__r_m) + vlTOPp->md5__DOT__r_t);
            } else {
                if ((3U == (IData)(vlTOPp->md5__DOT__r_r))) {
                    vlTOPp->md5__DOT__round__DOT__res 
                        = (((vlTOPp->md5__DOT__r_a 
                             + vlTOPp->md5__DOT__round__DOT__FGHI[3U]) 
                            + vlTOPp->md5__DOT__r_m) 
                           + vlTOPp->md5__DOT__r_t);
                }
            }
        }
    }
    vlTOPp->md5__DOT__r_out = (vlTOPp->md5__DOT__r_b 
                               + ((vlTOPp->md5__DOT__round__DOT__res 
                                   << (IData)(vlTOPp->md5__DOT__r_s)) 
                                  | ((0x1fU >= ((IData)(0x20U) 
                                                - (IData)(vlTOPp->md5__DOT__r_s)))
                                      ? (vlTOPp->md5__DOT__round__DOT__res 
                                         >> ((IData)(0x20U) 
                                             - (IData)(vlTOPp->md5__DOT__r_s)))
                                      : 0U)));
    vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__B;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_B = (vlTOPp->md5__DOT__BB 
                                    + vlTOPp->md5__DOT__B);
    }
    vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__A;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_A = (vlTOPp->md5__DOT__AA 
                                    + vlTOPp->md5__DOT__A);
    }
    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__C;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_C = (vlTOPp->md5__DOT__CC 
                                    + vlTOPp->md5__DOT__C);
    }
    vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__D;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_D = (vlTOPp->md5__DOT__DD 
                                    + vlTOPp->md5__DOT__D);
    }
}

void Vmd5::_settle__TOP__2(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_settle__TOP__2\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_valid = vlTOPp->md5__DOT__out_r;
    vlTOPp->ready = (1U & (IData)(vlTOPp->md5__DOT__state));
    vlTOPp->md5__DOT__next_state = vlTOPp->md5__DOT__state;
    if ((1U & (IData)(vlTOPp->md5__DOT__state))) {
        if (vlTOPp->in_valid) {
            vlTOPp->md5__DOT__next_state = 2U;
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 4U;
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 8U;
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 0x10U;
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 0x20U;
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_state = 0x40U;
    }
    if ((0x40U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_state = 1U;
    }
    vlTOPp->out[0U] = vlTOPp->md5__DOT__D;
    vlTOPp->out[1U] = vlTOPp->md5__DOT__C;
    vlTOPp->out[2U] = (IData)((((QData)((IData)(vlTOPp->md5__DOT__A)) 
                                << 0x20U) | (QData)((IData)(vlTOPp->md5__DOT__B))));
    vlTOPp->out[3U] = (IData)(((((QData)((IData)(vlTOPp->md5__DOT__A)) 
                                 << 0x20U) | (QData)((IData)(vlTOPp->md5__DOT__B))) 
                               >> 0x20U));
    vlTOPp->md5__DOT__r_r = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 0U;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 1U;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 2U;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_r = 3U;
    }
    vlTOPp->md5__DOT__r_m = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   << 5U)))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & (IData)(vlTOPp->md5__DOT__phase)))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 5U))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & (IData)(vlTOPp->md5__DOT__phase))] 
                                    >> (0x1fU & ((IData)(vlTOPp->md5__DOT__phase) 
                                                 << 5U))));
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & (
                                                   (0x100U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 8U)) 
                                                   | (0xe0U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 4U)))))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & ((8U 
                                                   & ((IData)(vlTOPp->md5__DOT__phase) 
                                                      << 3U)) 
                                                  | (7U 
                                                     & ((IData)(vlTOPp->md5__DOT__phase) 
                                                        >> 1U)))))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((0x100U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 8U)) 
                                                     | (0xe0U 
                                                        & ((IData)(vlTOPp->md5__DOT__phase) 
                                                           << 4U))))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & ((8U & 
                                              ((IData)(vlTOPp->md5__DOT__phase) 
                                               << 3U)) 
                                             | (7U 
                                                & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   >> 1U))))] 
                                    >> (0x1fU & ((0x100U 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 8U)) 
                                                 | (0xe0U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 4U))))));
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & (
                                                   (0x180U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 7U)) 
                                                   | (0x60U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 3U)))))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & ((0xcU 
                                                   & ((IData)(vlTOPp->md5__DOT__phase) 
                                                      << 2U)) 
                                                  | (3U 
                                                     & ((IData)(vlTOPp->md5__DOT__phase) 
                                                        >> 2U)))))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((0x180U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 7U)) 
                                                     | (0x60U 
                                                        & ((IData)(vlTOPp->md5__DOT__phase) 
                                                           << 3U))))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & ((0xcU 
                                              & ((IData)(vlTOPp->md5__DOT__phase) 
                                                 << 2U)) 
                                             | (3U 
                                                & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   >> 2U))))] 
                                    >> (0x1fU & ((0x180U 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 7U)) 
                                                 | (0x60U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 3U))))));
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_m = (((0U == (0x1fU & (
                                                   (0x1c0U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 6U)) 
                                                   | (0x20U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 2U)))))
                                   ? 0U : (vlTOPp->md5__DOT__msg[
                                           ((IData)(1U) 
                                            + (0xfU 
                                               & ((0xeU 
                                                   & ((IData)(vlTOPp->md5__DOT__phase) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & ((IData)(vlTOPp->md5__DOT__phase) 
                                                        >> 3U)))))] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((0x1c0U 
                                                      & ((IData)(vlTOPp->md5__DOT__phase) 
                                                         << 6U)) 
                                                     | (0x20U 
                                                        & ((IData)(vlTOPp->md5__DOT__phase) 
                                                           << 2U))))))) 
                                 | (vlTOPp->md5__DOT__msg[
                                    (0xfU & ((0xeU 
                                              & ((IData)(vlTOPp->md5__DOT__phase) 
                                                 << 1U)) 
                                             | (1U 
                                                & ((IData)(vlTOPp->md5__DOT__phase) 
                                                   >> 3U))))] 
                                    >> (0x1fU & ((0x1c0U 
                                                  & ((IData)(vlTOPp->md5__DOT__phase) 
                                                     << 6U)) 
                                                 | (0x20U 
                                                    & ((IData)(vlTOPp->md5__DOT__phase) 
                                                       << 2U))))));
    }
    vlTOPp->md5__DOT__r_a = 0U;
    vlTOPp->md5__DOT__cya = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__A;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__D;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__C;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cya = vlTOPp->md5__DOT__B;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_a = vlTOPp->md5__DOT__cya;
    }
    vlTOPp->md5__DOT__r_c = 0U;
    vlTOPp->md5__DOT__cyc = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__C;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__B;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__A;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cyc = vlTOPp->md5__DOT__D;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_c = vlTOPp->md5__DOT__cyc;
    }
    vlTOPp->md5__DOT__r_d = 0U;
    vlTOPp->md5__DOT__cyd = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__D;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__C;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__B;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cyd = vlTOPp->md5__DOT__A;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_d = vlTOPp->md5__DOT__cyd;
    }
    vlTOPp->md5__DOT__r_b = 0U;
    vlTOPp->md5__DOT__cyb = 0U;
    if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
        vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__B;
    } else {
        if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__A;
        } else {
            if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__D;
            } else {
                if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__cyb = vlTOPp->md5__DOT__C;
                }
            }
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_b = vlTOPp->md5__DOT__cyb;
    }
    vlTOPp->md5__DOT__r_s = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [vlTOPp->md5__DOT__phase]);
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [(0x10U | (IData)(vlTOPp->md5__DOT__phase))]);
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [(0x20U | (IData)(vlTOPp->md5__DOT__phase))]);
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_s = (0x1fU & vlSymsp->TOP____024unit.S
                                 [(0x30U | (IData)(vlTOPp->md5__DOT__phase))]);
    }
    vlTOPp->md5__DOT__r_t = 0U;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [vlTOPp->md5__DOT__phase];
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [(0x10U | (IData)(vlTOPp->md5__DOT__phase))];
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [(0x20U | (IData)(vlTOPp->md5__DOT__phase))];
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__r_t = vlSymsp->TOP____024unit.K
            [(0x30U | (IData)(vlTOPp->md5__DOT__phase))];
    }
    vlTOPp->md5__DOT__round__DOT__FGHI[0U] = ((vlTOPp->md5__DOT__r_b 
                                               & vlTOPp->md5__DOT__r_c) 
                                              | ((~ vlTOPp->md5__DOT__r_b) 
                                                 & vlTOPp->md5__DOT__r_d));
    vlTOPp->md5__DOT__round__DOT__FGHI[1U] = ((vlTOPp->md5__DOT__r_b 
                                               & vlTOPp->md5__DOT__r_d) 
                                              | (vlTOPp->md5__DOT__r_c 
                                                 & (~ vlTOPp->md5__DOT__r_d)));
    vlTOPp->md5__DOT__round__DOT__FGHI[2U] = ((vlTOPp->md5__DOT__r_b 
                                               ^ vlTOPp->md5__DOT__r_c) 
                                              ^ vlTOPp->md5__DOT__r_d);
    vlTOPp->md5__DOT__round__DOT__FGHI[3U] = (vlTOPp->md5__DOT__r_c 
                                              ^ (vlTOPp->md5__DOT__r_b 
                                                 | (~ vlTOPp->md5__DOT__r_d)));
    if ((0U == (IData)(vlTOPp->md5__DOT__r_r))) {
        vlTOPp->md5__DOT__round__DOT__res = (((vlTOPp->md5__DOT__r_a 
                                               + vlTOPp->md5__DOT__round__DOT__FGHI[0U]) 
                                              + vlTOPp->md5__DOT__r_m) 
                                             + vlTOPp->md5__DOT__r_t);
    } else {
        if ((1U == (IData)(vlTOPp->md5__DOT__r_r))) {
            vlTOPp->md5__DOT__round__DOT__res = (((vlTOPp->md5__DOT__r_a 
                                                   + 
                                                   vlTOPp->md5__DOT__round__DOT__FGHI[1U]) 
                                                  + vlTOPp->md5__DOT__r_m) 
                                                 + vlTOPp->md5__DOT__r_t);
        } else {
            if ((2U == (IData)(vlTOPp->md5__DOT__r_r))) {
                vlTOPp->md5__DOT__round__DOT__res = 
                    (((vlTOPp->md5__DOT__r_a + vlTOPp->md5__DOT__round__DOT__FGHI[2U]) 
                      + vlTOPp->md5__DOT__r_m) + vlTOPp->md5__DOT__r_t);
            } else {
                if ((3U == (IData)(vlTOPp->md5__DOT__r_r))) {
                    vlTOPp->md5__DOT__round__DOT__res 
                        = (((vlTOPp->md5__DOT__r_a 
                             + vlTOPp->md5__DOT__round__DOT__FGHI[3U]) 
                            + vlTOPp->md5__DOT__r_m) 
                           + vlTOPp->md5__DOT__r_t);
                }
            }
        }
    }
    vlTOPp->md5__DOT__r_out = (vlTOPp->md5__DOT__r_b 
                               + ((vlTOPp->md5__DOT__round__DOT__res 
                                   << (IData)(vlTOPp->md5__DOT__r_s)) 
                                  | ((0x1fU >= ((IData)(0x20U) 
                                                - (IData)(vlTOPp->md5__DOT__r_s)))
                                      ? (vlTOPp->md5__DOT__round__DOT__res 
                                         >> ((IData)(0x20U) 
                                             - (IData)(vlTOPp->md5__DOT__r_s)))
                                      : 0U)));
    vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__B;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    if ((3U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                        vlTOPp->md5__DOT__next_B = vlTOPp->md5__DOT__r_out;
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_B = (vlTOPp->md5__DOT__BB 
                                    + vlTOPp->md5__DOT__B);
    }
    vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__A;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            vlTOPp->md5__DOT__next_A = vlTOPp->md5__DOT__r_out;
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_A = (vlTOPp->md5__DOT__AA 
                                    + vlTOPp->md5__DOT__A);
    }
    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__C;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                if ((2U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                    vlTOPp->md5__DOT__next_C = vlTOPp->md5__DOT__r_out;
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_C = (vlTOPp->md5__DOT__CC 
                                    + vlTOPp->md5__DOT__C);
    }
    vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__D;
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0U != (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
            if ((1U == (3U & (IData)(vlTOPp->md5__DOT__phase)))) {
                vlTOPp->md5__DOT__next_D = vlTOPp->md5__DOT__r_out;
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_D = (vlTOPp->md5__DOT__DD 
                                    + vlTOPp->md5__DOT__D);
    }
}

VL_INLINE_OPT void Vmd5::_combo__TOP__3(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_combo__TOP__3\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->md5__DOT__next_state = vlTOPp->md5__DOT__state;
    if ((1U & (IData)(vlTOPp->md5__DOT__state))) {
        if (vlTOPp->in_valid) {
            vlTOPp->md5__DOT__next_state = 2U;
        }
    }
    if ((2U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 4U;
        }
    }
    if ((4U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 8U;
        }
    }
    if ((8U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 0x10U;
        }
    }
    if ((0x10U & (IData)(vlTOPp->md5__DOT__state))) {
        if ((0xfU == (IData)(vlTOPp->md5__DOT__phase))) {
            vlTOPp->md5__DOT__next_state = 0x20U;
        }
    }
    if ((0x20U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_state = 0x40U;
    }
    if ((0x40U & (IData)(vlTOPp->md5__DOT__state))) {
        vlTOPp->md5__DOT__next_state = 1U;
    }
}

void Vmd5::_eval(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_eval\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmd5::_eval_initial(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_eval_initial\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP____024unit._initial__TOP____024unit__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmd5::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::final\n"); );
    // Variables
    Vmd5__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmd5::_eval_settle(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_eval_settle\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vmd5::_change_request(Vmd5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_change_request\n"); );
    Vmd5* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmd5::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((in_valid & 0xfeU))) {
        Verilated::overWidthError("in_valid");}
}
#endif  // VL_DEBUG

void Vmd5::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmd5::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, in);
    in_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, out);
    out_valid = VL_RAND_RESET_I(1);
    ready = VL_RAND_RESET_I(1);
    md5__DOT__A = VL_RAND_RESET_I(32);
    md5__DOT__B = VL_RAND_RESET_I(32);
    md5__DOT__C = VL_RAND_RESET_I(32);
    md5__DOT__D = VL_RAND_RESET_I(32);
    md5__DOT__AA = VL_RAND_RESET_I(32);
    md5__DOT__BB = VL_RAND_RESET_I(32);
    md5__DOT__CC = VL_RAND_RESET_I(32);
    md5__DOT__DD = VL_RAND_RESET_I(32);
    md5__DOT__next_A = VL_RAND_RESET_I(32);
    md5__DOT__next_B = VL_RAND_RESET_I(32);
    md5__DOT__next_C = VL_RAND_RESET_I(32);
    md5__DOT__next_D = VL_RAND_RESET_I(32);
    md5__DOT__phase = VL_RAND_RESET_I(4);
    md5__DOT__state = VL_RAND_RESET_I(8);
    md5__DOT__next_state = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(512, md5__DOT__msg);
    md5__DOT__out_r = VL_RAND_RESET_I(1);
    md5__DOT__r_a = VL_RAND_RESET_I(32);
    md5__DOT__r_b = VL_RAND_RESET_I(32);
    md5__DOT__r_c = VL_RAND_RESET_I(32);
    md5__DOT__r_d = VL_RAND_RESET_I(32);
    md5__DOT__r_m = VL_RAND_RESET_I(32);
    md5__DOT__r_s = VL_RAND_RESET_I(5);
    md5__DOT__r_t = VL_RAND_RESET_I(32);
    md5__DOT__r_r = VL_RAND_RESET_I(2);
    md5__DOT__r_out = VL_RAND_RESET_I(32);
    md5__DOT__cya = VL_RAND_RESET_I(32);
    md5__DOT__cyb = VL_RAND_RESET_I(32);
    md5__DOT__cyc = VL_RAND_RESET_I(32);
    md5__DOT__cyd = VL_RAND_RESET_I(32);
    md5__DOT__round__DOT__res = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, md5__DOT__round__DOT__FGHI);
}
