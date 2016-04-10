#include "keymap_common.h"

/* This layout implements dvorak fully in the firmware. It will work
   on machines where the OS is set to use QWERTY, but not if the OS is
   already set for dvorak. For that use case, see keymap_multidvorak.c. */

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(QUOT, COMM, DOT, P, Y, F, G, C, R, L, \
         A, O, E, U, I, D, H, T, N, S, \
         SCLN, Q, J, K, X, B, M, W, V, Z, \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, LALT,     \
         SPC, FN0, MINS, SLSH, ENT),                     \
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER,                                     \
  /* 2: arrows and function keys */
  LAYER_TWO, \
  LAYER_THREE 
};
