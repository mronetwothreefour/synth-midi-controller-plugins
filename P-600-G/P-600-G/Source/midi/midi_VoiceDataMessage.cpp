#include "midi_VoiceDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"



void VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto voiceDataMessage{ createSysExMessageFromCurrentExposedParamsSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(voiceDataMessage);
}

void VoiceDataMessage::addVoiceDataMessageForVoiceStoredInSlotToOutgoingMidiBuffers(uint8 slot, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto voiceDataMessage{ createSysExMessageFromVoiceDataStoredInSlot(slot, unexposedParams) };
    outgoingBuffers->addDataMessage(voiceDataMessage);
}

void VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    auto voiceDataRequestMessage{ RawSysExDataVector::createVoiceDataRequestMessage(slot) };
    outgoingBuffers->addDataMessage(voiceDataRequestMessage);
}

std::vector<uint8> VoiceDataMessage::createSysExMessageFromCurrentExposedParamsSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    auto currentVoiceNumber{ voiceTransmissionOptions->currentVoiceNumber() };
    auto dataVector{ RawSysExDataVector::initializeVoiceDataMessage(currentVoiceNumber) };
    RawDataTools::addCurrentExposedParamsSettingsToDataVector(exposedParams, dataVector);
    return dataVector;
}

std::vector<uint8> VoiceDataMessage::createSysExMessageFromVoiceDataStoredInSlot(uint8 slot, UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::createVoiceDataMessageHeader(slot) };
    auto voicesBank{ unexposedParams->voicesBank_get() };
    auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(slot) };
    auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
    for (auto dataByte : voiceDataVector)
        dataVector.push_back(dataByte);
    return dataVector;
}
