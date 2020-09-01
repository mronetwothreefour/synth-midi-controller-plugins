#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForParameterReceive :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForParameterReceive() = delete;

	explicit ComboBoxForParameterReceive(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForParameterReceive();

private:

};

