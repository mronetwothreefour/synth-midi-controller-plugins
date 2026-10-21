#include "G_LAYER_Envelopes_P.h"

#include "C_ID_Main_P.h"

using namespace LAYER;

Envelopes::Envelopes(Data_Hub* hub) :
	Data_User{ hub },
	env{ false, hub },
	vca_env{ true, hub }
{
	setInterceptsMouseClicks(false, true);
	addChildComponent(env);
	env.setInterceptsMouseClicks(false, false);
	addChildComponent(vca_env);
	vca_env.setInterceptsMouseClicks(false, false);
	val_show_env = app_p.get_param_as_value(ID::app_show_env);
	val_show_env.addListener(this);
	val_show_vca_env = app_p.get_param_as_value(ID::app_show_vca_env);
	val_show_vca_env.addListener(this);
}

void Envelopes::resized() {
	env.setBounds(getLocalBounds());
	vca_env.setBounds(getLocalBounds());
}

void Envelopes::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_show_env))
		env.setVisible(app_p.show_envelope());
	if (v.refersToSameSourceAs(val_show_vca_env))
		vca_env.setVisible(app_p.show_vca_envelope());
}

Envelopes::~Envelopes() {
	val_show_env.removeListener(this);
	val_show_vca_env.removeListener(this);
}
