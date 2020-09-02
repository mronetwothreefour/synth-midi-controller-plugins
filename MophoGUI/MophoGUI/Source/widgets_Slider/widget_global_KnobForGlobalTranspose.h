#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class KnobForGlobalTranspose :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	KnobForGlobalTranspose() = delete;

	explicit KnobForGlobalTranspose(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~KnobForGlobalTranspose() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForGlobalTranspose)
};

