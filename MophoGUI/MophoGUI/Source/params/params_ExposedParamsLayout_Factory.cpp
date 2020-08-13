#include "params_ExposedParamsLayout_Factory.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "params_IntToContextualStringConverters.h"




ParamLayout ExposedParametersLayoutFactory::build() {
	ParamLayout layout;
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		auto choices{ buildChoicesStringArrayFor(param) };
		layout.add(std::make_unique<AudioParameterChoice>(info.IDfor(param).toString(), info.exposedNameFor(param), choices, info.defaultValueFor(param)));
	}
	return layout;
}

StringArray ExposedParametersLayoutFactory::buildChoicesStringArrayFor(uint8 param) {
	StringArray choices{};
	auto converter{ InfoForExposedParameters::get().converterFor(param) };
	for (uint8 i = 0; i != InfoForExposedParameters::get().numberOfStepsFor(param); ++i) {
		choices.add(converter->verboseConvert(i));
	}
	return choices;
}
