#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForProgramChange :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForProgramChange() = delete;

	explicit ComboBoxForProgramChange(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForProgramChange();

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForProgramChange)
};

