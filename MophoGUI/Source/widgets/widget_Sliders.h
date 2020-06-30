#pragma once

#include <JuceHeader.h>



// Overrides the mouseWheelMove() operation so that each wheel move event
// increments/decrements the slider's value by a single interval (step)
class SliderWithMouseWheelMod : public Slider
{
public:
	void mouseWheelMove(const MouseEvent& /*event*/, const MouseWheelDetails& wheel) override
	{
		auto delta{ wheel.deltaY };
		auto currentValue{ getValue() };
		auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f)
		{
			setValue(currentValue + interval);
		}
	}
};



class RotarySliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	RotarySliderWithMouseWheelMod()
	{
		setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
	}
	~RotarySliderWithMouseWheelMod() {}
};

