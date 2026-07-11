#include "G_LAYER_Exp_Ctrls_P.h"

Layer_Exposed_Controls_P::Layer_Exposed_Controls_P(Data_Hub_P* hub) :
	Data_User_P{ hub }
{
	for (int param_index = 0; param_index < EXP::exp_param_count; ++param_index) {
		auto ctrl_type = exp_info.ctrl_type_for(param_index);
		if (ctrl_type != Ctrl_Type::error) {
			if (ctrl_type == Ctrl_Type::cbox) {
				cboxes.push_back(std::make_unique<Combo_Box_Exposed_B>(param_index, hub));
				auto cbox_ptr = cboxes[cboxes.size() - 1].get();
				if (cbox_ptr) {
					cbox_ptr->attach_to_param();
					addAndMakeVisible(cbox_ptr);
				}
			}
			else {
				sliders.push_back(std::make_unique<Slider_Exposed_P>(param_index, hub));
				auto slider_ptr = sliders[sliders.size() - 1].get();
				if (slider_ptr) {
					slider_ptr->attach_to_param();
					addAndMakeVisible(slider_ptr);
				}
			}
		}
	}
}

void Layer_Exposed_Controls_P::resized() {
	for (int i = 0; i < sliders.size(); ++i) {
		auto slider_ptr = sliders[i].get();
		if (slider_ptr)
			slider_ptr->setBounds(slider_ptr->get_scaled_bounds());
	}
	for (int i = 0; i < cboxes.size(); ++i) {
		auto cbox_ptr = cboxes[i].get();
		if (cbox_ptr)
			cbox_ptr->setBounds(cbox_ptr->get_scaled_bounds());
	}
}

Layer_Exposed_Controls_P::~Layer_Exposed_Controls_P() {
	for (int i = 0; i < sliders.size(); ++i) {
		auto slider_ptr = sliders[i].get();
		if (slider_ptr)
			slider_ptr->remove_attachment();
	}
	sliders.clear();
	for (int i = 0; i < cboxes.size(); ++i) {
		auto cbox_ptr = cboxes[i].get();
		if (cbox_ptr)
			cbox_ptr->remove_attachment();
	}
	cboxes.clear();
}
