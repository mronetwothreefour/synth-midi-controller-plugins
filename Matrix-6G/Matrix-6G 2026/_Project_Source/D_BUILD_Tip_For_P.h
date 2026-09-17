#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static std::string exp_env_stage(const unsigned int env_num, const unsigned int stage_num);
		static std::string exp_osc_key_track(const unsigned int osc_num);
		static std::string exp_osc_type(const unsigned int osc_num);
		static std::string exp_track_point(const int point_num, int init_choice);

	};

}
