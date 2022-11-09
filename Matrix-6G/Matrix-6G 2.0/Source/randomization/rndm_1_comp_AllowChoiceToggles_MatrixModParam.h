#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"
#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class ExposedParameters;
class MatrixModOptions;
class ParamRandomizationOptions;
class TooltipsOptions;
class UnexposedParameters;

class AllowChoiceToggles_MatrixModParam :
	public AllowChoiceToggles_Base
{
	int modNum;
	MM_Type paramType;
	MatrixModOptions* matrixModOptions;
	ParamRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	uint8 numberOfChoices;

public:
	AllowChoiceToggles_MatrixModParam() = delete;

	AllowChoiceToggles_MatrixModParam(int modNum, MM_Type paramType, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	String buildChoiceName(uint8 choiceNum) override;
	String buildTooltip() override;
	const bool choiceIsAllowed(uint8 choiceNum) override;
	void setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) override;
	void clearAllowedChoices() override;
	const bool noChoiceIsAllowed() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_MatrixModParam)
};