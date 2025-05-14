// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_F13,   KC_F14, KC_F15, KC_F16,
    KC_F17, KC_F18, KC_F19, KC_F20,
    KC_F21,  KC_F22, KC_F23, KC_F24
  ),
  [1] = LAYOUT(
    LSFT(KC_F13), LSFT(KC_F14), LSFT(KC_F15), LSFT(KC_F16),
    LSFT(KC_F17), LSFT(KC_F18), LSFT(KC_F19), LSFT(KC_F20),
    LSFT(KC_F21), LSFT(KC_F22), LSFT(KC_F23), LSFT(KC_F24)
  ),
  [2] = LAYOUT(
      LCTL(KC_F13), LCTL(KC_F14), LCTL(KC_F15), LCTL(KC_F16),
      LCTL(KC_F17), LCTL(KC_F18), LCTL(KC_F19), LCTL(KC_F20),
      LCTL(KC_F21), LCTL(KC_F22), LCTL(KC_F23), LCTL(KC_F24)
  ),
  [3] = LAYOUT(
        LALT(KC_F13), LALT(KC_F14), LALT(KC_F15), LALT(KC_F16),
        LALT(KC_F17), LALT(KC_F18), LALT(KC_F19), LALT(KC_F20),
        LALT(KC_F21), LALT(KC_F22), LALT(KC_F23), LALT(KC_F24)
  ),
  [4] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, QK_RBT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

  )
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

//#if defined(DIP_SWITCH_MAP_ENABLE)
//bool dip_switch_update_user(uint8_t index, bool active) {

       //     if(!gpio_read_pin(B6)) { gpio_write_pin_high(F7); }
          //  if(active) { clicky_on(); } else { clicky_off(); }


//#endif
int layer = 0;
bool dip_switch_update_kb(uint8_t index, bool active) {
    gpio_set_pin_output(F7);
    gpio_set_pin_output(B2);
    gpio_set_pin_output(B5);

  if (!gpio_read_pin(B6)) {
    // Be adviced that 3 else if statements didn't work for me.

     switch (layer) {
    case 0:
        layer_move(1);
         gpio_write_pin_high(F7);
         gpio_write_pin_low(B2);
         gpio_write_pin_low(B5);
    break;
    case 1:
        layer_move(2);
         gpio_write_pin_high(F7);
         gpio_write_pin_high(B2);
         gpio_write_pin_low(B5);
    break;
    case 2:
        layer_move(3);
         gpio_write_pin_high(F7);
         gpio_write_pin_high(B2);
         gpio_write_pin_high(B5);
    break;
    case 3:
        layer_move(0);
        gpio_write_pin_low(F7);
        gpio_write_pin_low(B2);
        gpio_write_pin_low(B5);
    break;
    }
    if (layer < 3) {
        layer++;
    } else {
        layer = 0;
    }
 }
 if (!gpio_read_pin(B6) && !gpio_read_pin(F6)) {
     layer_move(4);
     gpio_write_pin_high(F7);
     gpio_write_pin_low(B2);
     gpio_write_pin_high(B5);

 }
    return true;
}
