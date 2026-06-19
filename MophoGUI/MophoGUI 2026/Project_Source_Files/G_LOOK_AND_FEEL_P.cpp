#include "G_LOOK_AND_FEEL_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{
}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	auto diam{ (float)s.getWidth() };
	Point<float> center{ diam / 2.0f, diam / 2.0f };
	Line<float> line;
	line.setStart(center.x, center.y);
	line.setEnd(center.x, diam);
	Path indicator;
	indicator.addArrow(line, scale_factor, 8.0f * scale_factor, 7.0f * scale_factor);
	auto angle = min_angle + pos * (max_angle - min_angle);
	indicator.applyTransform(AffineTransform::rotation(angle, center.x, center.y));
	g.setColour(COLOR::black);
	g.fillPath(indicator);
}
