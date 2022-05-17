#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RepeatValuesToggleComponentForAllStepsInSeqTrack :
	public Component,
	public Button::Listener,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	ToggleButton toggle_AllowRepeatValues;

public:
	RepeatValuesToggleComponentForAllStepsInSeqTrack() = delete;

	RepeatValuesToggleComponentForAllStepsInSeqTrack(int trackNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~RepeatValuesToggleComponentForAllStepsInSeqTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RepeatValuesToggleComponentForAllStepsInSeqTrack)
};