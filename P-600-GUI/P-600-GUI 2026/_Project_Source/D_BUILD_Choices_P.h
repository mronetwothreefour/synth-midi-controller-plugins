#pragma once

#include "D_BUILD_Choices_A.h"

struct Build_Choices :
	public Build_Choices_A
{
	static const StringArray exp_filter_key_track();
	static const StringArray exp_lfo_shape();
};