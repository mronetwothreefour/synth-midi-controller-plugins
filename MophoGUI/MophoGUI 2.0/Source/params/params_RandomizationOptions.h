#pragma once

#include <JuceHeader.h>



enum class RandomizationOptionsType {
	none = 0,
	valueRange,
	notesAndOctaves,
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
	ValueTree oscAllowedPitchesTree;
	ValueTree lfoAllowedFrequenciesTree;
	ValueTree seqTrackAllowedStepValuesTree;

public:
	RandomizationOptions();

private:
	void fillAllRandomizationOptionsTreesWithProperties();

public:
	const bool paramIsLocked(uint8 param);
	void setParamIsLocked(uint8 param);
	void setParamIsUnlocked(uint8 param);

	const bool pitchIsAllowedForOscillator(int pitchNum, int oscNum);
	const bool noteIsAllowedForOscillator(int noteNum, int oscNum);
	void setNoteIsAllowedForOscillator(int noteNum, int oscNum);
	void setNoteIsNotAllowedForOscillator(int noteNum, int oscNum);
	const bool noNoteIsAllowedForOscillator(int oscNum);
	const bool octaveIsAllowedForOscillator(int octaveNum, int oscNum);
	void setOctaveIsAllowedForOscillator(int octaveNum, int oscNum);
	void setOctaveIsNotAllowedForOscillator(int octaveNum, int oscNum);
	const bool noOctaveIsAllowedForOscillator(int oscNum);
	const bool onlyOctave10_IsAllowedForOscillator(int oscNum);

	const bool unsyncedFreqAreAllowedForLFO(int lfoNum);
	void setUnsyncedFreqAreAllowedForLFO(int lfoNum);
	void setUnsyncedFreqAreNotAllowedForLFO(int lfoNum);
	const uint8 minUnsyncedFreqForLFO(int lfoNum);
	void setMinUnsyncedFreqForLFO(uint8 newMin, int lfoNum);
	const uint8 maxUnsyncedFreqForLFO(int lfoNum);
	void setMaxUnsyncedFreqForLFO(uint8 newMax, int lfoNum);
	const bool pitchedFreqAreAllowedForLFO(int lfoNum);
	void setPitchedFreqAreAllowedForLFO(int lfoNum);
	void setPitchedFreqAreNotAllowedForLFO(int lfoNum);
	const bool pitchIsAllowedForLFO(int pitchNum, int lfoNum);
	const bool noteIsAllowedForLFO(int noteNum, int lfoNum);
	void setNoteIsAllowedForLFO(int noteNum, int lfoNum);
	void setNoteIsNotAllowedForLFO(int noteNum, int lfoNum);
	const bool noNoteIsAllowedForLFO(int lfoNum);
	const bool octaveIsAllowedForLFO(int octaveNum, int lfoNum);
	void setOctaveIsAllowedForLFO(int octaveNum, int lfoNum);
	void setOctaveIsNotAllowedForLFO(int octaveNum, int lfoNum);
	const bool noOctaveIsAllowedForLFO(int lfoNum);
	const bool onlyOctave5_IsAllowedForLFO(int lfoNum);
	const bool syncedFreqAreAllowedForLFO(int lfoNum);
	void setSyncedFreqAreAllowedForLFO(int lfoNum);
	void setSyncedFreqAreNotAllowedForLFO(int lfoNum);
	const bool syncedFreqIsAllowedForLFO(int syncedFreqNum, int lfoNum);
	void setSyncedFreqIsAllowedForLFO(int syncedFreqNum, int lfoNum);
	void setSyncedFreqIsNotAllowedForLFO(int syncedFreqNum, int lfoNum);
	const bool noSyncedFreqAreAllowedForLFO(int lfoNum);
	const bool noFreqAreAllowedForLFO(int lfoNum);

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

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
