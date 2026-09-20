#include "C_GET_P.h"

#include "C_MAP_Init_Bounds_P.h"
#include "C_MAP_NRPN_P.h"
#include "C_XYWH_P.h"

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
