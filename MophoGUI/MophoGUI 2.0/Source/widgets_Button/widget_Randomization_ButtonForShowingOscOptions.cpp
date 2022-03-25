#include "widget_Randomization_ButtonForShowingOscOptions.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingOscRandomizationOptions::ButtonForShowingOscRandomizationOptions(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_RandomizationRestrictions.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingOscRandomizationOptions::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a dialog where you can restrict\n";
		buttonTooltip += "the randomization of the oscillator\n";
		buttonTooltip += "pitches to specific notes and octaves.";
	}
	return buttonTooltip;
}

void ButtonForShowingOscRandomizationOptions::onClickMethod() {
}
