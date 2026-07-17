#pragma once

namespace SL
{

	constexpr auto knob_txt_edit_osc_pitch_tip = u8R"(
Type in either a pitch name and octave number
(e.g. ‘C#5’) or a MIDI note number (e.g. ‘61’).
Range: C0 (0) to D#5 (63).)";

	constexpr auto knob_txt_edit_signed_int_tip = u8R"(
Type in a new setting.
Range: -_ to _.)";

	constexpr auto knob_txt_edit_unsigned_int_tip = u8R"(
Type in a new setting.
Range: 0 to _.)";

}