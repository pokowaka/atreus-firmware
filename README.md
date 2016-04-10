# Atreus keyboard firmware for your MAC

This repository contains firmware (called TMK) loaded into its
controller to make the keyboard function. You can also use it to
customize its layout or behavior. This branch makes use of the latest TMK release.

This build is mainly geared to get the Atreus working on a Mac with a teensy 2 board. If you don't have a mac you are probably better of with [the original](https://github.com/technomancy/tmk_keyboard/).

The main differences are:

- Uses the latest branch of TMK
- Makes use of actions codes, vs. keymaps.
- Media keys enabled in build.
- Updated keymap macros so keymaps are very easy to define.
- The layers are not the same. I've been experimenting with it.

### Installing on Mac OS X

Install [homebrew](http://brew.sh/)

    $ brew tap larsimmisch/avr
    $ brew install avrdude
    $ brew install teensy_loader_cli
    $ brew install avr-libc
    $ cd atreus 
    $ OPT_DEFS=-DTEENSY make teensy KEYMAP=qwerty
I
*note: that you can build colemak by setting KEYMAP=colemak*    
    
### Layout

Copy `keymap_qwerty.c` (or another) into a new file to create your new
layout, and change the `keymaps` array to place the actioncodes you want
in the positions you want.

The `FN_ARROW_LAYER` and `LAYER_TWO` macros correspond to the default
extra layers as defined in `keymap_common.h`; replace them with
`KEYMAP` calls if you want to customize these layers.

For more details see the [TMK documentation](tmk/README.md).

### Compiling

This codebase defaults to targeting the most recent PCB-based design
of the Atreus which uses the A-Star microcontroller, but it can also
work with hand-wired boards that use the Teensy 2.

Uploading to a Teensy 2 can be done with `OPT_DEFS=-DTEENSY make teensy
KEYMAP=qwerty`. 

Getting to the bootloader on the Teensy is simpler;
if you can't do it in software simply press the hardware reset button
once.

