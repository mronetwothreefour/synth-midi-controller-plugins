#include "voices_VoiceSlotsWidget.h"

#include "voices_Constants.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_ProgramDump.h"
#include "../midi/midi_ProgramEditBufferDump.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ProgramSlotsWidget::ProgramSlotsWidget(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ banks::numberOfSlotsInBank }
{
	auto programBanks{ unexposedParams->programBanks_get() };
	for (uint8 slot = 0; slot != banks::numberOfSlotsInBank; ++slot) {
		setUpProgramSlotToggleButton(slot);
		addAndMakeVisible(programSlotButtons[slot]);
	}

	if (bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3) {
		programBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	setSize(GUI::voiceSlotsWidget_w, GUI::voiceSlotsWidget_h);
}

void ProgramSlotsWidget::setUpProgramSlotToggleButton(uint8 slot) {
	programSlotButtons[slot].setComponentID(ID::component_VoiceSlotRadioButton.toString());
	programSlotButtons[slot].setRadioGroupId(1);
	programSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForProgramSlotToggleButton(slot);
	setTextForProgramSlotToggleButton(slot);
}

void ProgramSlotsWidget::setTooltipForProgramSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescription()) {
		slotTooltip += "Click a program's name to select it before using the buttons below.\n";
		slotTooltip += "CTRL+C copies the selected program's settings into the clipboard.\n";
		slotTooltip += "CTRL+V overwrites the selected program with the settings in the\n";
		slotTooltip += "clipboard (only slots in the Custom banks can be overwritten).";
	}
	programSlotButtons[slot].setTooltip(slotTooltip);
}

void ProgramSlotsWidget::setTextForProgramSlotToggleButton(uint8 slot) {
	String slotNumber;
	if (slot < 9) slotNumber = "00" + (String)(slot + 1);
	if (slot > 8 && slot < 99) slotNumber = "0" + (String)(slot + 1);
	if (slot > 98) slotNumber = (String)(slot + 1);
	auto programBanks{ unexposedParams->programBanks_get() };
	auto programName{ programBanks->nameOfProgramInBankSlot(bank, slot) };
	programSlotButtons[slot].setName(slotNumber + " " + programName);
	programSlotButtons[slot].repaint();
}

void ProgramSlotsWidget::storeCurrentProgramSettingsInSelectedSlot() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto programDataVector{ RawDataTools::extractFromExposedParameters(exposedParams) };
		auto programDataHexString{ RawDataTools::convertDataVectorToHexString(programDataVector) };
		auto programBanks{ unexposedParams->programBanks_get() };
		programBanks->storeProgramDataHexStringInCustomBankSlot(programDataHexString, bank, selectedSlot);
		setTextForProgramSlotToggleButton(selectedSlot);
		repaint();
	}
}

void ProgramSlotsWidget::loadProgramFromSelectedSlot() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto programBanks{ unexposedParams->programBanks_get() };
		auto programDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot) };
		auto programDataVector{ RawDataTools::convertHexStringToDataVector(programDataHexString) };
		RawDataTools::applyToExposedParameters(programDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { ProgramEditBufferDump::addDumpToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get()); });
	}
}

void ProgramSlotsWidget::pullSelectedProgramFromHardware() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto transmitTime{ midiOptions->programTransmitTime() };
		ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(bank, selectedSlot, outgoingBuffers);
		callAfterDelay(transmitTime, [this] { setTextForProgramSlotToggleButton(selectedSlot); });
		callAfterDelay(transmitTime + 20, [this] { programSlotButtons[selectedSlot].repaint(); });
	}
}

void ProgramSlotsWidget::pushSelectedProgramToHardware() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto dumpDataVector{ ProgramDump::createProgramDumpForBankAndSlot(bank, selectedSlot, unexposedParams) };
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		outgoingBuffers->addDataMessage(dumpDataVector);
	}
}

void ProgramSlotsWidget::resized() {
	for (auto i = 0; i != banks::numberOfSlotsInBank; ++i) {
		auto col_x{ (i / 16) * (GUI::voiceSlotRadioButtton_w + GUI::voiceSlotRadioButtonsHorizontalGap) };
		auto row_y{ (i % 16) * GUI::voiceSlotRadioButtton_h };
		programSlotButtons[i].setBounds(col_x, row_y, GUI::voiceSlotRadioButtton_w, GUI::voiceSlotRadioButtton_h);
	}
}

void ProgramSlotsWidget::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("pgm", false, true) };
	setTextForProgramSlotToggleButton((uint8)slotString.getIntValue());
}

void ProgramSlotsWidget::timerCallback() {
}

ProgramSlotsWidget::~ProgramSlotsWidget() {
	if (bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3) {
		auto programBanks{ unexposedParams->programBanks_get() };
		programBanks->removeListenerFromNameStringsForCustomBank(this, bank);
	}
}

