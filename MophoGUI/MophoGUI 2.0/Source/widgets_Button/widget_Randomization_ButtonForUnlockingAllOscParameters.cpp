#include "widget_Randomization_ButtonForUnlockingAllOscParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllOscParameters::ButtonForUnlockingAllOscParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllOscParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the parameters related to the two oscillators.";
	return buttonTooltip;
}

void ButtonForUnlockingAllOscParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::unlockAllOscillatorParameters(randomizationComponent);
}
