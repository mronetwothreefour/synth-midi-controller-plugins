#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Category = LFO_FreqCategory;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class InfoForExposedParameters;

class ExposedParamsRandomizationOptions
{
	ValueTree randomizationOptionsTree;
	InfoForExposedParameters* info;

public:
	ExposedParamsRandomizationOptions() = delete;

	explicit ExposedParamsRandomizationOptions(InfoForExposedParameters* info);

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


	const bool choiceIsAllowedForVoiceNameCharParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForVoiceNameCharParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void checkNumberOfChoicesAllowedForVoiceNameCharParam(uint8 paramIndex);
	void clearAllowedChoicesForVoiceNameCharParam(uint8 paramIndex);
	void allowAllChoicesForVoiceNameCharParam(uint8 paramIndex);


	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);


	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex);


	void addListenerToChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);
	void removeListenerFromChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);


	ValueTree getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex);


	Step targetStepForSeqTrack(Track track);
	void setTargetStepForSeqTrack(Step step, Track track);
	const float probabilityOfRestForSeqTrack_1_Step(Step step);
	void setProbabilityOfRestForSeqTrack_1_Step(float newProb, Step step);
	const float probabilityOfDuplicateForSeqTrackStep(Track track, Step step);
	void setProbabilityOfDuplicateForSeqTrackStep(float newProb, Track track, Step step);
	const float probabilityOfResetForSeqTrackStep(Track track, Step step);
	void setProbabilityOfResetForSeqTrackStep(float newProb, Track track, Step step);
	const bool choiceIsAllowedForSeqTrackStep(uint8 choiceNum, Track track, Step step);
	void setChoiceIsAllowedForSeqTrackStep(uint8 choiceNum, bool shouldBeAllowed, Track track, Step step);
	void clearAllowedChoicesForSeqTrackStep(Track track, Step step);
	void allowAllChoicesForSeqTrackStep(Track track, Step step);
	void checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(Track track, Step step);
	const bool repeatChoicesMustBeAllowedForSeqTrackStep(Track track, Step step);
	const bool noChoiceIsAllowedForSeqTrackStep(Track track, Step step);
	const bool repeatChoicesAreAllowedForSeqTrackStep(Track track, Step step);
	const bool repeatChoicesAreForbiddenForSeqTrackStep(Track track, Step step);
	void setRepeatChoicesAreAllowedForSeqTrackStep(bool shouldBeAllowed, Track track, Step step);


	void addListenerToSeqTrackTree(ValueTree::Listener* listener, Track track);
	void removeListenerFromSeqTrackTree(ValueTree::Listener* listener, Track track);


	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationOptions)
};
