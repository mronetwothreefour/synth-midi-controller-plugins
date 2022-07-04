#pragma once

#include <JuceHeader.h>

#include "ep_tree_InfoForExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"

using namespace MophoConstants;
using ParameterLayout = AudioProcessorValueTreeState::ParameterLayout;



struct ExposedParametersLayout
{
	static ParameterLayout build(InfoForExposedParameters* info) {
		ParameterLayout layout;
		for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
			auto paramID{ info->IDfor(paramIndex).toString() };
			auto exposedName{ info->exposedNameFor(paramIndex) };
			auto choiceNamesList{ info->verboseChoiceNamesListFor(paramIndex) };
			auto defaultChoice{ info->defaultChoiceFor(paramIndex) };
			layout.add(std::make_unique<AudioParameterChoice>(paramID, exposedName, choiceNamesList, defaultChoice));
		}
		return layout;
	};

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersLayout)
};