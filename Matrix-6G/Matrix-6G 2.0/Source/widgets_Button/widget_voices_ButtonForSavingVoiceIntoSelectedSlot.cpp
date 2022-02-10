#include "widget_voices_ButtonForSavingVoiceIntoSelectedSlot.h"

#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForSavingVoiceIntoSelectedSlot::ButtonForSavingVoiceIntoSelectedSlot(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Save.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSavingVoiceIntoSelectedSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Saves the plugin GUI's current settings\n";
		buttonTooltip += "in the selected patch storage slot, both\n";
		buttonTooltip += "in this storage bank and in the Matrix-6R\n";
		buttonTooltip += "hardware. NOTE: This will overwrite the data\n";
		buttonTooltip += "stored in the hardware and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForSavingVoiceIntoSelectedSlot::onClickMethod() {
	if (voiceSlots.selectedSlot < voices::numberOfSlotsInBank) {
		voiceSlots.storeCurrentVoiceSettingsInSelectedSlot();
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this]
			{
				auto masterOptions{ unexposedParams->masterOptions_get() };
				auto basicChannel{ masterOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, (int)voiceSlots.selectedSlot);
			}
		);
	}
}

void ButtonForSavingVoiceIntoSelectedSlot::timerCallback() {
}
