#include "keymap_common.h"

/* This layout is designed to be used on machines where the OS is */
/* already set to a dvorak layout. It assumes that the dvorak mapping */
/* will be happening on the PC side and sends "un-dvorakized" */
/* keycodes. (So it sends qwerty letters, but specially-shuffled */
/* punctuation.)  This is helpful for laptops where you want to be */
/* able to use the internal keyboard in dvorak without having to */
/* change the OS mappings. */

/* This is an older variant of the multidvorak layout that has
   dual-use modifiers. Ctrl is down-arrow when tapped, alt is
   up-arrow, and shift is enter.*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_FN13, KC_BSPC, KC_FN11, KC_FN12,     \
         // KC_MINS and KC_LBRC are inverse-dvorakized
         KC_SPC, KC_FN0, KC_QUOT, KC_LBRC, KC_ENT),                     \
  /* 1: fn with undvorak-ized punctuation */
  KEYMAP(SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_MINS), SHIFT(KC_EQUAL), SHIFT(KC_BSLS), \
         KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8), \
         SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9), SHIFT(KC_0), KC_GRAVE, \
         KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_RBRC), \
         SHIFT(KC_5), SHIFT(KC_6), KC_MINS, KC_EQUAL, SHIFT(KC_GRAVE), \
         SHIFT(KC_7), KC_1, KC_2, KC_3, KC_BSLS,                       \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, KC_FN4, KC_BSPC, KC_FN11, KC_FN12, \
         KC_SPC, KC_FN0, KC_E, KC_0, KC_RBRC), \
  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_FN5, KC_NO, KC_NO, KC_NO, KC_FN3, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         KC_NO, KC_FN13, KC_LGUI, KC_FN4, KC_BSPC, KC_FN11, KC_FN12, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENT), \
  /* 3: hard dvorak */
  KEYMAP(KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, \
         KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, \
         KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, \
         KC_ESC, KC_TAB, KC_LGUI, KC_FN13, KC_BSPC, KC_FN11, KC_FN12,     \
         KC_SPC, KC_FN6, KC_MINS, KC_QUOT, KC_ENT),                     \

  /* 4: hard dvorak fn */
  KEYMAP(SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_BSLS), \
         KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8),       \
         SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9), SHIFT(KC_0), KC_GRAVE, \
         KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_EQUAL),   \
         SHIFT(KC_5), SHIFT(KC_6), KC_LBRC, KC_RBRC, SHIFT(KC_GRAVE), \
         SHIFT(KC_7), KC_1, KC_2, KC_3, KC_BSLS,       \
         KC_FN7, SHIFT(KC_INS), KC_LGUI, KC_FN13, KC_BSPC, KC_FN11, KC_FN12, \
         KC_SPC, KC_FN6, KC_DOT, KC_0, KC_EQUAL), \

  /* 5: hard dvorak L2 */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         KC_NO, KC_NO, KC_LGUI, KC_FN13, KC_BSPC, KC_FN11, KC_FN12, KC_SPC, KC_FN8, KC_NO, KC_NO, KC_FN10)

};

  const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay

  [5] = ACTION_LAYER_ON(3, 1),  // to hard dvorak
  [6] = ACTION_LAYER_MOMENTARY(4),  // to hard dvorak's fn
  [7] = ACTION_LAYER_ON(5, 1),  // switch to layer 2 hard
  [8] = ACTION_LAYER_OFF(5, 1),  // switch back to layer 0 hard
  [9] = ACTION_LAYER_MOMENTARY(4),  // to Fn overlay
  [10] = ACTION_LAYER_OFF(3, 1),

  [11] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_DOWN),
  [12] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_UP),
  [13] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT),
  };

  void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
  {
  if (id == BOOTLOADER) {
  bootloader();
  }
  }
