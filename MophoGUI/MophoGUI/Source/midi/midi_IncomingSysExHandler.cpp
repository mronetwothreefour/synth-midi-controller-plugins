#include "midi_IncomingSysExHandler.h"

#include "midi_SysExHelpers.h"
#include "../banks/banks_ConvertRawProgramDataFormat.h"
#include "../params/params_RawProgramData.h"
#include "../params/params_UnexposedParameters_Facade.h"



IncomingSysExHandler::IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    sysExMessageTypeByte{ 3 },
    programDumpBankByte{ 4 },
    programDumpSlotByte{ 5 },
    firstProgramDataByte{ 6 },
    firstUnusedProgramDataByte{ 236 },
    globalTransposeLSByte{ 4 },
    globalTransposeMSByte{ 5 },
    globalFineTuneLSByte{ 6 },
    globalFineTuneMSByte{ 7 },
    globalMidiChannelLSByte{ 8 },
    globalMidiChannelMSByte{ 9 },
    globalMidiClockSelectByte{ 10 },
    globalParameterSendFormatByte{ 12 },
    globalParameterReceiveFormatByte{ 14 },
    globalMidiControllersOnByte{ 16 },
    globalSysExOnByte{ 18 },
    globalStereoOutByte{ 20 },
    globalMidiThruByte{ 22 }
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
        handleIncomingProgramEditBufferDump(midiMessage.getSysExData());
        return true;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingProgramEditBufferDump(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::programEditBufferDump) {
        RawProgramData::applyToExposedParameters(sysExData + 4, exposedParams, unexposedParams);
        return;
    }
    else
        handleIncomingProgramDump(sysExData);
}

void IncomingSysExHandler::handleIncomingProgramDump(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::programDump) {
        auto bank{ sysExData[programDumpBankByte] };
        auto slot{ sysExData[programDumpSlotByte] };
        std::vector<uint8> programDataVector;
        for (auto dataByte = firstProgramDataByte; dataByte != firstUnusedProgramDataByte; ++dataByte)
            programDataVector.push_back(*(sysExData + dataByte));
        auto programDataHexString{ ConvertRawProgramDataFormat::dataVectorToHexString(programDataVector) };
        auto programBanks{ unexposedParams->pluginProgramBanks_get() };
        programBanks->storeProgramDataHexStringInBankSlot(programDataHexString, bank, slot);
        auto programNames{ unexposedParams->programNameStrings_get() };
        auto programName{ programNames->extractProgramNameFromDataVector(programDataVector) };
        programNames->storeNameOfProgramInBankSlot(programName, bank, slot);
    }
    else
        handleIncomingGlobalParametersDump(sysExData);
}

void IncomingSysExHandler::handleIncomingGlobalParametersDump(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::globalParametersDump) {
        auto midiOptions{ unexposedParams->midiOptions_get() };
    }
}

IncomingSysExHandler::~IncomingSysExHandler() {
}
