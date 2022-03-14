#include "widget_Randomization_ButtonForUnlockingAllStepsInSeqTrack.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"



ButtonForUnlockingAllStepsInSeqTrack::ButtonForUnlockingAllStepsInSeqTrack(int trackNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	trackNum{ trackNum },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllStepsInSeqTrack::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the steps in sequencer track " + (String)trackNum + ".";
	return buttonTooltip;
}

void ButtonForUnlockingAllStepsInSeqTrack::onClickMethod() {
	randomizationComponent->unlockAllStepsInSeqTrack(trackNum);
}
