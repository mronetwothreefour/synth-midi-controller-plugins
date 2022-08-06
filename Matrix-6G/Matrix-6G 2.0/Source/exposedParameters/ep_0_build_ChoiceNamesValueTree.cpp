#include "ep_0_build_ChoiceNamesValueTree.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;

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

ValueTree ExposedParamChoiceNamesValueTree::buildForOscPitch(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
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

ValueTree ExposedParamChoiceNamesValueTree::buildForOscType(const int oscNum, const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != oscNum == 1 ? 4 : 5; ++choiceNum) {
        String choiceName{ "" };
        if (choiceNum == 0)
            choiceName = verbose ? "Off" : "OFF";
        if (choiceNum == 1)
            choiceName = verbose ? "Pulse" : "PULSE";
        if (choiceNum == 2)
            choiceName = verbose ? "Wave (Saw/Triangle)" : "WAVE";
        if (choiceNum == 3)
            choiceName = verbose ? "Both" : "BOTH";
        if (choiceNum == 4)
            choiceName = verbose ? "Noise" : "NOISE";
        choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOsc_1_Sync(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != 4; ++choiceNum) {
        String choiceName{ "" };
        if (choiceNum == 0)
            choiceName = verbose ? "Off (0)" : "OFF";
        if (choiceNum == 1)
            choiceName = verbose ? "Soft Sync (1)" : "SOFT";
        if (choiceNum == 2)
            choiceName = verbose ? "Medium Sync (2)" : "MED";
        if (choiceNum == 3)
            choiceName = verbose ? "Hard Sync (3)" : "HARD";
        choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForSigned_6_BitValue(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != 63; ++choiceNum) {
        auto choiceName{ (choiceNum > 31 ? "+" : "") + String(choiceNum - 31) };
        choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForSigned_7_BitValue(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != 127; ++choiceNum) {
        auto choiceName{ (choiceNum > 63 ? "+" : "") + String(choiceNum - 63) };
        choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForUnsignedValue(const int numberOfChoices, const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != numberOfChoices; ++choiceNum) {
        auto choiceName{ (String)choiceNum };
        choiceNamesTree.setProperty("choice_" + choiceName, choiceName, nullptr);
    }
    return choiceNamesTree;
}

