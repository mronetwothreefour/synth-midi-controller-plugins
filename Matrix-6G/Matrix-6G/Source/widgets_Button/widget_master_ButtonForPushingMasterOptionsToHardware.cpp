#include "widget_master_ButtonForPushingMasterOptionsToHardware.h"

#include "../master/master_Constants.h"
#include "../midi/midi_MasterOptionsDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPushingMasterOptionsToHardware::ButtonForPushingMasterOptionsToHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PushMasterOptions.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingMasterOptionsToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push all the current Master\n";
		buttonTooltip += "settings to the hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingMasterOptionsToHardware::onClickMethod() {
	MasterOptionsDataMessage::addDataMessageForMasterOptionsToOutgoingMidiBuffers(unexposedParams);
}
