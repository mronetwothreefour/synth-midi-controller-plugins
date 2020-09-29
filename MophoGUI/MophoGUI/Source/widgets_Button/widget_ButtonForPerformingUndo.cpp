#include "widget_ButtonForPerformingUndo.h"

#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPerformingUndo::ButtonForPerformingUndo(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "UNDO", unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForPerformingUndo::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Click to undo the previous parameter change.";
	}
	return buttonTooltip;
}

void ButtonForPerformingUndo::onClickMethod() {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->undo();
}

