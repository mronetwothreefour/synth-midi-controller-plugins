#pragma once

#include <JuceHeader.h>

#include "widget_BaseSliderForSettingControllerNumber.h"



class UnexposedParameters;

class SliderForSettingPedalController :
	public BaseSliderForSettingControllerNumber
{
	UnexposedParameters* unexposedParams;
	int pedalNumber;

public:
	SliderForSettingPedalController() = delete;

	SliderForSettingPedalController(UnexposedParameters* unexposedParams, int pedalNumber);
	String generateTooltipString() override;
	~SliderForSettingPedalController() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingPedalController)
};
