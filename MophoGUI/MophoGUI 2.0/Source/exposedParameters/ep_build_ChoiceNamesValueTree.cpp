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

ValueTree ChoiceNamesValueTree::buildFor_GlideMode(bool verbose) {
	ValueTree choiceNamesTree{ verbose ? ID::choiceNames_Verbose : ID::choiceNames };
	choiceNamesTree.setProperty("choice_0", "Fixed Rate", nullptr);
	choiceNamesTree.setProperty("choice_1", "Fixed Rate Auto", nullptr);
	choiceNamesTree.setProperty("choice_2", "Fixed Time", nullptr);
	choiceNamesTree.setProperty("choice_3", "Fixed Time Auto", nullptr);
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
	choiceNamesTree.setProperty("choice_5", "Noise Level", nullptr);
	choiceNamesTree.setProperty("choice_6", "Oscillator 1 Pulse Width", nullptr);
	choiceNamesTree.setProperty("choice_7", "Oscillator 2 Pulse Width", nullptr);
	choiceNamesTree.setProperty("choice_8", "Oscillator 1 & 2 PW", nullptr);
	choiceNamesTree.setProperty("choice_9", "LPF Cutoff Frequency", nullptr);
	choiceNamesTree.setProperty("choice_10", "LPF Resonance", nullptr);
	choiceNamesTree.setProperty("choice_11", "LPF FM Amount", nullptr);
	choiceNamesTree.setProperty("choice_12", "VCA Level", nullptr);
	choiceNamesTree.setProperty("choice_13", "Output Panning", nullptr);
	choiceNamesTree.setProperty("choice_14", "LFO 1 Frequency", nullptr);
	choiceNamesTree.setProperty("choice_15", "LFO 2 Frequency", nullptr);
	choiceNamesTree.setProperty("choice_16", "LFO 3 Frequency", nullptr);
	choiceNamesTree.setProperty("choice_17", "LFO 4 Frequency", nullptr);
	choiceNamesTree.setProperty("choice_18", "All LFO Frequencies", nullptr);
	choiceNamesTree.setProperty("choice_19", "LFO 1 Amount", nullptr);
	choiceNamesTree.setProperty("choice_20", "LFO 2 Amount", nullptr);
	choiceNamesTree.setProperty("choice_21", "LFO 3 Amount", nullptr);
	choiceNamesTree.setProperty("choice_22", "LFO 4 Amount", nullptr);
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
	choiceNamesTree.setProperty("choice_40", "Modulator 1 Amount", nullptr);
	choiceNamesTree.setProperty("choice_41", "Modulator 2 Amount", nullptr);
	choiceNamesTree.setProperty("choice_42", "Modulator 3 Amount", nullptr);
	choiceNamesTree.setProperty("choice_43", "Modulator 4 Amount", nullptr);
	choiceNamesTree.setProperty("choice_44", "External Audio In Level", nullptr);
	choiceNamesTree.setProperty("choice_45", "Sub-Osc 1 Level", nullptr);
	choiceNamesTree.setProperty("choice_46", "Sub-Osc 2 Level", nullptr);
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

