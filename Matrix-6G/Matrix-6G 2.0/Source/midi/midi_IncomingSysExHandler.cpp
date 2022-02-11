#include "midi_IncomingSysExHandler.h"

#include "midi_Constants.h"
#include "midi_RawDataTools.h"
#include "../master/master_Constants.h"
#include "../voices/voices_VoicesBanks.h"
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
    if (SysExID::matchesHardwareSynthID(midiMessage)) {
        handleIncomingVoiceDump(midiMessage.getSysExData());
        return true;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingVoiceDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysexMessageOpcodeByte] == MIDI::opcode_VoiceData) {
        auto slot{ sysExData[MIDI::voiceAndSplitDumpSlotNumberByte] };
        std::vector<uint8> voiceDataVector;
        for (auto dataByte = MIDI::voiceAndSplitDumpFirstDataByte; dataByte != MIDI::sizeOfVoiceDataVector; ++dataByte)
            voiceDataVector.push_back(*(sysExData + dataByte));
        auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
        if (voiceTransmissionOptions->incomingVoiceShouldBeSavedInCustomBankA() || voiceTransmissionOptions->incomingVoiceShouldBeSavedInCustomBankB()) {
            auto voicesBanks{ unexposedParams->voicesBanks_get() };
            auto voiceDataHexString{ RawDataTools::convertVoiceOrSplitDataVectorToHexString(voiceDataVector) };
            const MessageManagerLock mmLock;
            if (voiceTransmissionOptions->incomingVoiceShouldBeSavedInCustomBankA())
                voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, VoicesBank::customA, slot);
            if (voiceTransmissionOptions->incomingVoiceShouldBeSavedInCustomBankB())
                voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, VoicesBank::customB, slot);
            voiceTransmissionOptions->setIncomingVoiceShouldNotBeSavedInCustomBank();
        }
        const MessageManagerLock mmLock;
        RawDataTools::applyVoiceDataVectorToGUI(slot, voiceDataVector, exposedParams, unexposedParams);
    }
    else
        handleIncomingSplitDump(sysExData);
}

void IncomingSysExHandler::handleIncomingSplitDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysexMessageOpcodeByte] == MIDI::opcode_SplitData) {
        auto slot{ sysExData[MIDI::voiceAndSplitDumpSlotNumberByte] };
        std::vector<uint8> splitDataVector;
        for (auto dataByte = MIDI::voiceAndSplitDumpFirstDataByte; dataByte != MIDI::sizeOfSplitDataVector; ++dataByte)
            splitDataVector.push_back(*(sysExData + dataByte));
        auto splitsBank{ unexposedParams->splitsBank_get() };
        auto splitDataHexString{ RawDataTools::convertVoiceOrSplitDataVectorToHexString(splitDataVector) };
        const MessageManagerLock mmLock;
        splitsBank->storeSplitDataHexStringInSlot(splitDataHexString, slot);
        RawDataTools::applySplitDataVectorToGUI(splitDataVector, unexposedParams);
    }
    else
        handleIncomingMasterOptionsDump(sysExData);
}

void IncomingSysExHandler::handleIncomingMasterOptionsDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysexMessageOpcodeByte] == MIDI::opcode_MasterData) {
        const MessageManagerLock mmLock;
        RawDataTools::applyMasterOptionsRawDataToGUI(sysExData + master::indexOfFirstMasterDataByte, unexposedParams);
    }
}
