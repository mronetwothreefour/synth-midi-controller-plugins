#include "voices_VoiceSlotsComponent.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



VoiceSlotsComponent::VoiceSlotsComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ voices::numberOfSlotsInVoicesBank }
{
	auto voicesBank{ unexposedParams->voicesBank_get() };
	for (uint8 slot = 0; slot != voices::numberOfSlotsInVoicesBank; ++slot) {
		setUpVoiceSlotToggleButton(slot);
		addAndMakeVisible(voiceSlotButtons[slot]);
	}

	voicesBank->addListenerToVoiceDataHexStrings(this);

	setSize(GUI::voiceSlotsComponent_w, GUI::voiceSlotsComponent_h);
}

void VoiceSlotsComponent::setUpVoiceSlotToggleButton(uint8 slot) {
	voiceSlotButtons[slot].setComponentID(ID::button_VoiceDataSlotRadioButton.toString());
	voiceSlotButtons[slot].setRadioGroupId(1);
	voiceSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForVoiceSlotToggleButton(slot);
	setTextForVoiceSlotToggleButton(slot);
}

void VoiceSlotsComponent::setTooltipForVoiceSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescriptions()) {
		slotTooltip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons above.\n";
		slotTooltip += "CTRL-C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
		slotTooltip += "CTRL-V overwrites the selected program with the settings in the clipboard.";
	}
	voiceSlotButtons[slot].setTooltip(slotTooltip);
}

void VoiceSlotsComponent::setTextForVoiceSlotToggleButton(uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	String slotNumber;
	if (slot < 10)
		slotNumber = "0" + (String)(slot);
	else
		slotNumber = (String)(slot);
	auto voicesBank{ unexposedParams->voicesBank_get() };
	auto voiceName{ voicesBank->nameOfVoiceInSlot(slot) };
	MessageManagerLock mmLock;
	voiceSlotButtons[slot].setName(slotNumber + "  " + voiceName);
	voiceSlotButtons[slot].repaint();
}

void VoiceSlotsComponent::storeCurrentVoiceDataSettingsInSelectedSlot() {
	if (selectedSlot < voices::numberOfSlotsInVoicesBank) {
		auto dataVector{ RawSysExDataVector::initializeVoiceDataMessage(selectedSlot) };
		RawDataTools::addCurrentExposedParamsSettingsToDataVector(exposedParams, dataVector);
		dataVector.erase(dataVector.begin(), dataVector.begin() + MIDI::numberOfHeaderBytesInVoiceDataMessage);
		auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(dataVector) };
		auto voicesBank{ unexposedParams->voicesBank_get() };
		voicesBank->storeVoiceDataHexStringInSlot(voiceDataHexString, selectedSlot);
		setTextForVoiceSlotToggleButton(selectedSlot);
		repaint();
		callAfterDelay(100, [this] { VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void VoiceSlotsComponent::loadVoiceFromSelectedSlot() {
	if (selectedSlot < voices::numberOfSlotsInVoicesBank) {
		auto voicesBank{ unexposedParams->voicesBank_get() };
		auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyVoiceDataVectorToGUI(selectedSlot, voiceDataVector, exposedParams, unexposedParams);
		callAfterDelay(100, [this] { VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void VoiceSlotsComponent::pullSelectedVoiceFromHardware() {
	if (selectedSlot < voices::numberOfSlotsInVoicesBank) {
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInVoicesBank();
		VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(selectedSlot, outgoingBuffers);
	}
}

void VoiceSlotsComponent::resized() {
	for (auto i = 0; i != voices::numberOfSlotsInVoicesBank; ++i) {
		auto col_x{ (i / 10) * GUI::voiceSlotRadioButton_w };
		auto row_y{ (i % 10) * GUI::voiceSlotRadioButton_h };
		voiceSlotButtons[i].setBounds(col_x, row_y, GUI::voiceSlotRadioButton_w, GUI::voiceSlotRadioButton_h);
	}
}

void VoiceSlotsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	if (propertyName.startsWith("voice")) {
		auto slotString{ propertyName.fromLastOccurrenceOf("voice", false, true) };
		setTextForVoiceSlotToggleButton((uint8)slotString.getIntValue());
	}
}

void VoiceSlotsComponent::timerCallback() {
}

VoiceSlotsComponent::~VoiceSlotsComponent() {
	auto voicesBank{ unexposedParams->voicesBank_get() };
	voicesBank->removeListenerFromVoiceDataHexStrings(this);
}
