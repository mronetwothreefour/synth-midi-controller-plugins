#include "C_GET_A.h"

#include "C_MAP_Bounds_P.h"
#include "C_MAP_Choices_P.h"
#include "C_MAP_Init_Choice_P.h"
#include "C_MAP_Name_P.h"
#include "C_MAP_Tip_P.h"

const double Get_A::editor_aspect_ratio() {
	return XYWH::editor_aspect_ratio;
}

const Rectangle<int> Get_A::init_bounds_for(const String component_id) {
	if (MAP::bounds.find(component_id) != MAP::bounds.end())
		return MAP::bounds.at(component_id);
	return {};
}

const int Get_A::init_h_for(const String component_id) {
	return init_bounds_for(component_id).getHeight();
}

const int Get_A::init_w_for(const String component_id) {
	return init_bounds_for(component_id).getWidth();
}

const int Get_A::init_x_for(const String component_id) {
	return init_bounds_for(component_id).getX();
}

const int Get_A::init_y_for(const String component_id) {
	return init_bounds_for(component_id).getY();
}

const float Get_A::rotary_slider_begin_angle() {
	return XYWH::rotary_slider_begin_angle;
}

const float Get_A::rotary_slider_end_angle() {
	return XYWH::rotary_slider_end_angle;
}

const StringArray Get_A::choices_for(const String component_id, const bool curt) {
	StringArray out_list;
	if (MAP::choices.find(component_id) != MAP::choices.end()) {
		for (auto& in_choice : MAP::choices.at(component_id)) {
			String out_choice{ in_choice };
			if (out_choice.contains("__"))
				out_choice = curt ? out_choice.upToFirstOccurrenceOf("__", false, true) :
									out_choice.fromFirstOccurrenceOf("__", false, true);
			out_list.add(out_choice);
		}
	}
	return out_list;
}

const int Get_A::init_choice_for(const String component_id) {
	if (MAP::init_choice.find(component_id) != MAP::init_choice.end())
		return MAP::init_choice.at(component_id);
	return -1;
}

const String Get_A::name_for(const String component_id) {
	if (MAP::name.find(component_id) != MAP::name.end())
		return MAP::name.at(component_id);
	return {};
}

const String Get_A::tip_for(const String component_id) {
	if (MAP::tip.find(component_id) != MAP::tip.end())
		return MAP::tip.at(component_id);
	return {};
}
