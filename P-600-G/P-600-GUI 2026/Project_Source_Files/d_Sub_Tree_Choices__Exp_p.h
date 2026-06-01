#pragma once

#include <JuceHeader.h>

#include "c_ID_p.h"
#include "c_ENUM_p.h"
#include "d_Sub_Tree_Choices_b.h"

using namespace ENUM;

struct Sub_Tree_Choices_Exposed :
	public Sub_Tree_Choices_Base
{
	static ValueTree filter_key_track(const bool curt = false);
	static ValueTree lfo_shape(const bool curt = false);
};
