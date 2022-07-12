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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDOWN),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_GAME] =  { ENCODER_CCW_CW(KC_PSLS, KC_PAST),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_FUN] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDOWN),           ENCODER_CCW_CW(KC_HOME, KC_END)  },
    [_MEDIA] = { ENCODER_CCW_CW(RGB_HUI, RGB_SAI),          ENCODER_CCW_CW(RGB_VAI, RGB_SPI) },
    [_NUM] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [_MOD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MSE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
