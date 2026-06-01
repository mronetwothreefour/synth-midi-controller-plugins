#pragma once

#include <JuceHeader.h>

#include "c_ID_p.h"
#include "c_ENUM_p.h"
#include "c_EXP_p.h"
#include "d_Sub_Tree_Choices_b.h"
#include "d_Sub_Tree_Exposed_p.h"

using namespace ENUM;

struct Sub_Tree_Choices_Exposed :
	public Sub_Tree_Choices_Base
{
	static String convert_int_to_seq_step_pitch_name(const int i);

	static ValueTree arp_mode(const bool curt = false);

	static ValueTree bend_range(const bool curt = false);

	static ValueTree clock_div(const bool curt = false);
	static ValueTree clock_tempo(const bool curt = false);

	static ValueTree glide_mode(const bool curt = false);

	static ValueTree knob_assign(const bool curt = false);

	static ValueTree lfo_freq(const bool curt = false);
	static ValueTree lfo_shape(const bool curt = false);
	static ValueTree lpf_freq(const bool curt = false);
	static ValueTree lpf_type(const bool curt = false);

	static ValueTree mod_dest(const bool curt = false);
	static ValueTree mod_src(const bool curt = false);

	static ValueTree note_priority(const bool curt = false);

	static ValueTree osc_fine(const bool curt = false);
	static ValueTree osc_shape(const bool curt = false);

	static ValueTree push_it_mode(const bool curt = false);

	static ValueTree seq_track_step(const bool curt = false);
	static ValueTree seq_track_2_4_dest(const bool track_2, const bool curt = false);
	static ValueTree seq_trig_mode(const bool curt = false);

	static ValueTree signed_8_bit_int(const bool curt = false);

	static ValueTree voice_name_char(const bool curt = false);
};
