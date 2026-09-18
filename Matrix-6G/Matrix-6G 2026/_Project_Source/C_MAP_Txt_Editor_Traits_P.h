#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace MISC;
using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> txt_editor_traits {
		{ ID::exp_osc_1_pitch, txt_editor_traits_osc_pitch },
		{ ID::exp_osc_1_pulse_w, txt_editor_traits_u_6_bit },
		{ ID::exp_osc_1_saw_tri, txt_editor_traits_u_6_bit },
		{ ID::exp_osc_1_lfo_1_fm, txt_editor_traits_s_6_bit },
		{ ID::exp_osc_1_lfo_2_pwm, txt_editor_traits_s_6_bit },
		{ ID::exp_osc_2_pitch, txt_editor_traits_osc_pitch },
		{ ID::exp_osc_2_pulse_w, txt_editor_traits_u_6_bit },
		{ ID::exp_osc_2_saw_tri, txt_editor_traits_u_6_bit },
		{ ID::exp_osc_2_detune, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(31) } },
		{ ID::exp_osc_2_lfo_1_fm, txt_editor_traits_s_6_bit },
		{ ID::exp_osc_2_lfo_2_pwm, txt_editor_traits_s_6_bit },
		{ ID::exp_osc_balance, txt_editor_traits_u_6_bit },
		{ ID::exp_vcf_freq, txt_editor_traits_u_7_bit },
		{ ID::exp_vcf_reso, txt_editor_traits_u_6_bit },
		{ ID::exp_vcf_reso, txt_editor_traits_u_6_bit },
		{ ID::exp_vcf_env_1_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_vcf_press_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_vca_1_volume, txt_editor_traits_u_6_bit },
		{ ID::exp_vca_1_velo_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_vca_2_env_2_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_vcf_fm_osc_1_amt, txt_editor_traits_u_6_bit },
		{ ID::exp_vcf_fm_env_3_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_vcf_fm_press_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_porta_rate, txt_editor_traits_u_6_bit },
		{ ID::exp_porta_velo, txt_editor_traits_s_6_bit },
		{ ID::exp_lfo_1_speed, txt_editor_traits_u_6_bit },
		{ ID::exp_lfo_1_amp, txt_editor_traits_u_6_bit },
		{ ID::exp_lfo_1_press_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_lfo_1_ramp_1_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_lfo_1_retrig_point, txt_editor_traits_u_6_bit },
		{ ID::exp_lfo_2_speed, txt_editor_traits_u_6_bit },
		{ ID::exp_lfo_2_amp, txt_editor_traits_u_6_bit },
		{ ID::exp_lfo_2_key_track_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_lfo_2_ramp_2_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_lfo_2_retrig_point, txt_editor_traits_u_6_bit },
		{ ID::exp_ramp_1_rate, txt_editor_traits_u_6_bit },
		{ ID::exp_ramp_2_rate, txt_editor_traits_u_6_bit },
		{ ID::exp_track_point_1, txt_editor_traits_u_6_bit },
		{ ID::exp_track_point_2, txt_editor_traits_u_6_bit },
		{ ID::exp_track_point_3, txt_editor_traits_u_6_bit },
		{ ID::exp_track_point_4, txt_editor_traits_u_6_bit },
		{ ID::exp_track_point_5, txt_editor_traits_u_6_bit },
		{ ID::exp_env_1_amp, txt_editor_traits_u_6_bit },
		{ ID::exp_env_1_velo_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_env_1_delay, txt_editor_traits_u_6_bit },
		{ ID::exp_env_1_attack, txt_editor_traits_u_6_bit },
		{ ID::exp_env_1_decay, txt_editor_traits_u_6_bit },
		{ ID::exp_env_1_sustain, txt_editor_traits_u_6_bit },
		{ ID::exp_env_1_release, txt_editor_traits_u_6_bit },
		{ ID::exp_env_2_amp, txt_editor_traits_u_6_bit },
		{ ID::exp_env_2_velo_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_env_2_delay, txt_editor_traits_u_6_bit },
		{ ID::exp_env_2_attack, txt_editor_traits_u_6_bit },
		{ ID::exp_env_2_decay, txt_editor_traits_u_6_bit },
		{ ID::exp_env_2_sustain, txt_editor_traits_u_6_bit },
		{ ID::exp_env_2_release, txt_editor_traits_u_6_bit },
		{ ID::exp_env_3_amp, txt_editor_traits_u_6_bit },
		{ ID::exp_env_3_velo_amt, txt_editor_traits_s_6_bit },
		{ ID::exp_env_3_delay, txt_editor_traits_u_6_bit },
		{ ID::exp_env_3_attack, txt_editor_traits_u_6_bit },
		{ ID::exp_env_3_decay, txt_editor_traits_u_6_bit },
		{ ID::exp_env_3_sustain, txt_editor_traits_u_6_bit },
		{ ID::exp_env_3_release, txt_editor_traits_u_6_bit },

		{ ID::mmod_0_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_1_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_2_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_3_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_4_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_5_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_6_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_7_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_8_amt, txt_editor_traits_s_6_bit },
		{ ID::mmod_9_amt, txt_editor_traits_s_6_bit },
	};

}
