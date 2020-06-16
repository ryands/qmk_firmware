#include QMK_KEYBOARD_H

enum layers {
    base,
    fn
};

#define KC_FN MO(fn)

enum custom_keycodes {
  ADB_FINGER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [base] = LAYOUT_ortho_4x4(
        KC_P7, KC_P8  ,   KC_P9  , KC_TRNS   ,
        KC_P4, KC_P5  ,   KC_P6  , KC_TRNS   ,
        KC_P1, KC_P2  ,   KC_P3  , ADB_FINGER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_FN     
    ),
    [fn] = LAYOUT_ortho_4x4(
        KC_F14 , KC_F15 , KC_F16  , KC_F17  ,
        KC_F18 , KC_F19 , KC_F20  , KC_F21  ,
        KC_TRNS, KC_UP  , KC_TRNS , KC_TRNS ,
        KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS
    ),
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
