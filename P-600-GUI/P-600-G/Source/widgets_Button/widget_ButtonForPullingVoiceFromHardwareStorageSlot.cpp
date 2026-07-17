#include "widget_ButtonForPullingVoiceFromHardwareStorageSlot.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;





ButtonForPullingVoiceFromHardwareStorageSlot::ButtonForPullingVoiceFromHardwareStorageSlot(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PullSelectedVoice.toString());
}

const String ButtonForPullingVoiceFromHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Pull the data from a program storage slot in the\n";
		buttonTooltip += "Prophet-600 hardware (specified by the program number\n";
		buttonTooltip += "control to the left) and apply it to the plugin GUI.";
	}
	return buttonTooltip;
}

void ButtonForPullingVoiceFromHardwareStorageSlot::onClickMethod() {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	auto slot{ voiceTransmissionOptions->currentVoiceNumber() };
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(slot, outgoingMidiBuffers);
	auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
	callAfterDelay(transmitTime, [this, slot]
		{
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, slot);
		}
	);
}

void ButtonForPullingVoiceFromHardwareStorageSlot::timerCallback() {
}
