#include "midi_PatchDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../patches/patches_RawPatchData.h"



void PatchDataMessage::sendCurrentPatchDataMessageToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, OutgoingMidiBuffers* outgoingBuffers) {
    auto patchDataMessage{ createSysExMessageFromCurrentPatchSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(patchDataMessage);
}

void PatchDataMessage::sendDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(uint8 /*bank*/, uint8 /*slot*/, OutgoingMidiBuffers* /*outgoingBuffers*/) {
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto dataVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::patchData) };
    uint8 patchDataOpcode{ 1 };
    dataVector[2] = patchDataOpcode;
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchNumber{ currentPatchOptions->currentPatchNumber() };
    dataVector[3] = currentPatchNumber;
	RawPatchData::addCurrentParameterSettingsToDataVector(exposedParams, unexposedParams, dataVector);
    return dataVector;
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromPatchDataStoredInBankAndSlot(uint8 /*bank*/, uint8 /*slot*/) {
    return {};
}
