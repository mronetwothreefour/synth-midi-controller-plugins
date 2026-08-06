#include "G_LAYER_Exp_Ctrls_P.h"

#include "C_EXP_P.h"
#include "C_XYWH_P.h"

Layer_Exposed_Controls_P::Layer_Exposed_Controls_P(Data_Hub_P* hub) :
	Data_User_P{ hub }
{
	setInterceptsMouseClicks(false, true);

	addAndMakeVisible(trig_area_env);
	trig_area_env.setInterceptsMouseClicks(true, false);
	trig_area_env.addMouseListener(this, false);
	addAndMakeVisible(trig_area_vca_env);
	trig_area_vca_env.setInterceptsMouseClicks(true, false);
	trig_area_vca_env.addMouseListener(this, false);

	for (int i = 0; i < EXP::exp_param_count; ++i) {
		auto ctrl_type = exp_info.ctrl_type_for(Exp_Param(i));
		if (ctrl_type != Ctrl_Type::error) {
			sliders.add(new Slider_Exposed_P{ Exp_Param(i), hub });
			auto slider_ptr = sliders[sliders.size() - 1];
			if (slider_ptr) {
				slider_ptr->attach_to_param();
				addAndMakeVisible(slider_ptr);
				if ((i >= Exp_Param::env_attack && i <= Exp_Param::env_sustain) ||
					(i >= Exp_Param::vca_env_attack && i <= Exp_Param::vca_env_sustain))
				{
					slider_ptr->addMouseListener(this, false);
				}
			}
		}
	}
}

void Layer_Exposed_Controls_P::resized() {
	auto trig_area_env_bounds = XYWH::trig_area_env_init_bounds * scale_factor;
	trig_area_env_bounds.expand(5, 5);
	trig_area_env.setBounds(trig_area_env_bounds);
	auto trig_area_vca_env_bounds = XYWH::trig_area_vca_env_init_bounds * scale_factor;
	trig_area_vca_env_bounds.expand(5, 5);
	trig_area_vca_env.setBounds(trig_area_vca_env_bounds);

	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->setBounds(sliders[i]->get_scaled_bounds());
	}
}

void Layer_Exposed_Controls_P::mouseEnter(const MouseEvent& e) {
	if (e.eventComponent == &trig_area_env)
		app_options.set_show_envelope(true);
	if (e.eventComponent == &trig_area_vca_env)
		app_options.set_show_vca_envelope(true);
	repaint();
}

void Layer_Exposed_Controls_P::mouseExit(const MouseEvent& e) {
	if (e.eventComponent == &trig_area_env)
		if (!trig_area_env.getScreenBounds().contains(e.getScreenPosition()))
			app_options.set_show_envelope(false);
	if (e.eventComponent == &trig_area_vca_env)
		if (!trig_area_vca_env.getScreenBounds().contains(e.getScreenPosition()))
			app_options.set_show_vca_envelope(false);
	repaint();
}

void Layer_Exposed_Controls_P::mouseUp(const MouseEvent& e) {
	if (!trig_area_env.getScreenBounds().contains(e.getScreenPosition()))
		app_options.set_show_envelope(false);
	if (!trig_area_vca_env.getScreenBounds().contains(e.getScreenPosition()))
		app_options.set_show_vca_envelope(false);
	repaint();
}


Layer_Exposed_Controls_P::~Layer_Exposed_Controls_P() {
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->remove_attachment();
	}
	sliders.clear();
}
