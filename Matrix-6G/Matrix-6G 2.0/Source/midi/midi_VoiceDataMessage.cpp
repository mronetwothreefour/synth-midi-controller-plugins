#include "midi_VoiceDataMessage.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



void VoiceDataMessage::addDataMessageForCurrentVoiceToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto voiceDataMessage{ createSysExMessageFromCurrentVoiceSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(voiceDataMessage);
}

void VoiceDataMessage::addDataMessageForVoiceStoredInBankAndSlotToOutgoingMidiBuffers(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto voiceDataMessage{ createSysExMessageFromVoiceDataStoredInBankAndSlot(bank, slot, unexposedParams) };
    outgoingBuffers->addDataMessage(voiceDataMessage);
}

void VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    auto voiceRequestMessage{ RawSysExDataVector::createVoiceDataRequestMessage(slot) };
    outgoingBuffers->addDataMessage(voiceRequestMessage);
}

std::vector<uint8> VoiceDataMessage::createSysExMessageFromCurrentVoiceSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
    auto currentVoiceNumber{ currentVoiceOptions->currentVoiceNumber() };
    auto dataVector{ RawSysExDataVector::initializeVoiceDataMessage(currentVoiceNumber) };
	RawDataTools::addCurrentParameterSettingsToDataVector(exposedParams, unexposedParams, dataVector);
    return dataVector;
}

std::vector<uint8> VoiceDataMessage::createSysExMessageFromVoiceDataStoredInBankAndSlot(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::createVoiceDataMessageHeader(slot) };
    auto voiceBanks{ unexposedParams->voicesBanks_get() };
    auto voiceDataHexString{ voiceBanks->getVoiceDataHexStringFromBankSlot(bank, slot) };
    auto voiceDataVector{ RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataHexString) };
    for (auto dataByte : voiceDataVector)
        dataVector.push_back(dataByte);
    return dataVector;
}
