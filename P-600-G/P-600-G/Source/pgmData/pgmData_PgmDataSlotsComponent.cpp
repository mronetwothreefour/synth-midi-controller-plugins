#include "pgmData_PgmDataSlotsComponent.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_ProgramDataDump.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ProgramDataSlotsComponent::ProgramDataSlotsComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ pgmData::numberOfSlotsInPgmDataBank }
{
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	for (uint8 slot = 0; slot != pgmData::numberOfSlotsInPgmDataBank; ++slot) {
		setUpPgmDataSlotToggleButton(slot);
		addAndMakeVisible(pgmDataSlotButtons[slot]);
	}

	pgmDataBank->addListenerToPgmDataHexStrings(this);

	setSize(GUI::pgmDataSlotsComponent_w, GUI::pgmDataSlotsComponent_h);
}

void ProgramDataSlotsComponent::setUpPgmDataSlotToggleButton(uint8 slot) {
	pgmDataSlotButtons[slot].setComponentID(ID::button_PgmDataSlotRadioButton.toString());
	pgmDataSlotButtons[slot].setRadioGroupId(1);
	pgmDataSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForPgmDataSlotToggleButton(slot);
	setTextForPgmDataSlotToggleButton(slot);
}

void ProgramDataSlotsComponent::setTooltipForPgmDataSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescriptions()) {
		slotTooltip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons above.\n";
		slotTooltip += "CTRL-C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
		slotTooltip += "CTRL-V overwrites the selected program with the settings in the clipboard.";
	}
	pgmDataSlotButtons[slot].setTooltip(slotTooltip);
}

void ProgramDataSlotsComponent::setTextForPgmDataSlotToggleButton(uint8 slot) {
	jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
	String slotNumber;
	if (slot < 10)
		slotNumber = "0" + (String)(slot);
	else
		slotNumber = (String)(slot);
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	auto pgmName{ pgmDataBank->nameOfPgmInSlot(slot) };
	pgmDataSlotButtons[slot].setName(slotNumber + "  " + pgmName);
	pgmDataSlotButtons[slot].repaint();
}

void ProgramDataSlotsComponent::storeCurrentPgmDataSettingsInSelectedSlot() {
	if (selectedSlot < pgmData::numberOfSlotsInPgmDataBank) {
		auto dataVector{ RawSysExDataVector::initializePgmDataDumpMessage(selectedSlot) };
		RawDataTools::addCurrentExposedParamsSettingsToDataVector(exposedParams, dataVector);
		dataVector.erase(dataVector.begin(), dataVector.begin() + MIDI::numberOfHeaderBytesInPgmDataDump);
		auto pgmDataHexString{ RawDataTools::convertPgmDataVectorToHexString(dataVector) };
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		pgmDataBank->storePgmDataHexStringInSlot(pgmDataHexString, selectedSlot);
		setTextForPgmDataSlotToggleButton(selectedSlot);
		repaint();
		callAfterDelay(100, [this] { ProgramDataDump::addPgmDataDumpForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void ProgramDataSlotsComponent::loadPgmDataFromSelectedSlot() {
	if (selectedSlot < pgmData::numberOfSlotsInPgmDataBank) {
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		auto pgmDataHexString{ pgmDataBank->getPgmDataHexStringFromSlot(selectedSlot) };
		auto pgmDataVector{ RawDataTools::convertPgmDataHexStringToDataVector(pgmDataHexString) };
		RawDataTools::applyPgmDataVectorToGUI(selectedSlot, pgmDataVector, exposedParams, unexposedParams);
		callAfterDelay(100, [this] { ProgramDataDump::addPgmDataDumpForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void ProgramDataSlotsComponent::pullSelectedPgmDataFromHardware() {
	if (selectedSlot < pgmData::numberOfSlotsInPgmDataBank) {
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
		pgmDataOptions->setIncomingPgmDataDumpShouldBeSavedInStorageBank();
		ProgramDataDump::addRequestForPgmDataStoredInHardwareSlotToOutgoingMidiBuffers(selectedSlot, outgoingBuffers);
	}
}

void ProgramDataSlotsComponent::resized() {
	for (auto i = 0; i != pgmData::numberOfSlotsInPgmDataBank; ++i) {
		auto col_x{ (i / 10) * GUI::pgmDataSlotRadioButton_w };
		auto row_y{ (i % 10) * GUI::pgmDataSlotRadioButton_h };
		pgmDataSlotButtons[i].setBounds(col_x, row_y, GUI::pgmDataSlotRadioButton_w, GUI::pgmDataSlotRadioButton_h);
	}
}

void ProgramDataSlotsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	if (propertyName.startsWith("pgm")) {
		auto slotString{ propertyName.fromLastOccurrenceOf("pgm", false, true) };
		setTextForPgmDataSlotToggleButton((uint8)slotString.getIntValue());
	}
}

void ProgramDataSlotsComponent::timerCallback() {
}

ProgramDataSlotsComponent::~ProgramDataSlotsComponent() {
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	pgmDataBank->removeListenerFromPgmDataHexStrings(this);
}
