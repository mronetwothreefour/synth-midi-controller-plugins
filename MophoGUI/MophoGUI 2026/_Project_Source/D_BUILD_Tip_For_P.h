#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static String exp_env_3_dest();
		static String exp_env_attack(const String env_name);
		static String exp_env_decay(const String env_name);
		static String exp_env_delay(const String env_name);
		static String exp_env_release(const String env_name);
		static String exp_env_sustain(const String env_name);
		static String exp_env_velo_amt(const String env_name);

		static String exp_flex_knob(const int knob_num);

		static String exp_lfo_amt(const int lfo_num);
		static String exp_lfo_dest(const int lfo_num);
		static String exp_lfo_freq(const int lfo_num);
		static String exp_lfo_key_sync(const int lfo_num);
		static String exp_lfo_shape(const int lfo_num);

		static String exp_mod_amt();
		static String exp_mod_dest();
		static String exp_mod_src();

		static String exp_osc_fine(const int osc_num);
		static String exp_osc_glide(const int osc_num);
		static String exp_osc_key_track(const int osc_num);
		static String exp_osc_pitch(const int osc_num);
		static String exp_osc_shape(const int osc_num);
		static String exp_osc_sub_level(const int osc_num);

		static String exp_seq_track_dest(const int track_num);
		static String exp_seq_track_step(const int track_num, int step_num);

		static String exp_voice_name_char(const int char_num);

		static String knob_text_editor(const String& slider_label_name);
	};

}
