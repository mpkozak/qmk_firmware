# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes    # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no     # Mouse keys
CONSOLE_ENABLE   = no     # Console for debug
COMMAND_ENABLE   = no     # Commands for debug and configuration
NKRO_ENABLE      = no     # Enable N-Key Rollover
EXTRAKEY_ENABLE  = yes
USB_HID_ENABLE   = yes
BACKLIGHT_ENABLE = no
CUSTOM_MATRIX    = yes

VIA_ENABLE = no
AUTOCORRECT_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LTO_ENABLE = yes

SRC = matrix.c adb.c led.c
