#include "params_build_ChoiceNamesValueTree.h"



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

ValueTree ChoiceNamesValueTree::buildFor_OscPitch() {
	ValueTree choiceNamesTree{ "choiceNames" };
	const int numberOfOscPitchChoices{ 121 };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfOscPitchChoices; ++choiceNum)
		choiceNamesTree.setProperty(
			"choice_" + (String)choiceNum,
			convertIntToPitchName(choiceNum),
			nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscPitch_Verbose() {
	ValueTree verboseChoiceNamesTree{ "verboseChoiceNames" };
	const int numberOfOscPitchChoices{ 121 };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfOscPitchChoices; ++choiceNum)
		verboseChoiceNamesTree.setProperty(
			"choice_" + (String)choiceNum,
			convertIntToPitchName(choiceNum) + " (MIDI Note " + String(choiceNum) + ")",
			nullptr);
	return verboseChoiceNamesTree;
}
