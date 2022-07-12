// [CRKBD layers Init] -------------------------------------------------------//
typedef enum {
    _BASE,
    _GAME,
    _NAV,
    _MSE,
    _BTN,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _MOD
}CRKBD_LAYERS;

extern enum CRKBD_LAYERS crkbd_layers;

typedef enum {
    _RGB_INDICATORS,
    _RGB_DANGER,
    _RGB_NUM,
    _RGB_FUN,
    _RGB_MEDIA,
    _RGB_GAME,
    _RGB_MODS,
    _RGB_NAV,
    _RGB_DEFAULT,
    _RGB_TRANS,
    _RGB_DISABLED
}CRKBD_RGB;

extern enum CRKBD_RGB crkbd_rgb;
