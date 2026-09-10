#pragma once

#include "D_BUILD_Choices_For_A.h"

namespace BUILD
{ 

	struct Choices_For :
		public Choices_For_A
	{
		static const StringArray exp_filter_key_track();
		static const StringArray exp_lfo_shape();
	};

}
