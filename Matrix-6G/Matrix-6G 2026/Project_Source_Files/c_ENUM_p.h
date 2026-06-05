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

	constexpr enum class Input_Choice_Type {
		mod,
		lfo,
		tracking
	};

	constexpr enum class Range_Type {
		error = -1,
		unsigned_int,
		signed_6_bit,
		signed_7_bit
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		osc_pitch,
		signed_6_bit_int,
		signed_7_bit,
		unsigned_int
	};

}
