#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static std::string exp_env_stage(const unsigned int stage_num, bool filter_env = false);
		static std::string exp_osc_pitch(const std::string osc_letter);
		static std::string exp_osc_pulse_w(const std::string osc_letter);
		static std::string exp_osc_pulse(const std::string osc_letter);
		static std::string exp_osc_saw(const std::string osc_letter);
		static std::string exp_osc_tri(const std::string osc_letter);
	};

}
