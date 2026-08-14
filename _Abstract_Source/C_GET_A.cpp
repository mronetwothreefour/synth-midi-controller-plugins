#include "C_GET_A.h"

#include "C_MAP_Bounds_P.h"
#include "C_MAP_Choices_P.h"
#include "C_MAP_Ctrl_Type_P.h"
#include "C_MAP_Init_Choice_P.h"
#include "C_MAP_Name_P.h"
#include "C_MAP_Tip_P.h"

const double GET_A::editor_aspect_ratio() {
	return XYWH::editor_aspect_ratio;
}

const Rectangle<int> GET_A::init_bounds_for(const String id) {
	if (MAP::bounds.find(id) != MAP::bounds.end())
		return MAP::bounds.at(id);
	return {};
}

const int GET_A::init_h_for(const String id) {
	return init_bounds_for(id).getHeight();
}

const int GET_A::init_w_for(const String id) {
	return init_bounds_for(id).getWidth();
}

const int GET_A::init_x_for(const String id) {
	return init_bounds_for(id).getX();
}

const int GET_A::init_y_for(const String id) {
	return init_bounds_for(id).getY();
}

const float GET_A::rotary_slider_begin_angle() {
	return XYWH::rotary_slider_begin_angle;
}

const float GET_A::rotary_slider_end_angle() {
	return XYWH::rotary_slider_end_angle;
}

const StringArray GET_A::choices_for(const String id, const bool curt) {
	StringArray out_list;
	if (MAP::choices.find(id) != MAP::choices.end()) {
		for (auto& in_choice : MAP::choices.at(id)) {
			String out_choice{ in_choice };
			if (out_choice.contains("__"))
				out_choice = curt ? out_choice.upToFirstOccurrenceOf("__", false, true) :
									out_choice.fromFirstOccurrenceOf("__", false, true);
			out_list.add(out_choice);
		}
	}
	return out_list;
}

const int GET_A::ctrl_type_for(const String id) {
	if (MAP::ctrl_type.find(id) != MAP::ctrl_type.end())
		return (int)MAP::ctrl_type.at(id);
	return (int)Ctrl::null;
}

const int GET_A::init_choice_for(const String id) {
	if (MAP::init_choice.find(id) != MAP::init_choice.end())
		return MAP::init_choice.at(id);
	return -1;
}

const String GET_A::name_for(const String id) {
	if (MAP::name.find(id) != MAP::name.end())
		return MAP::name.at(id);
	return {};
}

const String GET_A::tip_for(const String id) {
	if (MAP::tip.find(id) != MAP::tip.end())
		return MAP::tip.at(id);
	return {};
}
