#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramSlotsWidget;
class UnexposedParameters;

class ButtonForPushingSelectedProgramToHardware :
	public BaseButtonWithOnClickAndTooltipMethods
{
	ProgramSlotsWidget& programSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForPushingSelectedProgramToHardware() = delete;

	ButtonForPushingSelectedProgramToHardware(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	~ButtonForPushingSelectedProgramToHardware();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingSelectedProgramToHardware)
};
