#include "widget_Randomization_ButtonForLockingAllParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllParameters::ButtonForLockingAllParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_LockAll.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the program parameters.";
	return buttonTooltip;
}

void ButtonForLockingAllParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockAllParameters(randomizationComponent);
}
