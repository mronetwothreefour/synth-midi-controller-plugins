#pragma once

#include "D_BUILD_Choices_A.h"

struct Build_Choices :
	public Build_Choices_A
{
	static const StringArray arp_mode();
	static const StringArray bend_range();
	static const StringArray clock_div();
	static const StringArray clock_tempo();
	static const StringArray flex_knob();
	static const StringArray glide_mode();
	static const StringArray lfo_freq();
	static const StringArray lfo_shape();
	static const StringArray lpf_freq();
	static const StringArray lpf_type();
	static const StringArray mod_dest();
	static const StringArray mod_src();
	static const StringArray note_priority();
	static const StringArray osc_fine();
	static const StringArray osc_shape();
	static const StringArray push_it_mode();
	static const StringArray seq_track_2_4_dest(const bool track_2);
	static const StringArray seq_track_step();
	static const StringArray seq_trig_mode();
	static const StringArray voice_name_char();
};