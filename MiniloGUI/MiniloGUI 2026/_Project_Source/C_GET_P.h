#pragma once

#include <JuceHeader.h>

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const StringArray bit_locations_for(const String& id);
};
