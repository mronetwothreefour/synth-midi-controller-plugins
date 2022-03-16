#include "widget_Randomization_ButtonForUnlockingAllEnv3Parameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllEnv3Parameters::ButtonForUnlockingAllEnv3Parameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllEnv3Parameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the parameters related to envelope 3.";
	return buttonTooltip;
}

void ButtonForUnlockingAllEnv3Parameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllEnv3Parameters(randomizationComponent, false);
}
