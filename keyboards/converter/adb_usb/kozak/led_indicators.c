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
#include "adb.h"



/* Write LED state bitmask to ADB bus */
void adb_led_set(uint8_t led_mask) {
    adb_host_kbd_led(~led_mask);
}

/* Generate LED bytemask for current highest layer + caps state */
uint8_t get_led_mask(uint8_t layer, led_t led_state) {
    uint8_t led_mask = (0x01 << layer) >> 1;
    // invert led mask when caps lock is active
    if (led_state.caps_lock) {
        led_mask = ~led_mask;
    }
    return led_mask;
}

/* Toggle LED indicator update on layer change */
layer_state_t layer_state_set_kb(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    led_t led_state = host_keyboard_led_state();
    uint8_t led_mask = get_led_mask(layer, led_state);
    adb_led_set(led_mask);
    return layer_state_set_user(state);
}

/* Default LED indicator setup */
layer_state_t default_layer_state_set_kb(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    led_t led_state = host_keyboard_led_state();
    uint8_t led_mask = get_led_mask(layer, led_state);
    adb_led_set(led_mask);
    return default_layer_state_set_user(state);
}

/* Replace LED state indicator set fn */
void led_set(uint8_t usb_led) {
    uint8_t layer = get_highest_layer(layer_state);
    uint8_t led_mask = get_led_mask(layer, (led_t)usb_led);
    adb_led_set(led_mask);
}
