#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP_MIRROR(Q,   W,   E,   R,   T,  Y,    U,   I,   O,   P, \
         A,   S,   D,   F,   G,  H,    J,   K,   L,   SCLN, \
         Z,   X,   C,   V,   B,  LALT, N,   M,  COMM, DOT, SLSH, \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, SPC, FN0, QUOT, LBRC, ENT),
  /* 1: fn with software-dvorak-ized punctuation */
  KEYMAP_MIRROR(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, \
         QUOT, FN1, FN2, FN3, RBRC, E, MINS, EQL, FN4, FN5, \
         FN6, FN7, FN8, FN9, FN10, TRNS, FN11, FN12, FN13, FN15, FN14,  \
         FN19, FN18, TRNS, TRNS, GRV, TRNS, FN20, TRNS, FN16, FN17, BSLS ), \
  /* 2: hardware dvorak */
  KEYMAP_MIRROR(QUOT, COMM, DOT, P, Y, F, G, C, R, L, \
         A, O, E, U, I, D, H, T, N, S, \
         SCLN, Q, J, K, X, TRNS, B, M, W, V, Z,  \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, SPC, FN21, MINS, SLSH, ENT), \
  /* literal punctuation */
  KEYMAP_MIRROR(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, \
         MINS, FN5, FN2, FN3, EQL, DOT, LBRC, RBRC, FN14, FN1, \
         FN6, FN7, FN8, FN9, FN10, TRNS, FN11, FN12, FN13, FN15, FN22,  \
         FN19, FN18, TRNS, TRNS, GRV, TRNS, FN23, TRNS, FN4, FN17, BSLS ) \
};

enum function_id {
  TEENSY_KEY,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;

  if (id == TEENSY_KEY) {
    clear_keyboard();
    print("\n\nJump to bootloader... ");
    _delay_ms(250);
    bootloader_jump(); // should not return
    print("not supported.\n");
  }
}

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
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_INSERT), // for pasting

  // other
  [19] = ACTION_FUNCTION(TEENSY_KEY),

  // hardware dvorak
  [20] = ACTION_LAYER_SET(2, ON_PRESS),
  [21] = ACTION_LAYER_MOMENTARY(3),
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH), // ?
  [23] = ACTION_LAYER_SET(0, ON_PRESS),
};
