#include "widget_Randomization_ButtonForLockingAllLFOparameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllLFOparameters::ButtonForLockingAllLFOparameters(int lfoNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllLFOparameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the parameters related to LFO " + (String)lfoNum + ".";
	return buttonTooltip;
}

void ButtonForLockingAllLFOparameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLFOparameters(lfoNum, randomizationComponent, true);
}
