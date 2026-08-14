#pragma once

#include "D_BUILD_Choices_A.h"

namespace BUILD
{

	struct Choices :
		public Choices_A
	{
		static const StringArray exp_arp_mode();
		static const StringArray exp_bend_range();
		static const StringArray exp_clock_div();
		static const StringArray exp_clock_tempo();
		static const StringArray exp_flex_knob();
		static const StringArray exp_glide_mode();
		static const StringArray exp_lfo_freq();
		static const StringArray exp_lfo_shape();
		static const StringArray exp_lpf_freq();
		static const StringArray exp_lpf_type();
		static const StringArray exp_mod_dest();
		static const StringArray exp_mod_src();
		static const StringArray exp_note_priority();
		static const StringArray exp_osc_fine();
		static const StringArray exp_osc_shape();
		static const StringArray exp_push_it_mode();
		static const StringArray exp_seq_track_2_4_dest(const bool track_2);
		static const StringArray exp_seq_track_step();
		static const StringArray exp_seq_trig_mode();
		static const StringArray exp_voice_name_char();
	};

}
