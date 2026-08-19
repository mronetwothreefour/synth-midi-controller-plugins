#pragma once

#include "C_ENUM_P.h"
#include "C_ID_Aux_Voice_P.h"
#include "C_ID_Exp_P.h"

using namespace ENUM;

namespace MAP
{

	static const std::unordered_map<String, int> init_choice{
		{ ID::avp_amp_mod_by_velo_amt, 0 },
		{ ID::avp_fine_tune, 50 },
		{ ID::avp_flex_sli_bend_neg, 200 },
		{ ID::avp_flex_sli_bend_pos, 0 },
		{ ID::avp_flex_sli_range, 0 },
		{ ID::avp_flex_sli_target, (int)Flex_Slider_Target::pitch_bend },
		{ ID::avp_keyboard_octave, 2 },
		{ ID::avp_level, 25 },
		{ ID::avp_lfo_sync_bpm_on, 0 },
		{ ID::avp_lfo_sync_key_on, 1 },
		{ ID::avp_lfo_sync_voice_on, 1 },
		{ ID::avp_microtune_scale, (int)Microtune_Scale::equal_temp },
		{ ID::avp_name, -1 },
		{ ID::avp_porta_mode_on, 0 },
		{ ID::avp_porta_sync_bpm_on, 0 },
		{ ID::avp_porta_time, 0 },
		{ ID::avp_scale_key, 12 },
		{ ID::avp_transpose, 12 },
		{ ID::avp_voice_mode, (int)Voice_Mode::poly },

		//osc
		{ ID::exp_osc_1_octave, 1 },
		{ ID::exp_osc_1_wave, 2 },
		{ ID::exp_osc_1_pitch_fine, 512 },
		{ ID::exp_osc_1_shape, 0 },
		{ ID::exp_osc_2_octave, 1 },
		{ ID::exp_osc_2_wave, 2 },
		{ ID::exp_osc_2_pitch_fine, 512 },
		{ ID::exp_osc_2_shape, 0 },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, 0 },
		{ ID::exp_osc_2_pitch_eg_int, 512 },
		{ ID::exp_osc_2_sync, 0 },
		{ ID::exp_osc_2_ring_mod, 0 },
		//mix
		{ ID::exp_mix_osc_1, 1023 },
		{ ID::exp_mix_osc_2, 0 },
		{ ID::exp_mix_noise, 0 },
		//lpf
		{ ID::exp_lpf_freq, 1023 },
		{ ID::exp_lpf_reso, 0 },
		{ ID::exp_lpf_eg_int, 512 },
		{ ID::exp_lpf_type, 1 },
		{ ID::exp_lpf_key_track, 0 },
		{ ID::exp_lpf_velo_amt, 0 },
		//vca env
		{ ID::exp_vca_env_attack, 0 },
		{ ID::exp_vca_env_decay, 512 },
		{ ID::exp_vca_env_sustain, 1023 },
		{ ID::exp_vca_env_release, 0 },
		//env
		{ ID::exp_env_attack, 0 },
		{ ID::exp_env_decay, 512 },
		{ ID::exp_env_sustain, 0 },
		{ ID::exp_env_release, 0 },
		//lfo
		{ ID::exp_lfo_wave, 1 },
		{ ID::exp_lfo_eg_mod, 0 },
		{ ID::exp_lfo_rate, 512 },
		{ ID::exp_lfo_int, 0 },
		{ ID::exp_lfo_target, 2 },
		//delay
		{ ID::exp_delay_hpf_freq, 256 },
		{ ID::exp_delay_time, 1023 },
		{ ID::exp_delay_feedback, 512 },
		{ ID::exp_delay_routing, 0 },
		//voice mode depth
		{ ID::exp_voice_mode_depth, 0 }
	};

}
