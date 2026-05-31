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
	static ValueTree exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
									   Knob_Display_Type display, int nrpn, int choice_count,
									   int init_choice, int ctrl_center_x, int ctrl_center_y,
									   int ctrl_w, int ctrl_h, String tip, 
									   ValueTree curt_choice_names, ValueTree choice_names,
									   int red_toggle_center_x = 0, int red_toggle_center_y = 0);

	static String convert_int_to_seq_step_pitch_name(const int i);

	static ValueTree choice_names_arp_mode(const bool curt = false);

	static ValueTree choice_names_bend_range(const bool curt = false);

	static ValueTree choice_names_clock_div(const bool curt = false);
	static ValueTree choice_names_clock_tempo(const bool curt = false);

	static ValueTree choice_names_glide_mode(const bool curt = false);

	static ValueTree choice_names_knob_assign(const bool curt = false);

	static ValueTree choice_names_lfo_freq(const bool curt = false);
	static ValueTree choice_names_lfo_shape(const bool curt = false);
	static ValueTree choice_names_lpf_freq(const bool curt = false);
	static ValueTree choice_names_lpf_type(const bool curt = false);

	static ValueTree choice_names_mod_dest(const bool curt = false);
	static ValueTree choice_names_mod_src(const bool curt = false);

	static ValueTree choice_names_note_priority(const bool curt = false);

	static ValueTree choice_names_osc_fine(const bool curt = false);
	static ValueTree choice_names_osc_shape(const bool curt = false);

	static ValueTree choice_names_push_it_mode(const bool curt = false);

	static ValueTree choice_names_seq_track_step(const bool curt = false);
	static ValueTree choice_names_seq_track_2_4_dest(const bool track_2, const bool curt = false);
	static ValueTree choice_names_seq_trig_mode(const bool curt = false);

	static ValueTree choice_names_signed_8_bit_int(const bool curt = false);

	static ValueTree choice_names_voice_name_char(const bool curt = false);
};
