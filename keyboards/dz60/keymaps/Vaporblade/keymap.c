/*
 * 2019 Michele Bianchi
 */

#include QMK_KEYBOARD_H

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define PU_VU KC_AUDIO_VOL_UP
#define PC_VD KC_AUDIO_VOL_DOWN

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN 1
#define _ADJUST 16

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | FN      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      RShift     |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  GUI  |  Alt  |              Space                | RAlt  | ZKHK |  ADJ |  RCtrl |
   * `-----------------------------------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT(
      F(0),     KC_1,     KC_2,     KC_3,   KC_4,   KC_5,   KC_6,     KC_7,     KC_8,     KC_9,         KC_0,     KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,   KC_Y,     KC_U,     KC_I,     KC_O,         KC_P,     KC_LBRC, KC_RBRC, KC_BSLS,
      MO(_FN),  KC_A,     KC_S,     KC_D,   KC_F,   KC_G,   KC_H,     KC_J,     KC_K,     KC_L,         KC_SCLN,  KC_QUOT, KC_ENT,
      KC_LSFT,  XXXXXXX,  KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,     KC_N,     KC_M,     KC_COMM,      KC_DOT,   KC_SLSH, KC_RSFT, XXXXXXX,
      KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC, KC_SPC, KC_SPC, KC_RALT,  LALT(KC_ZKHK),  XXXXXXX,  MO(_ADJUST),  KC_RCTL
      ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |    DEL    |
   * |-----------------------------------------------------------------------------------------+
   * |        |Prev|Pl/Pau|Next |     |     |     |     |  Up |     |PGUp |Home  |      |PrScrn|
   * |-----------------------------------------------------------------------------------------+
   * |         |Vol+ |Vol- |Mute |     |     |     |Left |Down|Right |PGDwn| End |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |       |      |      |        |
   * `-----------------------------------------------------------------------------------------'
   */

  [_FN] = LAYOUT(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, _______, KC_DEL,
      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,  KC_UP,   _______,   KC_PGUP, KC_HOME, _______, KC_PSCR,
      _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, KC_END, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* ADJUST Layer
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |       |      |      |        |
   * `-----------------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
      _______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
};

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
      shift_esc_shift_mask = get_mods()&MODS_SHIFT_MASK;
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
