#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramSlotsWidget;
class UnexposedParameters;

class ButtonForLoadingSelectedProgram :
	public BaseButtonWithOnClickAndTooltipMethods
{
	ProgramSlotsWidget& programSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForLoadingSelectedProgram() = delete;

	ButtonForLoadingSelectedProgram(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedProgram)
};
