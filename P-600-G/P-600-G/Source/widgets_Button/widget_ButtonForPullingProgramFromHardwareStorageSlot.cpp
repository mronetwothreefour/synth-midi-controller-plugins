#include "widget_ButtonForPullingProgramFromHardwareStorageSlot.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"





ButtonForPullingProgramFromHardwareStorageSlot::ButtonForPullingProgramFromHardwareStorageSlot(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PullSelectedProgram.toString());
}

const String ButtonForPullingProgramFromHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from a program storage slot in the\n";
		buttonTooltip += "Prophet-600 hardware (specified by the program number\n";
		buttonTooltip += "control to the left) and apply it to the plugin GUI.";
	}
	return buttonTooltip;
}

void ButtonForPullingProgramFromHardwareStorageSlot::onClickMethod() {
}

void ButtonForPullingProgramFromHardwareStorageSlot::timerCallback() {
}
