#pragma once

#include <JuceHeader.h>

struct MatrixModParamChoiceName
{
	static String buildForModAmount(uint8 choiceNum);
	static String buildForModDest(uint8 choiceNum, bool verbose);
	static String buildForModSource(uint8 choiceNum, bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModParamChoiceName)
};