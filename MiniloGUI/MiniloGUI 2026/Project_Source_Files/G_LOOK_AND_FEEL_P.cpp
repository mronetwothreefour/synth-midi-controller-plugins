#include "G_LOOK_AND_FEEL_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	auto diam{ (float)s.getWidth() };
	Point<float> center{ diam / 2.0f, diam / 2.0f };
	Line<float> line;
	line.setStart(center.x, diam);
	line.setEnd(center.x, diam - 4 * scale_factor);
	Path indicator;
	indicator.addLineSegment(line, 1.5f * scale_factor);
	auto angle = min_angle + pos * (max_angle - min_angle);
	indicator.applyTransform(AffineTransform::rotation(angle, center.x, center.y));
	g.setColour(COLOR::grey_knob_indicators);
	PathStrokeType stroke{ 1.5f, PathStrokeType::mitered };
	g.strokePath(indicator, stroke);
}

void Look_And_Feel_P::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float /*pos*/, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& s)
{
	auto tab_diameter = 12 * scale_factor;
	if (s.getComponentID() == ID::switch_osc_octave.toString()) {
		auto s_val = roundToInt(s.getValue());
		auto tab_center_y = ((3 - s_val) * 12 + 8) * scale_factor;
		Rectangle<float> tab_bounds{ 0.0f, 0.0f, tab_diameter , tab_diameter };
		tab_bounds.setCentre(8 * scale_factor, tab_center_y);
		g.setColour(COLOR::grey_switch_tabs);
		g.fillEllipse(tab_bounds);
		auto led_diameter = 8 * scale_factor;
		Rectangle<float> led_bounds{ 0.0f, 0.0f, led_diameter, led_diameter };
		led_bounds.setCentre(30 * scale_factor, tab_center_y);
		g.setColour(COLOR::red_led_on);
		g.fillEllipse(led_bounds);
	}
}
