#pragma once

#include <JuceHeader.h>

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace Matrix_6G_Constants;

class LockToggle_ExposedParam :
	public ToggleButton,
	public Value::Listener
{
	uint8 paramIndex;
	Value paramIsLockedAsValue;

public:
	LockToggle_ExposedParam() = delete;

	LockToggle_ExposedParam(uint8 paramIndex, ExposedParameters* exposedParams) :
		paramIndex{ paramIndex },
		paramIsLockedAsValue{ exposedParams->randomization->getParamIsLockedAsValue(paramIndex) }
	{
		jassert(paramIndex < EP::numberOfExposedParams);

		paramIsLockedAsValue.addListener(this);

		setComponentID(ID::comp_ToggleLockExposedParam_.toString() + (String)paramIndex);
		setToggleState(exposedParams->randomization->paramIsLocked(paramIndex), dontSendNotification);
		auto toggle_w{ exposedParams->info->widthFor(paramIndex) };
		setSize(toggle_w, GUI::control_h);

	}

	void valueChanged(Value& /*value*/) override {
		setToggleState((bool)paramIsLockedAsValue.getValue(), dontSendNotification);
	}

	~LockToggle_ExposedParam() {
		paramIsLockedAsValue.removeListener(this);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LockToggle_ExposedParam)
};