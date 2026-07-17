#include "widget_voices_ButtonForPullingEntireBankFromHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingEntireBankFromHardware::ButtonForPullingEntireBankFromHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingEntireBankFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Pull all the programs stored in the Prophet-600\n";
		buttonTooltip += "hardware into the plugin storage bank. NOTE: The\n";
		buttonTooltip += "Prophet-600 does not store program names, so the\n";
		buttonTooltip += "names displayed in the slots will be deleted.";
	}
	return buttonTooltip;
}

void ButtonForPullingEntireBankFromHardware::onClickMethod() {
}
