#include "C_GET_P.h"

#include "C_MAP_Quick_Num_P.h"

const int GET::quick_num_for(const String& id) {
	if (MAP::quick_num.find(id) != MAP::quick_num.end())
		return MAP::quick_num.at(id);
	return -1;
}
