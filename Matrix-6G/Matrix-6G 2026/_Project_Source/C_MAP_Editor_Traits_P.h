#pragma once

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

	static const unordered_map<string, tuple<string, int, string>> editor_traits {
		{ ID::exp_osc_1_pitch, { allowed_chars_pitch, 3, Tip_For::txt_editor_pitch(25, 0, 63) } },
		{ ID::exp_osc_1_pulse_w, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_osc_1_saw_tri, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_osc_1_lfo_1_fm, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_osc_1_lfo_2_pwm, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_osc_2_pitch, { allowed_chars_pitch, 3, Tip_For::txt_editor_pitch(25, 0, 63) } },
		{ ID::exp_osc_2_pulse_w, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_osc_2_saw_tri, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_osc_2_detune, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(31) } },
		{ ID::exp_osc_2_lfo_1_fm, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_osc_2_lfo_2_pwm, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_osc_balance, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_vcf_freq, { allowed_chars_u_int, 3, Tip_For::txt_editor_u_int(127) } },
		{ ID::exp_vcf_reso, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_vcf_reso, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_vcf_env_1_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_vcf_press_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_vca_1_volume, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_vca_1_velo_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_vca_2_env_2_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_vcf_fm_osc_1_amt, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_vcf_fm_env_3_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_vcf_fm_press_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_porta_rate, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_porta_velo, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_lfo_1_speed, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_lfo_1_amp, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_lfo_1_press_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_lfo_1_ramp_1_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_lfo_1_retrig_point, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_lfo_2_speed, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_lfo_2_amp, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_lfo_2_key_track_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_lfo_2_ramp_2_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_lfo_2_retrig_point, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_ramp_1_rate, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_ramp_2_rate, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_track_point_1, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_track_point_2, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_track_point_3, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_track_point_4, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_track_point_5, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_1_amp, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_1_velo_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_env_1_delay, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_1_attack, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_1_decay, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_1_sustain, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_1_release, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_2_amp, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_2_velo_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_env_2_delay, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_2_attack, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_2_decay, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_2_sustain, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_2_release, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_3_amp, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_3_velo_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::exp_env_3_delay, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_3_attack, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_3_decay, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_3_sustain, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },
		{ ID::exp_env_3_release, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) } },

		{ ID::mmod_0_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_1_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_2_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_3_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_4_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_5_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_6_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_7_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_8_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
		{ ID::mmod_9_amt, { allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) } },
	};

}
