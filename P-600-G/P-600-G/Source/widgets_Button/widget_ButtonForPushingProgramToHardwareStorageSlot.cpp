#include "widget_ButtonForPushingProgramToHardwareStorageSlot.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForPushingProgramToHardwareStorageSlot::ButtonForPushingProgramToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PushSelectedProgram.toString());
}

const String ButtonForPushingProgramToHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Sends a dump of all the program data to the hardware storage\n";
		buttonTooltip += "slot specified by the program number control to the left.\n";
		buttonTooltip += "This overwrites the data that is currently stored in the slot.";
	}
	return buttonTooltip;
}

void ButtonForPushingProgramToHardwareStorageSlot::onClickMethod() {
}

void ButtonForPushingProgramToHardwareStorageSlot::timerCallback() {
}
