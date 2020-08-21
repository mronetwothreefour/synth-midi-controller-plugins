#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForPushingEntireBankToHardware : public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForPushingEntireBankToHardware() = delete;

	explicit ButtonForPushingEntireBankToHardware(UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	~ButtonForPushingEntireBankToHardware() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireBankToHardware)
};

