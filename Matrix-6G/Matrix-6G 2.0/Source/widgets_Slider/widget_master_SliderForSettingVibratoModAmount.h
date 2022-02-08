#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class SliderForSettingVibratoModAmount :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	const Identifier& propertyID;

public:
	SliderForSettingVibratoModAmount() = delete;

	SliderForSettingVibratoModAmount(UnexposedParameters* unexposedParams, const Identifier& propertyID);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForSettingVibratoModAmount() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingVibratoModAmount)
};

