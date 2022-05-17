#include "params_ExposedParamsLayout_Factory.h"

#include "params_Constants.h"
#include "params_ExposedParamsInfo_Singleton.h"
#include "params_Identifiers.h"
#include "params_IntToContextualStringConverters.h"

using namespace constants;




ParamLayout ExposedParametersLayoutFactory::build() {
	ParamLayout layout;
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 paramIndex = 0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		auto choices{ buildChoicesStringArrayFor(paramIndex) };
		layout.add(std::make_unique<AudioParameterChoice>(info.IDfor(paramIndex).toString(), info.exposedNameFor(paramIndex), choices, info.defaultValueFor(paramIndex)));
	}
	StringArray randomizationTriggerChoices{ "0", "1" };
	layout.add(std::make_unique<AudioParameterChoice>(ID::rndmTrigFor_AllUnlocked.toString(), "Trigger For Randomizing All Unlocked Parameters", randomizationTriggerChoices, 0));
	for (uint8 paramIndex = 0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info.IDfor(paramIndex) };
		auto paramName{ info.exposedNameFor(paramIndex) };
		layout.add(std::make_unique<AudioParameterChoice>(ID::rndmTrigFor_.toString() + paramID, paramName + " Randomization Trigger ", randomizationTriggerChoices, 0));
	}
	return layout;
}

StringArray ExposedParametersLayoutFactory::buildChoicesStringArrayFor(uint8 param) {
	StringArray choices{};
	auto& info{ InfoForExposedParameters::get() };
	auto converter{ info.converterFor(param) };
	jassert(converter != nullptr);
	if (converter != nullptr) {
		for (uint8 i = 0; i != info.numberOfStepsFor(param); ++i) {
			choices.add(converter->verboseConvert(i));
		}
	}
	return choices;
}
