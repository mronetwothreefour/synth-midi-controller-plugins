#include "ep_build_ChoiceNamesValueTree.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



String ChoiceNamesValueTree::convertIntToPitchName(const uint8& i) noexcept {
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
	default: return "invalid";
	}
}

String ChoiceNamesValueTree::convertIntToSeqStepPitchName(const uint8& i) noexcept {
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
	default: return "err";
	}
}

ValueTree ChoiceNamesValueTree::buildFor_ArpegMode(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Up", nullptr);
	choiceNamesTree.setProperty("choice_1", "Down", nullptr);
	choiceNamesTree.setProperty("choice_2", "Up & Down", nullptr);
	choiceNamesTree.setProperty("choice_3", "Assign", nullptr);
	choiceNamesTree.setProperty("choice_4", "Random", nullptr);
	choiceNamesTree.setProperty("choice_5", "2 Octaves Up", nullptr);
	choiceNamesTree.setProperty("choice_6", "2 Octaves Down", nullptr);
	choiceNamesTree.setProperty("choice_7", "2 Octaves Up & Down", nullptr);
	choiceNamesTree.setProperty("choice_8", "2 Octaves Assign", nullptr);
	choiceNamesTree.setProperty("choice_9", "2 Octaves Random", nullptr);
	choiceNamesTree.setProperty("choice_10", "3 Octaves Up", nullptr);
	choiceNamesTree.setProperty("choice_11", "3 Octaves Down", nullptr);
	choiceNamesTree.setProperty("choice_12", "3 Octaves Up & Down", nullptr);
	choiceNamesTree.setProperty("choice_13", "3 Octaves Assign", nullptr);
	choiceNamesTree.setProperty("choice_14", "3 Octaves Random", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_BendRange(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForBendRange; ++choiceNum) {
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

ValueTree ChoiceNamesValueTree::buildFor_ClockDivision(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", verbose ? "Half Note (BPM / 2)" : "Half Note", nullptr);
	choiceNamesTree.setProperty("choice_1", verbose ? "Quarter Note (BPM x 1)" : "Quarter Note", nullptr);
	choiceNamesTree.setProperty("choice_2", verbose ? "8th Note (BPM x 2)" : "8th Note", nullptr);
	choiceNamesTree.setProperty("choice_3", verbose ? "8th Note, 1/2 Swing (BPM x 2)" : "8th Note, 1/2 Swing", nullptr);
	choiceNamesTree.setProperty("choice_4", verbose ? "8th Note, Full Swing (BPM x 2)" : "8th Note, Full Swing", nullptr);
	choiceNamesTree.setProperty("choice_5", verbose ? "8th Note Triplets (BPM x 3)" : "8th Note Triplets", nullptr);
	choiceNamesTree.setProperty("choice_6", verbose ? "16th Note (BPM x 4)" : "16th Note", nullptr);
	choiceNamesTree.setProperty("choice_7", verbose ? "16th Note, 1/2 Swing (BPM x 4)" : "16th Note, 1/2 Swing", nullptr);
	choiceNamesTree.setProperty("choice_8", verbose ? "16th Note, Full Swing (BPM x 4)" : "16th Note, Full Swing", nullptr);
	choiceNamesTree.setProperty("choice_9", verbose ? "16th Note Triplets (BPM x 6)" : "16th Note Triplets", nullptr);
	choiceNamesTree.setProperty("choice_10", verbose ? "32nd Note (BPM x 8)" : "32nd Note", nullptr);
	choiceNamesTree.setProperty("choice_11", verbose ? "32nd Note Triplets (BPM x 12)" : "32nd Note Triplets", nullptr);
	choiceNamesTree.setProperty("choice_12", verbose ? "64th Note Triplets (BPM x 24)" : "64th Note Triplets", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_ClockTempo(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForClockTempo; ++choiceNum) {
		auto choiceName{ String(choiceNum + 30)};
		if (verbose)
			choiceName += " BPM";
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_GlideMode(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Fixed Rate", nullptr);
	choiceNamesTree.setProperty("choice_1", "Fixed Rate Auto", nullptr);
	choiceNamesTree.setProperty("choice_2", "Fixed Time", nullptr);
	choiceNamesTree.setProperty("choice_3", "Fixed Time Auto", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_KnobAssign(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		choiceNamesTree.setProperty(oscNum == 1 ? "choice_0" : "choice_6", "Oscillator " + (String)oscNum + " Pitch", nullptr);
		choiceNamesTree.setProperty(oscNum == 1 ? "choice_1" : "choice_7", "Oscillator " + (String)oscNum + " Fine Tune", nullptr);
		choiceNamesTree.setProperty(oscNum == 1 ? "choice_2" : "choice_8", "Oscillator " + (String)oscNum + " Wave Shape", nullptr);
		choiceNamesTree.setProperty(oscNum == 1 ? "choice_3" : "choice_9", "Oscillator " + (String)oscNum + " Glide Rate", nullptr);
		choiceNamesTree.setProperty(oscNum == 1 ? "choice_4" : "choice_10", "Oscillator " + (String)oscNum + " Key Track", nullptr);
		choiceNamesTree.setProperty(oscNum == 1 ? "choice_5" : "choice_11", "Sub-Oscillator " + (String)oscNum + " Level", nullptr);
	}
	choiceNamesTree.setProperty("choice_12", "Hard Sync Oscillators", nullptr);
	choiceNamesTree.setProperty("choice_13", "Glide Mode", nullptr);
	choiceNamesTree.setProperty("choice_14", "Oscillator Slop", nullptr);
	choiceNamesTree.setProperty("choice_15", "Pitch Bend Range", nullptr);
	choiceNamesTree.setProperty("choice_16", "Keyed Note Priority", nullptr);
	choiceNamesTree.setProperty("choice_17", "Oscillators 1 & 2 Mix", nullptr);
	choiceNamesTree.setProperty("choice_18", "Noise Level", nullptr);
	choiceNamesTree.setProperty("choice_19", "External Audio " + String(verbose ? "Input Level" : "In Level"), nullptr);
	choiceNamesTree.setProperty("choice_20", "LPF Cutoff Frequency", nullptr);
	choiceNamesTree.setProperty("choice_21", "LPF Resonance", nullptr);
	choiceNamesTree.setProperty("choice_22", "LPF Keyboard Amount", nullptr);
	choiceNamesTree.setProperty("choice_23", "LPF Freq. Mod. Amount", nullptr);
	choiceNamesTree.setProperty("choice_24", "LPF 2- or 4-Pole Select", nullptr);
	choiceNamesTree.setProperty("choice_25", "LPF Envelope Amount", nullptr);
	choiceNamesTree.setProperty("choice_26", verbose ? "LPF Envelope Velocity Amount" : "LPF Env Vel Amt", nullptr);
	choiceNamesTree.setProperty("choice_27", "LPF Envelope Delay", nullptr);
	choiceNamesTree.setProperty("choice_28", "LPF Envelope Attack", nullptr);
	choiceNamesTree.setProperty("choice_29", "LPF Envelope Decay", nullptr);
	choiceNamesTree.setProperty("choice_30", "LPF Envelope Sustain", nullptr);
	choiceNamesTree.setProperty("choice_31", "LPF Envelope Release", nullptr);
	choiceNamesTree.setProperty("choice_32", "VCA Initial Level", nullptr);
	choiceNamesTree.setProperty("choice_33", "VCA Envelope Amount", nullptr);
	choiceNamesTree.setProperty("choice_34", verbose ? "VCA Envelope Velocity Amount" : "VCA Env Vel Amnt", nullptr);
	choiceNamesTree.setProperty("choice_35", "VCA Envelope Delay", nullptr);
	choiceNamesTree.setProperty("choice_36", "VCA Envelope Attack", nullptr);
	choiceNamesTree.setProperty("choice_37", "VCA Envelope Decay", nullptr);
	choiceNamesTree.setProperty("choice_38", "VCA Envelope Sustain", nullptr);
	choiceNamesTree.setProperty("choice_39", "VCA Envelope Release", nullptr);
	choiceNamesTree.setProperty("choice_40", "Voice Volume", nullptr);
	for (auto lfoNum = 0; lfoNum != 4; ++lfoNum) {
		choiceNamesTree.setProperty("choice_" + String(41 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Frequency", nullptr);
		choiceNamesTree.setProperty("choice_" + String(42 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Wave Shape", nullptr);
		choiceNamesTree.setProperty("choice_" + String(43 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Amount", nullptr);
		choiceNamesTree.setProperty(
			"choice_" + String(44 + lfoNum * 5), 
			"LFO " + String(lfoNum + 1) + String(verbose ? " Modulation" : " Mod") + " Destination", 
			nullptr);
		choiceNamesTree.setProperty("choice_" + String(45 + lfoNum * 5), "LFO " + String(lfoNum + 1) + " Key Sync", nullptr);
	}
	choiceNamesTree.setProperty("choice_61", "Env 3 " + String(verbose ? "Modulation" : "Mod") + " Destination", nullptr);
	choiceNamesTree.setProperty("choice_62", "Envelope 3 Amount", nullptr);
	choiceNamesTree.setProperty("choice_63", "Env 3 Velocity Amount", nullptr);
	choiceNamesTree.setProperty("choice_64", "Envelope 3 Delay", nullptr);
	choiceNamesTree.setProperty("choice_65", "Envelope 3 Attack", nullptr);
	choiceNamesTree.setProperty("choice_66", "Envelope 3 Decay", nullptr);
	choiceNamesTree.setProperty("choice_67", "Envelope 3 Sustain", nullptr);
	choiceNamesTree.setProperty("choice_68", "Envelope 3 Release", nullptr);
	choiceNamesTree.setProperty("choice_69", "Envelope 3 Repeat", nullptr);
	for (auto modNum = 0; modNum != 4; ++modNum) {
		choiceNamesTree.setProperty("choice_" + String(70 + modNum * 3), "Modulator " + String(modNum + 1) + " Source", nullptr);
		choiceNamesTree.setProperty("choice_" + String(71 + modNum * 3), "Modulator " + String(modNum + 1) + " Amount", nullptr);
		choiceNamesTree.setProperty("choice_" + String(72 + modNum * 3), "Modulator " + String(modNum + 1) + " Destination", nullptr);
	}
	choiceNamesTree.setProperty("choice_82", "Modulation Wheel " + String(verbose ? "Amount" : "Amt"), nullptr);
	choiceNamesTree.setProperty("choice_83", "Modulation Wheel " + String(verbose ? "Destination" : "Dest"), nullptr);
	choiceNamesTree.setProperty("choice_84", "Pressure " + String(verbose ? "(Aftertouch) " : "") + "Amount", nullptr);
	choiceNamesTree.setProperty("choice_85", "Pressure " + String(verbose ? "(Aftertouch) " : "") + "Destination", nullptr);
	choiceNamesTree.setProperty("choice_86", "Breath " + String(verbose ? "Controller " : "") + "Amount", nullptr);
	choiceNamesTree.setProperty("choice_87", "Breath " + String(verbose ? "Controller " : "") + "Destination", nullptr);
	choiceNamesTree.setProperty("choice_88", String(verbose ? "Note " : "") + "Velocity Amount", nullptr);
	choiceNamesTree.setProperty("choice_89", String(verbose ? "Note " : "") + "Velocity Destination", nullptr);
	choiceNamesTree.setProperty("choice_90", "Foot Pedal Amount", nullptr);
	choiceNamesTree.setProperty("choice_91", "Foot Pedal Destination", nullptr);
	choiceNamesTree.setProperty("choice_92", "Push It! Switch Pitch", nullptr);
	choiceNamesTree.setProperty("choice_93", "Push It! Switch Velocity", nullptr);
	choiceNamesTree.setProperty("choice_94", "Push It! Switch Mode", nullptr);
	choiceNamesTree.setProperty("choice_95", "Clock Tempo (BPM)", nullptr);
	choiceNamesTree.setProperty("choice_96", "Clock Divide", nullptr);
	choiceNamesTree.setProperty("choice_97", "Arpeggiator Mode", nullptr);
	choiceNamesTree.setProperty("choice_98", "Arpeggiator On/Off", nullptr);
	choiceNamesTree.setProperty("choice_99", "Sequencer Trigger Mode", nullptr);
	choiceNamesTree.setProperty("choice_100", "Sequencer On/Off", nullptr);
	for (auto trackNum = 1; trackNum != 5; ++trackNum)
		choiceNamesTree.setProperty(
			"choice_10" + (String)trackNum, 
			"Sequencer Track " + (String)trackNum + String(verbose ? " Destination" : " Dest"),
			nullptr);
	for (auto trackNum = 0; trackNum != 4; ++trackNum) {
		for (auto stepNum = 0; stepNum != 16; ++stepNum)
			choiceNamesTree.setProperty(
				"choice_" + String(105 + trackNum * 16 + stepNum), 
				String(verbose ? "Sequencer" : "Seq") + " Track " + String(trackNum + 1) + " Step " + String(stepNum + 1),
				nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_LFO_Freq(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = 0; choiceNum != EP::firstLFO_PitchedFreqChoice; ++choiceNum) {
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, verbose ? "Un-synced " + (String)choiceNum : (String)choiceNum, nullptr);
	}
	for (auto choiceNum = EP::firstLFO_PitchedFreqChoice; choiceNum != EP::firstLFO_SyncedFreqChoice; ++choiceNum) {
		auto pitchName{ convertIntToPitchName(uint8(choiceNum - EP::firstLFO_PitchedFreqChoice)) };
		auto choiceName{ verbose ? (String)choiceNum + " (Pitch Freq. " + pitchName + ")" : pitchName };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	choiceNamesTree.setProperty("choice_151", verbose ? "Synced 151 : 1 LFO cycle lasts 32 steps" : "1:32", nullptr);
	choiceNamesTree.setProperty("choice_152", verbose ? "Synced 152 : 1 LFO cycle lasts 16 steps" : "1:16", nullptr);
	choiceNamesTree.setProperty("choice_153", verbose ? "Synced 153 : 1 LFO cycle lasts 8 steps" : "1:8", nullptr);
	choiceNamesTree.setProperty("choice_154", verbose ? "Synced 154 : 1 LFO cycle lasts 6 steps" : "1:6", nullptr);
	choiceNamesTree.setProperty("choice_155", verbose ? "Synced 155 : 1 LFO cycle lasts 4 steps" : "1:4", nullptr);
	choiceNamesTree.setProperty("choice_156", verbose ? "Synced 156 : 1 LFO cycle lasts 3 steps" : "1:3", nullptr);
	choiceNamesTree.setProperty("choice_157", verbose ? "Synced 157 : 1 LFO cycle lasts 2 steps" : "1:2", nullptr);
	choiceNamesTree.setProperty("choice_158", verbose ? "Synced 158 : 1 LFO cycle lasts 1-1/2 steps" : "1:1.5", nullptr);
	choiceNamesTree.setProperty("choice_159", verbose ? "Synced 159 : 1 LFO cycle lasts 1 step" : "1:1", nullptr);
	choiceNamesTree.setProperty("choice_160", verbose ? "Synced 160 : 1 LFO cycle lasts 2/3 step" : "3:2", nullptr);
	choiceNamesTree.setProperty("choice_161", verbose ? "Synced 161 : 1 LFO cycle lasts 1/2 step" : "2:1", nullptr);
	choiceNamesTree.setProperty("choice_162", verbose ? "Synced 162 : 1 LFO cycle lasts 1/3 step" : "3:1", nullptr);
	choiceNamesTree.setProperty("choice_163", verbose ? "Synced 163 : 1 LFO cycle lasts 1/4 step" : "4:1", nullptr);
	choiceNamesTree.setProperty("choice_164", verbose ? "Synced 164 : 1 LFO cycle lasts 1/6 step" : "6:1", nullptr);
	choiceNamesTree.setProperty("choice_165", verbose ? "Synced 165 : 1 LFO cycle lasts 1/8 step" : "8:1", nullptr);
	choiceNamesTree.setProperty("choice_166", verbose ? "Synced 166 : 1 LFO cycle lasts 1/16 step" : "16:1", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_LFO_Shape(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Triangle", nullptr);
	choiceNamesTree.setProperty("choice_1", "Reverse Sawtooth", nullptr);
	choiceNamesTree.setProperty("choice_2", "Sawtooth", nullptr);
	choiceNamesTree.setProperty("choice_3", "Square Wave", nullptr);
	choiceNamesTree.setProperty("choice_4", "Random", nullptr);
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

ValueTree ChoiceNamesValueTree::buildFor_LPF_Type(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "2-Pole", nullptr);
	choiceNamesTree.setProperty("choice_1", "4-Pole", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_ModDestination(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Off", nullptr);
	choiceNamesTree.setProperty("choice_1", "Oscillator 1 Pitch", nullptr);
	choiceNamesTree.setProperty("choice_2", "Oscillator 2 Pitch", nullptr);
	choiceNamesTree.setProperty("choice_3", "Oscillator 1 & 2 Pitch", nullptr);
	choiceNamesTree.setProperty("choice_4", "Oscillator Mix", nullptr);
	choiceNamesTree.setProperty("choice_5", "Noise Level", nullptr);
	choiceNamesTree.setProperty("choice_6", "Oscillator 1 Pulse Width", nullptr);
	choiceNamesTree.setProperty("choice_7", "Oscillator 2 Pulse Width", nullptr);
	choiceNamesTree.setProperty("choice_8", "Oscillator 1 & 2 PW", nullptr);
	choiceNamesTree.setProperty("choice_9", "LPF Cutoff Frequency", nullptr);
	choiceNamesTree.setProperty("choice_10", "LPF Resonance", nullptr);
	choiceNamesTree.setProperty("choice_11", "LPF FM Amount", nullptr);
	choiceNamesTree.setProperty("choice_12", "VCA Level", nullptr);
	choiceNamesTree.setProperty("choice_13", "Output Panning", nullptr);
	for (auto choiceNum = 14; choiceNum != 18; ++choiceNum)
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, "LFO " + String(choiceNum - 13) + " Frequency", nullptr);
	choiceNamesTree.setProperty("choice_18", "All LFO Frequencies", nullptr);
	for (auto choiceNum = 19; choiceNum != 23; ++choiceNum)
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, "LFO " + String(choiceNum - 18) + " Amount", nullptr);
	choiceNamesTree.setProperty("choice_23", "All LFO Amounts", nullptr);
	choiceNamesTree.setProperty("choice_24", "LPF Envelope Amount", nullptr);
	choiceNamesTree.setProperty("choice_25", "VCA Envelope Amount", nullptr);
	choiceNamesTree.setProperty("choice_26", "Envelope 3 Amount", nullptr);
	choiceNamesTree.setProperty("choice_27", "All Envelope Amounts", nullptr);
	choiceNamesTree.setProperty("choice_28", "LPF Envelope Attack", nullptr);
	choiceNamesTree.setProperty("choice_29", "VCA Envelope Attack", nullptr);
	choiceNamesTree.setProperty("choice_30", "Envelope 3 Attack", nullptr);
	choiceNamesTree.setProperty("choice_31", "All Envelope Attacks", nullptr);
	choiceNamesTree.setProperty("choice_32", "LPF Envelope Decay", nullptr);
	choiceNamesTree.setProperty("choice_33", "VCA Envelope Decay", nullptr);
	choiceNamesTree.setProperty("choice_34", "Envelope 3 Decay", nullptr);
	choiceNamesTree.setProperty("choice_35", "All Envelope Decays", nullptr);
	choiceNamesTree.setProperty("choice_36", "LPF Envelope Release", nullptr);
	choiceNamesTree.setProperty("choice_37", "VCA Envelope Release", nullptr);
	choiceNamesTree.setProperty("choice_38", "Envelope 3 Release", nullptr);
	choiceNamesTree.setProperty("choice_39", "All Envelope Releases", nullptr);
	for (auto choiceNum = 40; choiceNum != 44; ++choiceNum)
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, "Modulator " + String(choiceNum - 39) + " Amount", nullptr);
	choiceNamesTree.setProperty("choice_44", "External Audio " + String(verbose ? "Input Level" : "In Level"), nullptr);
	choiceNamesTree.setProperty("choice_45", String(verbose ? "Sub-Oscillator" : "Sub-Osc") + " 1 Level", nullptr);
	choiceNamesTree.setProperty("choice_46", String(verbose ? "Sub-Oscillator" : "Sub-Osc") + " 2 Level", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_ModSource(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Off", nullptr);
	for (auto choiceNum = 1; choiceNum != 5; ++choiceNum)
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, "Sequencer Track " + (String)choiceNum, nullptr);
	for (auto choiceNum = 5; choiceNum != 9; ++choiceNum)
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, "LFO " + String(choiceNum - 4), nullptr);
	choiceNamesTree.setProperty("choice_9", "LPF Envelope", nullptr);
	choiceNamesTree.setProperty("choice_10", "VCA Envelope", nullptr);
	choiceNamesTree.setProperty("choice_11", "Envelope 3", nullptr);
	choiceNamesTree.setProperty("choice_12", "Pitch Bend", nullptr);
	choiceNamesTree.setProperty("choice_13", "Mod Wheel", nullptr);
	choiceNamesTree.setProperty("choice_14", "Pressure (Aftertouch)", nullptr);
	choiceNamesTree.setProperty("choice_15", "MIDI Breath", nullptr);
	choiceNamesTree.setProperty("choice_16", "MIDI Foot Pedal", nullptr);
	choiceNamesTree.setProperty("choice_17", "MIDI Expression", nullptr);
	choiceNamesTree.setProperty("choice_18", "Velocity", nullptr);
	choiceNamesTree.setProperty("choice_19", "Note Number", nullptr);
	choiceNamesTree.setProperty("choice_20", "Noise", nullptr);
	choiceNamesTree.setProperty("choice_21", "Audio In Env. Follower", nullptr);
	choiceNamesTree.setProperty("choice_22", "Audio In Peak Hold", nullptr);
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
	choiceNamesTree.setProperty("choice_0", "Off", nullptr);
	choiceNamesTree.setProperty("choice_1", "On", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_OscFineTune(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
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
	for (auto choiceNum = 0; choiceNum != EP::numberOfChoicesForOscWaveShape; ++choiceNum) {
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
	for (auto choiceNum = 0; choiceNum != numberOfChoices; ++choiceNum) {
		auto choiceName{ (String)choiceNum };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_PlusMinus127(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = 0; choiceNum != 255; ++choiceNum) {
		auto choiceName{ (choiceNum > 127 ? "+" : "") + String(choiceNum - 127) };
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_PushItMode(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Normal", nullptr);
	choiceNamesTree.setProperty("choice_1", "Toggle", nullptr);
	choiceNamesTree.setProperty("choice_2", "Audio In", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_SeqTrackStep(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = 0; choiceNum != 126; ++choiceNum)
		choiceNamesTree.setProperty(
			"choice_" + (String)choiceNum, 
			(String)choiceNum + " (" + convertIntToSeqStepPitchName((uint8)choiceNum) + ")",
			nullptr);
	choiceNamesTree.setProperty("choice_126", "Reset Sequence", nullptr);
	choiceNamesTree.setProperty("choice_127", "Rest", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_SeqTracks_2_4_Destination(int trackNum, bool verbose) {
	jassert(trackNum == 2 || trackNum == 4);
	auto choiceNamesTree{ buildFor_ModDestination(verbose) };
	auto choiceNameString{ String(verbose ? "Sequencer" : "Seq.") + " Track " + String(trackNum - 1) + " Slew" };
	choiceNamesTree.setProperty("choice_47", choiceNameString, nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_SeqTrigMode(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Normal", nullptr);
	choiceNamesTree.setProperty("choice_1", "Normal, No Reset", nullptr);
	choiceNamesTree.setProperty("choice_2", "No Gate", nullptr);
	choiceNamesTree.setProperty("choice_3", "No Gate, No Reset", nullptr);
	choiceNamesTree.setProperty("choice_4", "Key Step", nullptr);
	choiceNamesTree.setProperty("choice_5", "Audio Input", nullptr);
	return choiceNamesTree;
}

ValueTree ChoiceNamesValueTree::buildFor_VoiceNameChar(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	for (auto choiceNum = 0; choiceNum != 32; ++choiceNum)
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, "ASCII Control Character " + (String)choiceNum, nullptr);
	choiceNamesTree.setProperty("choice_32", "Space", nullptr);
	for (auto choiceNum = 33; choiceNum != 128; ++choiceNum) {
		auto choiceName{ String(std::string(1, (char)choiceNum)) };
		if (choiceNum == 92)
			choiceName = "Yen Symbol";
		if (choiceNum == 126)
			choiceName = "Right Arrow";
		if (choiceNum == 127)
			choiceName = "Left Arrow";
		choiceNamesTree.setProperty("choice_" + (String)choiceNum, choiceName, nullptr);
	}
	return choiceNamesTree;

}

