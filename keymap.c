#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_slovak.h"
#include "process_unicode_common.h"
#include "process_leader.h"
#include "quantum_keycodes.h"
#include "rgb_matrix.h"

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

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_143_132_237,
  HSV_249_212_246,
  HSV_196_179_253,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  VIM_QUIT_MACRO,
  VIM_WRITE_MACRO,
  VIM_WRITE_QUIT_MACRO,
  VIM_ENEW_MACRO,
  VIM_QUIT_ALL_MACRO,
  VIM_SPLIT_MACRO,
  VIM_VSPLIT_MACRO,
  VIM_TABNEW_MACRO,
  SHRUG_MACRO,
  LOOK_MACRO,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

enum layers {
    BASE,
    SYMBOLS,
    NUMLOCK,
    MISC,
    SYSTEM,
    LOWER,
    RANDOM,
    GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       KC_APPLICATION, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    TD(DANCE_0),    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_MEH,                                         KC_HYPR,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,      
    KC_ESCAPE,      MT(MOD_LSFT, KC_A),KC_S,           KC_D,        LT(5,KC_F),           KC_G,           KC_RGUI,                                                                        KC_MEH,         KC_H,           LT(5,KC_J),           KC_K,           KC_L,           MT(MOD_RSFT, KC_SCOLON),KC_QUOTE,       
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,     KC_B,                                           KC_N,           KC_M,     KC_COMMA,       KC_DOT,         TD(DANCE_1),    KC_RSFT,        
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_BSPACE,                                                                                                      KC_DELETE,      KC_DOWN,        KC_UP,          KC_LBRACKET,    KC_RBRACKET,    TO(6),          
    KC_SPACE,       KC_LCTRL,       TD(DANCE_3),                                                                                                    TD(DANCE_2),    OSL(1),         KC_ENTER
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, VIM_QUIT_MACRO,     VIM_WRITE_MACRO,     VIM_ENEW_MACRO,     KC_TRANSPARENT, VIM_TABNEW_MACRO, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_MINUS,       KC_EQUAL,       KC_PIPE,        
    KC_TRANSPARENT, VIM_QUIT_ALL_MACRO,     VIM_SPLIT_MACRO,     KC_TRANSPARENT, LALT(LCTL(KC_F)),KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PIPE,        KC_LPRN,        KC_RPRN,        KC_UNDS,        KC_PLUS,        KC_DQUO,        
    KC_TRANSPARENT, KC_TRANSPARENT, VIM_WRITE_QUIT_MACRO, KC_TRANSPARENT, VIM_VSPLIT_MACRO,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_END,         KC_TRANSPARENT,                                                                                                 TO(0),          KC_PGDOWN,      KC_PGUP,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LALT(KC_SPACE), KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [NUMLOCK] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_EQUAL,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_NUMLOCK,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TO(0),          KC_KP_0,        KC_KP_COMMA,    KC_KP_DOT,      KC_KP_ENTER,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [MISC] = LAYOUT_moonlander(
    TO(4),          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_PSCREEN,     
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_UP,       KC_MS_WH_UP,    KC_TRANSPARENT, KC_CAPSLOCK,                                    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, 
    KC_TRANSPARENT,   KC_MS_WH_LEFT,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT, KC_ASTG,                                                                        KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, RGB_MOD,        RGB_SLD,        TOGGLE_LAYER_COLOR,
    KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 RGB_HUD,        RGB_HUI,        RGB_SAD,        RGB_SAI,        RGB_SPI,        RGB_TOG,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TO(0),          HSV_143_132_237,HSV_249_212_246,HSV_196_179_253,RGB_SPD,        MOON_LED_LEVEL, 
    KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,                     KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [SYSTEM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,                                                                    KC_POWER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [LOWER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_GRV, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_LEAD, 
    LSFT(KC_GRV), KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_LOCK, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPACE,      KC_TRANSPARENT,      KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
  [RANDOM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TO(0),          UC_MOD, UC_RMOD, SK_ACUT,        SK_CARN,        SK_EURO,        
    SHRUG_MACRO, LOOK_MACRO, UC(0x30C4),                 TO(GAME), TO(0),          KC_TRANSPARENT
  ),
  [GAME] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A, KC_TRANSPARENT, KC_TRANSPARENT, KC_F, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_J, KC_TRANSPARENT, KC_TRANSPARENT, KC_SCOLON, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT,        KC_TRANSPARENT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, TO(0),          KC_TRANSPARENT
  ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_SCOLON) {
            tap_code16(KC_CAPS);
        }
        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_Q))));
        }
        SEQ_TWO_KEYS(KC_S, KC_T) {
            SEND_STRING(SS_TAP(X_ESC)SS_RCTL(SS_TAP(X_GRAVE)) SS_DELAY(50) "./startup.sh");
        }

    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = { {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {61,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {61,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {61,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {61,242,207}, {21,210,242}, {61,242,207}, {61,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {15,247,201}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {21,210,242}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {21,210,242}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {61,242,207}, {21,210,242}, {15,247,201}, {15,247,201}, {21,210,242} },

    [SYMBOLS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {76,135,190}, {76,135,190}, {0,0,0}, {0,0,0}, {0,0,0}, {76,135,190}, {76,135,190}, {76,135,190}, {0,0,0}, {0,0,0}, {76,135,190}, {0,0,0}, {0,0,0}, {165,189,219}, {0,0,0}, {0,0,0}, {187,170,199}, {76,135,190}, {165,189,219}, {0,0,0}, {76,135,190}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {125,112,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {30,218,204}, {30,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {30,218,204}, {30,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {30,218,204}, {30,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {19,218,204}, {19,218,204}, {19,218,204}, {165,189,219}, {0,0,0}, {19,218,204}, {19,218,204}, {19,218,204}, {165,189,219}, {0,0,0}, {0,0,0}, {30,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {7,218,204}, {0,0,0}, {7,218,204} },

    [NUMLOCK] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {176,246,213}, {176,246,213}, {176,246,213}, {176,246,213}, {176,246,213}, {176,246,213}, {157,218,204}, {157,218,204}, {157,218,204}, {176,246,213}, {176,246,213}, {157,218,204}, {157,218,204}, {157,218,204}, {176,246,213}, {144,218,204}, {157,218,204}, {157,218,204}, {157,218,204}, {157,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {7,218,204}, {0,0,0}, {7,218,204} },

    [MISC] = { {246,250,219}, {70,119,255}, {70,119,255}, {70,119,255}, {0,0,0}, {183,218,204}, {0,0,0}, {19,218,204}, {0,0,0}, {0,0,0}, {183,218,204}, {19,218,204}, {32,218,204}, {0,0,0}, {0,0,0}, {183,218,204}, {32,218,204}, {32,218,204}, {0,0,0}, {0,0,0}, {183,218,204}, {19,218,204}, {32,218,204}, {0,0,0}, {0,0,0}, {183,218,204}, {0,0,0}, {19,218,204}, {0,0,0}, {183,218,204}, {0,195,224}, {225,218,204}, {32,218,204}, {32,218,204}, {32,218,204}, {0,0,0}, {172,218,204}, {0,0,0}, {139,228,85}, {139,228,85}, {139,228,85}, {183,218,204}, {116,178,230}, {35,12,248}, {169,218,204}, {169,218,204}, {183,218,204}, {116,178,230}, {37,218,255}, {37,218,255}, {196,179,253}, {183,218,204}, {116,178,230}, {0,0,0}, {37,218,255}, {249,212,246}, {183,218,204}, {45,178,230}, {37,218,255}, {37,218,255}, {143,132,237}, {183,218,204}, {45,178,230}, {37,218,255}, {37,218,255}, {183,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {7,218,204}, {0,0,0}, {7,218,204} },

    [SYSTEM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {198,242,207}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {251,255,246}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {137,13,96}, {0,0,0}, {7,218,204}, {0,0,0}, {7,218,204} },

    [LOWER] = { {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,189,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {115,255,255}, {75,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {144,242,207}, {254,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {7,218,204}, {0,0,0}, {7,218,204} },

    [RANDOM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {255,205,255}, {255,255,205}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {178,171,186}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {158,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {158,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {100,255,100}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {200,200,200}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {7,218,204}, {50,255,255}, {7,218,204} },

    [GAME] = { {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {61,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {61,242,207}, {144,242,207}, {1,224,236}, {1,224,236}, {21,210,242}, {61,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {61,242,207}, {21,210,242}, {61,242,207}, {61,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {15,247,201}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {21,210,242}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {21,210,242}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {1,224,236}, {21,210,242}, {43,242,207}, {144,242,207}, {21,210,242}, {21,210,242}, {21,210,242}, {21,210,242}, {61,242,207}, {61,242,207}, {21,210,242}, {15,247,201}, {15,247,201}, {21,210,242} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case BASE:
      set_layer_color(BASE);
      break;
    case SYMBOLS:
      set_layer_color(SYMBOLS);
      break;
    case NUMLOCK:
      set_layer_color(NUMLOCK);
      break;
    case MISC:
      set_layer_color(MISC);
      break;
    case SYSTEM:
      set_layer_color(SYSTEM);
      break;
    case LOWER:
      set_layer_color(LOWER);
      break;
    case RANDOM:
      set_layer_color(RANDOM);
      break;
    case GAME:
      set_layer_color(GAME);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VIM_QUIT_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50) SS_TAP(X_Q) SS_TAP(X_ENTER));

    }
    break;
    case VIM_WRITE_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50) SS_TAP(X_W) SS_TAP(X_ENTER));

    }
    break;
    case VIM_WRITE_QUIT_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50) SS_TAP(X_X) SS_TAP(X_ENTER));

    }
    break;
    case VIM_ENEW_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50)"enew"SS_TAP(X_ENTER));

    }
    break;
    case VIM_QUIT_ALL_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50)"qa"SS_TAP(X_ENTER));

    }
    break;
    case VIM_SPLIT_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50)"split"SS_TAP(X_ENTER));

    }
    break;
    case VIM_VSPLIT_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50)"vsplit"SS_TAP(X_ENTER));

    }
    break;
    case VIM_TABNEW_MACRO:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50)"tabnew"SS_TAP(X_ENTER));

    }
    break;
    case SHRUG_MACRO:
    if (record->event.pressed) {
        send_unicode_string("¯\\_(ツ)_/¯");
    }
    break;
    case LOOK_MACRO:
    if (record->event.pressed) {
        send_unicode_string("ಠ_ಠ");
    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_143_132_237:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(143,132,237);
      }
      return false;
    case HSV_249_212_246:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(249,212,246);
      }
      return false;
    case HSV_196_179_253:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(196,179,253);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(KC_TAB); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_HOLD: register_code16(LSFT(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_HOLD: unregister_code16(LSFT(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_QUES); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
        case DOUBLE_HOLD: register_code16(KC_RCTRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_QUES); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_HOLD: unregister_code16(KC_RCTRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[1].step = 0;
}
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: layer_move(2); break;
        case SINGLE_HOLD: layer_move(3); break;
        case DOUBLE_TAP: layer_move(2); break;
        case DOUBLE_SINGLE_TAP: layer_move(2); break;
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
    }
    dance_state[2].step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LALT);
        tap_code16(KC_LALT);
        tap_code16(KC_LALT);
    }
    if(state->count > 3) {
        tap_code16(KC_LALT);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data){
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_LALT); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_LGUI); break;
        case DOUBLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_SINGLE_TAP: register_code16(KC_LALT); break;
        // case DOUBLE_SINGLE_TAP: tap_code16(KC_LALT); register_code16(KC_LALT); break;
    }
}
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data){
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_LALT); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_LGUI); break;
        case DOUBLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LALT); break;
    }
    dance_state[3].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};

