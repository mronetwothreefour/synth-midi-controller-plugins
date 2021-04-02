#pragma once

#include <JuceHeader.h>

#include "widget_BaseSliderForSettingControllerNumber.h"



class UnexposedParameters;

class SliderForSettingLever3Controller :
	public BaseSliderForSettingControllerNumber
{
	UnexposedParameters* unexposedParams;

public:
	SliderForSettingLever3Controller() = delete;

	SliderForSettingLever3Controller(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~SliderForSettingLever3Controller() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingLever3Controller)
};
