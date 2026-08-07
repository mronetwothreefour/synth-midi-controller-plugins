#include "C_XYWH_Get_A.h"

#include "C_XYWH_P.h"

const double XYWH::Get::editor_aspect_ratio() {
	return XYWH::editor_aspect_ratio;
}

const Rectangle<int> XYWH::Get::init_bounds_for(const String component_id) {
	if (bounds_map.find(component_id) != bounds_map.end())
		return bounds_map.at(component_id);
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

