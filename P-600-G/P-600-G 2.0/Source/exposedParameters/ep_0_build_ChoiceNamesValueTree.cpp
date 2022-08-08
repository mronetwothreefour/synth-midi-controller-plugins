#include "ep_0_build_ChoiceNamesValueTree.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace P_600_G_Constants;

String ExposedParamChoiceNamesValueTree::convertIntToPitchName(const uint8& i) noexcept {
    auto noteNum{ i % 12 };
    auto octaveNumString{ String(i / 12) };
    String pitchName;
    switch (noteNum) {
    case 0: return "C " + octaveNumString;
    case 1: return "C# " + octaveNumString;
    case 2: return "D " + octaveNumString;
    case 3: return "D# " + octaveNumString;
    case 4: return "E " + octaveNumString;
    case 5: return "F " + octaveNumString;
    case 6: return "F# " + octaveNumString;
    case 7: return "G " + octaveNumString;
    case 8: return "G# " + octaveNumString;
    case 9: return "A " + octaveNumString;
    case 10: return "A# " + octaveNumString;
    case 11: return "B " + octaveNumString;
    default: return "ERR";
    }
}

ValueTree ExposedParamChoiceNamesValueTree::buildForFilterKeyTrack(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", "Off", nullptr);
    choiceNamesTree.setProperty("choice_1", "1/2", nullptr);
    choiceNamesTree.setProperty("choice_1", "Full", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForLFO_Shape(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", "Square", nullptr);
    choiceNamesTree.setProperty("choice_1", "Triangle", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOffOn(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", "Off", nullptr);
    choiceNamesTree.setProperty("choice_1", "On", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOscFreq(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscFreq; ++choiceNum) {
        String choiceName{ "" };
        if (verbose)
            choiceName = convertIntToPitchName(choiceNum) + " (MIDI Note " + String(choiceNum) + ")";
        else
            choiceName = convertIntToPitchName(choiceNum);
        choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForPlainValue(const uint8 numberOfChoices, bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != numberOfChoices; ++choiceNum) {
        auto choiceName{ (String)choiceNum };
        choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}
