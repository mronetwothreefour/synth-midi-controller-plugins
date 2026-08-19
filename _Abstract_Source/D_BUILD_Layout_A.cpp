#include "D_BUILD_Layout_A.h"

#include "C_GET_P.h"
#include "C_ID_Exp_P.h"

Layout BUILD::Layout_A::exposed() {
	Layout layout;
	for (auto& id : ID::exp_params) {
		auto name{ GET::exp_name_for(id) };
		auto choices{ GET::choices_for(id) };
		auto init_choice{ GET::init_choice_for(id) };
		layout.add(std::make_unique<AudioParameterChoice>(id, name, choices, init_choice));
	}
	return layout;
}
