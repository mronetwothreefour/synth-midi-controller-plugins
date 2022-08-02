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
	Value getParamIsLockedValueForParam(uint8 paramIndex);

	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void clearAllowedChoicesForParam(uint8 paramIndex);
	void allowAllChoicesForParam(uint8 paramIndex);

private:
	void checkNumberOfChoicesAllowedForParam(uint8 paramIndex);


public:
	const bool oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	void setOscShapeIsAllowedForParam(OscWaveShape shape, bool shouldBeAllowed, uint8 paramIndex);
	const bool noOscShapeIsAllowedForParam(uint8 paramIndex);
	const bool pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex);
	void setPulseWidthIsAllowedForParam(int pulseWidth, bool shouldBeAllowed, uint8 paramIndex);
	const bool noPulseWidthIsAllowedForParam(uint8 paramIndex);
	void clearAllowedOscShapesForParam(uint8 paramIndex);
	void clearAllowedPulseWidthsForParam(uint8 paramIndex);
	void allowAllChoicesForOscShapeParam(uint8 paramIndex);

private:
	void checkNumberOfChoicesAllowedForOscShapeParam(uint8 paramIndex);


public:
	const bool categoryIsAllowedFor_LFO_FreqParam(Category category, uint8 paramIndex);
	void setCategoryIsAllowedFor_LFO_FreqParam(LFO_FreqCategory category, bool shouldBeAllowed, uint8 paramIndex);
	const bool noCategoryIsAllowedFor_LFO_FreqParam(uint8 paramIndex);
	const bool unsyncedFreqIsAllowedFor_LFO_FreqParam(uint8 freq, uint8 paramIndex);
	void setUnsyncedFreqIsAllowedFor_LFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex);
	const bool noUnsyncedFreqIsAllowedFor_LFO_FreqParam(uint8 paramIndex);
	const bool pitchedFreqIsAllowedFor_LFO_FreqParam(uint8 freq, uint8 paramIndex);
	void setPitchedFreqIsAllowedFor_LFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex);
	const bool noPitchedFreqIsAllowedFor_LFO_FreqParam(uint8 paramIndex);
	const bool syncedFreqIsAllowedFor_LFO_FreqParam(uint8 freq, uint8 paramIndex);
	void setSyncedFreqIsAllowedFor_LFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex);
	const bool noSyncedFreqIsAllowedFor_LFO_FreqParam(uint8 paramIndex);
	void clearAllowedCategoriesFor_LFO_FreqParam(uint8 paramIndex);
	void clearAllowedUnsyncedFreqForParam(uint8 paramIndex);
	void clearAllowedPitchedFreqForParam(uint8 paramIndex);
	void clearAllowedSyncedFreqForParam(uint8 paramIndex);
	void allowAllChoicesFor_LFO_FreqParam(uint8 paramIndex);

private:
	void checkNumberOfChoicesAllowedFor_LFO_FreqParam(uint8 paramIndex);


public:
	const bool choiceIsAllowedForVoiceNameCharParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForVoiceNameCharParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void clearAllowedChoicesForVoiceNameCharParam(uint8 paramIndex);
	void allowAllChoicesForVoiceNameCharParam(uint8 paramIndex);

private:
	void checkNumberOfChoicesAllowedForVoiceNameCharParam(uint8 paramIndex);


public:
	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	Value getOnlyOneChoiceIsAllowedValueForParam(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);

	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex);

	ValueTree getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex);


	Step targetStepForSeqTrack(Track track);
	void setTargetStepForSeqTrack(Step step, Track track);
	Value getTargetStepForSeqTrackValue(Track track);
	const float probabilityOfRestForSeqTrack_1_Step(Step step);
	void setProbabilityOfRestForAllSeqTrack_1_Steps(float newProb);
	void setProbabilityOfRestForSeqTrack_1_Step(float newProb, Step step);
	const float probabilityOfResetForSeqTrackStep(Track track, Step step);
	void setProbabilityOfResetForAllSeqTrackSteps(float newProb, Track track);
	void setProbabilityOfResetForSeqTrackStep(float newProb, Track track, Step step);
	const bool choiceIsAllowedForSeqTrackStep(uint8 choiceNum, Track track, Step step);
	void setChoiceIsAllowedForAllSeqTrackSteps(uint8 choiceNum, bool shouldBeAllowed, Track track);
	void setChoiceIsAllowedForSeqTrackStep(uint8 choiceNum, bool shouldBeAllowed, Track track, Step step);
	void clearAllowedChoicesForAllSeqTrackSteps(Track track);
	void clearAllowedChoicesForSeqTrackStep(Track track, Step step);
	void allowAllChoicesForAllSeqTrackSteps(Track track);
	void allowAllChoicesForSeqTrackStep(Track track, Step step);
	const bool repeatsMustBeAllowedForSeqTrackStep(Track track, Step step);
	Value getRepeatsMustBeAllowedForSeqTrackStepValue(Track track, Step step);
	const bool noChoiceIsAllowedForSeqTrackStep(Track track, Step step);

private:
	void checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(Track track, Step step);

public:
	const bool repeatChoicesAreAllowedForSeqTrackStep(Track track, Step step);
	const bool repeatChoicesAreForbiddenForSeqTrackStep(Track track, Step step);
	void setRepeatChoicesAreAllowedForSeqTrackStep(bool shouldBeAllowed, Track track, Step step);

	ValueTree getCopyOfAllowedChoicesTreeForSeqTrackStep(Track track, Step step);


	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationOptions)

};
