#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class ParamRandomizationOptions;
class TooltipsOptions;

class GroupLockStateButtons :
	public Component
{
	TextButton btn_Lock;
	TextButton btn_Unlock;

public:
	GroupLockStateButtons() = delete;

	GroupLockStateButtons(LockStateGroup group, ParamRandomizationOptions* randomization, TooltipsOptions* tooltips);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GroupLockStateButtons)
};