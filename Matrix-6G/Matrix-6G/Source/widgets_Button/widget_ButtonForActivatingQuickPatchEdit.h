#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForActivatingQuickPatchEdit : 
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForActivatingQuickPatchEdit() = delete;

	ButtonForActivatingQuickPatchEdit(UnexposedParameters* unexposedParams);


protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForActivatingQuickPatchEdit)
};

