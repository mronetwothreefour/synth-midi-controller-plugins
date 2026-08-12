#include "D_BUILD_Exp_Param_Layout_A.h"

#include "C_GET_A.h"
#include "C_ID_EXP_P.h"

Layout Exp_Param_Layout_A::build() {
	Layout layout;
	for (auto& id : ID::exp_params) {
		auto name{ Get_A::name_for(id) };
		auto choices{ Get_A::choices_for(id) };
		auto init_choice{ Get_A::init_choice_for(id) };
		layout.add(std::make_unique<AudioParameterChoice>(id, name, choices, init_choice));
	}
	return layout;
}
