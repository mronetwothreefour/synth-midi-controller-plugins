#pragma once

#include <JuceHeader.h>

struct Describe_Exp_Param
{
	static String bend_range();
	static String glide_mode();
	static String osc_fine(const int osc_num);
	static String osc_glide(const int osc_num);
	static String osc_key_track(const int osc_num);
	static String osc_pitch(const int osc_num);
	static String osc_shape(const int osc_num);
	static String osc_slop();
	static String osc_sub_level(const int osc_num);
	static String osc_sync();
};