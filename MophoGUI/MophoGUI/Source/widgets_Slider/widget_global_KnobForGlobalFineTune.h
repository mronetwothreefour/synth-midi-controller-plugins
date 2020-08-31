#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class KnobForGlobalFineTune :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	KnobForGlobalFineTune() = delete;

	explicit KnobForGlobalFineTune(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~KnobForGlobalFineTune();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForGlobalFineTune)
};

