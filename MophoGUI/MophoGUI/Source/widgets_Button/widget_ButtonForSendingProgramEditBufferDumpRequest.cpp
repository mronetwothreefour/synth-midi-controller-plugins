#include "widget_ButtonForSendingProgramEditBufferDumpRequest.h"

#include "../midi/midi_ProgramEditBufferDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForSendingProgramEditBufferDumpRequest::ButtonForSendingProgramEditBufferDumpRequest(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Read.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSendingProgramEditBufferDumpRequest::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Requests a program edit buffer dump from the Mopho hardware\n";
		buttonTooltip += "and applies it to the plugin's program settings.";
	}
	return buttonTooltip;
}

void ButtonForSendingProgramEditBufferDumpRequest::onClickMethod() {
	ProgramEditBufferDump::addRequestForDumpToOutgoingMidiBuffers(unexposedParams->outgoingMidiBuffers_get());
}

