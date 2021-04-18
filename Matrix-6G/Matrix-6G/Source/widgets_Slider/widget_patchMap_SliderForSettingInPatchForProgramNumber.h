#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class SliderForSettingInPatchForProgramNumber :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	uint8 programNumber;
	Identifier sliderID;

public:
	SliderForSettingInPatchForProgramNumber() = delete;

	SliderForSettingInPatchForProgramNumber(UnexposedParameters* unexposedParams, uint8 programNumber);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingInPatchForProgramNumber() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingInPatchForProgramNumber)
};
