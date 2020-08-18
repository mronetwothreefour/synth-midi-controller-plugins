#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramSlotsWidget;
class UnexposedParameters;

class ButtonForSavingProgramInSelectedSlot :
	public BaseButtonWithOnClickAndTooltipMethods
{
	ProgramSlotsWidget& programSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForSavingProgramInSelectedSlot() = delete;

	ButtonForSavingProgramInSelectedSlot(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	~ButtonForSavingProgramInSelectedSlot();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingProgramInSelectedSlot)
};
