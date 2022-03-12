#include "widget_ButtonForShowingRandomizationComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingRandomizationComponent::ButtonForShowingRandomizationComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Random.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingRandomizationComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a dialog where you can apply random\n";
		buttonTooltip += "settings to specified program parameters.";
	}
	return buttonTooltip;
}

void ButtonForShowingRandomizationComponent::onClickMethod() {
}
