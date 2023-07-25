#include "ep_1_tree_InfoForExposedParameters.h"

#include "ep_0_build_ChoiceNamesValueTree.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_ExposedParamDescription.h"

using Description = ExposedParamDescription;
using ChoiceNames = ExposedParamChoiceNamesValueTree;

InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::tree_ExposedParamsInfo }
{
	const auto knobRow_1_y{ 67 };
	const auto knobRow_2_y{ 170 };
	const auto knobRow_3_y{ 308 };
	const auto knobRow_1_AllowedChoices_0to15_y{ 10 };
	const auto knobRow_1_AllowedChoices_0to63_y{ 10 };
	const auto knobRow_1_AllowedChoices_0to127_y{ 10 };
	const auto knobRow_2_AllowedChoices_0to15_y{ 69 };
	const auto knobRow_2_AllowedChoices_0to63_y{ 37 };
	const auto knobRow_2_AllowedChoices_0to127_y{ 44 };
	const auto knobRow_3_AllowedChoices_0to15_y{ 180 };
	const auto knobRow_3_AllowedChoices_0to31_y{ 116 };
	const auto knobRow_3_AllowedChoices_0to127_y{ 116 };
	const auto switchRow_1_y{ 177 };
	const auto switchRow_2_y{ 315 };
	const auto switchRow_1_AllowedChoices_y{ 138 };
	const auto switchRow_2_AllowedChoices_y{ 276 };

	const auto numberOfAllowChoiceColumns_0to15{ 4 };
	const auto numberOfAllowChoiceColumns_0to31{ 4 };
	const auto numberOfAllowChoiceColumns_0to63{ 8 };
	const auto numberOfAllowChoiceColumns_0to127{ 16 };
	const auto numberOfAllowChoiceColumns_OscPitch{ 5 };
	
	const auto numberOfAllowChoiceRows_0to15{ 4 };
	const auto numberOfAllowChoiceRows_0to31{ 8 };
	const auto numberOfAllowChoiceRows_0to63{ 8 };
	const auto numberOfAllowChoiceRows_0to127{ 8 };
	const auto numberOfAllowChoiceRows_OscPitch{ 12 };

	const auto widthOfAllowChoiceColumns_0to15{ 18 };
	const auto widthOfAllowChoiceColumns_0to31{ 18 };
	const auto widthOfAllowChoiceColumns_0to63{ 18 };
	const auto widthOfAllowChoiceColumns_0to127{ 24 };
	const auto widthOfAllowChoiceColumns_OscPitch{ 26 };

	const auto allowedChoices_x_KnobOffset_Right{ 27 };
	const auto allowedChoices_x_SwitchOffset{ 20 };

	// ------------------------------------------------------------------------------------------------------------- oscillators

	const auto oscCol_1_x{ 523 };
	const auto oscCol_2_x{ 609 };
	const auto oscCol_3_x{ 683 };
	const auto oscCol_4_x{ 743 };
	const auto oscCol_5_x{ 803 };
	const auto oscCol_6_x{ 877 };

	for (auto oscNum = 0; oscNum != 2; ++oscNum) {
		String oscLetter{ oscNum == 0 ? "A" : "B" };
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 0 ? "ep_00" : "ep_06", {
					{ ID::property_ParamID, oscNum == 0 ? ID::ep_00_Osc_A_Freq.toString() : ID::ep_06_Osc_B_Freq.toString() },
					{ ID::property_ExposedName, "Oscillator " + oscLetter + " Frequency" },
					{ ID::property_ControlType, (int)ControlType::knobForPitch },
					{ ID::property_FirstNybbleIndex, oscNum == 0 ? 8 : 6 },
					{ ID::property_FirstBitIndex, oscNum == 0 ? 1 : 3 },
					{ ID::property_NumberOfBits, 6 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscFreq },
					{ ID::property_DefaultChoice, 12 },
					{ ID::property_ControlCenter_x, oscCol_1_x },
					{ ID::property_ControlCenter_y, oscNum == 0 ? knobRow_2_y : knobRow_3_y },
					{ ID::property_Control_w, GUI::knob_diameter },
					{ ID::property_Control_h, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForOscFreq(oscLetter) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_OscPitch },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_OscPitch },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_OscPitch },
					{ ID::property_AllowedChoicesBackground_x, oscCol_1_x + allowedChoices_x_KnobOffset_Right },
					{ ID::property_AllowedChoicesBackground_y, oscNum == 0 ? 10 : 52 },
			}, {
					ValueTree{ ChoiceNames::buildForOscFreq(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOscFreq(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 0 ? "ep_01" : "ep_07", {
					{ ID::property_ParamID, oscNum == 0 ? ID::ep_01_Osc_A_Sync.toString() : ID::ep_07_Osc_B_Fine.toString() },
					{ ID::property_ExposedName, "Oscillator " + oscLetter + (oscNum == 0 ? " Sync" : " Fine") },
					{ ID::property_ControlType, oscNum == 0 ? (int)ControlType::twoPoleSwitch : (int)ControlType::knob },
					{ ID::property_FirstNybbleIndex, oscNum == 0 ? 30 : 9 },
					{ ID::property_FirstBitIndex, oscNum == 0 ? 2 : 3 },
					{ ID::property_NumberOfBits, oscNum == 0 ? 1 : 7 },
					{ ID::property_NumberOfChoices, oscNum == 0 ? 2 : 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, oscCol_2_x },
					{ ID::property_ControlCenter_y, oscNum == 0 ? switchRow_1_y : knobRow_3_y },
					{ ID::property_Control_w, oscNum == 0 ? GUI::switch_w : GUI::knob_diameter },
					{ ID::property_Control_h, oscNum == 0 ? GUI::switch_2_Pole_h : GUI::knob_diameter },
					{ ID::property_Description,  oscNum == 0 ? Description::buildForOsc_A_Sync() : Description::buildForOsc_B_Fine() },
					{ ID::property_NumberOfAllowChoiceToggleColumns, oscNum == 0 ? 0 : numberOfAllowChoiceColumns_0to127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, oscNum == 0 ? 0 : widthOfAllowChoiceColumns_0to127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, oscNum == 0 ? 0 : numberOfAllowChoiceRows_0to127 },
					{ ID::property_AllowedChoicesBackground_x, oscCol_2_x + (oscNum == 0 ? allowedChoices_x_SwitchOffset : allowedChoices_x_KnobOffset_Right) },
					{ ID::property_AllowedChoicesBackground_y, oscNum == 0 ? switchRow_1_AllowedChoices_y : knobRow_3_AllowedChoices_0to127_y },
			}, {
					ValueTree{ oscNum == 0 ? ChoiceNames::buildForOffOn(ChoiceNameType::concise) : ChoiceNames::buildForPlainValue(128, ChoiceNameType::concise) },
					ValueTree{ oscNum == 0 ? ChoiceNames::buildForOffOn(ChoiceNameType::verbose) : ChoiceNames::buildForPlainValue(128, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 0 ? "ep_02" : "ep_08", {
					{ ID::property_ParamID, oscNum == 0 ? ID::ep_02_Osc_A_Saw.toString() : ID::ep_08_Osc_B_Saw.toString() },
					{ ID::property_ExposedName, "Oscillator " + oscLetter + " Shape: Sawtooth" },
					{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
					{ ID::property_FirstNybbleIndex, 30 },
					{ ID::property_FirstBitIndex, oscNum == 0 ? 0 : 3 },
					{ ID::property_NumberOfBits, 1 },
					{ ID::property_NumberOfChoices, 2 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, oscCol_3_x },
					{ ID::property_ControlCenter_y, oscNum == 0 ? switchRow_1_y : switchRow_2_y },
					{ ID::property_Control_w, GUI::switch_w },
					{ ID::property_Control_h, GUI::switch_2_Pole_h },
					{ ID::property_Description,  "When on, oscillator " + oscLetter + " outputs a sawtooth wave." },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_AllowedChoicesBackground_x, oscCol_3_x + allowedChoices_x_SwitchOffset },
					{ ID::property_AllowedChoicesBackground_y, oscNum == 0 ? switchRow_1_AllowedChoices_y : switchRow_2_AllowedChoices_y },
			}, {
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 0 ? "ep_03" : "ep_09", {
					{ ID::property_ParamID, oscNum == 0 ? ID::ep_03_Osc_A_Tri.toString() : ID::ep_09_Osc_B_Tri.toString() },
					{ ID::property_ExposedName, "Oscillator " + oscLetter + " Shape: Triangle" },
					{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
					{ ID::property_FirstNybbleIndex, oscNum == 0 ? 30 : 31 },
					{ ID::property_FirstBitIndex, oscNum == 0 ? 1 : 0 },
					{ ID::property_NumberOfBits, 1 },
					{ ID::property_NumberOfChoices, 2 },
					{ ID::property_DefaultChoice, 1 },
					{ ID::property_ControlCenter_x, oscCol_4_x },
					{ ID::property_ControlCenter_y, oscNum == 0 ? switchRow_1_y : switchRow_2_y },
					{ ID::property_Control_w, GUI::switch_w },
					{ ID::property_Control_h, GUI::switch_2_Pole_h },
					{ ID::property_Description,  "When on, oscillator " + oscLetter + " outputs a triangle wave." },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_AllowedChoicesBackground_x, oscCol_4_x + allowedChoices_x_SwitchOffset },
					{ ID::property_AllowedChoicesBackground_y, oscNum == 0 ? switchRow_1_AllowedChoices_y : switchRow_2_AllowedChoices_y },
			}, {
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 0 ? "ep_04" : "ep_10", {
					{ ID::property_ParamID, oscNum == 0 ? ID::ep_04_Osc_A_Pulse.toString() : ID::ep_10_Osc_B_Pulse.toString() },
					{ ID::property_ExposedName, "Oscillator " + oscLetter + " Shape: Pulse" },
					{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
					{ ID::property_FirstNybbleIndex, 28 },
					{ ID::property_FirstBitIndex, oscNum == 0 ? 0 : 1 },
					{ ID::property_NumberOfBits, 1 },
					{ ID::property_NumberOfChoices, 2 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, oscCol_5_x },
					{ ID::property_ControlCenter_y, oscNum == 0 ? switchRow_1_y : switchRow_2_y },
					{ ID::property_Control_w, GUI::switch_w },
					{ ID::property_Control_h, GUI::switch_2_Pole_h },
					{ ID::property_Description,  "When on, oscillator " + oscLetter + " outputs a pulse wave." },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_AllowedChoicesBackground_x, oscCol_5_x + allowedChoices_x_SwitchOffset },
					{ ID::property_AllowedChoicesBackground_y, oscNum == 0 ? switchRow_1_AllowedChoices_y : switchRow_2_AllowedChoices_y },
			}, {
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 0 ? "ep_05" : "ep_11", {
					{ ID::property_ParamID, oscNum == 0 ? ID::ep_05_Osc_A_PulseWidth.toString() : ID::ep_11_Osc_B_PulseWidth.toString() },
					{ ID::property_ExposedName, "Oscillator " + oscLetter + " Pulse Width" },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_FirstNybbleIndex, oscNum == 0 ? 0 : 26 },
					{ ID::property_FirstBitIndex, oscNum == 0 ? 0 : 1 },
					{ ID::property_NumberOfBits, 7 },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 64 },
					{ ID::property_ControlCenter_x, oscCol_6_x },
					{ ID::property_ControlCenter_y, oscNum == 0 ? knobRow_2_y : knobRow_3_y },
					{ ID::property_Control_w, GUI::knob_diameter },
					{ ID::property_Control_h, GUI::knob_diameter },
					{ ID::property_Description,  Description::buildForOscPulseWidth(oscLetter) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
					{ ID::property_AllowedChoicesBackground_x, oscCol_6_x + allowedChoices_x_KnobOffset_Right },
					{ ID::property_AllowedChoicesBackground_y, oscNum == 0 ? knobRow_2_AllowedChoices_0to127_y : knobRow_3_AllowedChoices_0to127_y },
			}, {
					ValueTree{ ChoiceNames::buildForPlainValue(128, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForPlainValue(128, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);
	}

	// ----------------------------------------------------------------------------------------------------------- mixer / glide

	const auto mixerGlide_x{ 999 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_12", {
				{ ID::property_ParamID, ID::ep_12_Mixer.toString() },
				{ ID::property_ExposedName, "Mixer" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 11 },
				{ ID::property_FirstBitIndex, 2 },
				{ ID::property_NumberOfBits, 6 },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 32 },
				{ ID::property_ControlCenter_x, mixerGlide_x },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForMixer() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to63 },
				{ ID::property_AllowedChoicesBackground_x, mixerGlide_x + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to63_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_13", {
				{ ID::property_ParamID, ID::ep_13_Glide.toString() },
				{ ID::property_ExposedName, "Glide" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 25 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, mixerGlide_x },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForGlide() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, mixerGlide_x + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// ------------------------------------------------------------------------------------------------------------------ filter

	const auto filterAmpCol_horizSpacing{ 75 };
	const auto filterAmpCol_1_x{ 1117 };
	const auto filterAmpCol_2_x{ filterAmpCol_1_x + filterAmpCol_horizSpacing };
	const auto filterAmpCol_3_x{ filterAmpCol_2_x + filterAmpCol_horizSpacing };
	const auto filterAmpCol_4_x{ filterAmpCol_3_x + filterAmpCol_horizSpacing };
	const auto allowedChoices_x_KnobOffset_Left_0to15{ 171 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_14", {
				{ ID::property_ParamID, ID::ep_14_FilterCutoff.toString() },
				{ ID::property_ExposedName, "Filter Cutoff Frequency" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 13 },
				{ ID::property_FirstBitIndex, 0 },
				{ ID::property_NumberOfBits, 7 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_ControlCenter_x, filterAmpCol_1_x },
				{ ID::property_ControlCenter_y, knobRow_1_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForFilterCutoff() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_AllowedChoicesBackground_x, 676 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_1_AllowedChoices_0to127_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_15", {
				{ ID::property_ParamID, ID::ep_15_FilterReso.toString() },
				{ ID::property_ExposedName, "Filter Resonance" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 14 },
				{ ID::property_FirstBitIndex, 3 },
				{ ID::property_NumberOfBits, 6 },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 32 },
				{ ID::property_ControlCenter_x, filterAmpCol_2_x },
				{ ID::property_ControlCenter_y, knobRow_1_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForFilterReso() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to63 },
				{ ID::property_AllowedChoicesBackground_x, 991 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_1_AllowedChoices_0to63_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_16", {
				{ ID::property_ParamID, ID::ep_16_FilterEnvAmt.toString() },
				{ ID::property_ExposedName, "Filter Envelope Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 16 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_3_x },
				{ ID::property_ControlCenter_y, knobRow_1_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForFilterEnvAmt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_3_x - allowedChoices_x_KnobOffset_Left_0to15 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_1_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_17", {
				{ ID::property_ParamID, ID::ep_17_FilterKeyTrack.toString() },
				{ ID::property_ExposedName, "Filter Keyboard Tracking" },
				{ ID::property_ControlType, (int)ControlType::threePoleSwitch },
				{ ID::property_FirstNybbleIndex, 28 },
				{ ID::property_FirstBitIndex, 2 },
				{ ID::property_NumberOfBits, 2 },
				{ ID::property_NumberOfChoices, 3 },
				{ ID::property_DefaultChoice, 2 },
				{ ID::property_ControlCenter_x, 1338 },
				{ ID::property_ControlCenter_y, 72 },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_3_Pole_h },
				{ ID::property_Description,  Description::buildForFilterKeyTrack() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 28 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 3 },
				{ ID::property_AllowedChoicesBackground_x, 1174 },
				{ ID::property_AllowedChoicesBackground_y, 48 },
			}, {
				ValueTree{ ChoiceNames::buildForFilterKeyTrack(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForFilterKeyTrack(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_18", {
				{ ID::property_ParamID, ID::ep_18_FilterEnvAttack.toString() },
				{ ID::property_ExposedName, "Filter Envelope Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 20 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_1_x },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvAttack(EnvelopeType::filter) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_1_x + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_19", {
				{ ID::property_ParamID, ID::ep_19_FilterEnvDecay.toString() },
				{ ID::property_ExposedName, "Filter Envelope Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 19 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_2_x },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvDecay(EnvelopeType::filter) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_2_x + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_20", {
				{ ID::property_ParamID, ID::ep_20_FilterEnvSustain.toString() },
				{ ID::property_ExposedName, "Filter Envelope Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 18 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_3_x },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvSustain(EnvelopeType::filter) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_3_x - allowedChoices_x_KnobOffset_Left_0to15 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_21", {
				{ ID::property_ParamID, ID::ep_21_FilterEnvRelease.toString() },
				{ ID::property_ExposedName, "Filter Envelope Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 17 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_4_x },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvRelease(EnvelopeType::filter) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_4_x - allowedChoices_x_KnobOffset_Left_0to15 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------- amplifier

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_22", {
				{ ID::property_ParamID, ID::ep_22_AmpEnvAttack.toString() },
				{ ID::property_ExposedName, "Amplifier Envelope Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 24 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_1_x },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvAttack(EnvelopeType::amplifier) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_1_x + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_23", {
				{ ID::property_ParamID, ID::ep_23_AmpEnvDecay.toString() },
				{ ID::property_ExposedName, "Amplifier Envelope Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 23 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_2_x },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvDecay(EnvelopeType::amplifier) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_2_x + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_24", {
				{ ID::property_ParamID, ID::ep_24_AmpEnvSustain.toString() },
				{ ID::property_ExposedName, "Amplifier Envelope Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 22 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 15 },
				{ ID::property_ControlCenter_x, filterAmpCol_3_x },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvSustain(EnvelopeType::amplifier) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_3_x - allowedChoices_x_KnobOffset_Left_0to15 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_25", {
				{ ID::property_ParamID, ID::ep_25_AmpEnvRelease.toString() },
				{ ID::property_ExposedName, "Amplifier Envelope Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 21 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, filterAmpCol_4_x },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForEnvRelease(EnvelopeType::amplifier) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, filterAmpCol_4_x - allowedChoices_x_KnobOffset_Left_0to15 },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// ---------------------------------------------------------------------------------------------------------------- poly-mod

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_26", {
				{ ID::property_ParamID, ID::ep_26_PolyModAmt_FilterEnv.toString() },
				{ ID::property_ExposedName, "Poly-Mod Filter Envelope Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 1 },
				{ ID::property_FirstBitIndex, 3 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 60 },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForPolyModAmt_FilterEnv() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, 60 + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_27", {
				{ ID::property_ParamID, ID::ep_27_PolyModAmt_Osc_B.toString() },
				{ ID::property_ExposedName, "Poly-Mod Oscillator B Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 3 },
				{ ID::property_FirstBitIndex, 3 },
				{ ID::property_NumberOfBits, 7 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 204 },
				{ ID::property_ControlCenter_y, knobRow_2_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForPolyModAmt_Osc_B() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_AllowedChoicesBackground_x, 204 + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_2_AllowedChoices_0to127_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_28", {
				{ ID::property_ParamID, ID::ep_28_PolyModDest_Osc_A_Freq.toString() },
				{ ID::property_ExposedName, "Poly-Mod Destination: Oscillator A Frequency" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 31 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 307 },
				{ ID::property_ControlCenter_y, switchRow_1_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForPolyModDest_Osc_A_Freq() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 307 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_1_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_29", {
				{ ID::property_ParamID, ID::ep_29_PolyModDest_Filter.toString() },
				{ ID::property_ExposedName, "Poly-Mod Destination: Filter Cutoff Frequency" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 31 },
				{ ID::property_FirstBitIndex, 2 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 367 },
				{ ID::property_ControlCenter_y, switchRow_1_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForPolyModDest_Filter() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 367 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_1_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// ------------------------------------------------------------------------------------------------------------------ unison

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_30", {
				{ ID::property_ParamID, ID::ep_30_UnisonTrack.toString() },
				{ ID::property_ExposedName, "Unison Tracking" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 31 },
				{ ID::property_FirstBitIndex, 3 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 441 },
				{ ID::property_ControlCenter_y, switchRow_1_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForUnisonTrack() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 441 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_1_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------------- LFO

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_31", {
				{ ID::property_ParamID, ID::ep_31_LFO_Freq.toString() },
				{ ID::property_ExposedName, "LFO Frequency" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 2 },
				{ ID::property_FirstBitIndex, 3 },
				{ ID::property_NumberOfBits, 4 },
				{ ID::property_NumberOfChoices, 16 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 60 },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForLFO_Freq() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to15 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to15 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to15 },
				{ ID::property_AllowedChoicesBackground_x, 60 + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to15_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(16, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_32", {
				{ ID::property_ParamID, ID::ep_32_LFO_Shape.toString() },
				{ ID::property_ExposedName, "LFO Wave Shape" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 29 },
				{ ID::property_FirstBitIndex, 0 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 1 },
				{ ID::property_ControlCenter_x, 146 },
				{ ID::property_ControlCenter_y, switchRow_2_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForLFO_Shape() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 146 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForLFO_Shape(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForLFO_Shape(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_33", {
				{ ID::property_ParamID, ID::ep_33_LFO_InitAmount.toString() },
				{ ID::property_ExposedName, "LFO Initial Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_FirstNybbleIndex, 5 },
				{ ID::property_FirstBitIndex, 2 },
				{ ID::property_NumberOfBits, 5 },
				{ ID::property_NumberOfChoices, 32 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 232 },
				{ ID::property_ControlCenter_y, knobRow_3_y },
				{ ID::property_Control_w, GUI::knob_diameter },
				{ ID::property_Control_h, GUI::knob_diameter },
				{ ID::property_Description,  Description::buildForLFO_InitAmount() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to31 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to31 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to31 },
				{ ID::property_AllowedChoicesBackground_x, 232 + allowedChoices_x_KnobOffset_Right },
				{ ID::property_AllowedChoicesBackground_y, knobRow_3_AllowedChoices_0to31_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(32, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(32, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_34", {
				{ ID::property_ParamID, ID::ep_34_LFO_Dest_Freq.toString() },
				{ ID::property_ExposedName, "LFO Destination: Oscillator Frequency" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 29 },
				{ ID::property_FirstBitIndex, 1 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 307 },
				{ ID::property_ControlCenter_y, switchRow_2_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForLFO_Dest_Freq() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 307 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_35", {
				{ ID::property_ParamID, ID::ep_35_LFO_Dest_PW.toString() },
				{ ID::property_ExposedName, "LFO Destination: Oscillator Pulse Width" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 29 },
				{ ID::property_FirstBitIndex, 2 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 367 },
				{ ID::property_ControlCenter_y, switchRow_2_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForLFO_Dest_PW() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 367 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_36", {
				{ ID::property_ParamID, ID::ep_36_LFO_Dest_Filter.toString() },
				{ ID::property_ExposedName, "LFO Destination: Filter Cutoff" },
				{ ID::property_ControlType, (int)ControlType::twoPoleSwitch },
				{ ID::property_FirstNybbleIndex, 29 },
				{ ID::property_FirstBitIndex, 3 },
				{ ID::property_NumberOfBits, 1 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, 427 },
				{ ID::property_ControlCenter_y, switchRow_2_y },
				{ ID::property_Control_w, GUI::switch_w },
				{ ID::property_Control_h, GUI::switch_2_Pole_h },
				{ ID::property_Description,  Description::buildForLFO_Dest_Filter() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_AllowedChoicesBackground_x, 427 + allowedChoices_x_SwitchOffset },
				{ ID::property_AllowedChoicesBackground_y, switchRow_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);
}

Identifier InfoForExposedParameters::IDfor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return Identifier{ paramTree.getProperty(ID::property_ParamID).toString() };
}

String InfoForExposedParameters::exposedNameFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return paramTree.getProperty(ID::property_ExposedName).toString();
}

ControlType InfoForExposedParameters::controlTypeFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return ControlType{ (int)paramTree.getProperty(ID::property_ControlType) };
}

uint8 InfoForExposedParameters::firstNybbleIndexFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint8((int)paramTree.getProperty(ID::property_FirstNybbleIndex));
}

uint8 InfoForExposedParameters::firstBitIndexFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint8((int)paramTree.getProperty(ID::property_FirstBitIndex));
}

uint8 InfoForExposedParameters::numberOfBitsFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint8((int)paramTree.getProperty(ID::property_NumberOfBits));
}

uint8 InfoForExposedParameters::numberOfChoicesFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint8((int)paramTree.getProperty(ID::property_NumberOfChoices));
}

uint8 InfoForExposedParameters::defaultChoiceFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint8((int)paramTree.getProperty(ID::property_DefaultChoice));
}

Point<int> InfoForExposedParameters::centerPointFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	auto center_x{ (int)paramTree.getProperty(ID::property_ControlCenter_x) };
	auto center_y{ (int)paramTree.getProperty(ID::property_ControlCenter_y) };
	return Point<int>{ center_x, center_y };
}

int InfoForExposedParameters::widthFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_Control_w);
}

int InfoForExposedParameters::heightFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_Control_h);
}

String InfoForExposedParameters::descriptionFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return paramTree.getProperty(ID::property_Description).toString();
}

String InfoForExposedParameters::choiceNameFor(const uint8 choiceNum, const uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	auto choiceNamesTree{ paramTree.getChildWithName(ID::tree_ChoiceNames) };
	auto choiceName{ choiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return choiceName;
}

String InfoForExposedParameters::verboseChoiceNameFor(const uint8 choiceNum, const uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	auto choiceNamesTree{ paramTree.getChildWithName(ID::tree_ChoiceNames_Verbose) };
	auto verboseChoiceName{ choiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return verboseChoiceName;
}

StringArray InfoForExposedParameters::choiceNamesListFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	StringArray choiceNamesList;
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoicesFor(paramIndex); ++choiceNum)
		choiceNamesList.add(choiceNameFor(choiceNum, paramIndex));
	return choiceNamesList;
}

StringArray InfoForExposedParameters::verboseChoiceNamesListFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	StringArray verboseChoiceNamesList;
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoicesFor(paramIndex); ++choiceNum)
		verboseChoiceNamesList.add(verboseChoiceNameFor(choiceNum, paramIndex));
	return verboseChoiceNamesList;
}

int InfoForExposedParameters::mouseDragSensitivityFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	return 80 + roundToInt(numberOfChoicesFor(paramIndex) / 2);
}

int InfoForExposedParameters::numberOfAllowChoiceToggleColumnsFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_NumberOfAllowChoiceToggleColumns);
}

int InfoForExposedParameters::widthOfAllowChoiceToggleColumnFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_WidthOfAllowChoiceToggleColumn);
}

int InfoForExposedParameters::numberOfAllowChoiceToggleRowsFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_NumberOfAllowChoiceToggleRows);
}

int InfoForExposedParameters::allowedChoicesBackground_x_For(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_AllowedChoicesBackground_x);
}

int InfoForExposedParameters::allowedChoicesBackground_y_For(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_AllowedChoicesBackground_y);
}
