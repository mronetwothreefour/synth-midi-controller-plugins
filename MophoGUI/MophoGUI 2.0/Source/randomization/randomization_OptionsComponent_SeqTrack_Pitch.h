#pragma once

#include "randomization_AllowedNotesAndBentNotesComponent.h"
#include "randomization_AllowedOctavesComponentForSeqTrack.h"
#include "randomization_SeqTrackEditModeComponent.h"
#include "randomization_ProbabilitiesComponentForSeqTrack.h"


class RepeatValuesToggleComponent;
class RepeatValuesToggleComponentForAllStepsInSeqTrack;
class UnexposedParameters;

class RandomizationOptionsComponent_SeqTrack_Pitch :
	public Component,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	SeqTrackEditModeComponent editMode;
	ProbabilitiesComponentForSeqTrack probabilites;
	AllowedNotesAndBentNotesComponent allowedNotes;
	AllowedOctavesComponentForSeqTrack allowedOctaves;
	std::unique_ptr<RepeatValuesToggleComponent> repeatValues;
	std::unique_ptr<RepeatValuesToggleComponentForAllStepsInSeqTrack> repeatValuesForAllSteps;
	TextButton button_ForClosingSeqTrackOptionsComponent;

public:
	RandomizationOptionsComponent_SeqTrack_Pitch() = delete;

	RandomizationOptionsComponent_SeqTrack_Pitch(int trackNum, UnexposedParameters* unexposedParams);
	void resetAndRepaintAppropriateRepeatValuesToggle();
	void paint(Graphics& g) override;
	void resized() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_SeqTrack_Pitch();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_SeqTrack_Pitch)
};
