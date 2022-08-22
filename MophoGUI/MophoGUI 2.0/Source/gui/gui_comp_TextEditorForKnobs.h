#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using RangeType = KnobValueRangeType;

class TextEditorForKnobs :
	public Label
{
	RangeType rangeType;
	int minValue{ 0 };
	int maxValue{ 0 };

public:
	TextEditorForKnobs() = delete;

	TextEditorForKnobs(RangeType rangeType, uint8 currentChoiceNum);
};