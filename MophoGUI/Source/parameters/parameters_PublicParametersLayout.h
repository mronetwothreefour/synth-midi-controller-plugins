#pragma once

#include <JuceHeader.h>

#include "parameters_SynthParametersDB.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;

struct PublicParametersLayout
{
	static ParamLayout get()
	{
		ParamLayout layout;
		auto& paramsDB{ SynthParametersDatabase::get() };
		auto firstNonPublicParam{ paramsDB.firstNonPublicParam };
		for (uint8 index = 0; index != firstNonPublicParam; ++index)
		{
			auto param{ paramsDB.getSynthParameter(index) };
			StringArray choices{};
			IntToStringConverter* converter{ param.converter };
			for (uint8 i = 0; i != uint16(param.numberOfSteps); ++i)
			{
				choices.add(converter->convert(i, true));
			}
			layout.add(std::make_unique<AudioParameterChoice>(Identifier(param.ID).toString(), param.publicName, choices, 0));
		}

		return layout;
	}
};