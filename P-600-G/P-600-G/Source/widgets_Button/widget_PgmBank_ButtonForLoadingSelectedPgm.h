#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramDataSlotsComponent;
class UnexposedParameters;

class ButtonForLoadingSelectedProgram :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	ProgramDataSlotsComponent& slotsComponent;
	UnexposedParameters* unexposedParams;

public:

	ButtonForLoadingSelectedProgram() = delete;

	ButtonForLoadingSelectedProgram(ProgramDataSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedProgram)
};
