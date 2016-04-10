#include "keymap_common.h"

// This layout is designed to be used on machines where the OS is
// already set to a dvorak layout.

// You probably want keymap_multidvorak.c instead.

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(Q, W, E, R, T, Y, U, I, O, P,            \
         A, S, D, F, G, H, J, K, L, SCLN,         \
         Z, X, C, V, B, N, M, COMM, DOT, SLSH,    \
         ESC, TAB, LGUI, LSFT, BSPC, LCTL, LALT,  \
         // MINS and LBRC are inverse-dvorakized
         SPC, LM1, QUOT, LBRC, ENT),
  /* 1: fn with undvorak-ized punctuation */
  KEYMAP(SH(1), SH(2), SH(MINS), SH(EQUAL), SH(BSLS), PGUP, 7, 8, 9, SH(8), \
         SH(3), SH(4), SH(9), SH(0), GRAVE, PGDN, 4, 5, 6, SH(RBRC),        \
         SH(5), SH(6), MINS, EQUAL, SH(GRAVE), SH(7), 1, 2, 3, BSLS,        \
         ON(2), SH(INS), LGUI, FN4, BSPC, LCTL, LALT,                       \
         SPC, LM1, E, 0, RBRC), \
  /* 2: arrows and function keys */
  KEYMAP(INS, HOME, UP, END, PGUP, UP, F7, F8, F9, F10, \
         DEL, LEFT, DOWN, RIGHT, PGDN, DOWN, F4, F5, F6, F11, \
         NO, NO, NO, NO, BOOT, NO, F1, F2, F3, F12, \
         NO, LSFT, LGUI, OFF(2), BSPC, LCTL, LALT, SPC, LM1, NO, NO, ENT)
};
