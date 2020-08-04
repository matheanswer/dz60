#include QMK_KEYBOARD_H

/*
Physical layout
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
│10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
│20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
│30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3d    │3e │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┤
│40  │41  │43  │46                      │4a │4b │4c │4d │4e │
└────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┘

QMK standard arrangement "LAYOUT"
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
│10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
│20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │
├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
│30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3d    │3e │
├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬┴──┬───┼───┤
│40  │41  │43  │44      │46  │48        │4a │4b │4c │4d │4e │
└────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘

31, 44 and 48 aren't used so leave blank with keycode XXXXXXX (or KC_NO)
*/

#define _BL 0
#define _FL 1
#define _CL 2


enum custom_keycodes {
  VOL_UP = SAFE_RANGE,
  VOL_DN,
  EMAIL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VOL_UP:
      if (record->event.pressed) {
        // when keycode VOL_UP is pressed
        tap_code(KC_VOLU);
        tap_code(KC_VOLU);
        tap_code(KC_VOLU);
        tap_code(KC_VOLU);
        tap_code(KC_VOLU);
      } else {
        // when keycode VOL_UP is released
      }
      break;
    case VOL_DN:
      if (record->event.pressed) {
        // when keycode VOL_DN is pressed
        tap_code(KC_VOLD);
        tap_code(KC_VOLD);
        tap_code(KC_VOLD);
        tap_code(KC_VOLD);
        tap_code(KC_VOLD);
      } else {
        // when keycode VOL_DN is released
      }
      break;
    case EMAIL:
      if (record->event.pressed) {
           // when keycode EMAIL is pressed
                SEND_STRING("mathias.heyraud@gmail.com");
      } else {
        // when keycode EMAIL is released
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// Keymap _BL: Base Layer (Default Layer)
     [_BL] = LAYOUT(
		KC_GESC,  KC_1,     KC_2,     KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,
		KC_TAB,   KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRC,	KC_RBRC,	KC_BSPC,
		KC_LCTL,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOT,	KC_ENT,
		KC_LSFT,	XXXXXXX,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSFT,	KC_DEL,
		MO(_FL),	KC_LGUI,	KC_RALT,	XXXXXXX,	KC_SPC,	XXXXXXX,	KC_LALT,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT),

     // Keymap _FL: Function Layer
	[_FL] = LAYOUT(
		TO(_CL),  KC_F1,    KC_F2,    KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_F7,	KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  _______,  _______,  _______,
		KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
	     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  VOL_DN,   VOL_UP,   _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END),

     // Keymap _CL: Control Layer
	[_CL] = LAYOUT(
		TG(_CL),  RGB_MOD,  RGB_RMOD, RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  EEP_RST,  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______),
		
};


// // Underglow color depending on layer
// layer_state_t layer_state_set_user(layer_state_t state) {
//      switch (get_highest_layer(state)) {

//      case _CL:
//           rgblight_enable_noeeprom();
//           rgblight_setrgb (RGB_GREEN);
//           break;
//      case _FL:
//           rgblight_enable_noeeprom();
//           rgblight_setrgb (RGB_BLUE);
//           break;
//      default: //  for any other layers, or the default layer
//           rgblight_disable_noeeprom();
//           break;
//      }
//      return state;
// }
