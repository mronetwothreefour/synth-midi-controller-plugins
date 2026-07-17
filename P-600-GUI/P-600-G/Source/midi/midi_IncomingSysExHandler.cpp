#include "midi_IncomingSysExHandler.h"

#include "midi_Constants.h"
#include "midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



IncomingSysExHandler::IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
}

MidiBuffer IncomingSysExHandler::pullSysExWithMatchingIDOutOfBuffer(const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (!incomingSysExHasMatchingID(midiMessage))
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

bool IncomingSysExHandler::incomingSysExHasMatchingID(MidiMessage midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        auto sysExDataSize{ midiMessage.getSysExDataSize() };
        if (sysExData[MIDI::sysExByteHolding_ManufacturerID] == MIDI::manufacturerID && MIDI::sysExByteHolding_Opcode == MIDI::opcode_VoiceDataMessage) {
            handleIncomingVoiceDataMessage(midiMessage.getSysExData(), sysExDataSize);
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingVoiceDataMessage(const uint8* sysExData, int sysExDataSize) {
    auto voiceNum{ sysExData[MIDI::sysExByteHolding_VoiceNum] };
    auto voiceDataVector{ stripHeaderBytesFromVoiceDataMessage(sysExData, sysExDataSize) };
    RawDataTools::applyVoiceDataVectorToGUI(voiceNum, voiceDataVector, exposedParams,unexposedParams);
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    if (voiceTransmissionOptions->incomingVoiceShouldBeSavedInVoicesBank()) {
        auto voicesBank{ unexposedParams->voicesBank_get() };
        auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
        voicesBank->storeVoiceDataHexStringInSlot(voiceDataHexString, voiceNum);
        voiceTransmissionOptions->setIncomingVoiceShouldNotBeSavedInVoicesBank();
    }
}

std::vector<uint8> IncomingSysExHandler::stripHeaderBytesFromVoiceDataMessage(const uint8* sysExData, int sysExDataSize) {
    std::vector<uint8> voiceDataWithoutHeaderBytes;
    for (auto byteIndex = MIDI::sysExByteHolding_FirstVoiceDataNybble; byteIndex != (uint8)sysExDataSize; ++byteIndex)
        voiceDataWithoutHeaderBytes.push_back(*(sysExData + byteIndex));
    return voiceDataWithoutHeaderBytes;
}
