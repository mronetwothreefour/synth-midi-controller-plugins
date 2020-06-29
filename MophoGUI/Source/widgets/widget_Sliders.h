#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

//==============================================================================
// Overrides Slider's mouseWheelMove() operation so that each wheel move event
// increments/decrements the slider's value by a single interval (step)
class SliderWithMouseWheelMod : public Slider
{
public:
	void mouseWheelMove(const MouseEvent& /*e*/, const MouseWheelDetails& wheel) override
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

//==============================================================================
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

//==============================================================================
struct TooltipSetter
{};

//==============================================================================
class Knob : public Component
{
	RotarySliderWithMouseWheelMod knob;
	std::unique_ptr<SliderAttachment> attachment;

	TooltipSetter tooltipSetter;

public:
	Knob()
	{
		addAndMakeVisible(knob);
		knob.setComponentID(ID::component_Knob.toString());

		auto knob_diam{ 40 };
		setSize(knob_diam, knob_diam);
		knob.setBounds(getLocalBounds());
	}

	~Knob() {}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		attachment.reset(new SliderAttachment(*exposedParams, paramID.toString(), knob));
	}

	void deleteAttachment()
	{
		attachment = nullptr;
	}
};

class KnobWithValueStringDisplay : public Component
{
	Knob knob;

public:
	KnobWithValueStringDisplay()
	{
		addAndMakeVisible(knob);
		setSize(knob.getWidth(), knob.getHeight());
	}

	~KnobWithValueStringDisplay() {}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		knob.attachToExposedParameter(exposedParams, paramID);
	}

	void deleteAttachment() { knob.deleteAttachment(); }
};

