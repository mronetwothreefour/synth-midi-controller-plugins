#pragma once

namespace ENUM
{

	constexpr enum class Ctrl_Type {
		error = -1,
		dummy,
		slider,
		slider_osc_pitch,
		slider_osc_balance,
		cbox
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		osc_pitch,
		signed_6_bit_int,
		signed_7_bit_int,
		unsigned_int
	};

}
