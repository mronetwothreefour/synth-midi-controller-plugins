#include "widget_Randomization_ButtonForUnlockingAllLPFparameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllLPFparameters::ButtonForUnlockingAllLPFparameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllLPFparameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Unlocks all the parameters related to\n";
		buttonTooltip += "the low-pass filter and its envelope.";
	}
	return buttonTooltip;
}

void ButtonForUnlockingAllLPFparameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLPFparameters(randomizationComponent, false);
}
