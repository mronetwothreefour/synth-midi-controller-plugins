#pragma once

#include <JuceHeader.h>

#include "c_ID_p.h"
#include "c_ENUM_p.h"
#include "c_EXP_p.h"
#include "d_Sub_Tree_Choices_b.h"

using namespace ENUM;

struct Build_Tree :
	public Sub_Tree_Choices_Base
{
public: static ValueTree exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
									   Knob_Display_Type display, int cc_num,
									   int choice_count, int init_choice, 
									   int ctrl_center_x,int ctrl_center_y, int ctrl_w, 
									   int ctrl_h,String tip, ValueTree bit_locations,
									   ValueTree curt_choice_names, ValueTree choice_names);

public: static ValueTree bit_locations_delay_feedback();
public: static ValueTree bit_locations_delay_hpf_freq();
public: static ValueTree bit_locations_delay_routing();
public: static ValueTree bit_locations_delay_time();
public: static ValueTree bit_locations_env_attack(const bool vca);
public: static ValueTree bit_locations_env_decay(const bool vca);
public: static ValueTree bit_locations_env_release(const bool vca);
public: static ValueTree bit_locations_env_sustain(const bool vca);
public: static ValueTree bit_locations_level_knob(const int knob);
public: static ValueTree bit_locations_lfo_eg_mod();
public: static ValueTree bit_locations_lfo_int();
public: static ValueTree bit_locations_lfo_rate();
public: static ValueTree bit_locations_lfo_target();
public: static ValueTree bit_locations_lfo_wave();
public: static ValueTree bit_locations_lpf_eg_int();
public: static ValueTree bit_locations_lpf_freq();
public: static ValueTree bit_locations_lpf_key_track();
public: static ValueTree bit_locations_lpf_reso();
public: static ValueTree bit_locations_lpf_type();
public: static ValueTree bit_locations_lpf_velo_amt();
public: static ValueTree bit_locations_osc_2_pitch_eg_int();
public: static ValueTree bit_locations_osc_2_ring_mod();
public: static ValueTree bit_locations_osc_2_sync();
public: static ValueTree bit_locations_osc_2_x_mod_depth();
public: static ValueTree bit_locations_osc_octave(const int osc);
public: static ValueTree bit_locations_osc_pitch_fine(const int osc);
public: static ValueTree bit_locations_osc_shape(const int osc);
public: static ValueTree bit_locations_osc_wave(const int osc);
public: static ValueTree bit_locations_voice_mode_depth();

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
