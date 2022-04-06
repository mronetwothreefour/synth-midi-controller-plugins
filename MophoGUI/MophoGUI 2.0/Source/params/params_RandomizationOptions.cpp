#include "params_RandomizationOptions.h"

#include "params_Constants.h"
#include "params_Identifiers.h"
#include "../randomization/randomization_Constants.h"

using namespace constants;



RandomizationOptions::RandomizationOptions() :
	paramLocksTree{ ID::randomization_ParamLocks },
	oscAllowedPitchesTree{ ID::randomization_OscAllowedPitches },
	lfoAllowedFrequenciesTree{ ID::randomization_LFOallowedFrequencies }
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
		setStepTargetedForEditingInSeqTrack(1, trackNum);
		seqTrackAllowedStepValuesTree.setProperty("probabilityOfRepeatValueForStep1InSeqTrack" + (String)trackNum, 0.0f, nullptr);
		seqTrackAllowedStepValuesTree.setProperty("probabilityOfResetForStep1InSeqTrack" + (String)trackNum, 0.0f, nullptr);
		for (auto stepNum = 1; stepNum != 17; ++stepNum) {
			setMinValueForStepInSeqTrack((uint8)0, stepNum, trackNum);
			setMaxValueForStepInSeqTrack(params::maxValueForSeqTrackStep, stepNum, trackNum);
			if (trackNum == 1)
				setProbabilityOfRestForStepInSeqTrack1(0.125f, stepNum);
			if (stepNum != 1) {
				setProbabilityOfRepeatValueForStepInSeqTrack(0.25f, stepNum, trackNum);
				setProbabilityOfResetForStepInSeqTrack(0.0f, stepNum, trackNum);
			}
			for (auto noteNum = 0; noteNum != (randomization::numberOfNotesAndBentNotes); ++noteNum)
				setNoteIsAllowedForStepInSeqTrack(noteNum, stepNum, trackNum);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum)
				setOctaveIsAllowedForStepInSeqTrack(octaveNum, stepNum, trackNum);
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
	return (bool)seqTrackAllowedStepValuesTree.getProperty("editModeIsAllStepForSeqTrack" + (String)trackNum);
}

const bool RandomizationOptions::editModeForSeqTrackIsSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setEditModeForSeqTrackToAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("editModeIsAllStepForSeqTrack" + (String)trackNum, (bool)true, nullptr);
	seqTrackAllowedStepValuesTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

void RandomizationOptions::setEditModeForSeqTrackToSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("editModeIsAllStepForSeqTrack" + (String)trackNum, (bool)false, nullptr);
	seqTrackAllowedStepValuesTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

const int RandomizationOptions::stepTargetedForEditingInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (int)seqTrackAllowedStepValuesTree.getProperty("stepTargetedForEditingInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setStepTargetedForEditingInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("stepTargetedForEditingInSeqTrack" + (String)trackNum, stepNum, nullptr);
}

const uint8 RandomizationOptions::minValueForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	int minValue{ seqTrackAllowedStepValuesTree.getProperty("minValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return (uint8)minValue;
}

void RandomizationOptions::setMinValueForStepInSeqTrack(uint8 newMin, int stepNum, int trackNum) {
	jassert(newMin <= params::maxValueForSeqTrackStep);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("minValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newMin, nullptr);
}

const uint8 RandomizationOptions::maxValueForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	int maxValue{ seqTrackAllowedStepValuesTree.getProperty("maxValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return (uint8)maxValue;
}

void RandomizationOptions::setMaxValueForStepInSeqTrack(uint8 newMax, int stepNum, int trackNum) {
	jassert(newMax <= params::maxValueForSeqTrackStep);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("maxValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newMax, nullptr);
}

const float RandomizationOptions::probabilityOfRestForStepInSeqTrack1(int stepNum) {
	jassert(stepNum > 0 && stepNum < 17);
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRestForStep" + (String)stepNum + "InSeqTrack1") };
	return probability;
}

void RandomizationOptions::setProbabilityOfRestForStepInSeqTrack1(float newProb, int stepNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRestForStep" + (String)stepNum + "InSeqTrack1", newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 1 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfRepeatValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatValueForStepInSeqTrack(float newProb, int stepNum, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 1 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfRepeatValueForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 1 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	float probability{ seqTrackAllowedStepValuesTree.getProperty("probabilityOfResetForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForStepInSeqTrack(float newProb, int stepNum, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 1 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("probabilityOfResetForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, newProb, nullptr);
}

const bool RandomizationOptions::pitchIsAllowedForStepInSeqTrack(int pitchNum, int stepNum, int trackNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto noteIsAllowed{ noteIsAllowedForStepInSeqTrack(pitchNum % (randomization::numberOfNotesAndBentNotes), stepNum, trackNum) };
	auto octaveIsAllowed{ octaveIsAllowedForStepInSeqTrack(pitchNum / (randomization::numberOfNotesAndBentNotes), stepNum, trackNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForStepInSeqTrack(int noteNum, int stepNum, int trackNum) {
	jassert(noteNum > -1 && noteNum < (randomization::numberOfNotesAndBentNotes));
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("note" + String(noteNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setNoteIsAllowedForStepInSeqTrack(int noteNum, int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("note" + String(noteNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForStepInSeqTrack(int noteNum, int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("note" + String(noteNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		if (noteIsAllowedForStepInSeqTrack(noteNum, stepNum, trackNum))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForStepInSeqTrack(int octaveNum, int stepNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackAllowedStepValuesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setOctaveIsAllowedForStepInSeqTrack(int octaveNum, int stepNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForStepInSeqTrack(int octaveNum, int stepNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOsAndSeqSteps);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackAllowedStepValuesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForStep" + (String)stepNum + "InSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		if (octaveIsAllowedForStepInSeqTrack(octaveNum, stepNum, trackNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyOctave5_IsAllowedForStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto octave5_IsNotTheOnlyOneAllowed{ (bool)false };
	auto octave5_IsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps - 1; ++octaveNum) {
		if (octaveIsAllowedForStepInSeqTrack(octaveNum, stepNum, trackNum))
			return octave5_IsNotTheOnlyOneAllowed;
	}
	return octave5_IsTheOnlyOneAllowed;
}
