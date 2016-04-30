#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"

/* This keymap allows you to hold down fn+shift to hit keys on L2
   momentarily, rather than switching layers in a "sticky" way.

   NB: There is currently a bug in TMK where it works fine if you
   release shift first, but if you release fn first, the fn key
   remains stuck down until you tap fn again to release it. */

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(Q, W, E, R, T, Y, U, I, O, P,         \
         A, S, D, F, G, H, J, K, L, SCLN,      \
         Z, X, C, V, B, N, M, COMM, DOT, SLSH, \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, LALT, SPC, LM1, MINS, QUOT, ENT),
  /* 1: punctuation and numbers */
  KEYMAP(SH(1), SH(2), SH(LBRC), SH(RBRC), SH(BSLS),  PGUP, 7, 8, 9, SH(8),   \
         SH(3), SH(4), SH(9), SH(0), GRAVE,  PGDN, 4, 5, 6, SH(EQUAL),        \
         SH(5), SH(6), LBRC, RBRC, SH(GRAVE), SH(7), 1, 2, 3, BSLS,           \
         ON(2), SH(INS), LGUI, LM2, BSPC, LCTL, LALT, SPC, LM1, DOT, 0, EQUAL),
  /* 2: arrows and function keys */
  KEYMAP(INS, HOME, UP, END, PGUP, UP, F7, F8, F9, F10, \
  DEL, LEFT, DOWN, RIGHT, PGDN, DOWN, F4, F5, F6, F11, \
  NO, NO, NO, NO, BOOT, NO, F1, F2, F3, F12,             \
  NO, LSFT, LGUI, LM2, BSPC, LCTL, LALT, SPC, OFF(2), NO, NO, ENT)
};
