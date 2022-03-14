#include "widget_Randomization_ButtonForUnlockingAllSeqTrackParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllSeqTrackParameters::ButtonForUnlockingAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	trackNum{ trackNum },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllSeqTrackParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks the destination and all steps for sequencer track " + (String)trackNum + ".";
	return buttonTooltip;
}

void ButtonForUnlockingAllSeqTrackParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::unlockAllSeqTrackParameters(trackNum, randomizationComponent);
}
