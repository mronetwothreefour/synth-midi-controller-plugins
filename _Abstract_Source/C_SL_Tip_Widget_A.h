#pragma once

namespace SL
{

	constexpr auto edit_pitch_tip = u8R"(
Type in either a pitch name and octave number
(e.g. ‘~’) or a MIDI note number (e.g. ‘!’).
Range: @ (&) to $ (%).)";

	constexpr auto edit_s_int_tip = u8R"(
Type in a new setting.
Range: -_ to _.)";

	constexpr auto edit_u_int_tip = u8R"(
Type in a new setting.
Range: 0 to _.)";

}
