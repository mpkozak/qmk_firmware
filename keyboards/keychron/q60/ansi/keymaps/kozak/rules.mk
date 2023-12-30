VIA_ENABLE = yes
AUTOCORRECT_ENABLE = yes
DIP_SWITCH_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
LTO_ENABLE = yes

SRC += keymap_user_config.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif

VPATH += keyboards/keychron/common
SRC += keychron_common.c
