#pragma once

namespace SL
{

	constexpr auto btn_main_pull_tip = u8R"(
Pull the data from a program storage slot in
the Prophet-600 hardware (specified by the
program number control to the left) and apply
it to the plugin GUI. Shortcut key: CTRL+[)";

	constexpr auto btn_main_push_tip = u8R"(
Sends the current program settings to the
hardware storage slot specified by the program
number control to the left. NOTE: This overwrites
the data that is currently stored in the slot and
cannot be undone. Shortcut key: CTRL+])";

}