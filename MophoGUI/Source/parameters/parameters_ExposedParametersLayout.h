#pragma once

#include <JuceHeader.h>

#include "parameters_ExposedParamInfoArray_Singleton.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;



// Parameters that are exposed to the plugin host
struct ExposedParametersLayoutFactory
{
	static ParamLayout build() {
		ParamLayout layout;
		auto& paramInfoArray{ ExposedParamInfoArray_Singleton::get() };
		for (uint8 index = 0; index != paramInfoArray.size(); ++index) {
			auto param{ paramInfoArray[index] };
			auto choices{ buildChoicesStringArray(param) };
			layout.add(std::make_unique<AudioParameterChoice>(param.ID, param.publicName, choices, uint8(param.defaultValue)));
		}
		return layout;
	}

private:
	static StringArray buildChoicesStringArray(ExposedParameterInfo param) {
		StringArray choices{};
		IntToContextualStringConverter* converter{ param.converter };
		for (uint8 i = 0; i != uint16(param.numberOfSteps); ++i) {
			choices.add(converter->verboseConvert(i));
		}
		return choices;
	}
};