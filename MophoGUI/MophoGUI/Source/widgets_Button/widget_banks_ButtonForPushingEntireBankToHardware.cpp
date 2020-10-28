#include "widget_banks_ButtonForPushingEntireBankToHardware.h"


#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingEntireBankToHardware::ButtonForPushingEntireBankToHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingEntireBankToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push all the programs stored in this bank to the\n";
		buttonTooltip += "corresponding storage bank in the Mopho hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingEntireBankToHardware::onClickMethod() {
}

