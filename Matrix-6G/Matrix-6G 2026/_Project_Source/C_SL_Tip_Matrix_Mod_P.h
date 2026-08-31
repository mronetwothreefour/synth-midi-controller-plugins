#pragma once

namespace SL
{
	
    constexpr auto mmod_amt_tip = u8R"(
Sets whether and to what degree the selected source
modulates the selected destination. Range: -63 to +63.
0 is no modulation. Negative values invert the modulation.
Note: Matrix Mod parameters cannot be changed via quick patch
edit. Send the entire patch using the PUSH button instead.)";
	
    constexpr auto mmod_dst_tip = u8R"(
Selects the destination parameter for modulation. Note:
Matrix Mod parameters cannot be changed via quick patch
edit. Send the entire patch using the PUSH button instead.)";
	
    constexpr auto mmod_src_tip = u8R"(
Selects the modulation source. Note: Matrix Mod
parameters cannot be changed via quick patch edit.
Send the entire patch using the PUSH button instead.)";
	
}
