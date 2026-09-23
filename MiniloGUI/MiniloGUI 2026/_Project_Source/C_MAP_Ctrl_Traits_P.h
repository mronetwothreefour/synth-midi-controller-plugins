#pragma once

#include <tuple>
#include <unordered_map>

#include "C_ENUM_P.h"
#include "C_ID_Main_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Aux_Voice_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace ENUM;
using namespace NAME;
using namespace std;

using Tip = Tip_For;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> ctrl_traits{
		{ ID::avp_amp_mod_by_velo_amt, { ctr_sli_knb, 0, Tip::from_SL(SL::amp_mod_by_velo_amt_tip) } },
		{ ID::avp_fine_tune, { ctr_sli_knb, 50, Tip::from_SL(SL::fine_tune_tip) } },
		{ ID::avp_flex_sli_bend_neg, { ctr_sli_knb, 1, Tip::from_SL(SL::flex_sli_bend_neg_tip) } },
		{ ID::avp_flex_sli_bend_pos, { ctr_sli_knb, 1, Tip::from_SL(SL::flex_sli_bend_pos_tip) } },
		{ ID::avp_flex_sli_range, { ctr_sli_knb, 200, Tip::from_SL(SL::flex_sli_range_tip) } },
		{ ID::avp_flex_sli_target, { ctr_cbx, (int)Flex_Sli_Target::pitch_bend, Tip::from_SL(SL::flex_sli_target_tip) } },
		{ ID::avp_keyboard_octave, { ctr_sli_sw_key_octv, 2, Tip::from_SL(SL::keyboard_octave_tip) } },
		{ ID::avp_level, { ctr_sli_knb, 25, Tip::from_SL(SL::level_tip) } },
		{ ID::avp_lfo_sync_bpm_on, { ctr_sli_sw_2, 0, Tip::from_SL(SL::lfo_sync_bpm_on_tip) } },
		{ ID::avp_lfo_sync_key_on, { ctr_sli_sw_2, 1, Tip::from_SL(SL::lfo_sync_key_on_tip) } },
		{ ID::avp_lfo_sync_voice_on, { ctr_sli_sw_2, 1, Tip::from_SL(SL::lfo_sync_voice_on_tip) } },
		{ ID::avp_microtune_scale, { ctr_cbx, (int)Micro_Scale::equal_temp, Tip::from_SL(SL::microtune_scale_tip) } },
		{ ID::avp_porta_mode_on, { ctr_sli_sw_2, 0, Tip::from_SL(SL::porta_mode_on_tip) } },
		{ ID::avp_porta_sync_bpm_on, { ctr_sli_sw_2, 0, Tip::from_SL(SL::porta_sync_bpm_on_tip) } },
		{ ID::avp_porta_time, { ctr_sli_knb, 0, Tip::from_SL(SL::porta_time_tip) } },
		{ ID::avp_scale_key, { ctr_sli_knb, 12, Tip::from_SL(SL::scale_key_tip) } },
		{ ID::avp_transpose, { ctr_sli_knb, 12, Tip::from_SL(SL::transpose_tip) } },
		{ ID::avp_voice_mode, { ctr_voice_mode, (int)Voice_Mode::poly, Tip::from_SL(SL::voice_mode_tip) } },

		//osc
		{ ID::exp_osc_1_octave, { ctr_sli_sw_osc_octv, 1, Tip::exp_osc_octave(1) } },
		{ ID::exp_osc_1_wave, { ctr_sli_sw_3, 2, Tip::exp_osc_wave(1) } },
		{ ID::exp_osc_1_pitch_fine, { ctr_sli_knb, 512, Tip::exp_osc_pitch_fine(1) } },
		{ ID::exp_osc_1_shape, { ctr_sli_knb, 0, Tip::exp_osc_shape(1) } },
		{ ID::exp_osc_2_octave, { ctr_sli_sw_osc_octv, 1, Tip::exp_osc_octave(2) } },
		{ ID::exp_osc_2_wave, { ctr_sli_sw_3, 2, Tip::exp_osc_wave(2) } },
		{ ID::exp_osc_2_pitch_fine, { ctr_sli_knb, 512, Tip::exp_osc_pitch_fine(2) } },
		{ ID::exp_osc_2_shape, { ctr_sli_knb, 0, Tip::exp_osc_shape(2) } },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, { ctr_sli_knb, 0, Tip::from_SL(SL::osc_2_x_mod_depth_tip) } },
		{ ID::exp_osc_2_pitch_eg_int, { ctr_sli_knb, 512, Tip::from_SL(SL::osc_2_pitch_eg_int_tip) } },
		{ ID::exp_osc_2_sync, { ctr_sli_sw_2, 0, Tip::from_SL(SL::osc_2_sync_tip) } },
		{ ID::exp_osc_2_ring_mod, { ctr_sli_sw_2, 0, Tip::from_SL(SL::osc_2_ring_mod_tip) } },
		//mix
		{ ID::exp_mix_osc_1, { ctr_sli_knb, 1023, Tip::exp_level_knob(1) } },
		{ ID::exp_mix_osc_2, { ctr_sli_knb, 0, Tip::exp_level_knob(2) } },
		{ ID::exp_mix_noise, { ctr_sli_knb, 0, Tip::exp_level_knob(3) } },
		//lpf
		{ ID::exp_lpf_freq, { ctr_sli_knb, 1023, Tip::from_SL(SL::lpf_freq_tip) } },
		{ ID::exp_lpf_reso, { ctr_sli_knb, 0, Tip::from_SL(SL::lpf_reso_tip) } },
		{ ID::exp_lpf_eg_int, { ctr_sli_knb, 512, Tip::from_SL(SL::lpf_eg_int_tip) } },
		{ ID::exp_lpf_type, { ctr_sli_sw_lpf, 1, Tip::from_SL(SL::lpf_type_tip) } },
		{ ID::exp_lpf_key_track, { ctr_sli_sw_3, 0, Tip::from_SL(SL::lpf_key_track_tip) } },
		{ ID::exp_lpf_velo_amt, { ctr_sli_sw_3, 0, Tip::from_SL(SL::lpf_velo_amt_tip) } },
		//vca env
		{ ID::exp_vca_env_attack, { ctr_sli_knb, 0, Tip::exp_env_attack(true) } },
		{ ID::exp_vca_env_decay, { ctr_sli_knb, 512, Tip::exp_env_decay(true) } },
		{ ID::exp_vca_env_sustain, { ctr_sli_knb, 1023, Tip::exp_env_sustain(true) } },
		{ ID::exp_vca_env_release, { ctr_sli_knb, 0, Tip::exp_env_release(true) } },
		//env
		{ ID::exp_env_attack, { ctr_sli_knb, 0, Tip::exp_env_attack() } },
		{ ID::exp_env_decay, { ctr_sli_knb, 512, Tip::exp_env_decay() } },
		{ ID::exp_env_sustain, { ctr_sli_knb, 0, Tip::exp_env_sustain() } },
		{ ID::exp_env_release, { ctr_sli_knb, 0, Tip::exp_env_release() } },
		//lfo
		{ ID::exp_lfo_wave, { ctr_sli_sw_3, 1, Tip::from_SL(SL::lfo_wave_tip) } },
		{ ID::exp_lfo_eg_mod, { ctr_sli_sw_3, 0, Tip::from_SL(SL::lfo_eg_mod_tip) } },
		{ ID::exp_lfo_rate, { ctr_sli_knb, 512, Tip::from_SL(SL::lfo_rate_tip) } },
		{ ID::exp_lfo_int, { ctr_sli_knb, 0, Tip::from_SL(SL::lfo_int_tip) } },
		{ ID::exp_lfo_target, { ctr_sli_sw_3, 2, Tip::from_SL(SL::lfo_target_tip) } },
		//delay
		{ ID::exp_delay_hpf_freq, { ctr_sli_knb, 256, Tip::from_SL(SL::delay_hpf_freq_tip) } },
		{ ID::exp_delay_time, { ctr_sli_knb, 1023, Tip::from_SL(SL::delay_time_tip) } },
		{ ID::exp_delay_feedback, { ctr_sli_knb, 512, Tip::from_SL(SL::delay_feedback_tip) } },
		{ ID::exp_delay_routing, { ctr_sli_sw_3, 0, Tip::from_SL(SL::delay_routing_tip) } },
		//voice mode depth
		{ ID::exp_voice_mode_depth, { ctr_sli_knb, 0, Tip::from_SL(SL::voice_mode_depth_tip) } }
	};

}