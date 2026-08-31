#pragma once

#include <JuceHeader.h>

namespace ID
{

	static const String avp_amp_mod_by_velo_amt{ "avp_amp_mod_by_velo_amt" };
	static const String avp_fine_tune{ "avp_fine_tune" };
	static const String avp_flex_sli_bend_neg{ "avp_flex_sli_bend_neg" };
	static const String avp_flex_sli_bend_pos{ "avp_flex_sli_bend_pos" };
	static const String avp_flex_sli_range{ "avp_flex_sli_range" };
	static const String avp_flex_sli_target{ "avp_flex_sli_target" };
	static const String avp_keyboard_octave{ "avp_keyboard_octave" };
	static const String avp_level{ "avp_level" };
	static const String avp_lfo_sync_bpm_on{ "avp_lfo_sync_bpm_on" };
	static const String avp_lfo_sync_key_on{ "avp_lfo_sync_key_on" };
	static const String avp_lfo_sync_voice_on{ "avp_lfo_sync_voice_on" };
	static const String avp_microtune_scale{ "avp_microtune_scale" };
	static const String avp_name{ "avp_name" };
	static const String avp_porta_mode_on{ "avp_porta_mode_on" };
	static const String avp_porta_sync_bpm_on{ "avp_porta_sync_bpm_on" };
	static const String avp_porta_time{ "avp_porta_time" };
	static const String avp_scale_key{ "avp_scale_key" };
	static const String avp_transpose{ "avp_transpose" };
	static const String avp_voice_mode{ "avp_voice_mode" };
	static const String avp_voice_mode_btn_0{ "avp_voice_mode_btn_0" };
	static const String avp_voice_mode_btn_1{ "avp_voice_mode_btn_1" };
	static const String avp_voice_mode_btn_2{ "avp_voice_mode_btn_2" };
	static const String avp_voice_mode_btn_3{ "avp_voice_mode_btn_3" };
	static const String avp_voice_mode_btn_4{ "avp_voice_mode_btn_4" };
	static const String avp_voice_mode_btn_5{ "avp_voice_mode_btn_5" };
	static const String avp_voice_mode_btn_6{ "avp_voice_mode_btn_6" };
	static const String avp_voice_mode_btn_7{ "avp_voice_mode_btn_7" };

	static const String exp_delay_feedback{ "exp_delay_feedback" };
	static const String exp_delay_hpf_freq{ "exp_delay_hpf_freq" };
	static const String exp_delay_routing{ "exp_delay_routing" };
	static const String exp_delay_time{ "exp_delay_time" };
	static const String exp_env_attack{ "exp_env_attack" };
	static const String exp_env_decay{ "exp_env_decay" };
	static const String exp_env_release{ "exp_env_release" };
	static const String exp_env_sustain{ "exp_env_sustain" };
	static const String exp_lfo_eg_mod{ "exp_lfo_eg_mod" };
	static const String exp_lfo_int{ "exp_lfo_int" };
	static const String exp_lfo_rate{ "exp_lfo_rate" };
	static const String exp_lfo_target{ "exp_lfo_target" };
	static const String exp_lfo_wave{ "exp_lfo_wave" };
	static const String exp_lpf_eg_int{ "exp_lpf_eg_int" };
	static const String exp_lpf_freq{ "exp_lpf_freq" };
	static const String exp_lpf_key_track{ "exp_lpf_key_track" };
	static const String exp_lpf_reso{ "exp_lpf_reso" };
	static const String exp_lpf_type{ "exp_lpf_type" };
	static const String exp_lpf_velo_amt{ "exp_lpf_velo_amt" };
	static const String exp_mix_noise{ "exp_level_noise" };
	static const String exp_mix_osc_1{ "exp_level_osc_1" };
	static const String exp_mix_osc_2{ "exp_level_osc_2" };
	static const String exp_osc_1_octave{ "exp_osc_1_octave" };
	static const String exp_osc_1_pitch_fine{ "exp_osc_1_pitch_fine" };
	static const String exp_osc_1_shape{ "exp_osc_1_shape" };
	static const String exp_osc_1_wave{ "exp_osc_1_wave" };
	static const String exp_osc_2_octave{ "exp_osc_2_octave" };
	static const String exp_osc_2_pitch_eg_int{ "exp_osc_2_pitch_eg_int" };
	static const String exp_osc_2_pitch_fine{ "exp_osc_2_pitch_fine" };
	static const String exp_osc_2_ring_mod{ "exp_osc_2_ring_mod" };
	static const String exp_osc_2_shape{ "exp_osc_2_shape" };
	static const String exp_osc_2_sync{ "exp_osc_2_sync" };
	static const String exp_osc_2_wave{ "exp_osc_2_wave" };
	static const String exp_osc_2_xmod_depth{ "exp_osc_2_xmod_depth" };
	static const String exp_vca_env_attack{ "exp_vca_env_attack" };
	static const String exp_vca_env_decay{ "exp_vca_env_decay" };
	static const String exp_vca_env_release{ "exp_vca_env_release" };
	static const String exp_vca_env_sustain{ "exp_vca_env_sustain" };
	static const String exp_voice_mode_depth{ "exp_voice_mode_depth" };

	static const String tree_aux_voice{ "tree_aux_voice" };
	
	static const String xml_state_aux_voice{ "xml_state_aux_voice" };

	static const StringArray aux_voice_params{
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

	static const StringArray exp_params{
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
