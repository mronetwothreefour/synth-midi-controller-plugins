#include "widget_Randomization_ButtonForLockingAllEnv3Parameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllEnv3Parameters::ButtonForLockingAllEnv3Parameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllEnv3Parameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the parameters related to envelope 3.";
	return buttonTooltip;
}

void ButtonForLockingAllEnv3Parameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllEnv3Parameters(randomizationComponent, true);
}
