#pragma once

#include "D_BUILD_Init_Bounds_For_A.h"

namespace BUILD
{

	struct Init_Bounds_For :
		Init_Bounds_For_A
	{
		static const Rectangle<int> exp_ctrl_arp_mode();
		static const Rectangle<int> exp_ctrl_arpeg_on_off();
		static const Rectangle<int> exp_ctrl_cc_amt(const int cc_num);
		static const Rectangle<int> exp_ctrl_cc_dest(const int cc_num);
		static const Rectangle<int> exp_ctrl_clock_tempo();
		static const Rectangle<int> exp_ctrl_clock_div();
		static const Rectangle<int> exp_ctrl_env_3(const int row_num, const int col_num);
		static const Rectangle<int> exp_ctrl_env_3_dest();
		static const Rectangle<int> exp_ctrl_flex_knob(const int knob_num);
		static const Rectangle<int> exp_ctrl_glide_mode();
		static const Rectangle<int> exp_ctrl_lfo_cbox(const int lfo_num, const bool dest = false);
		static const Rectangle<int> exp_ctrl_lfo_key_sync(const int lfo_num);
		static const Rectangle<int> exp_ctrl_lfo_knob(const int lfo_num, const bool amt = false);
		static const Rectangle<int> exp_ctrl_lpf(const int row_num, const int col_num);
		static const Rectangle<int> exp_ctrl_lpf_type();
		static const Rectangle<int> exp_ctrl_mod_amt(const int mod_num);
		static const Rectangle<int> exp_ctrl_mod_cbox(const int mod_num, const bool dest = false);
		static const Rectangle<int> exp_ctrl_note_priority();
		static const Rectangle<int> exp_ctrl_osc(const int row_num, const int col_num);
		static const Rectangle<int> exp_ctrl_osc_sync();
		static const Rectangle<int> exp_ctrl_push_it_knob(const bool pitch = false);
		static const Rectangle<int> exp_ctrl_push_it_mode();
		static const Rectangle<int> exp_ctrl_seq_on_off();
		static const Rectangle<int> exp_ctrl_seq_track_dest(const int track_num);
		static const Rectangle<int> exp_ctrl_seq_track_step(const int track_num, const int step_num);
		static const Rectangle<int> exp_ctrl_seq_trig_mode();
		static const Rectangle<int> exp_ctrl_vca(const int row_num, const int col_num);
		static const Rectangle<int> exp_ctrl_voice_name_char(const int char_num);

		static const Rectangle<int> toggle_arpeg_on_off();
		static const Rectangle<int> toggle_env_3_repeat();
		static const Rectangle<int> toggle_lfo_key_sync(const int lfo_num);
		static const Rectangle<int> toggle_lpf_type();
		static const Rectangle<int> toggle_osc_key_track(const int row_num);
		static const Rectangle<int> toggle_osc_sync();
		static const Rectangle<int> toggle_seq_on_off();
	};

}
