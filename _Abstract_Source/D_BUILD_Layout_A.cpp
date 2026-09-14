#include "D_BUILD_Layout_A.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"

Layout BUILD::Layout_A::exposed() {
	Layout layout;
	for (auto id : ID::exp_params) {
		layout.add(std::make_unique<AudioParameterChoice>(id, 
														  GET::exp_name_for(id), 
														  GET::choices_for(id), 
														  GET::init_choice_for(id)));
	}
	return layout;
}
