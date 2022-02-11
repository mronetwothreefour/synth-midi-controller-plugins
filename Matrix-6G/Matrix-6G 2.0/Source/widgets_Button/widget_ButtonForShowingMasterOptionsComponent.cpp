#include "widget_ButtonForShowingMasterOptionsComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForShowingMasterOptionsComponent::ButtonForShowingMasterOptionsComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Master.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingMasterOptionsComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can edit\n";
		buttonTooltip += ("the " + GUI::openQuote + "master" + GUI::closeQuote + " options which apply\n");
		buttonTooltip += "uniformly to all patches.";
	}
	return buttonTooltip;
}

void ButtonForShowingMasterOptionsComponent::onClickMethod() {
}
