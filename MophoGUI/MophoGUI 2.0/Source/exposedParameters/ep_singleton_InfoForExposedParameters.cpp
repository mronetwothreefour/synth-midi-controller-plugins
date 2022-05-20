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
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
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

	//--------------------------------------------------------------------------------------------------------------- Envelope 3

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_061", {}, {
			ValueTree{ ID::ep_061_Env_3_Destination, {
						{ ID::property_ExposedName, "Envelope 3 Modulation Destination" },
						{ ID::property_NRPN, 57 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 58 },
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
		ValueTree{ "ep_063", {}, {
			ValueTree{ ID::ep_063_Env_3_VelAmount, {
						{ ID::property_ExposedName, "Envelope 3 Velocity Amount" },
						{ ID::property_NRPN, 59 },
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
		ValueTree{ "ep_064", {}, {
			ValueTree{ ID::ep_064_Env_3_Delay, {
						{ ID::property_ExposedName, "Envelope 3 Delay" },
						{ ID::property_NRPN, 60 },
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
		ValueTree{ "ep_065", {}, {
			ValueTree{ ID::ep_065_Env_3_Attack, {
						{ ID::property_ExposedName, "Envelope 3 Attack" },
						{ ID::property_NRPN, 61 },
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
		ValueTree{ "ep_066", {}, {
			ValueTree{ ID::ep_066_Env_3_Decay, {
						{ ID::property_ExposedName, "Envelope 3 Decay" },
						{ ID::property_NRPN, 62 },
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
		ValueTree{ "ep_067", {}, {
			ValueTree{ ID::ep_067_Env_3_Sustain, {
						{ ID::property_ExposedName, "Envelope 3 Sustain" },
						{ ID::property_NRPN, 63 },
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
		ValueTree{ "ep_068", {}, {
			ValueTree{ ID::ep_068_Env_3_Release, {
						{ ID::property_ExposedName, "Envelope 3 Release" },
						{ ID::property_NRPN, 64 },
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
		ValueTree{ "ep_069", {}, {
			ValueTree{ ID::ep_069_Env_3_Repeat, {
						{ ID::property_ExposedName, "Envelope 3 Repeat" },
						{ ID::property_NRPN, 98 },
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

	//--------------------------------------------------------------------------------------------------------------- modulators

	for (uint8 modNum = 0; modNum != 4; ++modNum) {
		auto paramNumString{ "ep_0" + (String)(70 + modNum * 3) };
		auto paramNameString{ paramNumString + "_Mod_" + String(modNum + 1) + "_Source" };
		auto exposedNameString{ "Modulator " + String(modNum + 1) + " Source" };
		auto nrpn{ 65 + modNum * 3 };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForModSource },
							{ ID::property_DefaultChoice, 0 },
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
							{ ID::property_NRPN, nrpn },
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

		paramNumString = "ep_0" + (String)(72 + modNum * 3);
		paramNameString = paramNumString + "_Mod_" + String(modNum + 1) + "_Destination";
		exposedNameString = "Modulator " + String(modNum + 1) + " Destination";
		nrpn = 67 + modNum * 3;
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
							{ ID::property_DefaultChoice, 0 },
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

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_082", {}, {
			ValueTree{ ID::ep_082_ModWheelAmount, {
						{ ID::property_ExposedName, "Modulation Wheel Amount" },
						{ ID::property_NRPN, 81 },
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
		ValueTree{ "ep_083", {}, {
			ValueTree{ ID::ep_083_ModWheelDest, {
						{ ID::property_ExposedName, "Modulation Wheel Destination" },
						{ ID::property_NRPN, 82 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 83 },
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
		ValueTree{ "ep_085", {}, {
			ValueTree{ ID::ep_085_PressureDest, {
						{ ID::property_ExposedName, "Pressure (Aftertouch) Destination" },
						{ ID::property_NRPN, 84 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 85 },
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
		ValueTree{ "ep_087", {}, {
			ValueTree{ ID::ep_087_BreathDest, {
						{ ID::property_ExposedName, "Breath Destination" },
						{ ID::property_NRPN, 86 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 87 },
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
		ValueTree{ "ep_089", {}, {
			ValueTree{ ID::ep_089_VelocityDest, {
						{ ID::property_ExposedName, "Note Velocity Destination" },
						{ ID::property_NRPN, 88 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 89 },
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
		ValueTree{ "ep_091", {}, {
			ValueTree{ ID::ep_091_PedalDest, {
						{ ID::property_ExposedName, "Foot Pedal Destination" },
						{ ID::property_NRPN, 90 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForModDest },
						{ ID::property_DefaultChoice, 0 },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_ModDestination(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//------------------------------------------------------------------------------------------------------------------ Push It

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_092", {}, {
			ValueTree{ ID::ep_092_PushItPitch, {
						{ ID::property_ExposedName, "Push It! Switch Pitch" },
						{ ID::property_NRPN, 111 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
						{ ID::property_DefaultChoice, 60 },
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
						{ ID::property_NRPN, 112 },
						{ ID::property_NumberOfChoices, 128 },
						{ ID::property_DefaultChoice, 100 },
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
						{ ID::property_NRPN, 113 },
						{ ID::property_NumberOfChoices, 3 },
						{ ID::property_DefaultChoice, 0 },
					}, {
						ValueTree{ ChoiceNamesValueTree::buildFor_PushItMode(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_PushItMode(verbose) }
					} } }
		},
		-1,
		nullptr
	);

	//------------------------------------------------------------------------------------------------------ clock & arpeggiator

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_095", {}, {
			ValueTree{ ID::ep_095_ClockTempo, {
						{ ID::property_ExposedName, "Clock Tempo" },
						{ ID::property_NRPN, 91 },
						{ ID::property_NumberOfChoices, EP::numberOfChoicesForClockTempo },
						{ ID::property_DefaultChoice, 90 },
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
						{ ID::property_NRPN, 92 },
						{ ID::property_NumberOfChoices, 13 },
						{ ID::property_DefaultChoice, 2 },
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
						{ ID::property_NRPN, 97 },
						{ ID::property_NumberOfChoices, 15 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 100 },
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

	//---------------------------------------------------------------------------------------------------------------- sequencer

	exposedParamsInfoTree.addChild(
		ValueTree{ "ep_099", {}, {
			ValueTree{ ID::ep_099_SeqTrigMode, {
						{ ID::property_ExposedName, "Sequencer Trigger Mode" },
						{ ID::property_NRPN, 94 },
						{ ID::property_NumberOfChoices, 6 },
						{ ID::property_DefaultChoice, 0 },
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
						{ ID::property_NRPN, 101 },
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
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, numberOfChoices },
							{ ID::property_DefaultChoice, 0 },
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

	for (uint8 knobNum = 1; knobNum != 5; ++knobNum) {
		auto paramNumString{ "ep_" + String(104 + knobNum) };
		auto paramNameString{ paramNumString + "_AssignKnob_" + (String)knobNum };
		auto exposedNameString{ "Assign Parameter to Knob " + (String)knobNum };
		auto nrpn{ 104 + knobNum };
		exposedParamsInfoTree.addChild(
			ValueTree{ paramNumString, {}, {
				ValueTree{ paramNameString, {
							{ ID::property_ExposedName, exposedNameString },
							{ ID::property_NRPN, nrpn },
							{ ID::property_NumberOfChoices, 169 },
							{ ID::property_DefaultChoice, knobNum == 1 ? 5 : knobNum == 2 ? 11 : knobNum == 3 ? 43 : 23 },
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
								{ ID::property_NRPN, nrpn },
								{ ID::property_NumberOfChoices, trackNum == 0 ? 128 : 127 },
								{ ID::property_DefaultChoice, 0 },
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

	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ String(charNum + 1) };
		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(173 + charNum), {}, {
				ValueTree{ "ep_" + String(173 + charNum) + "_VoiceNameChar_" + charNumString, {
							{ ID::property_ExposedName, "Program Name Character " + charNumString },
							{ ID::property_NRPN, 173 + charNum },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, int(String("Basic Program   ")[charNum]) },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_VoiceNameChar(concise) },
							ValueTree{ ChoiceNamesValueTree::buildFor_VoiceNameChar(verbose) }
						} } }
			},
			-1,
			nullptr
		);
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
