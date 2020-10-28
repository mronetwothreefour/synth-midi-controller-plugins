#include "widget_ButtonForPerformingRedo.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPerformingRedo::ButtonForPerformingRedo(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Redo.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPerformingRedo::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Click to redo a previously undone parameter change.";
	}
	return buttonTooltip;
}

void ButtonForPerformingRedo::onClickMethod() {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->redo();
}

