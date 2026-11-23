#include "C_GET_P.h"

#include "C_MAP_Init_Bounds_P.h"
#include "C_MAP_Menu_Traits_P.h"
#include "C_MAP_NRPN_P.h"
#include "C_XYWH_P.h"

const int GET::ls_byte_for(const int& param_index) {
	return ms_bit_pack_byte_for(param_index) + (param_index % 7) + 1;
}

const int GET::ms_bit_pack_byte_for(const int& param_index) {
	return (param_index / 7) * 8;
}

const int GET::ms_bit_mask_for(const int& param_index) {
	return roundToInt(pow(2, param_index % 7));
}

const bool GET::menu_to_left_for(const std::string& id) {
	if (MAP::menu_traits.find(id) != MAP::menu_traits.end())
		return std::get<3>(MAP::menu_traits.at(id));
	return {};
}

const int GET::nrpn_for(const std::string& id) {
	if (MAP::nrpn.find(id) != MAP::nrpn.end())
		return MAP::nrpn.at(id);
	return -1;
}

const Rectangle<int> GET::init_red_toggle_bounds_for(const std::string& n) {
	if (MAP::init_red_toggle_pos.find(n) != MAP::init_red_toggle_pos.end()) {
		auto& b = MAP::init_red_toggle_pos.at(n);
		Rectangle<int> r{ std::get<1>(b), std::get<2>(b), XYWH::toggle_diam, XYWH::toggle_diam };
		if (std::get<0>(b))
			r.setCentre(std::get<1>(b), std::get<2>(b));
		return r;
	}
	return {};
}
