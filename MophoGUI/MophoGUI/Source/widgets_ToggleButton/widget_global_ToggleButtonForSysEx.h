#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ToggleButtonForSysEx :
	public ToggleButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ToggleButtonForSysEx() = delete;

	explicit ToggleButtonForSysEx(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleButtonForSysEx() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonForSysEx)
};

