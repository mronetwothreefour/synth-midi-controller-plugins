#include "widget_ButtonForShowingRandomizeComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForShowingRandomizeComponent::ButtonForShowingRandomizeComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Rand.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingRandomizeComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a window where you can apply random\n";
		buttonTooltip += "settings to specific program parameters.";
	}
	return buttonTooltip;
}

void ButtonForShowingRandomizeComponent::onClickMethod() {
}
