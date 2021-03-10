#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingZoneMIDIout :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForSelectingZoneMIDIout() = delete;

	ComboBoxForSelectingZoneMIDIout(UnexposedParameters* unexposedParams, Identifier parameterID);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingZoneMIDIout() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingZoneMIDIout)
};

