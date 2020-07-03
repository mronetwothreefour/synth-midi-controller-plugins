#pragma once

#include <JuceHeader.h>

#include "parameters_ExposedParameters_DB.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;



// Parameters that are exposed to the plugin host
struct ExposedParametersLayoutFactory
{
	static ParamLayout build() {
		ParamLayout layout;
		auto& exposedParamsDB{ ExposedParameters_Database::get() };
		for (uint8 index = 0; index != exposedParamsDB.size(); ++index) {
			auto param{ exposedParamsDB.getSynthParameter(index) };
			auto choices{ buildChoicesStringArray(param) };
			layout.add(std::make_unique<AudioParameterChoice>(param.ID, param.publicName, choices, uint8(param.defaultValue)));
		}
		return layout;
	}

private:
	static StringArray buildChoicesStringArray(ParameterProperties param) {
		StringArray choices{};
		IntToContextualStringConverter* converter{ param.converter };
		for (uint8 i = 0; i != uint16(param.numberOfSteps); ++i) {
			choices.add(converter->verboseConvert(i));
		}
		return choices;
	}
};