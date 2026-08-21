#pragma once

#include "C_ID_Aux_Voice_P.h"
#include "C_ID_Exp_P.h"
#include "C_SL_Tip_Aux_Voice_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "D_BUILD_Tip_For_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> tip{

		{ ID::avp_amp_mod_by_velo_amt, Tip_For::from_string_literal(SL::amp_mod_by_velo_amt_tip) },
		{ ID::avp_fine_tune, Tip_For::from_string_literal(SL::fine_tune_tip) },
		{ ID::avp_flex_sli_bend_neg, Tip_For::from_string_literal(SL::flex_sli_bend_neg_tip) },
		{ ID::avp_flex_sli_bend_pos, Tip_For::from_string_literal(SL::flex_sli_bend_pos_tip) },
		{ ID::avp_flex_sli_range, Tip_For::from_string_literal(SL::flex_sli_range_tip) },
		{ ID::avp_flex_sli_target, Tip_For::from_string_literal(SL::flex_sli_target_tip) },
		{ ID::avp_keyboard_octave, Tip_For::from_string_literal(SL::keyboard_octave_tip) },
		{ ID::avp_level, Tip_For::from_string_literal(SL::level_tip) },
		{ ID::avp_lfo_sync_bpm_on, Tip_For::from_string_literal(SL::lfo_sync_bpm_on_tip) },
		{ ID::avp_lfo_sync_key_on, Tip_For::from_string_literal(SL::lfo_sync_key_on_tip) },
		{ ID::avp_lfo_sync_voice_on, Tip_For::from_string_literal(SL::lfo_sync_voice_on_tip) },
		{ ID::avp_microtune_scale, Tip_For::from_string_literal(SL::microtune_scale_tip) },
		{ ID::avp_porta_mode_on, Tip_For::from_string_literal(SL::porta_mode_on_tip) },
		{ ID::avp_porta_sync_bpm_on, Tip_For::from_string_literal(SL::porta_sync_bpm_on_tip) },
		{ ID::avp_porta_time, Tip_For::from_string_literal(SL::porta_time_tip) },
		{ ID::avp_scale_key, Tip_For::from_string_literal(SL::scale_key_tip) },
		{ ID::avp_transpose, Tip_For::from_string_literal(SL::transpose_tip) },
		{ ID::avp_voice_mode, Tip_For::from_string_literal(SL::voice_mode_tip) },

		//osc
		{ ID::exp_osc_1_octave, BUILD::Tip_For::exp_osc_octave(1) },
		{ ID::exp_osc_1_wave, BUILD::Tip_For::exp_osc_wave(1) },
		{ ID::exp_osc_1_pitch_fine, BUILD::Tip_For::exp_osc_pitch_fine(1) },
		{ ID::exp_osc_1_shape, BUILD::Tip_For::exp_osc_shape(1) },
		{ ID::exp_osc_2_octave, BUILD::Tip_For::exp_osc_octave(2) },
		{ ID::exp_osc_2_wave, BUILD::Tip_For::exp_osc_wave(2) },
		{ ID::exp_osc_2_pitch_fine, BUILD::Tip_For::exp_osc_pitch_fine(2) },
		{ ID::exp_osc_2_shape, BUILD::Tip_For::exp_osc_shape(2) },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, Tip_For::from_string_literal(SL::osc_2_x_mod_depth_tip) },
		{ ID::exp_osc_2_pitch_eg_int, Tip_For::from_string_literal(SL::osc_2_pitch_eg_int_tip) },
		{ ID::exp_osc_2_sync, Tip_For::from_string_literal(SL::osc_2_sync_tip) },
		{ ID::exp_osc_2_ring_mod, Tip_For::from_string_literal(SL::osc_2_ring_mod_tip) },
		//mix
		{ ID::exp_mix_osc_1, BUILD::Tip_For::exp_level_knob(1)},
		{ ID::exp_mix_osc_2, BUILD::Tip_For::exp_level_knob(2) },
		{ ID::exp_mix_noise, BUILD::Tip_For::exp_level_knob(3) },
		//lpf
		{ ID::exp_lpf_freq, Tip_For::from_string_literal(SL::lpf_freq_tip) },
		{ ID::exp_lpf_reso, Tip_For::from_string_literal(SL::lpf_reso_tip) },
		{ ID::exp_lpf_eg_int, Tip_For::from_string_literal(SL::lpf_eg_int_tip) },
		{ ID::exp_lpf_type, Tip_For::from_string_literal(SL::lpf_type_tip) },
		{ ID::exp_lpf_key_track, Tip_For::from_string_literal(SL::lpf_key_track_tip) },
		{ ID::exp_lpf_velo_amt, Tip_For::from_string_literal(SL::lpf_velo_amt_tip) },
		//vca env
		{ ID::exp_vca_env_attack, BUILD::Tip_For::exp_env_attack(true) },
		{ ID::exp_vca_env_decay, BUILD::Tip_For::exp_env_decay(true) },
		{ ID::exp_vca_env_sustain, BUILD::Tip_For::exp_env_sustain(true) },
		{ ID::exp_vca_env_release, BUILD::Tip_For::exp_env_release(true) },
		//env
		{ ID::exp_env_attack, BUILD::Tip_For::exp_env_attack() },
		{ ID::exp_env_decay, BUILD::Tip_For::exp_env_decay() },
		{ ID::exp_env_sustain, BUILD::Tip_For::exp_env_sustain() },
		{ ID::exp_env_release, BUILD::Tip_For::exp_env_release() },
		//lfo
		{ ID::exp_lfo_wave, Tip_For::from_string_literal(SL::lfo_wave_tip) },
		{ ID::exp_lfo_eg_mod, Tip_For::from_string_literal(SL::lfo_eg_mod_tip) },
		{ ID::exp_lfo_rate, Tip_For::from_string_literal(SL::lfo_rate_tip) },
		{ ID::exp_lfo_int, Tip_For::from_string_literal(SL::lfo_int_tip) },
		{ ID::exp_lfo_target, Tip_For::from_string_literal(SL::lfo_target_tip) },
		//delay
		{ ID::exp_delay_hpf_freq, Tip_For::from_string_literal(SL::delay_hpf_freq_tip) },
		{ ID::exp_delay_time, Tip_For::from_string_literal(SL::delay_time_tip) },
		{ ID::exp_delay_feedback, Tip_For::from_string_literal(SL::delay_feedback_tip) },
		{ ID::exp_delay_routing, Tip_For::from_string_literal(SL::delay_routing_tip) },
		//voice mode depth
		{ ID::exp_voice_mode_depth, Tip_For::from_string_literal(SL::voice_mode_depth_tip) }
	};

}
