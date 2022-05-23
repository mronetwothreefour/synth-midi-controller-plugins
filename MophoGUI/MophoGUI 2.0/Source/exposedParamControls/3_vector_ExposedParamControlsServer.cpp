#include "3_vector_ExposedParamControlsServer.h"

#include "../constants/constants_ExposedParameters.h"

using namespace MophoConstants;



ExposedParamControlsServer::ExposedParamControlsServer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	fillControlsVector();
}

void ExposedParamControlsServer::fillControlsVector() {
	for (uint8 paramIndex = 0; paramIndex != 32; ++paramIndex)
		controlsVector.push_back(std::make_unique<ExposedParamControl>(paramIndex, exposedParams, unexposedParams));
}

ExposedParamControl* ExposedParamControlsServer::controlPtrFor(uint8 paramIndex) const {
	return controlsVector[paramIndex].get();
}

int ExposedParamControlsServer::paramIndexOutOfRange() const {
	return (int)controlsVector.size();
}

void ExposedParamControlsServer::clearControlsVector() {
	controlsVector.clear();
}

void ExposedParamControlsServer::rebuildControlsVector() {
	controlsVector.clear();
	fillControlsVector();
}
