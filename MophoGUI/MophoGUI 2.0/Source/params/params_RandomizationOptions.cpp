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
	auto noteIsAllowed{ noteIsAllowedForOscillator(pitchNum % 12, oscNum) };
	auto octaveIsAllowed{ octaveIsAllowedForOscillator(pitchNum / 12, oscNum) };
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
	lfoAllowedFrequenciesTree.setProperty("minUnsyncedFreqForLFO" + (String)lfoNum, newMin, nullptr);
}

const uint8 RandomizationOptions::maxUnsyncedFreqForLFO(int lfoNum) {
	jassert(lfoNum > 0 && lfoNum < 5);
	int maxFreq{ lfoAllowedFrequenciesTree.getProperty("maxUnsyncedFreqForLFO" + (String)lfoNum) };
	return (uint8)maxFreq;
}

void RandomizationOptions::setMaxUnsyncedFreqForLFO(uint8 newMax, int lfoNum) {
	jassert(newMax <= params::maxUnsyncedLFOfreq);
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
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForLFOs);
	jassert(lfoNum > 0 && lfoNum < 5);
	auto noteIsAllowed{ noteIsAllowedForLFO(pitchNum % 12, lfoNum) };
	auto octaveIsAllowed{ octaveIsAllowedForLFO(pitchNum / 12, lfoNum) };
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
