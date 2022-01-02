#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForPullingProgramFromHardwareStorageSlot :
	public BaseButtonWithOnClickAndTooltipMethods,
	public Timer
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForPullingProgramFromHardwareStorageSlot() = delete;

	explicit ButtonForPullingProgramFromHardwareStorageSlot(UnexposedParameters* unexposedParams);


protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingProgramFromHardwareStorageSlot)
};

