#include "ep_singleton_InfoForExposedParameters.h"

#include "ep_build_ChoiceNamesValueTree.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace mophoConstants;



InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::exposedParamsInfo }
{
	fillExposedParamsInfoTree();
}

void InfoForExposedParameters::fillExposedParamsInfoTree() {
	auto concise{ (bool)false };
	auto verbose{ (bool)true };
	// ------------------------------------------------------------------------------------------------------------- oscillators
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ oscNum == 1 ? "ep_000" : "ep_006", {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_000_Osc_1_Pitch : ID::ep_006_Osc_2_Pitch), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pitch" },
							{ ID::property_NRPN, oscNum == 1 ? 0 : 5 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
							{ ID::property_DefaultChoice, 24 },
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
							{ ID::property_NRPN, oscNum == 1 ? 1 : 6 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscFineTune },
							{ ID::property_DefaultChoice, oscNum == 1 ? 49 : 51 },
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
							{ ID::property_NRPN, oscNum == 1 ? 2 : 7 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscWaveShape },
							{ ID::property_DefaultChoice, 1 },
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
							{ ID::property_NRPN, oscNum == 1 ? 3 : 8 },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
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
							{ ID::property_NRPN, oscNum == 1 ? 4 : 9 },
							{ ID::property_NumberOfChoices, 2 },
							{ ID::property_DefaultChoice, 1 },
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
							{ ID::property_NRPN, oscNum == 1 ? 114 : 115 },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 10 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 11 },
						{ ID::property_NumberOfChoices, 4 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 12 },
						{ ID::property_NumberOfChoices, 6 },
						{ ID::property_DefaultChoice, 2 },
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
						{ ID::property_NRPN, 93 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForBendRange },
						{ ID::property_DefaultChoice, 4 },
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
						{ ID::property_NRPN, 96 },
						{ ID::property_NumberOfChoices, 6 },
						{ ID::property_DefaultChoice, 4 },
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
						{ ID::property_NRPN, 13 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 64 },
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
						{ ID::property_NRPN, 14 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 116 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//---------------------------------------------------------------------------------------------------------------------- LPF

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_020", {}, {
			ValueTree{ ID::ep_020_LPF_Freq, {
						{ ID::property_ExposedName, "LPF Cutoff Frequency" },
						{ ID::property_NRPN, 15 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForLPF_Freq },
						{ ID::property_DefaultChoice, 148 },
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
						{ ID::property_NRPN, 15 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 17 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 18 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 19 },
						{ ID::property_NumberOfChoices, 2 },
						{ ID::property_DefaultChoice, 1 },
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
						{ ID::property_NRPN, 20 },
						{ ID::property_NumberOfChoices, 255 },
						{ ID::property_DefaultChoice, 127 },
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
						{ ID::property_NRPN, 21 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 22 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 23 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 24 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 25 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 26 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//---------------------------------------------------------------------------------------------------------------------- VCA

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_032", {}, {
			ValueTree{ ID::ep_032_VCA_Level, {
						{ ID::property_ExposedName, "VCA Baseline Level" },
						{ ID::property_NRPN, 27 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 30 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 127 },
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
						{ ID::property_NRPN, 31 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 32 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 33 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 34 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 35 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 64 },
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
						{ ID::property_NRPN, 36 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 64 },
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
						{ ID::property_NRPN, 29 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 120 },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue(128, verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//--------------------------------------------------------------------------------------------------------------------- LFOs

	for (uint8 lfoNum = 0; lfoNum != 4; ++lfoNum) {
		auto paramNumString{ "ep_0" + (String)(41 + lfoNum * 5) };
		auto paramNameString{ paramNumString + "_LFO_" + String(lfoNum + 1) + "_Freq" };
		auto exposedNameString{ "LFO " + String(lfoNum + 1) + " Frequency" };
		auto nrpn{ 37 + lfoNum * 5 };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 167 },
							{ ID::property_DefaultChoice, 80 },
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
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 5 },
							{ ID::property_DefaultChoice, 1 },
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
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
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
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 47 },
							{ ID::property_DefaultChoice, 0 },
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
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 2 },
							{ ID::property_DefaultChoice, 0 },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_OffOn(verbose) }
						} } }
			},
			-1,
			nullptr
		);
	}

	//--------------------------------------------------------------------------------------------------------------------------
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
