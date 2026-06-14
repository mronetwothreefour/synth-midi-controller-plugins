#pragma once

namespace SL
{

	constexpr auto knob_txt_edit_lfo_synced_tip = u8R"(
Select a new BPM-synced LFO rate
(the length of 1 lfo cycle, in beats).
Options: (0) 4,  (1) 2,  (2) 1,  (3) 3/4,
(4) 1/2,  (5) 3/8, (6) 1/3,  (7) 1/4,  
(8) 3/16,  (9) 1/6,  (10) 1/8,  (11) 1/12,
(12) 1/16,  (13) 1/24,  (14) 1/32,  (15) 1/64.)";

	constexpr auto knob_txt_edit_lfo_unsynced_tip = u8R"(
Type in a new LFO rate.
Range: 0 to 1023.)";

	constexpr auto knob_txt_edit_osc_2_pitch_eg_int_tip = u8R"(
Type in a new setting.
Range: -4800 to 4800.)";

	constexpr auto knob_txt_edit_osc_pitch_fine_tip = u8R"(
Type in a new setting.
Range: -1200 to 1200.)";

	constexpr auto knob_txt_edit_unsigned_10_bit_tip = u8R"(
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