#include QMK_KEYBOARD_H

enum keyboard_layers {
    BL,
    FN,
    CL
};

/*
 * Default HHKB Layout
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BkSpc│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Ctrl │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │█████│Enter│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Shift│█████│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │█████│Shift│ Fn  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│█████│ Gui │ Alt │█████│█████│Space│█████│█████│█████│█████│█████│ Alt │ Gui │█████│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
[BL] = LAYOUT_60_hhkb(
        KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_GRV, \
        KC_TAB,    KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,      \
        KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,      \
        KC_LSPO,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,      KC_RSPC, MO(FN), \
             KC_LALT, KC_LGUI,              KC_SPC,                         KC_RGUI, KC_RALT ),
    /* 1: HHKB Fn layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Pwr │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Caps │ RGB │RGBfw│RGBrv│BLtog│BLstp│     │     │ Psc │ Slk │ Pus │ Up  │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │ VoD │ VoU │ Mut │ Ejc │     │NP_* │NP_/ │Home │PgUp │Left │Right│█████│NPEnt│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │█████│     │     │     │     │     │NP_+ │NP_- │ End │PgDwn│Down │█████│     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│█████│     │     │█████│█████│█████│     │█████│█████│█████│█████│     │     │█████│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
[FN]= LAYOUT_60_hhkb(
       KC_PWR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL, \
       KC_CAPS, RGB_TOG, RGB_MOD, RGB_RMOD, BL_TOGG, BL_STEP, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS,   KC_UP, KC_TRNS, KC_TRNS,  \
       KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,       KC_PENT,       \
       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS,  KC_END, KC_PGDN, KC_DOWN,       KC_TRNS, KC_TRNS, \
             KC_TRNS, KC_TRNS,                   KC_TRNS,                         KC_TRNS, KC_TRNS ),
};

#define COLOR_BL HSV_CYAN
#define COLOR_FN HSV_BLUE
#define COLOR_CL HSV_PURPLE

const rgblight_segment_t PROGMEM layer_leds_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, COLOR_BL}
);

const rgblight_segment_t PROGMEM layer_leds_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, COLOR_FN}
);

const  rgblight_segment_t PROGMEM layer_leds_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, COLOR_CL}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_leds_base,
    layer_leds_fn,
    layer_leds_capslock
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(BL, true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(BL, layer_state_cmp(state, BL));
    rgblight_set_layer_state(FN, layer_state_cmp(state, FN));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(CL, led_state.caps_lock);
    return true;
}
