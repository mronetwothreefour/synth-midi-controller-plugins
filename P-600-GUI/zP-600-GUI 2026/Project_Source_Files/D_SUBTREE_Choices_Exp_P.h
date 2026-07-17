#pragma once

#include <JuceHeader.h>

#include "C_ID_P.h"
#include "D_SUBTREE_Choices_B.h"

struct Subtree_Choices_Exp_P :
	public Subtree_Choices_B
{
	static ValueTree filter_key_track(const bool curt = false);
	static ValueTree lfo_shape(const bool curt = false);
};
