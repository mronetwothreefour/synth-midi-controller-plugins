#pragma once

#include <JuceHeader.h>

#include "C_00-P_ID.h"
#include "C_01-P_ENUM.h"
#include "C_50-P_EP.h"
#include "H_00-B_Build_Tree.h"

using namespace ENUM;

struct Build_Tree :
	public Base_Build_Tree
{
public: static ValueTree exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
									   Knob_Display_Type display, uint8 cc_num,
									   uint16 choice_count, uint16 init_choice, 
									   int ctrl_center_x,int ctrl_center_y, int ctrl_w, 
									   int ctrl_h,String description, ValueTree bit_locations,
									   ValueTree curt_choice_names, ValueTree choice_names);

public: static ValueTree choice_names_0_50_100(const bool curt = false);
public: static ValueTree choice_names_delay_routing(const bool curt = false);
public: static ValueTree choice_names_lfo_eg_mod(const bool curt = false);
public: static ValueTree choice_names_lfo_rate(const bool curt = false);
public: static ValueTree choice_names_lfo_target(const bool curt = false);
public: static ValueTree choice_names_lpf_eg_int(const bool curt = false);
public: static ValueTree choice_names_lpf_type(const bool curt = false);
public: static ValueTree choice_names_osc_2_pitch_eg_int(const bool curt = false);
public: static ValueTree choice_names_osc_and_lfo_wave(const bool curt = false);
public: static ValueTree choice_names_osc_octave(const bool curt = false);
public: static ValueTree choice_names_osc_pitch_fine(const bool curt = false);
public: static ValueTree choice_names_voice_mode_depth(const bool curt = false);
private: static String choice_name_voice_mode_1_poly(const uint16 choice_num, const bool curt);
private: static String choice_name_voice_mode_2_duo_3_unison(const uint16 choice_num, const bool curt);
private: static String choice_name_voice_mode_4_mono(const uint16 choice_num, const bool curt);
private: static String choice_name_voice_mode_5_chord(const uint16 choice_num, const bool curt);
private: static String choice_name_voice_mode_6_delay(const uint16 choice_num, const bool curt);
private: static String choice_name_voice_mode_7_arp(const uint16 choice_num, const bool curt);
private: static String choice_name_voice_mode_8_sidechain(const uint16 choice_num, const bool curt);
};
