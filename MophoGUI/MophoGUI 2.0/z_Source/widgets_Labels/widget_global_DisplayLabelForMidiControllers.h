#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class DisplayLabelForMidiControllers :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	DisplayLabelForMidiControllers() = delete;

	explicit DisplayLabelForMidiControllers(UnexposedParameters* unexposedParams);
	void setTextAccordingToParameterSetting();
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~DisplayLabelForMidiControllers();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForMidiControllers)
};

