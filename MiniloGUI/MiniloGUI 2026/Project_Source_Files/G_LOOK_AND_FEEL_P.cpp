#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_Sliders_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	auto rotation = min_angle + pos * (max_angle - min_angle);
	if (s.getComponentID() == ID::knob_lpf_freq.toString())
		Draw_Paths_Sliders_P::knob_lpf_freq(g, rotation, scale_factor);
	else
		Draw_Paths_Sliders_P::knob(g, rotation, scale_factor);
}

void Look_And_Feel_P::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float /*pos*/, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& s)
{
	if (s.getComponentID() == ID::switch_2_pole.toString()) {
		Draw_Paths_Sliders_P::switch_2_pole(g, scale_factor, roundToInt(s.getValue()));
	}
	if (s.getComponentID() == ID::switch_3_pole.toString()) {
		Draw_Paths_Sliders_P::switch_3_pole(g, scale_factor, roundToInt(s.getValue()));
	}
	if (s.getComponentID() == ID::switch_lpf_type.toString()) {
		Draw_Paths_Sliders_P::switch_lpf_type(g, scale_factor, roundToInt(s.getValue()));
	}
	if (s.getComponentID() == ID::switch_keyboard_octave.toString()) {
		Draw_Paths_Sliders_P::switch_keyboard_octave(g, scale_factor, roundToInt(s.getValue()));
	}
	if (s.getComponentID() == ID::switch_osc_octave.toString()) {
		Draw_Paths_Sliders_P::switch_osc_octave(g, scale_factor, roundToInt(s.getValue()));
	}
}
