#include "widget_Randomization_ButtonForLockingAllStepsInSeqTrack.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/randomizationComponent.h"



ButtonForLockingAllStepsInSeqTrack::ButtonForLockingAllStepsInSeqTrack(int trackNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	trackNum{ trackNum },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllStepsInSeqTrack::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the steps in sequencer track " + (String)trackNum +".";
	return buttonTooltip;
}

void ButtonForLockingAllStepsInSeqTrack::onClickMethod() {
	randomizationComponent->lockAllStepsInSeqTrack(trackNum);
}
