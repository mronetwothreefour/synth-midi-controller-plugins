#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class RandomizationOptions;
class UnexposedParameters;

class AllowRepeatChoicesToggle_SeqTrackStep :
	public Component,
	public ValueTree::Listener
{
	Track track;
	Step step;
	RandomizationOptions* randomization;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle_SeqTrackStep() = delete;

	AllowRepeatChoicesToggle_SeqTrackStep(Track track, Step step, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~AllowRepeatChoicesToggle_SeqTrackStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle_SeqTrackStep)
};