#pragma once

#include <JuceHeader.h>

#include "C_EXP_P.h"
#include "D_TREE_Exposed_Info_B.h"

using Layout = AudioProcessorValueTreeState::ParameterLayout;

struct Layout_Exposed_B
{
	static Layout build(const Tree_Exposed_Info_B& info) {
		Layout layout;
		for (uint8 param_index = 0; param_index < EXP::exp_param_count; ++param_index) {
			auto id{ info.id_for(param_index).toString() };
			auto name{ info.name_for(param_index) };
			auto choices_list{ info.choices_list_for(param_index) };
			auto init_choice{ info.init_choice_for(param_index) };
			layout.add(std::make_unique<AudioParameterChoice>(id, name, choices_list, init_choice));
		}
		return layout;
	}
};