# Atreus keyboard firmware

The [Atreus](https://atreus.technomancy.us) is a small mechanical
column-staggered ergonomic keyboard, usually built from a kit.

## Layout

Only a handful of punctuation marks (and no digits) are available
unshifted, and all the modifiers are on the bottom row:

     q     w     e     r     t       ||       y     u     i     o    p
     a     s     d     f     g       ||       h     j     k     l    ;
     z     x     c     v     b       ||       n     m     ,     .    /
    esc   tab  super shift bksp ctrl || alt space  fn     -     '  enter

The numbers and most of the punctuation are on the fn layer with a
numpad-style arrangement under the right hand:

     !    @     up     {    }        ||     pgup    7     8     9    *
     #  left   down  right  $        ||     pgdn    4     5     6    +
     [    ]      (     )    &        ||       `     1     2     3    \
    L2  insert super shift bksp ctrl || alt space   fn    .     0    =

The `L2` key switches it to the function layer, and tapping `L0` here
brings it back to the first layer.

    insert home   up  end   pgup       ||      up     F7    F8    F9   F10
     del   left  down right pgdn       ||     down    F4    F5    F6   F11
          volup             reset      ||             F1    F2    F3   F12
          voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause

Further alternate layouts are included, such as Colemak and several
Dvorak options. Note that some keys (`%`, `^`, `~`, and `|`) do not
have dedicated keys; you must use `fn` and `shift` together to type
them. The `keymap_qwerty_classic.c` layout has these keys on the fn
layer, but it moves the arrow keys to L2.

## Prerequisites

Install
[gcc-avr](http://www.nongnu.org/avr-libc/user-manual/install\_tools.html)
and [avrdude](http://www.nongnu.org/avrdude/).

On Debian-based systems:

    $ sudo apt-get install avrdude gcc-avr avr-libc

Some linux-based systems will need a udev rule to grant permissions to
the USB device for uploading firmware.

    $ sudo make udev

On Mac OS X with Homebrew:

    $ brew tap larsimmisch/avr
    $ brew install avr-libc
    $ brew install avrdude

If you don't want to use Homebrew you can instead download
[Crosspack for AVR](https://www.obdev.at/products/crosspack/index.html).

## Uploading

Running `make upload KEYMAP=qwerty USB=/dev/ttyACM0` from the
directory containing this readme will compile the firmware with the
selected layout and begin the upload process. The `USB` argument
should be the path of the USB serial port opened by the bootloader. On
Linux-based systems it's usually `/dev/ttyACM0` while on Macs it's
usually `/dev/cu.usbmodem1421`. For the upload process to complete
you'll need to get the controller into its bootloader. If you've
already got the firmware loaded on the controller, you should have a
key bound for this; typically this is activated by jumping to layer 2
(`fn`+`ESC`) and then hitting `B`. If this is your first time
uploading, see "Reset" below.

You can identify the USB device like so:

```
$ ls /dev > /tmp/dev-off # run this while the device is unplugged
$ ls /dev > /tmp/dev-on # run this while the device is in bootloader mode
$ diff /tmp/dev-off /tmp/dev-on # this will show the device path
```

If the upload does not complete, check the permissions on the USB
device and ensure it's writeable by your user. You may need to run
`sudo make udev` on some Linux-based systems to install a udev rule if
another driver mistakenly takes control of the bootloader device.

Sometimes it can be tricky to get the timing right with the hard
reset; it can take a few attempts when you are first uploading the
firmware to a fresh board.

### Windows

Start by installing the A-Star drivers, as
[documented by Pololu](https://www.pololu.com/docs/0J61/6.1). Once the
driver is installed and the device is plugged in, you can determine
the correct port setting by resetting the controller and looking at
the "Ports (COM & LPT)"
[section of the Windows Device Manager](https://a.pololu-files.com/picture/0J5272.500.png);
it should show up as "Pololu A-Star Micro 32U4" if you check within 8
seconds of initiating a reset.

You can install the whole development toolchain using
[WinAVR](http://winavr.sourceforge.net/) to compile using `make upload
[...]` with the instructions above.

However, if the whole compiler setup is too complicated, it's also
possible to download a
[precompiled firmware](http://atreus.technomancy.us/atreus-tmk.hex)
containing the default layout and uploading it with the simpler
[AVRDUDESS](http://blog.zakkemble.co.uk/avrdudess-a-gui-for-avrdude/).

These are the steps to using AVRDUDESS:

* pick "avr109" as the programmer
* select "ATmega32u4" from the MCU section in the upper left
* select the port in the upper left as found in the device manager
* choose the .hex file you downloaded in the "flash" section
* reset the microcontroller so that the LED is gently pulsing
* press "go" under "flash"

### Reset

If you've already got the firmware loaded on the controller, you
should have a key bound to reset; typically this is activated by
jumping to layer 2 (`fn`+`ESC`) and then hitting `B`. (`Enter` on
older versions of the firmware.)

If your board has never before had
[the firmware uploaded](http://www.pololu.com/docs/0J61/5.3), you will
have to *hard reset* by connecting the `RST` pin to ground twice in
under a second to jump to the bootloader. (This requires removing the
back panel.) They are the sixth and seventh pin down on the right-side
row of microcontroller pins. If you idle in the bootloader for 8
seconds without uploading, the controller will exit the bootloader and
return to normal operation.

If you are hacking the lower-level logic of the firmware, the reset
key might not be reachable (due to bugs in layer functionality, etc)
and you will have to initiate a manual reset with the `RST` pin.

## Teensy 2

This codebase defaults to targeting the most recent PCB-based design
of the Atreus which uses the A-Star microcontroller, but it can also
work with hand-wired boards that use the Teensy 2. If you have one
with a Teensy 2 then you will need to install the
[teensy loader](http://www.pjrc.com/teensy/loader_cli.html).

Uploading to a Teensy 2 can be done with `TEENSY=y make teensy
KEYMAP=qwerty`.  Specifying the path to the USB device as per above is
unnecessary. Also getting to the bootloader on the Teensy is simpler;
if you can't do it in software simply press the hardware reset button
once.

## PCB flip

If you assembled your board with the PCB in backwards, never fear!
This is easy to fix in the firmware. Compile with `OPT_DEFS=-DPCBFLIP
make` to use the pinout for the reversed board with the columns
swapped. (This used to be called `SWAPCOLUMNS` in older firmware.)

## Alternatives

The default firmware for the Atreus used to be a
[custom codebase](https://github.com/technomancy/atreus-firmware)
which was a good deal simpler but less featureful. If you are
interested in extending the codebase yourself beyond just creating new
layouts, you may be interested in that instead.

There is also the [Menelaus](https://github.com/technomancy/menelaus)
firmware, which is written in MicroScheme. Note that this is still not
very polished and intended more for educational purposes than anything else.
