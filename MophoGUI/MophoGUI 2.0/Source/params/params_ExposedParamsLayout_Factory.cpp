#include "params_ExposedParamsLayout_Factory.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "params_Identifiers.h"
#include "params_IntToContextualStringConverters.h"




ParamLayout ExposedParametersLayoutFactory::build() {
	ParamLayout layout;
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		auto choices{ buildChoicesStringArrayFor(param) };
		layout.add(std::make_unique<AudioParameterChoice>(info.IDfor(param).toString(), info.exposedNameFor(param), choices, info.defaultValueFor(param)));
	}
	StringArray randomizationTriggerChoices{ "0", "1" };
	layout.add(std::make_unique<AudioParameterChoice>(ID::randomizationTrig.toString(), "Randomization Trigger", randomizationTriggerChoices, 0));
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
