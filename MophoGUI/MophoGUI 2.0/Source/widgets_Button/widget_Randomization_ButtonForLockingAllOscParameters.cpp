#include "widget_Randomization_ButtonForLockingAllOscParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllOscParameters::ButtonForLockingAllOscParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllOscParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the parameters related to the two oscillators.";
	return buttonTooltip;
}

void ButtonForLockingAllOscParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockAllOscillatorParameters(randomizationComponent);
}
