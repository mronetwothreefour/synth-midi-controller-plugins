#include "ep_1_tree_InfoForExposedParameters.h"

#include "ep_0_build_ChoiceNamesValueTree.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../descriptions/build_ExposedParamDescription.h"

using Description = ExposedParamDescription;
using ChoiceNames = ExposedParamChoiceNamesValueTree;

InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::tree_ExposedParamsInfo }
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

	const int firstAllowChoiceRow_PosNeg_127{ 13 };

	const int numberOfAllowChoiceColumns_0_To_127{ 16 };
	const int numberOfAllowChoiceColumns_ModDestination{ 3 };
	const int numberOfAllowChoiceColumns_ModSource{ 2 };
	const int numberOfAllowChoiceColumns_OscPitch{ 11 };
	const int numberOfAllowChoiceColumns_PosNeg_127{ 14 };

	const int numberOfAllowChoiceRows_0_To_127{ 8 };
	const int numberOfAllowChoiceRows_ModDestination{ 16 };
	const int numberOfAllowChoiceRows_ModSource{ 12 };
	const int numberOfAllowChoiceRows_PosNeg_127{ 20 };
	const int numberOfAllowChoiceRows_Pitch{ 12 };

	const int widthOfAllowChoiceColumns_0_To_127{ 26 };
	const int widthOfAllowChoiceColumns_ModSourceAndDestination{ 130 };
	const int widthOfAllowChoiceColumns_OscPitch{ 38 };
	const int widthOfAllowChoiceColumns_PosNeg_127{ 32 };

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
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::oscPitch },
					{ ID::property_NRPN, oscNum == 1 ? 0 : 5 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
					{ ID::property_DefaultChoice, 24 },
					{ ID::property_Center_x, controlsCol_1_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForOscPitch(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_OscPitch },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_OscPitch },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Pitch },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildForOscPitch(concise) },
					ValueTree{ ChoiceNames::buildForOscPitch(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_001" : "ep_007", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_001_Osc_1_FineTune.toString() : ID::ep_007_Osc_2_FineTune.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Fine Tune" },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::oscFineTune },
					{ ID::property_NRPN, oscNum == 1 ? 1 : 6 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscFineTune },
					{ ID::property_DefaultChoice, oscNum == 1 ? 49 : 51 },
					{ ID::property_Center_x, controlsCol_2_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForOscFine(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 11 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 28 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 10 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildForOscFineTune(concise) },
					ValueTree{ ChoiceNames::buildForOscFineTune(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_002" : "ep_008", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_002_Osc_1_Shape.toString() : ID::ep_008_Osc_2_Shape.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Wave Shape" },
					{ ID::property_ControlType, (int)ControlType::knobForOscShape },
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::oscShape },
					{ ID::property_NRPN, oscNum == 1 ? 2 : 7 },
					{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscWaveShape },
					{ ID::property_DefaultChoice, 1 },
					{ ID::property_Center_x, controlsCol_3_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForOscShape(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::oscShape },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildForOscShape(concise) },
					ValueTree{ ChoiceNames::buildForOscShape(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_003" : "ep_009", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_003_Osc_1_Glide.toString() : ID::ep_009_Osc_2_Glide.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Glide Rate" },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
					{ ID::property_NRPN, oscNum == 1 ? 3 : 8 },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, controlsCol_4_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForOscGlide(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildForPlainValue((uint8)128, concise) },
					ValueTree{ ChoiceNames::buildForPlainValue((uint8)128, verbose) }
				}
			}, -1, nullptr);

		auto keyTrackAllowedChoices_y{ center_y + 11 };
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_004" : "ep_010", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_004_Osc_1_KeyTrack.toString() : ID::ep_010_Osc_2_KeyTrack.toString() },
					{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Keyboard Track On/Off" },
					{ ID::property_ControlType, (int)ControlType::toggleButton },
					{ ID::property_NRPN, oscNum == 1 ? 4 : 9 },
					{ ID::property_NumberOfChoices, 2 },
					{ ID::property_DefaultChoice, 1 },
					{ ID::property_Center_x, controlsCol_6_x },
					{ ID::property_Center_y, center_y + 11 },
					{ ID::property_Width, 32 },
					{ ID::property_Height, 36 },
					{ ID::property_RedToggleCenter_x, controlsCol_6_x },
					{ ID::property_RedToggleCenter_y, center_y },
					{ ID::property_Description, Description::buildForOscKeyTrack(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Toggles },
					{ ID::property_AllowedChoicesBackground_y, keyTrackAllowedChoices_y },
				}, {
					ValueTree{ ChoiceNames::buildForOffOn(concise) },
					ValueTree{ ChoiceNames::buildForOffOn(verbose) }
				}
			}, -1, nullptr);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_005" : "ep_011", {
					{ ID::property_ParamID, oscNum == 1 ? ID::ep_005_Osc_1_SubLevel.toString() : ID::ep_011_Osc_2_SubLevel.toString() },
					{ ID::property_ExposedName, "Sub-Oscillator " + (String)oscNum + " Level"  },
					{ ID::property_ControlType, (int)ControlType::knob },
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
					{ ID::property_NRPN, oscNum == 1 ? 114 : 115 },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, controlsCol_5_x },
					{ ID::property_Center_y, center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForOscSubLevel(oscNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, knobTop_y },
				}, {
					ValueTree{ ChoiceNames::buildForPlainValue((uint8)128, concise) },
					ValueTree{ ChoiceNames::buildForPlainValue((uint8)128, verbose) }
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
				{ ID::property_Center_x, 242 },
				{ ID::property_Center_y, 22 },
				{ ID::property_Width, 76 },
				{ ID::property_Height, GUI::redToggle_diameter },
				{ ID::property_RedToggleCenter_x, 273 },
				{ ID::property_RedToggleCenter_y, 22 },
				{ ID::property_Description, Description::buildForOscSync() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Toggles },
				{ ID::property_AllowedChoicesBackground_y, 11 },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(concise) },
				ValueTree{ ChoiceNames::buildForOffOn(verbose) }
			}
		}, -1, nullptr);

	auto col_10_AllowedChoices_x{ controlsCol_10_x + 72 };
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
				{ ID::property_Description, Description::buildForGlideMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 124 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 4 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_10_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, 70 },
			}, {
				ValueTree{ ChoiceNames::buildForGlideMode(concise) },
				ValueTree{ ChoiceNames::buildForGlideMode(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_014", {
				{ ID::property_ParamID, ID::ep_014_OscSlop.toString() },
				{ ID::property_ExposedName, "Oscillator Slop" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::oscSlop },
				{ ID::property_NRPN, 12 },
				{ ID::property_NumberOfChoices, 6 },
				{ ID::property_DefaultChoice, 2 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, oscRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForOscSlop() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 14 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 6 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue((uint8)6, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue((uint8)6, verbose) }
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
				{ ID::property_Description, Description::buildForBendRange() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 34 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 13 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_9_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForBendRange(concise) },
				ValueTree{ ChoiceNames::buildForBendRange(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_016", {
				{ ID::property_ParamID, ID::ep_016_NotePriority.toString() },
				{ ID::property_ExposedName, "Note Priority (Key Assign)" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 96 },
				{ ID::property_NumberOfChoices, 6 },
				{ ID::property_DefaultChoice, 4 },
				{ ID::property_Center_x, controlsCol_10_x },
				{ ID::property_Center_y, 38 },
				{ ID::property_Width, 124 },
				{ ID::property_Height, GUI::comboBox_h },
				{ ID::property_Description, Description::buildForNotePriority() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 124 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 6 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_10_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, 30 },
			}, {
				ValueTree{ ChoiceNames::buildForNotePriority(concise) },
				ValueTree{ ChoiceNames::buildForNotePriority(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_017", {
				{ ID::property_ParamID, ID::ep_017_OscMix.toString() },
				{ ID::property_ExposedName, "Oscillator 1 & 2 Mix" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 13 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, oscRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForOscMix() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_018", {
				{ ID::property_ParamID, ID::ep_018_NoiseLevel.toString() },
				{ ID::property_ExposedName, "Noise Level" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 14 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, oscRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForNoiseLevel() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_019", {
				{ ID::property_ParamID, ID::ep_019_ExtInLevel.toString() },
				{ ID::property_ExposedName, "External Audio Input Level" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 116 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, oscRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForExtInLevel() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, oscRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	//---------------------------------------------------------------------------------------------------------------------- LPF

	const int lpfRow_1_center_y{ 167 };
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
				{ ID::property_NumberOfChoices, EP::numberOfChoicesFor_LPF_Freq },
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
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 16 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, lpfRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_Reso() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_022", {
				{ ID::property_ParamID, ID::ep_022_LPF_KeyAmount.toString() },
				{ ID::property_ExposedName, "LPF Keyboard Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 17 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, lpfRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_KeyAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_2_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_023", {
				{ ID::property_ParamID, ID::ep_023_LPF_FM_Amount.toString() },
				{ ID::property_ExposedName, "LPF FM (By Oscillator 1)" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 18 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_FM_Amount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
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
				{ ID::property_Width, 34 },
				{ ID::property_Height, 26 },
				{ ID::property_RedToggleCenter_x, controlsCol_2_x },
				{ ID::property_RedToggleCenter_y, 161 },
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
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 20 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, controlsCol_1_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_LPF_EnvAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, 187 },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_026", {
				{ ID::property_ParamID, ID::ep_026_LPF_VelAmount.toString() },
				{ ID::property_ExposedName, "LPF Envelope Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 21 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvVelAmount(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs},
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_027", {
				{ ID::property_ParamID, ID::ep_027_LPF_Delay.toString() },
				{ ID::property_ExposedName, "LPF Envelope Delay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 22 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_4_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvDelay(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_028", {
				{ ID::property_ParamID, ID::ep_028_LPF_Attack.toString() },
				{ ID::property_ExposedName, "LPF Envelope Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 23 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_5_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvAttack(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_029", {
				{ ID::property_ParamID, ID::ep_029_LPF_Decay.toString() },
				{ ID::property_ExposedName, "LPF Envelope Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 24 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvDecay(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_030", {
				{ ID::property_ParamID, ID::ep_030_LPF_Sustain.toString() },
				{ ID::property_ExposedName, "LPF Envelope Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 25 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvSustain(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_031", {
				{ ID::property_ParamID, ID::ep_031_LPF_Release.toString() },
				{ ID::property_ExposedName, "LPF Envelope Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 26 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, lpfRow_3_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvRelease(EnvelopeType::lpf) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, lpfRow_3_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
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
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 27 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_1_x },
				{ ID::property_Center_y, vcaRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_VCA_Level() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_033", {
				{ ID::property_ParamID, ID::ep_033_VCA_EnvAmount.toString() },
				{ ID::property_ExposedName, "VCA Envelope Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 30 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, vcaRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_VCA_EnvAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_034", {
				{ ID::property_ParamID, ID::ep_034_VCA_VelAmount.toString() },
				{ ID::property_ExposedName, "VCA Envelope Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 31 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, vcaRow_1_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvVelAmount(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_1_knobTop_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_035", {
				{ ID::property_ParamID, ID::ep_035_VCA_Delay.toString() },
				{ ID::property_ExposedName, "VCA Envelope Delay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 32 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_4_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvDelay(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_036", {
				{ ID::property_ParamID, ID::ep_036_VCA_Attack.toString() },
				{ ID::property_ExposedName, "VCA Envelope Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 33 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_5_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvAttack(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_037", {
				{ ID::property_ParamID, ID::ep_037_VCA_Decay.toString() },
				{ ID::property_ExposedName, "VCA Envelope Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 34 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvDecay(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_038", {
				{ ID::property_ParamID, ID::ep_038_VCA_Sustain.toString() },
				{ ID::property_ExposedName, "VCA Envelope Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 35 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvSustain(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_039", {
				{ ID::property_ParamID, ID::ep_039_VCA_Release.toString() },
				{ ID::property_ExposedName, "VCA Envelope Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 36 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 64 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvRelease(EnvelopeType::vca) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_040", {
				{ ID::property_ParamID, ID::ep_040_VoiceVolume.toString() },
				{ ID::property_ExposedName, "Program Volume" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 29 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 120 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, vcaRow_2_center_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForVoiceVolume() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x + allowedChoicesOffset_Knobs },
				{ ID::property_AllowedChoicesBackground_y, vcaRow_2_allowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
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
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 128 },
					{ ID::property_DefaultChoice, 0 },
					{ ID::property_Center_x, 461 + lfoNum * lfoControlsGroup_w },
					{ ID::property_Center_y, lfoRow_1_center_y },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildFor_LFO_Amount(lfoNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 236 + lfoNum * lfoControlsGroup_w },
					{ ID::property_AllowedChoicesBackground_y, 249 },
				}, {
					ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
					ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
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
					ValueTree{ ChoiceNames::buildForModDestination(concise) },
					ValueTree{ ChoiceNames::buildForModDestination(verbose) }
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
					{ ID::property_Center_y, 526 },
					{ ID::property_Width, 26 },
					{ ID::property_Height, 36 },
					{ ID::property_RedToggleCenter_x, 507 + lfoNum * lfoControlsGroup_w },
					{ ID::property_RedToggleCenter_y, lfoRow_1_center_y },
					{ ID::property_Description, Description::buildFor_LFO_KeySync(lfoNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 452 + lfoNum * lfoControlsGroup_w },
					{ ID::property_AllowedChoicesBackground_y, 381 },
				}, {
					ValueTree{ ChoiceNames::buildForOffOn(concise) },
					ValueTree{ ChoiceNames::buildForOffOn(verbose) }
				}
			}, -1, nullptr);
	}

	//--------------------------------------------------------------------------------------------------------------- Envelope 3

	const int env_3_ControlsRow_1_y{ 531 };
	const int env_3_ControlsRow_2_y{ 583 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_061", {
				{ ID::property_ParamID, ID::ep_061_Env_3_Destination.toString() },
				{ ID::property_ExposedName, "Envelope 3 Modulation Destination" },
				{ ID::property_ControlType, (int)ControlType::comboBox },
				{ ID::property_NRPN, 57 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, env_3_ControlsRow_2_y },
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
				ValueTree{ ChoiceNames::buildForModDestination(concise) },
				ValueTree{ ChoiceNames::buildForModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_062", {
				{ ID::property_ParamID, ID::ep_062_Env_3_Amount.toString() },
				{ ID::property_ExposedName, "Envelope 3 Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 58 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, controlsCol_2_x },
				{ ID::property_Center_y, env_3_ControlsRow_1_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnv_3_Amount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_2_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, 83 },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_063", {
				{ ID::property_ParamID, ID::ep_063_Env_3_VelAmount.toString() },
				{ ID::property_ExposedName, "Envelope 3 Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 59 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_3_x },
				{ ID::property_Center_y, env_3_ControlsRow_1_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvVelAmount(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_3_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, 275 },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	auto env3_Row_2_AllowedChoices_y{ 327 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_064", {
				{ ID::property_ParamID, ID::ep_064_Env_3_Delay.toString() },
				{ ID::property_ExposedName, "Envelope 3 Delay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 60 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_4_x },
				{ ID::property_Center_y, env_3_ControlsRow_2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvDelay(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_4_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_065", {
				{ ID::property_ParamID, ID::ep_065_Env_3_Attack.toString() },
				{ ID::property_ExposedName, "Envelope 3 Attack" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 61 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_5_x },
				{ ID::property_Center_y, env_3_ControlsRow_2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvAttack(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_5_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_066", {
				{ ID::property_ParamID, ID::ep_066_Env_3_Decay.toString() },
				{ ID::property_ExposedName, "Envelope 3 Decay" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 62 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_6_x },
				{ ID::property_Center_y, env_3_ControlsRow_2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvDecay(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_6_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_067", {
				{ ID::property_ParamID, ID::ep_067_Env_3_Sustain.toString() },
				{ ID::property_ExposedName, "Envelope 3 Sustain" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 63 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_7_x },
				{ ID::property_Center_y, env_3_ControlsRow_2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvSustain(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_7_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_068", {
				{ ID::property_ParamID, ID::ep_068_Env_3_Release.toString() },
				{ ID::property_ExposedName, "Envelope 3 Release" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 64 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 0 },
				{ ID::property_Center_x, controlsCol_8_x },
				{ ID::property_Center_y, env_3_ControlsRow_2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForEnvRelease(EnvelopeType::env_3) },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_8_x - GUI::knob_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, env3_Row_2_AllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
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
				{ ID::property_Center_y, 537 },
				{ ID::property_Width, 34 },
				{ ID::property_Height, 26 },
				{ ID::property_RedToggleCenter_x, controlsCol_1_x },
				{ ID::property_RedToggleCenter_y, env_3_ControlsRow_1_y },
				{ ID::property_Description, Description::buildForEnv_3_Repeat() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_1_x - GUI::toggleLockButton_diameter / 2 },
				{ ID::property_AllowedChoicesBackground_y, 398 },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(concise) },
				ValueTree{ ChoiceNames::buildForOffOn(verbose) }
			}
		}, -1, nullptr);

	//--------------------------------------------------------------------------------------------------------------- modulators

	const int modulatorComboBox_w{ 126 };
	const int modulatorControlsCol_1_x{ 486 };
	const int modulatorControlsCol_2_x{ 575 };
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
					{ ID::property_Center_x, modulatorControlsCol_1_x },
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
					ValueTree{ ChoiceNames::buildForModSource(concise) },
					ValueTree{ ChoiceNames::buildForModSource(verbose) }
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
					{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
					{ ID::property_NRPN, nrpn },
					{ ID::property_NumberOfChoices, 255 },
					{ ID::property_DefaultChoice, 127 },
					{ ID::property_Center_x, modulatorControlsCol_2_x },
					{ ID::property_Center_y, 201 + modNum * modulatorControlsGroup_h },
					{ ID::property_Width, GUI::knob_diameter },
					{ ID::property_Height, GUI::knob_diameter },
					{ ID::property_Description, Description::buildForModAmount() },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
					{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
					{ ID::property_AllowedChoicesBackground_x, modulatorControlsCol_2_x + allowedChoicesOffset_Knobs },
					{ ID::property_AllowedChoicesBackground_y, 109 },
				}, {
					ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
					ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
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
					{ ID::property_Center_x, modulatorControlsCol_1_x },
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
					ValueTree{ ChoiceNames::buildForModDestination(concise) },
					ValueTree{ ChoiceNames::buildForModDestination(verbose) }
				}
			}, -1, nullptr);
	}

	//---------------------------------------------------------------------------------------------------------- MIDI modulators

	const int midiControllerComboBox_w{ 136 };
	const int midiControllersCol_1_x{ 680 };
	const int midiControllersCol_2_x{ 776 };
	const int midiControllersGroup_h{ 62 };
	const int midiControllersRow_1_y{ 191 };
	const int midiControllersRow_2_y{ midiControllersRow_1_y + midiControllersGroup_h };
	const int midiControllersRow_3_y{ midiControllersRow_2_y + midiControllersGroup_h };
	const int midiControllersRow_4_y{ midiControllersRow_3_y + midiControllersGroup_h };
	const int midiControllersRow_5_y{ midiControllersRow_4_y + midiControllersGroup_h };

	auto midiModAmountsAllowedChoices_x{ 264 };
	auto midiModAmountsAllowedChoices_y{ 106 };
	auto midiModDestinationsAllowedChoices_x{ 758 };
	auto midiModDestinationsAllowedChoices_y{ 138 };
	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_082", {
				{ ID::property_ParamID, ID::ep_082_ModWheelAmount.toString() },
				{ ID::property_ExposedName, "Modulation Wheel Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 81 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol_2_x },
				{ ID::property_Center_y, midiControllersRow_1_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_ModWheelAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
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
				{ ID::property_Center_x, midiControllersCol_1_x },
				{ ID::property_Center_y, midiControllersRow_1_y },
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
				ValueTree{ ChoiceNames::buildForModDestination(concise) },
				ValueTree{ ChoiceNames::buildForModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_084", {
				{ ID::property_ParamID, ID::ep_084_PressureAmount.toString() },
				{ ID::property_ExposedName, "Pressure (Aftertouch) Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 83 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol_2_x },
				{ ID::property_Center_y, midiControllersRow_2_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_PressureAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
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
				{ ID::property_Center_x, midiControllersCol_1_x },
				{ ID::property_Center_y, midiControllersRow_2_y },
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
				ValueTree{ ChoiceNames::buildForModDestination(concise) },
				ValueTree{ ChoiceNames::buildForModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_086", {
				{ ID::property_ParamID, ID::ep_086_BreathAmount.toString() },
				{ ID::property_ExposedName, "Breath Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 85 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol_2_x },
				{ ID::property_Center_y, midiControllersRow_3_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_BreathAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
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
				{ ID::property_Center_x, midiControllersCol_1_x },
				{ ID::property_Center_y, midiControllersRow_3_y },
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
				ValueTree{ ChoiceNames::buildForModDestination(concise) },
				ValueTree{ ChoiceNames::buildForModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_088", {
				{ ID::property_ParamID, ID::ep_088_VelocityAmount.toString() },
				{ ID::property_ExposedName, "Note Velocity Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 87 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol_2_x },
				{ ID::property_Center_y, midiControllersRow_4_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_VelocityAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
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
				{ ID::property_Center_x, midiControllersCol_1_x },
				{ ID::property_Center_y, midiControllersRow_4_y },
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
				ValueTree{ ChoiceNames::buildForModDestination(concise) },
				ValueTree{ ChoiceNames::buildForModDestination(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_090", {
				{ ID::property_ParamID, ID::ep_090_PedalAmount.toString() },
				{ ID::property_ExposedName, "Foot Pedal Amount" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::posNeg_127 },
				{ ID::property_NRPN, 89 },
				{ ID::property_NumberOfChoices, 255 },
				{ ID::property_DefaultChoice, 127 },
				{ ID::property_Center_x, midiControllersCol_2_x },
				{ ID::property_Center_y, midiControllersRow_5_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildFor_MIDI_PedalAmount() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_PosNeg_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_PosNeg_127 },
				{ ID::property_FirstAllowChoiceToggleRow, firstAllowChoiceRow_PosNeg_127 },
				{ ID::property_AllowedChoicesBackground_x, midiModAmountsAllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, midiModAmountsAllowedChoices_y },
			}, {
				ValueTree{ ChoiceNames::buildForPosNeg_127(concise) },
				ValueTree{ ChoiceNames::buildForPosNeg_127(verbose) }
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
				{ ID::property_Center_x, midiControllersCol_1_x },
				{ ID::property_Center_y, midiControllersRow_5_y },
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
				ValueTree{ ChoiceNames::buildForModDestination(concise) },
				ValueTree{ ChoiceNames::buildForModDestination(verbose) }
			}
		}, -1, nullptr);

	//------------------------------------------------------------------------------------------------------------------ Push It

	const int pushiItKnobsRow_y{ 528 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_092", {
				{ ID::property_ParamID, ID::ep_092_PushItPitch.toString() },
				{ ID::property_ExposedName, "Push It! Switch Pitch" },
				{ ID::property_ControlType, (int)ControlType::knobForPitch },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::oscPitch },
				{ ID::property_NRPN, 111 },
				{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
				{ ID::property_DefaultChoice, 60 },
				{ ID::property_Center_x, 1191 },
				{ ID::property_Center_y, pushiItKnobsRow_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForPushItPitch() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_OscPitch },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_OscPitch },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_Pitch },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 759 },
				{ ID::property_AllowedChoicesBackground_y, 207 },
			}, {
				ValueTree{ ChoiceNames::buildForOscPitch(concise) },
				ValueTree{ ChoiceNames::buildForOscPitch(verbose) }
			}
		}, -1, nullptr);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_093", {
				{ ID::property_ParamID, ID::ep_093_PushItVelocity.toString() },
				{ ID::property_ExposedName, "Push It! Switch Velocity" },
				{ ID::property_ControlType, (int)ControlType::knob },
				{ ID::property_KnobValueRangeType, (int)KnobValueRangeType::pos_127 },
				{ ID::property_NRPN, 112 },
				{ ID::property_NumberOfChoices, 128 },
				{ ID::property_DefaultChoice, 100 },
				{ ID::property_Center_x, 1239 },
				{ ID::property_Center_y, pushiItKnobsRow_y },
				{ ID::property_Width, GUI::knob_diameter },
				{ ID::property_Height, GUI::knob_diameter },
				{ ID::property_Description, Description::buildForPushItVelocity() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_0_To_127 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_0_To_127 },
				{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_0_To_127 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 807 },
				{ ID::property_AllowedChoicesBackground_y, 271 },
			}, {
				ValueTree{ ChoiceNames::buildForPlainValue(128, concise) },
				ValueTree{ ChoiceNames::buildForPlainValue(128, verbose) }
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
				{ ID::property_Description, Description::buildForPushItMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 72 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 3 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 1153 },
				{ ID::property_AllowedChoicesBackground_y, 359 },
			}, {
				ValueTree{ ChoiceNames::buildForPushItMode(concise) },
				ValueTree{ ChoiceNames::buildForPushItMode(verbose) }
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
				{ ID::property_Description, Description::buildForClockTempo() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 12 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 26 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 20 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 860 },
				{ ID::property_AllowedChoicesBackground_y, 106 },
			}, {
				ValueTree{ ChoiceNames::buildForClockTempo(concise) },
				ValueTree{ ChoiceNames::buildForClockTempo(verbose) }
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
				{ ID::property_Description, Description::buildForClockDivision() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 2 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 118 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 7 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 797 },
				{ ID::property_AllowedChoicesBackground_y, 118 },
			}, {
				ValueTree{ ChoiceNames::buildForClockDivision(concise) },
				ValueTree{ ChoiceNames::buildForClockDivision(verbose) }
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
				{ ID::property_Description, Description::buildForArpegMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 3 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 120 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 5 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, col_10_AllowedChoices_x },
				{ ID::property_AllowedChoicesBackground_y, 110 },
			}, {
				ValueTree{ ChoiceNames::buildForArpegMode(concise) },
				ValueTree{ ChoiceNames::buildForArpegMode(verbose) }
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
				{ ID::property_Center_y, 116 },
				{ ID::property_Width, 20 },
				{ ID::property_Height, 26 },
				{ ID::property_RedToggleCenter_x, controlsCol_9_x },
				{ ID::property_RedToggleCenter_y, oscRow_2_center_y },
				{ ID::property_Description, Description::buildForArpegOnOff() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, controlsCol_9_x + allowedChoicesOffset_Toggles },
				{ ID::property_AllowedChoicesBackground_y, oscRow_2_center_y - GUI::toggleLockButton_diameter / 2 },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(concise) },
				ValueTree{ ChoiceNames::buildForOffOn(verbose) }
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
				{ ID::property_Description, Description::buildForSeqTrigMode() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 1 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 104 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 6 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 1065 },
				{ ID::property_AllowedChoicesBackground_y, 118 },
			}, {
				ValueTree{ ChoiceNames::buildForSeqTrigMode(concise) },
				ValueTree{ ChoiceNames::buildForSeqTrigMode(verbose) }
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
				{ ID::property_Center_x, 863 },
				{ ID::property_Center_y, clockAndSequencerControlsRow_y },
				{ ID::property_Width, 102 },
				{ ID::property_Height, GUI::redToggle_diameter },
				{ ID::property_RedToggleCenter_x, 819 },
				{ ID::property_RedToggleCenter_y, clockAndSequencerControlsRow_y },
				{ ID::property_Description, Description::buildForSeqOnOff() },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::binary },
				{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
				{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
				{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
				{ ID::property_FirstAllowChoiceToggleRow, 0 },
				{ ID::property_AllowedChoicesBackground_x, 819 - GUI::redToggle_diameter / 2},
				{ ID::property_AllowedChoicesBackground_y, clockAndSequencerControlsRow_y + allowedChoicesOffset_Toggles  },
			}, {
				ValueTree{ ChoiceNames::buildForOffOn(concise) },
				ValueTree{ ChoiceNames::buildForOffOn(verbose) }
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
					{ ID::property_Description, Description::buildForSeqTrackDestination(trackNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, numberOfAllowChoiceColumns_ModDestination },
					{ ID::property_WidthOfAllowChoiceToggleColumn, widthOfAllowChoiceColumns_ModSourceAndDestination },
					{ ID::property_NumberOfAllowChoiceToggleRows, numberOfAllowChoiceRows_ModDestination },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 498 },
					{ ID::property_AllowedChoicesBackground_y, 138 },
				}, {
					ValueTree{ trackNumIsEven ?
						ChoiceNames::buildForSeqTracks_2_4_Destination(trackNum, concise) :
						ChoiceNames::buildForModDestination(concise) },
					ValueTree{ trackNumIsEven ?
						ChoiceNames::buildForSeqTracks_2_4_Destination(trackNum, verbose) :
						ChoiceNames::buildForModDestination(verbose) }
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
					{ ID::property_Description, Description::buildForKnobAssign(knobNum) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::standard },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 9 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 134 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 20 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 17 },
					{ ID::property_AllowedChoicesBackground_y, 85 + (knobNum - 1) * knobAssignComboBoxesVertSpacing },
				}, {
					ValueTree{ ChoiceNames::buildForKnobAssign(concise) },
					ValueTree{ ChoiceNames::buildForKnobAssign(verbose) }
				}
			}, -1, nullptr);
	}

	//---------------------------------------------------------------------------------------------------------- sequencer steps

	const int gapBetweenSeqStepsAndVoiceNameChars{ 2 };

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
						{ ID::property_Center_x, 825 + stepNum * (GUI::seqSteps_w + gapBetweenSeqStepsAndVoiceNameChars) },
						{ ID::property_Center_y, 196 + trackNum * GUI::seqTrackControlsGroup_h },
						{ ID::property_Width, GUI::seqSteps_w },
						{ ID::property_Height, GUI::seqSteps_h },
						{ ID::property_Description, Description::buildForSeqTrackStep(trackNum + 1, stepNum + 1) },
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
						ValueTree{ ChoiceNames::buildForSeqTrackStep(concise) },
						ValueTree{ ChoiceNames::buildForSeqTrackStep(verbose) }
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
					{ ID::property_Center_x, 596 + charNum * (GUI::voiceNameChars_w + gapBetweenSeqStepsAndVoiceNameChars) },
					{ ID::property_Center_y, voiceNameCharacters_y },
					{ ID::property_Width, GUI::voiceNameChars_w },
					{ ID::property_Height, GUI::voiceNameChars_h },
					{ ID::property_Description, Description::buildForVoiceNameChar(charNum + 1) },
					{ ID::property_AllowedChoicesType, (int)AllowedChoicesType::voiceNameChar },
					{ ID::property_NumberOfAllowChoiceToggleColumns, 0 },
					{ ID::property_WidthOfAllowChoiceToggleColumn, 0 },
					{ ID::property_NumberOfAllowChoiceToggleRows, 0 },
					{ ID::property_FirstAllowChoiceToggleRow, 0 },
					{ ID::property_AllowedChoicesBackground_x, 590 + charNum * (GUI::voiceNameChars_w + gapBetweenSeqStepsAndVoiceNameChars) },
					{ ID::property_AllowedChoicesBackground_y, 71 },
				}, {
					ValueTree{ ChoiceNames::buildForVoiceNameChar(concise) },
					ValueTree{ ChoiceNames::buildForVoiceNameChar(verbose) }
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

Identifier InfoForExposedParameters::IDfor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return Identifier{ paramTree.getProperty(ID::property_ParamID).toString() };
}

Identifier InfoForExposedParameters::IDfor(Track track, Step step) const {
	jassert(step != Step::all);
	auto trackString{ String((int)track) };
	auto stepString{ String((int)step) };
	auto paramNumString{ "ep_" + String(EP::firstSeqStepParamIndex + ((int)track - 1) * 16 + ((int)step - 1)) };
	auto paramID_String{ paramNumString + "_SeqTrack_" + trackString + "_Step_" + stepString };
	return Identifier{ paramID_String };
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

KnobValueRangeType InfoForExposedParameters::knobValueRangeTypeFor(const uint8 paramIndex) const {
	auto controlType{ controlTypeFor(paramIndex) };
	jassert(controlType == ControlType::knob || controlType == ControlType::knobForOscShape || controlType == ControlType::knobForPitch);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return KnobValueRangeType{ (int)paramTree.getProperty(ID::property_KnobValueRangeType) };
}

uint8 InfoForExposedParameters::NRPNfor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (uint8)(int)paramTree.getProperty(ID::property_NRPN);
}

const uint8 InfoForExposedParameters::paramIndexForNRPN(const uint8 NRPN) const {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		if (NRPNfor(paramIndex) == NRPN)
			return paramIndex;
	}
	return (uint8)255;
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
	auto center_x{ (int)paramTree.getProperty(ID::property_Center_x) };
	auto center_y{ (int)paramTree.getProperty(ID::property_Center_y) };
	return Point<int>{ center_x, center_y };
}

Point<int> InfoForExposedParameters::redToggleCenterPointFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	auto center_x{ (int)paramTree.getProperty(ID::property_RedToggleCenter_x) };
	auto center_y{ (int)paramTree.getProperty(ID::property_RedToggleCenter_y) };
	return Point<int>{ center_x, center_y };
}

int InfoForExposedParameters::widthFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_Width);
}

int InfoForExposedParameters::heightFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (int)paramTree.getProperty(ID::property_Height);
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

uint16 InfoForExposedParameters::msBitPackedByteLocationFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint16((int)paramTree.getProperty(ID::property_MSBitPackedByteLocation));
}

uint8 InfoForExposedParameters::msBitMaskFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return (uint8)(int)paramTree.getProperty(ID::property_MSBitMask);
}

uint16 InfoForExposedParameters::lsByteLocationFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return uint16((int)paramTree.getProperty(ID::property_LSByteLocation));
}

AllowedChoicesType InfoForExposedParameters::allowedChoicesTypeFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	return AllowedChoicesType{ (int)paramTree.getProperty(ID::property_AllowedChoicesType) };
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

Track InfoForExposedParameters::seqTrackFor(const uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	auto trackNum{ (int)paramTree.getProperty(ID::property_SeqTrackNum) };
	return Track{ trackNum };
}

Step InfoForExposedParameters::seqTrackStepFor(const uint8 paramIndex) const
{
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChild(paramIndex) };
	auto stepNum{ (int)paramTree.getProperty(ID::property_SeqTrackStepNum) };
	return Step{ stepNum };
}

