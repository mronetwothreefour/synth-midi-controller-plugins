#pragma once

#include "randomization_AllowedNotesAndBentNotesComponent.h"
#include "randomization_AllowedOctavesComponentForSeqTrack.h"
#include "randomization_SeqTrackEditModeComponent.h"
#include "randomization_ProbabilitiesComponentForSeqTrack.h"
#include "randomization_ValueRangeComponentForSeqTrack.h"



class UnexposedParameters;

class RandomizationOptionsComponent_SeqTrack :
	public Component
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	SeqTrackEditModeComponent editMode;
	ProbabilitiesComponentForSeqTrack probabilites;
	ValueRangeComponentForSeqTrack valueRange;
	AllowedNotesAndBentNotesComponent allowedNotes;
	AllowedOctavesComponentForSeqTrack allowedOctaves;
	TextButton button_ForClosingSeqTrackOptionsComponent;

public:
	RandomizationOptionsComponent_SeqTrack() = delete;

	RandomizationOptionsComponent_SeqTrack(int trackNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_SeqTrack)
};
