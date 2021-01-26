#include "midi_PatchDataMessage.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../patches/patches_RawPatchData.h"

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
    auto patchRequestMessage{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::dataDumpRequest) };
    patchRequestMessage[2] = MIDI::opcode_DataRequest;
    patchRequestMessage[3] = MIDI::transmitCode_Patch;
    patchRequestMessage[4] = slot;
    outgoingBuffers->addDataMessage(patchRequestMessage);
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto dataVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::patchData) };
    dataVector[2] = MIDI::opcode_PatchData;
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchNumber{ currentPatchOptions->currentPatchNumber() };
    dataVector[3] = currentPatchNumber;
	RawPatchData::addCurrentParameterSettingsToDataVector(exposedParams, unexposedParams, dataVector);
    return dataVector;
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromPatchDataStoredInBankAndSlot(PatchBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto dataVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::patchData) };
    dataVector[2] = MIDI::opcode_PatchData;
    auto patchBanks{ unexposedParams->patchBanks_get() };
    auto patchDataHexString{ patchBanks->getPatchDataHexStringFromBankSlot(bank, slot) };
    auto patchDataVector{ RawPatchData::convertHexStringToDataVector(patchDataHexString) };
    for (auto dataByte : patchDataVector)
        dataVector.push_back(dataByte);
    return dataVector;
}
