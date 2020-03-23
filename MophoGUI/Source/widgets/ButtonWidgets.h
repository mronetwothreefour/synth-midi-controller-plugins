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

	// Override this function to create a tooltip String with a parameter
	// description and/or a verbose version of the parameter's current value
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
		MophoLookAndFeel* mophoLaF
	) : 
		ButtonWidget{ name, apvts, privateParameters, ID::oscSync, mophoLaF }
	{}

	~ButtonWidget_Sync() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters.intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "Turns oscillator sync on or off. When\n";
			tooltip += "turned on, every time oscillator 2 resets\n";
			tooltip += "it forces oscillator 1 to reset as well.";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_Sync)
};

//==============================================================================
// A button widget appropriate for controlling an oscillator's keyboard tracking parameter.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_Track : public ButtonWidget
{
public:
	ButtonWidget_Track
	(
		String name,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) : 
		ButtonWidget{ name, apvts, privateParameters, paramID, mophoLaF }
	{}

	~ButtonWidget_Track() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters.intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "Turns the oscillator's keyboard tracking\n";
			tooltip += "on or off. When turned off, the oscillator\n";
			tooltip += "always produces its base pitch, unaffected\n";
			tooltip += "by the pitch of incoming MIDI notes.\n";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_Track)
};

//==============================================================================
// A button widget appropriate for controlling envelope 3's repeat parameter.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_Repeat : public ButtonWidget
{
public:
	ButtonWidget_Repeat
	(
		String name,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) : 
		ButtonWidget{ name, apvts, privateParameters, ID::env3Repeat, mophoLaF }
	{}

	~ButtonWidget_Repeat() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters.intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "When repeat is on, envelope 3 loops through\n";
			tooltip += "its delay, attack, decay, and sustain segments\n";
			tooltip += "for as long as the envelope is gated on.\n";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_Repeat)
};

//==============================================================================
// A button widget appropriate for turning the Mopho's arpeggiator on and off.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_Arpeg : public ButtonWidget
{
public:
	ButtonWidget_Arpeg
	(
		String name,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) : 
		ButtonWidget{ name, apvts, privateParameters, ID::arpegOnOff, mophoLaF }
	{}

	~ButtonWidget_Arpeg() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters.intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "Turns the Mopho's arpeggiator on and off.\n";
			tooltip += "Turning this on will turn off the sequencer.";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_Arpeg)
};

