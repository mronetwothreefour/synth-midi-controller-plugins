#include "ep_singleton_InfoForExposedParameters.h"

#include "ep_build_ChoiceNamesValueTree.h"
#include "ep_build_DescriptionString.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::exposedParamsInfo }
{
	fillExposedParamsInfoTree();
}

void InfoForExposedParameters::fillExposedParamsInfoTree() {
	const int horizGapBtwnControls{ 5 };
	const int controlsCol1_x{ 48 };
	const int controlsCol2_x{ controlsCol1_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol3_x{ controlsCol2_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol4_x{ controlsCol3_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol5_x{ controlsCol4_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol6_x{ controlsCol5_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol7_x{ controlsCol6_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol8_x{ controlsCol7_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol9_x{ controlsCol8_x + GUI::knob_diameter + horizGapBtwnControls };
	const int controlsCol10_x{ 500 };

	auto concise{ (bool)false };
	auto verbose{ (bool)true };

	// ------------------------------------------------------------------------------------------------------------- oscillators

	const int oscControlsRow1_y{ 50 };
	const int oscControlsRow2_y{ 110 };

	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_000" : "ep_006", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_000_Osc_1_Pitch : ID::ep_006_Osc_2_Pitch), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pitch" },
							{ ID::property_ControlType, (int)ControlType::knobForPitch },
							{ ID::property_NRPN, oscNum == 1 ? 0 : 5 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
							{ ID::property_DefaultChoice, 24 },
							{ ID::property_Center_x, controlsCol1_x },
							{ ID::property_Center_y, oscNum == 1 ? oscControlsRow1_y : oscControlsRow2_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_OscPitch(oscNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_001" : "ep_007", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_001_Osc_1_FineTune : ID::ep_007_Osc_2_FineTune), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Fine Tune" },
							{ ID::property_ControlType, (int)ControlType::knob },
							{ ID::property_NRPN, oscNum == 1 ? 1 : 6 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscFineTune },
							{ ID::property_DefaultChoice, oscNum == 1 ? 49 : 51 },
							{ ID::property_Center_x, controlsCol2_x },
							{ ID::property_Center_y, oscNum == 1 ? oscControlsRow1_y : oscControlsRow2_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_OscFine(oscNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscFineTune(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscFineTune(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_002" : "ep_008", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_002_Osc_1_Shape : ID::ep_008_Osc_2_Shape), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Wave Shape" },
							{ ID::property_ControlType, (int)ControlType::knobForOscShape },
							{ ID::property_NRPN, oscNum == 1 ? 2 : 7 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscWaveShape },
							{ ID::property_DefaultChoice, 1 },
							{ ID::property_Center_x, controlsCol3_x },
							{ ID::property_Center_y, oscNum == 1 ? oscControlsRow1_y : oscControlsRow2_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_OscShape(oscNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscShape(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscShape(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_003" : "ep_009", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_003_Osc_1_Glide : ID::ep_009_Osc_2_Glide), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Glide Rate" },
							{ ID::property_ControlType, (int)ControlType::knob },
							{ ID::property_NRPN, oscNum == 1 ? 3 : 8 },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
							{ ID::property_Center_x, controlsCol4_x },
							{ ID::property_Center_y, oscNum == 1 ? oscControlsRow1_y : oscControlsRow2_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_OscGlide(oscNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)128, concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)128, verbose) }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_004" : "ep_010", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_004_Osc_1_KeyTrack : ID::ep_010_Osc_2_KeyTrack), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Keyboard Track On/Off" },
							{ ID::property_ControlType, (int)ControlType::toggleButton },
							{ ID::property_NRPN, oscNum == 1 ? 4 : 9 },
							{ ID::property_NumberOfChoices, 2 },
							{ ID::property_DefaultChoice, 1 },
							{ ID::property_Center_x, controlsCol6_x },
							{ ID::property_Center_y, oscNum == 1 ? oscControlsRow1_y : oscControlsRow2_y },
							{ ID::property_Width, GUI::toggle_diameter },
							{ ID::property_Height, GUI::toggle_diameter },
							{ ID::property_Description, DescriptionString::buildFor_OscKeyTrack(oscNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_005" : "ep_011", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_005_Osc_1_SubLevel : ID::ep_011_Osc_2_SubLevel), {
							{ ID::property_ExposedName, "Sub-Oscillator " + (String)oscNum + " Level"  },
							{ ID::property_ControlType, (int)ControlType::knob },
							{ ID::property_NRPN, oscNum == 1 ? 114 : 115 },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
							{ ID::property_Center_x, controlsCol5_x },
							{ ID::property_Center_y, oscNum == 1 ? oscControlsRow1_y : oscControlsRow2_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_OscSubLevel(oscNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)128, concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)128, verbose) }
						} } }
			},
			-1,
			nullptr
		);
	}

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_012", {}, {
			ValueTree{ ID::ep_012_OscSync, {
						{ ID::property_ExposedName, "Hard Oscillator Sync On/Off" },
						{ ID::property_ControlType, (int)ControlType::toggleButton },
						{ ID::property_NRPN, 10 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol6_x },
						{ ID::property_Center_y, 22 },
						{ ID::property_Width, GUI::toggle_diameter },
						{ ID::property_Height, GUI::toggle_diameter },
						{ ID::property_Description, DescriptionString::buildFor_OscSync() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_013", {}, {
			ValueTree{ ID::ep_013_GlideMode, {
						{ ID::property_ExposedName, "Glide Mode" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 11 },
						{ ID::property_NumberOfChoices, 4 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol10_x },
						{ ID::property_Center_y, 78 },
						{ ID::property_Width, 124 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, DescriptionString::buildFor_GlideMode() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_GlideMode(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_GlideMode(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_014", {}, {
			ValueTree{ ID::ep_014_OscSlop, {
						{ ID::property_ExposedName, "Oscillator Slop" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 12 },
						{ ID::property_NumberOfChoices, 6 },
						{ ID::property_DefaultChoice, 2 },
						{ ID::property_Center_x, controlsCol7_x },
						{ ID::property_Center_y, oscControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_OscSlop() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)6, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)6, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_015", {}, {
			ValueTree{ ID::ep_015_BendRange, {
						{ ID::property_ExposedName, "Pitch Bend Range" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 93 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForBendRange },
						{ ID::property_DefaultChoice, 4 },
						{ ID::property_Center_x, controlsCol9_x },
						{ ID::property_Center_y, oscControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_BendRange() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_BendRange(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_BendRange(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_016", {}, {
			ValueTree{ ID::ep_016_NotePriority, {
						{ ID::property_ExposedName, "Note Priority(Key Assign)" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 96 },
						{ ID::property_NumberOfChoices, 6 },
						{ ID::property_DefaultChoice, 4 },
						{ ID::property_Center_x, controlsCol10_x },
						{ ID::property_Center_y, 38 },
						{ ID::property_Width, 124 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, DescriptionString::buildFor_NotePriority() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_NotePriority(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_NotePriority(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_017", {}, {
			ValueTree{ ID::ep_017_OscMix, {
						{ ID::property_ExposedName, "Oscillator 1 & 2 Mix" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 13 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 64 },
						{ ID::property_Center_x, controlsCol8_x },
						{ ID::property_Center_y, oscControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_OscMix() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_018", {}, {
			ValueTree{ ID::ep_018_NoiseLevel, {
						{ ID::property_ExposedName, "Noise Level" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 14 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol7_x },
						{ ID::property_Center_y, oscControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_NoiseLevel() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_019", {}, {
			ValueTree{ ID::ep_019_ExtInLevel, {
						{ ID::property_ExposedName, "External Audio Input Level" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 116 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol8_x },
						{ ID::property_Center_y, oscControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_ExtInLevel() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//---------------------------------------------------------------------------------------------------------------------- LPF

	const int lpfControlsRow1_y{ 161 };
	const int lpfControlsRow2_y{ 215 };
	const int lpfControlsRow3_y{ 267 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_020", {}, {
			ValueTree{ ID::ep_020_LPF_Freq, {
						{ ID::property_ExposedName, "LPF Cutoff Frequency" },
						{ ID::property_ControlType, (int)ControlType::knobForPitch },
						{ ID::property_NRPN, 15 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForLPF_Freq },
						{ ID::property_DefaultChoice, 148 },
						{ ID::property_Center_x, controlsCol1_x },
						{ ID::property_Center_y, lpfControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_LPF_Freq() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_LPF_Freq(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_LPF_Freq(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_021", {}, {
			ValueTree{ ID::ep_021_LPF_Reso, {
						{ ID::property_ExposedName, "LPF Resonance" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 15 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, lpfControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_LPF_Reso() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_022", {}, {
			ValueTree{ ID::ep_022_LPF_KeyAmount, {
						{ ID::property_ExposedName, "LPF Keyboard Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 17 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol3_x },
						{ ID::property_Center_y, lpfControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_LPF_KeyAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_023", {}, {
			ValueTree{ ID::ep_023_LPF_FM_Amount, {
						{ ID::property_ExposedName, "LPF FM (By Oscillator 1)" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 18 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol3_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_LPF_FM_Amount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_024", {}, {
			ValueTree{ ID::ep_024_LPF_Type, {
						{ ID::property_ExposedName, "LPF Type" },
						{ ID::property_ControlType, (int)ControlType::toggleButton },
						{ ID::property_NRPN, 19 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 1 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, lpfControlsRow1_y },
						{ ID::property_Width, GUI::toggle_diameter },
						{ ID::property_Height, GUI::toggle_diameter },
						{ ID::property_Description, DescriptionString::buildFor_LPF_Type() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_LPF_Type(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_LPF_Type(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_025", {}, {
			ValueTree{ ID::ep_025_LPF_EnvAmount, {
						{ ID::property_ExposedName, "LPF Envelope Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 20 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, controlsCol1_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_LPF_EnvAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_026", {}, {
			ValueTree{ ID::ep_026_LPF_VelAmount, {
						{ ID::property_ExposedName, "LPF Envelope Velocity Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 21 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvVelAmount(EnvelopeType::lpf) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_027", {}, {
			ValueTree{ ID::ep_027_LPF_Delay, {
						{ ID::property_ExposedName, "LPF Envelope Delay" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 22 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol4_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvDelay(EnvelopeType::lpf) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_028", {}, {
			ValueTree{ ID::ep_028_LPF_Attack, {
						{ ID::property_ExposedName, "LPF Envelope Attack" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 23 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol5_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvAttack(EnvelopeType::lpf) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_029", {}, {
			ValueTree{ ID::ep_029_LPF_Decay, {
						{ ID::property_ExposedName, "LPF Envelope Decay" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 24 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol6_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvDecay(EnvelopeType::lpf) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_030", {}, {
			ValueTree{ ID::ep_030_LPF_Sustain, {
						{ ID::property_ExposedName, "LPF Envelope Sustain" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 25 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol7_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvSustain(EnvelopeType::lpf) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_031", {}, {
			ValueTree{ ID::ep_031_LPF_Release, {
						{ ID::property_ExposedName, "LPF Envelope Release" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 26 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol8_x },
						{ ID::property_Center_y, lpfControlsRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvRelease(EnvelopeType::lpf) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//---------------------------------------------------------------------------------------------------------------------- VCA

	const int vcaControlsRow1_y{ 373 };
	const int vcaControlsRow2_y{ 425 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_032", {}, {
			ValueTree{ ID::ep_032_VCA_Level, {
						{ ID::property_ExposedName, "VCA Baseline Level" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 27 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol1_x },
						{ ID::property_Center_y, vcaControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_VCA_Level() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_033", {}, {
			ValueTree{ ID::ep_033_VCA_EnvAmount, {
						{ ID::property_ExposedName, "VCA Envelope Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 30 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, vcaControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_VCA_EnvAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_034", {}, {
			ValueTree{ ID::ep_034_VCA_VelAmount, {
						{ ID::property_ExposedName, "VCA Envelope Velocity Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 31 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol3_x },
						{ ID::property_Center_y, vcaControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvVelAmount(EnvelopeType::vca) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_035", {}, {
			ValueTree{ ID::ep_035_VCA_Delay, {
						{ ID::property_ExposedName, "VCA Envelope Delay" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 32 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol4_x },
						{ ID::property_Center_y, vcaControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvDelay(EnvelopeType::vca) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_036", {}, {
			ValueTree{ ID::ep_036_VCA_Attack, {
						{ ID::property_ExposedName, "VCA Envelope Attack" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 33 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol5_x },
						{ ID::property_Center_y, vcaControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvAttack(EnvelopeType::vca) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_037", {}, {
			ValueTree{ ID::ep_037_VCA_Decay, {
						{ ID::property_ExposedName, "VCA Envelope Decay" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 34 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol6_x },
						{ ID::property_Center_y, vcaControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvDecay(EnvelopeType::vca) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_038", {}, {
			ValueTree{ ID::ep_038_VCA_Sustain, {
						{ ID::property_ExposedName, "VCA Envelope Sustain" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 35 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 64 },
						{ ID::property_Center_x, controlsCol7_x },
						{ ID::property_Center_y, vcaControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvSustain(EnvelopeType::vca) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_039", {}, {
			ValueTree{ ID::ep_039_VCA_Release, {
						{ ID::property_ExposedName, "VCA Envelope Release" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 36 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 64 },
						{ ID::property_Center_x, controlsCol8_x },
						{ ID::property_Center_y, vcaControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvRelease(EnvelopeType::vca) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_040", {}, {
			ValueTree{ ID::ep_040_VoiceVolume, {
						{ ID::property_ExposedName, "Program Volume" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 29 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 120 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, vcaControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_VoiceVolume() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//--------------------------------------------------------------------------------------------------------------------- LFOs

	const int lfoControlsRow1_y{ 515 };
	const int lfoControlsRow2_y{ 560 };
	const int lfoControlsRow3_y{ 594 };
	const int lfoControlsGroup_w{ 155 };
	auto modDestinationParamDescription{ "Selects the target parameter for modulation" };

	for (uint8 lfoNum = 0; lfoNum != 4; ++lfoNum) {
		auto paramNumString{ "ep_0" + (String)(41 + lfoNum * 5) };
		auto paramNameString{ paramNumString + "_LFO_" + String(lfoNum + 1) + "_Freq" };
		auto exposedNameString{ "LFO " + String(lfoNum + 1) + " Frequency" };
		auto nrpn{ 37 + lfoNum * 5 };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::knob },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 167 },
							{ ID::property_DefaultChoice, 80 },
							{ ID::property_Center_x, 416 + lfoNum * lfoControlsGroup_w },
							{ ID::property_Center_y, lfoControlsRow1_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_LFO_Freq(lfoNum + 1) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_LFO_Freq(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_LFO_Freq(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		paramNumString = "ep_0" + (String)(42 + lfoNum * 5);
		paramNameString = paramNumString + "_LFO_" + String(lfoNum + 1) + "_Shape";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Wave Shape";
		nrpn = 38 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::comboBox },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 5 },
							{ ID::property_DefaultChoice, 1 },
							{ ID::property_Center_x, 463 + lfoNum * lfoControlsGroup_w },
							{ ID::property_Center_y, lfoControlsRow2_y },
							{ ID::property_Width, 134 },
							{ ID::property_Height, GUI::comboBox_h },
							{ ID::property_Description, DescriptionString::buildFor_LFO_Shape(lfoNum + 1) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_LFO_Shape(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_LFO_Shape(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		paramNumString = "ep_0" + (String)(43 + lfoNum * 5);
		paramNameString = paramNumString + "_LFO_" + String(lfoNum + 1) + "_Amount";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Amount";
		nrpn = 39 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::knob },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
							{ ID::property_Center_x, 461 + lfoNum * lfoControlsGroup_w },
							{ ID::property_Center_y, lfoControlsRow1_y },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_LFO_Amount(lfoNum + 1) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
						} } }
			},
			-1,
			nullptr
		);

		paramNumString = "ep_0" + (String)(44 + lfoNum * 5);
		paramNameString = paramNumString + "_LFO_" + String(lfoNum + 1) + "_Destination";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Modulation Destination";
		nrpn = 40 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::comboBox },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
							{ ID::property_DefaultChoice, 0 },
							{ ID::property_Center_x, 463 + lfoNum * lfoControlsGroup_w },
							{ ID::property_Center_y, lfoControlsRow3_y },
							{ ID::property_Width, 134 },
							{ ID::property_Height, GUI::comboBox_h },
							{ ID::property_Description, modDestinationParamDescription + String(" by LFO ") + String(lfoNum + 1) + "." },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		paramNumString = "ep_0" + (String)(45 + lfoNum * 5);
		paramNameString = paramNumString + "_LFO_" + String(lfoNum + 1) + "_KeySync";
		exposedNameString = "LFO " + String(lfoNum + 1) + " Key Sync On/Off";
		nrpn = 41 + lfoNum * 5;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::toggleButton },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 2 },
							{ ID::property_DefaultChoice, 0 },
							{ ID::property_Center_x, 507 + lfoNum * lfoControlsGroup_w },
							{ ID::property_Center_y, lfoControlsRow1_y },
							{ ID::property_Width, GUI::toggle_diameter },
							{ ID::property_Height, GUI::toggle_diameter },
							{ ID::property_Description, DescriptionString::buildFor_LFO_KeySync(lfoNum + 1) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
						} } }
			},
			-1,
			nullptr
		);
	}

	//--------------------------------------------------------------------------------------------------------------- Envelope 3

	const int env3ControlsRow1_y{ 531 };
	const int env3ControlsRow2_y{ 583 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_061", {}, {
			ValueTree{ ID::ep_061_Env_3_Destination, {
						{ ID::property_ExposedName, "Envelope 3 Modulation Destination" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 57 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, env3ControlsRow2_y },
						{ ID::property_Width, 126 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, modDestinationParamDescription + String(" by envelope 3.") },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_062", {}, {
			ValueTree{ ID::ep_062_Env_3_Amount, {
						{ ID::property_ExposedName, "Envelope 3 Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 58 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, controlsCol2_x },
						{ ID::property_Center_y, env3ControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_Env_3_Amount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_063", {}, {
			ValueTree{ ID::ep_063_Env_3_VelAmount, {
						{ ID::property_ExposedName, "Envelope 3 Velocity Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 59 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol3_x },
						{ ID::property_Center_y, env3ControlsRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvVelAmount(EnvelopeType::env_3) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_064", {}, {
			ValueTree{ ID::ep_064_Env_3_Delay, {
						{ ID::property_ExposedName, "Envelope 3 Delay" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 60 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol4_x },
						{ ID::property_Center_y, env3ControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvDelay(EnvelopeType::env_3) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_065", {}, {
			ValueTree{ ID::ep_065_Env_3_Attack, {
						{ ID::property_ExposedName, "Envelope 3 Attack" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 61 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol5_x },
						{ ID::property_Center_y, env3ControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvAttack(EnvelopeType::env_3) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_066", {}, {
			ValueTree{ ID::ep_066_Env_3_Decay, {
						{ ID::property_ExposedName, "Envelope 3 Decay" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 62 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol6_x },
						{ ID::property_Center_y, env3ControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvDecay(EnvelopeType::env_3) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_067", {}, {
			ValueTree{ ID::ep_067_Env_3_Sustain, {
						{ ID::property_ExposedName, "Envelope 3 Sustain" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 63 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol7_x },
						{ ID::property_Center_y, env3ControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvSustain(EnvelopeType::env_3) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_068", {}, {
			ValueTree{ ID::ep_068_Env_3_Release, {
						{ ID::property_ExposedName, "Envelope 3 Release" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 64 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol8_x },
						{ ID::property_Center_y, env3ControlsRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_EnvRelease(EnvelopeType::env_3) },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_069", {}, {
			ValueTree{ ID::ep_069_Env_3_Repeat, {
						{ ID::property_ExposedName, "Envelope 3 Repeat" },
						{ ID::property_ControlType, (int)ControlType::toggleButton },
						{ ID::property_NRPN, 98 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol1_x },
						{ ID::property_Center_y, env3ControlsRow1_y },
						{ ID::property_Width, GUI::toggle_diameter },
						{ ID::property_Height, GUI::toggle_diameter },
						{ ID::property_Description, DescriptionString::buildFor_Env_3_Repeat() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//--------------------------------------------------------------------------------------------------------------- modulators

	const int modulatorComboBox_w{ 126 };
	const int modulatorControlsCol1_x{ 486 };
	const int modulatorControlsCol2_x{ 575 };
	const int modulatorControlsGroup_h{ 78 };

	for (uint8 modNum = 0; modNum != 4; ++modNum) {
		auto paramNumString{ "ep_0" + (String)(70 + modNum * 3) };
		auto paramNameString{ paramNumString + "_Mod_" + String(modNum + 1) + "_Source" };
		auto exposedNameString{ "Modulator " + String(modNum + 1) + " Source" };
		auto nrpn{ 65 + modNum * 3 };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
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
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_ModSource(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_ModSource(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		paramNumString = "ep_0" + (String)(71 + modNum * 3);
		paramNameString = paramNumString + "_Mod_" + String(modNum + 1) + "_Amount";
		exposedNameString = "Modulator " + String(modNum + 1) + " Amount";
		nrpn = 66 + modNum * 3;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::knob },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 255 },
							{ ID::property_DefaultChoice, 127 },
							{ ID::property_Center_x, modulatorControlsCol2_x },
							{ ID::property_Center_y, 201 + modNum * modulatorControlsGroup_h },
							{ ID::property_Width, GUI::knob_diameter },
							{ ID::property_Height, GUI::knob_diameter },
							{ ID::property_Description, DescriptionString::buildFor_ModAmount() },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
						} } }
			},
			-1,
			nullptr
		);

		paramNumString = "ep_0" + (String)(72 + modNum * 3);
		paramNameString = paramNumString + "_Mod_" + String(modNum + 1) + "_Destination";
		exposedNameString = "Modulator " + String(modNum + 1) + " Destination";
		nrpn = 67 + modNum * 3;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
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
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
						} } }
			},
			-1,
			nullptr
		);
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

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_082", {}, {
			ValueTree{ ID::ep_082_ModWheelAmount, {
						{ ID::property_ExposedName, "Modulation Wheel Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 81 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, midiControllersCol2_x },
						{ ID::property_Center_y, midiControllersRow1_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_MIDI_ModWheelAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_083", {}, {
			ValueTree{ ID::ep_083_ModWheelDest, {
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
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_084", {}, {
			ValueTree{ ID::ep_084_PressureAmount, {
						{ ID::property_ExposedName, "Pressure (Aftertouch) Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 83 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, midiControllersCol2_x },
						{ ID::property_Center_y, midiControllersRow2_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_MIDI_PressureAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_085", {}, {
			ValueTree{ ID::ep_085_PressureDest, {
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
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_086", {}, {
			ValueTree{ ID::ep_086_BreathAmount, {
						{ ID::property_ExposedName, "Breath Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 85 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, midiControllersCol2_x },
						{ ID::property_Center_y, midiControllersRow3_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_MIDI_BreathAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_087", {}, {
			ValueTree{ ID::ep_087_BreathDest, {
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
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_088", {}, {
			ValueTree{ ID::ep_088_VelocityAmount, {
						{ ID::property_ExposedName, "Note Velocity Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 87 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, midiControllersCol2_x },
						{ ID::property_Center_y, midiControllersRow4_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_MIDI_VelocityAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_089", {}, {
			ValueTree{ ID::ep_089_VelocityDest, {
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
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_090", {}, {
			ValueTree{ ID::ep_090_PedalAmount, {
						{ ID::property_ExposedName, "Foot Pedal Amount" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 89 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
						{ ID::property_Center_x, midiControllersCol2_x },
						{ ID::property_Center_y, midiControllersRow5_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_MIDI_PedalAmount() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlusMinus127(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_091", {}, {
			ValueTree{ ID::ep_091_PedalDest, {
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
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//------------------------------------------------------------------------------------------------------------------ Push It

	const int pushiItKnobsRow_y{ 528 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_092", {}, {
			ValueTree{ ID::ep_092_PushItPitch, {
						{ ID::property_ExposedName, "Push It! Switch Pitch" },
						{ ID::property_ControlType, (int)ControlType::knobForPitch },
						{ ID::property_NRPN, 111 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
						{ ID::property_DefaultChoice, 60 },
						{ ID::property_Center_x, 1191 },
						{ ID::property_Center_y, pushiItKnobsRow_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_PushItPitch() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_093", {}, {
			ValueTree{ ID::ep_093_PushItVelocity, {
						{ ID::property_ExposedName, "Push It! Switch Velocity" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 112 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 100 },
						{ ID::property_Center_x, 1239 },
						{ ID::property_Center_y, pushiItKnobsRow_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_PushItVelocity() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_094", {}, {
			ValueTree{ ID::ep_094_PushItMode, {
						{ ID::property_ExposedName, "Push It! Switch Mode" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 113 },
						{ ID::property_NumberOfChoices, 3 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, 1215 },
						{ ID::property_Center_y, 577 },
						{ ID::property_Width, 88 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, DescriptionString::buildFor_PushItMode() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PushItMode(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PushItMode(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//------------------------------------------------------------------------------------------------------ clock & arpeggiator

	const int clockAndSequencerControlsRow_y{ 126 };

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_095", {}, {
			ValueTree{ ID::ep_095_ClockTempo, {
						{ ID::property_ExposedName, "Clock Tempo" },
						{ ID::property_ControlType, (int)ControlType::knob },
						{ ID::property_NRPN, 91 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForClockTempo },
						{ ID::property_DefaultChoice, 90 },
						{ ID::property_Center_x, 1236 },
						{ ID::property_Center_y, clockAndSequencerControlsRow_y },
						{ ID::property_Width, GUI::knob_diameter },
						{ ID::property_Height, GUI::knob_diameter },
						{ ID::property_Description, DescriptionString::buildFor_ClockTempo() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ClockTempo(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ClockTempo(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_096", {}, {
			ValueTree{ ID::ep_096_ClockDivision, {
						{ ID::property_ExposedName, "Clock Division" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 92 },
						{ ID::property_NumberOfChoices, 13 },
						{ ID::property_DefaultChoice, 2 },
						{ ID::property_Center_x, 1139 },
						{ ID::property_Center_y, clockAndSequencerControlsRow_y },
						{ ID::property_Width, 126 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, DescriptionString::buildFor_ClockDivision() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ClockDivision(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ClockDivision(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_097", {}, {
			ValueTree{ ID::ep_097_ArpegMode, {
						{ ID::property_ExposedName, "Arpeggiator Mode" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 97 },
						{ ID::property_NumberOfChoices, 15 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol10_x },
						{ ID::property_Center_y, 118 },
						{ ID::property_Width, 124 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, DescriptionString::buildFor_ArpegMode() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ArpegMode(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ArpegMode(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_098", {}, {
			ValueTree{ ID::ep_098_ArpegOnOff, {
						{ ID::property_ExposedName, "Arpeggiator On/Off" },
						{ ID::property_ControlType, (int)ControlType::toggleButton },
						{ ID::property_NRPN, 100 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, controlsCol9_x },
						{ ID::property_Center_y, oscControlsRow2_y },
						{ ID::property_Width, GUI::toggle_diameter },
						{ ID::property_Height, GUI::toggle_diameter },
						{ ID::property_Description, DescriptionString::buildFor_ArpegOnOff() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//---------------------------------------------------------------------------------------------------------------- sequencer

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_099", {}, {
			ValueTree{ ID::ep_099_SeqTrigMode, {
						{ ID::property_ExposedName, "Sequencer Trigger Mode" },
						{ ID::property_ControlType, (int)ControlType::comboBox },
						{ ID::property_NRPN, 94 },
						{ ID::property_NumberOfChoices, 6 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, 998 },
						{ ID::property_Center_y, clockAndSequencerControlsRow_y },
						{ ID::property_Width, 114 },
						{ ID::property_Height, GUI::comboBox_h },
						{ ID::property_Description, DescriptionString::buildFor_SeqTrigMode() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_SeqTrigMode(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_SeqTrigMode(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_100", {}, {
			ValueTree{ ID::ep_100_SeqOnOff, {
						{ ID::property_ExposedName, "Sequencer On/Off" },
						{ ID::property_ControlType, (int)ControlType::toggleButton },
						{ ID::property_NRPN, 101 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 0 },
						{ ID::property_Center_x, 819 },
						{ ID::property_Center_y, clockAndSequencerControlsRow_y },
						{ ID::property_Width, GUI::toggle_diameter },
						{ ID::property_Height, GUI::toggle_diameter },
						{ ID::property_Description, DescriptionString::buildFor_SeqOnOff() },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	const int seqTrackDestComboBoxes_w{ 126 };
	const int seqTrackDestComboBoxes_x{ 1065 };

	for (uint8 trackNum = 1; trackNum != 5; ++trackNum) {
		auto paramNumString{ "ep_" + String(100 + trackNum) };
		auto paramNameString{ paramNumString + "_SeqTrack_" + (String)trackNum + "_Dest" };
		auto exposedNameString{ "Sequencer Track " + (String)trackNum + " Destination" };
		auto nrpn{ 76 + trackNum };
		auto trackNumIsEven{ trackNum == 2 || trackNum == 4 };
		auto numberOfChoices{ trackNumIsEven ? EP::numberOfChoicesForSeqTracks_2_4_Dest : EP::numberOfChoicesForModDest };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::comboBox },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, numberOfChoices },
							{ ID::property_DefaultChoice, trackNum < 3 ? trackNum : trackNum == 3 ? 9 : 0 },
							{ ID::property_Center_x, seqTrackDestComboBoxes_x },
							{ ID::property_Center_y, 169 + ((trackNum - 1) * GUI::seqTrackControlsGroup_h) },
							{ ID::property_Width, seqTrackDestComboBoxes_w },
							{ ID::property_Height, GUI::comboBox_h },
							{ ID::property_Description, DescriptionString::buildFor_SeqTrackDestination(trackNum) },
						}, {
							ValueTree{ trackNumIsEven ? 
								ChoiceNamesValueTree::buildFor_SeqTracks_2_4_Destination(trackNum, concise) : 
								ChoiceNamesValueTree::buildFor_ModDestination(concise) },
							ValueTree{ trackNumIsEven ? 
								ChoiceNamesValueTree::buildFor_SeqTracks_2_4_Destination(trackNum, verbose) :
								ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
						} } }
			},
			-1,
			nullptr
		);
	}

	//-------------------------------------------------------------------------------------------------------------- knob assign

	const int knobAssignComboBoxes_w{ 134 };
	const int knobAssignComboBoxes_x{ 1089 };
	const int knobAssignComboBoxesVertSpacing{ 28 };

	for (uint8 knobNum = 1; knobNum != 5; ++knobNum) {
		auto paramNumString{ "ep_" + String(104 + knobNum) };
		auto paramNameString{ paramNumString + "_AssignKnob_" + (String)knobNum };
		auto exposedNameString{ "Assign Parameter to Knob " + (String)knobNum };
		auto nrpn{ 104 + knobNum };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_ControlType, (int)ControlType::comboBox },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 169 },
							{ ID::property_DefaultChoice, knobNum == 1 ? 5 : knobNum == 2 ? 11 : knobNum == 3 ? 43 : 23 },
							{ ID::property_Center_x, knobAssignComboBoxes_x },
							{ ID::property_Center_y, 521 + (knobNum - 1) * knobAssignComboBoxesVertSpacing },
							{ ID::property_Width, knobAssignComboBoxes_w },
							{ ID::property_Height, GUI::comboBox_h },
							{ ID::property_Description, DescriptionString::buildFor_KnobAssign(knobNum) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_KnobAssign(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_KnobAssign(verbose) }
						} } }
			},
			-1,
			nullptr
		);
	}

	//---------------------------------------------------------------------------------------------------------- sequencer steps

	const int gapBetweenSeqStepsAndVoiceNameCharacters{ 2 };

	for (auto trackNum = 0; trackNum != 4; ++trackNum) {
		auto trackString{ String(trackNum + 1) };
		for (auto stepNum = 0; stepNum != 16; ++stepNum) {
			auto stepString{ String(stepNum + 1) };
			auto paramNumString{ "ep_" + String(109 + trackNum * 16 + stepNum) };
			auto paramNameString{ paramNumString + "_SeqTrack_" + trackString + "_Step_" + stepString };
			auto exposedNameString{ "Sequencer Track " + trackString + " Step " + stepString };
			auto nrpn{ 120 + trackNum * 16 + stepNum };
			exposedParamsInfoTree.addChild(
				ValueTree{ paramNumString, {}, {
					ValueTree{ paramNameString, {
								{ ID::property_ExposedName, exposedNameString },
								{ ID::property_ControlType, (int)ControlType::seqTrackStep },
								{ ID::property_NRPN, nrpn },
								{ ID::property_NumberOfChoices, trackNum == 0 ? 128 : 127 },
								{ ID::property_DefaultChoice, 0 },
								{ ID::property_Center_x, 825 + stepNum * (GUI::seqSteps_w + gapBetweenSeqStepsAndVoiceNameCharacters) },
								{ ID::property_Center_y, 196 + trackNum * GUI::seqTrackControlsGroup_h },
								{ ID::property_Width, GUI::seqSteps_w },
								{ ID::property_Height, GUI::seqSteps_h },
								{ ID::property_Description, DescriptionString::buildFor_SeqTrackStep(trackNum + 1, stepNum + 1) },
							}, {
								ValueTree{ ChoiceNamesValueTree::buildFor_SeqTrackStep(concise) },
								ValueTree{ ChoiceNamesValueTree::buildFor_SeqTrackStep(verbose) }
							} } }
				},
				-1,
				nullptr
			);
		}
	}

	//---------------------------------------------------------------------------------------------------- voice name characters

	const int voiceNameCharacters_y{ 52 };

	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ String(charNum + 1) };
		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(173 + charNum), {}, {
				ValueTree{ "ep_" + String(173 + charNum) + "_VoiceNameChar_" + charNumString, {
							{ ID::property_ExposedName, "Program Name Character " + charNumString },
							{ ID::property_ControlType, (int)ControlType::voiceNameChar },
							{ ID::property_NRPN, 173 + charNum },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForVoiceNameChar },
							{ ID::property_DefaultChoice, int(String("Basic Program   ")[charNum]) },
							{ ID::property_Center_x, 596 + charNum * (GUI::voiceNameCharacters_w + gapBetweenSeqStepsAndVoiceNameCharacters) },
							{ ID::property_Center_y, voiceNameCharacters_y },
							{ ID::property_Width, GUI::seqSteps_w },
							{ ID::property_Height, GUI::seqSteps_h },
							{ ID::property_Description, DescriptionString::buildFor_VoiceNameChar(charNum + 1) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_VoiceNameChar(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_VoiceNameChar(verbose) }
						} } }
			},
			-1,
			nullptr
		);
	}

	setDataByteLocationPropertiesForAllParams();
}

void InfoForExposedParameters::setDataByteLocationPropertiesForAllParams() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramNumString{ (String)paramIndex };
		auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
		auto paramPropertiesTree{ exposedParamsInfoTree.getChildWithName(paramTreeName).getChild(0) };
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

InfoForExposedParameters& InfoForExposedParameters::get() noexcept {
	static InfoForExposedParameters exposedParamsInfo;
	return exposedParamsInfo;
}

Identifier InfoForExposedParameters::IDfor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return paramTree.getChild(0).getType().toString();
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return paramTree.getChild(0).getProperty(ID::property_ExposedName).toString();
}

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto controlType{ (int)paramTree.getChild(0).getProperty(ID::property_ControlType) };
	switch (controlType)
	{
	case (int)ControlType::knob:
		return ControlType::knob;
	case (int)ControlType::knobForPitch:
		return ControlType::knobForPitch;
	case (int)ControlType::knobForOscShape:
		return ControlType::knobForOscShape;
	case (int)ControlType::toggleButton:
		return ControlType::toggleButton;
	case (int)ControlType::comboBox:
		return ControlType::comboBox;
	case (int)ControlType::seqTrackStep:
		return ControlType::seqTrackStep;
	case (int)ControlType::voiceNameChar:
		return ControlType::voiceNameChar;
	default:
		return ControlType::nullControl;
	}
}

uint8 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto NRPN{ (int)paramTree.getChild(0).getProperty(ID::property_NRPN) };
	return (uint8)NRPN;
}

uint8 InfoForExposedParameters::numberOfChoicesFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto numberOfChoices{ (int)paramTree.getChild(0).getProperty(ID::property_NumberOfChoices) };
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
	auto defaultChoice{ (int)paramTree.getChild(0).getProperty(ID::property_DefaultChoice) };
	return (uint8)defaultChoice;
}

Point<int> InfoForExposedParameters::centerPointFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto center_x{ (int)paramTree.getChild(0).getProperty(ID::property_Center_x) };
	auto center_y{ (int)paramTree.getChild(0).getProperty(ID::property_Center_y) };
	return Point<int>(center_x, center_y);
}

int InfoForExposedParameters::widthFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return (int)paramTree.getChild(0).getProperty(ID::property_Width);
}

int InfoForExposedParameters::heightFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	return (int)paramTree.getChild(0).getProperty(ID::property_Height);
}

String InfoForExposedParameters::choiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto choiceNamesTree{ paramTree.getChild(0).getChildWithName(ID::choiceNames) };
	auto choiceName{ choiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return choiceName;
}

String InfoForExposedParameters::verboseChoiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto verboseChoiceNamesTree{ paramTree.getChild(0).getChildWithName(ID::choiceNames_Verbose) };
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
	return paramTree.getChild(0).getProperty(ID::property_Description).toString();
}

int InfoForExposedParameters::mouseDragSensitivityFor(uint8 paramIndex) const {
	return 80 + roundToInt(numberOfChoicesFor(paramIndex) / 2);
}

uint16 InfoForExposedParameters::msBitPackedByteLocationFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto msBitLocation((int)paramTree.getChild(0).getProperty(ID::property_MSBitPackedByteLocation));
	return (uint16)msBitLocation;
}

uint8 InfoForExposedParameters::msBitMaskFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto msBitMask{ (int)paramTree.getChild(0).getProperty(ID::property_MSBitMask) };
	return (uint8)msBitMask;
}

uint16 InfoForExposedParameters::lsByteLocationFor(uint8 paramIndex) const {
	auto paramNumString{ (String)paramIndex };
	auto paramTreeName = "ep_" + paramNumString.paddedLeft('0', 3);
	auto paramTree{ exposedParamsInfoTree.getChildWithName(paramTreeName) };
	auto lsByteLocation{ (int)paramTree.getChild(0).getProperty(ID::property_LSByteLocation) };
	return (uint8)lsByteLocation;
}
