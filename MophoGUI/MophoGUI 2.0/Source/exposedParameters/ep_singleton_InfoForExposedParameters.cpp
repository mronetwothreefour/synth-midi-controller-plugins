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
						ValueTree{ ChoiceNamesValueTree::buildFor_GildeMode(concise) },
						ValueTree{ ChoiceNamesValueTree::buildFor_GildeMode(verbose) }
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
