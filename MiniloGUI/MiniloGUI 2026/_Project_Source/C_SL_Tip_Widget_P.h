#pragma once

namespace SL
{

	constexpr auto btn_main_pull_tip = u8R"(
Requests a program edit buffer dump from
the Minilogue hardware and applies it to
the plugin GUI. Shortcut key: CTRL+[)";

	constexpr auto btn_main_push_tip = u8R"(
Writes the plugin’s current program and sequencer
settings into the Minilogue hardware’s program
edit buffer. Shortcut key: CTRL+])";

	constexpr auto btn_main_vmode_0_tip = u8R"(
POLY mode: Up to four distinct notes can
play at once (i.e. one voice per note).
Chords will be inverted according to the
depth knob setting.)";

	constexpr auto btn_main_vmode_1_tip = u8R"(
DUO mode: Up to two distinct notes can
play at once (i.e. two voices per note).
Voices will be detuned according to the
depth knob setting.)";

	constexpr auto btn_main_vmode_2_tip = u8R"(
UNISON mode: Only one note at a time
can play, and it will use all four voices.
Voices will be detuned according to the
depth knob setting.)";

	constexpr auto btn_main_vmode_3_tip = u8R"(
MONO mode: Only one note at a time can play using voice 1.
The other three voices act as sub-oscillators. Voices 2 & 3
are one octave lower, and voice 4 is two octaves lower.
Use the depth knob to set the sub-oscillator levels.)";

	constexpr auto btn_main_vmode_4_tip = u8R"(
CHORD mode: Only one note at a time can play,
but it will produce a chord of up to four notes
(with the played note as the root). Use the depth
knob to select which type of chord is produced.)";

	constexpr auto btn_main_vmode_5_tip = u8R"(
DELAY mode: Only one note at a time can play
using voice 1. The other three voices will
repeat the note in sequence with a set
delay between steps. Use the depth knob
to select the length of the delay.)";

	constexpr auto btn_main_vmode_6_tip = u8R"(
ARP mode: Plays an arpeggiated sequence
of up to four notes. Use the depth knob
to select the arpeggio pattern.)";

	constexpr auto btn_main_vmode_7_tip = u8R"(
SIDECHAIN mode: A newly-triggered voice
lowers the volume of any voices that are
already playing. Use the depth knob to
control the degree of volume reduction.)";

	constexpr auto knob_txt_edit_amp_mod_tip = u8R"(
Type in a new setting.
Range: 0 to 127.)";

	constexpr auto knob_txt_edit_fine_tune_tip = u8R"(
Type in a new setting.
Range: -50 to 50.)";

	constexpr auto knob_txt_edit_flex_sli_bend_tip = u8R"(
Type in a new maximum
_tive pitch bend.
Range: 1 to 12.)";

	constexpr auto knob_txt_edit_flex_sli_range_tip = u8R"(
Type in a new range.
Range: -100 to 100.)";

	constexpr auto knob_txt_edit_level_tip = u8R"(
Type in a new level.
Range: -25 to 25.)";

	constexpr auto knob_txt_edit_porta_time_tip = u8R"(
Type in a new setting.
Range: ‘off’; 0 to 127.)";

	constexpr auto knob_txt_edit_lfo_synced_tip = u8R"(
Select a new BPM-synced LFO rate
(number of cycles : number of beats).
Options: (0) 1:4,  (1) 1:2,  (2) 1:1,  (3) 4:3,
(4) 2:1,  (5) 8:3, (6) 3:1,  (7) 4:1,  
(8) 16:3,  (9) 6:1,  (10) 8:1,  (11) 12:1,
(12) 16:1,  (13) 24:1,  (14) 32:1,  (15) 64:1.)";

	constexpr auto knob_txt_edit_lfo_unsynced_tip = u8R"(
Type in a new
unsynced LFO rate.
Range: 0 to 1023.)";

	constexpr auto knob_txt_edit_lpf_eg_int_tip = u8R"(
Type in a new intensity.
Range: -100 to 100.)";

	constexpr auto knob_txt_edit_osc_2_pitch_eg_int_tip = u8R"(
Type in a new setting.
Range: -4800 to 4800.)";

	constexpr auto knob_txt_edit_osc_pitch_fine_tip = u8R"(
Type in a new setting.
Range: -1200 to 1200.)";

	constexpr auto knob_txt_edit_scale_key_tip = u8R"(
Type in either a pitch name and octave number
(e.g. ‘C#1’) or a MIDI note number (e.g. ‘13’).
Range: C0 (0) to C2 (24).)";

	constexpr auto knob_txt_edit_transpose_tip = u8R"(
Type in a new setting.
Range: -12 to 12.)";

	constexpr auto knob_txt_edit_u_10_bit_int_tip = u8R"(
Type in a new setting.
Range: 0 to 1023.)";

	constexpr auto knob_txt_edit_voice_mode_0_tip = u8R"(
Type in a new inversion setting.
Range: 0 to 8.)";

	constexpr auto knob_txt_edit_voice_mode_1_2_tip = u8R"(
Type in a new detune setting.
Range: 0 to 50.)";

	constexpr auto knob_txt_edit_voice_mode_3_tip = u8R"(
Type in a new sub-oscillator setting.
Range: 0 to 1023.)";

	constexpr auto knob_txt_edit_voice_mode_4_tip = u8R"(
Select a new chord type.
Options: (0) 5th,  (1) sus2,  (2) min,  (3) Maj,  (4) sus4,
(5) m7,  (6) 7th,  (7) 7sus4,  (8) Maj7,  (9) aug,  (10) dim,  
(11) m7b5,  (12) mMaj7,  (13) Maj7b5.)";

	constexpr auto knob_txt_edit_voice_mode_5_tip = u8R"(
Select a new delay length (in fractions of a beat).
Options: (0) 1/192,  (1) 1/128,  (2) 1/64,  (3) 1/48,
(4) 1/32,  (5) 1/24,  (6) 1/16,  (7) 1/12,  (8) 1/8,  
(9) 1/6,  (10) 3/16,  (11) 1/4.)";

	constexpr auto knob_txt_edit_voice_mode_6_tip = u8R"(
Select a new arpeggio type.
(0) manual 1,  (1) manual 2,  (2) rise 1,  (3) rise 2,  (4) fall 1,
(5) fall 2,  (6) rise/fall 1,  (7) rise/fall 2,  (8) poly 1,  (9) poly 2,  
(10) random 1,  (11) random 2,  (12) random 3.)";

	constexpr auto knob_txt_edit_voice_mode_7_tip = u8R"(
Type in a new sidechain setting.
Range: 0 to 1023.)";

}