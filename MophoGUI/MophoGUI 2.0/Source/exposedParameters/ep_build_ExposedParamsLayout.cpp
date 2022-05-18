#include "ep_build_ExposedParamsLayout.h"

#include "ep_singleton_InfoForExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace mophoConstants;




ParameterLayout ExposedParametersLayout::build() {
	ParameterLayout layout;
	auto& info{ InfoForExposedParameters::get() };
	for (auto paramIndex = (uint8)0; paramIndex != 12; ++paramIndex) {
		StringArray choices;
		for (auto choiceNum = (uint8)0; choiceNum != info.numberOfChoicesFor(paramIndex); ++choiceNum)
			choices.add(info.verboseChoiceNameFor(choiceNum, paramIndex));

		layout.add(std::make_unique<AudioParameterChoice>(
				info.IDfor(paramIndex).toString(), 
				info.exposedNameFor(paramIndex), 
				choices, 
				info.defaultChoiceFor(paramIndex)
			));
	}
	return layout;
}
