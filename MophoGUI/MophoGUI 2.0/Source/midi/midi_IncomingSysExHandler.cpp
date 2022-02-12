#include "midi_IncomingSysExHandler.h"

#include "midi_Constants.h"
#include "midi_SysExHelpers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoicesBanks.h"

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
        handleIncomingEditBufferDataMessage(midiMessage.getSysExData());
        return true;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingEditBufferDataMessage(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::editBufferData) {
        RawDataTools::applyToExposedParameters(sysExData + 4, exposedParams, unexposedParams);
        return;
    }
    else
        handleIncomingVoiceDataMessage(sysExData);
}

void IncomingSysExHandler::handleIncomingVoiceDataMessage(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::voiceData) {
        auto bankNum{ sysExData[MIDI::voiceDumpBankByte] };
        VoicesBank bank;
        switch (bankNum)
        {
        case 0:
            bank = VoicesBank::custom1;
            break;
        case 1:
            bank = VoicesBank::custom2;
            break;
        case 2:
            bank = VoicesBank::custom3;
            break;
        default:
            bank = VoicesBank::custom1;
            break;
        }
        auto slot{ sysExData[MIDI::voiceDumpSlotByte] };
        std::vector<uint8> voiceDataVector;
        for (auto dataByte = MIDI::firstVoiceDataByte; dataByte != MIDI::firstUnusedPVoiceDataByte; ++dataByte)
            voiceDataVector.push_back(*(sysExData + dataByte));
        auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
        auto voicesBanks{ unexposedParams->voicesBanks_get() };
        voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, slot);
    }
    else
        handleIncomingGlobalParametersDump(sysExData);
}

void IncomingSysExHandler::handleIncomingGlobalParametersDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::globalParametersData) {
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
    auto voiceChangeIsOn{ (bool)sysExData[MIDI::globalVoiceChangeOnByte] };
    if (voiceChangeIsOn)
        midiOptions->setVoiceChangeOn();
    else
        midiOptions->setVoiceChangeOff();
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

