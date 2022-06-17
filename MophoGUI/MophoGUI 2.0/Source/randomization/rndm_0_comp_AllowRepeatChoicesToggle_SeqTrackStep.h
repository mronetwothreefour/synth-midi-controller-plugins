#pragma once

#include <JuceHeader.h>



class RandomizationOptions;
class UnexposedParameters;

class AllowRepeatChoicesToggle_SeqTrackStep :
	public Component,
	public ValueTree::Listener
{
	int trackNum;
	int stepNum;
	RandomizationOptions* randomizationOptions;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle_SeqTrackStep() = delete;

	AllowRepeatChoicesToggle_SeqTrackStep(int trackNum, int stepNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~AllowRepeatChoicesToggle_SeqTrackStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle_SeqTrackStep)
};