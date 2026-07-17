#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForPushingVoiceToHardwareStorageSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	ButtonForPushingVoiceToHardwareStorageSlot() = delete;

	ButtonForPushingVoiceToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);


protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingVoiceToHardwareStorageSlot)
};

