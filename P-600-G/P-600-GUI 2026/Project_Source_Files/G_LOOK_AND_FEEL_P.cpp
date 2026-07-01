#include "G_LOOK_AND_FEEL_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	if (s.getComponentID() != ID::knob_led_voice_num.toString()) {
		auto diam{ (float)s.getWidth() };
		Point<float> center{ diam / 2.0f, diam / 2.0f };
		Line<float> line;
		line.setStart(center.x, diam);
		line.setEnd(center.x, diam - 4 * scale_factor);
		Path indicator;
		indicator.addLineSegment(line, 1.5f * scale_factor);
		auto angle = min_angle + pos * (max_angle - min_angle);
		indicator.applyTransform(AffineTransform::rotation(angle, center.x, center.y));
		g.setColour(COLOR::grey_lite);
		PathStrokeType stroke{ 1.5f, PathStrokeType::mitered };
		g.strokePath(indicator, stroke);
	}
}

void Look_And_Feel_P::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float pos, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& /*s*/)
{
	auto tab_h = 16 * scale_factor;
	auto tab_w = 18 * scale_factor;
	Rectangle<float> tab_bounds{ 0.0f, 0.0f, tab_w , tab_h};
	tab_bounds.setCentre(10 * scale_factor, pos);
	g.setColour(COLOR::grey_dark);
	g.fillRect(tab_bounds);
	g.setColour(COLOR::grey_lite);
	g.drawRect(tab_bounds, 0.3f * scale_factor);
}
