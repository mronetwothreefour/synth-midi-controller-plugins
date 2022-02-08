#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForPedalMode :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForPedalMode() = delete;

	explicit ComboBoxForPedalMode(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForPedalMode() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForPedalMode)
};

