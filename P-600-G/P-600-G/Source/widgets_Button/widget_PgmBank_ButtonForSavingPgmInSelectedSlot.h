#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramDataSlotsComponent;
class UnexposedParameters;

class ButtonForSavingProgramInSelectedSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	ProgramDataSlotsComponent& slotsComponent;
	UnexposedParameters* unexposedParams;
	Label& nameEditor;

public:

	ButtonForSavingProgramInSelectedSlot() = delete;

	ButtonForSavingProgramInSelectedSlot(ProgramDataSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingProgramInSelectedSlot)
};