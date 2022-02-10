#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ButtonForPullingSelectedPatchFromHardware :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	VoiceSlotsComponent& patchSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForPullingSelectedPatchFromHardware() = delete;

	ButtonForPullingSelectedPatchFromHardware(VoiceSlotsComponent& patchSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedPatchFromHardware)
};
