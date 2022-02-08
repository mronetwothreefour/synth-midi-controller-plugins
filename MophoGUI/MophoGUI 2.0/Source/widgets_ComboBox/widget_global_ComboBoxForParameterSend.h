#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForParameterSend :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForParameterSend() = delete;

	explicit ComboBoxForParameterSend(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForParameterSend() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForParameterSend)
};

