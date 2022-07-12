#include QMK_KEYBOARD_H
#include "rgb.h"

#ifdef RGB_MATRIX_ENABLE

__attribute__ ((weak))

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_INDICATORS);
            }
        }
    }

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index >= led_min && index <= led_max && index != NO_LED && (keymap_key_to_keycode(layer, (keypos_t){col, row}) == QK_BOOTLOADER || keymap_key_to_keycode(layer, (keypos_t){col, row}) == QK_CLEAR_EEPROM)) {
                    rgb_matrix_set_color(index, RGB_DANGER);
                } else if (index >= led_min && index <= led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    switch (layer) {
                        case _NUM: {
                            rgb_matrix_set_color(index, RGB_NUM);
                            break;
                        }
                        case _FUN: {
                            rgb_matrix_set_color(index, RGB_FUNC);
                            break;
                        }
                        case _MEDIA: {
                            rgb_matrix_set_color(index, RGB_MEDIA);
                            break;
                        }
                        case _GAME: {
                            switch (keymap_key_to_keycode(layer, (keypos_t){col, row})) {
                                case KC_W: {
                                    rgb_matrix_set_color(index, RGB_GAME);
                                    break;
                                }
                                case KC_A: {
                                    rgb_matrix_set_color(index, RGB_GAME);
                                    break;
                                }
                                case KC_S: {
                                    rgb_matrix_set_color(index, RGB_GAME);
                                    break;
                                }
                                case KC_D: {
                                    rgb_matrix_set_color(index, RGB_GAME);
                                    break;
                                }
                                default: {
                                    rgb_matrix_set_color(index, RGB_DISABLED);
                                    break;
                                }
                            }
                            break;
                        };
                        case _MOD: {
                            rgb_matrix_set_color(index, RGB_MODS);
                            break;
                        };
                        default: { // for any other layers, or the default layer
                            rgb_matrix_set_color(index, RGB_DEFAULT);
                        }
                    }
                } else if (index >= led_min && index <= led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) == KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_TRANS);
                } else if (index >= led_min && index <= led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) == KC_NO) {
                    rgb_matrix_set_color(index, RGB_DISABLED);
                }
            }
        }
    }
}
#endif
