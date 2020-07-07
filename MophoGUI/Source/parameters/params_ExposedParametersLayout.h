#pragma once

#include <JuceHeader.h>

#include "parameters_ExposedParamsInfo_Singleton.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;



// Parameters that are exposed to the plugin host
struct ExposedParametersLayoutFactory
{
	static ParamLayout build() {
		ParamLayout layout;
		auto& allParamsInfo{ InfoForExposedParameters_Singleton::get() };
		for (uint8 index = 0; index != allParamsInfo.size(); ++index) {
			auto paramInfo{ allParamsInfo[index] };
			auto choices{ buildChoicesStringArray(paramInfo) };
			layout.add(std::make_unique<AudioParameterChoice>(paramInfo.ID, paramInfo.publicName, choices, uint8(paramInfo.defaultValue)));
		}
		return layout;
	}

private:
	static StringArray buildChoicesStringArray(ExposedParameterInfo paramInfo) {
		StringArray choices{};
		IntToContextualStringConverter* converter{ paramInfo.converter };
		for (uint8 i = 0; i != uint16(paramInfo.numberOfSteps); ++i) {
			choices.add(converter->verboseConvert(i));
		}
		return choices;
	}
};