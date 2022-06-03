#include "1_midi_handle_IncomingMessage_SysEx.h"

#include "0_midi_RawDataTools.h"
#include "../constants/constants_MIDI.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



IncomingMessageHandler_SysEx::IncomingMessageHandler_SysEx(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
}

MidiBuffer IncomingMessageHandler_SysEx::pullMessageForMophoOutOfBuffer(const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (RawDataTools::midiMessageIsSysExForMopho(midiMessage))
            handleSysExData(midiMessage.getSysExData());
        else
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

void IncomingMessageHandler_SysEx::handleSysExData(const uint8* sysExData) {
    handleIncomingEditBufferData(sysExData);
}

void IncomingMessageHandler_SysEx::handleIncomingEditBufferData(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::editBufferData)
        RawDataTools::applyRawDataToExposedParameters(sysExData + 4, exposedParams, unexposedParams);
    else
        handleIncomingVoiceData(sysExData);
}

void IncomingMessageHandler_SysEx::handleIncomingVoiceData(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::voiceData) {
        const int voiceDataMessageBankByte{ 4 };
        const int voiceDataMessageSlotByte{ 5 };
        const int firstVoiceDataByte{ 6 };
        const int firstUnusedPVoiceDataByte{ 236 };
        auto bankNum{ sysExData[voiceDataMessageBankByte] };
        VoicesBank bank;
        switch (bankNum)
        {
        case 0:
            bank = VoicesBank::custom_1;
            break;
        case 1:
            bank = VoicesBank::custom_2;
            break;
        case 2:
            bank = VoicesBank::custom_3;
            break;
        default:
            bank = VoicesBank::custom_1;
            break;
        }
        auto slot{ sysExData[voiceDataMessageSlotByte] };
        std::vector<uint8> voiceDataVector;
        for (auto dataByte = firstVoiceDataByte; dataByte != firstUnusedPVoiceDataByte; ++dataByte)
            voiceDataVector.push_back(*(sysExData + dataByte));
        auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
        auto voicesBanks{ unexposedParams->getVoicesBanks() };
        voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, slot);
    }
    else
        handleIncomingGlobalData(sysExData);
}

void IncomingMessageHandler_SysEx::handleIncomingGlobalData(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::globalParametersData) {
        const int globalControllersOnByte{ 16 };
        const int globalFineTuneLSByte{ 6 };
        const int globalFineTuneMSByte{ 7 };
        const int globalHardwareOutputBalanceByte{ 24 };
        const int globalHardwareOutputMonoByte{ 20 };
        const int globalHardwareReceiveChannelLSByte{ 8 };
        const int globalHardwareReceiveChannelMSByte{ 9 };
        const int globalMIDI_ClockSourceByte{ 10 };
        const int globalParamChangeSendTypeByte{ 12 };
        const int globalParamChangeReceiveTypeByte{ 14 };
        const int globalPedalModeIsArpByte{ 26 };
        const int globalSysExOnByte{ 18 };
        const int globalTransposeLSByte{ 4 };
        const int globalTransposeMSByte{ 5 };
        const int globalVoiceChangeOnByte{ 28 };
        auto voiceTransmissionOptions{ unexposedParams->getVoiceTransmissionOptions() };
        voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
        auto globalOptions{ unexposedParams->getGlobalOptions() };

        auto globalTranspose{ sysExData[globalTransposeMSByte] * 16 + sysExData[globalTransposeLSByte] };
        globalOptions->setGlobalTranspose((uint8)globalTranspose);

        auto globalFineTune{ sysExData[globalFineTuneMSByte] * 16 + sysExData[globalFineTuneLSByte] };
        globalOptions->setGlobalFineTune((uint8)globalFineTune);

        auto globalHardwareReceiveChannel{ sysExData[globalHardwareReceiveChannelMSByte] * 16 + sysExData[globalHardwareReceiveChannelLSByte] };
        globalOptions->setHardwareReceiveChannel((uint8)globalHardwareReceiveChannel);
        auto allChannels{ 0 };
        if (globalHardwareReceiveChannel == allChannels)
            globalOptions->setTransmitChannel((uint8)globalHardwareReceiveChannel);
        else
            globalOptions->setTransmitChannel((uint8)(globalHardwareReceiveChannel - 1));

        MIDI_ClockSource midiClockSource{ sysExData[globalMIDI_ClockSourceByte] };
        globalOptions->setMIDI_ClockSource(midiClockSource);

        auto pedalModeIsArpLatch{ (bool)sysExData[globalPedalModeIsArpByte] };
        if (pedalModeIsArpLatch)
            globalOptions->setPedalModeToArpLatch();
        else
            globalOptions->setPedalModeToNormal();

        auto voiceChangeIsEnabled{ (bool)sysExData[globalVoiceChangeOnByte] };
        if (voiceChangeIsEnabled)
            globalOptions->setVoiceChangeEnabled();
        else
            globalOptions->setVoiceChangeDisabled();

        ParamChangeSendType paramChangeSendType{ sysExData[globalParamChangeSendTypeByte] };
        globalOptions->setParamChangeSendType(paramChangeSendType);

        ParamChangeReceiveType paramChangeReceiveType{ sysExData[globalParamChangeReceiveTypeByte] };
        globalOptions->setParamChangeReceiveType(paramChangeReceiveType);

        auto controllersAreOn{ (bool)sysExData[globalControllersOnByte] };
        if (controllersAreOn)
            globalOptions->setControllersOn();
        else
            globalOptions->setControllersOff();

        auto sysExIsOn{ (bool)sysExData[globalSysExOnByte] };
        if (sysExIsOn)
            globalOptions->setSysExOn();
        else
            globalOptions->setSysExOff();

        auto outputIsMono{ (bool)sysExData[globalHardwareOutputMonoByte] };
        if (outputIsMono)
            globalOptions->setHardwareOutputToMono();
        else
            globalOptions->setHardwareOutputToStereo();

        auto hardwareOutputBalance{ sysExData[globalHardwareOutputBalanceByte] };
        globalOptions->setHardwareOutputBalance(hardwareOutputBalance);

        voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
    }
}
