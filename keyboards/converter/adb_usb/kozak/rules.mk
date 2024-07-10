# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes    # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no     # Mouse keys
CONSOLE_ENABLE   = yes    # Console for debug
COMMAND_ENABLE   = yes    # Commands for debug and configuration
NKRO_ENABLE      = yes    # Enable N-Key Rollover
EXTRAKEY_ENABLE  = yes
USB_HID_ENABLE   = yes
BACKLIGHT_ENABLE = no
CUSTOM_MATRIX    = yes

VIA_ENABLE = no
AUTOCORRECT_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
LTO_ENABLE = yes

SRC = matrix.c adb.c led.c
