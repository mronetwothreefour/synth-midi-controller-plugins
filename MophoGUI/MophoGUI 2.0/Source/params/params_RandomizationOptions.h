#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"



enum class RandomizationOptionsType {
	none = 0,
	pitch,
	valueRange,
	oscShape,
	comboBoxes,
	lpfFreq,
	lfoFreq,
	sequencerTrackStep,
	toggles
};



class RandomizationOptions
{
	ValueTree transmissionOptionsTree;
	ValueTree paramLocksTree;
	ValueTree allowedValuesTrees;
	ValueTree allowedPitchesTree; // todo: delete
	ValueTree allowedValueRangesTree; // todo: delete
	ValueTree allowedOscShapesTree; // todo: delete
	ValueTree allowedComboBoxItemsTree; // todo: delete
	ValueTree allowedFrequencyTypesTree; // todo: delete
	ValueTree lpfFreqOptionsTree; // todo: delete
	ValueTree repeatValuesOptionsTree;
	ValueTree seqTrackOptionsTree;

public:
	RandomizationOptions();

private:
	void fillAllRandomizationOptionsTreesWithProperties();

public:
	const bool transmissionMethodIsNRPN();
	const bool transmissionMethodIsSysEx();
	void setTransmissionMethodIsNRPN();
	void setTransmissionMethodIsSysEx();

	const bool paramIsLocked(uint8 param);
	const bool paramIsUnlocked(uint8 param);
	void setParamIsLocked(uint8 param);
	void setParamIsUnlocked(uint8 param);

	void addListenerToAllowedValuesTree(ValueTree::Listener* listener);
	void removeListenerFromAllowedValuesTree(ValueTree::Listener* listener);
	const bool valueIsAllowedForParam(uint8 value, uint8 param);
	const bool valueIsNotAllowedForParam(uint8 value, uint8 param); // todo: delete(?)
	void setValueIsAllowedForParam(uint8 value, uint8 param);
	void setValueIsNotAllowedForParam(uint8 value, uint8 param);
	const bool onlyOneValueIsAllowedForParam(uint8 param);
	const bool moreThanOneValueIsAllowedForParam(uint8 param);
	const bool noValueIsAllowedForParam(uint8 param);
	const uint8 onlyValueAllowedForParam(uint8 param);
	void checkNumberOfAllowedValuesForParam(uint8 param);
	void setOnlyOneValueIsAllowedForParam(uint8 param);
	void setMoreThanOneValueIsAllowedForParam(uint8 param);
	void setNoValueIsAllowedForParam(uint8 param);

	void addListenerToAllowedPitchesTree(ValueTree::Listener* listener); // todo: delete
	void removeListenerFromAllowedPitchesTree(ValueTree::Listener* listener); // todo: delete
	const bool noteIsAllowedForParam(int noteNum, uint8 paramIndex); // todo: delete
	void setNoteIsAllowedForParam(int noteNum, uint8 paramIndex); // todo: delete
	void setNoteIsNotAllowedForParam(int noteNum, uint8 paramIndex); // todo: delete
	const bool noNoteIsAllowedForParam(uint8 paramIndex); // todo: delete
	const bool octaveIsAllowedForParam(int octaveNum, uint8 paramIndex); // todo: delete
	void setOctaveIsAllowedForParam(int octaveNum, uint8 paramIndex); // todo: delete
	void setOctaveIsNotAllowedForParam(int octaveNum, uint8 paramIndex); // todo: delete
	const bool noOctaveIsAllowedForParam(uint8 paramIndex); // todo: delete
	const bool pitchIsAllowedForParam(int pitchNum, uint8 paramIndex); // todo: delete
	void checkIfOnlyOneValueIsAllowedForPitchParam(uint8 paramIndex); // todo: delete
	void checkIfHighestOctaveIsOnlyOneAllowedForParam(uint8 paramIndex); // todo: delete
	const bool highestOctaveIsOnlyOneAllowedForParam(uint8 paramIndex); // todo: delete
	void setHighestOctaveIsOnlyOneAllowedForParam(uint8 paramIndex); // todo: delete
	void setHighestOctaveIsNotOnlyOneAllowedForParam(uint8 paramIndex); // todo: delete
	void checkIfHighestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(int trackNum); // todo: delete
	const bool highestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(int trackNum); // todo: delete
	void setHighestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(int trackNum); // todo: delete
	void setHighestOctaveIsNotOnlyOneAllowedForAllStepsInSeqTrack(int trackNum); // todo: delete


