#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingMIDIechoEnabled :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingMIDIechoEnabled() = delete;

	ComboBoxForSelectingMIDIechoEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingMIDIechoEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingMIDIechoEnabled)
};

