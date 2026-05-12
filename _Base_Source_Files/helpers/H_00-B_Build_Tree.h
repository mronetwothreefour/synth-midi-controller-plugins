#pragma once

#include <JuceHeader.h>
#include "C_00-B_ID.h"

struct Base_Build_Tree
{
	static ValueTree choice_names_osc_pitch(uint8 choice_count, const bool curt = false);
	static ValueTree choice_names_unsigned_int(uint16 choice_count, const bool curt = false);
};