	const uint8 minValueAllowedForParam(uint8 paramIndex); // todo: delete
	void setMinValueAllowedForParam(uint8 newMin, uint8 paramIndex); // todo: delete
	const uint8 maxValueAllowedForParam(uint8 paramIndex); // todo: delete
	void setMaxValueAllowedForParam(uint8 newMax, uint8 paramIndex); // todo: delete

	const bool oscShapeIsAllowedForParam(int shapeIndex, uint8 paramIndex); // todo: delete
	void setOscShapeIsAllowedForParam(int shapeIndex, uint8 paramIndex); // todo: delete
	void setOscShapeIsNotAllowedForParam(int shapeIndex, uint8 paramIndex); // todo: delete
	void setOscShapeIsTheOnlyAllowedForParam(int shapeIndex, uint8 paramIndex); // todo: delete
	const bool noOscShapeIsAllowedForParam(uint8 paramIndex); // todo: delete
	const uint8 minPulseWidthAllowedForParam(uint8 paramIndex); // todo: delete
	void setMinPulseWidthAllowedForParam(uint8 newMin, uint8 paramIndex); // todo: delete
	const uint8 maxPulseWidthAllowedForParam(uint8 paramIndex); // todo: delete
	void setMaxPulseWidthAllowedForParam(uint8 newMax, uint8 paramIndex); // todo: delete
	void checkIfOnlyOneValueIsAllowedForOscShapeParam(uint8 paramIndex); // todo: delete

	const bool comboBoxItemIsAllowedForParam(int itemNum, uint8 paramIndex); // todo: delete
	void setComboBoxItemIsAllowedForParam(int itemNum, uint8 paramIndex); // todo: delete
	void setComboBoxItemIsNotAllowedForParam(int itemNum, uint8 paramIndex); // todo: delete
	const bool noComboBoxItemIsAllowedForParam(uint8 paramIndex); // todo: delete

	void addListenerToLPFfreqOptionsTree(ValueTree::Listener* listener); // todo: delete
	void removeListenerFromLPFfreqOptionsTree(ValueTree::Listener* listener); // todo: delete
	const bool randomizationModeForLPFfreqIsPitches(); // todo: delete
	const bool randomizationModeForLPFfreqIsValueRange(); // todo: delete
	void setRandomizationModeForLPFfreqToPitches(); // todo: delete
	void setRandomizationModeForLPFfreqToValueRange(); // todo: delete
	void checkIfOnlyOneValueIsAllowedForLPFfreqParam(); // todo: delete

