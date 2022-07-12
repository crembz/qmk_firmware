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
  XXXXXXX,XXXXXXX,LT(_MEDIA,KC_ESC),   LT(_NAV,KC_TAB),  LT(_MSE,KC_SPC),      LT(_SYM,KC_ENT),   LT(_NUM,KC_BSPC), LT(_FUN,KC_DEL), XXXXXXX, XXXXXXX
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
  XXXXXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    XXXXXXX,                    C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), C(KC_S),
  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                       KC_CAPS,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC,       _______, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,       KC_ENT, KC_BSPC, KC_DEL, XXXXXXX, _______
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
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TO(_GAME), XXXXXXX,                    C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), C(KC_S),
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,     KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX
),
[_MEDIA] = LAYOUT(
  XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,       RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
                         XXXXXXX, XXXXXXX, MO(_FUN), _______, KC_ENT,     XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
)
};
