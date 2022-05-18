#include "ep_build_ChoiceNamesValueTree.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace mophoConstants;



String ChoiceNamesValueTree::convertIntToPitchName(const uint8& i) noexcept {
	auto noteNum{ i % 12 };
	auto octaveNum{ i / 12 };
	String pitchName;
	switch (noteNum) {
	case 0: return "C " + (String)octaveNum;
	case 1: return "C# " + (String)octaveNum;
	case 2: return "D " + (String)octaveNum;
	case 3: return "D# " + (String)octaveNum;
	case 4: return "E " + (String)octaveNum;
	case 5: return "F " + (String)octaveNum;
	case 6: return "F# " + (String)octaveNum;
	case 7: return "G " + (String)octaveNum;
	case 8: return "G# " + (String)octaveNum;
	case 9: return "A " + (String)octaveNum;
	case 10: return "A# " + (String)octaveNum;
	case 11: return "B " + (String)octaveNum;
	default: return "invalid";
	}
}

ValueTree ChoiceNamesValueTree::buildFor_BendRange(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForBendRange; ++choiceNum) {
		if (verbose) {
			String choiceName{ "" };
			if (choiceNum == 0) 
				choiceName = "No Bend";
			if (choiceNum == 1) 
				choiceName = "+/-1 semitone";
			if (choiceNum > 1)
				choiceName = "+/-" + (String)choiceNum + " semitones";
			choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
		}
		else {
			String choiceName{ "" };
			if (choiceNum == 0)
				choiceName = "0";
			else
				choiceName = "+/-" + (String)choiceNum;
			choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
		}
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_GildeMode(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Fixed Rate", nullptr);
	choiceNamesTree.setProperty("choice_1", "Fixed Rate Auto", nullptr);
	choiceNamesTree.setProperty("choice_2", "Fixed Time", nullptr);
	choiceNamesTree.setProperty("choice_3", "Fixed Time Auto", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_LPF_Freq(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForLPF_Freq; ++choiceNum) {
		auto choiceNumString{ (String)choiceNum };
		auto pitchString{ convertIntToPitchName(choiceNum) };
		auto choiceName{ verbose ? choiceNumString + " (Pitch Freq. " + pitchString + ")" : pitchString };
		choiceNamesTree.setProperty("choice_" + choiceNumString, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_NotePriority(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", verbose ? "Low Note Has Priority" : "Low Note", nullptr);
	choiceNamesTree.setProperty("choice_1", verbose ? "Low Note Has Priority (Re-trigger)" : "Low Note (Re-trigger)", nullptr);
	choiceNamesTree.setProperty("choice_2", verbose ? "High Note Has Priority" : "High Note", nullptr);
	choiceNamesTree.setProperty("choice_3", verbose ? "High Note Has Priority (Re-trigger)" : "High Note (Re-trigger)", nullptr);
	choiceNamesTree.setProperty("choice_4", verbose ? "Last Note Hit Has Priority" : "Last Note", nullptr);
	choiceNamesTree.setProperty("choice_5", verbose ? "Last Note Hit Has Priority (Re-trigger)" : "Last Note (Re-trigger)", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OffOn(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != 2; ++choiceNum) {
		auto choiceName{ choiceNum == 0 ? "Off" : "On" };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscFineTune(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscFineTune; ++choiceNum) {
		if (verbose) {
			String choiceName{ "" };
			if (choiceNum < 49)
				choiceName = (String)(choiceNum - 50) + " cents";
			if (choiceNum == 49)
				choiceName = "-1 cent";
			if (choiceNum == 50)
				choiceName = "No Detune";
			if (choiceNum == 51)
				choiceName = "+1 cent";
			if (choiceNum > 51)
				choiceName = "+" + (String)(choiceNum - 50) + " cents";
			choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
		}
		else {
			auto choiceName{ choiceNum < 51 ? (String)(choiceNum - 50) : "+" + (String)(choiceNum - 50) };
			choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
		}
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscPitch(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscPitch; ++choiceNum) {
		String choiceName{ "" };
		if (verbose) {
			choiceName = convertIntToPitchName(choiceNum) + " (MIDI Note " + String(choiceNum) + ")";
		}
		else {
			choiceName = convertIntToPitchName(choiceNum);
		}
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscShape(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscWaveShape; ++choiceNum) {
		String choiceName{ "" };
		if (choiceNum == 0)
			choiceName = verbose ? "Oscillator Off" : "Off";
		if (choiceNum == 1)
			choiceName = verbose ? "Sawtooth" : "Saw";
		if (choiceNum == 2)
			choiceName = verbose ? "Triangle" : "Tri";
		if (choiceNum == 3)
			choiceName = verbose ? "Sawtooth/Triangle Mix"  : "Saw/Tri";
		if (choiceNum > 3)
			choiceName = verbose ? "Pulse (Width: " + String(choiceNum - 4) + ")"  : "PW " + String(choiceNum - 4);
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_PlainValue(uint8 numberOfChoices, bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum) {
		auto choiceName{ (String)choiceNum };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

