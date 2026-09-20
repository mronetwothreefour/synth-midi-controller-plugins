#pragma once

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const int nrpn_for(const std::string& id);
	static const Rectangle<int> init_red_toggle_bounds_for(const std::string& ctrl_name);
};
