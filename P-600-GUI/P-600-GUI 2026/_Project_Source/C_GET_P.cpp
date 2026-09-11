#include "C_GET_P.h"

#include "C_MAP_Data_Location_P.h"

const int GET::first_nybble_for(const String& id) {
	if (MAP::data_location.find(id) != MAP::data_location.end()) {
		auto& loc = MAP::data_location.at(id);
		return loc.fromFirstOccurrenceOf("nybble:", false, false)
				  .upToFirstOccurrenceOf("__", false, false)
				  .getIntValue();
	}
	return -1;
}

const int GET::first_bit_for(const String& id) {
	if (MAP::data_location.find(id) != MAP::data_location.end()) {
		auto& loc = MAP::data_location.at(id);
		return loc.fromFirstOccurrenceOf("bit:", false, false)
			.upToFirstOccurrenceOf("__", false, false)
			.getIntValue();
	}
	return -1;
}

const int GET::bit_count_for(const String& id) {
	if (MAP::data_location.find(id) != MAP::data_location.end()) {
		auto& loc = MAP::data_location.at(id);
		return loc.fromFirstOccurrenceOf("count:", false, false).getIntValue();
	}
	return -1;
}
