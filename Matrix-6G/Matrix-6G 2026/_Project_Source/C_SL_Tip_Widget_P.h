#pragma once

namespace SL
{

	constexpr auto knob_txt_edit_osc_pitch_tip = u8R"(
Type in either a pitch name and octave number
(e.g. ‘C#5’) or a MIDI note number (e.g. ‘61’).
Range: C0 (0) to D#5 (63).)";

	constexpr auto knob_txt_edit_s_int_tip = u8R"(
Type in a new setting.
Range: -_ to _.)";

	constexpr auto knob_txt_edit_u_int_tip = u8R"(
Type in a new setting.
Range: 0 to _.)";

	constexpr auto matrix_mod_cbox_dest = u8R"(
Selects the destination parameter for modulation.
Matrix Mod parameters cannot be changed via Quick Patch Edit.
Use the PUSH button to send the entire patch instead.)";

	constexpr auto matrix_mod_cbox_src = u8R"(
Selects the modulation source. Matrix Mod parameters
cannot be changed via Quick Patch Edit. Use the
PUSH button to send the entire patch instead.)";

	constexpr auto matrix_mod_knob_amt = u8R"(
Sets whether and to what degree the selected source
modulates the selected destination. Range: -63 to +63.
0 is no modulation. Negative values invert the modulation.
Matrix Mod parameters cannot be changed via Quick Patch
Edit. Use the PUSH button to send the entire patch instead.)";

}