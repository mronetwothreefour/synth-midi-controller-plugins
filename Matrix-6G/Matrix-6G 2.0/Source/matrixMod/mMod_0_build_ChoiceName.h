#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct MatrixModParamChoiceName
{
	static String buildForModAmount(uint8 choiceNum);
	static String buildForModDest(uint8 choiceNum, ChoiceNameType type);
	static String buildForModSource(uint8 choiceNum, ChoiceNameType type);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModParamChoiceName)
};