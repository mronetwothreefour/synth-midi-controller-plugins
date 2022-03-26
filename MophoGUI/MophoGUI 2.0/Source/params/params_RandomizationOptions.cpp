#include "params_RandomizationOptions.h"

#include "params_Constants.h"
#include "params_Identifiers.h"
#include "../randomization/randomization_Constants.h"

using namespace constants;



RandomizationOptions::RandomizationOptions() :
	paramLocksTree{ ID::randomization_ParamLocks },
	osc1AllowedNotesTree{ ID::randomization_Osc1AllowedNotes },
	osc1AllowedOctavesTree{ ID::randomization_Osc1AllowedOctaves },
	osc2AllowedNotesTree{ ID::randomization_Osc2AllowedNotes },
	osc2AllowedOctavesTree{ ID::randomization_Osc2AllowedOctaves }
{
	fillAllRandomizationOptionsTreesWithProperties();
}

void RandomizationOptions::fillAllRandomizationOptionsTreesWithProperties() {
	for (uint8 param = 0; param != params::numberOfExposedParams; ++param)
		paramLocksTree.setProperty("param" + String(param) + "_IsLocked", (bool)false, nullptr);
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		osc1AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)true, nullptr);
		osc2AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)true, nullptr);
	}
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		osc1AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)true, nullptr);
		osc2AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)true, nullptr);
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
	jassert(pitchNum > -1 && pitchNum < 121);
	jassert(oscNum == 1 || oscNum == 2);
	auto noteIsAllowed{ noteIsAllowedForOscillator(pitchNum % 12, oscNum) };
	auto octaveIsAllowed{ octaveIsAllowedForOscillator(pitchNum / 12, oscNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForOscillator(int noteNum, int oscNum) {
	jassert(noteNum > -1 && noteNum < 12);
	jassert(oscNum == 1 || oscNum == 2);
	if (oscNum == 1)
		return (bool)osc1AllowedNotesTree.getProperty("note" + String(noteNum) + "_IsAllowed");
	else
		return (bool)osc2AllowedNotesTree.getProperty("note" + String(noteNum) + "_IsAllowed");
}

void RandomizationOptions::setNoteIsAllowedForOscillator(int noteNum, int oscNum) {
	jassert(noteNum > -1 && noteNum < 12);
	jassert(oscNum == 1 || oscNum == 2);
	if (oscNum == 1)
		osc1AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)true, nullptr);
	else
		osc2AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForOscillator(int noteNum, int oscNum) {
	jassert(noteNum > -1 && noteNum < 12);
	jassert(oscNum == 1 || oscNum == 2);
	if (oscNum == 1)
		osc1AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)false, nullptr);
	else
		osc2AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)false, nullptr);
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
	jassert(octaveNum > -1 && octaveNum < 11);
	jassert(oscNum == 1 || oscNum == 2);
	if (oscNum == 1)
		return (bool)osc1AllowedOctavesTree.getProperty("octave" + String(octaveNum) + "_IsAllowed");
	else
		return (bool)osc2AllowedOctavesTree.getProperty("octave" + String(octaveNum) + "_IsAllowed");
}

void RandomizationOptions::setOctaveIsAllowedForOscillator(int octaveNum, int oscNum) {
	jassert(octaveNum > -1 && octaveNum < 11);
	jassert(oscNum == 1 || oscNum == 2);
	if (oscNum == 1)
		osc1AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)true, nullptr);
	else
		osc2AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForOscillator(int octaveNum, int oscNum) {
	jassert(octaveNum > -1 && octaveNum < 11);
	jassert(oscNum == 1 || oscNum == 2);
	if (oscNum == 1)
		osc1AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)false, nullptr);
	else
		osc2AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)false, nullptr);
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
