#pragma once

#include <JuceHeader.h>

#include "parameters_Synth.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;

struct PublicParametersLayout
{
	static ParamLayout get()
	{
		ParamLayout layout;
		SynthParamPropertiesDB& paramsDB{ SynthParamPropertiesDB::get() };
		auto numberOfPublicParams{ paramsDB.get_numberOfPublicSynthParams() };
		for (uint8 index = 0; index != numberOfPublicParams; ++index)
		{
			auto ID{ paramsDB.get_ID_forSynthParam(index).toString() };
			auto publicName{ paramsDB.get_publicName_forSynthParam(index) };
			StringArray choices{};
			auto numberOfSteps{ paramsDB.get_numberOfSteps_forSynthParam(index) };
			auto converter{ paramsDB.get_intToStringConverter_forSynthParam(index) };
			for (uint8 i = 0; i != numberOfSteps; ++i)
			{
				choices.add(converter->convert(i, true));
			}

			layout.add(std::make_unique<AudioParameterChoice>(ID, publicName, choices, 0));
		}

		return layout;
	}
};