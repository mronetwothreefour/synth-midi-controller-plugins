#include "widget_ButtonForSendingEditBufferDataMessageRequest.h"

#include "../midi/midi_EditBufferDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForSendingEditBufferDataMessageRequest::ButtonForSendingEditBufferDataMessageRequest(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Read.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSendingEditBufferDataMessageRequest::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Requests a program edit buffer dump from the Mopho\n";
		buttonTooltip += "hardware and applies it to the plugin GUI.";
	}
	return buttonTooltip;
}

void ButtonForSendingEditBufferDataMessageRequest::onClickMethod() {
	EditBufferDataMessage::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(unexposedParams->outgoingMidiBuffers_get());
}

