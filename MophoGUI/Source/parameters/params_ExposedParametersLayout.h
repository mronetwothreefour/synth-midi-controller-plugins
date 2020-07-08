#pragma once

#include <JuceHeader.h>

#include "params_InfoForExposedParameters_Singleton.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;



// Parameters that are exposed to the plugin host
struct ExposedParametersLayoutFactory
{
	static ParamLayout build() {
		ParamLayout layout;
		auto& info{ InfoForExposedParameters::get() };
		for (uint8 param = 0; param != info.numberOfExposedParameters(); ++param) {
			auto choices{ buildChoicesStringArray(param) };
			layout.add(std::make_unique<AudioParameterChoice>(info.IDfor(param).toString(), info.exposedNameFor(param), choices, info.defaultValueFor(param)));
		}
		return layout;
	}

private:
	static StringArray buildChoicesStringArray(uint8 param) {
		StringArray choices{};
		auto converter{ InfoForExposedParameters::get().converterFor(param) };
		for (uint8 i = 0; i != InfoForExposedParameters::get().numberOfStepsFor(param); ++i) {
			choices.add(converter->verboseConvert(i));
		}
		return choices;
	}
};