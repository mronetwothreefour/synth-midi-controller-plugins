#include "widget_ButtonForActivatingQuickPatchEdit.h"

#include "../midi/midi_QuickPatchEditing.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForActivatingQuickPatchEdit::ButtonForActivatingQuickPatchEdit(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_QuickEdit.toString());
	callAfterDelay(100, [this] { setComponentID(ID::button_QuickEdit_Flash.toString()); repaint(); });
	callAfterDelay(200, [this] { setComponentID(ID::button_QuickEdit.toString()); repaint(); });
	callAfterDelay(300, [this] { setComponentID(ID::button_QuickEdit_Flash.toString()); repaint(); });
	callAfterDelay(400, [this] { setComponentID(ID::button_QuickEdit.toString()); repaint(); });
	callAfterDelay(500, [this] { setComponentID(ID::button_QuickEdit_Flash.toString()); repaint(); });
	callAfterDelay(600, [this] { setComponentID(ID::button_QuickEdit.toString()); repaint(); });
	callAfterDelay(700, [this] { setComponentID(ID::button_QuickEdit_Flash.toString()); repaint(); });
	callAfterDelay(800, [this] { setComponentID(ID::button_QuickEdit.toString()); repaint(); });
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
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	QuickPatchEditing::sendActivateMessageToOutgoingMidiBuffers(outgoingMidiBuffers);
}

void ButtonForActivatingQuickPatchEdit::timerCallback() {
}
