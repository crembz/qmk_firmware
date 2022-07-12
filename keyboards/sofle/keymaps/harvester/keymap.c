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
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  RSFT_T(KC_QUOT),
  KC_LBRC,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TO(_NUM),     KC_MUTE,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RBRC,
                 KC_LGUI,KC_LALT,KC_LCTRL, MO(_MEDIA), KC_SPC,      KC_ENT,  LT(_FUNC,KC_LEFT), RCTL_T(KC_DOWN), RALT_T(KC_UP), RGUI_T(KC_RIGHT)
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
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LSFT,   KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  RSFT_T(KC_QUOT),
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_F13,     KC_MUTE,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_ENT,KC_LALT,MO(_FUNC),MO(_MODS), KC_SPC,      KC_SPC,  KC_TRNS, KC_RCTRL, KC_RALT, KC_RGUI
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
[_NUM] = LAYOUT(
  TO(_BASE),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              KC_NUM,   KC_PSLS,   KC_PAST,   KC_PMNS,  XXXXXXX,  _______,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,           KC_P7, KC_P8, KC_P9, KC_PPLS,    XXXXXXX,  XXXXXXX,
  _______, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                       KC_P4, KC_P5, KC_P6, KC_PPLS, XXXXXXX, XXXXXXX,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC,       _______, KC_P1, KC_P2, KC_P3, XXXXXXX, XXXXXXX, XXXXXXX,
                       _______, _______, _______, _______, _______,       _______, KC_P0, KC_P0, KC_PDOT, _______
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
[_FUNC] = LAYOUT(
  KC_F11,  KC_F1,   KC_F2,   KC_F3,  KC_F4, KC_F5,                           XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
  KC_F12,  KC_F6,   KC_F7,   KC_F8,  KC_F9, KC_F10,                        XXXXXXX, XXXXXXX,   KC_INS, XXXXXXX,XXXXXXX, XXXXXXX,
  KC_CAPS, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_PLUS,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  _______,       _______,  NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         KC_PSCR, KC_SCRL, KC_PAUS, KC_MINS, KC_UNDS,       _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),
[_MEDIA] = LAYOUT(
  QK_BOOT, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  RGB_TOG,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  _______, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  EE_CLR,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,       RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,       _______, TO(_GAME), KC_MPRV, KC_MPLY, KC_MNXT
),
[_MODS] = LAYOUT(
  TO(_BASE), KC_6,   KC_7,    KC_8,    KC_9,    KC_0,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,   _______,  XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  _______,  _______,  _______, XXXXXXX,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
