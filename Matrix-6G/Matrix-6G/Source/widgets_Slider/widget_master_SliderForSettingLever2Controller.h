#pragma once

#include <JuceHeader.h>

#include "widget_BaseSliderForSettingControllerNumber.h"



class UnexposedParameters;

class SliderForSettingLever2Controller :
	public BaseSliderForSettingControllerNumber
{
	UnexposedParameters* unexposedParams;

public:
	SliderForSettingLever2Controller() = delete;

	SliderForSettingLever2Controller(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~SliderForSettingLever2Controller() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingLever2Controller)
};
