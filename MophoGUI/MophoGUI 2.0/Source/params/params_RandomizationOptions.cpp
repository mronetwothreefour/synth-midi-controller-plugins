#include "params_RandomizationOptions.h"

#include "params_Constants.h"
#include "params_Identifiers.h"
#include "params_ExposedParamsInfo_Singleton.h"
#include "../randomization/randomization_Constants.h"

using namespace constants;



RandomizationOptions::RandomizationOptions() :
	paramLocksTree{ ID::randomization_ParamLocks },
	allowedPitchesTree{ ID::randomization_AllowedPitches },
	allowedValueRangesTree{ ID::randomization_AllowedValueRanges },
	allowedFrequencyTypesTree{ ID::randomization_AllowedFrequencyTypes },
	seqTrackOptionsTree{ ID::randomization_SeqTrackOptions }
{
	fillAllRandomizationOptionsTreesWithProperties();
}

void RandomizationOptions::fillAllRandomizationOptionsTreesWithProperties() {
	for (uint8 param = 0; param != params::numberOfExposedParams; ++param) {
		setParamIsUnlocked(param);
		auto& info{ InfoForExposedParameters::get() };
		auto optionsType{ info.randomizationOptionsTypeFor(param) };
		if (optionsType == RandomizationOptionsType::pitch) {
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
				setNoteIsAllowedForParam(noteNum, param);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctaves; ++octaveNum)
				setOctaveIsAllowedForParam(octaveNum, param);
		}
		if (optionsType == RandomizationOptionsType::valueRange) {
			setMinValueAllowedForParam((uint8)0, param);
			setMaxValueAllowedForParam(info.maxValueFor(param), param);
		}
		if (optionsType == RandomizationOptionsType::lfoFreq) {
			setUnsyncedFreqAreAllowedForParam(param);
			setPitchedFreqAreAllowedForParam(param);
			setSyncedFreqAreAllowedForParam(param);
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
				setNoteIsAllowedForParam(noteNum, param);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
				setOctaveIsAllowedForParam(octaveNum, param);
			setMinUnsyncedFreqForParam((uint8)0, param);
			setMaxUnsyncedFreqForParam(params::maxUnsyncedLFOfreq, param);
			for (auto syncedFreqNum = 0; syncedFreqNum != randomization::numberOfSyncedFreqForLFOs; ++syncedFreqNum)
				setSyncedFreqIsAllowedForParam(syncedFreqNum, param);
		}
		if (optionsType == RandomizationOptionsType::sequencerTrackStep) {
			for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum)
				setNoteIsAllowedForParam(noteNum, param);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
				setOctaveIsAllowedForParam(octaveNum, param);
			setMinValueAllowedForParam((uint8)0, param);
			setMaxValueAllowedForParam(params::maxValueForSeqTrackStep, param);
		}
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

