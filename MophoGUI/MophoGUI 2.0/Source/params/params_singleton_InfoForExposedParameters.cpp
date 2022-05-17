#include "params_singleton_InfoForExposedParameters.h"

#include "params_build_ChoiceNamesValueTree.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace mophoConstants;



InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::exposedParamsInfo }
{
	fillExposedParamsInfoTree();
}

void InfoForExposedParameters::fillExposedParamsInfoTree() {
	const int lastChoiceForOscPitches{ 120 };

	// ------------------------------------------------------------------------------------------------------------- oscillators
	for (auto oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "ep_" + String(oscNum == 1 ? 0 : 6), {}, {
				ValueTree{ (oscNum == 1 ? ID::ep_0_Osc_1_Pitch : ID::ep_6_Osc_2_Pitch), {
							{ "exposedName", "Oscillator " + (String)oscNum + " Pitch" },
							{ "NRPN", oscNum == 1 ? 0 : 5 },
							{ "lastChoice", lastChoiceForOscPitches },
							{ "defaultChoice", 24 },
						}, {
							ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch() },
							ValueTree{ ChoiceNamesValueTree::buildFor_OscPitch_Verbose() }
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
	return paramTree.getProperty("exposedName").toString();
}

uint8 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto NRPN{ (int)paramTree.getProperty("NRPN") };
	return (uint8)NRPN;
}

uint8 InfoForExposedParameters::lastChoiceFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto lastChoice{ (int)paramTree.getProperty("lastChoice") };
	return (uint8)lastChoice;
}

uint8 InfoForExposedParameters::numberOfChoicesFor(uint8 paramIndex) const {
	return uint8(lastChoiceFor(paramIndex) + 1);
}

uint8 InfoForExposedParameters::defaultChoiceFor(uint8 paramIndex) const {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto defaultChoice{ (int)paramTree.getProperty("defaultChoice") };
	return (uint8)defaultChoice;
}

String InfoForExposedParameters::choiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto choiceNamesTree{ paramTree.getChildWithName("choiceNames") };
	auto choiceName{ choiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return choiceName;
}

String InfoForExposedParameters::verboseChoiceNameFor(uint8 choiceNum, uint8 paramIndex) const {
	jassert(choiceNum < numberOfChoicesFor(paramIndex));
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("ep_" + (String)paramIndex).getChild(0) };
	auto verboseChoiceNamesTree{ paramTree.getChildWithName("verboseChoiceNames") };
	auto verboseChoiceName{ verboseChoiceNamesTree.getProperty("choice_" + (String)choiceNum).toString() };
	return verboseChoiceName;
}
