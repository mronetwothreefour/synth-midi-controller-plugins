#include "widget_splits_ButtonForPullingEntireBankFromHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingEntireSplitsBankFromHardware::ButtonForPullingEntireSplitsBankFromHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullSplitsBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingEntireSplitsBankFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull all the splits stored in the Matrix-6R\n";
		buttonTooltip += "hardware into this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingEntireSplitsBankFromHardware::onClickMethod() {
}
