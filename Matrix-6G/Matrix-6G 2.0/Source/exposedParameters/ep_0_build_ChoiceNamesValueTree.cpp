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

ValueTree ExposedParamChoiceNamesValueTree::buildForEnvMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Normal" : "NORMAL", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Delay-Attack-Decay-Release" : "DADR", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Free Run" : "FREE", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Both DADR & Free Run" : "BOTH", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForEnvTrigMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Single Trigger" : "STRIG", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Single Trigger Reset" : "SRESET", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Multiple Trigger" : "MTRIG", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Multiple Trigger Reset" : "MRESET", nullptr);
    choiceNamesTree.setProperty("choice_4", verbose ? "Ext. Single Trigger" : "XTRIG", nullptr);
    choiceNamesTree.setProperty("choice_5", verbose ? "Ext. Single Trigger Reset" : "XRESET", nullptr);
    choiceNamesTree.setProperty("choice_6", verbose ? "Ext. Multiple Trigger" : "XMTRIG", nullptr);
    choiceNamesTree.setProperty("choice_7", verbose ? "Ext. Multiple Trigger Reset" : "XMRST", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForEnv_LFO_1_Trig(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Normal (No LFO 1 Trigger)" : "NORMAL", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Gated LFO 1 Trigger" : "G-LFO1", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "LFO 1 Trigger" : "LFO 1", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForKeyboardMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Reassign" : "REASGN", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Rotate" : "ROTATE", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Unison" : "UNISON", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Reassign Rob" : "REAROB", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForLeverControl(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Off" : "OFF", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Pitch Bend by Lever 1" : "BEND", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Vibrato by Lever 2" : "VIB", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Modulated by Both Levers" : "BOTH", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForModSource(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "None" : "NONE", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Envelope 1" : "ENV 1", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Envelope 2" : "ENV 2", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Envelope 3" : "ENV 3", nullptr);
    choiceNamesTree.setProperty("choice_4", verbose ? "LFO 1" : "LFO 1", nullptr);
    choiceNamesTree.setProperty("choice_5", verbose ? "LFO 2" : "LFO 2", nullptr);
    choiceNamesTree.setProperty("choice_6", verbose ? "Vibrato LFO" : "VIBRATO", nullptr);
    choiceNamesTree.setProperty("choice_7", verbose ? "Ramp Generator 1" : "RAMP 1", nullptr);
    choiceNamesTree.setProperty("choice_8", verbose ? "Ramp Generator 2" : "RAMP 2", nullptr);
    choiceNamesTree.setProperty("choice_9", verbose ? "Keyboard Scaling" : "KEYBD", nullptr);
    choiceNamesTree.setProperty("choice_10", verbose ? "Portamento Speed" : "PORTA", nullptr);
    choiceNamesTree.setProperty("choice_11", verbose ? "Tracking Generator" : "TRACK", nullptr);
    choiceNamesTree.setProperty("choice_12", verbose ? "Keyboard Note Gate" : "GATE", nullptr);
    choiceNamesTree.setProperty("choice_13", verbose ? "Keyboard Note Velocity" : "VELO", nullptr);
    choiceNamesTree.setProperty("choice_14", verbose ? "Keyboard Release Velocity" : "R VELO", nullptr);
    choiceNamesTree.setProperty("choice_15", verbose ? "Keyboard Pressure (Aftertouch)" : "PRESS", nullptr);
    choiceNamesTree.setProperty("choice_16", verbose ? "Pedal 1" : "PEDAL 1", nullptr);
    choiceNamesTree.setProperty("choice_17", verbose ? "Pedal 2" : "PEDAL 2", nullptr);
    choiceNamesTree.setProperty("choice_18", verbose ? "Lever 1" : "LEVER 1", nullptr);
    choiceNamesTree.setProperty("choice_19", verbose ? "Lever 2" : "LEVER 2", nullptr);
    choiceNamesTree.setProperty("choice_20", verbose ? "Lever 3 (Lever 2 Reverse)" : "LEVER 3", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOffOn(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Off" : "OFF", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "On" : "ON", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOscPitch(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscPitch; ++choiceNum) {
        String choiceName{ "" };
        if (verbose)
            choiceName = convertIntToPitchName(choiceNum) + " (MIDI Note " + String(choiceNum) + ")";
        else
            choiceName = convertIntToPitchName(choiceNum);
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

ValueTree ExposedParamChoiceNamesValueTree::buildForOsc_1_KeyTrack(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Normal Key Tracking" : "KEYBD", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Key Tracking With Portamento" : "PORTA", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOsc_1_Sync(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Off (0)" : "OFF", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Soft Sync (1)" : "SOFT", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Medium Sync (2)" : "MED", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Hard Sync (3)" : "HARD", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOsc_2_And_VCF_KeyTrack(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Key Tracking Is Off" : "OFF", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Key Tracking With Portamento" : "PORTA", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Normal Key Tracking" : "KEYBD", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForPortaMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Linear" : "LINEAR", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Constant Time" : "CONST", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Exponential" : "EXPO", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForRampTrig(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Single Trigger" : "STRIG", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Multiple Trigger" : "MTRIG", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "External Single Trigger" : "XTRIG", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Gated External Single Trigger" : "GATEX", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LFO_SampleSource(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "None" : "NONE", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Envelope 1" : "ENV1", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Envelope 2" : "ENV2", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Envelope 3" : "ENV3", nullptr);
    choiceNamesTree.setProperty("choice_4", verbose ? "LFO 1" : "LFO1", nullptr);
    choiceNamesTree.setProperty("choice_5", verbose ? "LFO 2" : "LFO2", nullptr);
    choiceNamesTree.setProperty("choice_6", verbose ? "Vibrato LFO" : "VIB", nullptr);
    choiceNamesTree.setProperty("choice_7", verbose ? "Ramp Generator 1" : "RMP1", nullptr);
    choiceNamesTree.setProperty("choice_8", verbose ? "Ramp Generator 2" : "RMP2", nullptr);
    choiceNamesTree.setProperty("choice_9", verbose ? "Keyboard Scaling" : "KEYB", nullptr);
    choiceNamesTree.setProperty("choice_10", verbose ? "Portamento Speed" : "PORT", nullptr);
    choiceNamesTree.setProperty("choice_11", verbose ? "Tracking Generator" : "TRAK", nullptr);
    choiceNamesTree.setProperty("choice_12", verbose ? "Keyboard Note Gate" : "GATE", nullptr);
    choiceNamesTree.setProperty("choice_13", verbose ? "Keyboard Note Velocity" : "VEL", nullptr);
    choiceNamesTree.setProperty("choice_14", verbose ? "Keyboard Release Velocity" : "RVEL", nullptr);
    choiceNamesTree.setProperty("choice_15", verbose ? "Keyboard Pressure (Aftertouch)" : "PRES", nullptr);
    choiceNamesTree.setProperty("choice_16", verbose ? "Pedal 1" : "PED1", nullptr);
    choiceNamesTree.setProperty("choice_17", verbose ? "Pedal 2" : "PED2", nullptr);
    choiceNamesTree.setProperty("choice_18", verbose ? "Lever 1" : "LEV1", nullptr);
    choiceNamesTree.setProperty("choice_19", verbose ? "Lever 2" : "LEV2", nullptr);
    choiceNamesTree.setProperty("choice_20", verbose ? "Lever 3 (Lever 2 Reverse)" : "LEV3", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LFO_TrigMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Off (Free Running)" : "OFF", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Single Trigger" : "STRIG", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Multiple Trigger" : "MTRIG", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "External Single Trigger" : "XTRIG", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LFO_WaveType(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("choice_0", verbose ? "Triangle" : "TRI", nullptr);
    choiceNamesTree.setProperty("choice_1", verbose ? "Up (Rising) Sawtooth" : "UPSAW", nullptr);
    choiceNamesTree.setProperty("choice_2", verbose ? "Down (Falling) Sawtooth" : "DNSAW", nullptr);
    choiceNamesTree.setProperty("choice_3", verbose ? "Square" : "SQUAR", nullptr);
    choiceNamesTree.setProperty("choice_4", verbose ? "Random" : "RANDM", nullptr);
    choiceNamesTree.setProperty("choice_5", verbose ? "Noise" : "NOISE", nullptr);
    choiceNamesTree.setProperty("choice_6", verbose ? "Sampled" : "SAMPL", nullptr);
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

