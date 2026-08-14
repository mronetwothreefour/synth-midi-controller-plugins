#pragma once

#include "D_BUILD_Choices_A.h"

namespace BUILD
{ 

	struct Choices :
		public Choices_A
	{
		static const StringArray exp_filter_key_track();
		static const StringArray exp_lfo_shape();
	};

}
