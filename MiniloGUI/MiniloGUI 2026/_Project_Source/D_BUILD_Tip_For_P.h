#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
			
		static std::string exp_env_attack(bool vca = false);
		static std::string exp_env_decay(bool vca = false);
		static std::string exp_env_release(bool vca = false);
		static std::string exp_env_sustain(bool vca = false);

		static std::string exp_level_knob(const int knob_num);

		static std::string exp_osc_octave(const int osc_num);
		static std::string exp_osc_pitch_fine(const int osc_num);
		static std::string exp_osc_shape(const int osc_num);
		static std::string exp_osc_wave(const int osc_num);
	};

}
