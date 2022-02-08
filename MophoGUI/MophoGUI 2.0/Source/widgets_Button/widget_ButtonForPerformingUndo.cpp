#include "widget_ButtonForPerformingUndo.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPerformingUndo::ButtonForPerformingUndo(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Undo.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPerformingUndo::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Click this button (or type Ctrl+Z) to\n";
		buttonTooltip += "undo the previous parameter change.";
	}
	return buttonTooltip;
}

void ButtonForPerformingUndo::onClickMethod() {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->undo();
}

