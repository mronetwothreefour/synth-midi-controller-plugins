#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Category = LFO_FreqCategory;



class RandomizationOptions
{
	ValueTree randomizationOptionsTree;

public:
	RandomizationOptions();

	const bool transmitMethodIsSysEx();
	void setTransmitMethodIsSysEx(bool shouldBeSysEx);


	const bool paramIsLocked(uint8 paramIndex);
	const bool paramIsUnlocked(uint8 paramIndex);
	void setParamIsLocked(uint8 paramIndex, bool shouldBeLocked);


	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void checkNumberOfChoicesAllowedForParam(uint8 paramIndex);
	void clearAllowedChoicesForParam(uint8 paramIndex);
	void allowAllChoicesForParam(uint8 paramIndex);


	const bool oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	void setOscShapeIsAllowedForParam(OscWaveShape shape, bool shouldBeAllowed, uint8 paramIndex);
	const bool noOscShapeIsAllowedForParam(uint8 paramIndex);
	const bool pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex);
	void setPulseWidthIsAllowedForParam(int pulseWidth, bool shouldBeAllowed, uint8 paramIndex);
	const bool noPulseWidthIsAllowedForParam(uint8 paramIndex);
	void checkNumberOfChoicesAllowedForOscShapeParam(uint8 paramIndex);
	void clearAllowedOscShapesForParam(uint8 paramIndex);
	void clearAllowedPulseWidthsForParam(uint8 paramIndex);
	void allowAllChoicesForOscShapeParam(uint8 paramIndex);


	const bool categoryIsAllowedForLFO_FreqParam(Category category, uint8 paramIndex);
	void setCategoryIsAllowedForLFO_FreqParam(LFO_FreqCategory category, bool shouldBeAllowed, uint8 paramIndex);
	const bool noCategoryIsAllowedForLFO_FreqParam(uint8 paramIndex);
	const bool unsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	void setUnsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex);
	const bool noUnsyncedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex);
	const bool pitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	void setPitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex);
	const bool noPitchedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex);
	const bool syncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	void setSyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex);
	const bool noSyncedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex);
	void checkNumberOfChoicesAllowedForLFO_FreqParam(uint8 paramIndex);
	void clearAllowedCategoriesForLFO_FreqParam(uint8 paramIndex);
	void clearAllowedUnsyncedFreqForParam(uint8 paramIndex);
	void clearAllowedPitchedFreqForParam(uint8 paramIndex);
	void clearAllowedSyncedFreqForParam(uint8 paramIndex);
	void allowAllChoicesForLFO_FreqParam(uint8 paramIndex);


	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);


	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex);


	void addListenerToChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);
	void removeListenerFromChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);


	ValueTree getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex);


	const bool editModeIsAllStepsForSeqTrack(int trackNum);
	const bool editModeIsSelectedStepForSeqTrack(int trackNum);
	void setEditModeIsAllStepsForSeqTrack(bool shouldBeAllSteps, int trackNum);
	int selectedStepForSeqTrack(int trackNum);
	void setSelectedStepForSeqTrack(int stepNum, int trackNum);
	const float probabilityOfRestForAllStepsInSeqTrack_1();
	void setProbabilityOfRestForAllStepsInSeqTrack_1(float newProb);
	const float probabilityOfRestForSeqTrack_1_Step(int stepNum);
	void setProbabilityOfRestForSeqTrack_1_Step(float newProb, int stepNum);
	const float probabilityOfDuplicatesForAllStepsInSeqTrack(int trackNum);
	void setProbabilityOfDuplicatesForAllStepsInSeqTrack(float newProb, int trackNum);
	const float probabilityOfDuplicateForSeqTrackStep(int trackNum, int stepNum);
	void setProbabilityOfDuplicateForSeqTrackStep(float newProb, int trackNum, int stepNum);
	const float probabilityOfResetForAllStepsInSeqTrack(int trackNum);
	void setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum);
	const float probabilityOfResetForSeqTrackStep(int trackNum, int stepNum);
	void setProbabilityOfResetForSeqTrackStep(float newProb, int trackNum, int stepNum);
	const bool choiceIsAllowedForAllStepsInSeqTrack(uint8 choiceNum, int trackNum);
	void setChoiceIsAllowedForAllStepsInSeqTrack(uint8 choiceNum, bool shouldBeAllowed, int trackNum);
	void clearAllowedChoicesForAllStepsInSeqTrack(int trackNum);
	void allowAllChoicesForAllStepsInSeqTrack(int trackNum);
	const bool choiceIsAllowedForSeqTrackStep(uint8 choiceNum, int trackNum, int stepNum);
	void setChoiceIsAllowedForSeqTrackStep(uint8 choiceNum, bool shouldBeAllowed, int trackNum, int stepNum);
	void clearAllowedChoicesForSeqTrackStep(int trackNum, int stepNum);
	void allowAllChoicesForSeqTrackStep(int trackNum, int stepNum);
	void checkProbabilitiesAndNumberOfChoicesAllowedForAllStepsInSeqTrack(int trackNum);
	void checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(int trackNum, int stepNum);
	const bool repeatsMustBeAllowedForAllStepsInSeqTrack(int trackNum);
	const bool noChoiceIsAllowedForAllStepsInSeqTrack(int trackNum);
	const bool repeatsMustBeAllowedForSeqTrackStep(int trackNum, int stepNum);
	const bool noChoiceIsAllowedForSeqTrackStep(int trackNum, int stepNum);
	const bool repeatChoicesAreAllowedForAllStepsInSeqTrack(int trackNum);
	const bool repeatChoicesAreForbiddenForAllStepsInSeqTrack(int trackNum);
	void setRepeatChoicesAreAllowedForAllStepsInSeqTrack(bool shouldBeAllowed, int trackNum);
	const bool repeatChoicesAreAllowedForSeqTrackStep(int trackNum, int stepNum);
	const bool repeatChoicesAreForbiddenForSeqTrackStep(int trackNum, int stepNum);
	void setRepeatChoicesAreAllowedForSeqTrackStep(bool shouldBeAllowed, int trackNum, int stepNum);


	void addListenerToSeqTrackTree(ValueTree::Listener* listener, int trackNum);
	void removeListenerFromSeqTrackTree(ValueTree::Listener* listener, int trackNum);


	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
