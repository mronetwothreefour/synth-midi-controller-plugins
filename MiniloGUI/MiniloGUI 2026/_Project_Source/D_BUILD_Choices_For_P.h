#pragma once

#include "D_BUILD_Choices_For_A.h"

namespace BUILD
{

	struct Choices_For :
		public Choices_For_A
	{
	public: static const StringArray exp_delay_routing();
	public: static const StringArray exp_lfo_eg_mod();
	public: static const StringArray exp_lfo_rate();
	public: static const StringArray exp_lfo_target();
	public: static const StringArray exp_lpf_eg_int();
	public: static const StringArray exp_lpf_type();
	public: static const StringArray exp_osc_2_pitch_eg_int();
	public: static const StringArray exp_osc_and_lfo_wave();
	public: static const StringArray exp_osc_octave();
	public: static const StringArray exp_osc_pitch_fine();
	public: static const StringArray exp_voice_mode_depth();
	public: static const StringArray exp_zero_50_100();

	private: static String exp_choice_voice_mode_1_poly(const int choice_num, const bool curt = false);
	private: static String exp_choice_voice_mode_2_duo_3_unison(const int choice_num, const bool curt = false);
	private: static String exp_choice_voice_mode_4_mono(const int choice_num, const bool curt = false);
	private: static String exp_choice_voice_mode_5_chord(const int choice_num, const bool curt = false);
	private: static String exp_choice_voice_mode_6_delay(const int choice_num, const bool curt = false);
	private: static String exp_choice_voice_mode_7_arp(const int choice_num, const bool curt = false);
	private: static String exp_choice_voice_mode_8_sidechain(const int choice_num, const bool curt = false);
	};

}
