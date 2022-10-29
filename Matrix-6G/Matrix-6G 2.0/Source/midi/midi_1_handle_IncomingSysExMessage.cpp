#include "midi_1_handle_IncomingSysExMessage.h"

#include "midi_0_RawDataTools.h"
#include "../constants/constants_Global.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

IncomingSysExMessageHandler::IncomingSysExMessageHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    global{ unexposedParams->getGlobalOptions() },
    splitOptions{ unexposedParams->getSplitOptions() },
    splitsBank{ unexposedParams->getSplitsBank() },
    voicesBanks{ unexposedParams->getVoicesBanks() },
    transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
}

MidiBuffer IncomingSysExMessageHandler::pullMessageForMatrixOutOfBuffer(const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (RawDataTools::midiMessageIsSysExForMatrix(midiMessage))
            handleSysExData(midiMessage.getSysExData(), midiMessage.getSysExDataSize());
        else
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

void IncomingSysExMessageHandler::handleSysExData(const uint8* sysExData, int sysExDataSize) {
    handleIncomingVoiceData(sysExData, sysExDataSize);
}

void IncomingSysExMessageHandler::handleIncomingVoiceData(const uint8* sysExData, int sysExDataSize) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::voiceData) {
        auto slotNum{ sysExData[RawDataTools::voiceAndSplitDataMessageSlotByte] };
        RawDataTools::applyRawVoiceDataTo_GUI(slotNum, sysExData + RawDataTools::firstVoiceAndSplitNameByte, exposedParams, transmitOptions);
        if (transmitOptions->incomingVoiceShouldBeStored()) {
            std::vector<uint8> voiceDataVector;
            for (auto dataByte = RawDataTools::firstVoiceAndSplitNameByte; dataByte != sysExDataSize; ++dataByte)
                voiceDataVector.push_back(*(sysExData + dataByte));
            auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
            auto bank{ transmitOptions->bankToStoreIn() };
            voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, slotNum);
            transmitOptions->setIncomingVoiceShouldNotBeStored();
        }
    }
    else
        handleIncomingSplitData(sysExData, sysExDataSize);
}

void IncomingSysExMessageHandler::handleIncomingSplitData(const uint8* sysExData, int sysExDataSize) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::splitData) {
        auto slotNum{ sysExData[RawDataTools::voiceAndSplitDataMessageSlotByte] };
        std::vector<uint8> splitDataVector;
        for (auto dataByte = RawDataTools::firstVoiceAndSplitNameByte; dataByte != sysExDataSize; ++dataByte)
            splitDataVector.push_back(*(sysExData + dataByte));
        auto splitDataHexString{ RawDataTools::convertDataVectorToHexString(splitDataVector) };
        splitsBank->storeSplitDataHexStringInSlot(splitDataHexString, slotNum);
        RawDataTools::applyRawSplitDataTo_GUI(sysExData + RawDataTools::firstVoiceAndSplitNameByte, splitOptions);
    }
    else
        handleIncomingGlobalData(sysExData);
}

void IncomingSysExMessageHandler::handleIncomingGlobalData(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::globalData) {
        const MessageManagerLock mmLock;
        RawDataTools::applyRawGlobalDataTo_GUI(sysExData + GLBL::firstGlobalDataByte, global);
    }
}
