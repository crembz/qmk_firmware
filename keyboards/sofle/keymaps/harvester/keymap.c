 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "enums.h"
#include "rgb.c"
#include "oled.c"
#include "encoder.c"

// Aliases for readability
#define BASE   TO(_BASE)
#define GAME  TO(_GAME)
#define SYM      LT(_SYM,KC_ENT)
#define NAV      LT(_NAV,KC_TAB)
#define FUN    LT(_FUN,KC_DEL)
#define MEDIA   LT(_MEDIA,KC_ESC)
#define NUM   LT(_NUM,KC_BSPC)
#define MOD   MO(_MOD)
#define MSE     LT(_MSE,KC_SPC)

// Tap Dance keycodes
enum td_keycodes {
    CTL_LPRN, // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
    CTL_RPRN,

};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void ctl_lprn_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_lprn_reset(qk_tap_dance_state_t *state, void *user_data);
void ctl_rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_rprn_reset(qk_tap_dance_state_t *state, void *user_data);

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
  KC_ESC,       KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,    KC_9,  KC_0,       KC_BSPC,
  KC_GRV,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                           KC_Y,   KC_U,   KC_I,    KC_O,  KC_P,       KC_BSLS,
  KC_LSFT,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                           KC_H,   KC_J,   KC_K,    KC_L,  KC_SCLN,    RSFT_T(KC_QUOT),
  TD(CTL_LPRN), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_CAPS,    KC_MUTE,    KC_N,   KC_M,   KC_COMM, KC_DOT,KC_SLSH,    TD(CTL_RPRN),
                        KC_LGUI,KC_LALT,MEDIA,  NAV,    MSE,        SYM,        NUM,    FUN,    KC_RALT, KC_MENU
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LSFT,   KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_F13,     KC_MUTE,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 XXXXXXX,XXXXXXX,MO(_NUM), MO(_MOD),  KC_SPC,      KC_ENT,   KC_BSPC , KC_DEL, XXXXXXX, XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,               XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,                    C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), C(KC_S),
  _______, C(KC_A),   C(KC_S), XXXXXXX,  XXXXXXX, XXXXXXX,                       KC_CAPS,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
  _______,  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX,       XXXXXXX, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
                       _______, _______, XXXXXXX, _______, XXXXXXX,       KC_ENT, KC_BSPC, KC_DEL, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |--------|   |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MSE] = LAYOUT(
  QK_BOOT,  XXXXXXX,    XXXXXXX,        LGUI_T(KC_E),   XXXXXXX,    TO(_GAME),                          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,                            C(KC_Y),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),    C(KC_S),
  XXXXXXX,  XXXXXXX,    LSG_T(KC_S),    XXXXXXX,        XXXXXXX,    XXXXXXX,                            XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    XXXXXXX,
  EE_CLR,   XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,   XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   XXXXXXX,
                         XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,    _______,     KC_BTN1,   KC_BTN3,    KC_BTN2,    XXXXXXX,    XXXXXXX
),
[_MEDIA] = LAYOUT(
  _______, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,_______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,       RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX,     KC_MPLY, KC_MSTP, KC_MUTE, XXXXXXX, XXXXXXX
),
[_NUM] = LAYOUT(
  XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,                         XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  XXXXXXX, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI, XXXXXXX,
  XXXXXXX, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, KC_DOT, KC_0,  KC_MINS,     XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
),
[_SYM] = LAYOUT(
  XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI, XXXXXXX,
  XXXXXXX, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[_FUN] = LAYOUT(
  XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  XXXXXXX, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI, XXXXXXX,
  XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, KC_MENU, KC_TAB,  KC_SPC,     XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
),
[_MOD] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,TO(_BASE),
  XXXXXXX, XXXXXXX, XXXXXXX,   _______,  XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  _______,  _______,  _______, XXXXXXX,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_ENT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void ctl_lprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(LSFT(KC_9));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(LSFT(KC_9));
            register_code16(LSFT(KC_9));
            break;
        default:
            break;
    }
}

void ctl_lprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(LSFT(KC_9));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(LSFT(KC_9));
            break;
        default:
            break;
    }
}

void ctl_rprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(LSFT(KC_0));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(LSFT(KC_0));
            register_code16(LSFT(KC_0));
            break;
        default:
            break;
    }
}

void ctl_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(LSFT(KC_0));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(LSFT(KC_0));
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [CTL_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_lprn_finished, ctl_lprn_reset),
    [CTL_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_rprn_finished, ctl_rprn_reset)
};
