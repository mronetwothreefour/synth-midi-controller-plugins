#pragma once

#include "randomization_AllowedNotesForSeqTrackComponent.h"
#include "randomization_AllowedOctavesForSeqTrackComponent.h"
#include "randomization_AllowedStepValuesForSeqTrackComponent.h"
#include "randomization_EditModeForSeqTrackComponent.h"
#include "randomization_ProbablitiesForSeqTrackComponent.h"



class UnexposedParameters;

class SeqTrackRandomizationOptionsComponent :
	public Component
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	EditModeForSeqTrackComponent editMode;
	ProbabilitiesForSeqTrackComponent probabilites;
	AllowedStepValuesForSeqTrackComponent allowedValues;
	AllowedNotesForSeqTrackComponent allowedNotes;
	AllowedOctavesForSeqTrackComponent allowedOctaves;
	TextButton button_ForClosingSeqTrackOptionsComponent;

public:
	SeqTrackRandomizationOptionsComponent() = delete;

	SeqTrackRandomizationOptionsComponent(int trackNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	const char* getTitleImageData();
	size_t getTitleImageDataSize();
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackRandomizationOptionsComponent)
};
