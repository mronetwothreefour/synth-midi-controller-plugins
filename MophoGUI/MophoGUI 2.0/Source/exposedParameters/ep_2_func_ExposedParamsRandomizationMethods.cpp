#include "ep_2_func_ExposedParamsRandomizationMethods.h"

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "ep_3_facade_ExposedParameters.h"


ExposedParamsRandomizationMethods::ExposedParamsRandomizationMethods(ExposedParameters* exposedParams) :
	state{ exposedParams->state.get() },
	randomization{ exposedParams->randomization.get() },
	info{ exposedParams->info.get() }
{
}

void ExposedParamsRandomizationMethods::randomizeAllUnlockedParameters()
{
}

void ExposedParamsRandomizationMethods::randomizeParameter(String /*paramID*/)
{
}

void ExposedParamsRandomizationMethods::randomizeSeqTrack(Track /*track*/)
{
}

void ExposedParamsRandomizationMethods::timerCallback()
{
}
