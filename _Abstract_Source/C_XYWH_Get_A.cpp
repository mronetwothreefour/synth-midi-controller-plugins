#include "C_XYWH_Get_A.h"

#include "C_XYWH_Map_Bounds_P.h"

const double XYWH::Get::editor_aspect_ratio() {
	return XYWH::editor_aspect_ratio;
}

const Rectangle<int> XYWH::Get::init_bounds_for(const String component_id) {
	if (map_bounds.find(component_id) != map_bounds.end())
		return map_bounds.at(component_id);
	return {};
}

const int XYWH::Get::init_h_for(const String component_id) {
	return init_bounds_for(component_id).getHeight();
}

const int XYWH::Get::init_w_for(const String component_id) {
	return init_bounds_for(component_id).getWidth();
}

const int XYWH::Get::init_x_for(const String component_id) {
	return init_bounds_for(component_id).getX();
}

const int XYWH::Get::init_y_for(const String component_id) {
	return init_bounds_for(component_id).getY();
}

const float XYWH::Get::rotary_slider_begin_angle() {
	return XYWH::rotary_slider_begin_angle;
}

const float XYWH::Get::rotary_slider_end_angle() {
	return XYWH::rotary_slider_end_angle;
}

