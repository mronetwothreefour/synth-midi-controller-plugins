#include "widget_global_ButtonForPushingGlobalOptionsToHardware.h"

#include "../global/global_Constants.h"
#include "../midi/midi_GlobalOptionsDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPushingGlobalOptionsToHardware::ButtonForPushingGlobalOptionsToHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PushGlobalOptions.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingGlobalOptionsToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push all the current Master\n";
		buttonTooltip += "settings to the hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingGlobalOptionsToHardware::onClickMethod() {
	GlobalOptionsDataMessage::addDataMessageForGlobalOptionsToOutgoingMidiBuffers(unexposedParams);
}
