#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;

//==============================================================================
// Base class for button widgets which use a toggle button and attach to a public parameter.
// Has a createTooltipString() function that derived classes must override.
class ButtonWidget : public Component, public Button::Listener
{
public:
	PrivateParameters* privateParams;

	ButtonWidget
	(
		String name,
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID
	) :
		button{ name },
		buttonAttachment{ *publicParameters, paramID.toString(), button },
		privateParams{ privateParameters }
	{
		button.setComponentID(ID::paramToggle.toString());
		button.addListener(this);
		addAndMakeVisible(button);

		auto buttonWidget_diameter{ 14 };
		setSize(buttonWidget_diameter, buttonWidget_diameter);
	}

	~ButtonWidget()
	{
		button.removeListener(this);
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
			setButtonTooltip(tooltip);
		}
	}

	void setButtonTooltip(String text) { button.setTooltip(text); }

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
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) : 
		ButtonWidget{ "oscSync", publicParameters, privateParameters, ID::oscSync },
		valueConverters{ vc }
	{}

	~ButtonWidget_Sync() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToOffOn(currentValue) + "\n";
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
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		ValueConverters* vc
	) : 
		ButtonWidget{ name, publicParameters, privateParameters, paramID },
		valueConverters{ vc }
	{}

	~ButtonWidget_Track() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToOffOn(currentValue) + "\n";
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
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) : 
		ButtonWidget{ name, publicParameters, privateParameters, ID::env3Repeat },
		valueConverters{ vc }
	{}

	~ButtonWidget_Repeat() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToOffOn(currentValue) + "\n";
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
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) : 
		ButtonWidget{ "arpeg", publicParameters, privateParameters, ID::arpegOnOff },
		valueConverters{ vc }
	{}

	~ButtonWidget_Arpeg() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToOffOn(currentValue) + "\n";
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

//==============================================================================
// A button widget appropriate for selecting the low-pass filter type.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_LPFtype : public ButtonWidget
{
public:
	ButtonWidget_LPFtype
	(
		String name,
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) : 
		ButtonWidget{ name, publicParameters, privateParameters, ID::lpfType },
		valueConverters{ vc }
	{}

	~ButtonWidget_LPFtype() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToLPFtype(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
			tooltip += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
			tooltip += "slope and more pronounced resonance.";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_LPFtype)
};

//==============================================================================
// A button widget appropriate for turning an LFO's key sync parameter on and off.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_LFOkeySync : public ButtonWidget
{
public:
	ButtonWidget_LFOkeySync
	(
		int lfoNumber,
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) : 
		ButtonWidget{ "lfo" + (String)lfoNumber + "KeySync", publicParameters, privateParameters, "lfo" + (String)lfoNumber + "KeySync" },
		valueConverters{ vc }
	{}

	~ButtonWidget_LFOkeySync() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "When on, the LFO cycle re-starts\n";
			tooltip += "each time a new note is played.";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_LFOkeySync)
};

//==============================================================================
// A button widget appropriate for turning the Mopho's sequencer on and off.
// Derives from ButtonWidget and overrides createTooltipString()
class ButtonWidget_SequencerOffOn : public ButtonWidget
{
public:
	ButtonWidget_SequencerOffOn
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) :
		ButtonWidget{ "sequencer", publicParameters, privateParameters, ID::sequencerOnOff },
		valueConverters{ vc }
	{}

	~ButtonWidget_SequencerOffOn() {}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	String createTooltipString(const int& currentValue) const noexcept override
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + valueConverters->intToOffOn(currentValue) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += "Turns the Mopho's sequencer on and off.\n";
			tooltip += "Turning this on will turn off the arpeggiator.";
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget_SequencerOffOn)
};

