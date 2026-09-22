#pragma once

#include <JuceHeader.h>

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const int first_nybble_for(const String& id);
	static const int first_bit_for(const String& id);
	static const int bit_count_for(const String& id);
};
