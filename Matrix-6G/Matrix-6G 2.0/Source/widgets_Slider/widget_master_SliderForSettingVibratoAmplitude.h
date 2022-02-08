#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class SliderForSettingVibratoAmplitude :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	SliderForSettingVibratoAmplitude() = delete;

	explicit SliderForSettingVibratoAmplitude(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingVibratoAmplitude() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingVibratoAmplitude)
};

