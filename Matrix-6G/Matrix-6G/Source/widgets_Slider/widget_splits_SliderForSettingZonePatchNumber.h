#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class SliderForSettingZonePatchNumber :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	SliderForSettingZonePatchNumber() = delete;

	SliderForSettingZonePatchNumber(UnexposedParameters* unexposedParams, Identifier parameterID);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingZonePatchNumber() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingZonePatchNumber)
};

