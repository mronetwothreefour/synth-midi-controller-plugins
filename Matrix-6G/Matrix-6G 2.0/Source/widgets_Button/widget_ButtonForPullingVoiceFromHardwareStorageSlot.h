#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForPullingVoiceFromHardwareStorageSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForPullingVoiceFromHardwareStorageSlot() = delete;

	explicit ButtonForPullingVoiceFromHardwareStorageSlot(UnexposedParameters* unexposedParams);


protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingVoiceFromHardwareStorageSlot)
};

