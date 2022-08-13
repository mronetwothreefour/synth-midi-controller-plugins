#include "midi_1_handle_IncomingMessage_SysEx.h"

#include "midi_0_RawDataTools.h"
#include "../constants/constants_MIDI.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

IncomingMessageHandler_SysEx::IncomingMessageHandler_SysEx(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
    global{ unexposedParams->getGlobalOptions() },
    voicesBanks{ unexposedParams->getVoicesBanks() },
    transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
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
        RawDataTools::applyRawVoiceDataToExposedParameters(sysExData + 4, exposedParams, unexposedParams);
    else
        handleIncomingVoiceData(sysExData);
}

void IncomingMessageHandler_SysEx::handleIncomingVoiceData(const uint8* sysExData) {
    if (sysExData[sysExMessageTypeByte] == (uint8)SysExMessageType::voiceData) {
        const int voiceDataMessageBankByte{ 4 };
        const int voiceDataMessageSlotByte{ 5 };
        const int firstVoiceDataByte{ 6 };
        const int firstUnusedPVoiceDataByte{ 235 };
        auto bankNum{ sysExData[voiceDataMessageBankByte] };
        auto bank{ VoicesBank{ bankNum + 3 } };
        auto slotNum{ sysExData[voiceDataMessageSlotByte] };
        std::vector<uint8> voiceDataVector;
        for (auto dataByte = firstVoiceDataByte; dataByte != firstUnusedPVoiceDataByte; ++dataByte)
            voiceDataVector.push_back(*(sysExData + dataByte));
        auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
        voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, slotNum);
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
        const int globalHardwareOutputTypeByte{ 20 };
        const int globalHardwareReceiveChannelLSByte{ 8 };
        const int globalHardwareReceiveChannelMSByte{ 9 };
        const int globalMIDI_ClockSourceByte{ 10 };
        const int globalParamChangeSendTypeByte{ 12 };
        const int globalParamChangeReceiveTypeByte{ 14 };
        const int globalPedalModeIsArpLatchByte{ 26 };
        const int globalSysExByte{ 18 };
        const int globalTransposeLSByte{ 4 };
        const int globalTransposeMSByte{ 5 };
        const int globalVoiceChangesByte{ 28 };
        transmitOptions->setParamChangesShouldBeTransmitted(false);

        auto globalTranspose{ sysExData[globalTransposeMSByte] * 16 + sysExData[globalTransposeLSByte] };
        global->setGlobalTranspose((uint8)globalTranspose);

        auto globalFineTune{ sysExData[globalFineTuneMSByte] * 16 + sysExData[globalFineTuneLSByte] };
        global->setGlobalFineTune((uint8)globalFineTune);

        auto globalHardwareReceiveChannel{ sysExData[globalHardwareReceiveChannelMSByte] * 16 + sysExData[globalHardwareReceiveChannelLSByte] };
        global->setHardwareReceiveChannel((uint8)globalHardwareReceiveChannel);
        auto allChannels{ 0 };
        if (globalHardwareReceiveChannel == allChannels)
            global->setTransmitChannel((uint8)globalHardwareReceiveChannel);
        else
            global->setTransmitChannel((uint8)(globalHardwareReceiveChannel - 1));

        MIDI_ClockSource midiClockSource{ sysExData[globalMIDI_ClockSourceByte] };
        global->setMIDI_ClockSource(midiClockSource);

        auto shouldBeArpLatch{ (bool)sysExData[globalPedalModeIsArpLatchByte] };
        global->setPedalModeIsArpLatch(shouldBeArpLatch ? true : false);

        auto voiceChangesShouldBeEnabled{ (bool)sysExData[globalVoiceChangesByte] };
        global->setVoiceChangesAreEnabled(voiceChangesShouldBeEnabled ? true : false);

        ParamChangeSendType paramChangeSendType{ sysExData[globalParamChangeSendTypeByte] };
        global->setParamChangeSendType(paramChangeSendType);

        ParamChangeReceiveType paramChangeReceiveType{ sysExData[globalParamChangeReceiveTypeByte] };
        global->setParamChangeReceiveType(paramChangeReceiveType);

        auto controllersShouldBeEnabled{ (bool)sysExData[globalControllersOnByte] };
        global->setControllersAreEnabled(controllersShouldBeEnabled ? true : false);

        auto sysExShouldBeEnabled{ (bool)sysExData[globalSysExByte] };
        global->setSysExIsEnabled(sysExShouldBeEnabled ? true : false);

        auto outputShouldBeMono{ (bool)sysExData[globalHardwareOutputTypeByte] };
        global->setHardwareOutputIsMono(outputShouldBeMono ? true : false);

        auto hardwareOutputBalance{ sysExData[globalHardwareOutputBalanceByte] };
        global->setHardwareOutputBalance(hardwareOutputBalance);

        transmitOptions->setParamChangesShouldBeTransmitted(true);
    }
}
