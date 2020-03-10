#pragma once

#include <JuceHeader.h>

#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"

using Attachment = AudioProcessorValueTreeState::SliderAttachment;

//==============================================================================
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

//==============================================================================
// Base class for knob widgets. Derived classes must
// override drawValue() and drawHoverHint()
class KnobWidget : public Component, public Slider::Listener
{
public:
	KnobWidget
	(
		String knobName,
		AudioProcessorValueTreeState* apvts,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		sliderAttachment{ *apvts, paramID.toString(), slider },
		mophoLaF{ mophoLaF },
		name{ knobName }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setLookAndFeel(mophoLaF);
		slider.addListener(this);
		addAndMakeVisible(slider);

		valueDisplayLabel.setInterceptsMouseClicks(false, false);
		valueDisplayLabel.setLookAndFeel(mophoLaF);
		addAndMakeVisible(valueDisplayLabel);

		auto knobWidget_w{ 40 };
		auto knobWidget_h{ 50 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget()
	{
		valueDisplayLabel.setLookAndFeel(nullptr);
		slider.removeListener(this);
		slider.setLookAndFeel(nullptr);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);
		g.fillEllipse(5, 5, 30, 30);

		Font controlLabel{ "Arial", "Narrow", 13.5f };
		g.setFont(controlLabel);
		Rectangle<int> controlLabelArea{ 0, 35, 40, 15 };
		g.drawText(name, controlLabelArea, Justification::centred);
	}

	void resized() override
	{
		slider.setBounds(0, 0, 40, 40);
		valueDisplayLabel.setBounds(5, 5, 30, 30);
	}

	void sliderValueChanged(Slider* sliderThatChanged)
	{
		if (sliderThatChanged == &slider)
			drawValue(slider.getValue());
	}

	auto getSliderValue() { return slider.getValue(); }

	void setValueDisplayLabelText(String text) { valueDisplayLabel.setText(text, dontSendNotification); }

private:
	CustomSlider slider;
	Attachment sliderAttachment;
	MophoLookAndFeel* mophoLaF;
	Label valueDisplayLabel;

	String name;

	//==============================================================================
	// Override this function to define how the current
	// parameter value is drawn on the knob
	virtual void drawValue(double currentValue) = 0;

	// Override this function to define how a pop-up window with a parameter 
	// description and a verbose version of the current parameter value is 
	// drawn when the mouse hovers over the slider
	virtual void drawHoverHint(double currentValue) const = 0;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget)
};

//==============================================================================
// 
class KnobWidget_OscPitch : public KnobWidget
{
public:
	KnobWidget_OscPitch
	(
		String knobName, 
		AudioProcessorValueTreeState* apvts, 
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ knobName, apvts, paramID, mophoLaF },
		numberOfSteps{ 120 }
	{
		drawValue(getSliderValue());
	}

	~KnobWidget_OscPitch()
	{}

private:
	int numberOfSteps;

	ValueConverters valueConverters;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(double currentValue) override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	void drawHoverHint(double currentValue) const override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscPitch)
};