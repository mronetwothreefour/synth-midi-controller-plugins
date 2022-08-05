#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;
class VoiceSlotsComponent;

class ButtonForLoadingSelectedVoice :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	VoiceSlotsComponent& voiceSlots;
	UnexposedParameters* unexposedParams;

public:

	ButtonForLoadingSelectedVoice() = delete;

	ButtonForLoadingSelectedVoice(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedVoice)
};
