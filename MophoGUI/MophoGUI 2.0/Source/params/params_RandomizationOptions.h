#pragma once

#include <JuceHeader.h>



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

	const bool editModeForSeqTrackIsIndividualStep(int trackNum);
	void setEditModeForSeqTrackToAllSteps(int trackNum);
	void setEditModeForSeqTrackToIndividualStep(int trackNum);
	const int stepTargetedForEditingInSeqTrack(int trackNum);
	void setStepTargetedForEditingInSeqTrack(int stepNum, int trackNum);
	const uint8 minValueForStepInSeqTrack(int stepNum, int trackNum);
	void setMinValueForStepInSeqTrack(uint8 newMin, int stepNum, int trackNum);
	const uint8 maxValueForStepInSeqTrack(int stepNum, int trackNum);
	void setMaxValueForStepInSeqTrack(uint8 newMax, int stepNum, int trackNum);
	const float probabilityOfRestForStepInSeqTrack1(int stepNum);
	void setProbabilityOfRestForStepInSeqTrack1(float newProb, int stepNum);
	const float probabilityOfRepeatValueForStepInSeqTrack(int stepNum, int trackNum);
	void setProbabilityOfRepeatValueForStepInSeqTrack(float newProb, int stepNum, int trackNum);
	const float probabilityOfResetForStepInSeqTrack(int stepNum, int trackNum);
	void setProbabilityOfResetForStepInSeqTrack(float newProb, int stepNum, int trackNum);
	const bool pitchIsAllowedForStepInSeqTrack(int pitchNum, int stepNum, int trackNum);
	const bool noteIsAllowedForStepInSeqTrack(int noteNum, int stepNum, int trackNum);
	void setNoteIsAllowedForStepInSeqTrack(int noteNum, int stepNum, int trackNum);
	void setNoteIsNotAllowedForStepInSeqTrack(int noteNum, int stepNum, int trackNum);
	const bool noNoteIsAllowedForStepInSeqTrack(int stepNum, int trackNum);
	const bool octaveIsAllowedForStepInSeqTrack(int octaveNum, int stepNum, int trackNum);
	void setOctaveIsAllowedForStepInSeqTrack(int octaveNum, int stepNum, int trackNum);
	void setOctaveIsNotAllowedForStepInSeqTrack(int octaveNum, int stepNum, int trackNum);
	const bool noOctaveIsAllowedForStepInSeqTrack(int stepNum, int trackNum);
	const bool onlyOctave5_IsAllowedForStepInSeqTrack(int stepNum, int trackNum);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
