#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class SliderForSettingOutProgramNumber :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	uint8 programNumber;
	Identifier sliderID;

public:
	SliderForSettingOutProgramNumber() = delete;

	SliderForSettingOutProgramNumber(UnexposedParameters* unexposedParams, uint8 programNumber);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingOutProgramNumber() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingOutProgramNumber)
};
