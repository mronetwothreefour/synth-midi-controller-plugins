#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

class ExposedParamsRandomizationOptions;
class TooltipsOptions;

class GroupLockStateButtons :
	public Component
{
	TextButton btn_Lock;
	TextButton btn_Unlock;

public:
	GroupLockStateButtons() = delete;

	GroupLockStateButtons(LockStateGroup group, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GroupLockStateButtons)
};