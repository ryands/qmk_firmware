#include QMK_KEYBOARD_H



enum layers {
    base,
    num
};

#define KC_FN MO(num)

enum custom_keycodes {
  ADB_FINGER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [base] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS   ,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS   ,
        KC_TRNS, KC_TRNS, KC_TRNS, ADB_FINGER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_FN
    ),
    [num] = LAYOUT_ortho_4x4(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_P7, KC_P8  , KC_P9  , KC_TRNS,
        KC_P4, KC_P5  , KC_P6  , KC_TRNS,
        KC_P1, KC_P2  , KC_P3  , KC_TRNS
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
