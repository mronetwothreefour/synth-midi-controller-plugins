#include "midi_PatchDataMessage.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_MidiOptions.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



void PatchDataMessage::addDataMessageForCurrentPatchToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto patchDataMessage{ createSysExMessageFromCurrentPatchSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(patchDataMessage);
}

void PatchDataMessage::addDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(PatchBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto patchDataMessage{ createSysExMessageFromPatchDataStoredInBankAndSlot(bank, slot, unexposedParams) };
    outgoingBuffers->addDataMessage(patchDataMessage);
}

void PatchDataMessage::addRequestForPatchDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    auto patchRequestMessage{ RawSysExDataVector::createPatchDataRequestMessage(slot) };
    outgoingBuffers->addDataMessage(patchRequestMessage);
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchNumber{ currentPatchOptions->currentPatchNumber() };
    auto dataVector{ RawSysExDataVector::initializePatchDataMessage(currentPatchNumber) };
	RawDataTools::addCurrentParameterSettingsToDataVector(exposedParams, unexposedParams, dataVector);
    return dataVector;
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromPatchDataStoredInBankAndSlot(PatchBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::createPatchDataMessageHeader(slot) };
    auto patchBanks{ unexposedParams->patchBanks_get() };
    auto patchDataHexString{ patchBanks->getPatchDataHexStringFromBankSlot(bank, slot) };
    auto patchDataVector{ RawDataTools::convertPatchOrSplitHexStringToDataVector(patchDataHexString) };
    for (auto dataByte : patchDataVector)
        dataVector.push_back(dataByte);
    return dataVector;
}
