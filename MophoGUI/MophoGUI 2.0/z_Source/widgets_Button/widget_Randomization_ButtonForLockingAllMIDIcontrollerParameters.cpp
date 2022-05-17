#include "widget_Randomization_ButtonForLockingAllMIDIcontrollerParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllMIDIcontrollerParameters::ButtonForLockingAllMIDIcontrollerParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllMIDIcontrollerParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Locks all the parameters\n";
		buttonTooltip += "related to MIDI controllers.";
	}
	return buttonTooltip;
}

void ButtonForLockingAllMIDIcontrollerParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllMIDIcontrollerParameters(randomizationComponent, true);
}
