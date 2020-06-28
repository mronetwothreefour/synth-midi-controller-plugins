#pragma once

#include <JuceHeader.h>

#include "parameters_SynthParametersDB.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;

struct PublicParametersLayout
{
	static ParamLayout build()
	{
		ParamLayout layout;
		auto& paramsDB{ SynthParametersDatabase::get() };
		for (uint8 index = 0; index != paramsDB.firstNonPublicParam; ++index)
		{
			auto param{ paramsDB.getSynthParameter(index) };
			auto choices{ buildChoicesStringArray(param) };
			layout.add(std::make_unique<AudioParameterChoice>(Identifier(param.ID).toString(), param.publicName, choices, 0));
		}
		return layout;
	}

	static StringArray buildChoicesStringArray(SynthParameter param)
	{
		StringArray choices{};
		IntToContextualStringConverter* converter{ param.converter };
		for (uint8 i = 0; i != uint16(param.numberOfSteps); ++i)
		{
			choices.add(converter->verboseConvert(i));
		}

		return choices;
	}
};