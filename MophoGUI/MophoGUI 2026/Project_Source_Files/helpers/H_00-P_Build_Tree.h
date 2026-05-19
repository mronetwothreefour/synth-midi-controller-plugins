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
	static ValueTree exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
									   Knob_Display_Type display, uint8 nrpn, uint8 choice_count, 
									   uint8 init_choice, int ctrl_center_x, int ctrl_center_y,
									   int ctrl_w, int ctrl_h, String description, 
									   ValueTree curt_choice_names, ValueTree choice_names);

	static String convert_int_to_seq_step_pitch_name(const int i);

	static ValueTree choice_names_arpeg_mode(const bool curt = false);

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
	static ValueTree choice_names_seq_tracks_2_and_4_dest(const bool track_2, const bool curt = false);
	static ValueTree choice_names_seq_trig_mode(const bool curt = false);

	static ValueTree choice_names_voice_name_char(const bool curt = false);
};
