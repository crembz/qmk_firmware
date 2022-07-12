// [SOFLE layers Init] -------------------------------------------------------//
typedef enum {
    _BASE,
    _GAME,
    _NAV,
    _MSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _MOD
}SOFLE_LAYERS;

extern enum SOFLE_LAYERS sofle_layers;

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
}SOFLE_RGB;

extern enum SOFLE_RGB sofle_rgb;
