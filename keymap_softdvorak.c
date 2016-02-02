#include "keymap_common.h"

// This layout is designed to be used on machines where the OS is
// already set to a dvorak layout.

// You probably want keymap_multidvorak.c instead.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,     \
         // KC_MINS and KC_LBRC are inverse-dvorakized
         KC_SPC, KC_FN0, KC_QUOT, KC_LBRC, KC_ENT),                     \
  /* 1: fn with undvorak-ized punctuation */
  KEYMAP(SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_MINS), SHIFT(KC_EQUAL), SHIFT(KC_BSLS), \
         KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8), \
         SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9), SHIFT(KC_0), KC_GRAVE, \
         KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_RBRC), \
         SHIFT(KC_5), SHIFT(KC_6), KC_MINS, KC_EQUAL, SHIFT(KC_GRAVE), \
         SHIFT(KC_7), KC_1, KC_2, KC_3, KC_BSLS,                       \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, KC_FN4, KC_BSPC, KC_LCTL, KC_LALT, \
         KC_SPC, KC_FN0, KC_E, KC_0, KC_RBRC), \
  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_FN3, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         KC_NO, KC_LSFT, KC_LGUI, KC_FN4, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENT)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
