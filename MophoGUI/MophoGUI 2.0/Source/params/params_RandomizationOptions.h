#pragma once

#include <JuceHeader.h>



enum class RandomizationOptionsType {
	none = 0,
	valueRange,
	pitch,
	modulationSource,
	modulationDestination,
	oscShape,
	lpfFreq,
	lfoFreq,
	sequencerTrackStep,
	togglesForEachMenuItem
};



class RandomizationOptions
{
	ValueTree paramLocksTree;
	ValueTree allowedPitchesTree;
	ValueTree allowedValueRangesTree;
	ValueTree allowedFrequencyTypesTree;
	ValueTree seqTrackAllowedStepValuesTree;

public:
	RandomizationOptions();

private:
	void fillAllRandomizationOptionsTreesWithProperties();

public:
	const bool paramIsLocked(uint8 param);
	void setParamIsLocked(uint8 param);
	void setParamIsUnlocked(uint8 param);

	const bool noteIsAllowedForParam(int noteNum, uint8 paramIndex);
	void setNoteIsAllowedForParam(int noteNum, uint8 paramIndex);
	void setNoteIsNotAllowedForParam(int noteNum, uint8 paramIndex);
	const bool noNoteIsAllowedForParam(uint8 paramIndex);
	const bool octaveIsAllowedForParam(int octaveNum, uint8 paramIndex);
	void setOctaveIsAllowedForParam(int octaveNum, uint8 paramIndex);
	void setOctaveIsNotAllowedForParam(int octaveNum, uint8 paramIndex);
	const bool noOctaveIsAllowedForParam(uint8 paramIndex);
	const bool onlyHighestOctaveIsAllowedForParam(uint8 paramIndex);
	const bool pitchIsAllowedForParam(int pitchNum, uint8 paramIndex);

	const uint8 minValueAllowedForParam(uint8 paramIndex);
	void setMinValueAllowedForParam(uint8 newMin, uint8 paramIndex);
	const uint8 maxValueAllowedForParam(uint8 paramIndex);
	void setMaxValueAllowedForParam(uint8 newMax, uint8 paramIndex);

