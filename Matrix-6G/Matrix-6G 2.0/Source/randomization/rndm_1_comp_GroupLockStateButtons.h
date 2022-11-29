#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class ParamRandomizationOptions;
class TooltipsOptions;

class GroupLockStateButtons :
	public Component,
	public Value::Listener
{
	LockStateGroup group;
	ParamRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	TextButton btn_Lock;
	TextButton btn_Unlock;
	Value transmitMethodIsQuickEditAsValue;

public:
	GroupLockStateButtons() = delete;

	GroupLockStateButtons(LockStateGroup group, ParamRandomizationOptions* randomization, TooltipsOptions* tooltips);
	void updateTooltips();
	void valueChanged(Value& value) override;
	~GroupLockStateButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GroupLockStateButtons)
};