#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class SliderForVoiceNumber :
	public RotarySliderWithMouseWheelModForVoiceNumber,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	SliderForVoiceNumber() = delete;

	explicit SliderForVoiceNumber(UnexposedParameters* unexposedParams);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~SliderForVoiceNumber() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForVoiceNumber)
};

