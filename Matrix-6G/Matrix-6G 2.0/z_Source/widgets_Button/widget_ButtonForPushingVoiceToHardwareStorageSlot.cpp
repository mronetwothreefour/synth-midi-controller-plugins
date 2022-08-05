#include "widget_ButtonForPushingVoiceToHardwareStorageSlot.h"

#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForPushingVoiceToHardwareStorageSlot::ButtonForPushingVoiceToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_Push.toString());
}

const String ButtonForPushingVoiceToHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Sends a dump of the current patch data to the hardware storage\n";
		buttonTooltip += "slot specified by the patch number control to the right,\n";
		buttonTooltip += "overwriting the data that is currently stored in the slot.";
	}
	return buttonTooltip;
}

void ButtonForPushingVoiceToHardwareStorageSlot::onClickMethod() {
	VoiceDataMessage::addDataMessageForCurrentVoiceToOutgoingMidiBuffers(exposedParams, unexposedParams);
	callAfterDelay(10, [this]
		{
			auto globalOptions{ unexposedParams->globalOptions_get() };
			auto basicChannel{ globalOptions->basicChannel() };
			auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
			auto voiceSlot{ currentVoiceOptions->currentVoiceNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(basicChannel, voiceSlot);
		}
	);
}

void ButtonForPushingVoiceToHardwareStorageSlot::timerCallback() {
}
