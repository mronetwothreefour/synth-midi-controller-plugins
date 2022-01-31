#include "widget_PgmBank_ButtonForPushingEntireBankToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingEntireBankToHardware::ButtonForPushingEntireBankToHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PushBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingEntireBankToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Push all the programs stored in the plugin bank to\n";
		buttonTooltip += "the Prophet-600 hardware's storage bank. NOTE:\n";
		buttonTooltip += "All the patch data stored in the hardware will be\n";
		buttonTooltip += "overwritten and this cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForPushingEntireBankToHardware::onClickMethod()
{
}
