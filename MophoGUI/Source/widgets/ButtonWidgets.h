#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;

//==============================================================================
// Base class for button widgets. Derived
// classes must override createTooltipString()
class ButtonWidget : public Component, public Button::Listener
{
public:
	PrivateParameters* privateParams;

	ValueConverters valueConverters;

	ButtonWidget
	(
		String name,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		button{ name },
		buttonAttachment{ *apvts, paramID.toString(), button },
		privateParams{ privateParameters }
	{
		button.setLookAndFeel(mophoLaF);
		button.addListener(this);
		addAndMakeVisible(button);

		auto buttonWidget_diameter{ 14 };
		setSize(buttonWidget_diameter, buttonWidget_diameter);
	}

	~ButtonWidget()
	{
		button.removeListener(this);
		button.setLookAndFeel(nullptr);
	}

	void resized() override
	{
		button.setBounds(0, 0, 14, 14);
	}

	auto getButtonState() { return (int)button.getToggleState(); }

	void buttonClicked(Button* /*buttonThatWasClicked*/) override {}

	void buttonStateChanged(Button* buttonThatChanged) override
	{
		if (buttonThatChanged == &button)
		{
			auto currentValue{ getButtonState() };
			auto tooltip{ createTooltipString(currentValue) };
			setSliderTooltip(tooltip);
		}
	}

	void setSliderTooltip(String text) { button.setTooltip(text); }

private:
	String name;

	ToggleButton button;
	ButtonAttachment buttonAttachment;

	// Override this function to create a String with 
	// a verbose version of the current parameter value
	// along with a parameter description, which will
	// be used as the button's tooltip
	virtual String createTooltipString(const int& currentValue) const noexcept = 0;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget)
};

//==============================================================================
// A button widget appropriate for controlling the oscillator sync parameter.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_Sync : public ButtonWidget
{
public:
	ButtonWidget_Sync
	(
		String name,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) : 
		ButtonWidget{ name, apvts, privateParameters, paramID, mophoLaF }
	{}

	~ButtonWidget_Sync() {}

private:
	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the button
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters.intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "Turns oscillator sync on or off. When\n";
			tooltip += "turned on, every time oscillator 2 resets\n";
			tooltip += "it forces oscillator 1 to reset as well.\n";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_Sync)
};