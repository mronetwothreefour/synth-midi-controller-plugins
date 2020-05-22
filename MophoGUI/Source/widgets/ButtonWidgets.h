#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/InfoStrings.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;

//==============================================================================
// Base class for button widgets which use a toggle button and attach to a public parameter.
// Has a createTooltipString() function that derived classes must override.
class ButtonWidget : 
	public Component, 
	public Button::Listener,
	public ValueTree::Listener,
	public MophoParameterValueConverter,
	public MophoParameterInfoStringGenerator
{
public:
	PrivateParameters* privateParams;

	ButtonWidget
	(
		String name,
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		int index,
		int type
	) :
		button{ name },
		buttonAttachment{ *publicParameters, paramID.toString(), button },
		privateParams{ privateParameters },
		paramIndex{ index },
		paramType{ type }
	{
		privateParams->addListenerToGlobalOptions(this);

		button.setComponentID(ID::paramToggle.toString());
		button.addListener(this);
		addAndMakeVisible(button);

		auto buttonWidget_diameter{ 14 };
		setSize(buttonWidget_diameter, buttonWidget_diameter);
	}

	~ButtonWidget()
	{
		button.removeListener(this);
		privateParams->removeListenerFromGlobalOptions(this);
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

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
		{
			setButtonTooltip(createTooltipString(getButtonState()));
		}
	}

private:
	String name;

	int paramIndex;
	int paramType;

	ToggleButton button;
	ButtonAttachment buttonAttachment;

	// Override this function to create a tooltip String with a parameter
	// description and/or a verbose version of the parameter's current value
	virtual String createTooltipString(const int& currentValue) const noexcept
	{
		String tooltip{ "" };
		if (privateParams->shouldShowValueTip())
			tooltip += "Current Value: " + convertIntToValueString(paramType, currentValue, true) + "\n";
		if (privateParams->shouldShowInfoTip())
		{
			tooltip += getInfoString(paramIndex);
		}
		return tooltip;
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget)
};

