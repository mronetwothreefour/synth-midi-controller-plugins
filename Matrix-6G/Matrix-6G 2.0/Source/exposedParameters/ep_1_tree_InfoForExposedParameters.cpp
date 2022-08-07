#include "ep_1_tree_InfoForExposedParameters.h"

#include "ep_0_build_ChoiceNamesValueTree.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_ExposedParamDescription.h"

using namespace Matrix_6G_Constants;
using Description = ExposedParamDescription;
using ChoiceNames = ExposedParamChoiceNamesValueTree;

InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::tree_ExposedParamsInfo }
{
	const int vertDistBtwnRows{ 28 };
	const int controlsRow_1_y{ 69 };
	const int controlsRow_2_y{ controlsRow_1_y + vertDistBtwnRows };
	const int controlsRow_3_y{ controlsRow_2_y + vertDistBtwnRows };
	const int controlsRow_4_y{ controlsRow_3_y + vertDistBtwnRows };
	const int controlsRow_5_y{ controlsRow_4_y + vertDistBtwnRows };
	const int controlsRow_6_y{ controlsRow_5_y + vertDistBtwnRows };
	const int controlsRow_7_y{ controlsRow_6_y + vertDistBtwnRows };
	const int controlsRow_8_y{ controlsRow_7_y + vertDistBtwnRows };
	const int controlsRow_9_y{ controlsRow_8_y + vertDistBtwnRows };
	const int controlsRow_10_y{ controlsRow_9_y + vertDistBtwnRows };
	const int controlsRow_11_y{ controlsRow_10_y + vertDistBtwnRows };
	const int controlsRow_12_y{ controlsRow_11_y + vertDistBtwnRows };

	auto concise{ false };
	auto verbose{ true };

	// ------------------------------------------------------------------------------------------------------------- oscillators

	const int osc_1_x{ 130 };
	const int osc_2_x{ 196 };
	const int osc_w{ 60 };
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_00" : "ep_10", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_00_Osc_1_Pitch.toString() : ID::ep_10_Osc_2_Pitch.toString() },
					{ ID::property_ParamNum, oscNum == 1 ? 0 : 10 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pitch" },
					{ ID::property_ControlType, (int)ControlType::rotarySliderForPitch },
					{ ID::property_DataByteIndex, oscNum == 1 ? 1 : 6 },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_1_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOscPitch(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForOscPitch(concise) },
					ValueTree{ ChoiceNames::buildForOscPitch(verbose) }
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
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_2_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOscType(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForOscType(oscNum, concise) },
					ValueTree{ ChoiceNames::buildForOscType(oscNum, verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_02" : "ep_12", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_02_Osc_1_PulseWidth.toString() : ID::ep_12_Osc_2_PulseWidth.toString() },
					{ ID::property_ParamNum, oscNum == 1 ? 3 : 13 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pulse Width" },
					{ ID::property_ControlType, (int)ControlType::rotarySlider },
					{ ID::property_DataByteIndex, oscNum == 1 ? 3 : 8 },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, oscNum == 1 ? 31 : 24 },
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_3_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOscPulseWidth(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_03" : "ep_13", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_03_Osc_1_SawTri.toString() : ID::ep_13_Osc_2_SawTri.toString() },
					{ ID::property_ParamNum, oscNum == 1 ? 5 : 15 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Saw / Triangle Wave" },
					{ ID::property_ControlType, (int)ControlType::rotarySlider },
					{ ID::property_DataByteIndex, oscNum == 1 ? 2 : 7 },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, 31 },
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_4_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOscSawTri(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_04" : "ep_14", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_04_Osc_1_Sync.toString() : ID::ep_14_Osc_2_Detune.toString() },
					{ ID::property_ParamNum, oscNum == 1 ? 2 : 12 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + (oscNum == 1 ? " Sync" : " Detune") },
					{ ID::property_ControlType, oscNum == 1 ? (int)ControlType::comboBox : (int)ControlType::rotarySlider },
					{ ID::property_DataByteIndex, oscNum == 1 ? 17 : 11 },
					{ ID::property_RangeType, oscNum == 1 ? (int)RangeType::unsignedValue : (int)RangeType::signed_6_bitValue },
					{ ID::property_NumberOfChoices, oscNum == 1 ? 4 : 63 },
					{ ID::property_DefaultChoice, oscNum == 1 ? 0 : 33 },
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_5_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, oscNum == 1 ? Description::buildForOsc_1_Sync() : Description::buildForOsc_2_Detune() },
				}, {
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_Sync(concise) : ChoiceNames::buildForSigned_6_BitValue(concise) },
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_Sync(verbose) : ChoiceNames::buildForSigned_6_BitValue(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_05" : "ep_15", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_05_Osc_1_LFO_1_FM.toString() : ID::ep_15_Osc_2_LFO_1_FM.toString() },
					{ ID::property_ParamNum, oscNum == 1 ? 1 : 11 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Frequency Mod. by LFO 1" },
					{ ID::property_ControlType, (int)ControlType::rotarySlider },
					{ ID::property_DataByteIndex, oscNum == 1 ? 78 : 80 },
					{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
					{ ID::property_NumberOfChoices, 127 },
					{ ID::property_DefaultChoice, 63 },
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_6_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOsc_LFO_1_FM(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_06" : "ep_16", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_06_Osc_1_LFO_2_PWM.toString() : ID::ep_16_Osc_2_LFO_2_PWM.toString() },
					{ ID::property_ParamNum, oscNum == 1 ? 4 : 14 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pulse Width Mod. by LFO 2" },
					{ ID::property_ControlType, (int)ControlType::rotarySlider },
					{ ID::property_DataByteIndex, oscNum == 1 ? 79 : 81 },
					{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
					{ ID::property_NumberOfChoices, 127 },
					{ ID::property_DefaultChoice, 63 },
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_7_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOsc_LFO_2_PWM(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
					ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
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
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_8_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOscKeyClick() },
				}, {
					ValueTree{ ChoiceNames::buildForOffOn(concise) },
					ValueTree{ ChoiceNames::buildForOffOn(verbose) }
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
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_9_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForOscKeyTrack(oscNum) },
				}, {
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_KeyTrack(concise) : ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(concise) },
					ValueTree{ oscNum == 1 ? ChoiceNames::buildForOsc_1_KeyTrack(verbose) : ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(verbose) }
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
					{ ID::property_Center_x, oscNum == 1 ? osc_1_x : osc_2_x },
					{ ID::property_Center_y, controlsRow_10_y },
					{ ID::property_Width, osc_w },
					{ ID::property_Description, Description::buildForLeverControl(oscNum) },
				}, {
					ValueTree{ ChoiceNames::buildForLeverControl(concise) },
					ValueTree{ ChoiceNames::buildForLeverControl(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_20", {
					{ ID::property_ParamID, ID::ep_20_OscBalance.toString() },
					{ ID::property_ParamNum, 20 },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Balance" },
					{ ID::property_ControlType, (int)ControlType::linearSlider },
					{ ID::property_DataByteIndex, 12 },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, 31 },
					{ ID::property_Center_x, 163 },
					{ ID::property_Center_y, controlsRow_11_y },
					{ ID::property_Width, 126 },
					{ ID::property_Description, Description::buildForOscBalance() },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
				}
			}, -1, nullptr);
	}

	// --------------------------------------------------------------------------------------------------------------------- VCF

	const auto vcf_vca_x{ 382 };
	const auto vcf_vca_w{ 60 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_21", {
				{ ID::property_ParamID, ID::ep_21_VCF_Freq.toString() },
				{ ID::property_ParamNum, 21 },
				{ ID::property_ExposedName, "VCF Cutoff Frequency" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 18 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 55 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_1_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_Freq() },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(128, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_22", {
				{ ID::property_ParamID, ID::ep_22_VCF_Reso.toString() },
				{ ID::property_ParamNum, 24 },
				{ ID::property_ExposedName, "VCF Resonance" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 19 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_2_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_Reso() },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_23", {
				{ ID::property_ParamID, ID::ep_23_VCF_Env_1_Amt.toString() },
				{ ID::property_ParamNum, 22 },
				{ ID::property_ExposedName, "VCF Envelope 1 Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 82 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 105 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_3_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_Env_1_Amt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_24", {
				{ ID::property_ParamID, ID::ep_24_VCF_PressureAmt.toString() },
				{ ID::property_ParamNum, 23 },
				{ ID::property_ExposedName, "VCF Pressure Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 83 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_4_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_PressureAmt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
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
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_5_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_LeverControl() },
			}, {
				ValueTree{ ChoiceNames::buildForLeverControl(concise) },
				ValueTree{ ChoiceNames::buildForLeverControl(verbose) }
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
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_6_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCF_LeverControl() },
			}, {
				ValueTree{ ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(concise) },
				ValueTree{ ChoiceNames::buildForOsc_2_And_VCF_KeyTrack(verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------------- VCA

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_27", {
				{ ID::property_ParamID, ID::ep_27_VCA_1_Volume.toString() },
				{ ID::property_ParamNum, 27 },
				{ ID::property_ExposedName, "VCA 1 Volume" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 23 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_9_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCA_1_Volume() },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_28", {
				{ ID::property_ParamID, ID::ep_28_VCA_1_VeloAmt.toString() },
				{ ID::property_ParamNum, 28 },
				{ ID::property_ExposedName, "VCA 1 Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 84 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_10_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCA_1_VeloAmt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_29", {
				{ ID::property_ParamID, ID::ep_29_VCA_2_Env_2_Amt.toString() },
				{ ID::property_ParamNum, 29 },
				{ ID::property_ExposedName, "VCA 2 Envelope 2 Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 85 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 126 },
				{ ID::property_Center_x, vcf_vca_x },
				{ ID::property_Center_y, controlsRow_11_y },
				{ ID::property_Width, vcf_vca_w },
				{ ID::property_Description, Description::buildFor_VCA_1_VeloAmt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
			}
		}, -1, nullptr);

	// ------------------------------------------------------------------------------------------------------------------ VCF FM

	const auto vcf_fm_x{ 550 };
	const auto vcf_fm_w{ 60 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_30", {
				{ ID::property_ParamID, ID::ep_30_VCF_FM_Osc_1_Amt.toString() },
				{ ID::property_ParamNum, 30 },
				{ ID::property_ExposedName, "VCF FM By Oscillator 1 Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 22 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, vcf_fm_x },
				{ ID::property_Center_y, controlsRow_1_y },
				{ ID::property_Width, vcf_fm_w },
				{ ID::property_Description, Description::buildFor_VCF_FM_Osc_1_Amt() },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_31", {
				{ ID::property_ParamID, ID::ep_31_VCF_FM_Env_3_Amt.toString() },
				{ ID::property_ParamNum, 31 },
				{ ID::property_ExposedName, "VCF FM Envelope 3 Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 92 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, vcf_fm_x },
				{ ID::property_Center_y, controlsRow_2_y },
				{ ID::property_Width, vcf_fm_w },
				{ ID::property_Description, Description::buildFor_VCF_FM_Env_3_Amt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_32", {
				{ ID::property_ParamID, ID::ep_32_VCF_FM_PressureAmt.toString() },
				{ ID::property_ParamNum, 32 },
				{ ID::property_ExposedName, "VCF FM Pressure Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 93 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, vcf_fm_x },
				{ ID::property_Center_y, controlsRow_3_y },
				{ ID::property_Width, vcf_fm_w },
				{ ID::property_Description, Description::buildFor_VCF_FM_PressureAmt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
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
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 24 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, porta_keyMode_x },
				{ ID::property_Center_y, controlsRow_6_y },
				{ ID::property_Width, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaRate() },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_34", {
				{ ID::property_ParamID, ID::ep_34_PortaVelo.toString() },
				{ ID::property_ParamNum, 45 },
				{ ID::property_ExposedName, "Portamento Rate" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, 91 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, porta_keyMode_x },
				{ ID::property_Center_y, controlsRow_7_y },
				{ ID::property_Width, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaVelo() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
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
				{ ID::property_Center_x, porta_keyMode_x },
				{ ID::property_Center_y, controlsRow_8_y },
				{ ID::property_Width, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaMode() },
			}, {
				ValueTree{ ChoiceNames::buildForPortaMode(concise) },
				ValueTree{ ChoiceNames::buildForPortaMode(verbose) }
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
				{ ID::property_Center_x, porta_keyMode_x },
				{ ID::property_Center_y, controlsRow_9_y },
				{ ID::property_Width, porta_keyMode_w },
				{ ID::property_Description, Description::buildForPortaLegato() },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(concise) },
				ValueTree{ ChoiceNames::buildForOffOn(verbose) }
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
				{ ID::property_Center_x, porta_keyMode_x },
				{ ID::property_Center_y, controlsRow_12_y },
				{ ID::property_Width, porta_keyMode_w },
				{ ID::property_Description, Description::buildForKeyboardMode() },
			}, {
				ValueTree{ ChoiceNames::buildForKeyboardMode(concise) },
				ValueTree{ ChoiceNames::buildForKeyboardMode(verbose) }
			}
		}, -1, nullptr);

	// --------------------------------------------------------------------------------------------------------------------- LFO

	const auto lfo_1_x{ 726 };
	const auto lfo_2_x{ 792 };
	const auto lfo_w{ 60 };
	for (auto lfoNum = 1; lfoNum != 3; ++lfoNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_38" : "ep_47", {
					{ ID::property_ParamID, lfoNum == 1 ? ID::ep_38_LFO_1_Speed.toString() : ID::ep_47_LFO_2_Speed.toString() },
					{ ID::property_ParamNum, lfoNum == 1 ? 80 : 90 },
					{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Speed" },
					{ ID::property_ControlType, (int)ControlType::rotarySlider },
					{ ID::property_DataByteIndex, lfoNum == 1 ? 27 : 34 },
					{ ID::property_RangeType, (int)RangeType::unsignedValue },
					{ ID::property_NumberOfChoices, 64 },
					{ ID::property_DefaultChoice, lfoNum == 1 ? 40 : 30 },
					{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
					{ ID::property_Center_y, controlsRow_1_y },
					{ ID::property_Width, lfo_w },
					{ ID::property_Description, Description::buildFor_LFO_Speed(lfoNum) },
				}, {
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
					ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
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
					{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
					{ ID::property_Center_y, controlsRow_2_y },
					{ ID::property_Width, lfo_w },
					{ ID::property_Description, Description::buildFor_LFO_WaveType(lfoNum) },
				}, {
					ValueTree{ ChoiceNames::buildFor_LFO_WaveType(concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_WaveType(verbose) }
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
					{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
					{ ID::property_Center_y, controlsRow_3_y },
					{ ID::property_Width, lfo_w },
					{ ID::property_Description, Description::buildFor_LFO_SampleSource(lfoNum) },
				}, {
					ValueTree{ ChoiceNames::buildFor_LFO_SampleSource(concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_SampleSource(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_41" : "ep_50", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_41_LFO_1_Amp.toString() : ID::ep_50_LFO_2_Amp.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 84 : 94 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Amplitude" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 33 : 40 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_Center_y, controlsRow_4_y },
				{ ID::property_Width, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_Amp(lfoNum) },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
			}
		}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_42" : "ep_51", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_42_LFO_1_PressureAmt.toString() : ID::ep_51_LFO_2_KeyTrackAmt.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 81 : 91 },
				{ ID::property_ExposedName, lfoNum == 1 ? "LFO 1 Pressure Amount" : "LFO 2 Key Tracking Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 94 : 95 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 63 },
				{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_Center_y, controlsRow_5_y },
				{ ID::property_Width, lfo_w },
				{ ID::property_Description, lfoNum == 1 ? Description::buildFor_LFO_1_PressureAmt() : Description::buildFor_LFO_2_KeyTrackAmt() },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
			}
		}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_43" : "ep_52", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_43_LFO_1_Ramp_1_Amt.toString() : ID::ep_52_LFO_2_Ramp_2_Amt.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 85 : 95 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Ramp " + (String)lfoNum + " Amount" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 89 : 90 },
				{ ID::property_RangeType, (int)RangeType::signed_7_bitValue },
				{ ID::property_NumberOfChoices, 127 },
				{ ID::property_DefaultChoice, 126 },
				{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_Center_y, controlsRow_6_y },
				{ ID::property_Width, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_RampAmt(lfoNum) },
			}, {
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(concise) },
				ValueTree{ ChoiceNames::buildForSigned_7_BitValue(verbose) }
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
					{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
					{ ID::property_Center_y, controlsRow_7_y },
					{ ID::property_Width, lfo_w },
					{ ID::property_Description, Description::buildFor_LFO_TrigMode(lfoNum) },
				}, {
					ValueTree{ ChoiceNames::buildFor_LFO_TrigMode(concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_TrigMode(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ lfoNum == 1 ? "ep_45" : "ep_54", {
				{ ID::property_ParamID, lfoNum == 1 ? ID::ep_45_LFO_1_RetrigPoint.toString() : ID::ep_54_LFO_2_RetrigPoint.toString() },
				{ ID::property_ParamNum, lfoNum == 1 ? 83 : 93 },
				{ ID::property_ExposedName, "LFO " + (String)lfoNum + " Retrigger Point" },
				{ ID::property_ControlType, (int)ControlType::rotarySlider },
				{ ID::property_DataByteIndex, lfoNum == 1 ? 31 : 38 },
				{ ID::property_RangeType, (int)RangeType::unsignedValue },
				{ ID::property_NumberOfChoices, 64 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
				{ ID::property_Center_y, controlsRow_8_y },
				{ ID::property_Width, lfo_w },
				{ ID::property_Description, Description::buildFor_LFO_RetrigPoint(lfoNum) },
			}, {
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, concise) },
				ValueTree{ ChoiceNames::buildForUnsignedValue(64, verbose) }
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
					{ ID::property_Center_x, lfoNum == 1 ? lfo_1_x : lfo_2_x },
					{ ID::property_Center_y, controlsRow_9_y },
					{ ID::property_Width, lfo_w },
					{ ID::property_Description, Description::buildFor_LFO_Lag(lfoNum) },
				}, {
					ValueTree{ ChoiceNames::buildForOffOn(concise) },
					ValueTree{ ChoiceNames::buildForOffOn(verbose) }
				}
			}, -1, nullptr);
	}
}
