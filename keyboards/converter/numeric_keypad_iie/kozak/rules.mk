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
CUSTOM_MATRIX    = no

VIA_ENABLE					= no
AUTOCORRECT_ENABLE	= no
KEY_OVERRIDE_ENABLE	= no
LTO_ENABLE					= yes

DEFERRED_EXEC_ENABLE	= yes		# allow adb_handler recurring cb
KEYBOARD_SHARED_EP		= yes		# apple fn -> globe workaround

SRC += custom_keycodes.c
