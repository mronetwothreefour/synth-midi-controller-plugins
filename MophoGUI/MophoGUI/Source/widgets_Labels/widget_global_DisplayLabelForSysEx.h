#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class DisplayLabelForSysEx :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	DisplayLabelForSysEx() = delete;

	explicit DisplayLabelForSysEx(UnexposedParameters* unexposedParams);
	void setTextAccordingToParameterSetting();
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~DisplayLabelForSysEx();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForSysEx)
};

