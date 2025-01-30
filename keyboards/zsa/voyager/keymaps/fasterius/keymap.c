#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

// QMK custom keycodes
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// Macros
enum custom_keycodes {
  TOGL_LANG = ML_SAFE_RANGE,
  MAC_AA,
  MAC_OSLH,
  MAC_ADIA,
  SEL_ALL,
  REDO,
  UNDO,
  CUT,
  COPY,
  PASTE,
};

// Define custom layer names
enum custom_layers {
    _MAIN,
    _SYMBOLS,
    _NAVIGATION,
    _GAMING,
    _SWEDISH,
};

// Aliases needed for OS-aware macros
#define GENERAL_MODIFIER_KEY_DELAY_MS 20
#define GENERAL_KEY_ACTION_DELAY_MS 50
#define KEY_MODIFIER_ACTION(keycode, modifier) \
    SS_DOWN(modifier) SS_DELAY(GENERAL_MODIFIER_KEY_DELAY_MS) \
    SS_TAP(keycode) SS_DELAY(GENERAL_KEY_ACTION_DELAY_MS) \
    SS_UP(modifier) SS_DELAY(GENERAL_MODIFIER_KEY_DELAY_MS)
#define KEY_LGUI_ACTION(keycode) KEY_MODIFIER_ACTION(keycode, X_LGUI)
#define KEY_LCTL_ACTION(keycode) KEY_MODIFIER_ACTION(keycode, X_LCTL)
#define KEY_SHIFT_LGUI_ACTION(keycode) \
    SS_DOWN(X_LSFT) SS_DELAY(GENERAL_MODIFIER_KEY_DELAY_MS) \
    KEY_LGUI_ACTION(keycode) \
    SS_UP(X_LSFT) SS_DELAY(GENERAL_MODIFIER_KEY_DELAY_MS)
#define KEY_SHIFT_LCTL_ACTION(keycode) \
    SS_DOWN(X_LSFT) SS_DELAY(GENERAL_MODIFIER_KEY_DELAY_MS) \
    KEY_LCTL_ACTION(keycode) \
    SS_UP(X_LSFT) SS_DELAY(GENERAL_MODIFIER_KEY_DELAY_MS)

// Main layer aliases
#define LCTL_A MT(MOD_LCTL, KC_A)
#define LALT_S MT(MOD_LALT, KC_S)
#define LGUI_D MT(MOD_LGUI, KC_D)
#define LSFT_F MT(MOD_LSFT, KC_F)
#define RSFT_J MT(MOD_RSFT, KC_J)
#define LGUI_K MT(MOD_LGUI, KC_K) // RGUI is used by `rcmd` software
#define RALT_L MT(MOD_RALT, KC_L)
#define RCTL_COLN MT(MOD_RCTL, KC_0) // KC_0 is a placeholder
#define NAV_SPACE LT(_NAVIGATION, KC_SPACE)
#define RGUI_TAB MT(MOD_RGUI, KC_TAB)
#define RGUI_BSPC MT(MOD_RGUI, KC_BSPC)
#define SYM_ENTER LT(_SYMBOLS, KC_ENTER)

// Navigation / media / macro layer aliases
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE
#define PAGE_UP KC_PAGE_UP
#define LCTL_STOP MT(MOD_LCTL, KC_MEDIA_STOP)
#define LALT_PREV MT(MOD_LALT, KC_MEDIA_PREV_TRACK)
#define LGUI_NEXT MT(MOD_LGUI, KC_MEDIA_NEXT_TRACK)
#define LSFT_PLAY MT(MOD_LSFT, KC_MEDIA_PLAY_PAUSE)
#define SLEEP KC_SYSTEM_SLEEP

// Gaming layer aliases
#define ALT_TAB MT(MOD_LALT, KC_TAB)

// Swedish layer aliases
#define RCTL_OSLH MT(MOD_RCTL, SE_OSLH)

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT_voyager(
    KC_EQUAL , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,           KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINUS ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,           KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSLS  ,
    KC_ESC   , LCTL_A   , LALT_S   , LGUI_D   , LSFT_F   , KC_G     ,           KC_H     , RSFT_J   , LGUI_K   , RALT_L   , RCTL_COLN, KC_QUOTE ,
    KC_CAPS  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,           KC_N     , KC_M     , KC_COMMA , KC_DOT   , KC_SLASH , CW_TOGG  ,
                                               NAV_SPACE , RGUI_TAB ,           RGUI_BSPC, SYM_ENTER
  ),

  [_SYMBOLS] = LAYOUT_voyager(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,           KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
    _______  , XXXXXXX  , XXXXXXX  , KC_PLUS  , KC_LBRC  , KC_RBRC  ,           XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  ,
    _______  , KC_EQUAL , KC_UNDS  , KC_MINUS , KC_LPRN  , KC_RPRN  ,           XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  ,
    _______  , XXXXXXX  , KC_TILD  , KC_GRAVE , KC_LCBR  , KC_RCBR  ,           XXXXXXX  , XXXXXXX  , _______  , _______  , _______  , _______  ,
                                                _______  , _______  ,           _______  , _______
  ),

  [_NAVIGATION] = LAYOUT_voyager(
    XXXXXXX  , LED_LEVEL, RGB_VAD  , RGB_VAI  , RGB_TOG  , XXXXXXX  ,           XXXXXXX  , DT_DOWN  , DT_UP    , DT_PRNT  , XXXXXXX  , QK_BOOT  ,
    XXXXXXX  , XXXXXXX  , VOL_DOWN , VOL_UP   , MUTE     , XXXXXXX  ,           KC_HOME  , KC_PGDN  , PAGE_UP  , KC_END   , XXXXXXX  , MAC_AA   ,
    SEL_ALL  , LCTL_STOP, LALT_PREV, LGUI_NEXT, LSFT_PLAY, TOGL_LANG,           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , MAC_OSLH , MAC_ADIA ,
    REDO     , UNDO     , CUT      , COPY     , PASTE    , SLEEP    ,           XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
                                                _______  , _______  ,           _______  , _______
  ),

  [_GAMING] = LAYOUT_voyager(
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_LSFT  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_ESC   , KC_A     , KC_S     , KC_D     , KC_F     , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_LCTL  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
                                                _______  , ALT_TAB  ,           _______  , _______
  ),

  [_SWEDISH] = LAYOUT_voyager(
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , SE_AA    ,
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , RCTL_OSLH, SE_ADIA  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,           _______  , _______  , _______  , _______  , _______  , _______  ,
                                                _______  , _______  ,           _______  , _______
  ),

};

