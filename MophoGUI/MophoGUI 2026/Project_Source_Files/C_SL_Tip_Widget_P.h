#pragma once

namespace SL
{

	constexpr auto knob_txt_edit_clock_tempo_tip = u8R"(
Type in a new setting.
Range: 30 to 250.)";

	constexpr auto knob_txt_edit_lfo_freq_tip = u8R"(
Type in a new LFO frequency.
Unsynced: ‘0’..‘89’.
Pitched: ‘C0’..‘C5’ or ‘90’..‘150’. 
Synced: ‘1:32’..‘16:1’ or ‘151’..‘166’.)";

	constexpr auto knob_txt_edit_lpf_freq_tip = u8R"(
Type in either a pitch name and octave number
(e.g. ‘C#5’) or a note number (e.g. ‘61’).
Range: C0 (0) to G#13 (164).)";

	constexpr auto knob_txt_edit_osc_fine_tip = u8R"(
Type in a new setting.
Range: -50 to 50.)";

	constexpr auto knob_txt_edit_osc_pitch_tip = u8R"(
Type in either a pitch name and octave number
(e.g. ‘C#5’) or a MIDI note number (e.g. ‘61’).
Range: C0 (0) to C10 (120).)";

	constexpr auto knob_txt_edit_osc_shape_tip = u8R"(
Type in a new shape setting.
Off: ‘OFF’ or ‘0’.
Sawtooth: ‘SAW’ or ‘1’. 
Triangle: ‘TRI’ or ‘2’. 
Sawtooth/Triangle Mix: ‘S/T’ or ‘3’. 
Pulse Width 0..99: ‘PW0’..‘PW99’ or ‘4’..‘104’.
Square: ‘SQR’ or ‘PW50’ or ‘54’.)";

	constexpr auto knob_txt_edit_osc_slop_tip = u8R"(
Type in a new setting.
Range: 0 to 5.)";

	constexpr auto knob_txt_edit_bend_range_tip = u8R"(
Type in a new setting.
Range: 0 to 12.)";

	constexpr auto knob_txt_edit_signed_8_bit_tip = u8R"(
Type in a new setting.
Range: -127 to 127.)";

	constexpr auto knob_txt_edit_unsigned_7_bit_tip = u8R"(
Type in a new setting.
Range: 0 to 127.)";

}