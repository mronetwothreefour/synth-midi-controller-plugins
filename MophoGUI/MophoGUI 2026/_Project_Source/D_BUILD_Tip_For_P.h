#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static std::string exp_env_3_dest();
		static std::string exp_env_stage(const std::string env_name, const unsigned int stage_num);
		static std::string exp_env_velo_amt(const std::string env_name);

		static std::string exp_lfo_dest(const int lfo_num);

		static std::string exp_mod_amt();
		static std::string exp_mod_dest();
		static std::string exp_mod_src();

		static std::string exp_seq_track_dest(const unsigned int track_num);
		static std::string exp_seq_track_step(const unsigned int track_num, int step_num);
	};

}
