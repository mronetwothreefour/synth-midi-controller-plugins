#include "G_LAYER_Exp_Ctrls_P.h"

#include "C_EXP_P.h"

Layer_Exposed_Controls_P::Layer_Exposed_Controls_P(Data_Hub_P* hub) :
	Data_User_P{ hub }
{
	setInterceptsMouseClicks(false, true);
	for (int i = 0; i < EXP::exp_param_count; ++i) {
		auto ctrl_type = exp_info.ctrl_type_for(Exp_Param(i));
		if (ctrl_type != Ctrl_Type::error) {
			if (ctrl_type == Ctrl_Type::cbox) {
				cboxes.push_back(std::make_unique<Combo_Box_Exposed_G>(Exp_Param(i), hub));
				auto cbox_ptr = cboxes[cboxes.size() - 1].get();
				if (cbox_ptr) {
					cbox_ptr->attach_to_param();
					addAndMakeVisible(cbox_ptr);
				}
				continue;
			}
			if (ctrl_type == Ctrl_Type::toggle) {
				toggles.push_back(std::make_unique<Toggle_Exposed_P>(Exp_Param(i), hub));
				auto toggle_ptr = toggles[toggles.size() - 1].get();
				if (toggle_ptr) {
					toggle_ptr->attach_to_param();
					addAndMakeVisible(toggle_ptr);
				}
				continue;
			}
			sliders.push_back(std::make_unique<Slider_Exposed_P>(Exp_Param(i), hub));
			auto slider_ptr = sliders[sliders.size() - 1].get();
			if (slider_ptr) {
				slider_ptr->attach_to_param();
				addAndMakeVisible(slider_ptr);
			}
		}
	}
}

void Layer_Exposed_Controls_P::resized() {
	for (int i = 0; i < cboxes.size(); ++i) {
		auto cbox_ptr = cboxes[i].get();
		if (cbox_ptr)
			cbox_ptr->setBounds(cbox_ptr->get_scaled_bounds());
	}
	for (int i = 0; i < sliders.size(); ++i) {
		auto slider_ptr = sliders[i].get();
		if (slider_ptr)
			slider_ptr->setBounds(slider_ptr->get_scaled_bounds());
	}
	for (int i = 0; i < toggles.size(); ++i) {
		auto toggle_ptr = toggles[i].get();
		if (toggle_ptr)
			toggle_ptr->setBounds(toggle_ptr->get_scaled_bounds());
	}
}

Layer_Exposed_Controls_P::~Layer_Exposed_Controls_P() {
	for (int i = 0; i < cboxes.size(); ++i) {
		auto cbox_ptr = cboxes[i].get();
		if (cbox_ptr)
			cbox_ptr->remove_attachment();
	}
	cboxes.clear();
	for (int i = 0; i < sliders.size(); ++i) {
		auto slider_ptr = sliders[i].get();
		if (slider_ptr)
			slider_ptr->remove_attachment();
	}
	sliders.clear();
	for (int i = 0; i < toggles.size(); ++i) {
		auto toggle_ptr = toggles[i].get();
		if (toggle_ptr)
			toggle_ptr->remove_attachment();
	}
	toggles.clear();
}
