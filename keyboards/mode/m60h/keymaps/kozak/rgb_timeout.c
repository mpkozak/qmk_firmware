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
// RGB timeout

// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md#keyboard-housekeeping

static uint32_t key_timer;           // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false;         // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
    key_timer = timer_read32();     // store time of last refresh
    if (is_rgb_timeout) {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}

void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) {     // check if RGB has already timeout and if enough time has passed
        rgblight_suspend();
        is_rgb_timeout = true;
    }
}

/* Then, call the above functions from QMK's built in post processing functions like so */
/* Runs at the end of each scan loop, check if RGB timeout has occured or not */
void housekeeping_task_rgb(void) {
    #ifdef RGBLIGHT_TIMEOUT
        check_rgb_timeout();
    #endif
}

/* Runs after each key press, check if activity occurred */
void post_process_record_rgb(uint16_t keycode, keyrecord_t *record) {
    #ifdef RGBLIGHT_TIMEOUT
        if (record->event.pressed) {
            refresh_rgb();
        }
    #endif
}
