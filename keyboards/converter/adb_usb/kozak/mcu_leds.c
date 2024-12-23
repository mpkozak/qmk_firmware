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

/* Map MCU LED pins */
#define RX_LED B0
#define TX_LED D5



void mcu_led_enable(void) {
    gpio_set_pin_output(RX_LED);
    gpio_set_pin_output(TX_LED);
}

void mcu_led_toggle(uint8_t led_state) {
    gpio_write_pin_high(RX_LED);
    gpio_write_pin_high(TX_LED);
    if (led_state & 0x01) {
        gpio_write_pin_low(RX_LED);
    }
    if (led_state & 0x02) {
        gpio_write_pin_low(TX_LED);
    }
}

layer_state_t layer_state_set_mcu(layer_state_t state) {
    mcu_led_enable();
    switch (get_highest_layer(state)) {
        case DFLT:
            mcu_led_toggle(0x02);
            break;
        case SPD:
            mcu_led_toggle(0x03);
            break;
        default:
            mcu_led_toggle(0x00);
            break;
    }
    return state;
}





// void mcu_leds_on(void) {
//     gpio_write_pin_low(RX_LED);
//     gpio_write_pin_low(TX_LED);
// }

// void mcu_leds_off(void) {
//     gpio_write_pin_high(RX_LED);
//     gpio_write_pin_high(TX_LED);
// }

// layer_state_t layer_state_set_mcu(layer_state_t state) {
//     mcu_led_enable();
//     switch (get_highest_layer(state)) {
//         case SPD:
//             mcu_leds_on();
//             break;
//         default:
//             mcu_leds_off();
//             break;
//     }
//     return state;
// }
