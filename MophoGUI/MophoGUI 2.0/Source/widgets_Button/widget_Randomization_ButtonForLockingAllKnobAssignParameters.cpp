#include "widget_Randomization_ButtonForLockingAllKnobAssignParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllKnobAssignParameters::ButtonForLockingAllKnobAssignParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllKnobAssignParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the knob assignment parameters.";
	return buttonTooltip;
}

void ButtonForLockingAllKnobAssignParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllKnobAssignParameters(randomizationComponent, true);
}
