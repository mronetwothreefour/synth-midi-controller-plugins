#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramDataSlotsComponent;
class UnexposedParameters;

class ButtonForPullingSelectedProgramFromHardware :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	ProgramDataSlotsComponent& slotsComponent;
	UnexposedParameters* unexposedParams;
	Label& nameEditor;

public:

	ButtonForPullingSelectedProgramFromHardware() = delete;

	ButtonForPullingSelectedProgramFromHardware(ProgramDataSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedProgramFromHardware)
};
