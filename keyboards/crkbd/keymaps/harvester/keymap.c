/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.vvvvvvvvvfdfgfdvcfdfgbv';p:.'p;:...llloooll...cvbcvbgfdsssaaxzzxasasaqwqwaszxasssdddsdss;;;...s...sssdddf,,gmmf,,gf.,dfgdfg.,mcvbbbb
*/

#include QMK_KEYBOARD_H
#include "oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RSFT_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_CAPS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RCTL_T(KC_BSLS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(_NUM), KC_SPC,     KC_ENT, MO(_FUNC),  RALT_T(KC_MENU)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,                      KC_MINS, KC_EQL,   KC_LBRC,KC_RBRC, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, MO(_MEDIA), KC_SCRL
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GRAVE,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,   KC_INS,  KC_HOME,  KC_UP,  KC_END, KC_PGUP,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,   KC_LEFT, KC_LEFT,KC_DOWN,KC_RIGHT, KC_PGDN,                      NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(_MEDIA),  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, TO(_GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, KC_MPLY
                                      //`--------------------------'  `--------------------------'
  ),
  [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MO(_MODS2), MO(_MODS),  KC_SPC,     KC_ENT, XXXXXXX, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_MODS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_ENT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_MODS2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_ENT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    if (record->event.pressed) {
    set_keylog(keycode, record);
    }
    #endif
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};
