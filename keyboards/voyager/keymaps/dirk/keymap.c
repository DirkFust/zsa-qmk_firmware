// clang-format off

#include QMK_KEYBOARD_H
#include "print.h"
#include "version.h"
#include "keymap_german.h"
#include "tap_hold_helper.c"
#include "color_helper.c"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  You can use _______ in place for KC_TRANS (transparent)  *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define ____ KC_TRANSPARENT
#define _____ KC_TRANSPARENT
#define ______ KC_TRANSPARENT
#define _______ KC_TRANSPARENT
#define ________ KC_TRANSPARENT
#define _________ KC_TRANSPARENT
#define ___________ KC_TRANSPARENT
#define ____________ KC_TRANSPARENT


#define XXXX KC_NO
#define XXXXX KC_NO
#define XXXXXX KC_NO
#define XXXXXXX KC_NO
#define XXXXXXXX KC_NO
#define XXXXXXXXX KC_NO

#define TAB_LEFT LCTL(LSFT(KC_TAB))
#define TAB_RIGHT LCTL(KC_TAB)
#define CU_HYPR LCTL(LWIN(LALT())

static bool is_umlaut_active = false;
static uint8_t current_layer = 0;

enum custom_keycodes {
    TG_UML= ML_SAFE_RANGE,
    CU_SLASH, // / and backslash
    CU_QUOT,  // " and '
    CU_HASH,  // # ans `
    CU_SS,    // ß
};

enum layers {
    BASE,
    UMLAUT,
    SYM_NUM,
    MOVEMENT,
    MOUSE,
    GAMING,
    FUNCTION,
};


// Feature Caps Words, see https://docs.qmk.fm/#/feature_caps_word
bool caps_word_press_user(uint16_t keycode) {
  // #ifdef CONSOLE_ENABLE
  //   uprintf("caps_word_press_user(): kc: 0x%04X, keycoode: %u\n", keycode, keycode);
  // #endif
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case DE_UDIA:     // ü from german keyboard layout
    case DE_ODIA:     // ö from german keyboard layout
    case DE_ADIA:     // ä from german keyboard layout
    case DE_MINS:     // -_ from german keyboard layout
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case DE_UNDS:
    case TG_UML:
    case DE_SS:
    case CU_SS:
    case KC_LEFT:
    case KC_RIGHT:
    case LT(MOVEMENT, KC_BSPACE):
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_voyager(
        KC_ESCAPE    , KC_Q    , KC_W   , KC_E    , KC_R     , KC_T   ,                              KC_Y       , KC_U      , KC_I    , KC_O   , KC_P   , KC_DEL ,
        TG_UML       , KC_A    , KC_S   , KC_D    , KC_F     , KC_G   ,                              KC_H       , KC_J      , KC_K    , KC_L   , CU_QUOT, CU_HASH,
        CAPS_WORD    , KC_Z    , KC_X   , KC_C    , KC_V     , KC_B   ,                              KC_N       , KC_M      , KC_COMMA, KC_DOT , DE_MINS, DE_PLUS,
        OSL(FUNCTION), CU_SLASH, KC_LALT, KC_LCTRL, KC_LSHIFT, KC_LGUI,                              KC_RGUI    , KC_LSHIFT , KC_LCTRL, KC_LALT, XXXXXXX, XXXXXXX,
                           MT(MOD_LCTL, KC_ENTER), LT(SYM_NUM, KC_TAB),                              LT(MOVEMENT, KC_BSPACE), MT(MOD_LSFT, KC_SPACE)
    ),
    [UMLAUT] = LAYOUT_voyager(
        _______, DE_AT  , _____, DE_EURO, _______, _______,                             _______, DE_UDIA, _______, DE_ODIA, _______, KC_PSCR,
        _______, DE_ADIA, CU_SS, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _____, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _____, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                                          _______, _______,                             _______, _______
    ),
    [SYM_NUM] = LAYOUT_voyager(
        KC_ESCAPE, DE_DLR, DE_SECT, DE_PERC, XXXXXXX, LCAG_T(KC_NO),                        XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_EQUAL , KC_DEL   ,
        DE_TILD  , DE_EQL, DE_EXLM, DE_QUES, DE_LPRN, DE_RPRN      ,                        KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0     , KC_BSPACE   ,
        _______  , DE_DEG, DE_AMPR, DE_PIPE, DE_LCBR, DE_RCBR      ,                        KC_PPLS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS     , XXXXXXX,
        _______  , ______, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC      ,                        DE_COLN, KC_DOT , KC_PAST, KC_COMM, XXXXXXX     , KC_ENTER ,
                                               ______, _______,                             _______, _______
    ),
    [MOVEMENT] = LAYOUT_voyager(
        XXXXXXX, KC_PGUP  , KC_HOME , KC_UP  , KC_END   , XXXXXXX,                 XXXXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, TO(GAMING),
        XXXXXXX, KC_PGDOWN, KC_LEFT , KC_DOWN, KC_RIGHT , XXXXXXX,                 XXXXXXXXX, KC_LSFT, KC_LCTRL, KC_LALT, XXXXXXX, XXXXXXXXX ,
        XXXXXXX, XXXXXXXXX, TAB_LEFT, XXXXXXX, TAB_RIGHT, XXXXXXX,                 XXXXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXXXX ,
        _______, XXXXXXXXX, XXXXXXXX, XXXXXXX, XXXXXXXXX, XXXXXXX,                 XXXXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXXXX ,
                                                 _______, _______,                 _______  , _______
    ),
    [MOUSE] = LAYOUT_voyager(
        XXXXXX, XXXXXX, XXXXXXXXX   , KC_MS_UP    , XXXXXXXXX   , XXXXXXXXX ,                         XXXXXXXXX , XXXXXXXXX    , KC_MS_WH_UP  , XXXXXXXXX     , XXXXXX, XXXXXX,
        XXXXXX, XXXXXX, KC_MS_LEFT  , KC_MS_DOWN  , KC_MS_RIGHT , XXXXXXXXX ,                         XXXXXXXXX , KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, XXXXXX, XXXXXX,
        XXXXXX, XXXXXX, XXXXXXXXX   , XXXXXXXXX   , XXXXXXXXX   , XXXXXXXXX ,                         XXXXXXXXX , XXXXXXXXX    , XXXXXXXXX    , XXXXXXXXX     , XXXXXX, XXXXXX,
        XXXXXX, XXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXXXX ,                         XXXXXXXXX , ____________ , ____________ , ____________  , XXXXXX, XXXXXX,
                                                     XXXXXXXXX  , KC_MS_BTN1,                         KC_MS_BTN2, XXXXXXXXX
    ),
    [GAMING] = LAYOUT_voyager(
        _________, KC_1, KC_2, KC_3, KC_4, KC_5,                                                      KC_6, KC_7, KC_8    , KC_9  , KC_0     , TO(BASE)   ,
        _________, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                      KC_Z, KC_U, KC_I    , KC_O  , KC_P     , KC_LBRACKET,
        _________, KC_A, KC_S, KC_D, KC_F, KC_G,                                                      KC_H, KC_J, KC_K    , KC_L  , KC_SCOLON, KC_QUOTE   ,
        KC_LSHIFT, KC_Y, KC_X, KC_C, KC_V, KC_B,                                                      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH , KC_RSHIFT  ,
                           _________, _________,                                                      _________, _________
    ),
    [FUNCTION] = LAYOUT_voyager(
        ________, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                                            XXXXXX, KC_F1, KC_F2 , KC_F3 , KC_F4 , XXXXXX,
        ________, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                                            XXXXXX, KC_F5, KC_F6 , KC_F7 , KC_F8 , XXXXXX,
        ________, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                                            XXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXX,
        TO(BASE), XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                                            XXXXXX, XXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
                                          ______, ______,                                            ______, _________
    ),
};

