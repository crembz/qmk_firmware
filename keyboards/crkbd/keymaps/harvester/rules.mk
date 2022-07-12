RGBLIGHT_ENABLE = no     # Enable WS2812 RGB underlight.
VIA_ENABLE      = yes    # Enable VIA
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
MOUSEKEY_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
RGB_MATRIX_ENABLE = yes
GRAVE_ESC_ENABLE = yes
TAP_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = no
COMBO_ENABLE = no
KEY_LOCK_ENABLE = no
KEY_OVERRIDE_ENABLE = no
SEQUENCER_ENABLE = no
SERIAL_DRIVER = vendor
DEBOUNCE_TYPE = asym_eager_defer_pk

SRC += ./rgb.c
