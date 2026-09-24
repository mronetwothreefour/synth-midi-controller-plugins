#pragma once

#include <tuple>

#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace std;

namespace MISC
{

	constexpr auto allowed_chars_pitch{ "abcdefgABCDEFG0123456789#" };
	constexpr auto allowed_chars_porta_time{ "0123456789foFO" };
	constexpr auto allowed_chars_s_int{ "-0123456789" };
	constexpr auto allowed_chars_u_int{ "0123456789" };
	constexpr auto pitch_name_chars{ "abcdefgABCDEFG#" };

	static const tuple<string, int, string> 
		txt_editor_traits_u_7_bit{ allowed_chars_u_int, 3, Tip_For::txt_editor_u_int(127) };

}