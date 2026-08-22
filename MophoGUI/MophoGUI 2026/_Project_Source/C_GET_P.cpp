#include "C_GET_P.h"

#include "C_MAP_NRPN_P.h"

const int GET::nrpn_for(const String& id) {
	if (MAP::nrpn.find(id) != MAP::nrpn.end())
		return MAP::nrpn.at(id);
	return -1;
}
