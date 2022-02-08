#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForPushingMasterOptionsToHardware :
	public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:

	ButtonForPushingMasterOptionsToHardware() = delete;

	explicit ButtonForPushingMasterOptionsToHardware(UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingMasterOptionsToHardware)
};
