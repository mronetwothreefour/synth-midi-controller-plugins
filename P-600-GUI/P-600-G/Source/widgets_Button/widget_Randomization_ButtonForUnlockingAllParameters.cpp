#include "widget_Randomization_ButtonForUnlockingAllParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/randomizationComponent.h"



ButtonForUnlockingAllParameters::ButtonForUnlockingAllParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_LockNone.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the program parameters.";
	return buttonTooltip;
}

void ButtonForUnlockingAllParameters::onClickMethod() {
	randomizationComponent->unlockAllParameters();
}
