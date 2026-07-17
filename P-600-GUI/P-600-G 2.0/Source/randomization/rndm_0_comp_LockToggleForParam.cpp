#include "rndm_0_comp_LockToggleForParam.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace P_600_G_Constants;

LockToggleForParam::LockToggleForParam(uint8 paramIndex, ExposedParameters* exposedParams) :
	paramIndex{ paramIndex },
	paramIsLockedAsValue{ exposedParams->randomization->getParamIsLockedAsValue(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);

	paramIsLockedAsValue.addListener(this);

	auto controlType{ exposedParams->info->controlTypeFor(paramIndex) };
	switch (controlType)
	{
	case ControlType::knob:
		setComponentID(ID::comp_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knob_diameter, GUI::knob_diameter);
		break;
	case ControlType::knobForPitch:
		setComponentID(ID::comp_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knob_diameter, GUI::knob_diameter);
		break;
	case ControlType::twoPoleSwitch:
		setComponentID(ID::comp_ToggleLock_TwoPoleSwitch_Param_.toString() + (String)paramIndex);
		setSize(GUI::switch_w, GUI::switch_2_Pole_h);
		break;
	case ControlType::threePoleSwitch:
		setComponentID(ID::comp_ToggleLock_ThreePoleSwitch_Param_.toString() + (String)paramIndex);
		setSize(GUI::switch_w, GUI::switch_3_Pole_h);
		break;
	default:
		break;
	}
	setToggleState(exposedParams->randomization->paramIsLocked(paramIndex), dontSendNotification);
}

void LockToggleForParam::valueChanged(Value& /*value*/) {
	setToggleState((bool)paramIsLockedAsValue.getValue(), dontSendNotification);
}

LockToggleForParam::~LockToggleForParam() {
	paramIsLockedAsValue.removeListener(this);
}
