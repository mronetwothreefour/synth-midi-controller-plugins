#include "widget_banks_ButtonForPullingEntireBankFromHardware.h"

#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingEntireBankFromHardware::ButtonForPullingEntireBankFromHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingEntireBankFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull all the programs stored in the storage bank in\n";
		buttonTooltip += "the Mopho hardware into this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingEntireBankFromHardware::onClickMethod() {
}

