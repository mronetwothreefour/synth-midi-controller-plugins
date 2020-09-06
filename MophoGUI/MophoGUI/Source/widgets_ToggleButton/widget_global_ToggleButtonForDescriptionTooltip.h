#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ToggleButtonForDescriptionTooltip :
	public ToggleButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ToggleButtonForDescriptionTooltip() = delete;

	explicit ToggleButtonForDescriptionTooltip(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleButtonForDescriptionTooltip() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonForDescriptionTooltip)
};

