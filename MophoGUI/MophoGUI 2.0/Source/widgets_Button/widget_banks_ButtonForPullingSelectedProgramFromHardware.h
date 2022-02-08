#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramSlotsWidget;
class UnexposedParameters;

class ButtonForPullingSelectedProgramFromHardware :
	public BaseButtonWithOnClickAndTooltipMethods
{
	ProgramSlotsWidget& programSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForPullingSelectedProgramFromHardware() = delete;

	ButtonForPullingSelectedProgramFromHardware(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedProgramFromHardware)
};
