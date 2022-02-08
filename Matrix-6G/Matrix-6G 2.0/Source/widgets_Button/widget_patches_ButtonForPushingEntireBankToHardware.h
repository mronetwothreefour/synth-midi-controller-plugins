#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"
#include "../patches/patches_PatchBanks.h"



class UnexposedParameters;

class ButtonForPushingEntireBankToHardware : public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForPushingEntireBankToHardware() = delete;

	ButtonForPushingEntireBankToHardware(PatchBank bank, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireBankToHardware)
};

