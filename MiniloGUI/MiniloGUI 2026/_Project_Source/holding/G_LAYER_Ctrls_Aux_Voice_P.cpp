#include "G_LAYER_Ctrls_Aux_Voice_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_NAME_P.h"

using namespace LAYER;
using namespace WIDGET;

Ctrls_Aux_Voice::Ctrls_Aux_Voice(Data_Hub* hub) :
	Data_User{ hub }
{
	setInterceptsMouseClicks(false, true);
	for (auto& param_id : ID::aux_voice_params) {
		auto ctrl_name = GET::ctrl_name_for(param_id);
		if (ctrl_name.isNotEmpty()) {
			auto param_val = avp.get_param_as_value(param_id);
			if (ctrl_name == NAME::cbox) {
				cboxes.add(new Ctrl_Cbox_A{ param_id, param_val, hub });
				auto cbox = cboxes[cboxes.size() - 1];
				if (cbox)
					addAndMakeVisible(cbox);
				continue;
			}
			sliders.add(new Ctrl_Slider{ param_id, param_val, hub });
			auto slider = sliders[sliders.size() - 1];
			if (slider)
				addAndMakeVisible(slider);
		}
	}
}

void Ctrls_Aux_Voice::resized() {
	for (int i = 0; i < cboxes.size(); ++i) {
		if (cboxes[i])
			cboxes[i]->setBounds(cboxes[i]->scaled_bounds());
	}
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->setBounds(sliders[i]->scaled_bounds());
	}
}

Ctrls_Aux_Voice::~Ctrls_Aux_Voice() {
	cboxes.clear();
	sliders.clear();
}
