#include "widget_PgmBank_ButtonForLoadingSelectedPgm.h"

#include "../midi/midi_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ButtonForLoadingSelectedProgram::ButtonForLoadingSelectedProgram(VoiceSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Load.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLoadingSelectedProgram::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Applies the program settings stored in the selected slot\n";
		buttonTooltip += "to the plugin GUI and pushes them to the corresponding\n";
		buttonTooltip += "hardware storage slot. NOTE: This overwrites the program\n";
		buttonTooltip += "data in the hardware storage slot and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForLoadingSelectedProgram::onClickMethod() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		slotsComponent.loadVoiceFromSelectedSlot();
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this, slot]
			{
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(MIDI::channel, slot);
			}
		);
	}
}

void ButtonForLoadingSelectedProgram::timerCallback() {
}
