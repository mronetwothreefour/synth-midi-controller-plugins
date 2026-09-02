#include "G_Look_And_Feel_P.h"

#include "C_NAME_P.h"
#include "G_DRAW_Paths_Widgets_P.h"

using Draw_Widget = DRAW::Paths_Widgets;

Look_And_Feel::Look_And_Feel(float& scale_factor) :
	Look_And_Feel_A{ scale_factor }
{}

void Look_And_Feel::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									 const float min_angle, const float max_angle, Slider& s)
{
	if (s.getName() != NAME::knob_led_voice_num) {
		auto rotation = min_angle + pos * (max_angle - min_angle);
		Draw_Widget::knob(g, rotation, scale_factor);
	}
}

void Look_And_Feel::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float /*pos*/, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& s)
{
	auto n = s.getName();
	if (n == NAME::switch_2_pole)
		Draw_Widget::switch_2_pole(g, scale_factor, roundToInt(s.getValue()));
	if (n == NAME::switch_3_pole)
		Draw_Widget::switch_3_pole(g, scale_factor, roundToInt(s.getValue()));
}

