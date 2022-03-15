#include "widget_Randomization_ButtonForLockingAllVCAparameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllVCAparameters::ButtonForLockingAllVCAparameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllVCAparameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Locks all the parameters related to the\n";
		buttonTooltip += "voltage-controlled amplifier and its envelope.";
	}
	return buttonTooltip;
}

void ButtonForLockingAllVCAparameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVCAparameters(randomizationComponent, true);
}
