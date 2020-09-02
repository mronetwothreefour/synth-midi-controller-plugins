#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class DisplayLabelForParameterReceive :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	DisplayLabelForParameterReceive() = delete;

	explicit DisplayLabelForParameterReceive(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~DisplayLabelForParameterReceive() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForParameterReceive)
};

