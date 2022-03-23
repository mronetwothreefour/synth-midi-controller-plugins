#include "params_RandomizationOptions.h"

#include "params_Constants.h"
#include "params_Identifiers.h"

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
	for (auto noteNum = 0; noteNum != 12; ++noteNum) {
		osc1AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)true, nullptr);
		osc2AllowedNotesTree.setProperty("note" + String(noteNum) + "_IsAllowed", (bool)true, nullptr);
	}
	for (auto octaveNum = 0; octaveNum != 11; ++octaveNum) {
		osc1AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)true, nullptr);
		osc2AllowedOctavesTree.setProperty("octave" + String(octaveNum) + "_IsAllowed", (bool)true, nullptr);
	}
}

const bool RandomizationOptions::paramIsLocked(uint8 param) {
	return (bool)paramLocksTree.getProperty("param" + String(param) + "_IsLocked");
}

void RandomizationOptions::setParamIsLocked(uint8 param) {
	paramLocksTree.setProperty("param" + String(param) + "_IsLocked", (bool)true, nullptr);
}

void RandomizationOptions::setParamIsUnlocked(uint8 param) {
	paramLocksTree.setProperty("param" + String(param) + "_IsLocked", (bool)false, nullptr);
}
