// clang-format off

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#include "controlify_tap_dances.c"

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

#define _________ KC_TRANSPARENT

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    MACRO_AE,
    MACRO_SS,
    MACRO_UE,
    MACRO_OE,
    MACRO_PARA,
    DE_LSPO,
    DE_RSPC,
};

enum layers {
    BASE,
    UMLAUT,
    SYMBOLS_NUMBERS,
    MOVEMENT,
    MOUSE,
    GAMING,

};

enum tap_dance_codes {
    CC_Q,
    CC_W,
    CC_E,
    CC_R,
    CC_T,
    CC_A,
    CC_S,
    CC_D,
    CC_F,
    CC_G,
    CC_Y,
    CC_X,
    CC_C,
    CC_V,
    CC_B,
    CC_Z,
    CC_U,
    CC_I,
    CC_O,
    CC_P,
    CC_H,
    CC_J,
    CC_K,
    CC_L,
    CC_HASH,
    CC_N,
    CC_M,
    TD_TAB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_voyager(
        KC_ESCAPE, TD(CC_Q), TD(CC_W), TD(CC_E), TD(CC_R), TD(CC_T),                                  TD(CC_Z)   , TD(CC_U)  , TD(CC_I), TD(CC_O), TD(CC_P), KC_DEL      ,
        CAPS_WORD, TD(CC_A), TD(CC_S), TD(CC_D), TD(CC_F), TD(CC_G),                                  TD(CC_H)   , TD(CC_J)  , TD(CC_K), TD(CC_L), KC_DQUO , TD(CC_HASH) ,
        OSL(1)   , TD(CC_Y), TD(CC_X), TD(CC_C), TD(CC_V), TD(CC_B),                                  TD(CC_N)   , TD(CC_M)  , KC_COMMA, KC_DOT  , KC_MINUS, KC_PLUS     ,
        KC_SLASH, _________, KC_LALT , KC_LCTRL, KC_LGUI, _________,                                  _________  , KC_RGUI   , KC_RCTRL, KC_RALT, _________, _________   ,
                MT(MOD_LCTL, KC_ENTER), LT(SYMBOLS_NUMBERS, KC_TAB),                                  LT(MOVEMENT, KC_BSPACE), MT(MOD_LSFT, KC_SPACE)
    ),
    [UMLAUT] = LAYOUT_voyager(
        _________, _________, _________, _________, _________, _________,                             _________, _________, _________, _________, _________, _________,
        _________, _________, _________, _________, _________, _________,                             _________, MACRO_UE , _________, MACRO_OE , _________, _________,
        _________, MACRO_AE , MACRO_SS , _________, _________, _________,                             _________, _________, _________, _________, _________, _________,
        _________, _________, _________, _________, _________, _________,                             _________, _________, _________, _________, _________, _________,
                                                    _________, _________,                             _________, _________
    ),
    [SYMBOLS_NUMBERS] = LAYOUT_voyager(
        KC_ESCAPE , KC_F1  , KC_F2  , KC_F3  , KC_F4      , KC_F5      ,                              KC_F6    , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11   ,
        KC_GRAVE  , KC_AT  , KC_EXLM, KC_PERC, KC_LPRN    , KC_RPRN    ,                              KC_MINUS , KC_KP_7, KC_KP_8, KC_KP_9, KC_SLASH, KC_F12   ,
        KC_TILD   , KC_QUES, KC_AMPR, KC_PIPE, KC_LCBR    , KC_RCBR    ,                              KC_PLUS  , KC_KP_4, KC_KP_5, KC_KP_6, KC_ASTR , KC_BSPACE,
        MACRO_PARA, KC_DLR , KC_LABK, KC_RABK, KC_LBRACKET, KC_RBRACKET,                              KC_DOT   , KC_KP_1, KC_KP_2, KC_KP_3, KC_EQUAL, KC_ENTER ,
                                               _________  , _________  ,                              _________, KC_KP_0
    ),
    [MOVEMENT] = LAYOUT_voyager(
        _________, _________, _________, _________         , _________   , _________,                 _________, _________, _________, _________, _________, TO(GAMING),
        _________, KC_PGUP  , KC_HOME  , KC_UP             , KC_END      , _________,                 _________, KC_LALT  , _________, _________, _________, _________ ,
        _________, KC_PGDOWN, KC_LEFT  , KC_DOWN           , KC_RIGHT    , _________,                 _________, _________, _________, _________, _________, _________ ,
        _________, _________, _________, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), _________,                 _________, _________, _________, _________, _________, _________ ,
                                                            _________    , _________,                 _________, _________
    ),
    [MOUSE] = LAYOUT_voyager(
        _________, _________, _________, _________ , _________  , _________ ,                         _________ , _________    , _________    , _________     , _________, TO(BASE) ,
        _________, _________, _________, KC_MS_UP  , _________  , _________ ,                         _________ , _________    , KC_MS_WH_UP  , _________     , _________, _________,
        _________, _________, KC_MS_LEFT,KC_MS_DOWN, KC_MS_RIGHT, _________ ,                         _________ , KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _________, _________,
        _________, _________, _________, _________ , _________  , _________ ,                         _________ , _________    , _________    , _________     , _________, _________,
                                                    _________  , KC_MS_BTN1,                          KC_MS_BTN2, _________
    ),
    [GAMING] = LAYOUT_voyager(
        _________, KC_1, KC_2, KC_3, KC_4, KC_5,                                                      KC_6, KC_7, KC_8    , KC_9  , KC_0     , TO(BASE)   ,
        _________, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                      KC_Z, KC_U, KC_I    , KC_O  , KC_P     , KC_LBRACKET,
        _________, KC_A, KC_S, KC_D, KC_F, KC_G,                                                      KC_H, KC_J, KC_K    , KC_L  , KC_SCOLON, KC_QUOTE   ,
        KC_LSHIFT, KC_Y, KC_X, KC_C, KC_V, KC_B,                                                      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH , KC_RSHIFT  ,
                           _________, _________,                                                      _________, _________
    ),
};

