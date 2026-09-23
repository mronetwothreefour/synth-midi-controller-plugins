#pragma once

#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace NAME;
using namespace std;

using Tip = Tip_For;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> ctrl_traits{
		//osc
		{ exp_unison_track, { ctr_sli_sw_2, 0, Tip::from_SL(SL::unison_track_tip) } },
		{ exp_osc_a_pitch, { ctr_sli_knb, 12, Tip::exp_osc_pitch("A") } },
		{ exp_osc_a_sync, { ctr_sli_sw_2, 0, Tip::from_SL(SL::osc_a_sync_tip) } },
		{ exp_osc_a_saw, { ctr_sli_sw_2, 0, Tip::exp_osc_saw("A") } },
		{ exp_osc_a_tri, { ctr_sli_sw_2, 1, Tip::exp_osc_tri("A") } },
		{ exp_osc_a_pulse, { ctr_sli_sw_2, 0, Tip::exp_osc_pulse("A") } },
		{ exp_osc_a_pulse_w, { ctr_sli_knb, 64, Tip::exp_osc_pulse_w("A") } },
		{ exp_osc_b_pitch, { ctr_sli_knb, 12, Tip::exp_osc_pitch("B") } },
		{ exp_osc_b_fine, { ctr_sli_knb, 0, Tip::from_SL(SL::osc_b_fine_tip) } },
		{ exp_osc_b_saw, { ctr_sli_sw_2, 0, Tip::exp_osc_saw("B") } },
		{ exp_osc_b_tri, { ctr_sli_sw_2, 1, Tip::exp_osc_tri("B") } },
		{ exp_osc_b_pulse, { ctr_sli_sw_2, 0, Tip::exp_osc_pulse("B") } },
		{ exp_osc_b_pulse_w, { ctr_sli_knb, 64, Tip::exp_osc_pulse_w("B") } },
		{ exp_mixer, { ctr_sli_knb, 32, Tip::from_SL(SL::mixer_tip) } },
		{ exp_glide, { ctr_sli_knb, 0, Tip::from_SL(SL::glide_tip) } },
		//filter
		{ exp_filter_cutoff, { ctr_sli_knb, 64, Tip::from_SL(SL::filter_cutoff_tip) } },
		{ exp_filter_reso, { ctr_sli_knb, 32, Tip::from_SL(SL::filter_reso_tip) } },
		{ exp_filter_env_amt, { ctr_sli_knb, 0, Tip::from_SL(SL::filter_env_amt_tip) } },
		{ exp_filter_key_track, { ctr_sli_sw_3, 2, Tip::from_SL(SL::filter_key_track_tip) } },
		{ exp_filter_env_attack, { ctr_sli_knb, 0, Tip::exp_env_stage(0, true) } },
		{ exp_filter_env_decay, { ctr_sli_knb, 0, Tip::exp_env_stage(1, true) } },
		{ exp_filter_env_sustain, { ctr_sli_knb, 0, Tip::exp_env_stage(2, true) } },
		{ exp_filter_env_release, { ctr_sli_knb, 0, Tip::exp_env_stage(3, true) } },
		//amp
		{ exp_amp_env_attack, { ctr_sli_knb, 0, Tip::exp_env_stage(0) } },
		{ exp_amp_env_decay, { ctr_sli_knb, 0, Tip::exp_env_stage(1) } },
		{ exp_amp_env_sustain, { ctr_sli_knb, 15, Tip::exp_env_stage(2) } },
		{ exp_amp_env_release, { ctr_sli_knb, 0, Tip::exp_env_stage(3) } },
		//poly-mod
		{ exp_p_mod_amt_filter_env, { ctr_sli_knb, 0, Tip::from_SL(SL::poly_mod_src_osc_b_amt_tip) } },
		{ exp_p_mod_amt_osc_b, { ctr_sli_knb, 0, Tip::from_SL(SL::poly_mod_src_osc_b_amt_tip) } },
		{ exp_p_mod_dest_osc_a_freq, { ctr_sli_sw_2, 0, Tip::from_SL(SL::poly_mod_dest_osc_a_pitch_tip) } },
		{ exp_p_mod_dest_filter, { ctr_sli_sw_2, 0, Tip::from_SL(SL::poly_mod_dest_filter_freq_tip) } },
		//lfo
		{ exp_lfo_freq, { ctr_sli_knb, 0, Tip::from_SL(SL::lfo_freq_tip) } },
		{ exp_lfo_shape, { ctr_sli_sw_2, 1, Tip::from_SL(SL::lfo_shape_tip) } },
		{ exp_lfo_init_amt, { ctr_sli_knb, 0, Tip::from_SL(SL::lfo_init_amt_tip) } },
		{ exp_lfo_dest_osc_pitch, { ctr_sli_sw_2, 0, Tip::from_SL(SL::lfo_dest_osc_pitch_tip) } },
		{ exp_lfo_dest_osc_pw, { ctr_sli_sw_2, 0, Tip::from_SL(SL::lfo_dest_osc_pw_tip) } },
		{ exp_lfo_dest_filter, { ctr_sli_sw_2, 0, Tip::from_SL(SL::lfo_dest_filter_tip) } },
	};

}