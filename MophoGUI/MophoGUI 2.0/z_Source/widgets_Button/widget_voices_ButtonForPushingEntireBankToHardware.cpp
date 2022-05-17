#include "widget_voices_ButtonForPushingEntireBankToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingEntireBankToHardware::ButtonForPushingEntireBankToHardware(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::factory1)
		setComponentID(ID::button_PushFactoryBank1.toString());
	if (bank == VoicesBank::factory2)
		setComponentID(ID::button_PushFactoryBank2.toString());
	if (bank == VoicesBank::factory3)
		setComponentID(ID::button_PushFactoryBank3.toString());
	if (bank == VoicesBank::custom1)
		setComponentID(ID::button_PushCustomBank1.toString());
	if (bank == VoicesBank::custom2)
		setComponentID(ID::button_PushCustomBank2.toString());
	if (bank == VoicesBank::custom3)
		setComponentID(ID::button_PushCustomBank3.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingEntireBankToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Push all the programs stored in this bank to the\n";
		buttonTooltip += "corresponding storage bank in the Mopho hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingEntireBankToHardware::onClickMethod() {
}

