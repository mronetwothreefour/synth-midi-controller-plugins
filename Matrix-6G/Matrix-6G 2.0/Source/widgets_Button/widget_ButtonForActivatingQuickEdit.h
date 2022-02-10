#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForActivatingQuickEdit : 
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForActivatingQuickEdit() = delete;

	explicit ButtonForActivatingQuickEdit(UnexposedParameters* unexposedParams);


protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForActivatingQuickEdit)
};

