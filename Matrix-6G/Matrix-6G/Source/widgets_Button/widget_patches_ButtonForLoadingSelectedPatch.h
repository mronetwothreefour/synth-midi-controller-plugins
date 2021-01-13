#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class PatchSlotsWidget;
class UnexposedParameters;

class ButtonForLoadingSelectedPatch :
	public BaseButtonWithOnClickAndTooltipMethods
{
	PatchSlotsWidget& patchSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForLoadingSelectedPatch() = delete;

	ButtonForLoadingSelectedPatch(PatchSlotsWidget& patchSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedPatch)
};
