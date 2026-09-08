#include "C_GET_P.h"

#include "C_MAP_Bit_Locations_P.h"

const StringArray GET::bit_locations_for(const String& id) {
	if (MAP::bit_locations.find(id) != MAP::bit_locations.end())
		return MAP::bit_locations.at(id);
	return {};
}
