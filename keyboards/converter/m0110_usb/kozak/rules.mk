# Chaff
BACKLIGHT_ENABLE 	= no
VIA_ENABLE				= no

# Unavailable as data-driven
AUTOCORRECT_ENABLE	= no
KEY_OVERRIDE_ENABLE	= no
TAP_DANCE_ENABLE    = yes

# Processor frequency
F_CPU = 16000000

SRC = matrix.c m0110.c
SRC += custom_keycodes.c
