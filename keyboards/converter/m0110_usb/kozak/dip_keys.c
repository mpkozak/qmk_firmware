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
// DIP switch keys

const keypos_t PROGMEM dip_keypos[1] = {
    MAKE_KEYPOS(6, 6)       // \|
};

bool dip_switch_update_kb(uint8_t index, bool active) {
    keypos_t key = dip_keypos[index];
    keyevent_t event = MAKE_KEYEVENT(key.row, key.col, active);
    action_exec(event);
    return true;
}





////////////////////////////////////////////////////////////////////////////////
// alternate approach - tested working

// #define DIP_PIN C6

// void matrix_init_kb(void) {
//     // print("matrix_init_kb");
//     gpio_set_pin_input_high(DIP_PIN);
//     matrix_init_user();
// }

// void matrix_scan_kb(void) {
//     // print("matrix_scan_kb");
//     static bool state = 0;
//     bool active = !gpio_read_pin(DIP_PIN);
//     if (state != active) {
//         // print("active");
//         keypos_t key = MAKE_KEYPOS(6, 6);
//         keyevent_t event = MAKE_KEYEVENT(key.row, key.col, active);
//         action_exec(event);
//         state = active;
//     }
//     matrix_scan_user();
// }
