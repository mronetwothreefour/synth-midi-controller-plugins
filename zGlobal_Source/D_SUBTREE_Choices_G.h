#pragma once

#include <JuceHeader.h>

struct Subtree_Choices_G
{
	static ValueTree off_on(const bool curt = false);
	static ValueTree osc_pitch(int choice_count, const bool curt = false);
	static ValueTree s_7_bit_int(const bool curt = false);
	static ValueTree u_int(int choice_count, const bool curt = false);
};

