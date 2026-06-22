#pragma once

namespace ENUM
{

	constexpr enum class Ctrl_Type {
		error = -1,
		dummy,
		knob,
		knob_osc_pitch,
		switch_2_pole,
		switch_3_pole
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		int_4_bit,
		int_5_bit,
		int_6_bit,
		int_7_bit,
		osc_pitch
	};

}
