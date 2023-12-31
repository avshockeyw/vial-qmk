/* Copyright 2020 tominabox1
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



// Copyright 2023 sporkus
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HM_A  LSFT_T(KC_A)
#define HM_S  LALT_T(KC_S)
#define HM_D  LGUI_T(KC_D)
#define HM_F  LCTL_T(KC_F)
#define HM_J  RCTL_T(KC_J)
#define HM_K  RGUI_T(KC_K)
#define HM_L  RALT_T(KC_L)
#define HM_Z  LSFT_T(KC_Z)
#define HM_SLSH LSFT_T(KC_SLSH)
#define HM_QUOT RSFT_T(KC_QUOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,      KC_MUTE,     KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,
         HM_A,   HM_S,   HM_D,   HM_F,   KC_G,                   KC_H,   HM_J,   HM_K,    HM_L,   HM_QUOT,
         HM_Z,   KC_X,   KC_C,   KC_V,   KC_B,                   KC_N,   KC_M,   KC_COMM, KC_DOT, HM_SLSH,
                   LT(1, KC_ESC),  LT(1,KC_SPC),                 LT(2,KC_SPC), LT(2, KC_BSPC)
    ),

    [1] = LAYOUT(
         _______,  _______,  _______,  KC_SCLN,  _______,  _______,  KC_EQL,   KC_7,     KC_8,     KC_9,     KC_0,
         _______,  _______,  _______,  KC_COLN,  _______,            KC_MINS,  KC_4,     KC_5,     KC_6,     _______,
         _______,  _______,  _______,  _______,  _______,            KC_BSLS,  KC_1,     KC_2,     KC_3,     _______,
                                       _______,  KC_ENT,             KC_TAB,  _______
    ),

    [2] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_BSPC,   _______,    _______,
         _______,  _______,  _______,  _______,  _______,            KC_LEFT,  KC_DOWN,   KC_UP,     KC_LEFT,    _______,
         _______,  _______,  _______,  _______,  _______,            _______,  _______,   _______,   _______,    _______,
                                       _______,  KC_ENT,             KC_TAB,  _______
    )
};

#ifdef ENCODER_MAP_ENABLE
#undef BLANK_LAYER
#define BLANK_LAYER { ENCODER_CCW_CW(_______, _______) }
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =   BLANK_LAYER,
    [2] =   BLANK_LAYER
};
#endif


#ifdef RGB_MATRIX_ENABLE

// Layer and Mods indicator
#define LED_CENTER_TOP 9
#define LED_CENTER_BOTTOM 10

/* sporkus
#define LAYER_R layer_colors[layer][0] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_G layer_colors[layer][1] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_B layer_colors[layer][2] *  RGB_INDICATOR_BRIGHTNESS / 255
*/

#define MODS_ACTIVE(mods) \
    ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_INDICATOR_BRIGHTNESS:0)
#define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_INDICATOR_BRIGHTNESS/4:0)
#define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
#define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
#define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE

/*sporkus
const uint8_t PROGMEM layer_colors[][4] = {
    {RGB_OFF},
    {RGB_RED},
    {RGB_GREEN},
    {RGB_BLUE},
    {RGB_YELLOW},
    {RGB_PURPLE},
    {RGB_PINK},
    {RGB_TEAL}
};


void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
    #if defined(RGB_LAYER_INDICATOR_ENABLE)
    int layer = get_highest_layer(layer_state|default_layer_state);
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, LAYER_R, LAYER_G, LAYER_B);
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, 0, 0, 0);
    #endif

    #if defined(RGB_MODS_INDICATOR_ENABLE)
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, 0, 0, 0);
    #endif
}


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    set_rgb_matrix_indicators(led_min, led_max);
    return false;
}
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  #if defined(RGB_MODS_INDICATOR_ENABLE)
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
  #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, 0, 0, 0);
  #endif

  if (rgb_matrix_is_enabled()){
    HSV hsv = {0, 255, 0};
    if (!host_keyboard_led_state().caps_lock) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                hsv.h = 0;
                hsv.v = 255;
                break;
            case 2:
                hsv.h = 85;
                hsv.v = 255;
                break;
            case 3:
                hsv.h = 171;
                hsv.v = 255;
                break;
            case 4:
                hsv.h = 43;
                hsv.v = 255;
                break;
            case 5:
                hsv.h = 128;
                hsv.v = 255;
                break;
            case 6:
                hsv.h = 213;
                hsv.v = 255;
                break;
            default: //  for any other layers, or the default layer
                hsv.h = 0;
                hsv.v = 0;
                break;
            };
    }
    if (host_keyboard_led_state().caps_lock) {
        hsv.s = 0;
        hsv.v = 255;
    };
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
  }
    return true;
}

#endif



