#include QMK_KEYBOARD_H

enum layers {
    base,
    fn,
    fn2
};

#define KC_FN MO(fn)
#define KC_FN2 MO(fn2)

enum custom_keycodes {
  ADB_FINGER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* template:
    [layer] = LAYOUT_ortho_4x4(
        _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______
    )
    */
    [base] = LAYOUT_ortho_4x4(
        KC_P7 , KC_P8  ,   KC_P9  , _______   ,
        KC_P4 , KC_P5  ,   KC_P6  , _______   ,
        KC_P1 , KC_P2  ,   KC_P3  , ADB_FINGER,
        KC_FN2, KC_P0  ,   KC_PDOT, KC_FN     
    ),
    [fn] = LAYOUT_ortho_4x4(
        _______ , KC_UP   , _______ , _______ ,
        KC_LEFT , _______ , KC_RIGHT, _______ ,
        _______ , KC_DOWN , _______ , _______ ,
        _______ , _______ , _______ , _______
    ),
    [fn2] = LAYOUT_ortho_4x4(
        _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ADB_FINGER:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                SEND_STRING("\\");
                clear_keyboard();
            }
            return false;
            break;
    }
    return true;
}
