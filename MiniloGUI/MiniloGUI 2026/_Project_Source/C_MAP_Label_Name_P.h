#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> label_name{
		{ ID::avp_amp_mod_by_velo_amt, NAME::lbl_u_7_bit_int },
		{ ID::avp_fine_tune, NAME::lbl_fine_tune_and_level },
		{ ID::avp_flex_sli_bend_neg, NAME::lbl_flex_sli_bend_neg },
		{ ID::avp_flex_sli_bend_pos, NAME::lbl_flex_sli_bend_pos },
		{ ID::avp_flex_sli_range, NAME::lbl_flex_sli_range },
		{ ID::avp_flex_sli_target, NAME::lbl_cbox },
		{ ID::avp_keyboard_octave, "" },
		{ ID::avp_level, NAME::lbl_fine_tune_and_level },
		{ ID::avp_lfo_sync_bpm_on, "" },
		{ ID::avp_lfo_sync_key_on, "" },
		{ ID::avp_lfo_sync_voice_on, "" },
		{ ID::avp_microtune_scale, NAME::lbl_cbox },
		{ ID::avp_name, "" },
		{ ID::avp_porta_mode_on,"" },
		{ ID::avp_porta_sync_bpm_on, "" },
		{ ID::avp_porta_time, NAME::lbl_porta_time },
		{ ID::avp_scale_key, NAME::lbl_scale_key },
		{ ID::avp_transpose, NAME::lbl_transpose },
		{ ID::avp_voice_mode, "" },

		//osc
		{ ID::exp_osc_1_octave, "" },
		{ ID::exp_osc_1_wave, "" },
		{ ID::exp_osc_1_pitch_fine, NAME::lbl_osc_pitch_fine },
		{ ID::exp_osc_1_shape, NAME::lbl_u_10_bit_int },
		{ ID::exp_osc_2_octave, "" },
		{ ID::exp_osc_2_wave, "" },
		{ ID::exp_osc_2_pitch_fine, NAME::lbl_osc_pitch_fine },
		{ ID::exp_osc_2_shape, NAME::lbl_u_10_bit_int },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, NAME::lbl_u_10_bit_int  },
		{ ID::exp_osc_2_pitch_eg_int, NAME::lbl_osc_2_pitch_eg_int },
		{ ID::exp_osc_2_sync, "" },
		{ ID::exp_osc_2_ring_mod, "" },
		//mix
		{ ID::exp_mix_osc_1, NAME::lbl_u_10_bit_int },
		{ ID::exp_mix_osc_2, NAME::lbl_u_10_bit_int },
		{ ID::exp_mix_noise, NAME::lbl_u_10_bit_int },
		//lpf
		{ ID::exp_lpf_freq, NAME::lbl_u_10_bit_int },
		{ ID::exp_lpf_reso, NAME::lbl_u_10_bit_int },
		{ ID::exp_lpf_eg_int, NAME::lbl_lpf_eg_int },
		{ ID::exp_lpf_type, "" },
		{ ID::exp_lpf_key_track, "" },
		{ ID::exp_lpf_velo_amt, "" },
		//vca env
		{ ID::exp_vca_env_attack, NAME::lbl_u_10_bit_int },
		{ ID::exp_vca_env_decay, NAME::lbl_u_10_bit_int },
		{ ID::exp_vca_env_sustain, NAME::lbl_u_10_bit_int },
		{ ID::exp_vca_env_release, NAME::lbl_u_10_bit_int },
		//env
		{ ID::exp_env_attack, NAME::lbl_u_10_bit_int },
		{ ID::exp_env_decay, NAME::lbl_u_10_bit_int },
		{ ID::exp_env_sustain, NAME::lbl_u_10_bit_int },
		{ ID::exp_env_release, NAME::lbl_u_10_bit_int },
		//lfo
		{ ID::exp_lfo_wave, "" },
		{ ID::exp_lfo_eg_mod, "" },
		{ ID::exp_lfo_rate, NAME::lbl_lfo_rate },
		{ ID::exp_lfo_int, NAME::lbl_u_10_bit_int },
		{ ID::exp_lfo_target, "" },
		//delay
		{ ID::exp_delay_hpf_freq, NAME::lbl_u_10_bit_int },
		{ ID::exp_delay_time, NAME::lbl_u_10_bit_int },
		{ ID::exp_delay_feedback, NAME::lbl_u_10_bit_int },
		{ ID::exp_delay_routing, "" },
		//voice mode depth
		{ ID::exp_voice_mode_depth, NAME::lbl_voice_mode_depth }
	};

}
