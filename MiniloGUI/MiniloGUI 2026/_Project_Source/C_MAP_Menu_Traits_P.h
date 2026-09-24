#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"

using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<bool, int, int>> menu_traits{
		{ ID::avp_flex_sli_target, { false, 2, 15 } },
		{ ID::avp_microtune_scale, { false, 2, 18 } }
	};

}
