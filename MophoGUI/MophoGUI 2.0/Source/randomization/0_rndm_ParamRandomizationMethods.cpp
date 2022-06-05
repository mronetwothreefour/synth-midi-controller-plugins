#include "0_rndm_ParamRandomizationMethods.h"

ParamRandomizationMethods::ParamRandomizationMethods(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
}

void ParamRandomizationMethods::randomizeAllUnlockedParameters()
{
}

void ParamRandomizationMethods::randomizeParameter(String paramID)
{
}

void ParamRandomizationMethods::timerCallback()
{
}
