/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_code.h"
#include "action_layer.h"
#include "action_macro.h"
#include "action_util.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

extern const uint16_t actionmaps[][MATRIX_ROWS][MATRIX_COLS];

#define KEYMAP_PCBDOWN( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
) {                                                                     \
  { AC_##K09, AC_##K08, AC_##K07, AC_##K06, AC_##K05, KC_NO, AC_##K04, AC_##K03, AC_##K02, AC_##K01, AC_##K00 }, \
  { AC_##K19, AC_##K18, AC_##K17, AC_##K16, AC_##K15, KC_NO, AC_##K14, AC_##K13, AC_##K12, AC_##K11, AC_##K10 }, \
  { AC_##K29, AC_##K28, AC_##K27, AC_##K26, AC_##K25, AC_##K35,   AC_##K24, AC_##K23, AC_##K22, AC_##K21, AC_##K20 }, \
  { AC_##K3A, AC_##K39, AC_##K38, AC_##K37, AC_##K36, AC_##K34,   AC_##K33, AC_##K32, AC_##K31, AC_##K30, AC_##K2A } \
}

#define KEYMAP_PCBUP( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
) {                                                                     \
  { AC_##K00, AC_##K01, AC_##K02, AC_##K03, AC_##K04, KC_NO, AC_##K05, AC_##K06, AC_##K07, AC_##K08, AC_##K09 }, \
  { AC_##K10, AC_##K11, AC_##K12, AC_##K13, AC_##K14, KC_NO, AC_##K15, AC_##K16, AC_##K17, AC_##K18, AC_##K19 }, \
  { AC_##K20, AC_##K21, AC_##K22, AC_##K23, AC_##K24, AC_##K34,   AC_##K25, AC_##K26, AC_##K27, AC_##K28, AC_##K29 }, \
  { AC_##K2A, AC_##K30, AC_##K31, AC_##K32, AC_##K33, AC_##K35,   AC_##K36, AC_##K37, AC_##K38, AC_##K39, AC_##K3A }      \
}

#ifdef PCBDOWN
#define KEYMAP KEYMAP_PCBDOWN
#else
#define KEYMAP KEYMAP_PCBUP
#endif

#define AC_SH(key)    ACTION_MODS_KEY(MOD_LSFT, AC_##key)
#define AC_CTRL(key)  ACTION_MODS_KEY(MOD_LCTL, AC_##key)
#define AC_ALT(key)   ACTION_MODS_KEY(MOD_LALT, AC_##key)
#define AC_GUI(key)   ACTION_MODS_KEY(MOD_LGUI, AC_##key)
#define AC_LM1        ACTION_LAYER_MOMENTARY(1)
#define AC_LM2        ACTION_LAYER_MOMENTARY(2)
#define AC_LM3        ACTION_LAYER_MOMENTARY(3)
#define AC_ON(layer)  ACTION_LAYER_ON((layer), 1)
#define AC_OFF(layer) ACTION_LAYER_OFF((layer), 1)
#define AC_BOOT       ACTION_FUNCTION(BOOTLOADER)

/* 
 *  !    @      {     }     |       ||       _     7     8     9    *
 *  #    $      (     )     `       ||       -     4     5     6    +
 *  %    ^      [     ]     ~       ||       &     1     2     3    \
 * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
#define FN_LAYER   KEYMAP(SH(1), SH(2)  , SH(LBRC), SH(RBRC) , SH(BSLS)  /*| |*/  , SH(MINS), 7  , 8  , 9, SH(8),      \
                          SH(3), SH(4)  , SH(9)   , SH(0)    , GRAVE     /*| |*/  , MINS    , 4  , 5  , 6, SH(EQUAL),  \
                          SH(5), SH(6)  , LBRC    , RBRC     , SH(GRAVE) /*| |*/  , SH(7)   , 1  , 2  , 3, BSLS,          \
                          ON(2), SH(INS), LGUI    , LSFT     , BSPC , LCTL,  LALT , SPC     , LM1, DOT, 0, EQUAL)

/*
 *  !    @     up     {    }        ||     pgup    7     8     9    *
 *  #  left   down  right  $        ||     pgdn    4     5     6    +
 *  [    ]      (     )    &        ||       `     1     2     3    \
 * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
#define FN_ARROW_LAYER   KEYMAP(SH(1), SH(2)  , UP    , SH(LBRC), SH(RBRC), /*| |*/   PGUP , 7  , 8  , 9, SH(8), \
                                SH(3), LEFT   , DOWN  , RIGHT   , SH(4),    /*| |*/   PGDN , 4  , 5  , 6, SH(EQUAL), \
                                LBRC , RBRC   , SH(9) , SH(0)   , SH(7),    /*| |*/   GRAVE, 1  , 2  , 3, BSLS,    \
                                ON(2), SH(INS), LGUI  , LSFT    , BSPC,   LCTL, LALT, SPC  , LM1, DOT, 0, EQUAL)

/*
 * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
 *  volup prev  play next  reset      ||             F1    F2    F3   F12
 *  voldn mute super shift bksp ctrl  || alt space   L0  prtsc scroll pause
 */
#define LAYER_TWO KEYMAP(INS , HOME, UP  , END  , PGUP,   /*| |*/   UP  , F7    , F8     , F9  , F10, \
                         DEL , LEFT, DOWN, RIGHT, PGDN,   /*| |*/   DOWN, F4    , F5     , F6  , F11, \
                         VOLU, MPRV, MPLY, MNXT , BOOT,   /*| |*/   NO  , F1    , F2     , F3  , F12, \
                         VOLD, MUTE, LGUI, LSFT , BSPC, LCTL, LALT, SPC , OFF(2), LM2    , SLCK, PAUSE)


/*
 *  !    @      #     $    %        ||       ^     &     *     (    )
 *  [    ]      -     _             ||             \     |   home  end` 
 * 
 * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
#define LAYER_THREE KEYMAP(SH(1), SH(2)  , SH(3)   , SH(4)   , SH(5),     /* || */   SH(6), SH(7), SH(8)    , SH(9), SH(0), \
                           LBRC , RBRC   , MINS    , SH(MINS), NO   ,     /* || */   NO   , BSLS , SH(BSLS) , HOME , END  , \
                           NO   , NO     , NO      , NO      , NO   ,     /* || */   NO   , NO   , NO       , NO   , NO   , \
                           ON(2), SH(INS), LGUI    , LSFT    , BSPC,    LCTL,  LALT, SPC  , LM1  , LM3      , QUOT, ENT)

enum function_id {
  BOOTLOADER,
};

void bootloader(void);
#endif
