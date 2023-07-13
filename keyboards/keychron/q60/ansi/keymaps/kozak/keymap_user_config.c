/* Copyright 2023 @ M. Parker Kozak (https://github.com/mpkozak)
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
#include "keymap_user_config.h"

typedef struct {
    uint8_t enable_rgb;
    uint8_t fn_layer_transparent_keys_off;
    uint8_t fn_layer_color_enable;
} user_config_t;

user_config_t user_config;

void eeconfig_init_user(void) {
    user_config.fn_layer_transparent_keys_off = DEFAULT_FN_LAYER_TRANSPARENT_OFF;
    user_config.fn_layer_color_enable = DEFAULT_FN_LAYER_SHOW_COLOR;
    user_config.enable_rgb = DEFAULT_RGB_ENABLE_BASE;
    user_config_write_eeprom();
}

void user_config_read_eeprom(void) {
    eeconfig_read_user_datablock(&user_config);
}

void user_config_write_eeprom(void) {
    eeconfig_update_user_datablock(&user_config);
}

// getters

uint8_t  user_config_get_fn_layer_transparent_keys_off(void) {
    return user_config.fn_layer_transparent_keys_off;
}

uint8_t  user_config_get_fn_layer_color_enable(void) {
    return user_config.fn_layer_color_enable;
}

uint8_t user_config_get_enable_rgb(void) {
    return user_config.enable_rgb;
}

// setters

void user_config_toggle_fn_layer_transparent_keys_off(void) {
    user_config.fn_layer_transparent_keys_off ^= 1;
    user_config_write_eeprom();
}

void user_config_toggle_fn_layer_color_enable(void) {
    user_config.fn_layer_color_enable ^= 1;
    user_config_write_eeprom();
}

void user_config_toggle_enable_rgb(void) {
    user_config.enable_rgb ^= 1;
    user_config_write_eeprom();
}
