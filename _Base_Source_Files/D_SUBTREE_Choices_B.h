#pragma once

#include <JuceHeader.h>
#include "C_ID_B.h"

struct Subtree_Choices_B
{
	static ValueTree off_on(const bool curt = false);
	static ValueTree osc_pitch(uint8 choice_count, const bool curt = false);
	static ValueTree signed_7_bit_int(const bool curt = false);
	static ValueTree unsigned_int(uint16 choice_count, const bool curt = false);
};

