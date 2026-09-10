#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> ctrl_name{
		{ ID::avp_amp_mod_by_velo_amt, NAME::sli_knob },
		{ ID::avp_fine_tune, NAME::sli_knob },
		{ ID::avp_flex_sli_bend_neg, NAME::sli_knob },
		{ ID::avp_flex_sli_bend_pos, NAME::sli_knob },
		{ ID::avp_flex_sli_range, NAME::sli_knob },
		{ ID::avp_flex_sli_target, NAME::cbox },
		{ ID::avp_keyboard_octave, NAME::sli_switch_keyboard_octave },
		{ ID::avp_level, NAME::sli_knob },
		{ ID::avp_lfo_sync_bpm_on, NAME::sli_switch_2_pole },
		{ ID::avp_lfo_sync_key_on, NAME::sli_switch_2_pole },
		{ ID::avp_lfo_sync_voice_on, NAME::sli_switch_2_pole },
		{ ID::avp_microtune_scale, NAME::cbox },
		{ ID::avp_porta_mode_on, NAME::sli_switch_2_pole },
		{ ID::avp_porta_sync_bpm_on, NAME::sli_switch_2_pole },
		{ ID::avp_porta_time, NAME::sli_knob },
		{ ID::avp_scale_key, NAME::sli_knob },
		{ ID::avp_transpose, NAME::sli_knob },

		//osc
		{ ID::exp_osc_1_octave, NAME::sli_switch_osc_octave },
		{ ID::exp_osc_1_wave, NAME::sli_switch_3_pole },
		{ ID::exp_osc_1_pitch_fine, NAME::sli_knob },
		{ ID::exp_osc_1_shape, NAME::sli_knob },
		{ ID::exp_osc_2_octave, NAME::sli_switch_osc_octave },
		{ ID::exp_osc_2_wave, NAME::sli_switch_3_pole },
		{ ID::exp_osc_2_pitch_fine, NAME::sli_knob },
		{ ID::exp_osc_2_shape, NAME::sli_knob },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, NAME::sli_knob  },
		{ ID::exp_osc_2_pitch_eg_int, NAME::sli_knob },
		{ ID::exp_osc_2_sync, NAME::sli_switch_2_pole },
		{ ID::exp_osc_2_ring_mod, NAME::sli_switch_2_pole },
		//mix
		{ ID::exp_mix_osc_1, NAME::sli_knob },
		{ ID::exp_mix_osc_2, NAME::sli_knob },
		{ ID::exp_mix_noise, NAME::sli_knob },
		//lpf
		{ ID::exp_lpf_freq, NAME::sli_knob },
		{ ID::exp_lpf_reso, NAME::sli_knob },
		{ ID::exp_lpf_eg_int, NAME::sli_knob },
		{ ID::exp_lpf_type, NAME::sli_knob },
		{ ID::exp_lpf_key_track, NAME::sli_switch_3_pole },
		{ ID::exp_lpf_velo_amt, NAME::sli_switch_3_pole },
		//vca env
		{ ID::exp_vca_env_attack, NAME::sli_knob },
		{ ID::exp_vca_env_decay, NAME::sli_knob },
		{ ID::exp_vca_env_sustain, NAME::sli_knob },
		{ ID::exp_vca_env_release, NAME::sli_knob },
		//env
		{ ID::exp_env_attack, NAME::sli_knob },
		{ ID::exp_env_decay, NAME::sli_knob },
		{ ID::exp_env_sustain, NAME::sli_knob },
		{ ID::exp_env_release, NAME::sli_knob },
		//lfo
		{ ID::exp_lfo_wave, NAME::sli_switch_3_pole },
		{ ID::exp_lfo_eg_mod, NAME::sli_switch_3_pole },
		{ ID::exp_lfo_rate, NAME::sli_knob },
		{ ID::exp_lfo_int, NAME::sli_knob },
		{ ID::exp_lfo_target, NAME::sli_switch_3_pole },
		//delay
		{ ID::exp_delay_hpf_freq, NAME::sli_knob },
		{ ID::exp_delay_time, NAME::sli_knob },
		{ ID::exp_delay_feedback, NAME::sli_knob },
		{ ID::exp_delay_routing, NAME::sli_switch_3_pole },
		//voice mode depth
		{ ID::exp_voice_mode_depth, NAME::sli_knob }
	};

}
