#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_Y,    KC_U,   KC_I,   KC_O,   KC_P, \
         KC_A,   KC_S,   KC_D,   KC_F,   KC_G,  KC_H,    KC_J,   KC_K,   KC_L,   KC_SCLN, \
         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LALT, KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_SPC, KC_FN0, KC_PGUP, KC_PGDN, KC_ENT),
  /* 1: fn with software-dvorak-ized punctuation */
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, \
         KC_MINS, KC_FN1, KC_FN2, KC_FN3, KC_RBRC, KC_LBRC, KC_MINS, KC_EQL, KC_FN4, KC_FN5, \
         KC_FN6, KC_FN7, KC_FN8, KC_FN9, KC_FN10, KC_TRNS, KC_FN11, KC_FN12, KC_FN13, KC_FN15, \
         KC_FN14, KC_FN19, KC_FN18, KC_TRNS, KC_TRNS, KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_FN16, KC_FN17, KC_BSLS)
};

// looks like all normally-shifted keys need to be listed here
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay

  // row 1
  [1] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL), // +
  [2] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [3] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [4] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // {
  [5] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // }

  // row 2
  [6] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
  [7] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
  [8] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
  [9] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH), // ?
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV), // ~

  // row 3
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // _
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS), // |
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_INSERT), // for pasting

  // other
  [19] = ACTION_FUNCTION(BOOTLOADER),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (id == BOOTLOADER) {
        bootloader();
    }
}
