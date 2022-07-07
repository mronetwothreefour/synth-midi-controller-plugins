#include "rndm_0_comp_LockToggleForParam.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;



LockToggleForParam::LockToggleForParam(uint8 paramIndex, ExposedParameters* exposedParams) :
	paramIndex{ paramIndex }
{
	jassert(paramIndex < EP::numberOfExposedParams);

	auto controlType{ exposedParams->info->controlTypeFor(paramIndex) };
	switch (controlType)
	{
	case MophoConstants::ControlType::knob:
		setComponentID(ID::component_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
		break;
	case MophoConstants::ControlType::knobForPitch:
		setComponentID(ID::component_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
		break;
	case MophoConstants::ControlType::knobForOscShape:
		setComponentID(ID::component_ToggleLock_Knob_Param_.toString() + (String)paramIndex);
		setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
		break;
	case MophoConstants::ControlType::toggleButton:
		setComponentID(ID::component_ToggleLock_Toggle_Param_.toString() + (String)paramIndex);
		setSize(GUI::toggleLockButton_diameter, GUI::toggleLockButton_diameter);
		break;
	case MophoConstants::ControlType::comboBox:
		setComponentID(ID::component_ToggleLock_ComboBox_Param_.toString() + (String)paramIndex);
		setSize(exposedParams->info->widthFor(paramIndex), GUI::lockAndUnlockIcons_h);
		break;
	case MophoConstants::ControlType::seqTrackStep:
		setComponentID(ID::component_ToggleLock_SeqStep_Param_.toString() + (String)paramIndex);
		setSize(GUI::seqSteps_w, GUI::seqSteps_h);
		break;
	case MophoConstants::ControlType::voiceNameChar:
		setComponentID(ID::component_ToggleLock_VoiceNameChar_Param_.toString() + (String)paramIndex);
		setSize(GUI::voiceNameCharacters_w, GUI::voiceNameCharacters_h);
		break;
	default:
		break;
	}
	setToggleState(exposedParams->randomization->paramIsLocked(paramIndex), dontSendNotification);
}

