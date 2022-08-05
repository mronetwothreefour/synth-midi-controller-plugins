#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ButtonForSavingVoiceIntoSelectedSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	VoiceSlotsComponent& voiceSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForSavingVoiceIntoSelectedSlot() = delete;

	ButtonForSavingVoiceIntoSelectedSlot(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
