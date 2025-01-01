# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes    # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no     # Mouse keys
CONSOLE_ENABLE   = yes    # Console for debug
COMMAND_ENABLE   = yes    # Commands for debug and configuration
NKRO_ENABLE      = no     # Enable N-Key Rollover
EXTRAKEY_ENABLE  = yes
USB_HID_ENABLE   = yes
BACKLIGHT_ENABLE = no
CUSTOM_MATRIX    = yes

VIA_ENABLE					= no
AUTOCORRECT_ENABLE	= yes
KEY_OVERRIDE_ENABLE	= yes
LTO_ENABLE					= yes

KEYBOARD_SHARED_EP  = yes		# apple fn workaround

# Processor frequency
F_CPU = 16000000

SRC = matrix.c m0110.c
