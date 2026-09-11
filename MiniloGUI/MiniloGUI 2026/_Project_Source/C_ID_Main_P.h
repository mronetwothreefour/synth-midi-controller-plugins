#pragma once

#include <array>

namespace ID
{

	constexpr auto avp_amp_mod_by_velo_amt = "avp_amp_mod_by_velo_amt";
	constexpr auto avp_fine_tune = "avp_fine_tune";
	constexpr auto avp_flex_sli_bend_neg = "avp_flex_sli_bend_neg";
	constexpr auto avp_flex_sli_bend_pos = "avp_flex_sli_bend_pos";
	constexpr auto avp_flex_sli_range = "avp_flex_sli_range";
	constexpr auto avp_flex_sli_target = "avp_flex_sli_target";
	constexpr auto avp_keyboard_octave = "avp_keyboard_octave";
	constexpr auto avp_level = "avp_level";
	constexpr auto avp_lfo_sync_bpm_on = "avp_lfo_sync_bpm_on";
	constexpr auto avp_lfo_sync_key_on = "avp_lfo_sync_key_on";
	constexpr auto avp_lfo_sync_voice_on = "avp_lfo_sync_voice_on";
	constexpr auto avp_microtune_scale = "avp_microtune_scale";
	constexpr auto avp_name = "avp_name";
	constexpr auto avp_porta_mode_on = "avp_porta_mode_on";
	constexpr auto avp_porta_sync_bpm_on = "avp_porta_sync_bpm_on";
	constexpr auto avp_porta_time = "avp_porta_time";
	constexpr auto avp_scale_key = "avp_scale_key";
	constexpr auto avp_transpose = "avp_transpose";
	constexpr auto avp_voice_mode = "avp_voice_mode";
	constexpr auto avp_voice_mode_btn_0 = "avp_voice_mode_btn_0";
	constexpr auto avp_voice_mode_btn_1 = "avp_voice_mode_btn_1";
	constexpr auto avp_voice_mode_btn_2 = "avp_voice_mode_btn_2";
	constexpr auto avp_voice_mode_btn_3 = "avp_voice_mode_btn_3";
	constexpr auto avp_voice_mode_btn_4 = "avp_voice_mode_btn_4";
	constexpr auto avp_voice_mode_btn_5 = "avp_voice_mode_btn_5";
	constexpr auto avp_voice_mode_btn_6 = "avp_voice_mode_btn_6";
	constexpr auto avp_voice_mode_btn_7 = "avp_voice_mode_btn_7";

	constexpr auto exp_delay_feedback = "exp_delay_feedback";
	constexpr auto exp_delay_hpf_freq = "exp_delay_hpf_freq";
	constexpr auto exp_delay_routing = "exp_delay_routing";
	constexpr auto exp_delay_time = "exp_delay_time";
	constexpr auto exp_env_attack = "exp_env_attack";
	constexpr auto exp_env_decay = "exp_env_decay";
	constexpr auto exp_env_release = "exp_env_release";
	constexpr auto exp_env_sustain = "exp_env_sustain";
	constexpr auto exp_lfo_eg_mod = "exp_lfo_eg_mod";
	constexpr auto exp_lfo_int = "exp_lfo_int";
	constexpr auto exp_lfo_rate = "exp_lfo_rate";
	constexpr auto exp_lfo_target = "exp_lfo_target";
	constexpr auto exp_lfo_wave = "exp_lfo_wave";
	constexpr auto exp_lpf_eg_int = "exp_lpf_eg_int";
	constexpr auto exp_lpf_freq = "exp_lpf_freq";
	constexpr auto exp_lpf_key_track = "exp_lpf_key_track";
	constexpr auto exp_lpf_reso = "exp_lpf_reso";
	constexpr auto exp_lpf_type = "exp_lpf_type";
	constexpr auto exp_lpf_velo_amt = "exp_lpf_velo_amt";
	constexpr auto exp_mix_noise = "exp_level_noise";
	constexpr auto exp_mix_osc_1 = "exp_level_osc_1";
	constexpr auto exp_mix_osc_2 = "exp_level_osc_2";
	constexpr auto exp_osc_1_octave = "exp_osc_1_octave";
	constexpr auto exp_osc_1_pitch_fine = "exp_osc_1_pitch_fine";
	constexpr auto exp_osc_1_shape = "exp_osc_1_shape";
	constexpr auto exp_osc_1_wave = "exp_osc_1_wave";
	constexpr auto exp_osc_2_octave = "exp_osc_2_octave";
	constexpr auto exp_osc_2_pitch_eg_int = "exp_osc_2_pitch_eg_int";
	constexpr auto exp_osc_2_pitch_fine = "exp_osc_2_pitch_fine";
	constexpr auto exp_osc_2_ring_mod = "exp_osc_2_ring_mod";
	constexpr auto exp_osc_2_shape = "exp_osc_2_shape";
	constexpr auto exp_osc_2_sync = "exp_osc_2_sync";
	constexpr auto exp_osc_2_wave = "exp_osc_2_wave";
	constexpr auto exp_osc_2_xmod_depth = "exp_osc_2_xmod_depth";
	constexpr auto exp_vca_env_attack = "exp_vca_env_attack";
	constexpr auto exp_vca_env_decay = "exp_vca_env_decay";
	constexpr auto exp_vca_env_release = "exp_vca_env_release";
	constexpr auto exp_vca_env_sustain = "exp_vca_env_sustain";
	constexpr auto exp_voice_mode_depth = "exp_voice_mode_depth";

	constexpr std::array<const char*, 19> exp_params{
		avp_amp_mod_by_velo_amt,
		avp_fine_tune,
		avp_flex_sli_bend_neg,
		avp_flex_sli_bend_pos,
		avp_flex_sli_range,
		avp_flex_sli_target,
		avp_keyboard_octave,
		avp_level,
		avp_lfo_sync_bpm_on,
		avp_lfo_sync_key_on,
		avp_lfo_sync_voice_on,
		avp_microtune_scale,
		avp_name,
		avp_porta_mode_on,
		avp_porta_sync_bpm_on,
		avp_porta_time,
		avp_scale_key,
		avp_transpose,
		avp_voice_mode
	};

	constexpr std::array<const char*, 39> exp_params{
		exp_osc_1_octave,
		exp_osc_1_wave,
		exp_osc_1_pitch_fine,
		exp_osc_1_shape,
		exp_osc_2_octave,
		exp_osc_2_wave,
		exp_osc_2_pitch_fine,
		exp_osc_2_shape,
		exp_osc_2_xmod_depth,
		exp_osc_2_pitch_eg_int,
		exp_osc_2_sync,
		exp_osc_2_ring_mod,
		exp_mix_osc_1,
		exp_mix_osc_2,
		exp_mix_noise,
		exp_lpf_freq,
		exp_lpf_reso,
		exp_lpf_eg_int,
		exp_lpf_type,
		exp_lpf_key_track,
		exp_lpf_velo_amt,
		exp_vca_env_attack,
		exp_vca_env_decay,
		exp_vca_env_sustain,
		exp_vca_env_release,
		exp_env_attack,
		exp_env_decay,
		exp_env_sustain,
		exp_env_release,
		exp_lfo_wave,
		exp_lfo_eg_mod,
		exp_lfo_rate,
		exp_lfo_int,
		exp_lfo_target,
		exp_delay_hpf_freq,
		exp_delay_time,
		exp_delay_feedback,
		exp_delay_routing,
		exp_voice_mode_depth
	};

}
