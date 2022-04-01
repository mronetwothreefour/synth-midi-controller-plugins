#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForShowingLFOrandomizationOptions :
	public BaseButtonWithOnClickAndTooltipMethods
{
	int lfoNum;
	UnexposedParameters* unexposedParams;

public:

	ButtonForShowingLFOrandomizationOptions() = delete;

	ButtonForShowingLFOrandomizationOptions(int lfoNum, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForShowingLFOrandomizationOptions)
};
