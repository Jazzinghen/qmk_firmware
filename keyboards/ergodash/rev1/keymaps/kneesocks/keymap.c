// Copyright 2019 Michele Bianchi

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FUNCTION 1
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC,
  ADJUST,
};

// Keys definitions to make stuff easier to format
#define PU_VU KC_AUDIO_VOL_UP
#define PC_VD KC_AUDIO_VOL_DOWN

// Definiton for Esc + Shift Combo
#define MODS_CTRL_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  | Caps |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Space|   N  |   M  |   ,  |   .  |  /   | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | ADJ  |  GUI |  Alt | AltGr|||||||| FUNC | Space|      ||||||||      | Space| Enter|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_SPC , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    ADJUST,  KC_LGUI, KC_LALT, KC_ALGR,          FUNC,    KC_SPC ,KC_SPC,          KC_SPC,KC_SPC , KC_ENT,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Function
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | PrScr|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | Back |Pl/Pau| Next |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | Vol- | Mute | Vol+ |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      |||||||| Home |PageDn|PageUp| End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_FUNCTION] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                         KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_PSCR,  \
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,                        _______, _______, _______, _______, _______,   _______, _______, \
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______,                        _______, _______, _______, _______, _______,   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,   _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          KC_HOME, KC_PGDOWN, KC_PGUP, KC_END \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      | Reset|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |BL ON | BL+  |      |                    |      |RGB ON| HUE+ | SAT+ | VAL+ |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |BL Cyc| BL-  |      |                    |      | MODE | HUE- | SAT- | VAL- |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | MODER|      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______,  _______, _______, _______, _______, RESET, \
    _______, _______, _______, _______, BL_TOGG, BL_INC,  _______,                       _______, RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, \
    _______, _______, _______, _______, BL_BRTG, BL_DEC,  _______,                       _______, RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                       _______, RGB_RMOD, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,     _______, _______, _______,           _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
