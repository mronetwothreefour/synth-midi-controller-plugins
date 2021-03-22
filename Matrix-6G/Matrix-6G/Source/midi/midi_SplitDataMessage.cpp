#include "midi_SplitDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_MidiOptions.h"
#include "../params/params_UnexposedParameters_Facade.h"



void SplitDataMessage::addDataMessageForSplitStoredInSlotToOutgoingMidiBuffers(uint8 slot, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto splitDataMessage{ createSysExMessageFromSplitDataStoredInSlot(slot, unexposedParams) };
    outgoingBuffers->addDataMessage(splitDataMessage);
}

void SplitDataMessage::addRequestForSplitDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    auto splitRequestMessage{ RawSysExDataVector::createSplitDataRequestMessage(slot) };
    outgoingBuffers->addDataMessage(splitRequestMessage);
}

std::vector<uint8> SplitDataMessage::createSysExMessageFromSplitDataStoredInSlot(uint8 slot, UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::createSplitDataMessageHeader(slot) };
    auto splitsBank{ unexposedParams->splitsBank_get() };
    auto splitDataHexString{ splitsBank->getSplitDataHexStringFromSlot(slot) };
    auto splitDataVector{ RawDataTools::convertPatchOrSplitHexStringToDataVector(splitDataHexString) };
    for (auto dataByte : splitDataVector)
        dataVector.push_back(dataByte);
    return dataVector;
}
