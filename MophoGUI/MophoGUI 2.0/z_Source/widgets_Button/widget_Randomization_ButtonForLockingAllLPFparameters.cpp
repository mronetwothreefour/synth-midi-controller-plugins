#include "widget_Randomization_ButtonForLockingAllLPFparameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllLPFparameters::ButtonForLockingAllLPFparameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllLPFparameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Locks all the parameters related to\n";
		buttonTooltip += "the low-pass filter and its envelope.";
	}
	return buttonTooltip;
}

void ButtonForLockingAllLPFparameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLPFparameters(randomizationComponent, true);
}
