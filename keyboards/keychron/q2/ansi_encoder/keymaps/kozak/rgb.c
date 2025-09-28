/* Copyright 2024 @ M. Parker Kozak (https://github.com/mpkozak)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "rgb_matrix_user.h"
#include "keymap_user.h"
#include "keymap_user_config.h"



////////////////////////////////////////////////////////////////////////////////
// Bootloader

enum user_bootloader_state {
    BOOTLOADER_INACTIVE,
    BOOTLOADER_PRESSED,
    BOOTLOADER_WAIT,
    BOOTLOADER_DO
} bootloader_state;



////////////////////////////////////////////////////////////////////////////////
// RBG layers

void matrix_init_rgb(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void housekeeping_task_rgb(void) {
    switch(bootloader_state) {
        case BOOTLOADER_DO:
            // bootloader was pressed two frames ago. RGB should now be off,
            // so we can call the bootloader.
            reset_keyboard();
            break;
        case BOOTLOADER_WAIT:
            // bootloader was pressed on previous frame, we wait this frame and
            // set flag to do bootloader at end of next frame. For some reason, my
            // Q2 needed this extra wait frame.
            bootloader_state = BOOTLOADER_DO;
            break;
        case BOOTLOADER_PRESSED:
            // User pressed bootloader keycode and RGB was disabled earlier in this
            // frame. However RGB changes wont take place immediately, so we set a
            // flag here which will be caught at end of the next frame.
            bootloader_state = BOOTLOADER_WAIT;
            break;
        default:
            break;
    }
}

layer_state_t default_layer_state_set_rgb(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE:
            // load base settings
            rgb_matrix_enable_noeeprom();
            rgb_matrix_reload_from_eeprom();
            // check disable
            if (!user_config_get_enable_rgb()) {
                rgb_matrix_disable_noeeprom();
            }
            break;
        default:
            break;
    }
    return state;
}

void keyboard_post_init_rgb(void) {
    user_config_read_eeprom();
}

bool process_record_rgb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_BOOT:
            // We want to turn off LEDs before calling bootloader, so here
            // we call rgb_matrix_disable_noeeprom() and set a flag because
            // the LEDs won't be updated until the next frame.
            if (record->event.pressed) {
                rgb_matrix_disable_noeeprom();
                bootloader_state = BOOTLOADER_PRESSED;
            }
            return false;  // Skip all further processing of this key
        case RM_TOGG:
            if (record->event.pressed) {
                rgb_matrix_toggle_noeeprom();
                user_config_toggle_enable_rgb();
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE:
            if (record->event.pressed) {
                user_config_toggle_fn_layer_transparent_keys_off();
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                user_config_toggle_fn_layer_color_enable();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}
