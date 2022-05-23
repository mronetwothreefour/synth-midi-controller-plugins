#include "ep_build_ExposedParamsLayout.h"

#include "ep_singleton_InfoForExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;




ParameterLayout ExposedParametersLayout::build() {
	ParameterLayout layout;
	auto& info{ InfoForExposedParameters::get() };
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info.IDfor(paramIndex).toString() };
		auto exposedName{ info.exposedNameFor(paramIndex) };
		auto choiceNamesList{ info.verboseChoiceNamesListFor(paramIndex) };
		auto defaultChoice{ info.defaultChoiceFor(paramIndex) };
		layout.add(std::make_unique<AudioParameterChoice>(paramID, exposedName, choiceNamesList, defaultChoice));
	}
	return layout;
}
