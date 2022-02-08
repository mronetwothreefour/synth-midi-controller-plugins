#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class SplitSlotsComponent;
class UnexposedParameters;

class ButtonForPullingSelectedSplitFromHardware :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	SplitSlotsComponent& splitSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForPullingSelectedSplitFromHardware() = delete;

	ButtonForPullingSelectedSplitFromHardware(SplitSlotsComponent& splitSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedSplitFromHardware)
};
