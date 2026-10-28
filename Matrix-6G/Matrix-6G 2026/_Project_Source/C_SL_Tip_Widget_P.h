#pragma once

namespace SL
{

	constexpr auto btn_quick = u8R"(
The Matrix must be put into Quick Patch Edit mode
before it will respond to remote parameter changes.
Click this button before making any edits with the
plugin (the hardware’s front panel display should
show ‘PATCH EDIT’). Shortcut key: Alt+Q)";

	constexpr auto curr_pgm_name = u8R"(
Click to edit the name of the patch (8 characters max.)
The stored name cannot be changed via Quick Patch Edit.
Use the PUSH button to send the entire patch instead.)";

	constexpr auto curr_pgm_num = u8R"(
Selects which patch storage slot
on the hardware is targeted by the
PUSH and PULL buttons to the left.
Range: 00 to 99.)";

}