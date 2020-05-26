#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/InfoStrings.h"
#include "../parameters/PrivateParameters.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;

//==============================================================================
// Base class for button widgets which use a toggle button and attach to a public parameter.
class ButtonWidget : 
	public Component, 
	public Button::Listener,
	public ValueTree::Listener,
	public MophoParameterTooltipGenerator
{
public:
	PrivateParameters* privateParams;

	ButtonWidget
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		int index,
		int type
	) :
		button{ paramID.toString() },
		buttonAttachment{ *publicParameters, paramID.toString(), button },
		privateParams{ privateParameters },
		paramIndex{ index },
		paramType{ type }
	{
		privateParams->addListenerToGlobalOptions(this);

		button.setComponentID(ID::paramToggle.toString());
		button.addListener(this);
		addAndMakeVisible(button);
		buttonStateChanged(&button);

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
			button.setTooltip(createTooltipString(paramIndex, paramType, getButtonState(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
			button.setTooltip(createTooltipString(paramIndex, paramType, getButtonState(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

private:
	String name;

	int paramIndex;
	int paramType;

	ToggleButton button;
	ButtonAttachment buttonAttachment;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonWidget)
};

