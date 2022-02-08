#include "midi_IncomingSysExHandler.h"

#include "midi_Constants.h"
#include "midi_SysExHelpers.h"
#include "../banks/banks_ProgramBanks.h"
#include "../banks/banks_RawProgramData.h"
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
        handleIncomingProgramEditBufferDump(midiMessage.getSysExData());
        return true;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingProgramEditBufferDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::programEditBufferDump) {
        RawProgramData::applyToExposedParameters(sysExData + 4, exposedParams, unexposedParams);
        return;
    }
    else
        handleIncomingProgramDump(sysExData);
}

void IncomingSysExHandler::handleIncomingProgramDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::programDump) {
        auto bankNum{ sysExData[MIDI::programDumpBankByte] };
        ProgramBank bank;
        switch (bankNum)
        {
        case 0:
            bank = ProgramBank::custom1;
            break;
        case 1:
            bank = ProgramBank::custom2;
            break;
        case 2:
            bank = ProgramBank::custom3;
            break;
        default:
            bank = ProgramBank::custom1;
            break;
        }
        auto slot{ sysExData[MIDI::programDumpSlotByte] };
        std::vector<uint8> programDataVector;
        for (auto dataByte = MIDI::firstProgramDataByte; dataByte != MIDI::firstUnusedProgramDataByte; ++dataByte)
            programDataVector.push_back(*(sysExData + dataByte));
        auto programDataHexString{ RawProgramData::convertDataVectorToHexString(programDataVector) };
        auto programBanks{ unexposedParams->programBanks_get() };
        programBanks->storeProgramDataHexStringInCustomBankSlot(programDataHexString, bank, slot);
    }
    else
        handleIncomingGlobalParametersDump(sysExData);
}

void IncomingSysExHandler::handleIncomingGlobalParametersDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::globalParametersDump) {
        updateMidiOptions(sysExData);
        updateGlobalAudioOptions(sysExData);
    }
}

void IncomingSysExHandler::updateMidiOptions(const uint8* sysExData) {
    auto midiOptions{ unexposedParams->midiOptions_get() };
    midiOptions->setParamChangeEchosAreBlocked();
    auto globalHardwareReceiveChannel{ sysExData[MIDI::globalHardwareReceiveChannelMSByte] * 16 + sysExData[MIDI::globalHardwareReceiveChannelLSByte] };
    midiOptions->setHardwareReceiveChannel((uint8)globalHardwareReceiveChannel);
    auto allChannels{ 0 };
    if (globalHardwareReceiveChannel == allChannels)
        midiOptions->setTransmitChannel((uint8)globalHardwareReceiveChannel);
    else
        midiOptions->setTransmitChannel((uint8)(globalHardwareReceiveChannel - 1));
    auto midiClockType{ sysExData[MIDI::globalMidiClockTypeByte] };
    midiOptions->setClockType(midiClockType);
    auto paramSendType{ sysExData[MIDI::globalParameterSendTypetByte] };
    midiOptions->setParameterSendType(paramSendType);
    auto paramReceiveType{ sysExData[MIDI::globalParameterReceiveTypeByte] };
    midiOptions->setParameterReceiveType(paramReceiveType);
    auto controllersAreOn{ (bool)sysExData[MIDI::globalMidiControllersOnByte] };
    if (controllersAreOn)
        midiOptions->setControllersOn();
    else
        midiOptions->setControllersOff();
    auto sysExIsOn{ (bool)sysExData[MIDI::globalSysExOnByte] };
    if (sysExIsOn)
        midiOptions->setSysExOn();
    else
        midiOptions->setSysExOff();
    auto pedalModeIsArpLatch{ (bool)sysExData[MIDI::globalPedalModeIsArpByte] };
    if (pedalModeIsArpLatch)
        midiOptions->setPedalModeToArpLatch();
    else
        midiOptions->setPedalModeToNormal();
    auto programChangeIsOn{ (bool)sysExData[MIDI::globalProgramChangeOnByte] };
    if (programChangeIsOn)
        midiOptions->setProgramChangeOn();
    else
        midiOptions->setProgramChangeOff();
    midiOptions->setParamChangeEchosAreNotBlocked();
}

void IncomingSysExHandler::updateGlobalAudioOptions(const uint8* sysExData) {
    auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
    auto globalTranspose{ sysExData[MIDI::globalTransposeMSByte] * 16 + sysExData[MIDI::globalTransposeLSByte] };
    globalAudioOptions->setGlobalTranspose((uint8)globalTranspose);
    auto globalFineTune{ sysExData[MIDI::globalFineTuneMSByte] * 16 + sysExData[MIDI::globalFineTuneLSByte] };
    globalAudioOptions->setGlobalFineTune((uint8)globalFineTune);
    auto outputIsMono{ (bool)sysExData[MIDI::globalStereoOutByte] };
    if (outputIsMono)
        globalAudioOptions->setHardwareOutputMono();
    else
        globalAudioOptions->setHardwareOutputStereo();
    auto globalBalance{ sysExData[MIDI::globalBalanceByte] };
    globalAudioOptions->setGlobalBalance(globalBalance);
}

