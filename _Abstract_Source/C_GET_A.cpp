#include "C_GET_A.h"

#include "C_MAP_Choices_P.h"
#include "C_MAP_Ctrl_Traits_P.h"
#include "C_MAP_Editor_Traits_P.h"
#include "C_MAP_Exp_Name_P.h"
#include "C_MAP_Init_Bounds_P.h"
#include "C_MAP_Label_Name_P.h"

const std::string GET_A::editor_allowed_chars_for(const std::string& id) {
	if (MAP::editor_traits.find(id) != MAP::editor_traits.end())
		return std::get<0>(MAP::editor_traits.at(id));
	return {};
}

const int GET_A::editor_char_limit_for(const std::string& id) {
	if (MAP::editor_traits.find(id) != MAP::editor_traits.end())
		return std::get<1>(MAP::editor_traits.at(id));
	return 0;
}

const std::string GET_A::editor_tip_for(const std::string& id) {
	if (MAP::editor_traits.find(id) != MAP::editor_traits.end())
		return std::get<2>(MAP::editor_traits.at(id));
	return {};
}

const Rectangle<int> GET_A::init_bounds_for(const std::string& id) {
	if (MAP::init_bounds.find(id) != MAP::init_bounds.end()) {
		auto& b = MAP::init_bounds.at(id);
		Rectangle<int> r{ std::get<1>(b), std::get<2>(b), std::get<3>(b), std::get<4>(b) };
		if (std::get<0>(b))
			r.setCentre(std::get<1>(b), std::get<2>(b));
		return r;
	}
	return {};
}

const int GET_A::init_h_for(const std::string& id) {
	if (MAP::init_bounds.find(id) != MAP::init_bounds.end())
		return std::get<4>(MAP::init_bounds.at(id));
	return 0;
}

const int GET_A::init_w_for(const std::string& id) {
	if (MAP::init_bounds.find(id) != MAP::init_bounds.end())
		return std::get<3>(MAP::init_bounds.at(id));
	return 0;
}

const int GET_A::init_x_for(const std::string& id) {
	return init_bounds_for(id).getX();
}

const int GET_A::init_y_for(const std::string& id) {
	return init_bounds_for(id).getY();
}

const std::vector<std::string> GET_A::choices_for(const std::string& id, const bool curt) {
	std::vector<std::string> out_list;
	if (MAP::choices.find(id) != MAP::choices.end()) {
		for (auto& in_choice : MAP::choices.at(id)) {
			String out_choice{ in_choice };
			if (out_choice.contains("__"))
				out_choice = curt ? out_choice.upToFirstOccurrenceOf("__", false, true) :
									out_choice.fromFirstOccurrenceOf("__", false, true);
			out_list.push_back(out_choice.toStdString());
		}
	}
	return out_list;
}

const std::string GET_A::ctrl_name_for(const std::string& id) {
	if (MAP::ctrl_traits.find(id) != MAP::ctrl_traits.end())
		return std::get<0>(MAP::ctrl_traits.at(id));
	return {};
}

const std::string GET_A::exp_name_for(const std::string& id) {
	if (MAP::exp_name.find(id) != MAP::exp_name.end())
		return MAP::exp_name.at(id);
	return {};
}

const int GET_A::init_choice_for(const std::string& id) {
	if (MAP::ctrl_traits.find(id) != MAP::ctrl_traits.end())
		return std::get<1>(MAP::ctrl_traits.at(id));
	return -1;
}

const std::string GET_A::label_name_for(const std::string& id) {
	if (MAP::label_name.find(id) != MAP::label_name.end())
		return MAP::label_name.at(id);
	return {};
}

const std::string GET_A::tip_for(const std::string& id) {
	if (MAP::ctrl_traits.find(id) != MAP::ctrl_traits.end())
		return std::get<2>(MAP::ctrl_traits.at(id));
	return {};
}
