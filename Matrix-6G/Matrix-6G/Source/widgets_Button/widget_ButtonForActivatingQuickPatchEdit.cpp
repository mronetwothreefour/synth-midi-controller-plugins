#include "widget_ButtonForActivatingQuickPatchEdit.h"

#include "../gui/gui_Colors.h"
#include "../midi/midi_QuickPatchEditing.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForActivatingQuickPatchEdit::ButtonForActivatingQuickPatchEdit(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "", unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_QuickEdit.toString());
	setColour(ColourIds::buttonColourId, Color::button_red);
	setTooltip(createButtonTooltipString());
}

const String ButtonForActivatingQuickPatchEdit::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "The Matrix must be set to Quick Patch Edit mode in order\n";
		buttonTooltip += "for it to respond to remote parameter changes. Click this\n";
		buttonTooltip += "button before making any edits in the GUI (the hardware's\n";
		buttonTooltip += "front panel display should switch to PATCH EDIT).";
	}
	return buttonTooltip;
}

void ButtonForActivatingQuickPatchEdit::onClickMethod() {
	QuickPatchEditing::sendActivateMessageToUnexposedParamsForHandling(unexposedParams);
}
