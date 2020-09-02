#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ToggleButtonForMidiControllers :
	public ToggleButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ToggleButtonForMidiControllers() = delete;

	explicit ToggleButtonForMidiControllers(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleButtonForMidiControllers() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonForMidiControllers)
};

