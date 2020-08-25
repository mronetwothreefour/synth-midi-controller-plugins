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
    globalHardwareReceiveChannelLSByte{ 8 },
    globalHardwareReceiveChannelMSByte{ 9 },
    globalMidiClockTypeByte{ 10 },
    globalParameterSendTypetByte{ 12 },
    globalParameterReceiveTypeByte{ 14 },
    globalMidiControllersOnByte{ 16 },
    globalSysExOnByte{ 18 },
    globalStereoOutByte{ 20 },
    globalMidiThruOnByte{ 22 }
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
        updateMidiOptions(sysExData);
        updateGlobalAudioOptions(sysExData);
    }
}

void IncomingSysExHandler::updateMidiOptions(const uint8* sysExData) {
    auto midiOptions{ unexposedParams->midiOptions_get() };
    midiOptions->setParamChangeEchosAreBlocked();
    auto globalHardwareReceiveChannel{ sysExData[globalHardwareReceiveChannelMSByte] * 16 + sysExData[globalHardwareReceiveChannelLSByte] };
    midiOptions->setHardwareReceiveChannel((uint8)globalHardwareReceiveChannel);
    auto allChannels{ 0 };
    if (globalHardwareReceiveChannel == allChannels)
        midiOptions->setTransmitChannel((uint8)globalHardwareReceiveChannel);
    else
        midiOptions->setTransmitChannel((uint8)(globalHardwareReceiveChannel - 1));
    auto midiClockType{ sysExData[globalMidiClockTypeByte] };
    midiOptions->setClockType(midiClockType);
    auto paramSendType{ sysExData[globalParameterSendTypetByte] };
    midiOptions->setParameterSendType(paramSendType);
    auto paramReceiveType{ sysExData[globalParameterReceiveTypeByte] };
    midiOptions->setParameterReceiveType(paramReceiveType);
    auto controllersAreOn{ (bool)sysExData[globalMidiControllersOnByte] };
    if (controllersAreOn)
        midiOptions->setControllersOn();
    else
        midiOptions->setControllersOff();
    auto sysExIsOn{ (bool)sysExData[globalSysExOnByte] };
    if (sysExIsOn)
        midiOptions->setSysExOn();
    else
        midiOptions->setSysExOff();
    auto midiThruIsOn{ (bool)sysExData[globalMidiThruOnByte] };
    if (midiThruIsOn)
        midiOptions->setMidiThruOn();
    else
        midiOptions->setMidiThruOff();
    midiOptions->setParamChangeEchosAreNotBlocked();
}

void IncomingSysExHandler::updateGlobalAudioOptions(const uint8* sysExData) {
    auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
    auto globalTranspose{ sysExData[globalTransposeMSByte] * 16 + sysExData[globalTransposeLSByte] };
    globalAudioOptions->setGlobalTranspose((uint8)globalTranspose);
    auto globalFineTune{ sysExData[globalFineTuneMSByte] * 16 + sysExData[globalFineTuneLSByte] };
    globalAudioOptions->setGlobalFineTune((uint8)globalFineTune);
    auto outputIsMono{ (bool)sysExData[globalStereoOutByte] };
    if (outputIsMono)
        globalAudioOptions->setHardwareOutputMono();
    else
        globalAudioOptions->setHardwareOutputStereo();
}

IncomingSysExHandler::~IncomingSysExHandler() {
}