/************************************************************************************************************************
 *    COMBOS                                                                                                            *
 * See https://docs.qmk.fm/#/feature_combo                                                                              *
 * !! When new combos are declared, COMBO_COUNT in config.h must be adjusted to the new number! !!                      *
 ************************************************************************************************************************/

// define combo names
enum combos {
    COMBO_TOGGLE_MOUSE,

    COMBO_LSHIFT,
    COMBO_LCTRL,
    COMBO_LALT,
    COMBO_LCTRL_SHIFT,
    COMBO_LCTRL_ALT,
    COMBO_LCTRL_ALT_SHIFT,
    COMBO_LALT_SHIFT,

    COMBO_RSHIFT,
    COMBO_RCTRL,
    COMBO_RALT,
    COMBO_RCTRL_SHIFT,
    COMBO_RCTRL_ALT,
    COMBO_RCTRL_ALT_SHIFT,
    COMBO_RALT_SHIFT,

    // nifty trick to auto-specify how many combos you have
    COMBO_LENGTH
};

// nifty trick continued
uint16_t COMBO_LEN = COMBO_LENGTH;

// define keys that make up combos
// Combos are declared on the keycodes of the base layer (see #define COMBO_ONLY_FROM_LAYER 0 in config.h), so other layers work with them, even if the keys are set to NO_OP
const uint16_t PROGMEM toggle_mouse[] = {LT(MOVEMENT, KC_BSPACE), LT(SYM_NUM, KC_TAB), COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM adf_combo[] = {KC_A, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM asd_combo[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM asdf_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lquot_combo[] = {KC_L, CU_QUOT, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jkquot_combo[] = {KC_J, KC_K, CU_QUOT, COMBO_END};
const uint16_t PROGMEM klquot_combo[] = {KC_K, KC_L, CU_QUOT, COMBO_END};
const uint16_t PROGMEM jklquot_combo[] = {KC_J, KC_K, KC_L, CU_QUOT, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_TOGGLE_MOUSE] = COMBO(toggle_mouse, TG(MOUSE)),

    [COMBO_LSHIFT] = COMBO(df_combo, KC_LSFT),
    [COMBO_LCTRL] = COMBO(sd_combo, KC_LCTL),
    [COMBO_LALT] = COMBO(as_combo, KC_LALT),
    [COMBO_LCTRL_SHIFT] = COMBO(sdf_combo, LCTL(KC_LSFT)),
    [COMBO_LCTRL_ALT] = COMBO(asd_combo, LCTL(KC_LALT)),
    [COMBO_LALT_SHIFT] = COMBO(adf_combo, LALT(KC_LSFT)),
    [COMBO_LCTRL_ALT_SHIFT] = COMBO(asdf_combo, LCTL(LALT(KC_LSFT))),

    [COMBO_RSHIFT] = COMBO(jk_combo, KC_LSFT),
    [COMBO_RCTRL] = COMBO(kl_combo, KC_LCTL),
    [COMBO_RALT] = COMBO(lquot_combo, KC_LALT),
    [COMBO_RCTRL_SHIFT] = COMBO(jkl_combo,  LCTL(KC_LSFT)),
    [COMBO_RCTRL_ALT] = COMBO(klquot_combo, LCTL(KC_LALT)),
    [COMBO_RALT_SHIFT] = COMBO(klquot_combo, LALT(KC_LSFT)),
    [COMBO_RCTRL_ALT_SHIFT] = COMBO(jklquot_combo, LCTL(LALT(KC_LSFT))),

};

// Set tapping term per key (https://docs.qmk.fm/#/tap_hold?id=tapping-term)
// A key counts as HOLD if held longer than TAPPING_TERM, as TAP/DOUBLE TAP if shorter
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return TAPPING_TERM;
}

// extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();

    rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
    defer_exec(5000, change_led_effect_heatmap_callback, NULL);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t new_layer = get_highest_layer(state);

    if (current_layer != new_layer) {
        switch (new_layer) {
        case SYM_NUM:
            #ifdef CONSOLE_ENABLE
              print("layer: SYM_NUM\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);
            break;
        case MOVEMENT:
            #ifdef CONSOLE_ENABLE
              print("layer: MOVEMENT\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_BLUE);
            break;
        case MOUSE:
            #ifdef CONSOLE_ENABLE
              print("layer: MOUSE\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_RED);
            break;
        case BASE:
            #ifdef CONSOLE_ENABLE
              print("layer: BASE\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            break;
        case GAMING:
            #ifdef CONSOLE_ENABLE
                print("layer: GAMING\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_overwatch);
            break;
        case FUNCTION:
            #ifdef CONSOLE_ENABLE
              print("layer: FUNCTION\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GOLD);
            break;
        default:
            #ifdef CONSOLE_ENABLE
              print("layer: DEFAULT\n");
            #endif
            rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            break;
        }
        current_layer = new_layer;
    }

    return state;
}

/* This function handles custom keycodes and is called in
 * the "real" process_record_user() callback
 */
bool process_record_user_keys(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
    case CU_SLASH:
        return key_and_shift(DE_SLSH, DE_BSLS, record); // slash and backslash
    case CU_QUOT:
        return key_and_shift(DE_DQUO, DE_QUOT, record); // " and '
    case CU_HASH:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                tap_code16(DE_ACUT);
                tap_code16(KC_SPACE);
            } else {
                tap_code16(DE_HASH);
            }
        }
        return true;
    case CU_SS:
        if (record->event.pressed) {
            uint8_t mod_state = get_mods();
            del_mods(mod_state);
            tap_code16(DE_SS);
            set_mods(mod_state);
        }
        return true;
    // case CC_Q:
    //     return controlify_on_hold(KC_Q, record);
}
return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // #ifdef CONSOLE_ENABLE
    //     uprintf("process_record_user(): KL: kc: 0x%04X, keycode: %u, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    // #endif

    // handle custom "umlaut" one shot layer activation
    if (!is_umlaut_active && keycode == TG_UML && record->event.pressed) {
        is_umlaut_active = true;
        layer_on(UMLAUT);
    }

    // handle keypresses
    bool result = process_record_user_keys(keycode, record);

    // handle custom "umlaut" one shot layer deactivation
    if (is_umlaut_active && keycode != TG_UML && !record->event.pressed) {
        is_umlaut_active = false;
        layer_off(UMLAUT);
    }

    return result;
}
