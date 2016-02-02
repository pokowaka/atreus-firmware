#include "keymap_common.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,     \
         KC_SPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT),                     \
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER,                                     \
  /* 2: arrows and function keys */
  LAYER_TWO
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
