#include "midi_1_handle_IncomingSysExMessage.h"

#include "midi_0_RawDataTools.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

IncomingSysExMessageHandler::IncomingSysExMessageHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	voicesBank{ unexposedParams->getVoicesBank() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
}

MidiBuffer IncomingSysExMessageHandler::pullMessageForP_600_OutOfBuffer(const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (midiMessage.isSysEx()) {
            auto sysExData{ midiMessage.getSysExData() };
            auto manufacturerID{ sysExData[1] };
            auto messageType{ sysExData[2] };
            if (manufacturerID == RawDataTools::sequentialCircuits_ID && messageType == RawDataTools::messageType_VoiceData)
                handleIncomingVoiceData(sysExData, midiMessage.getSysExDataSize());
            else
                midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        }
        else
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

void IncomingSysExMessageHandler::handleIncomingVoiceData(const uint8* sysExData, int sysExDataSize) {
    const int voiceNumByte{ 3 };
    const int firstVoiceDataByte{ 4 };
    RawDataTools::applyRawVoiceDataToExposedParameters(sysExData + firstVoiceDataByte, exposedParams, transmitOptions);
    if (transmitOptions->incomingVoiceShouldBeStored()) {
        auto voiceNum{ sysExData[voiceNumByte] };
        std::vector<uint8> voiceDataWithoutHeaderBytes;
        for (auto byteIndex = firstVoiceDataByte; byteIndex != sysExDataSize; ++byteIndex)
            voiceDataWithoutHeaderBytes.push_back(*(sysExData + byteIndex));
        auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataWithoutHeaderBytes) };
        voicesBank->storeVoiceDataHexStringInSlot(voiceDataHexString, voiceNum);
        transmitOptions->setIncomingVoiceShouldBeStored(false);
    }
}
