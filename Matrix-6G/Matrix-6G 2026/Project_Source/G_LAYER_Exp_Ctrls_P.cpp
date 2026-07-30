#include "G_LAYER_Exp_Ctrls_P.h"

#include "C_EXP_P.h"

Layer_Exposed_Controls_P::Layer_Exposed_Controls_P(Data_Hub_P* hub) :
	Data_User_P{ hub }
{
	for (int i = 0; i < EXP::exp_param_count; ++i) {
		auto ctrl_type = exp_info.ctrl_type_for(Exp_Param(i));
		if (ctrl_type != Ctrl_Type::error) {
			if (ctrl_type == Ctrl_Type::cbox) {
				cboxes.add(new Combo_Box_Exposed_G{ Exp_Param(i), hub });
				auto cbox_ptr = cboxes[cboxes.size() - 1];
				if (cbox_ptr) {
					cbox_ptr->attach_to_param();
					addAndMakeVisible(cbox_ptr);
				}
				continue;
			}
			sliders.add(new Slider_Exposed_P{ Exp_Param(i), hub });
			auto slider_ptr = sliders[sliders.size() - 1];
			if (slider_ptr) {
				slider_ptr->attach_to_param();
				addAndMakeVisible(slider_ptr);
			}
		}
	}
}

void Layer_Exposed_Controls_P::resized() {
	for (int i = 0; i < cboxes.size(); ++i) {
		auto cbox_ptr = cboxes[i];
		if (cbox_ptr)
			cbox_ptr->setBounds(cbox_ptr->get_scaled_bounds());
	}
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->setBounds(sliders[i]->get_scaled_bounds());
	}
}

Layer_Exposed_Controls_P::~Layer_Exposed_Controls_P() {
	for (int i = 0; i < cboxes.size(); ++i) {
		if (cboxes[i])
			cboxes[i]->remove_attachment();
	}
	cboxes.clear();
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->remove_attachment();
	}
	sliders.clear();
}
