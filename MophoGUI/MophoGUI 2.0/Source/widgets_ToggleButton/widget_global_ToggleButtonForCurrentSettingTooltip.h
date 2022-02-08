#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ToggleButtonForCurrentSettingTooltip :
	public ToggleButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ToggleButtonForCurrentSettingTooltip() = delete;

	explicit ToggleButtonForCurrentSettingTooltip(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleButtonForCurrentSettingTooltip() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonForCurrentSettingTooltip)
};

