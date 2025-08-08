/* Copyright 2025 @ M. Parker Kozak (https://github.com/mpkozak)
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

#include "custom_keycodes.h"



////////////////////////////////////////////////////////////////////////////////
// User keymap callbacks

bool process_record_kc(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_APFN:       // apple fn key
            if (record->event.pressed) {
                host_consumer_send(0x029D);
            } else {
                host_consumer_send(0);
            }
            return false;
        case KC_F20:        // power key
            if (record->event.pressed) {
                if (get_mods() == MOD_BIT(KC_LCTL)) {   // while left control active
                    layer_clear();
                    return false;
                }
            }
            return true;
        default:
            return true;
    }
}
