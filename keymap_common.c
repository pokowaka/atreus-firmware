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
#include "keymap_common.h"
#ifndef TEENSY2
#include <avr/wdt.h> // for wdt_enable
#endif

/* translates key to keycode */
uint16_t actionmap_key_to_action(uint8_t layer, key_t key)
{
    return pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return (action_t){ .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]) };
}

// TODO: currently halts the operation but does not enter the bootloader.
// See https://github.com/tmk/tmk_keyboard/issues/179
void bootloader() {
  clear_keyboard();
  print("\n\nJump to bootloader... ");
  _delay_ms(250);
#ifndef TEENSY2
  *(uint16_t *)0x0800 = 0x7777; // these two are a-star-specific
  wdt_enable(WDTO_120MS);
#endif
  bootloader_jump(); // doesn't actually work ATM
  print("not supported.\n");
}
