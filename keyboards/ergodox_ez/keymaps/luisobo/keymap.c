#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


//#include "keymap_german.h"

//#include "keymap_nordic.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

enum {
  TD_SHIFT_CAPS = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
     // left hand
     KC_ESCAPE,        KC_1,         KC_2,     KC_3,           KC_4,         KC_5,     LCTL(LGUI(KC_LEFT)),  
     KC_TAB,           KC_Q,         KC_W,     KC_E,           KC_R,         KC_T,     LCTL(LGUI(KC_UP)),  
     LT(2, KC_QUOTE),  KC_A,         KC_S,     KC_D,           KC_F,         KC_G, 
     TD(TD_SHIFT_CAPS),CTL_T(KC_Z),  KC_X,     KC_C,           KC_V,         KC_B,     LALT(LCTL(KC_LGUI)),  
     LGUI(KC_GRAVE),   KC_TRNS,      KC_TRNS,  LGUI(KC_LEFT),  LALT(KC_LEFT),  
                                                     KC_TRNS,  KC_TRNS,  
                                                               KC_HOME,  
                                           KC_LGUI,  KC_LALT,  KC_END, 

     // right hand
     LCTL(LGUI(KC_RIGHT)), KC_6,           KC_7,     KC_8,     KC_9,   KC_0,               KC_MINUS, 
     KC_TRNS,              KC_Y,           KC_U,     KC_I,     KC_O,   KC_P,               KC_BSLASH,  
                           KC_H,           KC_J,     KC_K,     KC_L,   LT(2, KC_SCOLON),   LT(1, KC_ENTER),  
     KC_TRNS,              KC_N,           KC_M,     KC_COMMA, KC_DOT, RCTL_T(KC_SLASH),   KC_RSHIFT,  
     LALT(KC_RIGHT),       LGUI(KC_RIGHT), KC_TRNS,  KC_TRNS,  KC_TRNS,  
     KC_TRNS,    KC_DELETE,  
     KC_PGUP,
     KC_PGDOWN,  KC_BSPACE,  KC_SPACE),


[SYMB] = LAYOUT_ergodox(
     KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRNS,
     KC_GRAVE,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_UNDS,KC_TRNS,
     KC_TILD,KC_HASH,KC_DLR,KC_LBRACKET,KC_RBRACKET,KC_EQUAL,
     KC_TRNS,KC_PERC,KC_CIRC,KC_LPRN,KC_RPRN,KC_PLUS,KC_TRNS,
     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
     RGB_MOD,KC_TRNS,
     KC_TRNS,
     KC_LGUI,RGB_VAI,KC_TRNS,

     KC_TRNS,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
     KC_TRNS,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,
             KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRNS,
     KC_TRNS,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRNS,
     KC_TRNS,KC_DOT,KC_0,KC_EQUAL,KC_TRNS,
     RGB_TOG,RGB_SLD,
     KC_TRNS,
     KC_TRNS,KC_BSPACE,KC_SPACE),

 [MDIA] = LAYOUT_ergodox(
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,LALT(LCTL(KC_LEFT)),
      KC_TRNS,KC_TRNS,KC_MS_BTN2,KC_MS_UP,KC_MS_BTN1,KC_MS_WH_DOWN,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_UP,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_BTN1,KC_MS_BTN2,
      LCTL(LGUI(KC_UP)),KC_TRNS,
      KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,

      LALT(LCTL(KC_RIGHT)),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
              KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRNS,KC_MEDIA_PLAY_PAUSE,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRNS,KC_TRNS,
      KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,
      KC_TRNS,
      KC_TRNS,KC_TRNS,KC_WWW_BACK),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}