	const bool pitchedFreqAreAllowedForParam(uint8 paramIndex);
	void setPitchedFreqAreAllowedForParam(uint8 paramIndex);
	void setPitchedFreqAreNotAllowedForParam(uint8 paramIndex);
	const bool unsyncedFreqAreAllowedForParam(uint8 paramIndex);
	void setUnsyncedFreqAreAllowedForParam(uint8 paramIndex);
	void setUnsyncedFreqAreNotAllowedForParam(uint8 paramIndex);
	const uint8 minUnsyncedFreqForParam(uint8 paramIndex);
	void setMinUnsyncedFreqForParam(uint8 newMin, uint8 paramIndex);
	const uint8 maxUnsyncedFreqForParam(uint8 paramIndex);
	void setMaxUnsyncedFreqForParam(uint8 newMax, uint8 paramIndex);
	const bool syncedFreqAreAllowedForParam(uint8 paramIndex);
	void setSyncedFreqAreAllowedForParam(uint8 paramIndex);
	void setSyncedFreqAreNotAllowedForParam(uint8 paramIndex);
	const bool syncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex);
	void setSyncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex);
	void setSyncedFreqIsNotAllowedForParam(int syncedFreqNum, uint8 paramIndex);
	const bool noSyncedFreqAreAllowedForParam(uint8 paramIndex);
	const bool noFreqAreAllowedForParam(uint8 paramIndex);

	//-----to do: remove these functions
	void addListenerToSeqTrackAllowedStepValuesTree(ValueTree::Listener* listener);
	void removeListenerFromSeqTrackAllowedStepValuesTree(ValueTree::Listener* listener);
	const bool editModeForSeqTrackIsAllSteps(int trackNum);
	const bool editModeForSeqTrackIsSelectedStep(int trackNum);
	void setEditModeForSeqTrackToAllSteps(int trackNum);
	void setEditModeForSeqTrackToSelectedStep(int trackNum);
	const int stepSelectedForEditingInSeqTrack(int trackNum);
	void setStepSelectedForEditingInSeqTrack(int stepNum, int trackNum);
	const float probabilityOfRestForAllStepsInSeqTrack1();
	void setProbabilityOfRestForAllStepsInSeqTrack1(float newProb);
	const float probabilityOfRestForSelectedStepInSeqTrack1(int stepNum);
	void setProbabilityOfRestForSelectedStepInSeqTrack1(float newProb, int stepNum);
	const float probabilityOfRepeatValueForAllStepsInSeqTrack(int trackNum);
	void setProbabilityOfRepeatForAllStepsInSeqTrack(float newProb, int trackNum);
	const float probabilityOfRepeatValueForSelectedStepInSeqTrack(int stepNum, int trackNum);
	void setProbabilityOfRepeatValueForSelectedStepInSeqTrack(float newProb, int stepNum, int trackNum);
	const float probabilityOfResetForAllStepsInSeqTrack(int trackNum);
	void setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum);
	const float probabilityOfResetForSelectedStepInSeqTrack(int stepNum, int trackNum);
	void setProbabilityOfResetForSelectedStepInSeqTrack(float newProb, int stepNum, int trackNum);
	const uint8 minValueForAllStepsInSeqTrack(int trackNum);
	void setMinValueForAllStepsInSeqTrack(uint8 newMin, int trackNum);
	const uint8 minValueForSelectedStepInSeqTrack(int stepNum, int trackNum);
	void setMinValueForSelectedStepInSeqTrack(uint8 newMin, int stepNum, int trackNum);
	const uint8 maxValueForAllStepsInSeqTrack(int trackNum);
	void setMaxValueForAllStepsInSeqTrack(uint8 newMax, int trackNum);
	const uint8 maxValueForSelectedStepInSeqTrack(int stepNum, int trackNum);
	void setMaxValueForSelectedStepInSeqTrack(uint8 newMax, int stepNum, int trackNum);
	const bool pitchIsAllowedForAllStepsInSeqTrack(int pitchNum, int trackNum);
	const bool pitchIsAllowedForSelectedStepInSeqTrack(int pitchNum, int stepNum, int trackNum);
	const bool noteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum);
	void setNoteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum);
	void setNoteIsNotAllowedForAllStepsInSeqTrack(int noteNum, int trackNum);
	const bool noNoteIsAllowedForAllStepsInSeqTrack(int trackNum);
	const bool noteIsAllowedForSelectedStepInSeqTrack(int noteNum, int stepNum, int trackNum);
	void setNoteIsAllowedForSelectedStepInSeqTrack(int noteNum, int stepNum, int trackNum);
	void setNoteIsNotAllowedForSelectedStepInSeqTrack(int noteNum, int stepNum, int trackNum);
	const bool noNoteIsAllowedForSelectedStepInSeqTrack(int stepNum, int trackNum);
	const bool octaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum);
	void setOctaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum);
	void setOctaveIsNotAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum);
	const bool noOctaveIsAllowedForAllStepsInSeqTrack(int trackNum);
	const bool onlyOctave5_IsAllowedForAllStepsInSeqTrack(int trackNum);
	const bool octaveIsAllowedForSelectedStepInSeqTrack(int octaveNum, int stepNum, int trackNum);
	void setOctaveIsAllowedForSelectedStepInSeqTrack(int octaveNum, int stepNum, int trackNum);
	void setOctaveIsNotAllowedForSelectedStepInSeqTrack(int octaveNum, int stepNum, int trackNum);
	const bool noOctaveIsAllowedForSelectedStepInSeqTrack(int stepNum, int trackNum);
	const bool onlyOctave5_IsAllowedForSelectedStepInSeqTrack(int stepNum, int trackNum);
	//-----end to do: remove these functions

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
