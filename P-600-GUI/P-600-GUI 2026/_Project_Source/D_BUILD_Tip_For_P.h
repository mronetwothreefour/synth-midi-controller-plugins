#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static String exp_env_attack(bool filter_env = false);
		static String exp_env_decay(bool filter_env = false);
		static String exp_env_release(bool filter_env = false);
		static String exp_env_sustain(bool filter_env = false);

		static String exp_osc_pitch(const String osc_letter);
		static String exp_osc_pulse_w(const String osc_letter);
		static String exp_osc_pulse(const String osc_letter);
		static String exp_osc_saw(const String osc_letter);
		static String exp_osc_tri(const String osc_letter);

		static String knob_txt_editor(const String& slider_label_name);
	};

}
