#include "rndm_0_ParamRandomizationMethods.h"

#include "../unexposedParameters/up_facade_UnexposedParameters.h"



ParamRandomizationMethods::ParamRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	randomization{ unexposedParams->getRandomizationOptions() }
{
}

void ParamRandomizationMethods::randomizeAllUnlockedParameters()
{
}

void ParamRandomizationMethods::randomizeParameter(String /*paramID*/)
{
}

void ParamRandomizationMethods::randomizeSeqTrack(Track /*track*/)
{
}

void ParamRandomizationMethods::timerCallback()
{
}
