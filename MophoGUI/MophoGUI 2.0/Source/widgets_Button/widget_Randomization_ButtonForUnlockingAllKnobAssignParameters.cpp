#include "widget_Randomization_ButtonForUnlockingAllKnobAssignParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllKnobAssignParameters::ButtonForUnlockingAllKnobAssignParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllKnobAssignParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the knob assignment parameters.";
	return buttonTooltip;
}

void ButtonForUnlockingAllKnobAssignParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllKnobAssignParameters(randomizationComponent, false);
}
