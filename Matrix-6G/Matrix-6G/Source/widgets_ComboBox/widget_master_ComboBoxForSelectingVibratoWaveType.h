#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingVibratoWaveType :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForSelectingVibratoWaveType() = delete;

	explicit ComboBoxForSelectingVibratoWaveType(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingVibratoWaveType() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingVibratoWaveType)
};

