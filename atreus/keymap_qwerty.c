#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(Q, W, E, R, T, Y, U, I, O, P,            \
         A, S, D, F, G, H, J, K, L, SCLN,         \
         Z, X, C, V, B, N, M, COMM, DOT, SLSH,    \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, LALT,  \
         SPC, LM1, MINS, QUOT, ENT),              \
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER,                                 \
  /* 2: arrows and function keys */
  LAYER_TWO
};
