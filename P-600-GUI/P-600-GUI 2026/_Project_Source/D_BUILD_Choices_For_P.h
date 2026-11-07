#pragma once

#include "D_BUILD_Choices_For_A.h"

namespace BUILD
{ 

	struct Choices_For :
		public Choices_For_A
	{
		static const StringArray app_curr_pgm_num();

		static const StringArray exp_filter_key_track();
		static const StringArray exp_lfo_shape();
	};

}
