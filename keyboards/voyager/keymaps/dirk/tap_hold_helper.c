// Define the tap-value and the shifted value for a key
bool key_and_shift(uint16_t keycode, uint16_t keycode_shifted, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            tap_code16(keycode_shifted);
            set_mods(mod_state);
        } else {
            tap_code16(keycode);
        }
    }
    return true;
}

// Used in process_record_user() to provide ctrl+<key> on hold, <key> on tap
// Tap/hold logic works only on basic keycodes (https://docs.qmk.fm/#/keycodes_basic)
bool controlify_on_hold(uint16_t keycode, keyrecord_t *record) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(C(keycode)); // Intercept hold function to send Ctrl+<KEYCODE>. Other modifiers (Shift, Alt) are applied
        return false;
    }
    return true; // Return true for normal processing of tap keycode
}

// Used in process_record_user() to provide <key1> on tap, <key2> on hold.
// Tap/hold logic works only on basic keycodes (https://docs.qmk.fm/#/keycodes_basic)
bool tap_or_hold(uint16_t keycode_tap, uint16_t keycode_hold, keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        tap_code16(keycode_tap); // Intercept tap function to send [keycode_tap]
    } else if (record->event.pressed) {
        tap_code16(keycode_hold); // Intercept hold function to send [keycode_hold]
    }
    return false;
}

// Produces hash (#) on tap, ctrl+# on hold, backtick(`) on shift as a "normal character", not as a dead key and accent-modifier
bool hash_tap_hold_shift(keyrecord_t *record) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(C(DE_HASH)); // Intercept hold function to send Ctrl+<KEYCODE>. Other modifiers (Shift, Alt) are applied
        return false;
    }

    uint8_t mod_state = get_mods();
    if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            tap_code16(DE_HASH);
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_3) SS_TAP(X_KP_5)));
        }
    }
    return true;
}
