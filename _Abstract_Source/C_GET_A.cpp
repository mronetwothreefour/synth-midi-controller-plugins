#include "C_GET_A.h"

//#include "C_MAP_Choices_P.h"
//#include "C_MAP_Ctrl_Name_P.h"
//#include "C_MAP_Edit_Allowed_Chars_P.h"
//#include "C_MAP_Edit_Char_Limit_P.h"
//#include "C_MAP_Exp_Name_P.h"
#include "C_MAP_Init_Bounds_P.h"
//#include "C_MAP_Init_Choice_P.h"
//#include "C_MAP_Label_Name_P.h"
//#include "C_MAP_Tip_P.h"

const Rectangle<int> GET_A::init_bounds_for(const String& id) {
	if (MAP::init_bounds.find(id) != MAP::init_bounds.end()) {
		auto& b = MAP::init_bounds.at(id);
		Rectangle<int> r{ b[1], b[2], b[3], b[4]};
		if (b[0])
			r.setCentre(b[1], b[2]);
		return r;
	}
	return {};
}

const int GET_A::init_h_for(const String& id) {
	if (MAP::init_bounds.find(id) != MAP::init_bounds.end())
		return MAP::init_bounds.at(id)[4];
	return 0;
}

const int GET_A::init_w_for(const String& id) {
	if (MAP::init_bounds.find(id) != MAP::init_bounds.end())
		return MAP::init_bounds.at(id)[3];
	return 0;
}

const int GET_A::init_x_for(const String& id) {
	return init_bounds_for(id).getX();
}

const int GET_A::init_y_for(const String& id) {
	return init_bounds_for(id).getY();
}

//const StringArray GET_A::choices_for(const String& id, const bool curt) {
//	StringArray out_list;
//	if (MAP::choices.find(id) != MAP::choices.end()) {
//		for (auto& in_choice : MAP::choices.at(id)) {
//			String out_choice{ in_choice };
//			if (out_choice.contains("__"))
//				out_choice = curt ? out_choice.upToFirstOccurrenceOf("__", false, true) :
//									out_choice.fromFirstOccurrenceOf("__", false, true);
//			out_list.add(out_choice);
//		}
//	}
//	return out_list;
//}
//
//const String GET_A::ctrl_name_for(const String& id) {
//	if (MAP::ctrl_name.find(id) != MAP::ctrl_name.end())
//		return MAP::ctrl_name.at(id);
//	return {};
//}
//
//const String GET_A::edit_allowed_chars_for(const String& id) {
//	if (MAP::edit_allowed_chars.find(id) != MAP::edit_allowed_chars.end())
//		return MAP::edit_allowed_chars.at(id);
//	return {};
//}
//
//const int GET_A::edit_char_limit_for(const String& id) {
//	if (MAP::edit_char_limit.find(id) != MAP::edit_char_limit.end())
//		return MAP::edit_char_limit.at(id);
//	return {};
//}
//
//const String GET_A::exp_name_for(const String& id) {
//	if (MAP::exp_name.find(id) != MAP::exp_name.end())
//		return MAP::exp_name.at(id);
//	return {};
//}
//
//const int GET_A::init_choice_for(const String& id) {
//	if (MAP::init_choice.find(id) != MAP::init_choice.end())
//		return MAP::init_choice.at(id);
//	return -1;
//}
//
//const String GET_A::label_name_for(const String& id) {
//	if (MAP::label_name.find(id) != MAP::label_name.end())
//		return MAP::label_name.at(id);
//	return {};
//}
//
//const String GET_A::tip_for(const String& id) {
//	if (MAP::tip.find(id) != MAP::tip.end())
//		return MAP::tip.at(id);
//	return {};
//}
