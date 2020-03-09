#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"

class LaF_Knob :
	public LookAndFeel_V4
{
public:
	LaF_Knob()
	{}

	~LaF_Knob() {}

	void drawRotarySlider(Graphics& g, int /*x*/, int y, int width, int /*height*/,
		float sliderPos, const float rotaryStartAngle,
		const float rotaryEndAngle, Slider& /*slider*/) override
	{
		Point<float> center{ float(width) / 2.0f, float(width) / 2.0f };

		// draw pointer and rotate it according to the slider's value
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		Line<float> l;
		l.setStart(center);
		l.setEnd(center.x, float(y + 1));
		Path p;
		p.addArrow(l, 1.0f, 8.0f, 6.0f);
		p.applyTransform(AffineTransform::rotation(angle, center.x, center.y));
		g.setColour(Color::black);
		g.fillPath(p);
	};

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LaF_Knob)
};