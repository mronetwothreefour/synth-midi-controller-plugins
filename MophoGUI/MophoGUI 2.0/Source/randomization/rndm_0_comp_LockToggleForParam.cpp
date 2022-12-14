#include "rndm_0_comp_LockToggleForParam.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;

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
		setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
		break;
	case ControlType::knobForPitch:
		setComponentID(ID::comp_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
		break;
	case ControlType::knobForOscShape:
		setComponentID(ID::comp_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
		break;
	case ControlType::toggleButton:
		setComponentID(ID::comp_ToggleLock_Toggle_Param_.toString() + (String)paramIndex);
		setSize(GUI::toggleLockButton_diameter, GUI::toggleLockButton_diameter);
		break;
	case ControlType::comboBox:
		setComponentID(ID::comp_ToggleLock_ComboBox_Param_.toString() + (String)paramIndex);
		setSize(exposedParams->info->widthFor(paramIndex), GUI::lockAndUnlockIcons_h);
		break;
	case ControlType::seqTrackStep:
		setComponentID(ID::comp_ToggleLock_SeqStep_Param_.toString() + (String)paramIndex);
		setSize(GUI::seqSteps_w, GUI::seqSteps_h);
		break;
	case ControlType::voiceNameChar:
		setComponentID(ID::comp_ToggleLock_VoiceNameChar_Param_.toString() + (String)paramIndex);
		setSize(GUI::voiceNameChars_w, GUI::voiceNameChars_h);
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

