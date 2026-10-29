#pragma once

namespace SL
{

	constexpr auto btn_main_redo_tip = u8R"(
Click this button to redo a pre-
viously undone parameter change.
Shortcut key: CTRL+SHIFT+Z)";

	constexpr auto btn_main_undo_tip = u8R"(
Click this button to undo the previous
parameter change. Shortcut key: CTRL+Z.)";

	constexpr auto edit_pgm_name_tip = u8R"(
Type in a new name
(_ characters maximum).)";

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
