#include "widget_voices_ButtonForSavingVoiceIntoSelectedSlot.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ButtonForSavingVoiceIntoSelectedSlot::ButtonForSavingVoiceIntoSelectedSlot(VoiceSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams },
	nameEditor{ nameEditor }
{
	setComponentID(ID::button_Save.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSavingVoiceIntoSelectedSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Saves the plugin GUI" + GUI::apostrophe + "s current settings in the\n";
		buttonTooltip += "selected program storage slot, both in this\n";
		buttonTooltip += "storage bank and in the Prophet-600 hardware.\n";
		buttonTooltip += "NOTE: This will overwrite the data stored in\n";
		buttonTooltip += "the hardware and cannot be undone. There will\n";
		buttonTooltip += "then be a prompt to change the program" + GUI::apostrophe + "s name.";
	}
	return buttonTooltip;
}

void ButtonForSavingVoiceIntoSelectedSlot::onClickMethod() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		voiceTransmissionOptions->setCurrentVoiceNumber(slot);
		slotsComponent.storeCurrentVoiceDataSettingsInSelectedSlot();
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this, slot]
			{
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(MIDI::channel, (int)slot);
				auto editor_x{ GUI::voiceNameEditorLabel_horizInset + (slot / 10 * GUI::voiceSlotRadioButton_w) };
				auto editor_y{ GUI::voiceSlotsComponent_y + (slot % 10 * GUI::voiceSlotRadioButton_h) };
				nameEditor.setBounds(editor_x, editor_y, GUI::voiceNameEditorLabel_w, GUI::voiceSlotRadioButton_h);
				nameEditor.showEditor();
			}
		);
	}
}

void ButtonForSavingVoiceIntoSelectedSlot::timerCallback() {
}
