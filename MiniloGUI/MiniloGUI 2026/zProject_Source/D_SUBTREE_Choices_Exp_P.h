#pragma once

#include "D_SUBTREE_Choices_G.h"

struct Subtree_Choices_Exp_P :
	public Subtree_Choices_G
{
public: static ValueTree delay_routing(const bool curt = false);
public: static ValueTree lfo_eg_mod(const bool curt = false);
public: static ValueTree lfo_rate(const bool curt = false);
public: static ValueTree lfo_target(const bool curt = false);
public: static ValueTree lpf_eg_int(const bool curt = false);
public: static ValueTree lpf_type(const bool curt = false);
public: static ValueTree osc_2_pitch_eg_int(const bool curt = false);
public: static ValueTree osc_and_lfo_wave(const bool curt = false);
public: static ValueTree osc_octave(const bool curt = false);
public: static ValueTree osc_pitch_fine(const bool curt = false);
public: static ValueTree voice_mode_depth(const bool curt = false);
public: static ValueTree zero_50_100(const bool curt = false);

private: static String choice_voice_mode_1_poly(const uint16 choice_num, const bool curt);
private: static String choice_voice_mode_2_duo_3_unison(const uint16 choice_num, const bool curt);
private: static String choice_voice_mode_4_mono(const uint16 choice_num, const bool curt);
private: static String choice_voice_mode_5_chord(const uint16 choice_num, const bool curt);
private: static String choice_voice_mode_6_delay(const uint16 choice_num, const bool curt);
private: static String choice_voice_mode_7_arp(const uint16 choice_num, const bool curt);
private: static String choice_voice_mode_8_sidechain(const uint16 choice_num, const bool curt);
};
