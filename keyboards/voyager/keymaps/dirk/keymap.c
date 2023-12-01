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

#define XXXX KC_NO
#define XXXXX KC_NO
#define XXXXXX KC_NO
#define XXXXXXX KC_NO
#define XXXXXXXX KC_NO
#define XXXXXXXXX KC_NO

#define CC_Q LT(BASE, KC_Q)
#define CC_W LT(BASE, KC_W)
#define CC_E LT(BASE, KC_E)
#define CC_R LT(BASE, KC_R)
#define CC_T LT(BASE, KC_T)
#define CC_Z LT(BASE, KC_Z)
#define CC_U LT(BASE, KC_U)
#define CC_I LT(BASE, KC_I)
#define CC_O LT(BASE, KC_O)
#define CC_P LT(BASE, KC_P)
#define CC_A LT(BASE, KC_A)
#define CC_S LT(BASE, KC_S)
#define CC_D LT(BASE, KC_D)
#define CC_F LT(BASE, KC_F)
#define CC_G LT(BASE, KC_G)
#define CC_H LT(BASE, KC_H)
#define CC_J LT(BASE, KC_J)
#define CC_K LT(BASE, KC_K)
#define CC_L LT(BASE, KC_L)
#define CC_Y LT(BASE, KC_Y)
#define CC_X LT(BASE, KC_X)
#define CC_C LT(BASE, KC_C)
#define CC_V LT(BASE, KC_V)
#define CC_B LT(BASE, KC_B)
#define CC_N LT(BASE, KC_N)
#define CC_M LT(BASE, KC_M)
#define CC_HASH LT(BASE, KC_NUHS)
// #define TG_UML OSL(UMLAUT)
#define TAB_LEFT LCTL(LSFT(KC_TAB))
#define TAB_RIGHT LCTL(KC_TAB)

static uint8_t is_oneshot_active = 0;

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    MACRO_AE,
    MACRO_SS,
    MACRO_UE,
    MACRO_OE,
    MACRO_PARA,
    DE_LSPO,
    DE_RSPC,
    TG_UML,
};

enum layers {
    BASE,
    UMLAUT,
    SYM_NUM,
    MOVEMENT,
    MOUSE,
    GAMING,

};

