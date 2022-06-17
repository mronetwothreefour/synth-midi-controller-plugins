#pragma once

#include <JuceHeader.h>



class RandomizationOptions;
class UnexposedParameters;

class AllowRepeatChoicesToggle_AllSeqTrackSteps :
	public Component,
	public ValueTree::Listener
{
	int trackNum;
	RandomizationOptions* randomizationOptions;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle_AllSeqTrackSteps() = delete;

	AllowRepeatChoicesToggle_AllSeqTrackSteps(int trackNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~AllowRepeatChoicesToggle_AllSeqTrackSteps();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle_AllSeqTrackSteps)
};