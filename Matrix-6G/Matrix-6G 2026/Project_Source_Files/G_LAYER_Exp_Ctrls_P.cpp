#include "G_LAYER_Exp_Ctrls_P.h"

#include "G_WIDG_Cbox_Exp_B.h"
#include "G_WIDG_Slider_Exp_P.h"

Layer_Exposed_Controls_P::Layer_Exposed_Controls_P(Data_Hub_P* hub) :
	Data_User_P{ hub }
{
	for (uint8 param_index = 0; param_index < EXP::exp_param_count; ++param_index) {
		auto ctrl_type = exp_info.ctrl_type_for(param_index);
		if (ctrl_type == Ctrl_Type::slider ||
			ctrl_type == Ctrl_Type::slider_osc_pitch ||
			ctrl_type == Ctrl_Type::slider_osc_balance)
		{
			controls.push_back(std::make_unique<Slider_Exposed_P>(param_index, hub));
			auto slider_ptr = static_cast<Slider_Exposed_P*>(controls[param_index].get());
			if (slider_ptr)
				slider_ptr->attach_to_param();
		}
		if (ctrl_type == Ctrl_Type::cbox) {
			controls.push_back(std::make_unique<Combo_Box_Exposed_B>(param_index, hub));
			auto cbox_ptr = static_cast<Combo_Box_Exposed_B*>(controls[param_index].get());
			if (cbox_ptr)
				cbox_ptr->attach_to_param();
		}
		auto ctrl_ptr = controls[param_index].get();
		if (ctrl_ptr)
			addAndMakeVisible(ctrl_ptr);
	}
}

void Layer_Exposed_Controls_P::resized() {
	for (uint8 param_index = 0; param_index < EXP::exp_param_count; ++param_index) {
		auto ctrl_ptr = controls[param_index].get();
		if (ctrl_ptr) {
			auto center = exp_info.ctrl_center_for(param_index);
			auto x = roundToInt(center.x * scale_factor);
			auto y = roundToInt(center.y * scale_factor);
			auto w = roundToInt(exp_info.ctrl_width_for(param_index) * scale_factor);
			auto h = roundToInt(exp_info.ctrl_height_for(param_index) * scale_factor);
			ctrl_ptr->setBounds(x, y, w, h);
		}
	}
}

Layer_Exposed_Controls_P::~Layer_Exposed_Controls_P() {
	for (uint8 param_index = 0; param_index < EXP::exp_param_count; ++param_index) {
		auto ctrl_ptr = controls[param_index].get();
		if (ctrl_ptr) {
			auto ctrl_type = exp_info.ctrl_type_for(param_index);
			if (ctrl_type == Ctrl_Type::slider ||
				ctrl_type == Ctrl_Type::slider_osc_pitch ||
				ctrl_type == Ctrl_Type::slider_osc_balance)
			{
				static_cast<Slider_Exposed_P*>(ctrl_ptr)->remove_attachment();
			}
			if (ctrl_type == Ctrl_Type::cbox)
				static_cast<Combo_Box_Exposed_B*>(ctrl_ptr)->remove_attachment();
		}
	}
	controls.clear();
}
