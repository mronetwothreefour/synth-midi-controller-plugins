#include "params_RandomizationOptions.h"

#include "params_Constants.h"
#include "params_Identifiers.h"
#include "../randomization/randomization_Constants.h"

using namespace constants;



RandomizationOptions::RandomizationOptions() :
	paramLocksTree{ ID::randomization_ParamLocks },
	oscAllowedPitchesTree{ ID::randomization_OscAllowedPitches },
	lfoAllowedFrequenciesTree{ ID::randomization_LFOallowedFrequencies },
	seqTrackAllowedStepValuesTree{ ID::randomization_SeqTrackAllowedStepValues }
{
	fillAllRandomizationOptionsTreesWithProperties();
}

void RandomizationOptions::fillAllRandomizationOptionsTreesWithProperties() {
	for (uint8 param = 0; param != params::numberOfExposedParams; ++param)
		setParamIsUnlocked(param);
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
			setNoteIsAllowedForOscillator(noteNum, oscNum);
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum)
			setOctaveIsAllowedForOscillator(octaveNum, oscNum);
	}
	for (auto lfoNum = 1; lfoNum != 5; ++lfoNum) {
		setUnsyncedFreqAreAllowedForLFO(lfoNum);
		setMinUnsyncedFreqForLFO((uint8)0, lfoNum);
		setMaxUnsyncedFreqForLFO(params::maxUnsyncedLFOfreq, lfoNum);
		setPitchedFreqAreAllowedForLFO(lfoNum);
		for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
			setNoteIsAllowedForLFO(noteNum, lfoNum);
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum)
			setOctaveIsAllowedForLFO(octaveNum, lfoNum);
		setSyncedFreqAreAllowedForLFO(lfoNum);
		for (auto syncedFreqNum = 0; syncedFreqNum != randomization::numberOfSyncedFreqForLFOs; ++syncedFreqNum)
			setSyncedFreqIsAllowedForLFO(syncedFreqNum, lfoNum);
	}
	for (auto trackNum = 1; trackNum != 5; ++trackNum) {
		setEditModeForSeqTrackToAllSteps(trackNum);
		setStepSelectedForEditingInSeqTrack(1, trackNum);
		if (trackNum == 1)
			setProbabilityOfRestForAllStepsInSeqTrack1(0.125f);
		setProbabilityOfRepeatForAllStepsInSeqTrack(0.0f, trackNum);
		setProbabilityOfResetForAllStepsInSeqTrack(0.0f, trackNum);
		for (auto stepNum = 1; stepNum != 17; ++stepNum) {
			if (trackNum == 1)
				setProbabilityOfRestForSelectedStepInSeqTrack1(0.125f, stepNum);
			if (stepNum == 1) 
				setProbabilityOfRepeatValueForSelectedStepInSeqTrack(0.0f, stepNum, trackNum);
			else
				setProbabilityOfRepeatValueForSelectedStepInSeqTrack(0.25f, stepNum, trackNum);
			setProbabilityOfResetForSelectedStepInSeqTrack(0.0f, stepNum, trackNum);
			for (auto noteNum = 0; noteNum != (randomization::numberOfNotesAndBentNotes); ++noteNum)
				setNoteIsAllowedForSelectedStepInSeqTrack(noteNum, stepNum, trackNum);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum)
				setOctaveIsAllowedForSelectedStepInSeqTrack(octaveNum, stepNum, trackNum);
			setMinValueForSelectedStepInSeqTrack((uint8)0, stepNum, trackNum);
			setMaxValueForSelectedStepInSeqTrack(params::maxValueForSeqTrackStep, stepNum, trackNum);
		}
	}
}

const bool RandomizationOptions::paramIsLocked(uint8 param) {
	jassert(param < params::numberOfExposedParams);
	return (bool)paramLocksTree.getProperty("param" + String(param) + "_IsLocked");
}

void RandomizationOptions::setParamIsLocked(uint8 param) {
	jassert(param < params::numberOfExposedParams);
	paramLocksTree.setProperty("param" + String(param) + "_IsLocked", (bool)true, nullptr);
}

