#include "widget_ButtonForSendingEditBufferDataMessage.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_EditBufferDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForSendingEditBufferDataMessage::ButtonForSendingEditBufferDataMessage(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Write.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSendingEditBufferDataMessage::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Writes the plugin" + GUI::apostrophe + "s current program settings\n";
		buttonTooltip += "into the Mopho hardware" + GUI::apostrophe + "s program edit buffer.";
	}
	return buttonTooltip;
}

void ButtonForSendingEditBufferDataMessage::onClickMethod() {
	EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
}

