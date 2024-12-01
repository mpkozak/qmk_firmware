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
#include "custom_keycodes.h"



////////////////////////////////////////////////////////////////////////////////
// Control/Fn tap+hold stack

static bool was_ctrl_tapped = false;
static bool is_ctrl_clean = false;
static bool is_fn_active = false;
static uint16_t fn_timer = 0;

void housekeeping_task_fn(void) {
    if (was_ctrl_tapped) {
        if (timer_elapsed(fn_timer) >= TAPPING_TERM * 2) {
            was_ctrl_tapped = false;
        }
    }
}

bool process_record_fn(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_FN:       // left control + tap/hold apple fn key
            if (record->event.pressed) {    // keydown
                if (was_ctrl_tapped) {      // control was tapped already
                    if (timer_elapsed(fn_timer) < TAPPING_TERM * 2) {       // recently enough
                        was_ctrl_tapped = false;
                        host_consumer_send(0x029D);     // send fn
                        is_fn_active = true;
                        return false;
                    } else {                // not recently enough
                        was_ctrl_tapped = false;
                    }
                }                           // ctrl was not tapped already
                register_code(KC_LCTL);     // send ctrl
                is_ctrl_clean = true;
                fn_timer = timer_read();    // start timer
                return false;
            } else {                        // keyup
                if (is_fn_active) {         // fn was active
                    host_consumer_send(0);  // clear fn
                    is_fn_active = false;
                    return false;
                }
                if (timer_elapsed(fn_timer) <= TAPPING_TERM * 2) {   // was tapped
                    if (is_ctrl_clean) {                             // without other keystroke occurring
                        was_ctrl_tapped = true;
                        fn_timer = timer_read();     // restart timer
                    }
                }
                unregister_code(KC_LCTL);       // clear ctrl
                return false;
            }
        case KC_APFN:       // apple fn key
            if (record->event.pressed) {
                host_consumer_send(0x029D);
            } else {
                host_consumer_send(0);
            }
            return false;
        default:
            is_ctrl_clean = false;
            was_ctrl_tapped = false;
            return true;
    }
}
