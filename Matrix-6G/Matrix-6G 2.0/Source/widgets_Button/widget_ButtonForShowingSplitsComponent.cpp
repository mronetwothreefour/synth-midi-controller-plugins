#include "widget_ButtonForShowingSplitsComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForShowingSplitsComponent::ButtonForShowingSplitsComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Splits.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingSplitsComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can create and store\n";
		buttonTooltip += (GUI::openQuote + "splits," + GUI::closeQuote + " which allow you to play two patches\n");
		buttonTooltip += "at once with a single keyboard controller.";
	}
	return buttonTooltip;
}

void ButtonForShowingSplitsComponent::onClickMethod() {
}
