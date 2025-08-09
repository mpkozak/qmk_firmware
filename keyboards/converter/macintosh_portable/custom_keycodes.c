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
// Default layer untoggle

bool process_record_kc(uint16_t keycode, keyrecord_t *record) {
    // default layer untoggle
    if (keycode == KC_ESC) {                            // esc key
        if (get_highest_layer(layer_state) > 0) {       // while above base layer
            if (record->event.pressed) {                // keydown event
                if (get_mods() == MOD_BIT(KC_LCTL)) {   // while left control active
                    layer_clear();
                    return false;
                }
            }
        }
        return true;
    }
    return true;
}
