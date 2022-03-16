#include "widget_Randomization_ButtonForLockingAllModulatorParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllModulatorParameters::ButtonForLockingAllModulatorParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllModulatorParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Locks all the parameters related\n";
		buttonTooltip += "to the four modulators.";
	}
	return buttonTooltip;
}

void ButtonForLockingAllModulatorParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllModulatorParameters(randomizationComponent, true);
}
