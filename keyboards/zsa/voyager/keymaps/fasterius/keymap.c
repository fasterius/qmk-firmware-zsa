#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  CTL_SPC,
  MAC_AA,
  MAC_OSLH,
  MAC_ADIA,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
};

// Define custom key names for layout readability
// Main layer:
#define LCTL_A MT(MOD_LCTL, KC_A)
#define LALT_S MT(MOD_LALT, KC_S)
#define LGUI_D MT(MOD_LGUI, KC_D)
#define LSFT_F MT(MOD_LSFT, KC_F)
#define RSFT_J MT(MOD_RSFT, KC_J)
#define RGUI_K MT(MOD_RGUI, KC_K)
#define RALT_L MT(MOD_RALT, KC_L)
#define RCTL_CLON TD(DANCE_0)
#define L2_SPACE LT(2, KC_SPACE)
#define MEH_TAB MEH_T(KC_TAB)
#define MEH_BSPC MEH_T(KC_BSPC)
#define L1_ENTER LT(1, KC_ENTER)
// Navigation / media / macro layer
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE
#define PAGE_UP KC_PAGE_UP
#define LCTL_STOP MT(MOD_LCTL, KC_MEDIA_STOP)
#define LALT_PREV MT(MOD_LALT, KC_MEDIA_PREV_TRACK)
#define LGUI_NEXT MT(MOD_LGUI, KC_MEDIA_NEXT_TRACK)
#define LSFT_PLAY MT(MOD_LSFT, KC_MEDIA_PLAY_PAUSE)
#define SEL_ALL LGUI(KC_A)
#define REDO LGUI(LSFT(KC_Z))
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
// Gaming layer
#define ALT_TAB MT(MOD_LALT, KC_TAB)
// Swedish layer
#define RCTL_OSLH MT(MOD_RCTL, MAC_OSLH)

// Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Main layer
  [0] = LAYOUT_voyager(
    KC_EQUAL , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,           KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINUS ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,           KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSLS  ,
    KC_ESC   , LCTL_A   , LALT_S   , LGUI_D   , LSFT_F   , KC_G     ,           KC_H     , RSFT_J   , RGUI_K   , RALT_L   , RCTL_CLON, KC_QUOTE ,
    KC_CAPS  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,           KC_N     , KC_M     , KC_COMMA , KC_DOT   , KC_SLASH , CW_TOGG  ,
                                               L2_SPACE  , MEH_TAB  ,           MEH_BSPC , L1_ENTER
  ),

  // Symbols layer
  [1] = LAYOUT_voyager(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,           KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
    _______  , KC_NO    , KC_NO    , KC_PLUS  , KC_LBRC  , KC_RBRC  ,           KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______  ,
    _______  , KC_EQUAL , KC_UNDS  , KC_MINUS , KC_LPRN  , KC_RPRN  ,           KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_SCLN  , _______  ,
    _______  , KC_NO    , KC_TILD  , KC_GRAVE , KC_LCBR  , KC_RCBR  ,           KC_NO    , KC_NO    , _______  , _______  , _______  , _______  ,
                                                _______  , _______  ,           _______  , _______
  ),

  // Navigation / media / macro layer
  [2] = LAYOUT_voyager(
    KC_NO    , LED_LEVEL, RGB_VAD  , RGB_VAI  , RGB_TOG  , KC_NO    ,           KC_NO    , KC_NO    , KC_NO   , KC_NO    , KC_NO     , QK_BOOT  ,
    KC_NO    , KC_NO    , VOL_DOWN , VOL_UP   , MUTE     , KC_NO    ,           KC_HOME  , KC_PGDN  , PAGE_UP , KC_END   , KC_NO     , MAC_AA   ,
    SEL_ALL  , LCTL_STOP, LALT_PREV, LGUI_NEXT, LSFT_PLAY, CTL_SPC  ,           KC_LEFT  , KC_DOWN  , KC_UP   , KC_RIGHT , MAC_OSLH  , MAC_ADIA ,
    REDO     , UNDO     , CUT      , COPY     , PASTE    , KC_F19   ,           KC_NO    , KC_NO    , KC_NO   , KC_NO    , KC_NO     , KC_NO    ,
                                                _______  , _______  ,           _______  , _______
  ),

  // Gaming layer
  [3] = LAYOUT_voyager(
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_LSFT  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_ESC   , KC_A     , KC_S     , KC_D     , KC_F     , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_LCTL  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
                                                _______  , ALT_TAB  ,           _______  , _______
  ),

  // Swedish layer
  [4] = LAYOUT_voyager(
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , SE_AA    ,
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , RCTL_OSLH, SE_ADIA  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
                                                _______  , _______  ,           _______  , _______
  ),

};

const uint16_t PROGMEM combo0[] = { KC_EQUAL, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_G, KC_H, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(3)),
    COMBO(combo1, TG(4)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MEH_T(KC_TAB):
            return TAPPING_TERM -50;
        case MEH_T(KC_BSPC):
            return TAPPING_TERM -50;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255} },

    [1] = { {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255} },

    [2] = { {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255}, {129,102,255} },

    [3] = { {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225}, {74,241,225} },

    [4] = { {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147}, {148,255,147} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTL_SPC:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)));
    }
    break;
    case MAC_AA:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_A)));
    }
    break;
    case MAC_OSLH:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case MAC_ADIA:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_A));
    }
    break;

    case TD(DANCE_0):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_RIGHT_CTRL),
};
