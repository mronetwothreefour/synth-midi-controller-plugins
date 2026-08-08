#include "C_EXP_Get_A.h"

#include "C_EXP_Map_Name_P.h"

const String EXP::Get_A::name_for(const String component_id) {
	if (map_name.find(component_id) != map_name.end())
		return map_name.at(component_id);
	return {};
}
