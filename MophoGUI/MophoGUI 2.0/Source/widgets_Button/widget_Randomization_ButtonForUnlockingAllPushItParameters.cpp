#include "widget_Randomization_ButtonForUnlockingAllPushItParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllPushItParameters::ButtonForUnlockingAllPushItParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllPushItParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the Push It! switch parameters.";
	return buttonTooltip;
}

void ButtonForUnlockingAllPushItParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllPushItParameters(randomizationComponent, false);
}
