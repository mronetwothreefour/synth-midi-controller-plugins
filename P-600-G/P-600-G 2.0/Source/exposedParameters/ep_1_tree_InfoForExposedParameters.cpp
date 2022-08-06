#include "ep_1_tree_InfoForExposedParameters.h"

#include "ep_0_build_ChoiceNamesValueTree.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_ExposedParamDescription.h"

using namespace P_600_G_Constants;

InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::tree_ExposedParamsInfo }
{

	// ------------------------------------------------------------------------------------------------------------- oscillators

	for (auto oscNum = 1; oscNum != 3; ++oscNum) {

	}
}
