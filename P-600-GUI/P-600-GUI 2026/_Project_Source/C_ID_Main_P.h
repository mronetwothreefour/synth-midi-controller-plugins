#pragma once

#include <array>

namespace ID
{

	constexpr auto exp_amp_env_attack = "exp_amp_env_attack";
	constexpr auto exp_amp_env_decay = "exp_amp_env_decay";
	constexpr auto exp_amp_env_release = "exp_amp_env_release";
	constexpr auto exp_amp_env_sustain = "exp_amp_env_sustain";
	constexpr auto exp_filter_cutoff = "exp_filter_cutoff";
	constexpr auto exp_filter_env_amt = "exp_filter_env_amt";
	constexpr auto exp_filter_env_attack = "exp_filter_env_attack";
	constexpr auto exp_filter_env_decay = "exp_filter_env_decay";
	constexpr auto exp_filter_env_release = "exp_filter_env_release";
	constexpr auto exp_filter_env_sustain = "exp_filter_env_sustain";
	constexpr auto exp_filter_key_track = "exp_filter_key_track";
	constexpr auto exp_filter_reso = "exp_filter_reso";
	constexpr auto exp_glide = "exp_glide";
	constexpr auto exp_lfo_dest_filter = "exp_lfo_dest_filter";
	constexpr auto exp_lfo_dest_osc_pitch = "exp_lfo_dest_osc_pitch";
	constexpr auto exp_lfo_dest_osc_pw = "exp_lfo_dest_osc_pw";
	constexpr auto exp_lfo_freq = "exp_lfo_freq";
	constexpr auto exp_lfo_init_amt = "exp_lfo_init_amt";
	constexpr auto exp_lfo_shape = "exp_lfo_shape";
	constexpr auto exp_mixer = "exp_mixer";
	constexpr auto exp_osc_a_pitch = "exp_osc_a_pitch";
	constexpr auto exp_osc_a_pulse = "exp_osc_a_pulse";
	constexpr auto exp_osc_a_pulse_w = "exp_osc_a_pulse_w";
	constexpr auto exp_osc_a_saw = "exp_osc_a_saw";
	constexpr auto exp_osc_a_sync = "exp_osc_a_sync";
	constexpr auto exp_osc_a_tri = "exp_osc_a_tri";
	constexpr auto exp_osc_b_fine = "exp_osc_b_fine";
	constexpr auto exp_osc_b_pitch = "exp_osc_b_pitch";
	constexpr auto exp_osc_b_pulse = "exp_osc_b_pulse";
	constexpr auto exp_osc_b_pulse_w = "exp_osc_b_pulse_w";
	constexpr auto exp_osc_b_saw = "exp_osc_b_saw";
	constexpr auto exp_osc_b_tri = "exp_osc_b_tri";
	constexpr auto exp_p_mod_amt_filter_env = "exp_p_mod_amt_filter_env";
	constexpr auto exp_p_mod_amt_osc_b = "exp_p_mod_amt_osc_b";
	constexpr auto exp_p_mod_dest_filter = "exp_p_mod_dest_filter";
	constexpr auto exp_p_mod_dest_osc_a_freq = "exp_p_mod_dest_osc_a_freq";
	constexpr auto exp_unison_track = "exp_unison_track";

	constexpr std::array<const char*, 37> exp_params{
		exp_unison_track,
		exp_osc_a_pitch,
		exp_osc_a_sync,
		exp_osc_a_saw,
		exp_osc_a_tri,
		exp_osc_a_pulse,
		exp_osc_a_pulse_w,
		exp_osc_b_pitch,
		exp_osc_b_fine,
		exp_osc_b_saw,
		exp_osc_b_tri,
		exp_osc_b_pulse,
		exp_osc_b_pulse_w,
		exp_mixer,
		exp_glide,
		exp_filter_cutoff,
		exp_filter_reso,
		exp_filter_env_amt,
		exp_filter_key_track,
		exp_filter_env_attack,
		exp_filter_env_decay,
		exp_filter_env_sustain,
		exp_filter_env_release,
		exp_amp_env_attack,
		exp_amp_env_decay,
		exp_amp_env_sustain,
		exp_amp_env_release,
		exp_p_mod_amt_filter_env,
		exp_p_mod_amt_osc_b,
		exp_p_mod_dest_osc_a_freq,
		exp_p_mod_dest_filter,
		exp_lfo_freq,
		exp_lfo_shape,
		exp_lfo_init_amt,
		exp_lfo_dest_osc_pitch,
		exp_lfo_dest_osc_pw,
		exp_lfo_dest_filter
	};

}
