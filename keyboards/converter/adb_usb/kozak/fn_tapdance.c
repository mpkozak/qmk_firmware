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

#include QMK_KEYBOARD_H



////////////////////////////////////////////////////////////////////////////////
// Tap Dance

enum td_keycodes {
    TD_LCTL_FN                  // left control + apple fn (tap-hold)
};

// Tapdance states
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
} td_state_t;

// Global tapdance state
static td_state_t td_state;

// Tapdance fns
// td_state_t cur_dance(tap_dance_state_t *state);
// void lctlfn_finished(tap_dance_state_t *state, void *user_data);
// void lctlfn_reset(tap_dance_state_t *state, void *user_data);

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

void lctlfn_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LCTL);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            host_consumer_send(0x029D);   // apple fn
            break;
        default:
            break;
    }
}

void lctlfn_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LCTL);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            host_consumer_send(0);   // apple fn (clear)
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lctlfn_finished, lctlfn_reset)
};
