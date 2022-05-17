#pragma once

#include "randomization_SeqTrackEditModeComponent.h"
#include "randomization_ProbabilitiesComponentForSeqTrack.h"
#include "randomization_ValueRangeComponentForSeqTrack.h"


class RepeatValuesToggleComponent;
class RepeatValuesToggleComponentForAllStepsInSeqTrack;
class UnexposedParameters;

class RandomizationOptionsComponent_SeqTrack_Value :
	public Component,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	SeqTrackEditModeComponent editMode;
	ProbabilitiesComponentForSeqTrack probabilites;
	ValueRangeComponentForSeqTrack valueRange;
	std::unique_ptr<RepeatValuesToggleComponent> repeatValues;
	std::unique_ptr<RepeatValuesToggleComponentForAllStepsInSeqTrack> repeatValuesForAllSteps;
	TextButton button_ForClosingSeqTrackOptionsComponent;
	int background_y;

public:
	RandomizationOptionsComponent_SeqTrack_Value() = delete;

	RandomizationOptionsComponent_SeqTrack_Value(int trackNum, UnexposedParameters* unexposedParams);
	void resetAndRepaintAppropriateRepeatValuesToggle();
	void paint(Graphics& g) override;
	void resized() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_SeqTrack_Value();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_SeqTrack_Value)
};
