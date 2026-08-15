#pragma once

#include <JuceHeader.h>

struct GET_A
{
	static const double editor_aspect_ratio();
	static const Rectangle<int> init_bounds_for(const String id);
	static const int init_h_for(const String id);
	static const int init_w_for(const String id);
	static const int init_x_for(const String id);
	static const int init_y_for(const String id);
	static const float rotary_slider_begin_angle();
	static const float rotary_slider_end_angle();

	static const StringArray choices_for(const String id, const bool curt = false);
	static const int ctrl_type_for(const String id);
	static const int init_choice_for(const String id);
	static const String exp_name_for(const String id);
	static const String tip_for(const String id);
};
