#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class DisplayLabelForAudioOutput :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	DisplayLabelForAudioOutput() = delete;

	explicit DisplayLabelForAudioOutput(UnexposedParameters* unexposedParams);
	void setTextAccordingToParameterSetting();
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~DisplayLabelForAudioOutput();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForAudioOutput)
};