void RandomizationOptions::setParamIsUnlocked(uint8 param) {
	jassert(param < params::numberOfExposedParams);
	paramLocksTree.setProperty("param" + String(param) + "_IsLocked", (bool)false, nullptr);
}

const bool RandomizationOptions::pitchIsAllowedForOscillator(int pitchNum, int oscNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForOscillators);
	jassert(oscNum == 1 || oscNum == 2);
	auto noteIsAllowed{ noteIsAllowedForOscillator(pitchNum % randomization::numberOfNotes, oscNum) };
	auto octaveIsAllowed{ octaveIsAllowedForOscillator(pitchNum / randomization::numberOfNotes, oscNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForOscillator(int noteNum, int oscNum) {
	jassert(noteNum > -1 && noteNum < randomization::numberOfNotes);
	jassert(oscNum == 1 || oscNum == 2);
	return (bool)oscAllowedPitchesTree.getProperty("note" + String(noteNum) + "_IsAllowedForOsc" + String(oscNum));
}

void RandomizationOptions::setNoteIsAllowedForOscillator(int noteNum, int oscNum) {
	jassert(noteNum > -1 && noteNum < randomization::numberOfNotes);
	jassert(oscNum == 1 || oscNum == 2);
	oscAllowedPitchesTree.setProperty("note" + String(noteNum) + "_IsAllowedForOsc" + String(oscNum), (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForOscillator(int noteNum, int oscNum) {
	jassert(noteNum > -1 && noteNum < randomization::numberOfNotes);
	jassert(oscNum == 1 || oscNum == 2);
	oscAllowedPitchesTree.setProperty("note" + String(noteNum) + "_IsAllowedForOsc" + String(oscNum), (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForOscillator(int oscNum) {
	jassert(oscNum == 1 || oscNum == 2);
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		if (noteIsAllowedForOscillator(noteNum, oscNum))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForOscillator(int octaveNum, int oscNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForOscillators);
	jassert(oscNum == 1 || oscNum == 2);
	return (bool)oscAllowedPitchesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedForOsc" + String(oscNum));
}

void RandomizationOptions::setOctaveIsAllowedForOscillator(int octaveNum, int oscNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForOscillators);
	jassert(oscNum == 1 || oscNum == 2);
	oscAllowedPitchesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForOsc" + String(oscNum), (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForOscillator(int octaveNum, int oscNum) {
	jassert(octaveNum > -1 && octaveNum < 11);
	jassert(oscNum == 1 || oscNum == 2);
	oscAllowedPitchesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForOsc" + String(oscNum), (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForOscillator(int oscNum) {
	jassert(oscNum == 1 || oscNum == 2);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		if (octaveIsAllowedForOscillator(octaveNum, oscNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyOctave10_IsAllowedForOscillator(int oscNum) {
	jassert(oscNum == 1 || oscNum == 2);
	auto octave10_IsNotTheOnlyOneAllowed{ (bool)false };
	auto octave10_IsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators - 1; ++octaveNum) {
		if (octaveIsAllowedForOscillator(octaveNum, oscNum))
			return octave10_IsNotTheOnlyOneAllowed;
	}
	return octave10_IsTheOnlyOneAllowed;
}

const bool RandomizationOptions::unsyncedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	return lfoAllowedFrequenciesTree.getProperty("unsyncedFreqAreAllowedForLFO" + (String)lfoNum);
}

void RandomizationOptions::setUnsyncedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("unsyncedFreqAreAllowedForLFO" + (String)lfoNum, (bool)true, nullptr);
}

void RandomizationOptions::setUnsyncedFreqAreNotAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("unsyncedFreqAreAllowedForLFO" + (String)lfoNum, (bool)false, nullptr);
}

const uint8 RandomizationOptions::minUnsyncedFreqForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	int minFreq{ lfoAllowedFrequenciesTree.getProperty("minUnsyncedFreqForLFO" + (String)lfoNum) };
	return (uint8)minFreq;
}

void RandomizationOptions::setMinUnsyncedFreqForLFO(uint8 newMin, int lfoNum) {
	jassert(newMin <= params::maxUnsyncedLFOfreq);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("minUnsyncedFreqForLFO" + (String)lfoNum, newMin, nullptr);
}

const uint8 RandomizationOptions::maxUnsyncedFreqForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	int maxFreq{ lfoAllowedFrequenciesTree.getProperty("maxUnsyncedFreqForLFO" + (String)lfoNum) };
	return (uint8)maxFreq;
}

void RandomizationOptions::setMaxUnsyncedFreqForLFO(uint8 newMax, int lfoNum) {
	jassert(newMax <= params::maxUnsyncedLFOfreq);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("maxUnsyncedFreqForLFO" + (String)lfoNum, newMax, nullptr);
}

const bool RandomizationOptions::pitchedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	return (bool)lfoAllowedFrequenciesTree.getProperty("pitchedFreqAreAllowedForLFO" + (String)lfoNum);
}

void RandomizationOptions::setPitchedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("pitchedFreqAreAllowedForLFO" + (String)lfoNum, (bool)true, nullptr);
}

void RandomizationOptions::setPitchedFreqAreNotAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("pitchedFreqAreAllowedForLFO" + (String)lfoNum, (bool)false, nullptr);
}

const bool RandomizationOptions::pitchIsAllowedForLFO(int pitchNum, int lfoNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchedFreqForLFOs);
	jassert(lfoNum > 0 && lfoNum < 5);
	auto noteIsAllowed{ noteIsAllowedForLFO(pitchNum % randomization::numberOfNotes, lfoNum) };
	auto octaveIsAllowed{ octaveIsAllowedForLFO(pitchNum / randomization::numberOfNotes, lfoNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForLFO(int noteNum, int lfoNum) {
	jassert(noteNum > -1 && noteNum < randomization::numberOfNotes);
	jassert(lfoNum > 0 && lfoNum < 5);
	return (bool)lfoAllowedFrequenciesTree.getProperty("note" + String(noteNum) + "_IsAllowedForLFO" + String(lfoNum));
}

void RandomizationOptions::setNoteIsAllowedForLFO(int noteNum, int lfoNum) {
	jassert(noteNum > -1 && noteNum < randomization::numberOfNotes);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("note" + String(noteNum) + "_IsAllowedForLFO" + String(lfoNum), (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForLFO(int noteNum, int lfoNum) {
	jassert(noteNum > -1 && noteNum < randomization::numberOfNotes);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("note" + String(noteNum) + "_IsAllowedForLFO" + String(lfoNum), (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		if (noteIsAllowedForLFO(noteNum, lfoNum))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForLFO(int octaveNum, int lfoNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(lfoNum > 0 && lfoNum < 5);
	return (bool)lfoAllowedFrequenciesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedForLFO" + String(lfoNum));
}

void RandomizationOptions::setOctaveIsAllowedForLFO(int octaveNum, int lfoNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForLFO" + String(lfoNum), (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForLFO(int octaveNum, int lfoNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForLFO" + String(lfoNum), (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		if (octaveIsAllowedForLFO(octaveNum, lfoNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyOctave5_IsAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	auto octave5_IsNotTheOnlyOneAllowed{ (bool)false };
	auto octave5_IsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps - 1; ++octaveNum) {
		if (octaveIsAllowedForLFO(octaveNum, lfoNum))
			return octave5_IsNotTheOnlyOneAllowed;
	}
	return octave5_IsTheOnlyOneAllowed;
}

const bool RandomizationOptions::syncedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	return (bool)lfoAllowedFrequenciesTree.getProperty("syncedFreqAreAllowedForLFO" + (String)lfoNum);
}

void RandomizationOptions::setSyncedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("syncedFreqAreAllowedForLFO" + (String)lfoNum, (bool)true, nullptr);
}

void RandomizationOptions::setSyncedFreqAreNotAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("syncedFreqAreAllowedForLFO" + (String)lfoNum, (bool)false, nullptr);
}

const bool RandomizationOptions::syncedFreqIsAllowedForLFO(int syncedFreqNum, int lfoNum) {
	jassert(syncedFreqNum > -1 && syncedFreqNum < randomization::numberOfSyncedFreqForLFOs);
	jassert(lfoNum > 0 && lfoNum < 5);
	return (bool)lfoAllowedFrequenciesTree.getProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedForLFO" + (String)lfoNum);
}

void RandomizationOptions::setSyncedFreqIsAllowedForLFO(int syncedFreqNum, int lfoNum) {
	jassert(syncedFreqNum > -1 && syncedFreqNum < randomization::numberOfSyncedFreqForLFOs);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedForLFO" + (String)lfoNum, (bool)true, nullptr);
}

void RandomizationOptions::setSyncedFreqIsNotAllowedForLFO(int syncedFreqNum, int lfoNum) {
	jassert(syncedFreqNum > -1 && syncedFreqNum < randomization::numberOfSyncedFreqForLFOs);
	jassert(lfoNum > 0 && lfoNum < 5);
	lfoAllowedFrequenciesTree.setProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedForLFO" + (String)lfoNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noSyncedFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	auto atLeastOneSyncedFreqIsAllowed{ (bool)false };
	auto noSyncedFreqIsAllowed{ (bool)true };
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		if (syncedFreqIsAllowedForLFO(freqNum, lfoNum))
			return atLeastOneSyncedFreqIsAllowed;
	}
	return noSyncedFreqIsAllowed;
}

const bool RandomizationOptions::noFreqAreAllowedForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	if (pitchedFreqAreAllowedForLFO(lfoNum) || syncedFreqAreAllowedForLFO(lfoNum) || unsyncedFreqAreAllowedForLFO(lfoNum))
		return false;
	else
		return true;
}

void RandomizationOptions::addListenerToSeqTrackAllowedStepValuesTree(ValueTree::Listener* listener) {
	seqTrackAllowedStepValuesTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromSeqTrackAllowedStepValuesTree(ValueTree::Listener* listener) {
	seqTrackAllowedStepValuesTree.removeListener(listener);
}

const bool RandomizationOptions::editModeForSeqTrackIsAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return !(bool)seqTrackAllowedStepValuesTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

const bool RandomizationOptions::editModeForSeqTrackIsSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setEditModeForSeqTrackToAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

void RandomizationOptions::setEditModeForSeqTrackToSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

const int RandomizationOptions::stepSelectedForEditingInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (int)seqTrackAllowedStepValuesTree.getProperty("stepSelectedForEditingInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setStepSelectedForEditingInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("stepSelectedForEditingInSeqTrack" + (String)trackNum, stepNum, nullptr);
}

const float RandomizationOptions::probabilityOfRestForAllStepsInSeqTrack1() {
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRestForAllStepsInSeqTrack1") };
	return probability;
}

void RandomizationOptions::setProbabilityOfRestForAllStepsInSeqTrack1(float newProb) {
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRestForAllStepsInSeqTrack1", newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRestForSelectedStepInSeqTrack1(int stepNum) {
	jassert(stepNum > 0 && stepNum < 17);
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRestForStep" + (String)stepNum + "InSeqTrack1") };
	return probability;
}

void RandomizationOptions::setProbabilityOfRestForSelectedStepInSeqTrack1(float newProb, int stepNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRestForStep" + (String)stepNum + "InSeqTrack1", newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForAllStepsInSeqTrack(int trackNum) {
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRepeatValueForAllStepsInSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatForAllStepsInSeqTrack(float newProb, int trackNum) {
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRepeatValueForAllStepsInSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRepeatValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatValueForSelectedStepInSeqTrack(float newProb, int stepNum, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRepeatValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForAllStepsInSeqTrack(int trackNum) {
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRestForAllStepsInSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum) {
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRestForAllStepsInSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfResetForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForSelectedStepInSeqTrack(float newProb, int stepNum, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfResetForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newProb, nullptr);
}

const uint8 RandomizationOptions::minValueForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	int minValue{ seqTrackAllowedStepValuesTree.getProperty("minValueForAllStepsInSeqTrack" + (String)trackNum) };
	return (uint8)minValue;
}

void RandomizationOptions::setMinValueForAllStepsInSeqTrack(uint8 newMin, int trackNum) {
	jassert(newMin <= params::maxValueForSeqTrackStep);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("minValueForAllStepsInSeqTrack" + (String)trackNum, newMin, nullptr);
}

const uint8 RandomizationOptions::minValueForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	int minValue{ seqTrackAllowedStepValuesTree.getProperty("minValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return (uint8)minValue;
}

void RandomizationOptions::setMinValueForSelectedStepInSeqTrack(uint8 newMin, int stepNum, int trackNum) {
	jassert(newMin <= params::maxValueForSeqTrackStep);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("minValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newMin, nullptr);
}

const uint8 RandomizationOptions::maxValueForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	int maxValue{ seqTrackAllowedStepValuesTree.getProperty("maxValueForAllStepsInSeqTrack" + (String)trackNum) };
	return (uint8)maxValue;
}

void RandomizationOptions::setMaxValueForAllStepsInSeqTrack(uint8 newMax, int trackNum) {
	jassert(newMax <= params::maxValueForSeqTrackStep);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("maxValueForAllStepsInSeqTrack" + (String)trackNum, newMax, nullptr);
}

const uint8 RandomizationOptions::maxValueForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	int maxValue{ seqTrackAllowedStepValuesTree.getProperty("maxValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return (uint8)maxValue;
}

void RandomizationOptions::setMaxValueForSelectedStepInSeqTrack(uint8 newMax, int stepNum, int trackNum) {
	jassert(newMax <= params::maxValueForSeqTrackStep);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("maxValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newMax, nullptr);
}

const bool RandomizationOptions::pitchIsAllowedForAllStepsInSeqTrack(int pitchNum, int trackNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	auto noteIsAllowed{ noteIsAllowedForAllStepsInSeqTrack(pitchNum % (randomization::numberOfNotesAndBentNotes), trackNum) };
	auto octaveIsAllowed{ octaveIsAllowedForAllStepsInSeqTrack(pitchNum / (randomization::numberOfNotesAndBentNotes), trackNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::pitchIsAllowedForSelectedStepInSeqTrack(int pitchNum, int stepNum, int trackNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto noteIsAllowed{ noteIsAllowedForSelectedStepInSeqTrack(pitchNum % (randomization::numberOfNotesAndBentNotes), stepNum, trackNum) };
	auto octaveIsAllowed{ octaveIsAllowedForSelectedStepInSeqTrack(pitchNum / (randomization::numberOfNotesAndBentNotes), stepNum, trackNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(noteNum > -1 && noteNum < (randomization::numberOfNotesAndBentNotes));
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("note" + String(noteNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setNoteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("note" + String(noteNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("note" + String(noteNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		if (noteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForSelectedStepInSeqTrack(int noteNum, int stepNum, int trackNum) {
	jassert(noteNum > -1 && noteNum < (randomization::numberOfNotesAndBentNotes));
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("note" + String(noteNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setNoteIsAllowedForSelectedStepInSeqTrack(int noteNum, int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("note" + String(noteNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForSelectedStepInSeqTrack(int noteNum, int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("note" + String(noteNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		if (noteIsAllowedForSelectedStepInSeqTrack(noteNum, stepNum, trackNum))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setOctaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		if (octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyOctave5_IsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto octave5_IsNotTheOnlyOneAllowed{ (bool)false };
	auto octave5_IsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps - 1; ++octaveNum) {
		if (octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum))
			return octave5_IsNotTheOnlyOneAllowed;
	}
	return octave5_IsTheOnlyOneAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForSelectedStepInSeqTrack(int octaveNum, int stepNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setOctaveIsAllowedForSelectedStepInSeqTrack(int octaveNum, int stepNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForSelectedStepInSeqTrack(int octaveNum, int stepNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		if (octaveIsAllowedForSelectedStepInSeqTrack(octaveNum, stepNum, trackNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyOctave5_IsAllowedForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto octave5_IsNotTheOnlyOneAllowed{ (bool)false };
	auto octave5_IsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps - 1; ++octaveNum) {
		if (octaveIsAllowedForSelectedStepInSeqTrack(octaveNum, stepNum, trackNum))
			return octave5_IsNotTheOnlyOneAllowed;
	}
	return octave5_IsTheOnlyOneAllowed;
}

XmlElement* RandomizationOptions::getStateXml() {
	std::unique_ptr<XmlElement> randomizationOptionsStateXml{ new XmlElement(ID::state_RandomizationOptions) };

	auto paramLocksTreeStateXml{ paramLocksTree.createXml() };
	if (paramLocksTreeStateXml != nullptr) {
		paramLocksTreeStateXml->setTagName(ID::randomization_ParamLocks);
		randomizationOptionsStateXml->addChildElement(paramLocksTreeStateXml.release());
	}

	auto oscAllowedPitchesTreeStateXml{ oscAllowedPitchesTree.createXml() };
	if (oscAllowedPitchesTreeStateXml != nullptr) {
		oscAllowedPitchesTreeStateXml->setTagName(ID::randomization_OscAllowedPitches);
		randomizationOptionsStateXml->addChildElement(oscAllowedPitchesTreeStateXml.release());
	}

	auto lfoAllowedFrequenciesTreeStateXml{ lfoAllowedFrequenciesTree.createXml() };
	if (lfoAllowedFrequenciesTreeStateXml != nullptr) {
		lfoAllowedFrequenciesTreeStateXml->setTagName(ID::randomization_LFOallowedFrequencies);
		randomizationOptionsStateXml->addChildElement(lfoAllowedFrequenciesTreeStateXml.release());
	}

	auto seqTrackAllowedStepValuesTreeStateXml{ seqTrackAllowedStepValuesTree.createXml() };
	if (seqTrackAllowedStepValuesTreeStateXml != nullptr) {
		seqTrackAllowedStepValuesTreeStateXml->setTagName(ID::randomization_SeqTrackAllowedStepValues);
		randomizationOptionsStateXml->addChildElement(seqTrackAllowedStepValuesTreeStateXml.release());
	}

	return randomizationOptionsStateXml.release();
}

void RandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid()) {
		auto paramLocksTreeState{ newState.getChildWithName(ID::randomization_ParamLocks) };
		if (paramLocksTreeState.isValid())
			paramLocksTree.copyPropertiesAndChildrenFrom(paramLocksTreeState, nullptr);

		auto oscAllowedPitchesTreeState{ newState.getChildWithName(ID::randomization_OscAllowedPitches) };
		if (oscAllowedPitchesTreeState.isValid())
			oscAllowedPitchesTree.copyPropertiesAndChildrenFrom(oscAllowedPitchesTreeState, nullptr);

		auto lfoAllowedFrequenciesTreeState{ newState.getChildWithName(ID::randomization_LFOallowedFrequencies) };
		if (lfoAllowedFrequenciesTreeState.isValid())
			lfoAllowedFrequenciesTree.copyPropertiesAndChildrenFrom(lfoAllowedFrequenciesTreeState, nullptr);

		auto seqTrackAllowedStepValuesTreeState{ newState.getChildWithName(ID::randomization_SeqTrackAllowedStepValues) };
		if (seqTrackAllowedStepValuesTreeState.isValid())
			seqTrackAllowedStepValuesTree.copyPropertiesAndChildrenFrom(seqTrackAllowedStepValuesTreeState, nullptr);
	}
}
