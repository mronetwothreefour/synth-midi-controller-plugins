#include "C_GET_P.h"

#include "C_MAP_Byte_Index_P.h"
#include "C_MAP_Quick_Edit_Traits_P.h"

const int GET::byte_index_for(const std::string& id) {
	if (MAP::byte_index.find(id) != MAP::byte_index.end())
		return MAP::byte_index.at(id);
	return -1;
}

const int GET::quick_num_for(const std::string& id) {
	if (MAP::quick_edit_traits.find(id) != MAP::quick_edit_traits.end())
		return std::get<0>(MAP::quick_edit_traits.at(id));
	return -1;
}

const bool GET::range_is_s_6_bit_for(const std::string& id) {
	if (MAP::quick_edit_traits.find(id) != MAP::quick_edit_traits.end())
		return std::get<1>(MAP::quick_edit_traits.at(id));
	return false;
}

const bool GET::range_is_s_7_bit_for(const std::string& id) {
	if (MAP::quick_edit_traits.find(id) != MAP::quick_edit_traits.end())
		return std::get<2>(MAP::quick_edit_traits.at(id));
	return false;
}
