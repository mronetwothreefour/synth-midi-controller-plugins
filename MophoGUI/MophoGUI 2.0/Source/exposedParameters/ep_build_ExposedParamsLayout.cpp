#include "ep_build_ExposedParamsLayout.h"

#include "ep_singleton_InfoForExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;
using Info = InfoForExposedParameters;




ParameterLayout ExposedParametersLayout::build() {
	ParameterLayout layout;
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ Info::get().IDfor(paramIndex).toString() };
		auto exposedName{ Info::get().exposedNameFor(paramIndex) };
		auto choiceNamesList{ Info::get().verboseChoiceNamesListFor(paramIndex) };
		auto defaultChoice{ Info::get().defaultChoiceFor(paramIndex) };
		layout.add(std::make_unique<AudioParameterChoice>(paramID, exposedName, choiceNamesList, defaultChoice));
	}
	return layout;
}
