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

ValueTree ChoiceNamesValueTree::buildFor_OscFineTune() {
	ValueTree choiceNamesTree{ ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscFineTune; ++choiceNum) {
		auto choiceName{ choiceNum < 51 ? (String)(choiceNum - 50) : "+" + (String)(choiceNum - 50) };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscFineTune_Verbose() {
	ValueTree verboseChoiceNamesTree{ ID::choiceNames_Verbose };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscFineTune; ++choiceNum) {
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
		verboseChoiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return verboseChoiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscPitch() {
	ValueTree choiceNamesTree{ ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscPitch; ++choiceNum)
		choiceNamesTree.setProperty(
			"choice_" + (String)choiceNum,
			convertIntToPitchName(choiceNum),
			nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscPitch_Verbose() {
	ValueTree verboseChoiceNamesTree{ ID::choiceNames_Verbose };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscPitch; ++choiceNum)
		verboseChoiceNamesTree.setProperty(
			"choice_" + (String)choiceNum,
			convertIntToPitchName(choiceNum) + " (MIDI Note " + String(choiceNum) + ")",
			nullptr);
	return verboseChoiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscShape() {
	ValueTree choiceNamesTree{ ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscWaveShape; ++choiceNum) {
		String choiceName{ "" };
		if (choiceNum == 0)
			choiceName = "Off";
		if (choiceNum == 1)
			choiceName = "Saw";
		if (choiceNum == 2)
			choiceName = "Tri";
		if (choiceNum == 3)
			choiceName = "Saw/Tri";
		if (choiceNum > 3)
			choiceName = "PW " + String(choiceNum - 4);
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscShape_Verbose() {
	ValueTree verboseChoiceNamesTree{ ID::choiceNames_Verbose };
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscWaveShape; ++choiceNum) {
		String choiceName{ "" };
		if (choiceNum == 0)
			choiceName = "Oscillator Off";
		if (choiceNum == 1)
			choiceName = "Sawtooth";
		if (choiceNum == 2)
			choiceName = "Triangle";
		if (choiceNum == 3)
			choiceName = "Sawtooth/Triangle Mix";
		if (choiceNum > 3)
			choiceName = "Pulse (Width: " + String(choiceNum - 4) + ")";
		verboseChoiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return verboseChoiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_PlainValue(uint8 numberOfChoices) {
	ValueTree choiceNamesTree{ ID::choiceNames };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum) {
		auto choiceName{ (String)choiceNum };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_PlainValue_Verbose(uint8 numberOfChoices) {
	ValueTree verboseChoiceNamesTree{ ID::choiceNames_Verbose };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum) {
		auto choiceName{ (String)choiceNum };
		verboseChoiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return verboseChoiceNamesTree;
}
