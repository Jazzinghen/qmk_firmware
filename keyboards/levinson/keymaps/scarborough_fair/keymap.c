#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |AltGr |Lower |Space |   |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Raise
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   |      |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |   |      |      |      |      |      |  |   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |   |      |      | Home |PgDown| PgUp | End  |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, KC_PIPE, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

/* Lower
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Del  | Prev |Pl/Pau| Next |      | Kana |   |      |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      | Vol- | Vol+ |      |MuHen | Hen  |   |      |      |      |      |      |  \   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_KANA, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  _______, KC_VOLD, KC_VOLU, _______, KC_MHEN, KC_HENK, _______, _______, _______, _______, _______, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |      | Reset|      |      |      |      |   |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|   |AGswap|      |Hue - |Hue + |RGBTog|Knight|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |BLTogg|BL Inc|BL Dec|BLBrtg|      |   |      |      |Sat + |Sat - |Static|Swirl |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |Bri + |Bri - |Rainb |Gradi |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______,  RGB_HUI, RGB_HUD, RGB_TOG, RGB_M_K, \
  _______, BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, _______, _______, _______, RGB_SAI, RGB_SAD, RGB_M_P, RGB_M_SW, \
  _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_VAD, RGB_M_R, RGB_M_G  \
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
