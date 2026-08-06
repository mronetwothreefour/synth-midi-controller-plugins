#pragma once

#include <JuceHeader.h>

#include "D_SUBTREE_Choices_G.h"

struct Subtree_Choices_Exp_P :
	public Subtree_Choices_G
{
	static ValueTree filter_key_track(const bool curt = false);
	static ValueTree lfo_shape(const bool curt = false);
};
