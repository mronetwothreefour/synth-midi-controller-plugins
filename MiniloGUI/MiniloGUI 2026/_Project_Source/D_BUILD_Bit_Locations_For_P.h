#pragma once

#include <JuceHeader.h>

namespace BUILD
{

	struct Bit_Locations_For
	{
	public: static const StringArray exp_delay_feedback();
	public: static const StringArray exp_delay_hpf_freq();
	public: static const StringArray exp_delay_routing();
	public: static const StringArray exp_delay_time();
	public: static const StringArray exp_env_attack(const bool vca = false);
	public: static const StringArray exp_env_decay(const bool vca = false);
	public: static const StringArray exp_env_release(const bool vca = false);
	public: static const StringArray exp_env_sustain(const bool vca = false);
	public: static const StringArray exp_lfo_eg_mod();
	public: static const StringArray exp_lfo_int();
	public: static const StringArray exp_lfo_rate();
	public: static const StringArray exp_lfo_target();
	public: static const StringArray exp_lfo_wave();
	public: static const StringArray exp_lpf_eg_int();
	public: static const StringArray exp_lpf_freq();
	public: static const StringArray exp_lpf_key_track();
	public: static const StringArray exp_lpf_reso();
	public: static const StringArray exp_lpf_type();
	public: static const StringArray exp_lpf_velo_amt();
	public: static const StringArray exp_osc_2_pitch_eg_int();
	public: static const StringArray exp_osc_2_ring_mod();
	public: static const StringArray exp_osc_2_sync();
	public: static const StringArray exp_osc_2_x_mod_depth();
	public: static const StringArray exp_mix(const int osc);
	public: static const StringArray exp_osc_octave(const int osc);
	public: static const StringArray exp_osc_pitch_fine(const int osc);
	public: static const StringArray exp_osc_shape(const int osc);
	public: static const StringArray exp_osc_wave(const int osc);
	public: static const StringArray exp_voice_mode_depth();
	};

}
