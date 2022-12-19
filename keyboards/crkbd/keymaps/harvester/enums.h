// [CRKBD layers Init] -------------------------------------------------------//
typedef enum {
    _BASE,
    _NUM,
    _FUN,
    _MEDIA,
    _GAME,
    _MOD,
    _NAV,
    _MSE,
    _SYM
}CRKBD_LAYERS;

extern enum CRKBD_LAYERS crkbd_layers;

typedef enum {
    _RGB_INDICATORS,
    _RGB_DANGER,
    _RGB_NUM,
    _RGB_FUNC,
    _RGB_MEDIA,
    _RGB_GAME,
    _RGB_MOD,
    _RGB_DEFAULT,
    _RGB_TRANS,
    _RGB_DISABLED
}CRKBD_RGB;

extern enum CRKBD_RGB crkbd_rgb;
