#pragma once

#include "C_ID_A.h"
#include "C_ID_Main_P.h"
#include "D_BUILD_Init_Bounds_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, Rectangle<int>> init_bounds{
		{ ID::avp_voice_mode_btn_0, Init_Bounds_For::avp_ctrl_voice_mode_btn(0) },
		{ ID::avp_voice_mode_btn_1, Init_Bounds_For::avp_ctrl_voice_mode_btn(1) },
		{ ID::avp_voice_mode_btn_2, Init_Bounds_For::avp_ctrl_voice_mode_btn(2) },
		{ ID::avp_voice_mode_btn_3, Init_Bounds_For::avp_ctrl_voice_mode_btn(3) },
		{ ID::avp_voice_mode_btn_4, Init_Bounds_For::avp_ctrl_voice_mode_btn(4) },
		{ ID::avp_voice_mode_btn_5, Init_Bounds_For::avp_ctrl_voice_mode_btn(5) },
		{ ID::avp_voice_mode_btn_6, Init_Bounds_For::avp_ctrl_voice_mode_btn(6) },
		{ ID::avp_voice_mode_btn_7, Init_Bounds_For::avp_ctrl_voice_mode_btn(7) },
		{ ID::avp_keyboard_octave, Init_Bounds_For::avp_ctrl_keyboard_octave() },
		{ ID::avp_flex_sli_target, Init_Bounds_For::avp_ctrl_flex_sli_target() },
		{ ID::avp_flex_sli_range, Init_Bounds_For::avp_ctrl_flex_sli_knob(1) },
		{ ID::avp_flex_sli_bend_pos, Init_Bounds_For::avp_ctrl_flex_sli_knob(2) },
		{ ID::avp_flex_sli_bend_neg, Init_Bounds_For::avp_ctrl_flex_sli_knob(3) },
		{ ID::avp_lfo_sync_bpm_on, Init_Bounds_For::avp_ctrl_lfo_switch(1) },
		{ ID::avp_lfo_sync_key_on, Init_Bounds_For::avp_ctrl_lfo_switch(2) },
		{ ID::avp_lfo_sync_voice_on, Init_Bounds_For::avp_ctrl_lfo_switch(3) },
		{ ID::avp_amp_mod_by_velo_amt, Init_Bounds_For::avp_ctrl_amp_mod_and_level(true) },
		{ ID::avp_level, Init_Bounds_For::avp_ctrl_amp_mod_and_level() },
		{ ID::avp_microtune_scale, Init_Bounds_For::avp_ctrl_microtune_scale() },
		{ ID::avp_scale_key, Init_Bounds_For::avp_ctrl_tuning_knob(1) },
		{ ID::avp_fine_tune, Init_Bounds_For::avp_ctrl_tuning_knob(2) },
		{ ID::avp_transpose, Init_Bounds_For::avp_ctrl_tuning_knob(3) },
		{ ID::avp_porta_time, Init_Bounds_For::avp_ctrl_porta_time() },
		{ ID::avp_porta_mode_on, Init_Bounds_For::avp_ctrl_porta_switch(true) },
		{ ID::avp_porta_sync_bpm_on, Init_Bounds_For::avp_ctrl_porta_switch() },

		{ ID::exp_osc_1_octave, Init_Bounds_For::exp_ctrl_osc_switch(true, true) },
		{ ID::exp_osc_1_wave, Init_Bounds_For::exp_ctrl_osc_switch(true, false) },
		{ ID::exp_osc_1_pitch_fine, Init_Bounds_For::exp_ctrl_osc_knob(true, true) },
		{ ID::exp_osc_1_shape, Init_Bounds_For::exp_ctrl_osc_knob(true, false) },
		{ ID::exp_osc_2_octave, Init_Bounds_For::exp_ctrl_osc_switch(false, true) },
		{ ID::exp_osc_2_wave, Init_Bounds_For::exp_ctrl_osc_switch(false, false) },
		{ ID::exp_osc_2_pitch_fine, Init_Bounds_For::exp_ctrl_osc_knob(false, true) },
		{ ID::exp_osc_2_shape, Init_Bounds_For::exp_ctrl_osc_knob(false, false) },
		{ ID::exp_osc_2_xmod_depth, Init_Bounds_For::exp_ctrl_osc_2_mod_knob(true) },
		{ ID::exp_osc_2_pitch_eg_int, Init_Bounds_For::exp_ctrl_osc_2_mod_knob() },
		{ ID::exp_osc_2_sync, Init_Bounds_For::exp_ctrl_osc_2_mod_switch(true) },
		{ ID::exp_osc_2_ring_mod, Init_Bounds_For::exp_ctrl_osc_2_mod_switch() },
		{ ID::exp_mix_osc_1, Init_Bounds_For::exp_ctrl_mixer_knob(1) },
		{ ID::exp_mix_osc_2, Init_Bounds_For::exp_ctrl_mixer_knob(2) },
		{ ID::exp_mix_noise, Init_Bounds_For::exp_ctrl_mixer_knob(3) },
		{ ID::exp_lpf_freq, Init_Bounds_For::exp_ctrl_lpf_freq() },
		{ ID::exp_lpf_reso, Init_Bounds_For::exp_ctrl_lpf_knob(true) },
		{ ID::exp_lpf_eg_int, Init_Bounds_For::exp_ctrl_lpf_knob() },
		{ ID::exp_lpf_type, Init_Bounds_For::exp_ctrl_lpf_type() },
		{ ID::exp_lpf_key_track, Init_Bounds_For::exp_ctrl_lpf_switch(true) },
		{ ID::exp_lpf_velo_amt, Init_Bounds_For::exp_ctrl_lpf_switch() },
		{ ID::exp_vca_env_attack, Init_Bounds_For::exp_ctrl_env_stage(1, true) },
		{ ID::exp_vca_env_decay, Init_Bounds_For::exp_ctrl_env_stage(2, true) },
		{ ID::exp_vca_env_sustain, Init_Bounds_For::exp_ctrl_env_stage(3, true) },
		{ ID::exp_vca_env_release, Init_Bounds_For::exp_ctrl_env_stage(4, true) },
		{ ID::exp_env_attack, Init_Bounds_For::exp_ctrl_env_stage(1) },
		{ ID::exp_env_decay, Init_Bounds_For::exp_ctrl_env_stage(2) },
		{ ID::exp_env_sustain, Init_Bounds_For::exp_ctrl_env_stage(3) },
		{ ID::exp_env_release, Init_Bounds_For::exp_ctrl_env_stage(4) },
		{ ID::exp_lfo_wave, Init_Bounds_For::exp_ctrl_lfo_switch(true) },
		{ ID::exp_lfo_eg_mod, Init_Bounds_For::exp_ctrl_lfo_switch() },
		{ ID::exp_lfo_rate, Init_Bounds_For::exp_ctrl_lfo_knob(true) },
		{ ID::exp_lfo_int, Init_Bounds_For::exp_ctrl_lfo_knob() },
		{ ID::exp_lfo_target, Init_Bounds_For::exp_ctrl_lfo_target() },
		{ ID::exp_delay_hpf_freq, Init_Bounds_For::exp_ctrl_delay_knob(1) },
		{ ID::exp_delay_time, Init_Bounds_For::exp_ctrl_delay_knob(2) },
		{ ID::exp_delay_feedback, Init_Bounds_For::exp_ctrl_delay_knob(3) },
		{ ID::exp_delay_routing, Init_Bounds_For::exp_ctrl_delay_routing() },
		{ ID::exp_voice_mode_depth, Init_Bounds_For::exp_ctrl_voice_mode_depth() },

		{ ID::gui_editor, Init_Bounds_For::gui_editor() },
	};

}