// Combos
const uint16_t PROGMEM combo0[] = { KC_EQUAL, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_G, KC_H, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(_GAMING)),
    COMBO(combo1, TG(_SWEDISH)),
};

// Key-specific tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGUI_TAB:
            return TAPPING_TERM -50;
        case RGUI_BSPC:
            return TAPPING_TERM -50;
        default:
            return TAPPING_TERM;
    }
}

// RGB colour configuration
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// HSV (hue, saturation, value) colours
#define WHITE {129, 102, 255}
#define GREEN { 74, 241, 225}
#define BLUE  {148, 255, 147}

// Array for HSV layer layout
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_MAIN] =       { WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE },

    [_SYMBOLS] =    { WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE },

    [_NAVIGATION] = { WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE },

    [_GAMING] =     { GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN },

    [_SWEDISH] =    { BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE },
};

// Function to set layer RGB colours
void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    // Read values from HSV array
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    // Disable RGB if HSV is zero
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    // Convert HSV to RGB and set the LED colours
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  // Check for external processes in control of RGB
  if (rawhid_state.rgb_control) {
    return false;
  }
  // Check if layer LEDs are disabled
  if (keyboard_config.disable_layer_led) {
    return false;
  }
  // Set layer LED colours
  switch (biton32(layer_state)) {
    case _MAIN:
      set_layer_color(_MAIN);
      break;
    case _SYMBOLS:
      set_layer_color(_SYMBOLS);
      break;
    case _NAVIGATION:
      set_layer_color(_NAVIGATION);
      break;
    case _GAMING:
      set_layer_color(_GAMING);
      break;
    case _SWEDISH:
      set_layer_color(_SWEDISH);
      break;
  default:
    // No colours
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

// Handle custom key press behaviours
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Save modifiers and check if Shift is held for RCTL_COLN
  const uint8_t saved_mods = get_mods();
  const bool shifted = (saved_mods | get_oneshot_mods()) & MOD_MASK_SHIFT;

  // Save detected OS for OS-specific macros
  os_variant_t current_os = detected_host_os();

  switch (keycode) {

    // General macros

    case MAC_AA: // Type `å` on MacOS
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_A)));
      }
      break;

    case MAC_ADIA: // Type `ä` on MacOS
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_A));
      }
      break;

    case MAC_OSLH: // Type `ö` on MacOS
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_O));
      }
      break;

    case RCTL_COLN: // RCTL_COLN: RCTL on hold, COLN (:) on tap and SCLN (;) on shifted tap
      if (record->tap.count) {
        if (record->event.pressed) {
          // Clear Shift from modifiers so that the correct keycode can be sent
          del_oneshot_mods(MOD_MASK_SHIFT);
          unregister_mods(MOD_MASK_SHIFT);
          // Tap the applicable key depending on Shift status
          tap_code16(shifted ? KC_SCLN : KC_COLN);
          // Restore the saved mods
          set_mods(saved_mods);
        }
        return false;  // Skip default handling for KC_0 on tap
      }
      break;  // Continue default handling for Ctrl on hold

    // OS-specific macros

    case TOGL_LANG: // [Ctrl/GUI] + Space to toggle input language
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)));
        } else {
          SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        }
      }
      break;

    case SEL_ALL: // Select all
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(KEY_LGUI_ACTION(X_A));
        }
        else {
          SEND_STRING(KEY_LCTL_ACTION(X_A));
        }
      }
      break;

    case UNDO:
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(KEY_LGUI_ACTION(X_Z));
        }
        else {
          SEND_STRING(KEY_LCTL_ACTION(X_Z));
        }
      }
      break;

    case REDO:
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(KEY_SHIFT_LGUI_ACTION(X_Z));
        }
        else {
          SEND_STRING(KEY_SHIFT_LCTL_ACTION(X_Z));
        }
      }
      break;

    case CUT:
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(KEY_LGUI_ACTION(X_X));
        }
        else {
          SEND_STRING(KEY_LCTL_ACTION(X_X));
        }
      }
      break;

    case COPY:
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(KEY_LGUI_ACTION(X_C));
        }
        else {
          SEND_STRING(KEY_LCTL_ACTION(X_C));
        }
      }
      break;

    case PASTE:
      if (record->event.pressed) {
        if (current_os == OS_MACOS || current_os == OS_IOS) {
          SEND_STRING(KEY_LGUI_ACTION(X_V));
        }
        else {
          SEND_STRING(KEY_LCTL_ACTION(X_V));
        }
      }
      break;

  }
  return true;
}
