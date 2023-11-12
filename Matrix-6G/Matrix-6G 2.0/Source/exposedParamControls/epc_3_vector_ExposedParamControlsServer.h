#pragma once

#include <JuceHeader.h>

#include "epc_2_comp_ExposedParamControl.h"
#include "../constants/constants_ExposedParameters.h"

using namespace Matrix_6G_Constants;

class ExposedParamControlsServer
{
	ExposedParameters* exposedParams;
	TooltipsOptions* tooltips;
	std::vector<std::unique_ptr<ExposedParamControl>> controlsVector;

public:
	ExposedParamControlsServer() = delete;

	explicit ExposedParamControlsServer(ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
		exposedParams{ exposedParams },
		tooltips{ tooltips }
	{
	}

	void fillControlsVector() {
		for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex)
			controlsVector.push_back(std::make_unique<ExposedParamControl>(paramIndex, exposedParams, tooltips));
	}

	ExposedParamControl* controlPtrFor(uint8 paramIndex) const {
		return controlsVector[paramIndex].get();
	}

	int paramIndexOutOfRange() const {
		return (int)controlsVector.size();
	}

	void clearControlsVector() {
		controlsVector.clear();
	}

	void rebuildControlsVector() {
		controlsVector.clear();
		fillControlsVector();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamControlsServer)
};
