#include "widget_Randomization_ButtonForUnlockingAllVCAparameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllVCAparameters::ButtonForUnlockingAllVCAparameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllVCAparameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Unlocks all the parameters related to the\n";
		buttonTooltip += "voltage-controlled amplifier and its envelope.";
	}
	return buttonTooltip;
}

void ButtonForUnlockingAllVCAparameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVCAparameters(randomizationComponent, false);
}
