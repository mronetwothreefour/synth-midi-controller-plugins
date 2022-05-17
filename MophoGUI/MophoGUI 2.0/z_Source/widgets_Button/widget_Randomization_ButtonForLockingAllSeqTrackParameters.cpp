#include "widget_Randomization_ButtonForLockingAllSeqTrackParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForLockingAllSeqTrackParameters::ButtonForLockingAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	trackNum{ trackNum },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllSeqTrackParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks the destination and all steps for sequencer track " + (String)trackNum +".";
	return buttonTooltip;
}

void ButtonForLockingAllSeqTrackParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllSeqTrackParameters(trackNum, randomizationComponent, true);
}
