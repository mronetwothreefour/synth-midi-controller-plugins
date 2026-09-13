#pragma once

#include <JuceHeader.h>

struct GET_A
{
	static const std::string editor_allowed_chars_for(const std::string& id);
	static const int editor_char_limit_for(const std::string& id);
	static const std::string editor_tip_for(const std::string& id);

	static const Rectangle<int> init_bounds_for(const std::string& id);
	static const int init_h_for(const std::string& id);
	static const int init_w_for(const std::string& id);
	static const int init_x_for(const std::string& id);
	static const int init_y_for(const std::string& id);

	static const std::vector<std::string> choices_for(const std::string& id, const bool curt = false);
	static const std::string ctrl_name_for(const std::string& id);
	static const std::string exp_name_for(const std::string& id);
	static const int init_choice_for(const std::string& id);
	//static const std::string label_name_for(const std::string& id);
	static const std::string tip_for(const std::string& id);
};
