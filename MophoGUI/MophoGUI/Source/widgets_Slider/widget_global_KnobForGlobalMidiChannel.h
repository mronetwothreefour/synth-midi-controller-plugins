#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class KnobForGlobalMidiChannel :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	KnobForGlobalMidiChannel() = delete;

	explicit KnobForGlobalMidiChannel(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~KnobForGlobalMidiChannel();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForGlobalMidiChannel)
};