	const bool pitchedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	const bool pitchedFreqAreNotAllowedForParam(uint8 paramIndex); // todo: delete
	void setPitchedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	void setPitchedFreqAreNotAllowedForParam(uint8 paramIndex); // todo: delete
	const bool moreThanOnePitchedFreqIsAllowedForParam(uint8 paramIndex); // todo: delete
	const bool unsyncedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	const bool unsyncedFreqAreNotAllowedForParam(uint8 paramIndex); // todo: delete
	void setUnsyncedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	void setUnsyncedFreqAreNotAllowedForParam(uint8 paramIndex); // todo: delete
	const uint8 minUnsyncedFreqForParam(uint8 paramIndex); // todo: delete
	void setMinUnsyncedFreqForParam(uint8 newMin, uint8 paramIndex); // todo: delete
	const uint8 maxUnsyncedFreqForParam(uint8 paramIndex); // todo: delete
	void setMaxUnsyncedFreqForParam(uint8 newMax, uint8 paramIndex); // todo: delete
	const bool moreThanOneUnsyncedFreqIsAllowedForParam(uint8 paramIndex); // todo: delete
	const bool syncedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	const bool syncedFreqAreNotAllowedForParam(uint8 paramIndex); // todo: delete
	void setSyncedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	void setSyncedFreqAreNotAllowedForParam(uint8 paramIndex); // todo: delete
	const bool syncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex); // todo: delete
	void setSyncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex); // todo: delete
	void setSyncedFreqIsNotAllowedForParam(int syncedFreqNum, uint8 paramIndex); // todo: delete
	const bool noSyncedFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	const bool moreThanOneSyncedFreqIsAllowedForParam(uint8 paramIndex); // todo: delete
	const bool noFreqAreAllowedForParam(uint8 paramIndex); // todo: delete
	void checkIfOnlyOneValueIsAllowedForLFOfreqParam(uint8 paramIndex); // todo: delete

	void addListenerToRepeatValuesOptionsTree(ValueTree::Listener* listener);
	void removeListenerFromRepeatValuesOptionsTree(ValueTree::Listener* listener);
	const bool repeatValuesAreAllowedForParam(uint8 paramIndex);
	const bool repeatValuesAreNotAllowedForParam(uint8 paramIndex);
	void setRepeatValuesAreAllowedForParam(uint8 paramIndex);
	void setRepeatValuesAreNotAllowedForParam(uint8 paramIndex);
	const bool onlyOneValueIsAllowedForParam_z(uint8 paramIndex); // todo: delete
	const uint8 onlyAllowedValueForParam_z(uint8 paramIndex); // todo: delete
	void setValueIsOnlyOneAllowedForParam_z(uint8 val, uint8 paramIndex); // todo: delete
	void setMoreThanOneValueIsAllowedForParam_z(uint8 paramIndex); // todo: delete
	const bool repeatValuesAreAllowedForAllStepsInSeqTrack(int trackNum);
	const bool repeatValuesAreNotAllowedForAllStepsInSeqTrack(int trackNum);
	void setRepeatValuesAreAllowedForAllStepsInSeqTrack(int trackNum);
	void setRepeatValuesAreNotAllowedForAllStepsInSeqTrack(int trackNum);
	const bool onlyOneValueIsAllowedForAllStepsInSeqTrack(int trackNum);
	const uint8 onlyAllowedValueForAllStepsInSeqTrack(int trackNum);
	void setValueIsOnlyOneAllowedForAllStepsInSeqTrack(uint8 val, int trackNum);
	void setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(int trackNum);

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
	const uint8 minValueForAllStepsInSeqTrack(int trackNum); // todo: delete
	void setMinValueForAllStepsInSeqTrack(uint8 newMin, int trackNum); // todo: delete
	const uint8 maxValueForAllStepsInSeqTrack(int trackNum); // todo: delete
	void setMaxValueForAllStepsInSeqTrack(uint8 newMax, int trackNum); // todo: delete
	const bool pitchIsAllowedForAllStepsInSeqTrack(int pitchNum, int trackNum); // todo: delete
	const bool noteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum); // todo: delete
	void setNoteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum); // todo: delete
	void setNoteIsNotAllowedForAllStepsInSeqTrack(int noteNum, int trackNum); // todo: delete
	const bool noNoteIsAllowedForAllStepsInSeqTrack(int trackNum); // todo: delete
	const bool octaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum); // todo: delete
	void setOctaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum); // todo: delete
	void setOctaveIsNotAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum); // todo: delete
	const bool noOctaveIsAllowedForAllStepsInSeqTrack(int trackNum); // todo: delete
	const bool trackDestinationIsAnOscPitchParameter(int trackNum); // todo: delete
	void setTrackDestinationIsAnOscPitchParameter(int trackNum); // todo: delete
	void setTrackDestinationIsNotAnOscPitchParameter(int trackNum); // todo: delete
	void checkIfOnlyOneValueIsAllowedForSeqStepParam(uint8 paramIndex); // todo: delete
	void checkIfOnlyOneValueIsAllowedForAllStepsInSeqTrack(int trackNum);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
