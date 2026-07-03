#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_Sliders_P.h"

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
