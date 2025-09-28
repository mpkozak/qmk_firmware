# Chaff
BACKLIGHT_ENABLE 	= no
VIA_ENABLE				= no

# Unavailable as data-driven
AUTOCORRECT_ENABLE		= yes
KEY_OVERRIDE_ENABLE		= yes
TAP_DANCE_ENABLE    	= yes
DEFERRED_EXEC_ENABLE	= yes		# allow adb_handler recurring cb

SRC = matrix.c adb.c
SRC += adb_handler.c
SRC += adb_led_indicators.c
SRC += custom_keycodes.c
