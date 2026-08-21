#pragma once

#include "D_BUILD_Tip_For_A.h"
#include "D_TREE_Aux_Voice_Params_P.h"

using namespace TREE;

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
			
		static String exp_env_attack(bool vca = false);
		static String exp_env_decay(bool vca = false);
		static String exp_env_release(bool vca = false);
		static String exp_env_sustain(bool vca = false);

		static String exp_level_knob(const int knob_num);

		static String exp_osc_octave(const int osc_num);
		static String exp_osc_pitch_fine(const int osc_num);
		static String exp_osc_shape(const int osc_num);
		static String exp_osc_wave(const int osc_num);

		static String knob_txt_editor(const String& slider_label_name, Aux_Voice_Params& avp);
	};

}
