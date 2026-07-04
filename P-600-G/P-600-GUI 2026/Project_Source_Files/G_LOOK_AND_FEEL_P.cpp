#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_Widgets_P.h"

using Draw_Widget = Draw_Paths_Widgets_P;

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	if (s.getComponentID() != ID::knob_led_voice_num.toString()) {
		auto rotation = min_angle + pos * (max_angle - min_angle);
		Draw_Widget::knob(g, rotation, scale_factor);
	}
}

void Look_And_Feel_P::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float pos, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& s)
{
	if (s.getComponentID() == ID::switch_2_pole.toString())
		Draw_Widget::switch_2_pole(g, scale_factor, roundToInt(s.getValue()));
	if (s.getComponentID() == ID::switch_3_pole.toString())
		Draw_Widget::switch_3_pole(g, scale_factor, roundToInt(s.getValue()));
}
