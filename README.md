# Atreus keyboard firmware

The [Atreus](http://atreus.technomancy.us) is a 40% column-staggered
ergo keyboard.

The TMK firmware is more featureful than the default
[Atreus firmware](https://github.com/technomancy/atreus-firmware),
however it is much more complex, doesn't work with low-voltage
laptops.

There is also a [firmware](https://github.com/technomancy/menelaus)
implemented in [Microscheme](http://microscheme.org), but that is intended
primarily for educational purposes.

## Prerequisites

Install
[gcc-avr](http://www.nongnu.org/avr-libc/user-manual/install\_tools.html)
and [avrdude](http://www.nongnu.org/avrdude/).

On Debian-based systems:

    $ sudo apt-get install avrdude gcc-avr avr-libc

On Mac OS X with Homebrew:

    $ brew tap larsimmisch/avr
    $ brew install avr-libc
    $ brew install avrdude

## Uploading

Running `make upload KEYMAP=qwerty USB=/dev/ttyACM0` will compile the
firmware with the selected layout and begin the upload process. The
`USB` option should be the path of the USB serial port opened by the
bootloader. On Linux-based systems it's usually `/dev/ttyACM0` while
on Macs it's usually `/dev/cu.usbmodem1421`. For the upload process to
complete you'll need to get the controller into its bootloader. If
you've already got the firmware loaded on the controller, you should
have a key bound for this; typically this is activated by jumping to
layer 2 (`fn`+`ESC`) and then hitting `enter`.

If your board has never before had
[the firmware uploaded](http://www.pololu.com/docs/0J61/5.3), you will
have to *hard reset* by connecting the `RST` pin to ground twice in
under a second to jump to the bootloader. (This requires removing the
back panel and touching them together with a piece of wire or a
trimmed diode leg.)  For older models, `RST` and ground are exposed
with hookup wire poking out of the bottom of the board, but for newer
models they are the sixth and seventh pin down on the right-side row
of microcontroller pins.

For first-time uploads, hit reset before running `make upload`.
You'll know if the board is in the bootloader because the LED will
pulse. If you wait too long (8 seconds) in the bootloader without
uploading new firmware, it will go back to normal operation.

If you are hacking the lower-level logic of the firmware, the reset
key might not be reachable (due to bugs in layer functionality, etc)
and you will have to initiate a manual reset as per above with the `RST` pin.

Sometimes it can be tricky to get the timing right with the hard
reset; it can take a few attempts when you are first uploading the
firmware to a fresh board.

You can identify the USB device like so:

```
$ ls /dev > /tmp/dev-off # run this while the device is unplugged
$ ls /dev > /tmp/dev-on # run this while the device is in bootloader mode
$ diff /tmp/dev-off /tmp/dev-on # this will show the device path
```

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
