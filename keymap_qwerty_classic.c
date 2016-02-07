#include "keymap_common.h"

// This is the "classic" layout, which has the arrow keys on L2
// instead of on the fn layer. However, it has no characters which
// require both shift and fn to be inserted, unlike the newer default.

//    !     @     {     }     |       ||     pgup    7     8     9    *
//    #     $     (     )     `       ||     pgdn    4     5     6    +
//    %     ^     [     ]     ~       ||       &     1     2     3    \
//   L2  insert super shift bksp ctrl || alt space   fn    .     0    =

// L2 has the arrows:

//  insert home    ↑    end  pgup     ||       ↑     F7    F8    F9   F10
//    del   ←      ↓     →   pgdn     ||       ↓     F4    F5    F6   F11
//                                    ||             F1    F2    F3   F12
//              super shift bksp ctrl || alt space   L0             reset

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,     \
         KC_SPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT),                     \
  /* 1: punctuation and numbers */
  FN_LAYER,                                     \
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
