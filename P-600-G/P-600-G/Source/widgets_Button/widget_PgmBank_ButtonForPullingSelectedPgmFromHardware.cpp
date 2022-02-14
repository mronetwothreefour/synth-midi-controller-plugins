#include "widget_PgmBank_ButtonForPullingSelectedPgmFromHardware.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;




ButtonForPullingSelectedProgramFromHardware::ButtonForPullingSelectedProgramFromHardware(VoiceSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams },
	nameEditor{ nameEditor }
{
	setComponentID(ID::button_PullSelectedVoice.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedProgramFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Pull the data from the selected program storage slot in the\n";
		buttonTooltip += "Prophet-600 hardware and save it in the corresponding slot in\n";
		buttonTooltip += "the plugin storage bank. There will then be a prompt to name\n";
		buttonTooltip += "the program (the hardware does not store program names).";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedProgramFromHardware::onClickMethod() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		slotsComponent.pullSelectedVoiceFromHardware();
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this, slot]
			{
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(MIDI::channel, slot);
				auto editor_x{ GUI::voiceNameEditorLabel_horizInset + (slot / 10 * GUI::voiceSlotRadioButton_w) };
				auto editor_y{ GUI::voiceSlotsComponent_y + (slot % 10 * GUI::voiceSlotRadioButton_h) };
				nameEditor.setBounds(editor_x, editor_y, GUI::voiceNameEditorLabel_w, GUI::voiceSlotRadioButton_h);
				nameEditor.showEditor();
			}
		);
	}
}

void ButtonForPullingSelectedProgramFromHardware::timerCallback() {
}
