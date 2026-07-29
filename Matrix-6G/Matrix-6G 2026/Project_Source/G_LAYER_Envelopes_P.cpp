#include "G_LAYER_Envelopes_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Layer_Envelopes_P::Layer_Envelopes_P(Data_Hub_P* hub) :
	Data_User_P{ hub },
	env_1{ Env_Type::env_1, hub },
	env_2{ Env_Type::env_2, hub },
	env_3{ Env_Type::env_3, hub }
{
	setInterceptsMouseClicks(false, false);
	addAndMakeVisible(env_1);
	addAndMakeVisible(env_2);
	addAndMakeVisible(env_3);
}

void Layer_Envelopes_P::resized() {
	Rectangle<int> env_bounds{ env_1_init_x, env_init_y, env_init_w, env_init_h };
	env_bounds = env_bounds.transformedBy(AffineTransform::scale(scale_factor));
	env_1.setBounds(env_bounds);
	env_bounds.translate(roundToInt(env_block_spacing * scale_factor), 0);
	env_2.setBounds(env_bounds);
	env_bounds.translate(roundToInt(env_block_spacing * scale_factor), 0);
	env_3.setBounds(env_bounds);
}
