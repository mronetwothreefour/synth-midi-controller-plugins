#include "widget_ButtonForPushingVoiceToHardwareStorageSlot.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPushingVoiceToHardwareStorageSlot::ButtonForPushingVoiceToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PushSelectedVoice.toString());
}

const String ButtonForPushingVoiceToHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Sends the current program settings to the hardware\n";
		buttonTooltip += "storage slot specified by the program number control\n";
		buttonTooltip += "to the left. NOTE: This overwrites the data that is\n";
		buttonTooltip += "currently stored in the slot and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForPushingVoiceToHardwareStorageSlot::onClickMethod() {
	VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams);
	callAfterDelay(10, [this]
		{
			auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
			auto voiceSlot{ voiceTransmissionOptions->currentVoiceNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, voiceSlot);
		}
	);
}

void ButtonForPushingVoiceToHardwareStorageSlot::timerCallback() {
}
