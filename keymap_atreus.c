#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(Q,   W,   E,   R,   T,  Y,    U,   I,   O,   P, \
         A,   S,   D,   F,   G,  H,    J,   K,   L,   SCLN, \
         Z,   X,   C,   V,   B,  LALT, N,   M,  COMM, DOT, SLSH, \
         ESC, TAB, FN0, LSFT, BSPC, LCTL, SPC, ENT, LGUI, PGUP, PGDN),
  /* 1: fn with software-dvorak-ized punctuation */
  KEYMAP(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, \
         QUOT, FN1, FN2, FN3, RBRC, LBRC, MINS, EQL, FN4, FN5, \
         FN6, FN7, FN8, FN9, FN10, TRNS, FN11, FN12, FN13, FN14, FN15,  \
         TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, GRV, FN16, BSLS, FN17) \
};

// looks like all normally-shifted keys need to be listed here
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay

  // row 1
  [1] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // dvorak +
  [2] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [3] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [4] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // dvorak [
  [5] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL), // dvorak ]

  // row 2
  [6] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
  [7] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
  [8] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
  [9] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // dvorak ?
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),

  // row 3
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT), // dvorak _
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
};
