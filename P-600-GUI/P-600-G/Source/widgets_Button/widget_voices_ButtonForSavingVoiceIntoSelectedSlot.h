#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ButtonForSavingVoiceIntoSelectedSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	VoiceSlotsComponent& slotsComponent;
	UnexposedParameters* unexposedParams;
	Label& nameEditor;

public:

	ButtonForSavingVoiceIntoSelectedSlot() = delete;

	ButtonForSavingVoiceIntoSelectedSlot(VoiceSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
