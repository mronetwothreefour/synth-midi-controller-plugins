#include "ep_0_build_ChoiceNamesValueTree.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;

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

String ExposedParamChoiceNamesValueTree::convertIntToSeqStepPitchName(const uint8& i) noexcept {
    auto noteNum{ i % 24 };
    auto octaveNumString{ String(i / 24) };
    switch (noteNum)
    {
    case 0: return "C" + octaveNumString;
    case 1: return "C" + octaveNumString + "+";
    case 2: return "C#" + octaveNumString;
    case 3: return "C#" + octaveNumString + "+";
    case 4: return "D" + octaveNumString;
    case 5: return "D" + octaveNumString + "+";
    case 6: return "D#" + octaveNumString;
    case 7: return "D#" + octaveNumString + "+";
    case 8: return "E" + octaveNumString;
    case 9: return "E" + octaveNumString + "+";
    case 10: return "F" + octaveNumString;
    case 11: return "F" + octaveNumString + "+";
    case 12: return "F#" + octaveNumString;
    case 13: return "F#" + octaveNumString + "+";
    case 14: return "G" + octaveNumString;
    case 15: return "G" + octaveNumString + "+";
    case 16: return "G#" + octaveNumString;
    case 17: return "G#" + octaveNumString + "+";
    case 18: return "A" + octaveNumString;
    case 19: return "A" + octaveNumString + "+";
    case 20: return "A#" + octaveNumString;
    case 21: return "A#" + octaveNumString + "+";
    case 22: return "B" + octaveNumString;
    case 23: return "B" + octaveNumString + "+";
    default: return "ERR";
    }
}

