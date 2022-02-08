#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForPushingEntireSplitBankToHardware : public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForPushingEntireSplitBankToHardware() = delete;

	explicit ButtonForPushingEntireSplitBankToHardware(UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireSplitBankToHardware)
};

