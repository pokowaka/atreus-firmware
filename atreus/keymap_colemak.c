#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"

/* This layout implements colemak in the firmware, so you don't have to
   set the OS configuration into colemak layout. Useful if you don't have
   a laptop with an internal keyboard, or if you use other peoples' computers
   a lot. */


/*
 * Q W F P G || J L U Y ;
 * A R S T D || H N E I O
 * Z X C V B || K M , . \
 */
const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: colemak */
  KEYMAP(Q, W, F, P, G, /*||*/ J, L, U, Y, SCLN, \
         A, R, S, T, D, /*||*/ H, N, E, I, O, \
         Z, X, C, V, B, /*||*/ K, M, COMM, DOT, SLSH, \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, LALT, SPC, LM1, LM2, QUOT, ENT),
  /* 1: punctuation and numbers */
  FN_LAYER,
  /* 2: arrows and function keys */
  LAYER_TWO
};
