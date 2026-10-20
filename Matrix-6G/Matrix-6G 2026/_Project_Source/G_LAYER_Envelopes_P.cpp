#include "G_LAYER_Envelopes_P.h"

#include "C_XYWH_P.h"

using namespace LAYER;
using namespace XYWH;

Envelopes::Envelopes(Data_Hub* hub) :
	Data_User{ hub },
	tracking_env{ hub },
	env_1{ 1, hub },
	env_2{ 2, hub },
	env_3{ 3, hub }
{
	setInterceptsMouseClicks(false, false);
	addAndMakeVisible(tracking_env);
	addAndMakeVisible(env_1);
	addAndMakeVisible(env_2);
	addAndMakeVisible(env_3);
}

void Envelopes::resized() {
	tracking_env.setBounds(getLocalBounds());
	Rectangle<int> env_bounds{ env_1_init_x, env_init_y, env_init_w, env_init_h };
	env_bounds = env_bounds.transformedBy(AffineTransform::scale(scale_f));
	env_1.setBounds(env_bounds);
	env_bounds.translate(roundToInt(env_block_spacing * scale_f), 0);
	env_2.setBounds(env_bounds);
	env_bounds.translate(roundToInt(env_block_spacing * scale_f), 0);
	env_3.setBounds(env_bounds);
}
