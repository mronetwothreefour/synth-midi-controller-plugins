#include "G_LAYER_Envelopes_P.h"

Layer_Envelopes_P::Layer_Envelopes_P(Data_Hub_P* hub) :
	Data_User_P{ hub },
	env{ false, hub },
	vca_env{ true, hub }
{
	setInterceptsMouseClicks(false, true);
	addChildComponent(env);
	env.setInterceptsMouseClicks(false, false);
	addChildComponent(vca_env);
	vca_env.setInterceptsMouseClicks(false, false);
	val_show_env = app_options.get_option_as_value(App_Option::show_env);
	val_show_env.addListener(this);
	val_show_vca_env = app_options.get_option_as_value(App_Option::show_vca_env);
	val_show_vca_env.addListener(this);
}

void Layer_Envelopes_P::resized() {
	env.setBounds(getLocalBounds());
	vca_env.setBounds(getLocalBounds());
}

void Layer_Envelopes_P::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_show_env))
		env.setVisible(app_options.show_envelope());
	if (v.refersToSameSourceAs(val_show_vca_env))
		vca_env.setVisible(app_options.show_vca_envelope());
}

Layer_Envelopes_P::~Layer_Envelopes_P() {
	val_show_env.removeListener(this);
	val_show_vca_env.removeListener(this);
}
