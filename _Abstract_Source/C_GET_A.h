#pragma once

#include <JuceHeader.h>

struct Get_A
{
	static const double editor_aspect_ratio();
	static const Rectangle<int> init_bounds_for(const String component_id);
	static const int init_h_for(const String component_id);
	static const int init_w_for(const String component_id);
	static const int init_x_for(const String component_id);
	static const int init_y_for(const String component_id);
	static const float rotary_slider_begin_angle();
	static const float rotary_slider_end_angle();

	static const String name_for(const String component_id);
	static const StringArray choices_for(const String component_id, const bool curt);
};
