#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class SliderForSettingOutPatchForProgramNumber :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	uint8 programNumber;
	Identifier sliderID;

public:
	SliderForSettingOutPatchForProgramNumber() = delete;

	SliderForSettingOutPatchForProgramNumber(UnexposedParameters* unexposedParams, uint8 programNumber);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingOutPatchForProgramNumber() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingOutPatchForProgramNumber)
};
