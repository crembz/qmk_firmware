/* Copyright 2020 @toastedmangoes
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

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_WHITE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_RED}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer7_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer0_layer,    // Overrides caps lock layer
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,
    my_layer4_layer,
    my_layer5_layer,
    my_layer6_layer,
    my_layer7_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


// Tap Dance keycodes
enum td_keycodes {
    CTL_LPRN, // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
    ALT_RPRN,

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
void alt_rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_rprn_reset(qk_tap_dance_state_t *state, void *user_data);

// Aliases for readability
#define BASE   TO(_BASE)
#define GAME  TO(_GAME)
#define SYM      LT(_SYM,KC_ENT)
#define NAV      LT(_NAV,KC_DEL)
#define FUN    LT(_FUN,KC_SPC)
#define MEDIA   LT(_MEDIA,KC_RGUI)
#define NUM   LT(_NUM,KC_BSPC)
#define MOD   MO(_MOD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    QK_GESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    LSFT_T(KC_TAB),  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  RSFT_T(KC_QUOT),
    TD(CTL_LPRN),  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  TD(ALT_RPRN),
                                            MEDIA,   NAV,    FUN,   NUM,    SYM
  ),

  [_GAME] = LAYOUT_reviung41(
    KC_TAB,  KC_T,   KC_Q,   KC_W,   KC_E,    KC_R,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    KC_LSFT,  KC_G,   KC_A,   KC_S,   KC_D,    KC_F,            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    KC_LCTL ,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RCTL,
                                            KC_ESC,   MOD,  KC_SPC,   KC_ENT,  KC_RALT
  ),

  [_NAV] = LAYOUT_reviung41(
    KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME,            C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), C(KC_S),
    _______,  C(KC_A), C(KC_S), XXXXXXX, C(KC_F), XXXXXXX,            KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
    KC_LCBR,  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,            KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_RCBR,
                                            KC_LGUI,   _______,  KC_ENT,  KC_DEL,  XXXXXXX
  ),

  [_MEDIA] = LAYOUT_reviung41(
    XXXXXXX  , XXXXXXX , XXXXXXX , G(KC_E) , G(KC_R) , XXXXXXX,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    _______, XXXXXXX, LSG(KC_S), XXXXXXX,  XXXXXXX, XXXXXXX,              XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______,   XXXXXXX,  KC_MPLY, KC_MSTP, KC_MUTE
  ),
  [_NUM] = LAYOUT_reviung41(
    XXXXXXX, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                      KC_NUM, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI, _______,
    KC_LBRC,   KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,            QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RBRC,
                                            KC_DOT,   KC_0,  KC_MINS,  _______,  XXXXXXX
  ),
  [_SYM] = LAYOUT_reviung41(
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI, _______,
    XXXXXXX,   KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,            XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            KC_LPRN, KC_RPRN, KC_UNDS,  XXXXXXX,  _______
  ),
  [_FUN] = LAYOUT_reviung41(
    XXXXXXX, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI, _______,
    XXXXXXX,   KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,            XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EE_CLR,
                                            KC_MENU,   KC_TAB,  _______,  XXXXXXX,  XXXXXXX
  ),
  [_MOD] = LAYOUT_reviung41(
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,BASE,
  XXXXXXX, XXXXXXX, XXXXXXX,   _______,  XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
    XXXXXXX,   XXXXXXX, _______,  _______,  _______,   XXXXXXX,            QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            XXXXXXX,   _______,  KC_ENT,  XXXXXXX,  XXXXXXX
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

void atl_rprn_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void alt_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
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
    [ALT_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, atl_rprn_finished, alt_rprn_reset)
};

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(4, layer_state_cmp(state, _MEDIA));
    rgblight_set_layer_state(5, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(6, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(7, layer_state_cmp(state, _FUN));
    return state;
}
