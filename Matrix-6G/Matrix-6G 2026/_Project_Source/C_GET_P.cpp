#include "C_GET_P.h"

#include "C_MAP_Byte_Index_P.h"
#include "C_MAP_Quick_Num_P.h"

const int GET::byte_index_for(const String& id) {
	if (MAP::byte_index.find(id) != MAP::byte_index.end())
		return MAP::byte_index.at(id);
	return -1;
}

const int GET::quick_num_for(const String& id) {
	if (MAP::quick_num.find(id) != MAP::quick_num.end())
		return MAP::quick_num.at(id);
	return -1;
}