const uint16_t PROGMEM combo0[] = {LT(MOVEMENT, KC_BSPACE), LT(SYMBOLS_NUMBERS, KC_TAB), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TO(MOUSE)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(CC_Q):
        case TD(CC_W):
        case TD(CC_E):
        case TD(CC_R):
        case TD(CC_T):
        case TD(CC_A):
        case TD(CC_S):
        case TD(CC_D):
        case TD(CC_F):
        case TD(CC_G):
        case TD(CC_Y):
        case TD(CC_X):
        case TD(CC_C):
        case TD(CC_V):
        case TD(CC_B):
        case TD(CC_Z):
        case TD(CC_U):
        case TD(CC_I):
        case TD(CC_O):
        case TD(CC_P):
        case TD(CC_H):
        case TD(CC_J):
        case TD(CC_K):
        case TD(CC_L):
        case TD(CC_HASH):
        case TD(CC_N):
        case TD(CC_M):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [2] = {{74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}},

    [3] = {{169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}},

    [4] = {{0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {74, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}},

    [5] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}, {41, 255, 255}, {74, 255, 255}, {41, 255, 255}, {169, 255, 255}, {0, 0, 0}, {0, 0, 0}, {74, 255, 255}, {74, 255, 255}, {74, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {169, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 119}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_AE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_2)));
            }
            break;
        case MACRO_SS:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_5)));
            }
            break;
        case MACRO_UE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_9)));
            }
            break;
        case MACRO_OE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8)));
            }
            break;
        case MACRO_PARA:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_1)));
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





qk_tap_dance_action_t tap_dance_actions[] = {
    [CC_Q]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [CC_W]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [CC_E]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [CC_R]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [CC_T]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [CC_A]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [CC_S]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    [CC_D]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [CC_F]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    [CC_G]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
    [CC_Y]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
    [CC_X]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
    [CC_C]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
    [CC_V]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
    [CC_B]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
    [TD_TAB]  = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
    [CC_Z]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
    [CC_U]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
    [CC_I]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
    [CC_O]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
    [CC_P]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
    [CC_H]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
    [CC_J]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
    [CC_K]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
    [CC_L]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
    [CC_HASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
    [CC_N]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
    [CC_M]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
};
