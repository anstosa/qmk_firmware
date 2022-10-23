/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// MACROS
enum custom_keycodes {
    M_WNDWS,
    M_TASKS,
    M_CANCL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_CANCL:
        if (record->event.pressed) {
            clear_oneshot_mods();
        }
        break;
    case M_TASKS:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LWIN));
            SEND_STRING(SS_TAP(X_TAB));
            SEND_STRING(SS_UP(X_LWIN));
        }
        break;
    }

    return true;
};

// LAYERS
enum layers{
    BASE,
    FNCS,
    NUMS,
    MCRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    M_WNDWS,  KC_F4,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_F10,   KC_F11,   KC_F12,   KC_MUTE,  KC_PSCR,  _______,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_NO,    OSL(MCRO),MO(FNCS), TG(NUMS), KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FNCS] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   RGB_TOG,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [NUMS] = LAYOUT_tkl_f13_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [MCRO] = LAYOUT_tkl_f13_ansi(
        M_CANCL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,
        KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,              KC_NO,
        KC_NO,    KC_NO,    KC_NO,                                  KC_NO,                                  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO),
};

    // [NUMS] = LAYOUT_tkl_f13_ansi(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PAST,  _______,  _______,  KC_PMNS,  KC_PPLS,  _______,  KC_4,     KC_5,     KC_6,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    //     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSLS,            _______,            KC_0,
    //     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  KC_0,     KC_0,     KC_0),

// rotary encoder layers
#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][1][2] = {
        [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [FNCS] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
        [NUMS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [MCRO] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    };
#endif

// {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, __, 13, 14 },
// { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
// { 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 },
// { 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 49, 62, 15, 32 },
// { 63, __, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, __, 74, 86, 75 },
// { 76, 77, 78, __, __, __, 79, __, __, __, 80, 81, 82, 83, 84, 85 },
void rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color_all(50, 50, 50); // everything white
    switch (get_highest_layer(layer_state)) {
        case BASE:
            rgb_matrix_set_color_all(255, 255, 255); // everything white
            break;
        case FNCS:
            rgb_matrix_set_color(1, 0, 255, 0); // F1
            rgb_matrix_set_color(2, 0, 255, 0); // F2
            rgb_matrix_set_color(3, 0, 255, 0); // F3
            rgb_matrix_set_color(4, 0, 255, 0); // F4
            rgb_matrix_set_color(5, 0, 255, 0); // F5
            rgb_matrix_set_color(6, 0, 255, 0); // F6
            rgb_matrix_set_color(7, 0, 255, 0); // F7
            rgb_matrix_set_color(8, 0, 255, 0); // F8
            rgb_matrix_set_color(9, 0, 255, 0); // F9
            rgb_matrix_set_color(10, 0, 255, 0); // F10
            rgb_matrix_set_color(11, 0, 255, 0); // F11
            rgb_matrix_set_color(12, 0, 255, 0); // F12
            break;
        case NUMS:
            rgb_matrix_set_color(84, 0, 255, 0); // 0 (left)
            rgb_matrix_set_color(85, 0, 255, 0); // 0 (down)
            rgb_matrix_set_color(86, 0, 255, 0); // 0 (right)
            rgb_matrix_set_color(75, 0, 255, 0); // 0 (up)
            rgb_matrix_set_color(47, 0, 255, 0); // 1 (del)
            rgb_matrix_set_color(48, 0, 255, 0); // 2 (end)
            rgb_matrix_set_color(49, 0, 255, 0); // 3 (page down)
            rgb_matrix_set_color(30, 0, 255, 0); // 4 (insert)
            rgb_matrix_set_color(31, 0, 255, 0); // 5 (home)
            rgb_matrix_set_color(32, 0, 255, 0); // 6 (page up)
            rgb_matrix_set_color(13, 0, 255, 0); // 7 (screenshot)
            rgb_matrix_set_color(14, 0, 255, 0); // 8 (mic)
            rgb_matrix_set_color(15, 0, 255, 0); // 9 (light)
            rgb_matrix_set_color(27, 0, 255, 0); // -
            rgb_matrix_set_color(28, 0, 255, 0); // +
            rgb_matrix_set_color(73, 0, 255, 0); // /
            rgb_matrix_set_color(24, 0, 255, 0); // *
            break;
        case MCRO:
            rgb_matrix_set_color(0, 0, 255, 0); // esc
            rgb_matrix_set_color(1, 0, 255, 0); // F1
            rgb_matrix_set_color(2, 0, 255, 0); // F2
            rgb_matrix_set_color(3, 0, 255, 0); // F3
            rgb_matrix_set_color(4, 0, 255, 0); // F4
            rgb_matrix_set_color(5, 0, 255, 0); // F5
            rgb_matrix_set_color(6, 0, 255, 0); // F6
            rgb_matrix_set_color(7, 0, 255, 0); // F7
            rgb_matrix_set_color(8, 0, 255, 0); // F8
            rgb_matrix_set_color(9, 0, 255, 0); // F9
            rgb_matrix_set_color(10, 0, 255, 0); // F10
            rgb_matrix_set_color(11, 0, 255, 0); // F11
            rgb_matrix_set_color(12, 0, 255, 0); // F12
            break;
    }
}


    // const rgblight_segment_t PROGMEM state_caps[] = RGBLIGHT_LAYER_SEGMENTS({34, 10, HSV_RED}, // q-p
    //                                                                         {51, 9, HSV_RED},  // a-l
    //                                                                         {64, 7, HSV_RED},  // z-m
    //                                                                         {50, 1, HSV_RED}   // caps
    // );


// set caps lock state
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(4, led_state.caps_lock);
//     return true;
// }
