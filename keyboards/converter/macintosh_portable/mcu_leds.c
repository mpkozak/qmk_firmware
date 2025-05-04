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



////////////////////////////////////////////////////////////////////////////////
// MCU led controls

/* Activate MCU led on power-on */
void keyboard_pre_init_kb(void) {
    setPinOutput(LED_PIN);
#ifdef LED_POWER_ON
    writePinHigh(LED_PIN);
#endif
}

layer_state_t layer_state_set_mcu(layer_state_t state) {
    state = layer_state_set_ac(state);
#ifdef LED_LAYER_STATUS
    switch (get_highest_layer(state)) {
        case SPD:
            gpio_write_pin_high(LED_PIN);
            break;
        default:
            gpio_write_pin_low(LED_PIN);
            break;
    }
#endif
    return state;
}



/* Runs after each key press, toggles MCU LED off with keydown */
#ifdef LED_DIAG_BLINK
void post_process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state) == DFLT) {
        if (record->event.pressed) {
            gpio_write_pin_low(LED_PIN);
        } else {
            gpio_write_pin_high(LED_PIN);
        }
    }
}
#endif
