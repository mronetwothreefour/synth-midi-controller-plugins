#include "G_LAYER_Envelopes_P.h"

#include "C_XYWH_P.h"

Layer_Envelopes_P::Layer_Envelopes_P(Data_Hub_P* hub) :
	Data_User_P{ hub },
	env{ false, hub },
	vca_env{ true, hub }
{
	setInterceptsMouseClicks(false, false);
	addAndMakeVisible(trigger_area_env);
	trigger_area_env.setInterceptsMouseClicks(false, false);
	trigger_area_env.addMouseListener(this, false);
	addAndMakeVisible(trigger_area_vca_env);
	trigger_area_vca_env.setInterceptsMouseClicks(false, false);
	trigger_area_env.addMouseListener(this, false);
	addChildComponent(env);
	env.setInterceptsMouseClicks(false, false);
	addChildComponent(vca_env);
	vca_env.setInterceptsMouseClicks(false, false);
}

void Layer_Envelopes_P::resized() {
	trigger_area_env.setBounds(XYWH::env_trig_area_init_bounds * scale_factor);
	trigger_area_vca_env.setBounds(XYWH::vca_env_trig_area_init_bounds * scale_factor);
	env.setBounds(getLocalBounds());
	vca_env.setBounds(getLocalBounds());
}

void Layer_Envelopes_P::mouseEnter(const MouseEvent& e) {
	if(e.eventComponent == &trigger_area_env)
		env.setVisible(true);
	if(e.eventComponent == &trigger_area_vca_env)
		vca_env.setVisible(true);
	repaint();
}

void Layer_Envelopes_P::mouseExit(const MouseEvent& /*e*/) {
	env.setVisible(false);
	vca_env.setVisible(false);
	repaint();
}
