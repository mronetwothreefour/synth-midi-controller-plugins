#include "widget_Voices_ButtonForPullingEntireBankFromHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingEntireBankFromHardware::ButtonForPullingEntireBankFromHardware(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::custom1)
		setComponentID(ID::button_PullCustomBank1.toString());
	if (bank == VoicesBank::custom2)
		setComponentID(ID::button_PullCustomBank2.toString());
	if (bank == VoicesBank::custom3)
		setComponentID(ID::button_PullCustomBank3.toString());
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