enum tap_dance_codes {
    TD_TAB,
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
    case DE_SS:       // ß
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case DE_UNDS:
    case TG_UML:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_voyager(
        KC_ESCAPE, CC_Q, CC_W   , CC_E    , CC_R   , CC_T,                                  CC_Y, CC_U   , CC_I    , CC_O   , CC_P   , KC_DEL ,
        CAPS_WORD, CC_A, CC_S   , CC_D    , CC_F   , CC_G,                                  CC_H, CC_J   , CC_K    , CC_L   , KC_DQUO, CC_HASH,
        TG_UML   , CC_Z, CC_X   , CC_C    , CC_V   , CC_B,                                  CC_N, CC_M   , KC_COMMA, KC_DOT , DE_MINS, DE_PLUS,
        KC_SLASH , DE_ADIA, KC_LALT, KC_LCTRL, KC_LGUI, ____,                               XXXX, KC_RGUI, KC_RCTRL, KC_RALT, XXXXXXX, XXXXXXX,
              MT(MOD_LCTL, KC_ENTER), LT(SYM_NUM, KC_TAB),                                  LT(MOVEMENT, KC_BSPACE), MT(MOD_LSFT, KC_SPACE)
    ),
    [UMLAUT] = LAYOUT_voyager(
        _______, _______, _____, _______, _______, _______,                             _______, DE_UDIA, _______, DE_ODIA, _______, _______,
        _______, DE_ADIA, DE_SS, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _____, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _____, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                                          _______, _______,                             _______, _______
    ),
    [SYM_NUM] = LAYOUT_voyager(
        KC_ESCAPE, KC_F1  , KC_F2  , KC_F3  , KC_F4      , KC_F5      ,                              KC_F6    , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11   ,
        KC_GRAVE , KC_AT  , KC_EXLM, KC_PERC, KC_LPRN    , KC_RPRN    ,                              KC_MINUS , KC_KP_7, KC_KP_8, KC_KP_9, KC_SLASH, KC_F12   ,
        KC_TILD  , KC_QUES, KC_AMPR, KC_PIPE, KC_LCBR    , KC_RCBR    ,                              KC_PLUS  , KC_KP_4, KC_KP_5, KC_KP_6, KC_ASTR , KC_BSPACE,
        XXXXXXXXX, KC_DLR , KC_LABK, KC_RABK, KC_LBRACKET, KC_RBRACKET,                              KC_DOT   , KC_KP_1, KC_KP_2, KC_KP_3, KC_EQUAL, KC_ENTER ,
                                              _______    , _______    ,                              _______,   KC_KP_0
    ),
    [MOVEMENT] = LAYOUT_voyager(
        XXXXXXX, KC_PGUP  , KC_HOME , KC_UP  , KC_END   , XXXXXXX,                 XXXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(GAMING),
        XXXXXXX, KC_PGDOWN, KC_LEFT , KC_DOWN, KC_RIGHT , XXXXXXX,                 XXXXXXXXX, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXXXX ,
        XXXXXXX, XXXXXXXXX, TAB_LEFT, XXXXXXX, TAB_RIGHT, XXXXXXX,                 XXXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXXXX ,
        XXXXXXX, XXXXXXXXX, XXXXXXXX, XXXXXXX, XXXXXXXXX, XXXXXXX,                 XXXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXXXX ,
                                                 _______  , _______,                 _______  , _______
    ),
    [MOUSE] = LAYOUT_voyager(
        XXXXXX, XXXXXX, XXXXXXXXX , KC_MS_UP  , XXXXXXXXX  , XXXXXXXXX ,                         XXXXXXXXX , XXXXXXXXX    , KC_MS_WH_UP  , XXXXXXXXX     , XXXXXX, XXXXXX,
        XXXXXX, XXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXXXX ,                         XXXXXXXXX , KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, XXXXXX, XXXXXX,
        XXXXXX, XXXXXX, XXXXXXXXX , XXXXXXXXX , XXXXXXXXX  , XXXXXXXXX ,                         XXXXXXXXX , XXXXXXXXX    , XXXXXXXXX    , XXXXXXXXX     , XXXXXX, XXXXXX,
        XXXXXX, XXXXXX, XXXXXXXXX , XXXXXXXXX , XXXXXXXXX  , XXXXXXXXX ,                         XXXXXXXXX , XXXXXXXXX    , XXXXXXXXX    , XXXXXXXXX     , XXXXXX, XXXXXX,
                                                XXXXXXXXX  , KC_MS_BTN1,                         KC_MS_BTN2, XXXXXXXXX
    ),
    [GAMING] = LAYOUT_voyager(
        _________, KC_1, KC_2, KC_3, KC_4, KC_5,                                                      KC_6, KC_7, KC_8    , KC_9  , KC_0     , TO(BASE)   ,
        _________, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                      KC_Z, KC_U, KC_I    , KC_O  , KC_P     , KC_LBRACKET,
        _________, KC_A, KC_S, KC_D, KC_F, KC_G,                                                      KC_H, KC_J, KC_K    , KC_L  , KC_SCOLON, KC_QUOTE   ,
        KC_LSHIFT, KC_Y, KC_X, KC_C, KC_V, KC_B,                                                      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH , KC_RSHIFT  ,
                           _________, _________,                                                      _________, _________
    ),
};

/************************************************************************************************************************
 *    COMBOS                                                                                                            *
 * See https://docs.qmk.fm/#/feature_combo                                                                              *
 * !! When new combos are declared, COMBO_COUNT in config.h must be adjusted to the new number! !!                      *
 ************************************************************************************************************************/

