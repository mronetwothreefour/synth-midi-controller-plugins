#include "widget_ButtonForSendingAllPatchData.h"

#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForSendingAllPatchData::ButtonForSendingAllPatchData(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_SendAll.toString());
}

const String ButtonForSendingAllPatchData::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Sends a dump of all the patch data to the hardware storage\n";
		buttonTooltip += "slot specified by the patch number control to the right,\n";
		buttonTooltip += "overwriting the data that is currently stored in the slot.";
	}
	return buttonTooltip;
}

void ButtonForSendingAllPatchData::onClickMethod() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	PatchDataMessage::sendCurrentPatchDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams, outgoingMidiBuffers);
}
