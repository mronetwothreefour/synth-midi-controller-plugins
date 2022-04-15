#pragma once

#include "randomization_AllowedNotesAndBentNotesComponent.h"
#include "randomization_AllowedOctavesComponentForSeqTrack.h"
#include "randomization_SeqTrackEditModeComponent.h"
#include "randomization_ProbablitiesForSeqTrackComponent.h"
#include "randomization_ValueRangeComponentForSeqTrack.h"



class UnexposedParameters;

class SeqTrackRandomizationOptionsComponent :
	public Component
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	SeqTrackEditModeComponent editMode;
	ProbabilitiesForSeqTrackComponent probabilites;
	ValueRangeComponentForSeqTrack allowedValues;
	AllowedNotesAndBentNotesComponent allowedNotes;
	AllowedOctavesComponentForSeqTrack allowedOctaves;
	TextButton button_ForClosingSeqTrackOptionsComponent;

public:
	SeqTrackRandomizationOptionsComponent() = delete;

	SeqTrackRandomizationOptionsComponent(int trackNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackRandomizationOptionsComponent)
};