// Combos are declared on the keycodes of the base layer (see #define COMBO_ONLY_FROM_LAYER 0 in config.h), so other layers work with them, even if the keys are set to NO_OP
const uint16_t PROGMEM enter_mouse[] = {LT(MOVEMENT, KC_BSPACE), LT(SYM_NUM, KC_TAB), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(enter_mouse, TG(MOUSE)),
};

// Set tapping term per key (https://docs.qmk.fm/#/tap_hold?id=tapping-term)
// A key counts as HOLD if held longer than TAPPING_TERM, as TAP/DOUBLE TAP if shorter
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CC_Q:
        case CC_W:
        case CC_E:
        case CC_R:
        case CC_T:
        case CC_Z:
        case CC_U:
        case CC_I:
        case CC_O:
        case CC_P:
        case CC_A:
        case CC_S:
        case CC_D:
        case CC_F:
        case CC_G:
        case CC_H:
        case CC_J:
        case CC_K:
        case CC_L:
        case CC_Y:
        case CC_X:
        // case CC_C:
        case CC_V:
        case CC_B:
        case CC_N:
        case CC_M:
        case CC_HASH:
            // Make all holds but copy (KC_C) slower
            return TAPPING_TERM * 1.25;
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
    if (is_oneshot_active > 0) is_oneshot_active++;
    if (keycode != TG_UML && !record->event.pressed && is_oneshot_active > 1) {
        is_oneshot_active = 0;
        layer_off(UMLAUT);
    }

    switch (keycode) {
        case TG_UML:
            is_oneshot_active = 1;
            layer_on(UMLAUT);
        case CC_Q:
            return controlify_on_hold(KC_Q, record);
        case CC_W:
            return controlify_on_hold(KC_W, record);
        case CC_E:
            return controlify_on_hold(KC_E, record);
        case CC_R:
            return controlify_on_hold(KC_R, record);
        case CC_T:
            return controlify_on_hold(KC_T, record);
        case CC_Z:
            return controlify_on_hold(KC_Z, record);
        case CC_U:
            return controlify_on_hold(KC_U, record);
        case CC_I:
            return controlify_on_hold(KC_I, record);
        case CC_O:
            return controlify_on_hold(KC_O, record);
        case CC_P:
            return controlify_on_hold(KC_P, record);
        case CC_A:
            return controlify_on_hold(KC_A, record);
        case CC_S:
            return controlify_on_hold(KC_S, record);
        case CC_D:
            return controlify_on_hold(KC_D, record);
        case CC_F:
            return controlify_on_hold(KC_F, record);
        case CC_G:
            return controlify_on_hold(KC_G, record);
        case CC_H:
            return controlify_on_hold(KC_H, record);
        case CC_J:
            return controlify_on_hold(KC_J, record);
        case CC_K:
            return controlify_on_hold(KC_K, record);
        case CC_L:
            return controlify_on_hold(KC_L, record);
        case CC_Y:
            return controlify_on_hold(KC_Y, record);
        case CC_X:
            return controlify_on_hold(KC_X, record);
        case CC_C:
            return controlify_on_hold(KC_C, record);
        case CC_V:
            return controlify_on_hold(KC_V, record);
        case CC_B:
            return controlify_on_hold(KC_B, record);
        case CC_N:
            return controlify_on_hold(KC_N, record);
        case CC_M:
            return controlify_on_hold(KC_M, record);
        case CC_HASH:
            return controlify_on_hold(KC_NUHS, record);
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // [CC_Q]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    // [CC_W]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    // [CC_E]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    // [CC_R]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    // [CC_T]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    // [CC_A]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    // [CC_S]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    // [CC_D]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    // [CC_F]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    // [CC_G]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
    // [CC_Y]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
    // [CC_X]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
    // [CC_C]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
    // [CC_V]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
    // [CC_B]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
    // [TD_TAB]  = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
    // [CC_Z]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
    // [CC_U]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
    // [CC_I]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
    // [CC_O]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
    // [CC_P]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
    // [CC_H]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
    // [CC_J]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
    // [CC_K]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
    // [CC_L]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
    // [CC_HASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
    // [CC_N]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
    // [CC_M]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
};
