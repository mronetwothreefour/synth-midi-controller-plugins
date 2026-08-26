#pragma once

#include "C_ID_A.h"
#include "C_ID_Main_P.h"
#include "D_BUILD_Init_Bounds_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, Rectangle<int>> init_bounds{
		{ ID::exp_unison_track, Init_Bounds_For::exp_ctrl_unison_track() },
		{ ID::exp_osc_a_pitch, Init_Bounds_For::exp_ctrl_osc_pitch(true) },
		{ ID::exp_osc_a_sync, Init_Bounds_For::exp_ctrl_osc_a_sync() },
		{ ID::exp_osc_a_saw, Init_Bounds_For::exp_ctrl_osc_shape(1, true) },
		{ ID::exp_osc_a_tri, Init_Bounds_For::exp_ctrl_osc_shape(2, true) },
		{ ID::exp_osc_a_pulse, Init_Bounds_For::exp_ctrl_osc_shape(3, true) },
		{ ID::exp_osc_a_pulse_w, Init_Bounds_For::exp_ctrl_osc_pulse_w(true) },
		{ ID::exp_osc_b_pitch, Init_Bounds_For::exp_ctrl_osc_pitch() },
		{ ID::exp_osc_b_fine, Init_Bounds_For::exp_ctrl_osc_b_fine() },
		{ ID::exp_osc_b_saw, Init_Bounds_For::exp_ctrl_osc_shape(1) },
		{ ID::exp_osc_b_tri, Init_Bounds_For::exp_ctrl_osc_shape(2) },
		{ ID::exp_osc_b_pulse, Init_Bounds_For::exp_ctrl_osc_shape(3) },
		{ ID::exp_osc_b_pulse_w, Init_Bounds_For::exp_ctrl_osc_pulse_w() },
		{ ID::exp_mixer, Init_Bounds_For::exp_ctrl_mixer_glide(true) },
		{ ID::exp_glide, Init_Bounds_For::exp_ctrl_mixer_glide() },
		{ ID::exp_filter_cutoff, Init_Bounds_For::exp_ctrl_filter_knob(1) },
		{ ID::exp_filter_reso, Init_Bounds_For::exp_ctrl_filter_knob(2) },
		{ ID::exp_filter_env_amt, Init_Bounds_For::exp_ctrl_filter_knob(3) },
		{ ID::exp_filter_key_track, Init_Bounds_For::exp_ctrl_filter_key_track() },
		{ ID::exp_filter_env_attack, Init_Bounds_For::exp_ctrl_env_stage(1, true) },
		{ ID::exp_filter_env_decay, Init_Bounds_For::exp_ctrl_env_stage(2, true) },
		{ ID::exp_filter_env_sustain, Init_Bounds_For::exp_ctrl_env_stage(3, true) },
		{ ID::exp_filter_env_release, Init_Bounds_For::exp_ctrl_env_stage(4, true) },
		{ ID::exp_amp_env_attack, Init_Bounds_For::exp_ctrl_env_stage(1) },
		{ ID::exp_amp_env_decay, Init_Bounds_For::exp_ctrl_env_stage(2) },
		{ ID::exp_amp_env_sustain, Init_Bounds_For::exp_ctrl_env_stage(3) },
		{ ID::exp_amp_env_release, Init_Bounds_For::exp_ctrl_env_stage(4) },
		{ ID::exp_p_mod_amt_filter_env, Init_Bounds_For::exp_ctrl_poly_mod(1) },
		{ ID::exp_p_mod_amt_osc_b, Init_Bounds_For::exp_ctrl_poly_mod(2) },
		{ ID::exp_p_mod_dest_osc_a_freq, Init_Bounds_For::exp_ctrl_poly_mod(3) },
		{ ID::exp_p_mod_dest_filter, Init_Bounds_For::exp_ctrl_poly_mod(4) },
		{ ID::exp_lfo_freq, Init_Bounds_For::exp_ctrl_lfo_knob(true) },
		{ ID::exp_lfo_shape, Init_Bounds_For::exp_ctrl_lfo_switch(1) },
		{ ID::exp_lfo_init_amt, Init_Bounds_For::exp_ctrl_lfo_knob() },
		{ ID::exp_lfo_dest_osc_pitch, Init_Bounds_For::exp_ctrl_lfo_switch(2) },
		{ ID::exp_lfo_dest_osc_pw, Init_Bounds_For::exp_ctrl_lfo_switch(3) },
		{ ID::exp_lfo_dest_filter, Init_Bounds_For::exp_ctrl_lfo_switch(4) },

		{ ID::gui_editor, Init_Bounds_For::gui_editor() },
	};

}
