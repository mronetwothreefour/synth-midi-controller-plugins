#pragma once

#include "C_ID_Main_P.h"
#include "D_BUILD_Bit_Locations_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, StringArray> bit_locations{
		{ ID::avp_amp_mod_by_velo_amt, Bit_Locations_For::avp_amp_mod_by_velo_amt() },
		{ ID::avp_fine_tune, Bit_Locations_For::avp_fine_tune() },
		{ ID::avp_flex_sli_bend_neg, Bit_Locations_For::avp_flex_sli_bend_limit() },
		{ ID::avp_flex_sli_bend_pos, Bit_Locations_For::avp_flex_sli_bend_limit(true) },
		{ ID::avp_flex_sli_range, Bit_Locations_For::avp_flex_sli_range() },
		{ ID::avp_flex_sli_target, Bit_Locations_For::avp_flex_sli_target() },
		{ ID::avp_keyboard_octave, Bit_Locations_For::avp_keyboard_octave() },
		{ ID::avp_level, Bit_Locations_For::avp_level() },
		{ ID::avp_lfo_sync_bpm_on, Bit_Locations_For::avp_lfo_sync_bpm_on() },
		{ ID::avp_lfo_sync_key_on, Bit_Locations_For::avp_lfo_sync_key_on() },
		{ ID::avp_lfo_sync_voice_on, Bit_Locations_For::avp_lfo_sync_voice_on() },
		{ ID::avp_microtune_scale, Bit_Locations_For::avp_microtune_scale() },
		{ ID::avp_porta_mode_on, Bit_Locations_For::avp_porta_mode_on() },
		{ ID::avp_porta_sync_bpm_on, Bit_Locations_For::avp_porta_sync_bpm_on() },
		{ ID::avp_porta_time, Bit_Locations_For::avp_porta_time() },
		{ ID::avp_scale_key, Bit_Locations_For::avp_scale_key() },
		{ ID::avp_transpose, Bit_Locations_For::avp_transpose() },
		{ ID::avp_voice_mode, Bit_Locations_For::avp_voice_mode() },

		//osc
		{ ID::exp_osc_1_octave, Bit_Locations_For::exp_osc_octave(1) },
		{ ID::exp_osc_1_wave, Bit_Locations_For::exp_osc_wave(1) },
		{ ID::exp_osc_1_pitch_fine, Bit_Locations_For::exp_osc_pitch_fine(1) },
		{ ID::exp_osc_1_shape, Bit_Locations_For::exp_osc_shape(1) },
		{ ID::exp_osc_2_octave, Bit_Locations_For::exp_osc_octave(2) },
		{ ID::exp_osc_2_wave, Bit_Locations_For::exp_osc_wave(2) },
		{ ID::exp_osc_2_pitch_fine, Bit_Locations_For::exp_osc_pitch_fine(2) },
		{ ID::exp_osc_2_shape, Bit_Locations_For::exp_osc_shape(2) },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, Bit_Locations_For::exp_osc_2_x_mod_depth() },
		{ ID::exp_osc_2_pitch_eg_int, Bit_Locations_For::exp_osc_2_pitch_eg_int() },
		{ ID::exp_osc_2_sync, Bit_Locations_For::exp_osc_2_sync() },
		{ ID::exp_osc_2_ring_mod, Bit_Locations_For::exp_osc_2_ring_mod() },
		//mix
		{ ID::exp_mix_osc_1, Bit_Locations_For::exp_mix(1) },
		{ ID::exp_mix_osc_2, Bit_Locations_For::exp_mix(2) },
		{ ID::exp_mix_noise, Bit_Locations_For::exp_mix(3) },
		//lpf
		{ ID::exp_lpf_freq, Bit_Locations_For::exp_lpf_freq() },
		{ ID::exp_lpf_reso, Bit_Locations_For::exp_lpf_reso() },
		{ ID::exp_lpf_eg_int, Bit_Locations_For::exp_lpf_eg_int() },
		{ ID::exp_lpf_type, Bit_Locations_For::exp_lpf_type() },
		{ ID::exp_lpf_key_track, Bit_Locations_For::exp_lpf_key_track() },
		{ ID::exp_lpf_velo_amt, Bit_Locations_For::exp_lpf_velo_amt() },
		//vca env
		{ ID::exp_vca_env_attack, Bit_Locations_For::exp_env_attack(true) },
		{ ID::exp_vca_env_decay, Bit_Locations_For::exp_env_decay(true) },
		{ ID::exp_vca_env_sustain, Bit_Locations_For::exp_env_sustain(true) },
		{ ID::exp_vca_env_release, Bit_Locations_For::exp_env_release(true) },
		//env
		{ ID::exp_env_attack, Bit_Locations_For::exp_env_attack() },
		{ ID::exp_env_decay, Bit_Locations_For::exp_env_decay() },
		{ ID::exp_env_sustain, Bit_Locations_For::exp_env_sustain() },
		{ ID::exp_env_release, Bit_Locations_For::exp_env_release() },
		//lfo
		{ ID::exp_lfo_wave, Bit_Locations_For::exp_lfo_wave() },
		{ ID::exp_lfo_eg_mod, Bit_Locations_For::exp_lfo_eg_mod() },
		{ ID::exp_lfo_rate, Bit_Locations_For::exp_lfo_rate() },
		{ ID::exp_lfo_int, Bit_Locations_For::exp_lfo_int() },
		{ ID::exp_lfo_target, Bit_Locations_For::exp_lfo_target() },
		//delay
		{ ID::exp_delay_hpf_freq, Bit_Locations_For::exp_delay_hpf_freq() },
		{ ID::exp_delay_time, Bit_Locations_For::exp_delay_time() },
		{ ID::exp_delay_feedback, Bit_Locations_For::exp_delay_feedback() },
		{ ID::exp_delay_routing, Bit_Locations_For::exp_delay_routing() },
		//voice mode depth
		{ ID::exp_voice_mode_depth, Bit_Locations_For::exp_voice_mode_depth() }
	};

}
