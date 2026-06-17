#pragma once

#include <JuceHeader.h>

#include "G_LOOK_AND_FEEL_B.h"

class Look_And_Feel_P :
	public Look_And_Feel_B
{
//==============================================================================
public: explicit Look_And_Feel_P(float& scale_factor);

public: void draw_label_p(Graphics& g, Label& lbl, String& lbl_id) override;

public: void drawRotarySlider(Graphics& /*g*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float /*pos*/,
							  const float /*start_angle*/, const float /*end_angle*/, Slider& /*s*/) override {}
public: void drawLinearSlider(Graphics& g, int x, int y, int w, int h, float pos, float min_pos, 
							  float max_pos, const Slider::SliderStyle style, Slider& s) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel_P)
};
