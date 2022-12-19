LTO_ENABLE = yes
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no			# Commands for debug and configuration
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
MAGIC_ENABLE = yes
BACKLIGHT_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
BOOTMAGIC_ENABLE = yes
TERMINAL_ENABLE = no
RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
OLED_ENABLE = no
OLED_DRIVER = SSD1306
VIA_ENABLE = yes
GRAVE_ESC_ENABLE = yes
SPACE_CADET_ENABLE = no
NKRO_ENABLE = yes
SPLIT_KEYBOARD = no
ENCODER_ENABLE = no
DEBOUNCE_TYPE = asym_eager_defer_pk
ENCODER_MAP_ENABLE = no
TAP_DANCE_ENABLE = yes

BOOTLOADER = qmk-dfu
MCU = atmega32u4
