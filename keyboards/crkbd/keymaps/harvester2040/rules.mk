
MCU := RP2040
BOOTLOADER := rp2040
BOARD = GENERIC_PROMICRO_RP2040
LTO_ENABLE      = yes
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
VIA_ENABLE      = yes
GRAVE_ESC_ENABLE = yes
DEBOUNCE_TYPE = asym_eager_defer_pk
