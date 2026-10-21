#include "G_LAYER_Envelopes_P.h"

#include "C_XYWH_P.h"

using namespace LAYER;
using namespace XYWH;

Envelopes::Envelopes(Data_Hub* hub) :
	Data_User{ hub },
	env_lpf{ "exp_lpf", hub},
	env_vca{ "exp_vca", hub},
	env_3{ "exp_env_3", hub}
{
	setInterceptsMouseClicks(false, false);
	addAndMakeVisible(env_lpf);
	addAndMakeVisible(env_vca);
	addAndMakeVisible(env_3);
}

void Envelopes::resized() {
	Rectangle<int> env_bounds{ env_init_x, env_lpf_init_y, env_init_w, env_init_h };
	env_bounds = env_bounds.transformedBy(AffineTransform::scale(scale_f));
	env_lpf.setBounds(env_bounds);
	env_bounds.translate(0, roundToInt(env_block_spacing * scale_f));
	env_vca.setBounds(env_bounds);
	env_bounds.translate(0, roundToInt(env_block_spacing * scale_f));
	env_3.setBounds(env_bounds);
}
