#include "ep_1_tree_InfoForExposedParameters.h"

#include "ep_0_build_ChoiceNamesValueTree.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_ExposedParamDescription.h"

using Description = ExposedParamDescription;
using ChoiceNames = ExposedParamChoiceNamesValueTree;

InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::tree_ExposedParamsInfo }
{
	const auto controlsRow_1_y{ 69 };
	const auto controlsRow_2_y{ controlsRow_1_y + GUI::vertDistBtwnRows };
	const auto controlsRow_3_y{ controlsRow_2_y + GUI::vertDistBtwnRows };
	const auto controlsRow_4_y{ controlsRow_3_y + GUI::vertDistBtwnRows };
	const auto controlsRow_5_y{ controlsRow_4_y + GUI::vertDistBtwnRows };
	const auto controlsRow_6_y{ controlsRow_5_y + GUI::vertDistBtwnRows };
	const auto controlsRow_7_y{ controlsRow_6_y + GUI::vertDistBtwnRows };
	const auto controlsRow_8_y{ controlsRow_7_y + GUI::vertDistBtwnRows };
	const auto controlsRow_9_y{ controlsRow_8_y + GUI::vertDistBtwnRows };
	const auto controlsRow_10_y{ controlsRow_9_y + GUI::vertDistBtwnRows };
	const auto controlsRow_11_y{ controlsRow_10_y + GUI::vertDistBtwnRows };
	const auto controlsRow_12_y{ controlsRow_11_y + GUI::vertDistBtwnRows };

	const int numberOfAllowChoiceColumns_0_To_63{ 8 };
	const int numberOfAllowChoiceColumns_0_To_127{ 16 };
	const int numberOfAllowChoiceColumns_PosNeg_31{ numberOfAllowChoiceColumns_0_To_63 };
	const int numberOfAllowChoiceColumns_PosNeg_63{ numberOfAllowChoiceColumns_0_To_127 };

	const int numberOfAllowChoiceRows_Numeric{ 8 };

	const int widthOfAllowChoiceColumns_0_To_63{ 16 };
	const int widthOfAllowChoiceColumns_0_To_127{ 22 };
	const int widthOfAllowChoiceColumns_PosNeg_31{ 26 };
	const int widthOfAllowChoiceColumns_PosNeg_63{ widthOfAllowChoiceColumns_PosNeg_31 };

	// ------------------------------------------------------------------------------------------------------------- oscillators

	const auto osc_1_x{ 130 };
	const auto osc_2_x{ 196 };
	const auto osc_w{ 60 };
	const auto osc_1_AllowedChoices_x{ 166 };
	const auto osc_2_AllowedChoices_x{ 232 };
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_00" : "ep_10", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_00_Osc_1_Pitch.toString() : ID::ep_10_Osc_2_Pitch.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 0 : 10 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pitch" },
				{ ID::property_ControlType, (int)ControlType::sliderForPitch },
				{ ID::property_DataByteIndex, oscNum == 1 ? 1 : 6 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::oscPitch },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_1_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOscPitch(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 6 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 30 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 12 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_1_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForOscPitch(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOscPitch(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_01" : "ep_11", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_01_Osc_1_Type.toString() : ID::ep_11_Osc_2_Type.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 6 : 16 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Type" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, oscNum == 1 ? 5 : 10 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, oscNum == 1 ? 4 : 5 },
				{ ID::property_DefaultChoice, oscNum == 1 ? 2 : 1 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_2_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOscType(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 32 },
				{ ID::property_NumberOfAllowChoiceToggleRows, oscNum == 1 ? 4 : 5 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_2_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForOscType(oscNum, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOscType(oscNum, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_02" : "ep_12", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_02_Osc_1_PulseWidth.toString() : ID::ep_12_Osc_2_PulseWidth.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 3 : 13 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pulse Width" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, oscNum == 1 ? 3 : 8 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, oscNum == 1 ? 31 : 24 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_3_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOscPulseWidth(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_3_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_03" : "ep_13", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_03_Osc_1_SawTri.toString() : ID::ep_13_Osc_2_SawTri.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 5 : 15 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Saw / Triangle Wave" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, oscNum == 1 ? 2 : 7 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 31 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_4_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOscSawTri(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_4_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_04" : "ep_14", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_04_Osc_1_Sync.toString() : ID::ep_14_Osc_2_Detune.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 2 : 12 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + (oscNum == 1 ? " Sync" : " Detune") },
				{ ID::property_ControlType, oscNum == 1 ? (int)ControlType::comboBox : (int)ControlType::slider },
				{ ID::property_DataByteIndex, oscNum == 1 ? 17 : 11 },
				{ ID::property_RangeType, oscNum == 1 ? (int)RangeType::unsignedValue : (int)RangeType::signed_6_bitValue },
				{ ID::property_SliderTextEditorType, oscNum == 1 ? -1 : (int)SliderTextEditorType::signed_6_bitValue},
				{ ID::property_NumberOfChoices, oscNum == 1 ? 4 : 63 },
				{ ID::property_DefaultChoice, oscNum == 1 ? 0 : 33 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_5_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, oscNum == 1 ? Description::buildForOsc_1_Sync() : Description::buildForOsc_2_Detune() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, oscNum == 1 ? 1 : numberOfAllowChoiceColumns_PosNeg_31 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, oscNum == 1 ? 28 : widthOfAllowChoiceColumns_PosNeg_31 },
				{ ID::property_NumberOfAllowChoiceToggleRows, oscNum == 1 ? 4 : numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, oscNum == 1 ? 0 : 1 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_5_y - GUI::control_h / 2 },
			}, {
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_Sync(ChoiceNameType::concise) : ChoiceNames::buildForSigned_6_BitValue(ChoiceNameType::concise) },
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_Sync(ChoiceNameType::verbose) : ChoiceNames::buildForSigned_6_BitValue(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_05" : "ep_15", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_05_Osc_1_LFO_1_FM.toString() : ID::ep_15_Osc_2_LFO_1_FM.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 1 : 11 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Frequency Mod. by LFO 1" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_DataByteIndex, oscNum == 1 ? 78 : 80 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_6_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOsc_LFO_1_FM(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63},
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_6_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_06" : "ep_16", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_06_Osc_1_LFO_2_PWM.toString() : ID::ep_16_Osc_2_LFO_2_PWM.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 4 : 14 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pulse Width Mod. by LFO 2" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, oscNum == 1 ? 79 : 81 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_7_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOsc_LFO_2_PWM(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63},
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_7_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_07" : "ep_17", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_07_Osc_1_KeyClick.toString() : ID::ep_17_Osc_2_KeyClick.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 9 : 19 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Key Click" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, oscNum == 1 ? 14 : 16 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_8_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOscKeyClick() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0},
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_8_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_08" : "ep_18", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_08_Osc_1_KeyTrack.toString() : ID::ep_18_Osc_2_KeyTrack.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 8 : 18 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Key Tracking" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, oscNum == 1 ? 13 : 15 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, oscNum == 1 ? 2 : 3 },
				{ ID::property_DefaultChoice, oscNum == 1 ? 0 : 2 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_9_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForOscKeyTrack(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, oscNum == 1 ? 0 : 1},
				{ ID::property_WidthOfAllowChoiceToggleColumn, oscNum == 1 ? 0 : 34 },
				{ ID::property_NumberOfAllowChoiceToggleRows, oscNum == 1 ? 0 : 3 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_9_y - GUI::control_h / 2 },
			}, {
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_KeyTrack(ChoiceNameType::concise) : ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(ChoiceNameType::concise) },
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_KeyTrack(ChoiceNameType::verbose) : ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_09" : "ep_19", {
				{ ID::property_ParamID, oscNum == 1 ? ID::ep_09_Osc_1_LeverControl.toString() : ID::ep_19_Osc_2_LeverControl.toString() },
				{ ID::property_ParamNum, oscNum == 1 ? 7 : 17 },
				{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Lever Control" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, oscNum == 1 ? 4 : 9 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 4 },
				{ ID::property_DefaultChoice, 3 },
				{ ID::property_ControlCenter_x, oscNum == 1 ? osc_1_x : osc_2_x },
				{ ID::property_ControlCenter_y, controlsRow_10_y },
				{ ID::property_ControlWidth, osc_w },
				{ ID::property_Description, Description::buildForLeverControl(oscNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 28 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, oscNum == 1 ? osc_1_AllowedChoices_x : osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_10_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForLeverControl(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForLeverControl(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);
	}

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_20", {
				{ ID::property_ParamID, ID::ep_20_OscBalance.toString() },
				{ ID::property_ParamNum, 20 },
				{ ID::property_ExposedName, "Oscillator Balance" },
				{ ID::property_ControlType, (int)ControlType::sliderForOscBalance },
				{ ID::property_DataByteIndex, 12 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 31 },
				{ ID::property_ControlCenter_x, 163 },
				{ ID::property_ControlCenter_y, controlsRow_11_y },
				{ ID::property_ControlWidth, 126 },
				{ ID::property_Description, Description::buildForOscBalance() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, osc_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_11_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------------- VCF

	const auto vcf_vca_x{ 382 };
	const auto vcf_vca_w{ 60 };
	const auto vcf_vca_AllowedChoices_x{ 418 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_21", {
				{ ID::property_ParamID, ID::ep_21_VCF_Freq.toString() },
				{ ID::property_ParamNum, 21 },
				{ ID::property_ExposedName, "VCF Cutoff Frequency" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 18 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 55 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_1_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_Freq() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_1_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(128, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(128, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_22", {
				{ ID::property_ParamID, ID::ep_22_VCF_Reso.toString() },
				{ ID::property_ParamNum, 24 },
				{ ID::property_ExposedName, "VCF Resonance" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 19 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_2_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_Reso() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_2_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_23", {
				{ ID::property_ParamID, ID::ep_23_VCF_Env_1_Amt.toString() },
				{ ID::property_ParamNum, 22 },
				{ ID::property_ExposedName, "VCF Envelope 1 Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 82 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 105 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_3_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_Env_1_Amt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_3_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_24", {
				{ ID::property_ParamID, ID::ep_24_VCF_PressureAmt.toString() },
				{ ID::property_ParamNum, 23 },
				{ ID::property_ExposedName, "VCF Pressure Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 83 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_4_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_PressureAmt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_4_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_25", {
				{ ID::property_ParamID, ID::ep_25_VCF_LeverControl.toString() },
				{ ID::property_ParamNum, 25 },
				{ ID::property_ExposedName, "VCF Lever Control" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, 20 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 4 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_5_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_LeverControl() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 28 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_5_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForLeverControl(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForLeverControl(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_26", {
				{ ID::property_ParamID, ID::ep_26_VCF_KeyTrack.toString() },
				{ ID::property_ParamNum, 26 },
				{ ID::property_ExposedName, "VCF Key Tracking" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, 21 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 3 },
				{ ID::property_DefaultChoice, 2 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_6_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_LeverControl() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1},
				{ ID::property_WidthOfAllowChoiceToggleColumn, 34 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 3 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x,vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_6_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------------- VCA

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_27", {
				{ ID::property_ParamID, ID::ep_27_VCA_1_Volume.toString() },
				{ ID::property_ParamNum, 27 },
				{ ID::property_ExposedName, "VCA 1 Volume" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 23 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_9_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCA_1_Volume() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_9_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_28", {
				{ ID::property_ParamID, ID::ep_28_VCA_1_VeloAmt.toString() },
				{ ID::property_ParamNum, 28 },
				{ ID::property_ExposedName, "VCA 1 Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 84 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_10_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCA_1_VeloAmt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_10_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_29", {
				{ ID::property_ParamID, ID::ep_29_VCA_2_Env_2_Amt.toString() },
				{ ID::property_ParamNum, 29 },
				{ ID::property_ExposedName, "VCA 2 Envelope 2 Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 85 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 126 },
				{ ID::property_ControlCenter_x, vcf_vca_x },
				{ ID::property_ControlCenter_y, controlsRow_11_y },
				{ ID::property_ControlWidth, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCA_1_VeloAmt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, vcf_vca_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_11_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// ------------------------------------------------------------------------------------------------------------------ VCF FM

	const auto vcf_fm_x{ 550 };
	const auto vcf_fm_w{ 60 };
	const auto col_3_AllowedChoices_x{ 586 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_30", {
				{ ID::property_ParamID, ID::ep_30_VCF_FM_Osc_1_Amt.toString() },
				{ ID::property_ParamNum, 30 },
				{ ID::property_ExposedName, "VCF FM By Oscillator 1 Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 22 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, vcf_fm_x },
				{ ID::property_ControlCenter_y, controlsRow_1_y },
				{ ID::property_ControlWidth, vcf_fm_w },
				{ ID::property_Description, Description::buildFor_VCF_FM_Osc_1_Amt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_1_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_31", {
				{ ID::property_ParamID, ID::ep_31_VCF_FM_Env_3_Amt.toString() },
				{ ID::property_ParamNum, 31 },
				{ ID::property_ExposedName, "VCF FM Envelope 3 Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 92 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, vcf_fm_x },
				{ ID::property_ControlCenter_y, controlsRow_2_y },
				{ ID::property_ControlWidth, vcf_fm_w },
				{ ID::property_Description, Description::buildFor_VCF_FM_Env_3_Amt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_2_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_32", {
				{ ID::property_ParamID, ID::ep_32_VCF_FM_PressureAmt.toString() },
				{ ID::property_ParamNum, 32 },
				{ ID::property_ExposedName, "VCF FM Pressure Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 93 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, vcf_fm_x },
				{ ID::property_ControlCenter_y, controlsRow_3_y },
				{ ID::property_ControlWidth, vcf_fm_w },
				{ ID::property_Description, Description::buildFor_VCF_FM_PressureAmt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_3_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// -------------------------------------------------------------------------------------------------------------- Portamento

	const auto porta_keyMode_x{ 544 };
	const auto porta_keyMode_w{ 72 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_33", {
				{ ID::property_ParamID, ID::ep_33_PortaRate.toString() },
				{ ID::property_ParamNum, 44 },
				{ ID::property_ExposedName, "Portamento Rate" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 24 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, porta_keyMode_x },
				{ ID::property_ControlCenter_y, controlsRow_6_y },
				{ ID::property_ControlWidth, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaRate() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_6_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_34", {
				{ ID::property_ParamID, ID::ep_34_PortaVelo.toString() },
				{ ID::property_ParamNum, 45 },
				{ ID::property_ExposedName, "Portamento Rate" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, 91 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, porta_keyMode_x },
				{ ID::property_ControlCenter_y, controlsRow_7_y },
				{ ID::property_ControlWidth, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaVelo() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_7_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_35", {
				{ ID::property_ParamID, ID::ep_35_PortaMode.toString() },
				{ ID::property_ParamNum, 46 },
				{ ID::property_ExposedName, "Portamento Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, 25 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 3 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, porta_keyMode_x },
				{ ID::property_ControlCenter_y, controlsRow_8_y },
				{ ID::property_ControlWidth, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaMode() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 36 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 3 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_8_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForPortaMode(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForPortaMode(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_36", {
				{ ID::property_ParamID, ID::ep_36_PortaLegato.toString() },
				{ ID::property_ParamNum, 47 },
				{ ID::property_ExposedName, "Portamento Legato Off / On" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, 26 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, porta_keyMode_x },
				{ ID::property_ControlCenter_y, controlsRow_9_y },
				{ ID::property_ControlWidth, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaLegato() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0},
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_9_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// ----------------------------------------------------------------------------------------------------------- Keyboard Mode

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_37", {
				{ ID::property_ParamID, ID::ep_37_KeyboardMode.toString() },
				{ ID::property_ParamNum, 48 },
				{ ID::property_ExposedName, "Keyboard Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, 0 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 4 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, porta_keyMode_x },
				{ ID::property_ControlCenter_y, controlsRow_12_y },
				{ ID::property_ControlWidth, porta_keyMode_w },
				{ ID::property_Description, Description::buildForKeyboardMode() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1},
				{ ID::property_WidthOfAllowChoiceToggleColumn, 40 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_3_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_12_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForKeyboardMode(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForKeyboardMode(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------------- LFO

	const auto lfo_1_x{ 726 };
	const auto lfo_2_x{ 792 };
	const auto lfo_w{ 60 };
	const auto lfo_1_AllowedChoices_x{ 762 };
	const auto lfo_2_AllowedChoices_x{ 828 };
	for (auto lfoNum = 1; lfoNum != 3; ++lfoNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_38" : "ep_47", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_38_LFO_1_Speed.toString() : ID::ep_47_LFO_2_Speed.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 80 : 90 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Speed" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 27 : 34 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, lfoNum == 1 ? 40 : 30 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_1_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_Speed(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_1_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_39" : "ep_48", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_39_LFO_1_WaveType.toString() : ID::ep_48_LFO_2_WaveType.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 82 : 92 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Wave Type" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 30 : 37 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 7 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_2_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_WaveType(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 38 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 7 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_2_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildFor_LFO_WaveType(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_WaveType(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_40" : "ep_49", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_40_LFO_1_SampleSource.toString() : ID::ep_49_LFO_2_SampleSource.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 88 : 98 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Sample Source" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 32 : 39 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 21 },
				{ ID::property_DefaultChoice, 9 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_3_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_SampleSource(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 3 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 30 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 7 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_3_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildFor_LFO_SampleSource(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_SampleSource(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_41" : "ep_50", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_41_LFO_1_Amp.toString() : ID::ep_50_LFO_2_Amp.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 84 : 94 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Amplitude" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 33 : 40 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_4_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_Amp(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_4_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_42" : "ep_51", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_42_LFO_1_PressureAmt.toString() : ID::ep_51_LFO_2_KeyTrackAmt.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 81 : 91 },
				{ ID::property_ExposedName, lfoNum == 1 ? "LFO 1 Pressure Amount" : "LFO 2 Key Tracking Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 94 : 95 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_5_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, lfoNum == 1 ? Description::buildFor_LFO_1_PressureAmt() : Description::buildFor_LFO_2_KeyTrackAmt() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63},
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, (lfoNum == 1 ? lfo_1_x : lfo_2_x) - lfo_w / 2 },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_5_y + GUI::control_h / 2 + 6 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_43" : "ep_52", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_43_LFO_1_Ramp_1_Amt.toString() : ID::ep_52_LFO_2_Ramp_2_Amt.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 85 : 95 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Ramp " + (String)lfoNum + " Amount" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 89 : 90 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 126 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_6_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_RampAmt(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 1 },
				{ ID::property_AllowedChoicesBackground_x, (lfoNum == 1 ? lfo_1_x : lfo_2_x) - lfo_w / 2 },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_6_y + GUI::control_h / 2 + 6 },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
			}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_44" : "ep_53", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_44_LFO_1_TrigMode.toString() : ID::ep_53_LFO_2_TrigMode.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 86 : 96 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Trigger Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 28 : 35 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 4 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_7_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_TrigMode(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 34 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_7_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildFor_LFO_TrigMode(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_TrigMode(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_45" : "ep_54", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_45_LFO_1_RetrigPoint.toString() : ID::ep_54_LFO_2_RetrigPoint.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 83 : 93 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Retrigger Point" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 31 : 38 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_8_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_RetrigPoint(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_8_y - GUI::control_h / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
			}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_46" : "ep_55", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_46_LFO_1_Lag.toString() : ID::ep_55_LFO_2_Lag.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 87 : 97 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Lag Processing Off / On" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 29 : 36 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_ControlCenter_y, controlsRow_9_y },
				{ ID::property_ControlWidth, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_Lag(lfoNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, lfoNum == 1 ? lfo_1_AllowedChoices_x : lfo_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_9_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForOffOn(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);
	}

	// -------------------------------------------------------------------------------------------------------------------- Ramp

	const auto ramp_1_x{ 894 };
	const auto ramp_2_x{ 960 };
	const auto ramp_1_AllowedChoices_x{ 930 };
	const auto ramp_2_AllowedChoices_x{ 996 };
	const auto ramp_w{ 60 };
	for (auto rampNum = 1; rampNum != 3; ++rampNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ rampNum == 1 ? "ep_56" : "ep_58", {
				{ ID::property_ParamID, rampNum == 1 ? ID::ep_56_Ramp_1_Rate.toString() : ID::ep_58_Ramp_2_Rate.toString() },
				{ ID::property_ParamNum, rampNum == 1 ? 40 : 42 },
				{ ID::property_ExposedName, "Ramp " + (String)rampNum + " Rate" },
				{ ID::property_ControlType, (int)ControlType::slider },
				{ ID::property_DataByteIndex, rampNum == 1 ? 74 : 76 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, rampNum == 1 ? ramp_1_x : ramp_2_x },
				{ ID::property_ControlCenter_y, controlsRow_1_y },
				{ ID::property_ControlWidth, ramp_w },
				{ ID::property_Description, Description::buildForRampRate(rampNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, rampNum == 1 ? ramp_1_AllowedChoices_x : ramp_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_1_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ rampNum == 1 ? "ep_57" : "ep_59", {
				{ ID::property_ParamID, rampNum == 1 ? ID::ep_57_Ramp_1_Trig.toString() : ID::ep_59_Ramp_2_Trig.toString() },
				{ ID::property_ParamNum, rampNum == 1 ? 41 : 43 },
				{ ID::property_ExposedName, "Ramp " + (String)rampNum + " Trigger" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, rampNum == 1 ? 75 : 77 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 4 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_ControlCenter_x, rampNum == 1 ? ramp_1_x : ramp_2_x },
				{ ID::property_ControlCenter_y, controlsRow_2_y },
				{ ID::property_ControlWidth, ramp_w },
				{ ID::property_Description, Description::buildForRampTrig(rampNum) },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 34 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, rampNum == 1 ? ramp_1_AllowedChoices_x : ramp_2_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, controlsRow_2_y - GUI::control_h / 2 },
			}, {
					ValueTree{ ChoiceNames::buildForRampTrig(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForRampTrig(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);
	}

	// ---------------------------------------------------------------------------------------------------------------- Tracking

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_60", {
				{ ID::property_ParamID, ID::ep_60_TrackInput.toString() },
				{ ID::property_ParamNum, 33 },
				{ ID::property_ExposedName, "Tracking Generator Input" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_DataByteIndex, 68 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 21 },
				{ ID::property_DefaultChoice, 9 },
				{ ID::property_ControlCenter_x, 943 },
				{ ID::property_ControlCenter_y, 165 },
				{ ID::property_ControlWidth, 94 },
				{ ID::property_Description, Description::buildForTrackInput() },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 3 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 50 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 7 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 996 },
				{ ID::property_AllowedChoicesBackground_y, 155 },
			}, {
				ValueTree{ ChoiceNames::buildForTrackingInputSource(ChoiceNameType::concise) },
				ValueTree{ ChoiceNames::buildForTrackingInputSource(ChoiceNameType::verbose) }
			}
		}, -1, nullptr);

	const auto trackPoint_1_x{ 853 };
	const auto trackPoint_horizSpacing{ 31 };
	const auto trackPoint_w{ 26 };
	const auto trackPoint_y{ 279 };
	const auto trackPoint_1_AllowedChoices_x{ 872 };
	for (auto pointNum = 1; pointNum != 6; ++pointNum) {
		auto defaultChoice{ 0 };
		if (pointNum == 2)
			defaultChoice = 15;
		if (pointNum > 2)
			defaultChoice = 15 + (pointNum - 2) * 16;
		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_6" + (String)pointNum, {
					{ ID::property_ParamID, "ep_6" + (String)pointNum + "_TrackPoint_" + (String)pointNum },
					{ ID::property_ParamNum, 33 + pointNum },
					{ ID::property_ExposedName, "Tracking Point " + (String)pointNum },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 68 + pointNum },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, defaultChoice },
					{ ID::property_ControlCenter_x, trackPoint_1_x + (pointNum - 1) * trackPoint_horizSpacing },
					{ ID::property_ControlCenter_y, trackPoint_y },
					{ ID::property_ControlWidth, trackPoint_w },
					{ ID::property_Description, Description::buildForTrackPoint(pointNum, defaultChoice) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, trackPoint_1_AllowedChoices_x + (pointNum - 1) * trackPoint_horizSpacing },
					{ ID::property_AllowedChoicesBackground_y, trackPoint_y - GUI::control_h / 2 },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);
	}

	// --------------------------------------------------------------------------------------------------------------- Envelopes

	const auto envControlsBlock_horizSpacing{ 410 };
	const auto env_DADSR_horizSpacing{ 50 };
	const auto env_1_Controls_x{ 134 };
	const auto env_1_Delay_x{ 198 };
	const auto env_1_Attack_x{ env_1_Delay_x + env_DADSR_horizSpacing };
	const auto env_1_Decay_x{ env_1_Attack_x + env_DADSR_horizSpacing };
	const auto env_1_Sustain_x{ env_1_Decay_x + env_DADSR_horizSpacing };
	const auto env_1_Release_x{ env_1_Sustain_x + env_DADSR_horizSpacing };
	const auto envControlsRow_1_y{ 450 };
	const auto envControlsRow_2_y{ envControlsRow_1_y + GUI::vertDistBtwnRows };
	const auto envControlsRow_3_y{ envControlsRow_2_y + GUI::vertDistBtwnRows };
	const auto envControlsRow_4_y{ envControlsRow_3_y + GUI::vertDistBtwnRows };
	const auto envControlsRow_5_y{ envControlsRow_4_y + GUI::vertDistBtwnRows };
	const auto envControls_w{ 72 };
	const auto envControls_DADSR_w{ 28 };
	const auto env_1_AllowedChoices_x{ 176 };
	const auto env_1_Delay_AllowedChoices_x{ 34 };
	const auto env_1_Attack_AllowedChoices_x{ env_1_Delay_AllowedChoices_x + env_DADSR_horizSpacing };
	const auto env_1_Decay_AllowedChoices_x{ env_1_Attack_AllowedChoices_x + env_DADSR_horizSpacing };
	const auto env_1_Sustain_AllowedChoices_x{ env_1_Decay_AllowedChoices_x + env_DADSR_horizSpacing };
	const auto env_1_Release_AllowedChoices_x{ env_1_Sustain_AllowedChoices_x + env_DADSR_horizSpacing };
	const auto envControls_DADSR_AllowedChoices_y{ 280 };
	for (auto envNum = 0; envNum != 3; ++envNum) {
		auto envNumString{ String(envNum + 1) };
		auto envOffset{ envNum * 10 };
		auto epTreeID{ "ep_" + String(66 + envOffset)};
		auto datByteOffset{ envNum * 9 };
		auto envBlockOffset{ envNum * envControlsBlock_horizSpacing };
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Amp" },
					{ ID::property_ParamNum, 55 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Amplitude" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 47 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, 40 },
					{ ID::property_ControlCenter_x, env_1_Controls_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_1_y },
					{ ID::property_ControlWidth, envControls_w },
					{ ID::property_Description, Description::buildForEnvAmp(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_AllowedChoices_x + envBlockOffset  },
					{ ID::property_AllowedChoicesBackground_y, 222 },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(67 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_VeloAmt" },
					{ ID::property_ParamNum, 56 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Velocity Amount" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 86 + envNum },
					{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::signed_7_bitValue },
					{ ID::property_NumberOfChoices, 127 },
					{ ID::property_DefaultChoice, 126 },
					{ ID::property_ControlCenter_x, env_1_Controls_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_2_y },
					{ ID::property_ControlWidth, envControls_w },
					{ ID::property_Description, Description::buildForEnvVeloAmt(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 1 },
					{ ID::property_AllowedChoicesBackground_x, envNum == 0 ? 98 : envNum == 1 ? 508 : 524 },
					{ ID::property_AllowedChoicesBackground_y, 222 },
				}, {
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(68 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_TrigMode" },
					{ ID::property_ParamNum, 57 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Trigger Mode" },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_DataByteIndex, 41 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 8 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, env_1_Controls_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_3_y },
					{ ID::property_ControlWidth, envControls_w },
					{ ID::property_Description, Description::buildForEnvTrigMode(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 2 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 40 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_AllowedChoices_x + envBlockOffset },
					{ ID::property_AllowedChoicesBackground_y, 312 },
				}, {
					ValueTree{ ChoiceNames::buildForEnvTrigMode(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForEnvTrigMode(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(69 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Mode" },
					{ ID::property_ParamNum, 58 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Mode" },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_DataByteIndex, 49 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 4 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, env_1_Controls_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_4_y },
					{ ID::property_ControlWidth, envControls_w },
					{ ID::property_Description, Description::buildForEnvMode(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 42 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_AllowedChoices_x + envBlockOffset },
					{ ID::property_AllowedChoicesBackground_y, 340 },
				}, {
					ValueTree{ ChoiceNames::buildForEnvMode(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForEnvMode(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(70 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_LFO_1_Trig" },
					{ ID::property_ParamNum, 59 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " LFO 1 Trigger" },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_DataByteIndex, 48 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 3 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, env_1_Controls_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_5_y },
					{ ID::property_ControlWidth, envControls_w },
					{ ID::property_Description, Description::buildForEnv_LFO_1_Trig(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 42 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 3 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_AllowedChoices_x + envBlockOffset },
					{ ID::property_AllowedChoicesBackground_y, 384 },
				}, {
					ValueTree{ ChoiceNames::buildForEnv_LFO_1_Trig(ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForEnv_LFO_1_Trig(ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(71 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Delay" },
					{ ID::property_ParamNum, 50 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Delay Time" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 42 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, env_1_Delay_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_4_y },
					{ ID::property_ControlWidth, envControls_DADSR_w },
					{ ID::property_Description, Description::buildForEnvDelay(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_Delay_AllowedChoices_x + envBlockOffset  },
					{ ID::property_AllowedChoicesBackground_y, envControls_DADSR_AllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(72 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Attack" },
					{ ID::property_ParamNum, 51 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Attack Time" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 43 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_ControlCenter_x, env_1_Attack_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_4_y },
					{ ID::property_ControlWidth, envControls_DADSR_w },
					{ ID::property_Description, Description::buildForEnvAttack(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_Attack_AllowedChoices_x + envBlockOffset  },
					{ ID::property_AllowedChoicesBackground_y, envControls_DADSR_AllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(73 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Decay" },
					{ ID::property_ParamNum, 52 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Decay Time" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 44 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, envNum == 2 ? (uint8)20 : (uint8)10 },
					{ ID::property_ControlCenter_x, env_1_Decay_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_4_y },
					{ ID::property_ControlWidth, envControls_DADSR_w },
					{ ID::property_Description, Description::buildForEnvDecay(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_Decay_AllowedChoices_x + envBlockOffset  },
					{ ID::property_AllowedChoicesBackground_y, envControls_DADSR_AllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(74 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Sustain" },
					{ ID::property_ParamNum, 53 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Sustain Level" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 45 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, envNum == 2 ? (uint8)0 : (uint8)50 },
					{ ID::property_ControlCenter_x, env_1_Sustain_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_4_y },
					{ ID::property_ControlWidth, envControls_DADSR_w },
					{ ID::property_Description, Description::buildForEnvSustain(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_Sustain_AllowedChoices_x + envBlockOffset  },
					{ ID::property_AllowedChoicesBackground_y, envControls_DADSR_AllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);

		epTreeID = "ep_" + String(75 + envOffset);
		exposedParamsInfoTree.addChild(
			ValueTree{ epTreeID, {
					{ ID::property_ParamID, epTreeID + "_Env_" + envNumString + "_Release" },
					{ ID::property_ParamNum, 54 + envOffset },
					{ ID::property_ExposedName, "Envelope " + envNumString + " Release Time" },
					{ ID::property_ControlType, (int)ControlType::slider },
					{ ID::property_DataByteIndex, 46 + datByteOffset },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_SliderTextEditorType, (int)SliderTextEditorType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, envNum == 2 ? (uint8)20 : (uint8)10 },
					{ ID::property_ControlCenter_x, env_1_Release_x + envBlockOffset },
					{ ID::property_ControlCenter_y, envControlsRow_4_y },
					{ ID::property_ControlWidth, envControls_DADSR_w },
					{ ID::property_Description, Description::buildForEnvRelease(envNumString) },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_63 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_63 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Numeric },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, env_1_Release_AllowedChoices_x + envBlockOffset  },
					{ ID::property_AllowedChoicesBackground_y, envControls_DADSR_AllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, ChoiceNameType::verbose) }
				}
			}, -1, nullptr);
	}
}

Identifier InfoForExposedParameters::IDfor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return Identifier{ paramTree.getProperty(ID::property_ParamID).toString() };
}

uint8 InfoForExposedParameters::paramNumFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (uint8)(int)paramTree.getProperty(ID::property_ParamNum);
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

uint8 InfoForExposedParameters::dataByteIndexFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (uint8)(int)paramTree.getProperty(ID::property_DataByteIndex);
}

RangeType InfoForExposedParameters::rangeTypeFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return RangeType{ (int)paramTree.getProperty(ID::property_RangeType) };
}

SliderTextEditorType InfoForExposedParameters::sliderTextEditorTypeFor(const uint8 paramIndex) const {
	auto controlType{ controlTypeFor(paramIndex) };
	jassert(controlType == ControlType::slider || controlType == ControlType::sliderForOscBalance || controlType == ControlType::sliderForPitch);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return SliderTextEditorType{ (int)paramTree.getProperty(ID::property_SliderTextEditorType) };
}

uint8 InfoForExposedParameters::numberOfChoicesFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (uint8)(int)paramTree.getProperty(ID::property_NumberOfChoices);
}

uint8 InfoForExposedParameters::defaultChoiceFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (uint8)(int)paramTree.getProperty(ID::property_DefaultChoice);
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
	return (int)paramTree.getProperty(ID::property_ControlWidth);
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

int InfoForExposedParameters::firstAllowChoiceToggleRowFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_FirstAllowChoiceToggleRow);
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
