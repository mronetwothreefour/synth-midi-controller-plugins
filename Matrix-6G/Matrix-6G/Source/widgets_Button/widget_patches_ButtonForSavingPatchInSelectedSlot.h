#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class PatchSlotsComponent;
class UnexposedParameters;

class ButtonForSavingPatchInSelectedSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	PatchSlotsComponent& patchSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForSavingPatchInSelectedSlot() = delete;

	ButtonForSavingPatchInSelectedSlot(PatchSlotsComponent& patchSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingPatchInSelectedSlot)
};
