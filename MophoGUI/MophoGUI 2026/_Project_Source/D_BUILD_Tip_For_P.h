#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static String exp_arp_mode();
		static String exp_arp_on_off();

		static String exp_bend_range();

		static String exp_clock_division();
		static String exp_clock_tempo();

		static String exp_env_3_amt();
		static String exp_env_3_dest();
		static String exp_env_3_repeat();
		static String exp_env_attack(const String env_name);
		static String exp_env_decay(const String env_name);
		static String exp_env_delay(const String env_name);
		static String exp_env_release(const String env_name);
		static String exp_env_sustain(const String env_name);
		static String exp_env_velo_amt(const String env_name);
		static String exp_ext_in_level();

		static String exp_flex_knob(const int knob_num);

		static String exp_glide_mode();

		static String exp_lfo_amt(const int lfo_num);
		static String exp_lfo_dest(const int lfo_num);
		static String exp_lfo_freq(const int lfo_num);
		static String exp_lfo_key_sync(const int lfo_num);
		static String exp_lfo_shape(const int lfo_num);
		static String exp_lpf_env_amt();
		static String exp_lpf_fm_amt();
		static String exp_lpf_freq();
		static String exp_lpf_key_amt();
		static String exp_lpf_reso();
		static String exp_lpf_type();

		static String exp_midi_breath_amt();
		static String exp_midi_mod_wheel_amt();
		static String exp_midi_pedal_amt();
		static String exp_midi_pressure_amt();
		static String exp_midi_velocity_amt();
		static String exp_mod_amt();
		static String exp_mod_dest();

		static String exp_noise_level();
		static String exp_note_priority();

		static String exp_osc_fine(const int osc_num);
		static String exp_osc_glide(const int osc_num);
		static String exp_osc_key_track(const int osc_num);
		static String exp_osc_mix();
		static String exp_osc_pitch(const int osc_num);
		static String exp_osc_shape(const int osc_num);
		static String exp_osc_slop();
		static String exp_osc_sub_level(const int osc_num);
		static String exp_osc_sync();

		static String exp_push_it_mode();
		static String exp_push_it_pitch();
		static String exp_push_it_velocity();

		static String exp_seq_on_off();
		static String exp_seq_track_dest(const int track_num);
		static String exp_seq_track_step(const int track_num, int step_num);
		static String exp_seq_trig_mode();

		static String exp_vca_env_amt();
		static String exp_vca_level();
		static String exp_voice_name_char(const int char_num);
		static String exp_voice_volume();

		static String knob_text_editor(const String& slider_label_name);
	};

}
