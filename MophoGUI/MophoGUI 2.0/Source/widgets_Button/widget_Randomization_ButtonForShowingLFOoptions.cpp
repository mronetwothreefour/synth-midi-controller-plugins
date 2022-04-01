#include "widget_Randomization_ButtonForShowingLFOoptions.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingLFOrandomizationOptions::ButtonForShowingLFOrandomizationOptions(int lfoNum, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_RandomizationRestrictions.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingLFOrandomizationOptions::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a dialog where you can restrict\n";
		buttonTooltip += "the randomization of LFO " + (String)lfoNum + "'s frequency\n";
		buttonTooltip += "to specific un-synced, pitched, and/or\n";
		buttonTooltip += "synced values.\n";
	}
	return buttonTooltip;
}

void ButtonForShowingLFOrandomizationOptions::onClickMethod() {
}
