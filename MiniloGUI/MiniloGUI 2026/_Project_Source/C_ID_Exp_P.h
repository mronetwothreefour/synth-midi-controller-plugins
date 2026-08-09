#pragma once

#include <JuceHeader.h>

namespace ID
{

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
	static const String exp_lpf_vel_amt{ "exp_lpf_vel_amt" };
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

	static const StringArray exp_id{
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
		exp_lpf_vel_amt,
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
