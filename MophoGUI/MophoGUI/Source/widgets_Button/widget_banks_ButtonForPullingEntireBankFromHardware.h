#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"
#include "../banks/banks_ProgramBanks.h"



class UnexposedParameters;

class ButtonForPullingEntireBankFromHardware : public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForPullingEntireBankFromHardware() = delete;

	ButtonForPullingEntireBankFromHardware(ProgramBank bank, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingEntireBankFromHardware)
};

