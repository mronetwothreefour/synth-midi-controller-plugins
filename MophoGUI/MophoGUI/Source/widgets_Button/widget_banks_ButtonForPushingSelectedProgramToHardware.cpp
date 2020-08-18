#include "widget_banks_ButtonForPushingSelectedProgramToHardware.h"

#include "../banks/banks_ProgramSlotsWidget.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingSelectedProgramToHardware::ButtonForPushingSelectedProgramToHardware(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "PUSH", unexposedParams },
	programSlots{ programSlots },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingSelectedProgramToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push the data in the selected program storage slot\n";
		buttonTooltip += "to the corresponding storage slot in the Mopho hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingSelectedProgramToHardware::onClickMethod() {
	programSlots.pushSelectedProgramToHardware();
}

ButtonForPushingSelectedProgramToHardware::~ButtonForPushingSelectedProgramToHardware() {
}
