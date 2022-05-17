#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForVoiceChange :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForVoiceChange() = delete;

	explicit ComboBoxForVoiceChange(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForVoiceChange();

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForVoiceChange)
};

