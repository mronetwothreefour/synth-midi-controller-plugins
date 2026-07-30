#include "G_LAYER_Envelopes_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Layer_Envelopes_P::Layer_Envelopes_P(Data_Hub_P* hub) :
	Data_User_P{ hub },
	env_lpf{ Env_Type::env_lpf, hub },
	env_vca{ Env_Type::env_vca, hub },
	env_3{ Env_Type::env_3, hub }
{
	setInterceptsMouseClicks(false, false);
	addAndMakeVisible(env_lpf);
	addAndMakeVisible(env_vca);
	addAndMakeVisible(env_3);
}

void Layer_Envelopes_P::resized() {
	Rectangle<int> env_bounds{ env_init_x, env_lpf_init_y, env_init_w, env_init_h };
	env_bounds = env_bounds.transformedBy(AffineTransform::scale(scale_factor));
	env_lpf.setBounds(env_bounds);
	env_bounds.translate(0, roundToInt(env_block_spacing * scale_factor));
	env_vca.setBounds(env_bounds);
	env_bounds.translate(0, roundToInt(env_block_spacing * scale_factor));
	env_3.setBounds(env_bounds);
}
