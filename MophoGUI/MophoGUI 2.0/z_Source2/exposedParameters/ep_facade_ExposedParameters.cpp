#include "ep_facade_ExposedParameters.h"

#include "ep_build_ExposedParamsLayout.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



ExposedParameters::ExposedParameters(AudioProcessor* processor) :
	state{ *processor, &undoManager, "exposedParams", ExposedParametersLayout::build(&info) }
{
}
