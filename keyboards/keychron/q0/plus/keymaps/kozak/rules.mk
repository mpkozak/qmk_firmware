VIA_ENABLE              = yes
ENCODER_MAP_ENABLE      = yes
KEY_OVERRIDE_ENABLE     = no
LTO_ENABLE              = yes
KEYBOARD_SHARED_EP      = yes       # apple fn -> globe workaround

SRC += keymap_user_config.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif

# VPATH += keyboards/keychron/common
# SRC += keychron_common.c
