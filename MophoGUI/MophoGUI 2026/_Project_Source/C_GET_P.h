#pragma once

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const int ls_byte_for(const int& param_index);
	static const int ms_bit_pack_byte_for(const int& param_index);
	static const uint8 ms_bit_mask_for(const int& param_index);
	static const bool menu_to_left_for(const std::string& id);
	static const int nrpn_for(const std::string& id);
	static const Rectangle<int> init_red_toggle_bounds_for(const std::string& ctrl_name);
};
