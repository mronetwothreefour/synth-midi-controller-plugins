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

	// ------------------------------------------------------------------------------------------------------------- oscillators
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(oscNum == 1 ? 0 : 6), {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_0_Osc_1_Pitch : ID::ep_6_Osc_2_Pitch), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Pitch" },
							{ ID::property_NRPN, oscNum == 1 ? 0 : 5 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscPitch },
							{ ID::property_DefaultChoice, 24 },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch() },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch_Verbose() }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(oscNum == 1 ? 1 : 7), {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_1_Osc_1_FineTune : ID::ep_7_Osc_2_FineTune), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Fine Tune" },
							{ ID::property_NRPN, oscNum == 1 ? 1 : 6 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscFineTune },
							{ ID::property_DefaultChoice, oscNum == 1 ? 49 : 51 },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscFineTune() },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscFineTune_Verbose() }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(oscNum == 1 ? 2 : 8), {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_2_Osc_1_Shape : ID::ep_8_Osc_2_Shape), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Wave Shape" },
							{ ID::property_NRPN, oscNum == 1 ? 2 : 7 },
							{ ID::property_NumberOfChoices, EP::numberOfChoicesForOscWaveShape },
							{ ID::property_DefaultChoice, 1 },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscShape() },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscShape_Verbose() }
						} } }
			},
			-1,
			nullptr
		);

		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(oscNum == 1 ? 3 : 9), {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_3_Osc_1_Glide : ID::ep_9_Osc_2_Glide), {
							{ ID::property_ExposedName, "Oscillator " + (String)oscNum + " Glide Rate" },
							{ ID::property_NRPN, oscNum == 1 ? 3 : 8 },
							{ ID::property_NumberOfChoices, 128 },
							{ ID::property_DefaultChoice, 0 },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue((uint8)128) },
							ValueTree{ ChoiceNamesValueTree::buildFor_PlainValue_Verbose((uint8)128) }
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
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	return paramTree.getType().toString();
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	return paramTree.getProperty(ID::property_ExposedName).toString();
}

uint8 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto NRPN{ (int)paramTree.getProperty(ID::property_NRPN) };
	return (uint8)NRPN;
}

uint8 InfoForExposedParameters::numberOfChoicesFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto numberOfChoices{ (int)paramTree.getProperty(ID::property_NumberOfChoices) };
	return (uint8)numberOfChoices;
}

uint8 InfoForExposedParameters::lastChoiceFor(uint8 paramIndex) const {
	return uint8(numberOfChoicesFor(paramIndex) - 1);
}

uint8 InfoForExposedParameters::defaultChoiceFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto defaultChoice{ (int)paramTree.getProperty(ID::property_DefaultChoice) };
	return (uint8)defaultChoice;
}

String InfoForExposedParameters::choiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto choiceNamesTree{ paramTree.getChildWithName(ID::choiceNames) };
	auto choiceName{ choiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return choiceName;
}

String InfoForExposedParameters::verboseChoiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto verboseChoiceNamesTree{ paramTree.getChildWithName(ID::choiceNames_Verbose) };
	auto verboseChoiceName{ verboseChoiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return verboseChoiceName;
}
