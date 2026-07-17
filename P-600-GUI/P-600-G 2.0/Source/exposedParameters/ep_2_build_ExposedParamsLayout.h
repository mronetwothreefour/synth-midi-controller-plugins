#pragma once

#include <JuceHeader.h>

#include "ep_1_tree_InfoForExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace P_600_G_Constants;
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
		StringArray rndmTrigChoices{ "0", "1" };
		layout.add(std::make_unique<AudioParameterChoice>(ID::rndmTrig_AllUnlocked.toString(), "Randomize: All Unlocked Parameters", rndmTrigChoices, 0));
		for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
			auto paramID{ info->IDfor(paramIndex) };
			auto paramName{ info->exposedNameFor(paramIndex) };
			layout.add(std::make_unique<AudioParameterChoice>(ID::rndmTrig_.toString() + paramID, "Randomize: " + paramName, rndmTrigChoices, 0));
		}
		return layout;
	};

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersLayout)
};