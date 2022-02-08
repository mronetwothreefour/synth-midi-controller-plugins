#include "widget_splits_ButtonForPushingEntireBankToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingEntireSplitBankToHardware::ButtonForPushingEntireSplitBankToHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PushSplitsBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingEntireSplitBankToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push all the splits stored in this bank to\n";
		buttonTooltip += "the Matrix hardware's storage bank. NOTE: All\n";
		buttonTooltip += "the split data stored in the hardware will be\n";
		buttonTooltip += "overwritten and this cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForPushingEntireSplitBankToHardware::onClickMethod() {
}
