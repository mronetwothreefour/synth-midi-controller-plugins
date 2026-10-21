#include "G_LAYER_Ctrls_Exp_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_XYWH_P.h"

using namespace LAYER;
using namespace WIDGET;

Ctrls_Exposed::Ctrls_Exposed(Data_Hub* hub) :
	Data_User{ hub }
{
	addAndMakeVisible(trig_area_env);
	trig_area_env.setInterceptsMouseClicks(true, false);
	trig_area_env.addMouseListener(this, false);
	addAndMakeVisible(trig_area_vca_env);
	trig_area_vca_env.setInterceptsMouseClicks(true, false);
	trig_area_vca_env.addMouseListener(this, false);

	for (auto& param_id : ID::exp_params) {
		auto ctrl_name = GET::ctrl_name_for(param_id);
		if (!ctrl_name.empty()) {
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
	auto trig_area_env_bounds = XYWH::trig_area_env_init_bounds * scale_f;
	trig_area_env_bounds.expand(5, 5);
	trig_area_env.setBounds(trig_area_env_bounds);
	auto trig_area_vca_env_bounds = XYWH::trig_area_vca_env_init_bounds * scale_f;
	trig_area_vca_env_bounds.expand(5, 5);
	trig_area_vca_env.setBounds(trig_area_vca_env_bounds);

	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->setBounds(sliders[i]->scaled_bounds());
	}
}

void LAYER::Ctrls_Exposed::mouseEnter(const MouseEvent& e) {
	if (e.eventComponent == &trig_area_env)
		app_p.set_show_envelope(true);
	if (e.eventComponent == &trig_area_vca_env)
		app_p.set_show_vca_envelope(true);
	repaint();
}

void LAYER::Ctrls_Exposed::mouseExit(const MouseEvent& e) {
	if (e.eventComponent == &trig_area_env)
		if (!trig_area_env.getScreenBounds().contains(e.getScreenPosition()))
			app_p.set_show_envelope(false);
	if (e.eventComponent == &trig_area_vca_env)
		if (!trig_area_vca_env.getScreenBounds().contains(e.getScreenPosition()))
			app_p.set_show_vca_envelope(false);
	repaint();
}

void LAYER::Ctrls_Exposed::mouseUp(const MouseEvent& e) {
	if (!trig_area_env.getScreenBounds().contains(e.getScreenPosition()))
		app_p.set_show_envelope(false);
	if (!trig_area_vca_env.getScreenBounds().contains(e.getScreenPosition()))
		app_p.set_show_vca_envelope(false);
	repaint();
}

Ctrls_Exposed::~Ctrls_Exposed() {
	for (int i = 0; i < sliders.size(); ++i) {
		if (sliders[i])
			sliders[i]->remove_attachment();
	}
	sliders.clear();
}
