#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"



enum class RandomizationOptionsType {
	none = 0,
	valueRange,
	pitch,
	oscShape,
	comboBoxes,
	lpfFreq,
	lfoFreq,
	sequencerTrackStep
};



class RandomizationOptions
{
	ValueTree paramLocksTree;
	ValueTree allowedPitchesTree;
	ValueTree allowedValueRangesTree;
	ValueTree allowedOscShapesTree;
	ValueTree allowedComboBoxItemsTree;
	ValueTree allowedFrequencyTypesTree;
	ValueTree lpfFreqOptionsTree;
	ValueTree seqTrackOptionsTree;

public:
	RandomizationOptions();

private:
	void fillAllRandomizationOptionsTreesWithProperties();

public:
	const bool paramIsLocked(uint8 param);
	const bool paramIsUnlocked(uint8 param);
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

	const bool oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	void setOscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	void setOscShapeIsNotAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	const bool noOscShapeIsAllowedForParam(uint8 paramIndex);
	const uint8 minPulseWidthAllowedForParam(uint8 paramIndex);
	void setMinPulseWidthAllowedForParam(uint8 newMin, uint8 paramIndex);
	const uint8 maxPulseWidthAllowedForParam(uint8 paramIndex);
	void setMaxPulseWidthAllowedForParam(uint8 newMax, uint8 paramIndex);

	const bool comboBoxItemIsAllowedForParam(int itemNum, uint8 paramIndex);
	void setComboBoxItemIsAllowedForParam(int itemNum, uint8 paramIndex);
	void setComboBoxItemIsNotAllowedForParam(int itemNum, uint8 paramIndex);
	const bool noComboBoxItemIsAllowedForParam(uint8 paramIndex);

	const bool pitchedFreqAreAllowedForParam(uint8 paramIndex);
	const bool pitchedFreqAreNotAllowedForParam(uint8 paramIndex);
	void setPitchedFreqAreAllowedForParam(uint8 paramIndex);
	void setPitchedFreqAreNotAllowedForParam(uint8 paramIndex);
	const bool unsyncedFreqAreAllowedForParam(uint8 paramIndex);
	const bool unsyncedFreqAreNotAllowedForParam(uint8 paramIndex);
	void setUnsyncedFreqAreAllowedForParam(uint8 paramIndex);
	void setUnsyncedFreqAreNotAllowedForParam(uint8 paramIndex);
	const uint8 minUnsyncedFreqForParam(uint8 paramIndex);
	void setMinUnsyncedFreqForParam(uint8 newMin, uint8 paramIndex);
	const uint8 maxUnsyncedFreqForParam(uint8 paramIndex);
	void setMaxUnsyncedFreqForParam(uint8 newMax, uint8 paramIndex);
	const bool syncedFreqAreAllowedForParam(uint8 paramIndex);
	const bool syncedFreqAreNotAllowedForParam(uint8 paramIndex);
	void setSyncedFreqAreAllowedForParam(uint8 paramIndex);
	void setSyncedFreqAreNotAllowedForParam(uint8 paramIndex);
	const bool syncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex);
	void setSyncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex);
	void setSyncedFreqIsNotAllowedForParam(int syncedFreqNum, uint8 paramIndex);
	const bool noSyncedFreqAreAllowedForParam(uint8 paramIndex);
	const bool noFreqAreAllowedForParam(uint8 paramIndex);

	void addListenerToLPFfreqOptionsTree(ValueTree::Listener* listener);
	void removeListenerFromLPFfreqOptionsTree(ValueTree::Listener* listener);
	const bool randomizationModeForLPFfreqIsPitches();
	const bool randomizationModeForLPFfreqIsValueRange();
	void setRandomizationModeForLPFfreqToPitches();
	void setRandomizationModeForLPFfreqToValueRange();

	void addListenerToSeqTrackOptionsTree(ValueTree::Listener* listener);
	void removeListenerFromSeqTrackOptionsTree(ValueTree::Listener* listener);
	const bool editModeForSeqTrackIsAllSteps(int trackNum);
	const bool editModeForSeqTrackIsSelectedStep(int trackNum);
	void setEditModeForSeqTrackToAllSteps(int trackNum);
	void setEditModeForSeqTrackToSelectedStep(int trackNum);
	const int stepSelectedForEditingInSeqTrack(int trackNum);
	void setStepSelectedForEditingInSeqTrack(int stepNum, int trackNum);
	const float probabilityOfRestForAllStepsInSeqTrack1();
	void setProbabilityOfRestForAllStepsInSeqTrack1(float newProb);
	const float probabilityOfRestForParam(uint8 paramIndex);
	void setProbabilityOfRestForParam(float newProb, uint8 paramIndex);
	const float probabilityOfRepeatValueForAllStepsInSeqTrack(int trackNum);
	void setProbabilityOfRepeatForAllStepsInSeqTrack(float newProb, int trackNum);
	const float probabilityOfRepeatValueForParam(uint8 paramIndex);
	void setProbabilityOfRepeatValueForParam(float newProb, uint8 paramIndex);
	const float probabilityOfResetForAllStepsInSeqTrack(int trackNum);
	void setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum);
	const float probabilityOfResetForParam(uint8 paramIndex);
	void setProbabilityOfResetForParam(float newProb, uint8 paramIndex);
	const uint8 minValueForAllStepsInSeqTrack(int trackNum);
	void setMinValueForAllStepsInSeqTrack(uint8 newMin, int trackNum);
	const uint8 maxValueForAllStepsInSeqTrack(int trackNum);
	void setMaxValueForAllStepsInSeqTrack(uint8 newMax, int trackNum);
	const bool pitchIsAllowedForAllStepsInSeqTrack(int pitchNum, int trackNum);
	const bool noteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum);
	void setNoteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum);
	void setNoteIsNotAllowedForAllStepsInSeqTrack(int noteNum, int trackNum);
	const bool noNoteIsAllowedForAllStepsInSeqTrack(int trackNum);
	const bool octaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum);
	void setOctaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum);
	void setOctaveIsNotAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum);
	const bool noOctaveIsAllowedForAllStepsInSeqTrack(int trackNum);
	const bool onlyHighestOctaveIsAllowedForAllStepsInSeqTrack(int trackNum);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
