#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class SliderForSettingBasicChannel :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	SliderForSettingBasicChannel() = delete;

	explicit SliderForSettingBasicChannel(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingBasicChannel() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingBasicChannel)
};

