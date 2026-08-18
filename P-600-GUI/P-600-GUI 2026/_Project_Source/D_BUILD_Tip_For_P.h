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

		static String exp_filter_cutoff();
		static String exp_filter_env_amt();
		static String exp_filter_key_track();
		static String exp_filter_reso();

		static String exp_glide();

		static String exp_lfo_dest_filter();
		static String exp_lfo_dest_osc_pitch();
		static String exp_lfo_dest_osc_pw();
		static String exp_lfo_freq();
		static String exp_lfo_init_amt();
		static String exp_lfo_shape();

		static String exp_mixer();

		static String exp_osc_pitch(const String osc_letter);
		static String exp_osc_pulse_w(const String osc_letter);
		static String exp_osc_pulse(const String osc_letter);
		static String exp_osc_saw(const String osc_letter);
		static String exp_osc_tri(const String osc_letter);
		static String exp_osc_a_sync();
		static String exp_osc_b_fine();

		static String exp_poly_mod_amt_filter_env();
		static String exp_poly_mod_amt_osc_b();
		static String exp_poly_mod_dest_filter_freq();
		static String exp_poly_mod_dest_osc_a_freq();

		static String exp_unison_track();

		static String knob_txt_editor(const String& slider_label_name);
	};

}
