#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ToggleButtonForStereoOutput :
	public ToggleButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ToggleButtonForStereoOutput() = delete;

	ToggleButtonForStereoOutput(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleButtonForStereoOutput();

private:

};

