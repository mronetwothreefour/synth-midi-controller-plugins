#include "widget_Randomization_ButtonForUnlockingAllModulatorParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllModulatorParameters::ButtonForUnlockingAllModulatorParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllModulatorParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Unlocks all the parameters\n";
		buttonTooltip += "related to the four modulators.";
	}
	return buttonTooltip;
}

void ButtonForUnlockingAllModulatorParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllModulatorParameters(randomizationComponent, false);
}
