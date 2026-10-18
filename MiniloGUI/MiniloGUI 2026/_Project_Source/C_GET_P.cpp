#include "C_GET_P.h"

#include "C_MAP_Bit_Locations_P.h"
#include "C_MAP_Init_Sli_Traits_P.h"

const StringArray GET::bit_locations_for(const std::string& id) {
	if (MAP::bit_locations.find(id) != MAP::bit_locations.end())
		return MAP::bit_locations.at(id);
	return {};
}

const bool GET::init_sli_is_mapped(const std::string& id) {
	if (MAP::init_slider_traits.find(id) != MAP::init_slider_traits.end())
		return std::get<0>(MAP::init_slider_traits.at(id));
	return false;
}

const int GET::init_sli_increment_shift(const std::string& id) {
	if (MAP::init_slider_traits.find(id) != MAP::init_slider_traits.end())
		return std::get<1>(MAP::init_slider_traits.at(id));
	return 0;
}

const int GET::init_sli_increment_ctrl(const std::string& id) {
	if (MAP::init_slider_traits.find(id) != MAP::init_slider_traits.end())
		return std::get<2>(MAP::init_slider_traits.at(id));
	return 0;
}

const bool GET::init_sli_alt_snaps(const std::string& id) {
	if (MAP::init_slider_traits.find(id) != MAP::init_slider_traits.end())
		return std::get<3>(MAP::init_slider_traits.at(id));
	return false;
}

const int GET::init_txt_editor_offset(const std::string& id) {
	if (MAP::init_slider_traits.find(id) != MAP::init_slider_traits.end())
		return std::get<4>(MAP::init_slider_traits.at(id));
	return -255;
}
