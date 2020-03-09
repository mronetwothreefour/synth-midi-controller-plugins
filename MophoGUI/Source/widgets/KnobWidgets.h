#pragma once

#include <JuceHeader.h>

#include "../lookAndFeel/LaF_Knob.h"

using Attachment = AudioProcessorValueTreeState::SliderAttachment;

// modifies mouseWheelMove() so slider
// value is changed by a single interval
// with each wheel move
class CustomSlider :
	public Slider
{
public:
	CustomSlider() {}

	void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override
	{
		ignoreUnused(e);
		float delta{ wheel.deltaY };
		double currentValue{ getValue() };
		double interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f)
		{
			setValue(currentValue + interval);
		}
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomSlider)
};

// 
class KnobWidget_OscPitch :
	public Component
{
public:
	KnobWidget_OscPitch
	(
		String knobName, 
		AudioProcessorValueTreeState* apvts, 
		Identifier paramID,
		LaF_Knob* knobLookAndFeel
	) :
		sliderAttachment{*apvts, paramID.toString(), slider},
		sliderLaF{ knobLookAndFeel }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setLookAndFeel(sliderLaF);
		addAndMakeVisible(slider);

		auto knobWidget_w{ 40 };
		auto knobWidget_h{ 50 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget_OscPitch()
	{
		slider.setLookAndFeel(nullptr);
	}

	//==============================================================================
	void paint(Graphics& g) override
	{
		g.setColour(Color::black);
		g.fillEllipse(5, 5, 30, 30);
	}

	void resized() override
	{
		slider.setBounds(0, 0, 40, 40);
	}

private:
	CustomSlider slider;
	Attachment sliderAttachment;
	LaF_Knob* sliderLaF;

	Label knobNameLabel;
	Label valueDisplayLabel;

	String name;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue()
	{

	}

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	void drawHoverHint()
	{

	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscPitch)
};