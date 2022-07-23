#include "ep_1_tree_InfoForExposedParameters.h"

#include "ep_0_build_ChoiceNamesValueTree.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../descriptions/build_ExposedParamDescription.h"

using namespace MophoConstants;
using Description = ExposedParamDescription;
using ChoiceNames = ExposedParamChoiceNamesValueTree;



InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::exposedParamsInfo }
{
	const int horizDistanceBtwnColumns{ GUI::knob_diameter + 5 };
	const int controlsCol_1_x{ 48 };
	const int controlsCol_2_x{ controlsCol_1_x + horizDistanceBtwnColumns };
	const int controlsCol_3_x{ controlsCol_2_x + horizDistanceBtwnColumns };
	const int controlsCol_4_x{ controlsCol_3_x + horizDistanceBtwnColumns };
	const int controlsCol_5_x{ controlsCol_4_x + horizDistanceBtwnColumns };
	const int controlsCol_6_x{ controlsCol_5_x + horizDistanceBtwnColumns };
	const int controlsCol_7_x{ controlsCol_6_x + horizDistanceBtwnColumns };
	const int controlsCol_8_x{ controlsCol_7_x + horizDistanceBtwnColumns };
	const int controlsCol_9_x{ controlsCol_8_x + horizDistanceBtwnColumns };
	const int controlsCol_10_x{ 500 };

	const int allowedChoicesOffset_Knobs{ GUI::knob_diameter / 2 + 10 };
	const int allowedChoicesOffset_Toggles{ GUI::toggleLockButton_diameter / 2 + 10 };

	const int firstAllowChoiceRow_PlusMinus127{ 14 };

	const int numberOfAllowChoiceColumns_0to127{ 16 };
	const int numberOfAllowChoiceColumns_ModDestination{ 3 };
	const int numberOfAllowChoiceColumns_ModSource{ 2 };
	const int numberOfAllowChoiceColumns_OscPitch{ 11 };
	const int numberOfAllowChoiceColumns_PlusMinus127{ 14 };

	const int numberOfAllowChoiceRows_0to127{ 8 };
	const int numberOfAllowChoiceRows_ModDestination{ 16 };
	const int numberOfAllowChoiceRows_ModSource{ 12 };
	const int numberOfAllowChoiceRows_PlusMinus127{ 20 };
	const int numberOfAllowChoiceRows_Pitch{ 12 };

	const int widthOfAllowChoiceColumns_0to127{ 26 };
	const int widthOfAllowChoiceColumns_ModSourceAndDestination{ 130 };
	const int widthOfAllowChoiceColumns_OscPitch{ 38 };
	const int widthOfAllowChoiceColumns_PlusMinus127{ 32 };

	auto concise{ false };
	auto verbose{ true };

	// ------------------------------------------------------------------------------------------------------------- oscillators

	const int vertDistanceBtwnOscRows{ 60 };
	const int oscRow_1_center_y{ 50 };
	const int oscRow_2_center_y{ oscRow_1_center_y + vertDistanceBtwnOscRows };
	const int oscRow_1_knobTop_y{ oscRow_1_center_y - GUI::knob_diameter / 2 };
	const int oscRow_2_knobTop_y{ oscRow_1_knobTop_y + vertDistanceBtwnOscRows };

	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		auto center_y{ oscNum == 1 ? oscRow_1_center_y : oscRow_2_center_y };
		auto knobTop_y{ oscNum == 1 ? oscRow_1_knobTop_y : oscRow_2_knobTop_y };
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_000" : "ep_006", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_000_Osc_1_Pitch.toString() : ID::ep_006_Osc_2_Pitch.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pitch" },
					{ ID::property_ControlType, (int)ControlType::knobForPitch },
					{ ID::property_NRPN, oscNum == 1 ? 0 : 5 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
					{ ID::property_DefaultChoice, 24 },
					{ ID::property_Center_x, controlsCol_1_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_OscPitch(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_OscPitch },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_OscPitch },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Pitch },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildFor_OscPitch(concise) },
					ValueTree{ ChoiceNames::buildFor_OscPitch(verbose) }
				} 
			}, - 1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_001" : "ep_007", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_001_Osc_1_FineTune.toString() : ID::ep_007_Osc_2_FineTune.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Fine Tune" },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_NRPN, oscNum == 1 ? 1 : 6 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscFineTune },
					{ ID::property_DefaultChoice, oscNum == 1 ? 49 : 51 },
					{ ID::property_Center_x, controlsCol_2_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_OscFine(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 11 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 28 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 10 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildFor_OscFineTune(concise) },
					ValueTree{ ChoiceNames::buildFor_OscFineTune(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_002" : "ep_008", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_002_Osc_1_Shape.toString() : ID::ep_008_Osc_2_Shape.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Wave Shape" },
					{ ID::property_ControlType, (int)ControlType::knobForOscShape },
					{ ID::property_NRPN, oscNum == 1 ? 2 : 7 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscWaveShape },
					{ ID::property_DefaultChoice, 1 },
					{ ID::property_Center_x, controlsCol_3_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_OscShape(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::oscShape },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildFor_OscShape(concise) },
					ValueTree{ ChoiceNames::buildFor_OscShape(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_003" : "ep_009", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_003_Osc_1_Glide.toString() : ID::ep_009_Osc_2_Glide.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Glide Rate" },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_NRPN, oscNum == 1 ? 3 : 8 },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, controlsCol_4_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_OscGlide(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildFor_PlainValue((uint8)128, concise) },
					ValueTree{ ChoiceNames::buildFor_PlainValue((uint8)128, verbose) }
				}
			}, -1, nullptr);

		auto keyTrackAllowedChoices_y{ center_y - GUI::toggleLockButton_diameter / 2 };
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_004" : "ep_010", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_004_Osc_1_KeyTrack.toString() : ID::ep_010_Osc_2_KeyTrack.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Keyboard Track On/Off" },
					{ ID::property_ControlType, (int)ControlType::toggleButton },
					{ ID::property_NRPN, oscNum == 1 ? 4 : 9 },
					{ ID::property_NumberOfChoices, 2 },
					{ ID::property_DefaultChoice, 1 },
					{ ID::property_Center_x, controlsCol_6_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::toggle_diameter },
					{ ID::property_Height, GUI::toggle_diameter },
					{ ID::property_Description, Description::buildFor_OscKeyTrack(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Toggles },
					{ ID::property_AllowedChoicesBackground_y, keyTrackAllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildFor_OffOn(concise) },
					ValueTree{ ChoiceNames::buildFor_OffOn(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_005" : "ep_011", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_005_Osc_1_SubLevel.toString() : ID::ep_011_Osc_2_SubLevel.toString() },
					{ ID::property_ExposedName, "Sub-Oscillator " + (String)oscNum + " Level"  },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_NRPN, oscNum == 1 ? 114 : 115 },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, controlsCol_5_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_OscSubLevel(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildFor_PlainValue((uint8)128, concise) },
					ValueTree{ ChoiceNames::buildFor_PlainValue((uint8)128, verbose) }
				}
			}, -1, nullptr);
	}

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_012", {
				{ ID::property_ParamID, ID::ep_012_OscSync.toString() },
				{ ID::property_ExposedName, "Hard Oscillator Sync On/Off" },
				{ ID::property_ControlType, (int)ControlType::toggleButton },
				{ ID::property_NRPN, 10 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, 22 },
				{ ID::property_Width, GUI::toggle_diameter },
				{ ID::property_Height, GUI::toggle_diameter },
				{ ID::property_Description, Description::buildFor_OscSync() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Toggles },
				{ ID::property_AllowedChoicesBackground_y, 11 },
			}, {
				ValueTree{ ChoiceNames::buildFor_OffOn(concise) },
				ValueTree{ ChoiceNames::buildFor_OffOn(verbose) }
			}
		}, -1, nullptr);

	auto col_10_AllowedChoices_x{ controlsCol_6_x + 72 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_013", {
				{ ID::property_ParamID, ID::ep_013_GlideMode.toString() },
				{ ID::property_ExposedName, "Glide Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 11 },
				{ ID::property_NumberOfChoices, 4 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_10_x },
				{ ID::property_Center_y, 78 },
				{ ID::property_Width, 124 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildFor_GlideMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 124 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_10_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, 70 },
			}, {
				ValueTree{ ChoiceNames::buildFor_GlideMode(concise) },
				ValueTree{ ChoiceNames::buildFor_GlideMode(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_014", {
				{ ID::property_ParamID, ID::ep_014_OscSlop.toString() },
				{ ID::property_ExposedName, "Oscillator Slop" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 12 },
				{ ID::property_NumberOfChoices, 6 },
				{ ID::property_DefaultChoice, 2 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, oscRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_OscSlop() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 14 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 6 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue((uint8)6, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue((uint8)6, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_015", {
				{ ID::property_ParamID, ID::ep_015_BendRange.toString() },
				{ ID::property_ExposedName, "Pitch Bend Range" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 93 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForBendRange },
				{ ID::property_DefaultChoice, 4 },
				{ ID::property_Center_x, controlsCol_9_x },
				{ ID::property_Center_y, oscRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_BendRange() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 34 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 13 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_9_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_BendRange(concise) },
				ValueTree{ ChoiceNames::buildFor_BendRange(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_016", {
				{ ID::property_ParamID, ID::ep_016_NotePriority.toString() },
				{ ID::property_ExposedName, "Note Priority(Key Assign)" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 96 },
				{ ID::property_NumberOfChoices, 6 },
				{ ID::property_DefaultChoice, 4 },
				{ ID::property_Center_x, controlsCol_10_x },
				{ ID::property_Center_y, 38 },
				{ ID::property_Width, 124 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildFor_NotePriority() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 124 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 6 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_10_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, 30 },
			}, {
				ValueTree{ ChoiceNames::buildFor_NotePriority(concise) },
				ValueTree{ ChoiceNames::buildFor_NotePriority(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_017", {
				{ ID::property_ParamID, ID::ep_017_OscMix.toString() },
				{ ID::property_ExposedName, "Oscillator 1 & 2 Mix" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 13 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, oscRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_OscMix() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_018", {
				{ ID::property_ParamID, ID::ep_018_NoiseLevel.toString() },
				{ ID::property_ExposedName, "Noise Level" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 14 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, oscRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_NoiseLevel() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_019", {
				{ ID::property_ParamID, ID::ep_019_ExtInLevel.toString() },
				{ ID::property_ExposedName, "External Audio Input Level" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 116 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, oscRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_ExtInLevel() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	//---------------------------------------------------------------------------------------------------------------------- LPF

	const int lpfRow_1_center_y{ 161 };
	const int lpfRow_2_center_y{ 215 };
	const int lpfRow_3_center_y{ 267 };
	const int lpfRow_2_knobTop_y{ lpfRow_2_center_y - GUI::knob_diameter / 2 };
	const int lpfRow_3_knobTop_y{ lpfRow_3_center_y - GUI::knob_diameter / 2 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_020", {
				{ ID::property_ParamID, ID::ep_020_LPF_Freq.toString() },
				{ ID::property_ExposedName, "LPF Cutoff Frequency" },
				{ ID::property_ControlType, (int)ControlType::knobForPitch },
				{ ID::property_NRPN, 15 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForLPF_Freq },
				{ ID::property_DefaultChoice, 148 },
				{ ID::property_Center_x, controlsCol_1_x },
				{ ID::property_Center_y, lpfRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_Freq() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 14 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_OscPitch },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Pitch },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_LPF_Freq(concise) },
				ValueTree{ ChoiceNames::buildFor_LPF_Freq(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_021", {
				{ ID::property_ParamID, ID::ep_021_LPF_Reso.toString() },
				{ ID::property_ExposedName, "LPF Resonance" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 16 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, lpfRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_Reso() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_022", {
				{ ID::property_ParamID, ID::ep_022_LPF_KeyAmount.toString() },
				{ ID::property_ExposedName, "LPF Keyboard Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 17 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, lpfRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_KeyAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_023", {
				{ ID::property_ParamID, ID::ep_023_LPF_FM_Amount.toString() },
				{ ID::property_ExposedName, "LPF FM (By Oscillator 1)" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 18 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_FM_Amount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_024", {
				{ ID::property_ParamID, ID::ep_024_LPF_Type.toString() },
				{ ID::property_ExposedName, "LPF Type" },
				{ ID::property_ControlType, (int)ControlType::toggleButton },
				{ ID::property_NRPN, 19 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 1 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, lpfRow_1_center_y },
				{ ID::property_Width, GUI::toggle_diameter },
				{ ID::property_Height, GUI::toggle_diameter },
				{ ID::property_Description, Description::buildFor_LPF_Type() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Toggles },
				{ ID::property_AllowedChoicesBackground_y, 150 },
			}, {
				ValueTree{ ChoiceNames::buildFor_LPF_Type(concise) },
				ValueTree{ ChoiceNames::buildFor_LPF_Type(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_025", {
				{ ID::property_ParamID, ID::ep_025_LPF_EnvAmount.toString() },
				{ ID::property_ExposedName, "LPF Envelope Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 20 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, controlsCol_1_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_EnvAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, 187 },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_026", {
				{ ID::property_ParamID, ID::ep_026_LPF_VelAmount.toString() },
				{ ID::property_ExposedName, "LPF Envelope Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 21 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvVelAmount(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs},
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_027", {
				{ ID::property_ParamID, ID::ep_027_LPF_Delay.toString() },
				{ ID::property_ExposedName, "LPF Envelope Delay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 22 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_4_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvDelay(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_028", {
				{ ID::property_ParamID, ID::ep_028_LPF_Attack.toString() },
				{ ID::property_ExposedName, "LPF Envelope Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 23 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_5_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvAttack(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_029", {
				{ ID::property_ParamID, ID::ep_029_LPF_Decay.toString() },
				{ ID::property_ExposedName, "LPF Envelope Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 24 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvDecay(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_030", {
				{ ID::property_ParamID, ID::ep_030_LPF_Sustain.toString() },
				{ ID::property_ExposedName, "LPF Envelope Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 25 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvSustain(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_031", {
				{ ID::property_ParamID, ID::ep_031_LPF_Release.toString() },
				{ ID::property_ExposedName, "LPF Envelope Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 26 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvRelease(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	//---------------------------------------------------------------------------------------------------------------------- VCA

	const int vcaRow_1_center_y{ 373 };
	const int vcaRow_2_center_y{ 425 };
	const int vcaRow_1_knobTop_y{ vcaRow_1_center_y - GUI::knob_diameter / 2 };
	const int vcaRow_2_allowedChoices_y{ 312 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_032", {
				{ ID::property_ParamID, ID::ep_032_VCA_Level.toString() },
				{ ID::property_ExposedName, "VCA Baseline Level" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 27 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_1_x },
				{ ID::property_Center_y, vcaRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_VCA_Level() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_033", {
				{ ID::property_ParamID, ID::ep_033_VCA_EnvAmount.toString() },
				{ ID::property_ExposedName, "VCA Envelope Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 30 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, vcaRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_VCA_EnvAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_034", {
				{ ID::property_ParamID, ID::ep_034_VCA_VelAmount.toString() },
				{ ID::property_ExposedName, "VCA Envelope Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 31 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, vcaRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvVelAmount(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_035", {
				{ ID::property_ParamID, ID::ep_035_VCA_Delay.toString() },
				{ ID::property_ExposedName, "VCA Envelope Delay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 32 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_4_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvDelay(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_036", {
				{ ID::property_ParamID, ID::ep_036_VCA_Attack.toString() },
				{ ID::property_ExposedName, "VCA Envelope Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 33 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_5_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvAttack(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_037", {
				{ ID::property_ParamID, ID::ep_037_VCA_Decay.toString() },
				{ ID::property_ExposedName, "VCA Envelope Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 34 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvDecay(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_038", {
				{ ID::property_ParamID, ID::ep_038_VCA_Sustain.toString() },
				{ ID::property_ExposedName, "VCA Envelope Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 35 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvSustain(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_039", {
				{ ID::property_ParamID, ID::ep_039_VCA_Release.toString() },
				{ ID::property_ExposedName, "VCA Envelope Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 36 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvRelease(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_040", {
				{ ID::property_ParamID, ID::ep_040_VoiceVolume.toString() },
				{ ID::property_ExposedName, "Program Volume" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 29 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 120 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_VoiceVolume() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	//--------------------------------------------------------------------------------------------------------------------- LFOs

	const int lfoRow_1_center_y{ 515 };
	const int lfoRow_2_center_y{ 560 };
	const int lfoRow_3_center_y{ 594 };
	const int lfoControlsGroup_w{ 155 };
	auto modDestinationParamDescription{ "Selects the target parameter for modulation" };

	for (uint8 lfoNum = 0; lfoNum != 4; ++lfoNum) {
		auto paramNumString{ "ep_0" + (String)(41 + lfoNum * 5) };
		auto paramID_String{ paramNumString + "_LFO_" + String(lfoNum + 1) + "_Freq" };
		auto exposedNameString{ "LFO " + String(lfoNum + 1) + " Frequency" };
		auto nrpn{ 37 + lfoNum * 5 };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 167 },
					{ ID::property_DefaultChoice, 80 },
					{ ID::property_Center_x, 416 + lfoNum * lfoControlsGroup_w },
					{ ID::property_Center_y, lfoRow_1_center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_LFO_Freq(lfoNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::lfoFreq },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 361 },
					{ ID::property_AllowedChoicesBackground_y, 160 },
				}, {
					ValueTree{ ChoiceNames::buildFor_LFO_Freq(concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_Freq(verbose) }
				}
			}, -1, nullptr);

		paramNumString = "ep_0" + (String)(42 + lfoNum * 5);
		paramID_String = paramNumString + "_LFO_" + String(lfoNum + 1) + "_Shape";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Wave Shape";
		nrpn = 38 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 5 },
					{ ID::property_DefaultChoice, 1 },
					{ ID::property_Center_x, 463 + lfoNum * lfoControlsGroup_w },
					{ ID::property_Center_y, lfoRow_2_center_y },
					{ ID::property_Width, 134 },
					{ ID::property_Height, GUI::comboBox_h },
					{ ID::property_Description, Description::buildFor_LFO_Shape(lfoNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 100 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 5 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 396 + lfoNum * lfoControlsGroup_w },
					{ ID::property_AllowedChoicesBackground_y, 310 },
				}, {
					ValueTree{ ChoiceNames::buildFor_LFO_Shape(concise) },
					ValueTree{ ChoiceNames::buildFor_LFO_Shape(verbose) }
				}
			}, -1, nullptr);

		paramNumString = "ep_0" + (String)(43 + lfoNum * 5);
		paramID_String = paramNumString + "_LFO_" + String(lfoNum + 1) + "_Amount";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Amount";
		nrpn = 39 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, 461 + lfoNum * lfoControlsGroup_w },
					{ ID::property_Center_y, lfoRow_1_center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_LFO_Amount(lfoNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 236 + lfoNum * lfoControlsGroup_w },
					{ ID::property_AllowedChoicesBackground_y, 249 },
				}, {
					ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
					ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
				}
			}, -1, nullptr);

		paramNumString = "ep_0" + (String)(44 + lfoNum * 5);
		paramID_String = paramNumString + "_LFO_" + String(lfoNum + 1) + "_Destination";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Modulation Destination";
		nrpn = 40 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, 463 + lfoNum * lfoControlsGroup_w },
					{ ID::property_Center_y, lfoRow_3_center_y },
					{ ID::property_Width, 134 },
					{ ID::property_Height, GUI::comboBox_h },
					{ ID::property_Description, modDestinationParamDescription + String(" by LFO ") + String(lfoNum + 1) + "." },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 251 + lfoNum * lfoControlsGroup_w },
					{ ID::property_AllowedChoicesBackground_y, 222 },
				}, {
					ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
					ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
				}
			}, -1, nullptr);

		paramNumString = "ep_0" + (String)(45 + lfoNum * 5);
		paramID_String = paramNumString + "_LFO_" + String(lfoNum + 1) + "_KeySync";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Key Sync On/Off";
		nrpn = 41 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::toggleButton },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 2 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, 507 + lfoNum * lfoControlsGroup_w },
					{ ID::property_Center_y, lfoRow_1_center_y },
					{ ID::property_Width, GUI::toggle_diameter },
					{ ID::property_Height, GUI::toggle_diameter },
					{ ID::property_Description, Description::buildFor_LFO_KeySync(lfoNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 452 + lfoNum * lfoControlsGroup_w },
					{ ID::property_AllowedChoicesBackground_y, 381 },
				}, {
					ValueTree{ ChoiceNames::buildFor_OffOn(concise) },
					ValueTree{ ChoiceNames::buildFor_OffOn(verbose) }
				}
			}, -1, nullptr);
	}

	//--------------------------------------------------------------------------------------------------------------- Envelope 3

	const int env3ControlsRow1_y{ 531 };
	const int env3ControlsRow2_y{ 583 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_061", {
				{ ID::property_ParamID, ID::ep_061_Env_3_Destination.toString() },
				{ ID::property_ExposedName, "Envelope 3 Modulation Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 57 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, env3ControlsRow2_y },
				{ ID::property_Width, 126 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, modDestinationParamDescription + String(" by envelope 3.") },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 30 },
				{ ID::property_AllowedChoicesBackground_y, 211 },
			}, {
				ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
				ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_062", {
				{ ID::property_ParamID, ID::ep_062_Env_3_Amount.toString() },
				{ ID::property_ExposedName, "Envelope 3 Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 58 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, env3ControlsRow1_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_Env_3_Amount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, 83 },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_063", {
				{ ID::property_ParamID, ID::ep_063_Env_3_VelAmount.toString() },
				{ ID::property_ExposedName, "Envelope 3 Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 59 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, env3ControlsRow1_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvVelAmount(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, 275 },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	auto env3_Row_2_AllowedChoices_y{ 327 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_064", {
				{ ID::property_ParamID, ID::ep_064_Env_3_Delay.toString() },
				{ ID::property_ExposedName, "Envelope 3 Delay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 60 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_4_x },
				{ ID::property_Center_y, env3ControlsRow2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvDelay(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_065", {
				{ ID::property_ParamID, ID::ep_065_Env_3_Attack.toString() },
				{ ID::property_ExposedName, "Envelope 3 Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 61 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_5_x },
				{ ID::property_Center_y, env3ControlsRow2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvAttack(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_066", {
				{ ID::property_ParamID, ID::ep_066_Env_3_Decay.toString() },
				{ ID::property_ExposedName, "Envelope 3 Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 62 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, env3ControlsRow2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvDecay(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_067", {
				{ ID::property_ParamID, ID::ep_067_Env_3_Sustain.toString() },
				{ ID::property_ExposedName, "Envelope 3 Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 63 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, env3ControlsRow2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvSustain(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_068", {
				{ ID::property_ParamID, ID::ep_068_Env_3_Release.toString() },
				{ ID::property_ExposedName, "Envelope 3 Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 64 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, env3ControlsRow2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_EnvRelease(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_069", {
				{ ID::property_ParamID, ID::ep_069_Env_3_Repeat.toString() },
				{ ID::property_ExposedName, "Envelope 3 Repeat" },
				{ ID::property_ControlType, (int)ControlType::toggleButton },
				{ ID::property_NRPN, 98 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_1_x },
				{ ID::property_Center_y, env3ControlsRow1_y },
				{ ID::property_Width, GUI::toggle_diameter },
				{ ID::property_Height, GUI::toggle_diameter },
				{ ID::property_Description, Description::buildFor_Env_3_Repeat() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x - GUI::toggleLockButton_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, 398 },
			}, {
				ValueTree{ ChoiceNames::buildFor_OffOn(concise) },
				ValueTree{ ChoiceNames::buildFor_OffOn(verbose) }
			}
		}, -1, nullptr);

	//--------------------------------------------------------------------------------------------------------------- modulators

	const int modulatorComboBox_w{ 126 };
	const int modulatorControlsCol1_x{ 486 };
	const int modulatorControlsCol2_x{ 575 };
	const int modulatorControlsGroup_h{ 78 };
	const int modulatorComboBoxes_AllowedChoices_x{ 559 };

	for (uint8 modNum = 0; modNum != 4; ++modNum) {
		auto paramNumString{ "ep_0" + (String)(70 + modNum * 3) };
		auto paramID_String{ paramNumString + "_Mod_" + String(modNum + 1) + "_Source" };
		auto exposedNameString{ "Modulator " + String(modNum + 1) + " Source" };
		auto nrpn{ 65 + modNum * 3 };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForModSource },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, modulatorControlsCol1_x },
					{ ID::property_Center_y, 184 + modNum * modulatorControlsGroup_h },
					{ ID::property_Width, modulatorComboBox_w },
					{ ID::property_Height, GUI::comboBox_h },
					{ ID::property_Description, "Selects the modulation source." },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModSource },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModSource },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, modulatorComboBoxes_AllowedChoices_x },
					{ ID::property_AllowedChoicesBackground_y, 39 + modNum * modulatorControlsGroup_h },
				}, {
					ValueTree{ ChoiceNames::buildFor_ModSource(concise) },
					ValueTree{ ChoiceNames::buildFor_ModSource(verbose) }
				}
			}, -1, nullptr);

		paramNumString = "ep_0" + (String)(71 + modNum * 3);
		paramID_String = paramNumString + "_Mod_" + String(modNum + 1) + "_Amount";
		exposedNameString = "Modulator " + String(modNum + 1) + " Amount";
		nrpn = 66 + modNum * 3;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 255 },
					{ ID::property_DefaultChoice, 127 },
					{ ID::property_Center_x, modulatorControlsCol2_x },
					{ ID::property_Center_y, 201 + modNum * modulatorControlsGroup_h },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_ModAmount() },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
					{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
					{ ID::property_AllowedChoicesBackground_x, modulatorControlsCol2_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, 109 },
				}, {
					ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
					ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
				}
			}, -1, nullptr);

		paramNumString = "ep_0" + (String)(72 + modNum * 3);
		paramID_String = paramNumString + "_Mod_" + String(modNum + 1) + "_Destination";
		exposedNameString = "Modulator " + String(modNum + 1) + " Destination";
		nrpn = 67 + modNum * 3;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
					{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, modulatorControlsCol1_x },
					{ ID::property_Center_y, 218 + modNum * modulatorControlsGroup_h },
					{ ID::property_Width, modulatorComboBox_w },
					{ ID::property_Height, GUI::comboBox_h },
					{ ID::property_Description, "Selects the target parameter for modulation." },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, modulatorComboBoxes_AllowedChoices_x },
					{ ID::property_AllowedChoicesBackground_y, 141 },
				}, {
					ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
					ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
				}
			}, -1, nullptr);
	}

	//---------------------------------------------------------------------------------------------------------- MIDI modulators

	const int midiControllerComboBox_w{ 136 };
	const int midiControllersCol1_x{ 680 };
	const int midiControllersCol2_x{ 776 };
	const int midiControllersGroup_h{ 62 };
	const int midiControllersRow1_y{ 191 };
	const int midiControllersRow2_y{ midiControllersRow1_y + midiControllersGroup_h };
	const int midiControllersRow3_y{ midiControllersRow2_y + midiControllersGroup_h };
	const int midiControllersRow4_y{ midiControllersRow3_y + midiControllersGroup_h };
	const int midiControllersRow5_y{ midiControllersRow4_y + midiControllersGroup_h };

	auto midiModAmountsAllowedChoices_x{ 264 };
	auto midiModAmountsAllowedChoices_y{ 106 };
	auto midiModDestinationsAllowedChoices_x{ 758 };
	auto midiModDestinationsAllowedChoices_y{ 138 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_082", {
				{ ID::property_ParamID, ID::ep_082_ModWheelAmount.toString() },
				{ ID::property_ExposedName, "Modulation Wheel Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 81 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol2_x },
				{ ID::property_Center_y, midiControllersRow1_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_ModWheelAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_083", {
				{ ID::property_ParamID, ID::ep_083_ModWheelDest.toString() },
				{ ID::property_ExposedName, "Modulation Wheel Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 82 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, midiControllersCol1_x },
				{ ID::property_Center_y, midiControllersRow1_y },
				{ ID::property_Width, midiControllerComboBox_w },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, modDestinationParamDescription + String(".") },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, midiModDestinationsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModDestinationsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
				ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_084", {
				{ ID::property_ParamID, ID::ep_084_PressureAmount.toString() },
				{ ID::property_ExposedName, "Pressure (Aftertouch) Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 83 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol2_x },
				{ ID::property_Center_y, midiControllersRow2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_PressureAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_085", {
				{ ID::property_ParamID, ID::ep_085_PressureDest.toString() },
				{ ID::property_ExposedName, "Pressure (Aftertouch) Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 84 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, midiControllersCol1_x },
				{ ID::property_Center_y, midiControllersRow2_y },
				{ ID::property_Width, midiControllerComboBox_w },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, modDestinationParamDescription + String(".") },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, midiModDestinationsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModDestinationsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
				ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_086", {
				{ ID::property_ParamID, ID::ep_086_BreathAmount.toString() },
				{ ID::property_ExposedName, "Breath Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 85 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol2_x },
				{ ID::property_Center_y, midiControllersRow3_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_BreathAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_087", {
				{ ID::property_ParamID, ID::ep_087_BreathDest.toString() },
				{ ID::property_ExposedName, "Breath Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 86 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, midiControllersCol1_x },
				{ ID::property_Center_y, midiControllersRow3_y },
				{ ID::property_Width, midiControllerComboBox_w },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, modDestinationParamDescription + String(".") },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, midiModDestinationsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModDestinationsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
				ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_088", {
				{ ID::property_ParamID, ID::ep_088_VelocityAmount.toString() },
				{ ID::property_ExposedName, "Note Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 87 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol2_x },
				{ ID::property_Center_y, midiControllersRow4_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_VelocityAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_089", {
				{ ID::property_ParamID, ID::ep_089_VelocityDest.toString() },
				{ ID::property_ExposedName, "Note Velocity Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 88 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, midiControllersCol1_x },
				{ ID::property_Center_y, midiControllersRow4_y },
				{ ID::property_Width, midiControllerComboBox_w },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, modDestinationParamDescription + String(".") },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, midiModDestinationsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModDestinationsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
				ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_090", {
				{ ID::property_ParamID, ID::ep_090_PedalAmount.toString() },
				{ ID::property_ExposedName, "Foot Pedal Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 89 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol2_x },
				{ ID::property_Center_y, midiControllersRow5_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_PedalAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PlusMinus127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PlusMinus127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PlusMinus127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(concise) },
				ValueTree{ ChoiceNames::buildFor_PlusMinus127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_091", {
				{ ID::property_ParamID, ID::ep_091_PedalDest.toString() },
				{ ID::property_ExposedName, "Foot Pedal Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 90 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, midiControllersCol1_x },
				{ ID::property_Center_y, midiControllersRow5_y },
				{ ID::property_Width, midiControllerComboBox_w },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, modDestinationParamDescription + String(".") },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, midiModDestinationsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModDestinationsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildFor_ModDestination(concise) },
				ValueTree{ ChoiceNames::buildFor_ModDestination(verbose) }
			}
		}, -1, nullptr);

	//------------------------------------------------------------------------------------------------------------------ Push It

	const int pushiItKnobsRow_y{ 528 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_092", {
				{ ID::property_ParamID, ID::ep_092_PushItPitch.toString() },
				{ ID::property_ExposedName, "Push It! Switch Pitch" },
				{ ID::property_ControlType, (int)ControlType::knobForPitch },
				{ ID::property_NRPN, 111 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
				{ ID::property_DefaultChoice, 60 },
				{ ID::property_Center_x, 1191 },
				{ ID::property_Center_y, pushiItKnobsRow_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_PushItPitch() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_OscPitch },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_OscPitch },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Pitch },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 759 },
				{ ID::property_AllowedChoicesBackground_y, 207 },
			}, {
				ValueTree{ ChoiceNames::buildFor_OscPitch(concise) },
				ValueTree{ ChoiceNames::buildFor_OscPitch(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_093", {
				{ ID::property_ParamID, ID::ep_093_PushItVelocity.toString() },
				{ ID::property_ExposedName, "Push It! Switch Velocity" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 112 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 100 },
				{ ID::property_Center_x, 1239 },
				{ ID::property_Center_y, pushiItKnobsRow_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_PushItVelocity() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0to127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0to127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0to127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 807 },
				{ ID::property_AllowedChoicesBackground_y, 271 },
			}, {
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildFor_PlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_094", {
				{ ID::property_ParamID, ID::ep_094_PushItMode.toString() },
				{ ID::property_ExposedName, "Push It! Switch Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 113 },
				{ ID::property_NumberOfChoices, 3 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, 1215 },
				{ ID::property_Center_y, 577 },
				{ ID::property_Width, 88 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildFor_PushItMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 72 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 3 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 1153 },
				{ ID::property_AllowedChoicesBackground_y, 359 },
			}, {
				ValueTree{ ChoiceNames::buildFor_PushItMode(concise) },
				ValueTree{ ChoiceNames::buildFor_PushItMode(verbose) }
			}
		}, -1, nullptr);

	//------------------------------------------------------------------------------------------------------ clock & arpeggiator

	const int clockAndSequencerControlsRow_y{ 126 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_095", {
				{ ID::property_ParamID, ID::ep_095_ClockTempo.toString() },
				{ ID::property_ExposedName, "Clock Tempo" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_NRPN, 91 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForClockTempo },
				{ ID::property_DefaultChoice, 90 },
				{ ID::property_Center_x, 1236 },
				{ ID::property_Center_y, clockAndSequencerControlsRow_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_ClockTempo() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 12 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 26 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 20 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 860 },
				{ ID::property_AllowedChoicesBackground_y, 106 },
			}, {
				ValueTree{ ChoiceNames::buildFor_ClockTempo(concise) },
				ValueTree{ ChoiceNames::buildFor_ClockTempo(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_096", {
				{ ID::property_ParamID, ID::ep_096_ClockDivision.toString() },
				{ ID::property_ExposedName, "Clock Division" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 92 },
				{ ID::property_NumberOfChoices, 13 },
				{ ID::property_DefaultChoice, 2 },
				{ ID::property_Center_x, 1139 },
				{ ID::property_Center_y, clockAndSequencerControlsRow_y },
				{ ID::property_Width, 126 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildFor_ClockDivision() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 2 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 118 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 7 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 797 },
				{ ID::property_AllowedChoicesBackground_y, 118 },
			}, {
				ValueTree{ ChoiceNames::buildFor_ClockDivision(concise) },
				ValueTree{ ChoiceNames::buildFor_ClockDivision(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_097", {
				{ ID::property_ParamID, ID::ep_097_ArpegMode.toString() },
				{ ID::property_ExposedName, "Arpeggiator Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 97 },
				{ ID::property_NumberOfChoices, 15 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_10_x },
				{ ID::property_Center_y, 118 },
				{ ID::property_Width, 124 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildFor_ArpegMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 3 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 120 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 5 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 572 },
				{ ID::property_AllowedChoicesBackground_y, 110 },
			}, {
				ValueTree{ ChoiceNames::buildFor_ArpegMode(concise) },
				ValueTree{ ChoiceNames::buildFor_ArpegMode(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_098", {
				{ ID::property_ParamID, ID::ep_098_ArpegOnOff.toString() },
				{ ID::property_ExposedName, "Arpeggiator On/Off" },
				{ ID::property_ControlType, (int)ControlType::toggleButton },
				{ ID::property_NRPN, 100 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_9_x },
				{ ID::property_Center_y, oscRow_2_center_y },
				{ ID::property_Width, GUI::toggle_diameter },
				{ ID::property_Height, GUI::toggle_diameter },
				{ ID::property_Description, Description::buildFor_ArpegOnOff() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_9_x + allowedChoicesOffset_Toggles },
				{ ID::property_AllowedChoicesBackground_y, oscRow_2_center_y - GUI::toggleLockButton_diameter / 2 },
			}, {
				ValueTree{ ChoiceNames::buildFor_OffOn(concise) },
				ValueTree{ ChoiceNames::buildFor_OffOn(verbose) }
			}
		}, -1, nullptr);

	//---------------------------------------------------------------------------------------------------------------- sequencer

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_099", {
				{ ID::property_ParamID, ID::ep_099_SeqTrigMode.toString() },
				{ ID::property_ExposedName, "Sequencer Trigger Mode" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 94 },
				{ ID::property_NumberOfChoices, 6 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, 998 },
				{ ID::property_Center_y, clockAndSequencerControlsRow_y },
				{ ID::property_Width, 114 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildFor_SeqTrigMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 104 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 6 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 1065 },
				{ ID::property_AllowedChoicesBackground_y, 118 },
			}, {
				ValueTree{ ChoiceNames::buildFor_SeqTrigMode(concise) },
				ValueTree{ ChoiceNames::buildFor_SeqTrigMode(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_100", {
				{ ID::property_ParamID, ID::ep_100_SeqOnOff.toString() },
				{ ID::property_ExposedName, "Sequencer On/Off" },
				{ ID::property_ControlType, (int)ControlType::toggleButton },
				{ ID::property_NRPN, 101 },
				{ ID::property_NumberOfChoices, 2 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, 819 },
				{ ID::property_Center_y, clockAndSequencerControlsRow_y },
				{ ID::property_Width, GUI::toggle_diameter },
				{ ID::property_Height, GUI::toggle_diameter },
				{ ID::property_Description, Description::buildFor_SeqOnOff() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 819 - GUI::toggle_diameter / 2},
				{ ID::property_AllowedChoicesBackground_y, clockAndSequencerControlsRow_y + allowedChoicesOffset_Toggles  },
			}, {
				ValueTree{ ChoiceNames::buildFor_OffOn(concise) },
				ValueTree{ ChoiceNames::buildFor_OffOn(verbose) }
			}
		}, -1, nullptr);

	const int seqTrackDestComboBoxes_w{ 126 };
	const int seqTrackDestComboBoxes_x{ 1065 };

	for (uint8 trackNum = 1; trackNum != 5; ++trackNum) {
		auto paramNumString{ "ep_10" + String(trackNum) };
		auto paramID_String{ paramNumString + "_SeqTrack_" + (String)trackNum + "_Dest" };
		auto exposedNameString{ "Sequencer Track " + (String)trackNum + " Destination" };
		auto nrpn{ 76 + trackNum };
		auto trackNumIsEven{ trackNum == 2 || trackNum == 4 };
		auto numberOfChoices{ trackNumIsEven ? EP::numberOfChoicesForSeqTracks_2_4_Dest : EP::numberOfChoicesForModDest };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
				{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, numberOfChoices },
					{ ID::property_DefaultChoice, trackNum < 3 ? trackNum : trackNum == 3 ? 9 : 0 },
					{ ID::property_Center_x, seqTrackDestComboBoxes_x },
					{ ID::property_Center_y, 169 + ((trackNum - 1) * GUI::seqTrackControlsGroup_h) },
					{ ID::property_Width, seqTrackDestComboBoxes_w },
					{ ID::property_Height, GUI::comboBox_h },
					{ ID::property_Description, Description::buildFor_SeqTrackDestination(trackNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 498 },
					{ ID::property_AllowedChoicesBackground_y, 138 },
				}, {
					ValueTree{ trackNumIsEven ?
						ChoiceNames::buildFor_SeqTracks_2_4_Destination(trackNum, concise) :
						ChoiceNames::buildFor_ModDestination(concise) },
					ValueTree{ trackNumIsEven ?
						ChoiceNames::buildFor_SeqTracks_2_4_Destination(trackNum, verbose) :
						ChoiceNames::buildFor_ModDestination(verbose) }
				}
			}, -1, nullptr);
	}

	//-------------------------------------------------------------------------------------------------------------- knob assign

	const int knobAssignComboBoxes_w{ 134 };
	const int knobAssignComboBoxes_x{ 1089 };
	const int knobAssignComboBoxesVertSpacing{ 28 };

	for (uint8 knobNum = 1; knobNum != 5; ++knobNum) {
		auto paramNumString{ "ep_" + String(104 + knobNum) };
		auto paramID_String{ paramNumString + "_AssignKnob_" + (String)knobNum };
		auto exposedNameString{ "Assign Parameter to Knob " + (String)knobNum };
		auto nrpn{ 104 + knobNum };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {
				{ ID::property_ParamID, paramID_String },
					{ ID::property_ExposedName, exposedNameString },
					{ ID::property_ControlType, (int)ControlType::comboBox },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 169 },
					{ ID::property_DefaultChoice, knobNum == 1 ? 5 : knobNum == 2 ? 11 : knobNum == 3 ? 43 : 23 },
					{ ID::property_Center_x, knobAssignComboBoxes_x },
					{ ID::property_Center_y, 521 + (knobNum - 1) * knobAssignComboBoxesVertSpacing },
					{ ID::property_Width, knobAssignComboBoxes_w },
					{ ID::property_Height, GUI::comboBox_h },
					{ ID::property_Description, Description::buildFor_KnobAssign(knobNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 9 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 134 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 20 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 17 },
					{ ID::property_AllowedChoicesBackground_y, 85 + (knobNum - 1) * knobAssignComboBoxesVertSpacing },
				}, {
					ValueTree{ ChoiceNames::buildFor_KnobAssign(concise) },
					ValueTree{ ChoiceNames::buildFor_KnobAssign(verbose) }
				}
			}, -1, nullptr);
	}

	//---------------------------------------------------------------------------------------------------------- sequencer steps

	const int gapBetweenSeqStepsAndVoiceNameCharacters{ 2 };

	for (auto trackNum = 0; trackNum != 4; ++trackNum) {
		auto trackString{ String(trackNum + 1) };
		for (auto stepNum = 0; stepNum != 16; ++stepNum) {
			auto stepString{ String(stepNum + 1) };
			auto paramNumString{ "ep_" + String(EP::firstSeqStepParamIndex + trackNum * 16 + stepNum) };
			auto paramID_String{ paramNumString + "_SeqTrack_" + trackString + "_Step_" + stepString };
			auto exposedNameString{ "Sequencer Track " + trackString + " Step " + stepString };
			auto nrpn{ 120 + trackNum * 16 + stepNum };
			exposedParamsInfoTree.addChild(
				ValueTree{ paramNumString, {
						{ ID::property_ParamID, paramID_String },
						{ ID::property_ExposedName, exposedNameString },
						{ ID::property_ControlType, (int)ControlType::seqTrackStep },
						{ ID::property_NRPN, nrpn },
						{ ID::property_NumberOfChoices, trackNum == 0 ? 128 : 127 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, 825 + stepNum * (GUI::seqSteps_w + gapBetweenSeqStepsAndVoiceNameCharacters) },
						{ ID::property_Center_y, 196 + trackNum * GUI::seqTrackControlsGroup_h },
						{ ID::property_Width, GUI::seqSteps_w },
						{ ID::property_Height, GUI::seqSteps_h },
						{ ID::property_Description, Description::buildFor_SeqTrackStep(trackNum + 1, stepNum + 1) },
						{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::seqTrackStep },
						{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
						{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
						{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
						{ ID::property_FirstAllowChoiceToggleRow, 0 },
						{ ID::property_AllowedChoicesBackground_x, 0 },
						{ ID::property_AllowedChoicesBackground_y, 0 },
						{ ID::property_SeqTrackNum, trackNum + 1 },
						{ ID::property_SeqTrackStepNum, stepNum + 1 },
					}, {
						ValueTree{ ChoiceNames::buildFor_SeqTrackStep(concise) },
						ValueTree{ ChoiceNames::buildFor_SeqTrackStep(verbose) }
					}
				}, -1, nullptr);
		}
	}

	//---------------------------------------------------------------------------------------------------- voice name characters

	const int voiceNameCharacters_y{ 52 };

	for (auto charNum = 0; charNum != VCS::numberOfCharsInVoiceName; ++charNum) {
		auto charNumString{ String(charNum + 1) };
		auto paramNumString{ String(EP::firstVoiceNameCharParamIndex + charNum) };
		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + paramNumString, {
					{ ID::property_ParamID, "ep_" + paramNumString + "_VoiceNameChar_" + charNumString },
					{ ID::property_ExposedName, "Program Name Character " + charNumString },
					{ ID::property_ControlType, (int)ControlType::voiceNameChar },
					{ ID::property_NRPN, 184 + charNum },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForVoiceNameChar },
					{ ID::property_DefaultChoice, int(String("Basic Program   ")[charNum]) },
					{ ID::property_Center_x, 596 + charNum * (GUI::voiceNameCharacters_w + gapBetweenSeqStepsAndVoiceNameCharacters) },
					{ ID::property_Center_y, voiceNameCharacters_y },
					{ ID::property_Width, GUI::voiceNameCharacters_w },
					{ ID::property_Height, GUI::voiceNameCharacters_h },
					{ ID::property_Description, Description::buildFor_VoiceNameChar(charNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::voiceNameChar },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 590 + charNum * (GUI::voiceNameCharacters_w + gapBetweenSeqStepsAndVoiceNameCharacters) },
					{ ID::property_AllowedChoicesBackground_y, 71 },
				}, {
					ValueTree{ ChoiceNames::buildFor_VoiceNameChar(concise) },
					ValueTree{ ChoiceNames::buildFor_VoiceNameChar(verbose) }
				}
			}, -1, nullptr);
	}

	setDataByteLocationPropertiesForAllParams();
}

void InfoForExposedParameters::setDataByteLocationPropertiesForAllParams() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramNumString{ (String)paramIndex };
		auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
		auto paramPropertiesTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
		auto firstUnassignedParamNumber{ 109 };
		auto numberOfUnassignedParams{ (uint8)11 };
		auto paramNumber{ paramIndex };
		if (paramNumber >= firstUnassignedParamNumber)
			paramNumber += numberOfUnassignedParams;
		auto msBitPackedByteLocation{ uint16((paramNumber / 7) * 8) };
		paramPropertiesTree.setProperty(ID::property_MSBitPackedByteLocation, msBitPackedByteLocation, nullptr);
		uint8 msBitMask{ (uint8)(roundToInt(pow(2, paramNumber % 7))) };
		paramPropertiesTree.setProperty(ID::property_MSBitMask, msBitMask, nullptr);
		uint16 lsByteLocation{ (uint16)(msBitPackedByteLocation + paramNumber % 7 + 1) };
		paramPropertiesTree.setProperty(ID::property_LSByteLocation, lsByteLocation, nullptr);
	}
}

//==============================================================================================================================

Identifier InfoForExposedParameters::IDfor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return Identifier{ paramTree.getProperty(ID::property_ParamID).toString() };
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return paramTree.getProperty(ID::property_ExposedName).toString();
}

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto controlTypeIndex{ (int)paramTree.getProperty(ID::property_ControlType) };
	return ControlType{ controlTypeIndex };
}

uint8 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto NRPN{ (int)paramTree.getProperty(ID::property_NRPN) };
	return (uint8)NRPN;
}

uint8 InfoForExposedParameters::paramIndexForNRPN(const uint8 NRPN) const {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		if (NRPNfor(paramIndex) == NRPN)
			return paramIndex;
	}
	return (uint8)255;
}

uint8 InfoForExposedParameters::numberOfChoicesFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto numberOfChoices{ (int)paramTree.getProperty(ID::property_NumberOfChoices) };
	return (uint8)numberOfChoices;
}

uint8 InfoForExposedParameters::lastChoiceFor(uint8 paramIndex) const {
	return uint8(numberOfChoicesFor(paramIndex) - 1);
}

uint8 InfoForExposedParameters::defaultChoiceFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto defaultChoice{ (int)paramTree.getProperty(ID::property_DefaultChoice) };
	return (uint8)defaultChoice;
}

Point<int> InfoForExposedParameters::centerPointFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto center_x{ (int)paramTree.getProperty(ID::property_Center_x) };
	auto center_y{ (int)paramTree.getProperty(ID::property_Center_y) };
	return Point<int>(center_x, center_y);
}

int InfoForExposedParameters::widthFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return (int)paramTree.getProperty(ID::property_Width);
}

int InfoForExposedParameters::heightFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return (int)paramTree.getProperty(ID::property_Height);
}

String InfoForExposedParameters::choiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto choiceNamesTree{ paramTree.getChildWithName(ID::choiceNames) };
	auto choiceName{ choiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return choiceName;
}

String InfoForExposedParameters::verboseChoiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto verboseChoiceNamesTree{ paramTree.getChildWithName(ID::choiceNames_Verbose) };
	auto verboseChoiceName{ verboseChoiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return verboseChoiceName;
}

StringArray InfoForExposedParameters::choiceNamesListFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	StringArray choiceNamesList;
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoicesFor(paramIndex); ++choiceNum)
		choiceNamesList.add(choiceNameFor(choiceNum, paramIndex));
	return choiceNamesList;
}

StringArray InfoForExposedParameters::verboseChoiceNamesListFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	StringArray verboseChoiceNamesList;
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoicesFor(paramIndex); ++choiceNum)
		verboseChoiceNamesList.add(verboseChoiceNameFor(choiceNum, paramIndex));
	return verboseChoiceNamesList;
}

String InfoForExposedParameters::descriptionFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return paramTree.getProperty(ID::property_Description).toString();
}

int InfoForExposedParameters::mouseDragSensitivityFor(uint8 paramIndex) const {
	return 80 + roundToInt(numberOfChoicesFor(paramIndex) / 2);
}

uint16 InfoForExposedParameters::msBitPackedByteLocationFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto msBitLocation((int)paramTree.getProperty(ID::property_MSBitPackedByteLocation));
	return (uint16)msBitLocation;
}

uint8 InfoForExposedParameters::msBitMaskFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto msBitMask{ (int)paramTree.getProperty(ID::property_MSBitMask) };
	return (uint8)msBitMask;
}

uint16 InfoForExposedParameters::lsByteLocationFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto lsByteLocation{ (int)paramTree.getProperty(ID::property_LSByteLocation) };
	return (uint8)lsByteLocation;
}

AllowedChoicesType InfoForExposedParameters::allowedChoicesTypeFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto allowedChoicesTypeIndex{ (int)paramTree.getProperty(ID::property_AllowedChoicesType) };
	return AllowedChoicesType{ allowedChoicesTypeIndex };
}

int InfoForExposedParameters::numberOfAllowChoiceToggleColumnsFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto numberOfColumns{ (int)paramTree.getProperty(ID::property_NumberOfAllowChoiceToggleColumns) };
	return numberOfColumns;
}

int InfoForExposedParameters::widthOfAllowChoiceToggleColumnFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto columnWidth{ (int)paramTree.getProperty(ID::property_WidthOfAllowChoiceToggleColumn) };
	return columnWidth;
}

int InfoForExposedParameters::numberOfAllowChoiceToggleRowsFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto numberOfRows{ (int)paramTree.getProperty(ID::property_NumberOfAllowChoiceToggleRows) };
	return numberOfRows;
}

int InfoForExposedParameters::firstAllowChoiceToggleRowFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto firstRow{ (int)paramTree.getProperty(ID::property_FirstAllowChoiceToggleRow) };
	return firstRow;
}

int InfoForExposedParameters::allowedChoicesBackground_x_For(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto background_x{ (int)paramTree.getProperty(ID::property_AllowedChoicesBackground_x) };
	return background_x;
}

int InfoForExposedParameters::allowedChoicesBackground_y_For(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto background_y{ (int)paramTree.getProperty(ID::property_AllowedChoicesBackground_y) };
	return background_y;
}

int InfoForExposedParameters::seqTrackNum_For(uint8 paramIndex) const {
	jassert(paramIndex >= EP::firstSeqStepParamIndex && paramIndex < EP::firstVoiceNameCharParamIndex);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto trackNum{ (int)paramTree.getProperty(ID::property_SeqTrackNum) };
	return trackNum;
}

int InfoForExposedParameters::seqTrackStepNum_For(uint8 paramIndex) const {
	jassert(paramIndex >= EP::firstSeqStepParamIndex && paramIndex < EP::firstVoiceNameCharParamIndex);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto stepNum{ (int)paramTree.getProperty(ID::property_SeqTrackStepNum) };
	return stepNum;
}