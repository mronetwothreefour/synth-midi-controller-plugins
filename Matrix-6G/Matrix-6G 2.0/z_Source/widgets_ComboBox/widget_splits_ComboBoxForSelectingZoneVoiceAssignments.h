#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingZoneVoiceAssignments :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForSelectingZoneVoiceAssignments() = delete;

	explicit ComboBoxForSelectingZoneVoiceAssignments(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingZoneVoiceAssignments() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingZoneVoiceAssignments)
};

