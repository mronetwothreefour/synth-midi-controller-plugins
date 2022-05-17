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
        auto bankNum{ sysExData[MIDI::voiceDataMessageBankByte] };
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
        auto slot{ sysExData[MIDI::voiceDataMessageSlotByte] };
        std::vector<uint8> voiceDataVector;
        for (auto dataByte = MIDI::firstVoiceDataByte; dataByte != MIDI::firstUnusedPVoiceDataByte; ++dataByte)
            voiceDataVector.push_back(*(sysExData + dataByte));
        auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
        auto voicesBanks{ unexposedParams->voicesBanks_get() };
        voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, slot);
    }
    else
        handleIncomingGlobalDataMessage(sysExData);
}

void IncomingSysExHandler::handleIncomingGlobalDataMessage(const uint8* sysExData) {
    if (sysExData[MIDI::sysExMessageTypeByte] == (uint8)SysExMessageType::globalParametersData) {
        updateGlobalOptions(sysExData);
    }
}

void IncomingSysExHandler::updateGlobalOptions(const uint8* sysExData) {
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
    auto globalOptions{ unexposedParams->globalOptions_get() };

    auto globalTranspose{ sysExData[MIDI::globalTransposeMSByte] * 16 + sysExData[MIDI::globalTransposeLSByte] };
    globalOptions->setGlobalTranspose((uint8)globalTranspose);

    auto globalFineTune{ sysExData[MIDI::globalFineTuneMSByte] * 16 + sysExData[MIDI::globalFineTuneLSByte] };
    globalOptions->setGlobalFineTune((uint8)globalFineTune);

    auto globalHardwareReceiveChannel{ sysExData[MIDI::globalHardwareReceiveChannelMSByte] * 16 + sysExData[MIDI::globalHardwareReceiveChannelLSByte] };
    globalOptions->setHardwareReceiveChannel((uint8)globalHardwareReceiveChannel);
    auto allChannels{ 0 };
    if (globalHardwareReceiveChannel == allChannels)
        globalOptions->setTransmitChannel((uint8)globalHardwareReceiveChannel);
    else
        globalOptions->setTransmitChannel((uint8)(globalHardwareReceiveChannel - 1));

    auto midiClockType{ sysExData[MIDI::globalMidiClockTypeByte] };
    globalOptions->setClockType(midiClockType);

    auto pedalModeIsArpLatch{ (bool)sysExData[MIDI::globalPedalModeIsArpByte] };
    if (pedalModeIsArpLatch)
        globalOptions->setPedalModeToArpLatch();
    else
        globalOptions->setPedalModeToNormal();

    auto voiceChangeIsOn{ (bool)sysExData[MIDI::globalVoiceChangeOnByte] };
    if (voiceChangeIsOn)
        globalOptions->setVoiceChangeOn();
    else
        globalOptions->setVoiceChangeOff();

    auto paramSendType{ sysExData[MIDI::globalParameterSendTypetByte] };
    globalOptions->setParameterSendType(paramSendType);

    auto paramReceiveType{ sysExData[MIDI::globalParameterReceiveTypeByte] };
    globalOptions->setParameterReceiveType(paramReceiveType);

    auto controllersAreOn{ (bool)sysExData[MIDI::globalMidiControllersOnByte] };
    if (controllersAreOn)
        globalOptions->setControllersOn();
    else
        globalOptions->setControllersOff();

    auto sysExIsOn{ (bool)sysExData[MIDI::globalSysExOnByte] };
    if (sysExIsOn)
        globalOptions->setSysExOn();
    else
        globalOptions->setSysExOff();

    auto outputIsMono{ (bool)sysExData[MIDI::globalStereoOutByte] };
    if (outputIsMono)
        globalOptions->setHardwareOutputMono();
    else
        globalOptions->setHardwareOutputStereo();

    auto globalBalance{ sysExData[MIDI::globalBalanceByte] };
    globalOptions->setGlobalBalance(globalBalance);

    voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

