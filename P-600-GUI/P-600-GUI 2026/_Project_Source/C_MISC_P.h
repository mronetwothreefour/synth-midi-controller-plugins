#pragma once

#include <JuceHeader.h>

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto editor_aspect_ratio = 3.42347;

	constexpr auto knb_angle_0 = degreesToRadians(30.0f);
	constexpr auto knb_angle_1 = degreesToRadians(330.0f);

	constexpr auto pgm_name_init = "Basic Program       ";
	constexpr auto pgm_name_length = 20;
	constexpr auto pgm_num_max = 99;
	constexpr auto pgm_num_min = 0;

	static const tuple<string, int, string>
		txt_editor_traits_osc_pitch{ allowed_chars_pitch, 3, Tip_For::txt_editor_pitch(37, 0, 48) },
		txt_editor_traits_u_4_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(15) },
		txt_editor_traits_u_5_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(31) },
		txt_editor_traits_u_6_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) };

	constexpr array<tuple<bool, bool, bool, bool, bool, bool, bool>, 10> led_segment_flags{
		//              a      b      c      d      e      f      g
		/*00*/ tuple{ true,  true,  true,  true,  true,  true,  false },
		/*01*/ tuple{ false, true,  true,  false, false, false, false },
		/*02*/ tuple{ true,  true,  false, true,  true,  false, true  },
		/*03*/ tuple{ true,  true,  true,  true,  false, false, true  },
		/*04*/ tuple{ false, true,  true,  false, false, true,  true  },
		/*05*/ tuple{ true,  false, true,  true,  false, true,  true  },
		/*06*/ tuple{ false, false, true,  true,  true,  true,  true  },
		/*07*/ tuple{ true,  true,  true,  false, false, false, false },
		/*08*/ tuple{ true,  true,  true,  true,  true,  true,  true  },
		/*09*/ tuple{ true,  true,  true,  false, false, true,  true  },
	};

}
