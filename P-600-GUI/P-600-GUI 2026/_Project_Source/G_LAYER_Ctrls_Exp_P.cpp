#include "G_LAYER_Ctrls_Exp_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_NAME_P.h"

using namespace LAYER;
using namespace WIDGET;

Ctrls_Exposed::Ctrls_Exposed(Data_Hub* hub) :
	Data_User{ hub }
{
	for (auto& param_id : ID::exp_params) {
		auto ctrl_name = GET::ctrl_name_for(param_id);
		if (ctrl_name.isNotEmpty()) {
			auto param_val = exp_state->getParameterAsValue(param_id);
			sliders.add(new Ctrl_Slider{ param_id, param_val, hub });
			auto slider = sliders[sliders.size() - 1];
			if (slider) {
				slider->attach_to_param();
				addAndMakeVisible(slider);
			}
		}
	}
}

void Ctrls_Exposed::resized() {
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->setBounds(sliders[i]->scaled_bounds());
	}
}

Ctrls_Exposed::~Ctrls_Exposed() {
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->remove_attachment();
	}
	sliders.clear();
}
