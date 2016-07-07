// Norwegian/Nordic planck layout

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _L3 3
#define _ADJUST 16

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define L3 M(_L3)
#define M_BL 5
#define M_TIDL 6		// AltGR + ¨, space = ~
#define M_CART 7		// Shift + ¨, space = ^
#define EXT_PLV M(13)
#define TOG_OUT M(14)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty nordic
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |	  Q	 |	 W	|	E  |   R  |	  T	 |	 Y	|	U  |   I  |	  O	 |	 P	|  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |	  A	 |	 S	|	D  |   F  |	  G	 |	 H	|	J  |   K  |	  L	 |	 Ø	|  Æ   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|	  Z	 |	 X	|	C  |   V  |	  B	 |	 N	|	M  |  ,;  |	 .:	 |	-_	|Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |	 Win | Alt  |  L3  |Lower |	   Space	|Raise | Left | Down |	Up	|Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,	KC_Q,	 KC_W,	  KC_E,		KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,		KC_O,	KC_P,	KC_LBRC},
  {KC_BSPC,	KC_A,	 KC_S,	  KC_D,		KC_F,	KC_G,	KC_H,	KC_J,	KC_K,		KC_L,	KC_SCLN,KC_QUOT},
  {KC_LSFT, KC_Z,	 KC_X,	  KC_C,	   	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,KC_ENT },
  {KC_LCTL,	KC_LGUI, KC_LALT, L3,	 	LOWER,	KC_SPC,	KC_SPC,	RAISE,	KC_LEFT,	KC_DOWN,KC_UP,	KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   |  |	  !	 |	 " 	|	#  |   $  |	  %	 |	 &	|	/  |   (  |	  )	 |	 =	|   ?  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |	     |	    |	   |	  |		 |		|	   |      |	   	 |	 *	|   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |	  |	 F1	 |	F2	|  F3  |  F4  |	 F5  |	F6  |  F7  |  F8  |	 F9  |	F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |	  |		 |		|	   |	  |	   Delete	|	   |      | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
{KC_GRV,	KC_EXLM,	KC_AT,		KC_HASH,	RALT(KC_4),	KC_PERC,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	S(KC_MINS)},
{_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	S(KC_NUHS),	KC_EQL},
{_______,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		_______},
{_______,	_______,	_______,	_______,	_______,	KC_DELETE,	KC_DELETE,	_______,	_______,	KC_VOLD,	KC_VOLU,	_______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   §  |	  1	 |	 2	|	3  |   4  |	  5	 |	 6	|	7  |   8  |	  9	 |	 0	|  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |	     |	    |      |      |	   	 |	  	|	   |      |	   	 |	 ^	|  ~   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |	 F11 |	F12 |      |      |	     |	    |      |   <  |	  >  |	 '	|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |	  |		 |		|	   |	  |	   Insert 	|	   | HOME | PGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {S(KC_GRV),	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,			KC_0,		KC_EQL},
  {KC_TAB,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,		M_CART,		M_TIDL},
  {KC_CAPS,		KC_F11, 	KC_F12,		_______,	_______,	_______,	_______,	_______,	KC_NUBS,	LSFT(KC_NUBS),	KC_NUHS,	_______},
  {_______,		_______, 	_______, 	_______, 	_______, 	KC_INS, 	KC_INS, 	_______, 	KC_HOME, 	KC_PGDN,		KC_PGUP, 	KC_END}
},	

/* Layer 3, mostly AltGr stuff. 
 * ,-----------------------------------------------------------------------------------.
 * |	  |      |	 @	|	£  |	  |		 |		|	{  |   [  |	  ]	 |	 }	|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |	  |		 |		|   €  |      |      |      |      |      |      |      |	   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |	  |      |      |      |      |      |      |	µ  |	  |		 |		|	   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |	  |		 |		|	   |	  |				|	   |	  |		 |		|	   |
 * `-----------------------------------------------------------------------------------'
 */
[_L3] = {
  {_______, _______, RALT(KC_2),RALT(KC_3), _______, _______, _______, RALT(KC_7), 	RALT(KC_8), RALT(KC_9), RALT(KC_0), _______},
  {_______, _______, _______, 	RALT(KC_E), _______, _______, _______, _______, 	_______, 	_______, 	_______, 	_______},
  {_______, _______, _______, 	_______, 	_______, _______, _______, RALT(KC_M), 	_______,	_______, 	_______, 	_______},
  {_______, _______, _______, 	_______, 	_______, _______, _______, _______, 	_______, 	_______, 	_______, 	_______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |	  | Reset|		|	   |	  |		 |		|	   |	  |		 |		|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |	  |		 |		|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |	   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |	  |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|	   |	  |		 |		|	   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |	  |		 |		|	   |	  |				|	   |	  |		 |		|	   |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,	 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,	AG_NORM, AG_SWAP, _______, _______, _______, _______, _______},
  {_______, MUV_DE,	 MUV_IN,  MU_ON,   MU_OFF,	MI_ON,	 MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


/* Blank template
 * ,-----------------------------------------------------------------------------------.
 * |	  |      |	 	|	   |	  |		 |		|	   |	  |		 |		|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |	  |		 |		|      |      |      |      |      |      |      |      |	   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |	  |      |      |      |      |      |      |	   |	  |		 |		|	   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |	  |		 |		|	   |	  |				|	   |	  |		 |		|	   |
 * `-----------------------------------------------------------------------------------'
 *
[_TEMPLATE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
*/

};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]	   = SONG(STARTUP_SOUND);
float tone_qwerty[][2]	   = SONG(QWERTY_SOUND);
float tone_dvorak[][2]	   = SONG(DVORAK_SOUND);
float tone_colemak[][2]	   = SONG(COLEMAK_SOUND);
float tone_plover[][2]	   = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]	   = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
	case _QWERTY:
	  if (record->event.pressed) {
		#ifdef AUDIO_ENABLE
		  PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
		#endif
		persistant_default_layer_set(1UL<<_QWERTY);
	  }
	  break;
 
	case _LOWER:
	  if (record->event.pressed) {
		layer_on(_LOWER);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  } else {
		layer_off(_LOWER);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  }
	  break;
	  
	case _RAISE:
	  if (record->event.pressed) {
		layer_on(_RAISE);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  } else {
		layer_off(_RAISE);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  }
	  break;
	  
	 case _L3:
	  if (record->event.pressed) {
		layer_on(_L3);
	  } else {
		layer_off(_L3);
	  }
	  break;
	  
	case M_BL:
	  if (record->event.pressed) {
		register_code(KC_RSFT);
		#ifdef BACKLIGHT_ENABLE
		  backlight_step();
		#endif
	  } else {
		unregister_code(KC_RSFT);
	  }
	break;
	
	case M_TIDL:
		if (record->event.pressed) {
		return MACRO( D(RALT), T(RBRC), U(RALT), T(SPACE), END );
	  }
	  break;
	  
	case M_CART:
		if (record->event.pressed) {
		return MACRO( D(RSFT), T(RBRC), U(RSFT), T(SPACE), END );
	  }
	  break;
	  
	case 14:
	  if (record->event.pressed) {
		return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
	  }
	break;
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
	#ifdef AUDIO_ENABLE
		startup_user();
	#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
	_delay_ms(20); // gets rid of tick
	PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
	PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
	_delay_ms(150);
	stop_all_notes();
}

void music_on_user(void)
{
	music_scale_user();
}

void music_scale_user(void)
{
	PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
