// [Q2 layers Init] -------------------------------------------------------//
typedef enum {
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _MEDIA,
    _FUNC
}Q2_LAYERS;

extern enum Q2_LAYERS crkbd_layers;

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
}Q2_RGB;

extern enum Q2_RGB crkbd_rgb;
