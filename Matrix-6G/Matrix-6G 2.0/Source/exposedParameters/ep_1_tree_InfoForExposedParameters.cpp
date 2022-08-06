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
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " LFO 1 FM Amount" },
					{ ID::property_ControlType, (int)ControlType::rotarySlider },
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
	}
}