ValueTree ExposedParamChoiceNamesValueTree::buildForArpegMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "1 Octave Up", nullptr);
    choiceNamesTree.setProperty("1", "1 Octave Down", nullptr);
    choiceNamesTree.setProperty("2", "1 Octave Up & Down", nullptr);
    choiceNamesTree.setProperty("3", "1 Octave Assign", nullptr);
    choiceNamesTree.setProperty("4", "1 Octave Random", nullptr);
    choiceNamesTree.setProperty("5", "2 Octaves Up", nullptr);
    choiceNamesTree.setProperty("6", "2 Octaves Down", nullptr);
    choiceNamesTree.setProperty("7", "2 Octaves Up & Down", nullptr);
    choiceNamesTree.setProperty("8", "2 Octaves Assign", nullptr);
    choiceNamesTree.setProperty("9", "2 Octaves Random", nullptr);
    choiceNamesTree.setProperty("10", "3 Octaves Up", nullptr);
    choiceNamesTree.setProperty("11", "3 Octaves Down", nullptr);
    choiceNamesTree.setProperty("12", "3 Octaves Up & Down", nullptr);
    choiceNamesTree.setProperty("13", "3 Octaves Assign", nullptr);
    choiceNamesTree.setProperty("14", "3 Octaves Random", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForBendRange(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForBendRange; ++choiceNum) {
        if (verbose) {
            String choiceName{ "" };
            if (choiceNum == 0)
                choiceName = "No Bend";
            if (choiceNum == 1)
                choiceName = "+/-1 semitone";
            if (choiceNum > 1)
                choiceName = "+/-" + (String)choiceNum + " semitones";
            choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
        }
        else {
            String choiceName{ "" };
            if (choiceNum == 0)
                choiceName = "0";
            else
                choiceName = "+/-" + (String)choiceNum;
            choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
        }
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForClockDivision(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", verbose ? "Half Note (BPM / 2)" : "Half Note", nullptr);
    choiceNamesTree.setProperty("1", verbose ? "Quarter Note (BPM x 1)" : "Quarter Note", nullptr);
    choiceNamesTree.setProperty("2", verbose ? "8th Note (BPM x 2)" : "8th Note", nullptr);
    choiceNamesTree.setProperty("3", verbose ? "8th Note, 1/2 Swing (BPM x 2)" : "8th Note, 1/2 Swing", nullptr);
    choiceNamesTree.setProperty("4", verbose ? "8th Note, Full Swing (BPM x 2)" : "8th Note, Full Swing", nullptr);
    choiceNamesTree.setProperty("5", verbose ? "8th Note Triplets (BPM x 3)" : "8th Note Triplets", nullptr);
    choiceNamesTree.setProperty("6", verbose ? "16th Note (BPM x 4)" : "16th Note", nullptr);
    choiceNamesTree.setProperty("7", verbose ? "16th Note, 1/2 Swing (BPM x 4)" : "16th Note, 1/2 Swing", nullptr);
    choiceNamesTree.setProperty("8", verbose ? "16th Note, Full Swing (BPM x 4)" : "16th Note, Full Swing", nullptr);
    choiceNamesTree.setProperty("9", verbose ? "16th Note Triplets (BPM x 6)" : "16th Note Triplets", nullptr);
    choiceNamesTree.setProperty("10", verbose ? "32nd Note (BPM x 8)" : "32nd Note", nullptr);
    choiceNamesTree.setProperty("11", verbose ? "32nd Note Triplets (BPM x 12)" : "32nd Note Triplets", nullptr);
    choiceNamesTree.setProperty("12", verbose ? "64th Note Triplets (BPM x 24)" : "64th Note Triplets", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForClockTempo(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForClockTempo; ++choiceNum) {
        auto choiceName{ String(choiceNum + 30) };
        if (verbose)
            choiceName += " BPM";
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForGlideMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Fixed Rate", nullptr);
    choiceNamesTree.setProperty("1", "Fixed Rate Auto", nullptr);
    choiceNamesTree.setProperty("2", "Fixed Time", nullptr);
    choiceNamesTree.setProperty("3", "Fixed Time Auto", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForKnobAssign(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto oscNum = 1; oscNum != 3; ++oscNum) {
        choiceNamesTree.setProperty(oscNum == 1 ? "0" : "6", "Oscillator " + (String)oscNum + " Pitch", nullptr);
        choiceNamesTree.setProperty(oscNum == 1 ? "1" : "7", "Oscillator " + (String)oscNum + " Fine Tune", nullptr);
        choiceNamesTree.setProperty(oscNum == 1 ? "2" : "8", "Oscillator " + (String)oscNum + " Wave Shape", nullptr);
        choiceNamesTree.setProperty(oscNum == 1 ? "3" : "9", "Oscillator " + (String)oscNum + " Glide Rate", nullptr);
        choiceNamesTree.setProperty(oscNum == 1 ? "4" : "10", "Oscillator " + (String)oscNum + " Key Track", nullptr);
        choiceNamesTree.setProperty(oscNum == 1 ? "5" : "11", "Sub-Oscillator " + (String)oscNum + " Level", nullptr);
    }
    choiceNamesTree.setProperty("12", "Hard Sync Oscillators", nullptr);
    choiceNamesTree.setProperty("13", "Glide Mode", nullptr);
    choiceNamesTree.setProperty("14", "Oscillator Slop", nullptr);
    choiceNamesTree.setProperty("15", "Pitch Bend Range", nullptr);
    choiceNamesTree.setProperty("16", "Keyed Note Priority", nullptr);
    choiceNamesTree.setProperty("17", "Oscillators 1 & 2 Mix", nullptr);
    choiceNamesTree.setProperty("18", "Noise Level", nullptr);
    choiceNamesTree.setProperty("19", "External Audio " + String(verbose ? "Input Level" : "In Level"), nullptr);
    choiceNamesTree.setProperty("20", "LPF Cutoff Frequency", nullptr);
    choiceNamesTree.setProperty("21", "LPF Resonance", nullptr);
    choiceNamesTree.setProperty("22", "LPF Keyboard Amount", nullptr);
    choiceNamesTree.setProperty("23", "LPF Freq. Mod. Amount", nullptr);
    choiceNamesTree.setProperty("24", "LPF 2- or 4-Pole Select", nullptr);
    choiceNamesTree.setProperty("25", "LPF Envelope Amount", nullptr);
    choiceNamesTree.setProperty("26", verbose ? "LPF Envelope Velocity Amount" : "LPF Env Vel Amt", nullptr);
    choiceNamesTree.setProperty("27", "LPF Envelope Delay", nullptr);
    choiceNamesTree.setProperty("28", "LPF Envelope Attack", nullptr);
    choiceNamesTree.setProperty("29", "LPF Envelope Decay", nullptr);
    choiceNamesTree.setProperty("30", "LPF Envelope Sustain", nullptr);
    choiceNamesTree.setProperty("31", "LPF Envelope Release", nullptr);
    choiceNamesTree.setProperty("32", "VCA Initial Level", nullptr);
    choiceNamesTree.setProperty("33", "VCA Envelope Amount", nullptr);
    choiceNamesTree.setProperty("34", verbose ? "VCA Envelope Velocity Amount" : "VCA Env Vel Amnt", nullptr);
    choiceNamesTree.setProperty("35", "VCA Envelope Delay", nullptr);
    choiceNamesTree.setProperty("36", "VCA Envelope Attack", nullptr);
    choiceNamesTree.setProperty("37", "VCA Envelope Decay", nullptr);
    choiceNamesTree.setProperty("38", "VCA Envelope Sustain", nullptr);
    choiceNamesTree.setProperty("39", "VCA Envelope Release", nullptr);
    choiceNamesTree.setProperty("40", "Voice Volume", nullptr);
    for (auto lfoNum = 0; lfoNum != 4; ++lfoNum) {
        choiceNamesTree.setProperty(String(41 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Frequency", nullptr);
        choiceNamesTree.setProperty(String(42 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Wave Shape", nullptr);
        choiceNamesTree.setProperty(String(43 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Amount", nullptr);
        choiceNamesTree.setProperty(
            String(44 + lfoNum * 5),
            "LFO " + String(lfoNum + 1) + String(verbose ? " Modulation" : " Mod") + " Destination",
            nullptr);
        choiceNamesTree.setProperty(String(45 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Key Sync", nullptr);
    }
    choiceNamesTree.setProperty("61", "Env 3 " + String(verbose ? "Modulation" : "Mod") + " Destination", nullptr);
    choiceNamesTree.setProperty("62", "Envelope 3 Amount", nullptr);
    choiceNamesTree.setProperty("63", "Env 3 Velocity Amount", nullptr);
    choiceNamesTree.setProperty("64", "Envelope 3 Delay", nullptr);
    choiceNamesTree.setProperty("65", "Envelope 3 Attack", nullptr);
    choiceNamesTree.setProperty("66", "Envelope 3 Decay", nullptr);
    choiceNamesTree.setProperty("67", "Envelope 3 Sustain", nullptr);
    choiceNamesTree.setProperty("68", "Envelope 3 Release", nullptr);
    choiceNamesTree.setProperty("69", "Envelope 3 Repeat", nullptr);
    for (auto modNum = 0; modNum != 4; ++modNum) {
        choiceNamesTree.setProperty(String(70 + modNum * 3), "Modulator " + String(modNum + 1) + " Source", nullptr);
        choiceNamesTree.setProperty(String(71 + modNum * 3), "Modulator " + String(modNum + 1) + " Amount", nullptr);
        choiceNamesTree.setProperty(String(72 + modNum * 3), "Modulator " + String(modNum + 1) + " Destination", nullptr);
    }
    choiceNamesTree.setProperty("82", "Modulation Wheel " + String(verbose ? "Amount" : "Amt"), nullptr);
    choiceNamesTree.setProperty("83", "Modulation Wheel " + String(verbose ? "Destination" : "Dest"), nullptr);
    choiceNamesTree.setProperty("84", "Pressure " + String(verbose ? "(Aftertouch) " : "") + "Amount", nullptr);
    choiceNamesTree.setProperty("85", "Pressure " + String(verbose ? "(Aftertouch) " : "") + "Destination", nullptr);
    choiceNamesTree.setProperty("86", "Breath " + String(verbose ? "Controller " : "") + "Amount", nullptr);
    choiceNamesTree.setProperty("87", "Breath " + String(verbose ? "Controller " : "") + "Destination", nullptr);
    choiceNamesTree.setProperty("88", String(verbose ? "Note " : "") + "Velocity Amount", nullptr);
    choiceNamesTree.setProperty("89", String(verbose ? "Note " : "") + "Velocity Destination", nullptr);
    choiceNamesTree.setProperty("90", "Foot Pedal Amount", nullptr);
    choiceNamesTree.setProperty("91", "Foot Pedal Destination", nullptr);
    choiceNamesTree.setProperty("92", "Push It! Switch Pitch", nullptr);
    choiceNamesTree.setProperty("93", "Push It! Switch Velocity", nullptr);
    choiceNamesTree.setProperty("94", "Push It! Switch Mode", nullptr);
    choiceNamesTree.setProperty("95", "Clock Tempo (BPM)", nullptr);
    choiceNamesTree.setProperty("96", "Clock Divide", nullptr);
    choiceNamesTree.setProperty("97", "Arpeggiator Mode", nullptr);
    choiceNamesTree.setProperty("98", "Arpeggiator On/Off", nullptr);
    choiceNamesTree.setProperty("99", "Sequencer Trigger Mode", nullptr);
    choiceNamesTree.setProperty("100", "Sequencer On/Off", nullptr);
    for (auto trackNum = 1; trackNum != 5; ++trackNum)
        choiceNamesTree.setProperty(
            "10" + (String)trackNum,
            "Sequencer Track " + (String)trackNum + String(verbose ? " Destination" : " Dest"),
            nullptr);
    for (auto trackNum = 0; trackNum != 4; ++trackNum) {
        for (auto stepNum = 0; stepNum != 16; ++stepNum)
            choiceNamesTree.setProperty(
                String(105 + trackNum * 16 + stepNum),
                String(verbose ? "Sequencer" : "Seq") + " Track " + String(trackNum + 1) + " Step " + String(stepNum + 1),
                nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LFO_Freq(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != EP::first_LFO_PitchedFreqChoice; ++choiceNum) {
        choiceNamesTree.setProperty((String)choiceNum, verbose ? "Un-synced " + (String)choiceNum : (String)choiceNum, nullptr);
    }
    for (auto choiceNum = EP::first_LFO_PitchedFreqChoice; choiceNum != EP::first_LFO_SyncedFreqChoice; ++choiceNum) {
        auto pitchName{ convertIntToPitchName(uint8(choiceNum - EP::first_LFO_PitchedFreqChoice)) };
        auto choiceName{ verbose ? (String)choiceNum + " (Pitch Freq. " + pitchName + ")" : pitchName };
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    choiceNamesTree.setProperty("151", verbose ? "Synced 151 : 1 LFO cycle lasts 32 steps" : "1:32", nullptr);
    choiceNamesTree.setProperty("152", verbose ? "Synced 152 : 1 LFO cycle lasts 16 steps" : "1:16", nullptr);
    choiceNamesTree.setProperty("153", verbose ? "Synced 153 : 1 LFO cycle lasts 8 steps" : "1:8", nullptr);
    choiceNamesTree.setProperty("154", verbose ? "Synced 154 : 1 LFO cycle lasts 6 steps" : "1:6", nullptr);
    choiceNamesTree.setProperty("155", verbose ? "Synced 155 : 1 LFO cycle lasts 4 steps" : "1:4", nullptr);
    choiceNamesTree.setProperty("156", verbose ? "Synced 156 : 1 LFO cycle lasts 3 steps" : "1:3", nullptr);
    choiceNamesTree.setProperty("157", verbose ? "Synced 157 : 1 LFO cycle lasts 2 steps" : "1:2", nullptr);
    choiceNamesTree.setProperty("158", verbose ? "Synced 158 : 1 LFO cycle lasts 1-1/2 steps" : "1:1.5", nullptr);
    choiceNamesTree.setProperty("159", verbose ? "Synced 159 : 1 LFO cycle lasts 1 step" : "1:1", nullptr);
    choiceNamesTree.setProperty("160", verbose ? "Synced 160 : 1 LFO cycle lasts 2/3 step" : "3:2", nullptr);
    choiceNamesTree.setProperty("161", verbose ? "Synced 161 : 1 LFO cycle lasts 1/2 step" : "2:1", nullptr);
    choiceNamesTree.setProperty("162", verbose ? "Synced 162 : 1 LFO cycle lasts 1/3 step" : "3:1", nullptr);
    choiceNamesTree.setProperty("163", verbose ? "Synced 163 : 1 LFO cycle lasts 1/4 step" : "4:1", nullptr);
    choiceNamesTree.setProperty("164", verbose ? "Synced 164 : 1 LFO cycle lasts 1/6 step" : "6:1", nullptr);
    choiceNamesTree.setProperty("165", verbose ? "Synced 165 : 1 LFO cycle lasts 1/8 step" : "8:1", nullptr);
    choiceNamesTree.setProperty("166", verbose ? "Synced 166 : 1 LFO cycle lasts 1/16 step" : "16:1", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForModDestination(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Off", nullptr);
    choiceNamesTree.setProperty("1", "Oscillator 1 Pitch", nullptr);
    choiceNamesTree.setProperty("2", "Oscillator 2 Pitch", nullptr);
    choiceNamesTree.setProperty("3", "Oscillator 1 & 2 Pitch", nullptr);
    choiceNamesTree.setProperty("4", "Oscillator Mix", nullptr);
    choiceNamesTree.setProperty("5", "Noise Level", nullptr);
    choiceNamesTree.setProperty("6", "Oscillator 1 Pulse Width", nullptr);
    choiceNamesTree.setProperty("7", "Oscillator 2 Pulse Width", nullptr);
    choiceNamesTree.setProperty("8", "Oscillator 1 & 2 PW", nullptr);
    choiceNamesTree.setProperty("9", "LPF Cutoff Frequency", nullptr);
    choiceNamesTree.setProperty("10", "LPF Resonance", nullptr);
    choiceNamesTree.setProperty("11", "LPF FM Amount", nullptr);
    choiceNamesTree.setProperty("12", "VCA Level", nullptr);
    choiceNamesTree.setProperty("13", "Output Panning", nullptr);
    for (auto choiceNum = 14; choiceNum != 18; ++choiceNum)
        choiceNamesTree.setProperty((String)choiceNum, "LFO " + String(choiceNum - 13) + " Frequency", nullptr);
    choiceNamesTree.setProperty("18", "All LFO Frequencies", nullptr);
    for (auto choiceNum = 19; choiceNum != 23; ++choiceNum)
        choiceNamesTree.setProperty((String)choiceNum, "LFO " + String(choiceNum - 18) + " Amount", nullptr);
    choiceNamesTree.setProperty("23", "All LFO Amounts", nullptr);
    choiceNamesTree.setProperty("24", "LPF Envelope Amount", nullptr);
    choiceNamesTree.setProperty("25", "VCA Envelope Amount", nullptr);
    choiceNamesTree.setProperty("26", "Envelope 3 Amount", nullptr);
    choiceNamesTree.setProperty("27", "All Envelope Amounts", nullptr);
    choiceNamesTree.setProperty("28", "LPF Envelope Attack", nullptr);
    choiceNamesTree.setProperty("29", "VCA Envelope Attack", nullptr);
    choiceNamesTree.setProperty("30", "Envelope 3 Attack", nullptr);
    choiceNamesTree.setProperty("31", "All Envelope Attacks", nullptr);
    choiceNamesTree.setProperty("32", "LPF Envelope Decay", nullptr);
    choiceNamesTree.setProperty("33", "VCA Envelope Decay", nullptr);
    choiceNamesTree.setProperty("34", "Envelope 3 Decay", nullptr);
    choiceNamesTree.setProperty("35", "All Envelope Decays", nullptr);
    choiceNamesTree.setProperty("36", "LPF Envelope Release", nullptr);
    choiceNamesTree.setProperty("37", "VCA Envelope Release", nullptr);
    choiceNamesTree.setProperty("38", "Envelope 3 Release", nullptr);
    choiceNamesTree.setProperty("39", "All Envelope Releases", nullptr);
    for (auto choiceNum = 40; choiceNum != 44; ++choiceNum)
        choiceNamesTree.setProperty((String)choiceNum, "Modulator " + String(choiceNum - 39) + " Amount", nullptr);
    choiceNamesTree.setProperty("44", "External Audio " + String(verbose ? "Input Level" : "In Level"), nullptr);
    choiceNamesTree.setProperty("45", String(verbose ? "Sub-Oscillator" : "Sub-Osc") + " 1 Level", nullptr);
    choiceNamesTree.setProperty("46", String(verbose ? "Sub-Oscillator" : "Sub-Osc") + " 2 Level", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForModSource(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Off", nullptr);
    for (auto choiceNum = 1; choiceNum != 5; ++choiceNum)
        choiceNamesTree.setProperty((String)choiceNum, "Sequencer Track " + (String)choiceNum, nullptr);
    for (auto choiceNum = 5; choiceNum != 9; ++choiceNum)
        choiceNamesTree.setProperty((String)choiceNum, "LFO " + String(choiceNum - 4), nullptr);
    choiceNamesTree.setProperty("9", "LPF Envelope", nullptr);
    choiceNamesTree.setProperty("10", "VCA Envelope", nullptr);
    choiceNamesTree.setProperty("11", "Envelope 3", nullptr);
    choiceNamesTree.setProperty("12", "Pitch Bend", nullptr);
    choiceNamesTree.setProperty("13", "Mod Wheel", nullptr);
    choiceNamesTree.setProperty("14", "Pressure (Aftertouch)", nullptr);
    choiceNamesTree.setProperty("15", "MIDI Breath", nullptr);
    choiceNamesTree.setProperty("16", "MIDI Foot Pedal", nullptr);
    choiceNamesTree.setProperty("17", "MIDI Expression", nullptr);
    choiceNamesTree.setProperty("18", "Velocity", nullptr);
    choiceNamesTree.setProperty("19", "Note Number", nullptr);
    choiceNamesTree.setProperty("20", "Noise", nullptr);
    choiceNamesTree.setProperty("21", "Audio In Env. Follower", nullptr);
    choiceNamesTree.setProperty("22", "Audio In Peak Hold", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForNotePriority(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", verbose ? "Low Note Has Priority" : "Low Note", nullptr);
    choiceNamesTree.setProperty("1", verbose ? "Low Note Has Priority (Re-trigger)" : "Low Note (Re-trigger)", nullptr);
    choiceNamesTree.setProperty("2", verbose ? "High Note Has Priority" : "High Note", nullptr);
    choiceNamesTree.setProperty("3", verbose ? "High Note Has Priority (Re-trigger)" : "High Note (Re-trigger)", nullptr);
    choiceNamesTree.setProperty("4", verbose ? "Last Note Hit Has Priority" : "Last Note", nullptr);
    choiceNamesTree.setProperty("5", verbose ? "Last Note Hit Has Priority (Re-trigger)" : "Last Note (Re-trigger)", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOffOn(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Off", nullptr);
    choiceNamesTree.setProperty("1", "On", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOscFineTune(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForOscFineTune; ++choiceNum) {
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
            choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
        }
        else {
            auto choiceName{ choiceNum < 51 ? (String)(choiceNum - 50) : "+" + (String)(choiceNum - 50) };
            choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
        }
    }
    return choiceNamesTree;
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
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForOscShape(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForOscWaveShape; ++choiceNum) {
        String choiceName{ "" };
        if (choiceNum == 0)
            choiceName = verbose ? "Oscillator Off" : "Off";
        if (choiceNum == 1)
            choiceName = verbose ? "Sawtooth" : "Saw";
        if (choiceNum == 2)
            choiceName = verbose ? "Triangle" : "Tri";
        if (choiceNum == 3)
            choiceName = verbose ? "Sawtooth/Triangle Mix" : "Saw/Tri";
        if (choiceNum > 3)
            choiceName = verbose ? "Pulse (Width: " + String(choiceNum - 4) + ")" : "PW " + String(choiceNum - 4);
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForPlainValue(const uint8 numberOfChoices, bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != numberOfChoices; ++choiceNum) {
        auto choiceName{ (String)choiceNum };
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForPosNeg_127(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != 255; ++choiceNum) {
        auto choiceName{ (choiceNum > 127 ? "+" : "") + String(choiceNum - 127) };
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForPushItMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Normal", nullptr);
    choiceNamesTree.setProperty("1", "Toggle", nullptr);
    choiceNamesTree.setProperty("2", "Audio In", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForSeqTrackStep(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != 126; ++choiceNum)
        choiceNamesTree.setProperty(
            (String)choiceNum,
            (String)choiceNum + " (" + convertIntToSeqStepPitchName((uint8)choiceNum) + ")",
            nullptr);
    choiceNamesTree.setProperty("126", "Reset Sequence", nullptr);
    choiceNamesTree.setProperty("127", "Rest", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForSeqTracks_2_4_Destination(const int trackNum, bool verbose) {
    jassert(trackNum == 2 || trackNum == 4);
    auto choiceNamesTree{ buildForModDestination(verbose) };
    auto choiceNameString{ String(verbose ? "Sequencer" : "Seq.") + " Track " + String(trackNum - 1) + " Slew" };
    choiceNamesTree.setProperty("47", choiceNameString, nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForSeqTrigMode(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Normal", nullptr);
    choiceNamesTree.setProperty("1", "Normal, No Reset", nullptr);
    choiceNamesTree.setProperty("2", "No Gate", nullptr);
    choiceNamesTree.setProperty("3", "No Gate, No Reset", nullptr);
    choiceNamesTree.setProperty("4", "Key Step", nullptr);
    choiceNamesTree.setProperty("5", "Audio Input", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildForVoiceNameChar(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = 0; choiceNum != 32; ++choiceNum)
        choiceNamesTree.setProperty((String)choiceNum, "ASCII Control Character " + (String)choiceNum, nullptr);
    choiceNamesTree.setProperty("32", verbose ? "Space" : " ", nullptr);
    for (auto choiceNum = 33; choiceNum != EP::numberOfChoicesForVoiceNameChar; ++choiceNum) {
        auto choiceName{ String(std::string(1, (char)choiceNum)) };
        if (choiceNum == 92)
            choiceName = verbose ? "Yen Symbol" : GUI::yen;
        if (choiceNum == 126)
            choiceName = verbose ? "Right Arrow" : "->";
        if (choiceNum == 127)
            choiceName = verbose ? "Left Arrow" : "<-";
        choiceNamesTree.setProperty((String)choiceNum, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LFO_Shape(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "Triangle", nullptr);
    choiceNamesTree.setProperty("1", "Reverse Sawtooth", nullptr);
    choiceNamesTree.setProperty("2", "Sawtooth", nullptr);
    choiceNamesTree.setProperty("3", "Pulse (Square)", nullptr);
    choiceNamesTree.setProperty("4", "Random", nullptr);
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LPF_Freq(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesFor_LPF_Freq; ++choiceNum) {
        auto choiceNumString{ (String)choiceNum };
        auto pitchString{ convertIntToPitchName(choiceNum) };
        auto choiceName{ verbose ? choiceNumString + " (Pitch Freq. " + pitchString + ")" : pitchString };
        choiceNamesTree.setProperty(choiceNumString, choiceName, nullptr);
    }
    return choiceNamesTree;
}

ValueTree ExposedParamChoiceNamesValueTree::buildFor_LPF_Type(const bool verbose) {
    ValueTree choiceNamesTree{ verbose ? ID::tree_ChoiceNames_Verbose : ID::tree_ChoiceNames };
    choiceNamesTree.setProperty("0", "2-Pole", nullptr);
    choiceNamesTree.setProperty("1", "4-Pole", nullptr);
    return choiceNamesTree;
}