const bool RandomizationOptions::noteIsAllowedForParam(int noteNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert(optionsType == RandomizationOptionsType::sequencerTrackStep ?
		noteNum < randomization::numberOfNotesAndBentNotes : noteNum < randomization::numberOfNotes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)allowedPitchesTree.getProperty("note" + String(noteNum) + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setNoteIsAllowedForParam(int noteNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert(optionsType == RandomizationOptionsType::sequencerTrackStep ?
		noteNum < randomization::numberOfNotesAndBentNotes : noteNum < randomization::numberOfNotes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("note" + String(noteNum) + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForParam(int noteNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert(optionsType == RandomizationOptionsType::sequencerTrackStep ?
		noteNum < randomization::numberOfNotesAndBentNotes : noteNum < randomization::numberOfNotes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("note" + String(noteNum) + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	auto numberOfNotes{ optionsType == RandomizationOptionsType::sequencerTrackStep ? 
		randomization::numberOfNotesAndBentNotes : randomization::numberOfNotes };
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != numberOfNotes; ++noteNum) {
		if (noteIsAllowedForParam(noteNum, paramIndex))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForParam(int octaveNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert((optionsType == RandomizationOptionsType::pitch && octaveNum < randomization::numberOfOctaves) ||
		(optionsType == RandomizationOptionsType::lpfFreq && octaveNum < randomization::numberOfOctavesForLPFfreq) ||
		(optionsType == RandomizationOptionsType::lfoFreq && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps) ||
		(optionsType == RandomizationOptionsType::sequencerTrackStep && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps));
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)allowedPitchesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setOctaveIsAllowedForParam(int octaveNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert((optionsType == RandomizationOptionsType::pitch && octaveNum < randomization::numberOfOctaves) ||
		(optionsType == RandomizationOptionsType::lpfFreq && octaveNum < randomization::numberOfOctavesForLPFfreq) ||
		(optionsType == RandomizationOptionsType::lfoFreq && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps) ||
		(optionsType == RandomizationOptionsType::sequencerTrackStep && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps));
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForParam(int octaveNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert((optionsType == RandomizationOptionsType::pitch && octaveNum < randomization::numberOfOctaves) ||
		(optionsType == RandomizationOptionsType::lpfFreq && octaveNum < randomization::numberOfOctavesForLPFfreq) ||
		(optionsType == RandomizationOptionsType::lfoFreq && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps) ||
		(optionsType == RandomizationOptionsType::sequencerTrackStep && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps));
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	int numberOfOctaves{ randomization::numberOfOctaves };
	if (optionsType == RandomizationOptionsType::lpfFreq)
		numberOfOctaves = randomization::numberOfOctavesForLPFfreq;
	if (optionsType == RandomizationOptionsType::lfoFreq || optionsType == RandomizationOptionsType::sequencerTrackStep)
		numberOfOctaves = randomization::numberOfOctavesForLFOfreqAndSeqSteps;
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != numberOfOctaves; ++octaveNum) {
		if (octaveIsAllowedForParam(octaveNum, paramIndex))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyHighestOctaveIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	int numberOfOctaves{ randomization::numberOfOctaves };
	if (optionsType == RandomizationOptionsType::lpfFreq)
		numberOfOctaves = randomization::numberOfOctavesForLPFfreq;
	if (optionsType == RandomizationOptionsType::lfoFreq || optionsType == RandomizationOptionsType::sequencerTrackStep)
		numberOfOctaves = randomization::numberOfOctavesForLFOfreqAndSeqSteps;
	auto highestOctaveIsNotTheOnlyOneAllowed{ (bool)false };
	auto highestOctaveIsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != numberOfOctaves - 1; ++octaveNum) {
		if (octaveIsAllowedForParam(octaveNum, paramIndex))
			return highestOctaveIsNotTheOnlyOneAllowed;
	}
	return highestOctaveIsTheOnlyOneAllowed;
}

const bool RandomizationOptions::pitchIsAllowedForParam(int pitchNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::lfoFreq ||
		optionsType == RandomizationOptionsType::sequencerTrackStep);
	jassert(pitchNum > -1);
	jassert((optionsType == RandomizationOptionsType::pitch && pitchNum < randomization::numberOfPitchesForOscillators) ||
		(optionsType == RandomizationOptionsType::lpfFreq && pitchNum < randomization::numberOfPitchedFreqForLFOs) ||
		(optionsType == RandomizationOptionsType::lfoFreq && pitchNum < randomization::numberOfPitchedFreqForLFOs) ||
		(optionsType == RandomizationOptionsType::sequencerTrackStep && pitchNum < randomization::numberOfPitchesForSeqSteps));
	auto numberOfNotes{ optionsType == RandomizationOptionsType::sequencerTrackStep ?
		randomization::numberOfNotesAndBentNotes : randomization::numberOfNotes };
	auto noteIsAllowed{ noteIsAllowedForParam(pitchNum % numberOfNotes, paramIndex) };
	auto octaveIsAllowed{ octaveIsAllowedForParam(pitchNum / numberOfNotes, paramIndex) };
	return noteIsAllowed && octaveIsAllowed;
}

const uint8 RandomizationOptions::minValueAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	int minValueAllowed{ allowedValueRangesTree.getProperty("minValueAllowedFor_" + paramID) };
	return (uint8)minValueAllowed;
}

void RandomizationOptions::setMinValueAllowedForParam(uint8 newMin, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	allowedValueRangesTree.setProperty("minValueAllowedFor_" + paramID, newMin, nullptr);
}

const uint8 RandomizationOptions::maxValueAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	int maxValueAllowed{ allowedValueRangesTree.getProperty("maxValueAllowedFor_" + paramID) };
	return (uint8)maxValueAllowed;
}

void RandomizationOptions::setMaxValueAllowedForParam(uint8 newMax, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	allowedValueRangesTree.setProperty("maxValueAllowedFor_" + paramID, newMax, nullptr);
}

const bool RandomizationOptions::pitchedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("pitchedFreqAreAllowedFor_" + paramID);
}

void RandomizationOptions::setPitchedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("pitchedFreqAreAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setPitchedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("pitchedFreqAreAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::unsyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("unsyncedFreqAreAllowedFor_" + paramID);
}

void RandomizationOptions::setUnsyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("unsyncedFreqAreAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setUnsyncedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("unsyncedFreqAreAllowedFor_" + paramID, (bool)false, nullptr);
}

const uint8 RandomizationOptions::minUnsyncedFreqForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	int minFreq{ allowedFrequencyTypesTree.getProperty("minUnsyncedFreqFor_" + paramID) };
	return (uint8)minFreq;
}

void RandomizationOptions::setMinUnsyncedFreqForParam(uint8 newMin, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	jassert(newMin <= params::maxUnsyncedLFOfreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("minUnsyncedFreqFor_" + paramID, newMin, nullptr);
}

const uint8 RandomizationOptions::maxUnsyncedFreqForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	int maxFreq{ allowedFrequencyTypesTree.getProperty("maxUnsyncedFreqFor_" + paramID) };
	return (uint8)maxFreq;
}

void RandomizationOptions::setMaxUnsyncedFreqForParam(uint8 newMax, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	jassert(newMax <= params::maxUnsyncedLFOfreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("maxUnsyncedFreqFor_" + paramID, newMax, nullptr);
}

const bool RandomizationOptions::syncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("syncedFreqAreAllowedFor_" + paramID);
}

void RandomizationOptions::setSyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreqAreAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setSyncedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreqAreAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::syncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setSyncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setSyncedFreqIsNotAllowedForParam(int syncedFreqNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noSyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto atLeastOneSyncedFreqIsAllowed{ (bool)false };
	auto noSyncedFreqIsAllowed{ (bool)true };
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		if (syncedFreqIsAllowedForParam(freqNum, paramIndex))
			return atLeastOneSyncedFreqIsAllowed;
	}
	return noSyncedFreqIsAllowed;
}

const bool RandomizationOptions::noFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	if (pitchedFreqAreAllowedForParam(paramIndex) || syncedFreqAreAllowedForParam(paramIndex) || unsyncedFreqAreAllowedForParam(paramIndex))
		return false;
	else
		return true;
}

void RandomizationOptions::addListenerToSeqTrackOptionsTree(ValueTree::Listener* listener) {
	seqTrackOptionsTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromSeqTrackOptionsTree(ValueTree::Listener* listener) {
	seqTrackOptionsTree.removeListener(listener);
}

const bool RandomizationOptions::editModeForSeqTrackIsAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return !(bool)seqTrackOptionsTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

const bool RandomizationOptions::editModeForSeqTrackIsSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setEditModeForSeqTrackToAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

void RandomizationOptions::setEditModeForSeqTrackToSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

const int RandomizationOptions::stepSelectedForEditingInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (int)seqTrackOptionsTree.getProperty("stepSelectedForEditingInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setStepSelectedForEditingInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("stepSelectedForEditingInSeqTrack" + (String)trackNum, stepNum, nullptr);
}

const float RandomizationOptions::probabilityOfRestForAllStepsInSeqTrack1() {
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRestForAllStepsInSeqTrack1") };
	return probability;
}

void RandomizationOptions::setProbabilityOfRestForAllStepsInSeqTrack1(float newProb) {
	seqTrackOptionsTree.setProperty("probabilityOfRestForAllStepsInSeqTrack1", newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRestForSelectedStepInSeqTrack1(int stepNum) {
	jassert(stepNum > 0 && stepNum < 17);
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRestForStep" + (String)stepNum + "_InSeqTrack1") };
	return probability;
}

void RandomizationOptions::setProbabilityOfRestForSelectedStepInSeqTrack1(float newProb, int stepNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	seqTrackOptionsTree.setProperty("probabilityOfRestForStep" + (String)stepNum + "_InSeqTrack1", newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForAllStepsInSeqTrack(int trackNum) {
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRepeatValueForAllStepsInSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatForAllStepsInSeqTrack(float newProb, int trackNum) {
	seqTrackOptionsTree.setProperty("probabilityOfRepeatValueForAllStepsInSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRepeatValueForStep" + (String)stepNum + "_InSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatValueForSelectedStepInSeqTrack(float newProb, int stepNum, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("probabilityOfRepeatValueForStep" + (String)stepNum + "_InSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForAllStepsInSeqTrack(int trackNum) {
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRestForAllStepsInSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum) {
	seqTrackOptionsTree.setProperty("probabilityOfRestForAllStepsInSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForSelectedStepInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfResetForStep" + (String)stepNum + "_InSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForSelectedStepInSeqTrack(float newProb, int stepNum, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("probabilityOfResetForStep" + (String)stepNum + "_InSeqTrack" + (String)trackNum, newProb, nullptr);
}

const uint8 RandomizationOptions::minValueForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	int minValue{ seqTrackOptionsTree.getProperty("minValueForAllStepsInSeqTrack" + (String)trackNum) };
	return (uint8)minValue;
}

void RandomizationOptions::setMinValueForAllStepsInSeqTrack(uint8 newMin, int trackNum) {
	jassert(newMin <= params::maxValueForSeqTrackStep);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("minValueForAllStepsInSeqTrack" + (String)trackNum, newMin, nullptr);
}

const uint8 RandomizationOptions::maxValueForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	int maxValue{ seqTrackOptionsTree.getProperty("maxValueForAllStepsInSeqTrack" + (String)trackNum) };
	return (uint8)maxValue;
}

void RandomizationOptions::setMaxValueForAllStepsInSeqTrack(uint8 newMax, int trackNum) {
	jassert(newMax <= params::maxValueForSeqTrackStep);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("maxValueForAllStepsInSeqTrack" + (String)trackNum, newMax, nullptr);
}

const bool RandomizationOptions::pitchIsAllowedForAllStepsInSeqTrack(int pitchNum, int trackNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	auto noteIsAllowed{ noteIsAllowedForAllStepsInSeqTrack(pitchNum % (randomization::numberOfNotesAndBentNotes), trackNum) };
	auto octaveIsAllowed{ octaveIsAllowedForAllStepsInSeqTrack(pitchNum / (randomization::numberOfNotesAndBentNotes), trackNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(noteNum > -1 && noteNum < (randomization::numberOfNotesAndBentNotes));
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("note" + String(noteNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setNoteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("note" + String(noteNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("note" + String(noteNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
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

const bool RandomizationOptions::octaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("octave" + String(octaveNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setOctaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("octave" + String(octaveNum) + "_IsAllowedForAllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum) {
		if (octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::onlyHighestOctaveIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto octave5_IsNotTheOnlyOneAllowed{ (bool)false };
	auto octave5_IsTheOnlyOneAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps - 1; ++octaveNum) {
		if (octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum))
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

	auto allowedPitchesTreeStateXml{ allowedPitchesTree.createXml() };
	if (allowedPitchesTreeStateXml != nullptr) {
		allowedPitchesTreeStateXml->setTagName(ID::randomization_AllowedPitches);
		randomizationOptionsStateXml->addChildElement(allowedPitchesTreeStateXml.release());
	}

	auto allowedValueRangesTreeStateXml{ allowedValueRangesTree.createXml() };
	if (allowedValueRangesTreeStateXml != nullptr) {
		allowedValueRangesTreeStateXml->setTagName(ID::randomization_AllowedValueRanges);
		randomizationOptionsStateXml->addChildElement(allowedValueRangesTreeStateXml.release());
	}

	auto allowedFrequencyTypesTreeStateXml{ allowedFrequencyTypesTree.createXml() };
	if (allowedFrequencyTypesTreeStateXml != nullptr) {
		allowedFrequencyTypesTreeStateXml->setTagName(ID::randomization_AllowedFrequencyTypes);
		randomizationOptionsStateXml->addChildElement(allowedFrequencyTypesTreeStateXml.release());
	}

	auto seqTrackOptionsTreeStateXml{ seqTrackOptionsTree.createXml() };
	if (seqTrackOptionsTreeStateXml != nullptr) {
		seqTrackOptionsTreeStateXml->setTagName(ID::randomization_SeqTrackOptions);
		randomizationOptionsStateXml->addChildElement(seqTrackOptionsTreeStateXml.release());
	}

	return randomizationOptionsStateXml.release();
}

void RandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid()) {
		auto paramLocksTreeState{ newState.getChildWithName(ID::randomization_ParamLocks) };
		if (paramLocksTreeState.isValid())
			paramLocksTree.copyPropertiesAndChildrenFrom(paramLocksTreeState, nullptr);

		auto allowedPitchesTreeState{ newState.getChildWithName(ID::randomization_AllowedPitches) };
		if (allowedPitchesTreeState.isValid())
			allowedPitchesTree.copyPropertiesAndChildrenFrom(allowedPitchesTreeState, nullptr);

		auto allowedValueRangesTreeState{ newState.getChildWithName(ID::randomization_AllowedValueRanges) };
		if (allowedValueRangesTreeState.isValid())
			allowedValueRangesTree.copyPropertiesAndChildrenFrom(allowedValueRangesTreeState, nullptr);

		auto allowedFrequencyTypesTreeState{ newState.getChildWithName(ID::randomization_AllowedFrequencyTypes) };
		if (allowedFrequencyTypesTreeState.isValid())
			allowedFrequencyTypesTree.copyPropertiesAndChildrenFrom(allowedFrequencyTypesTreeState, nullptr);

		auto seqTrackOptionsTreeState{ newState.getChildWithName(ID::randomization_SeqTrackOptions) };
		if (seqTrackOptionsTreeState.isValid())
			seqTrackOptionsTree.copyPropertiesAndChildrenFrom(seqTrackOptionsTreeState, nullptr);
	}
}
