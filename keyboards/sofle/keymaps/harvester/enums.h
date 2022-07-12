// [CRKBD layers Init] -------------------------------------------------------//
typedef enum {
    _BASE,
    _NUM,
    _GAME,
    _FUNC,
    _MEDIA,
    _MODS,
    _MODS2
}CRKBD_LAYERS;

extern enum CRKBD_LAYERS crkbd_layers;

typedef enum {
    _RGB_INDICATORS,
    _RGB_DANGER,
    _RGB_NUM,
    _RGB_FUNC,
    _RGB_MEDIA,
    _RGB_GAME,
    _RGB_MODS,
    _RGB_MODS2,
    _RGB_DEFAULT,
    _RGB_TRANS,
    _RGB_DISABLED
}CRKBD_RGB;

extern enum CRKBD_RGB crkbd_rgb;
