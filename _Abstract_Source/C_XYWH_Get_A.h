#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	struct Get
	{
		static const double editor_aspect_ratio();
		static const Rectangle<int> init_bounds_for(const String component_id);
		static const int init_h_for(const String component_id);
		static const int init_w_for(const String component_id);
		static const int init_x_for(const String component_id);
		static const int init_y_for(const String component_id);
		static const float rotary_slider_begin_angle();
		static const float rotary_slider_end_angle();
	};

}
