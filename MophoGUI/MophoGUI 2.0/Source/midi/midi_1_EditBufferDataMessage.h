#pragma once

#include <JuceHeader.h>

#include "midi_0_RawDataTools.h"
#include "../constants/constants_Enum.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

struct EditBufferDataMessage {
    static void addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
        auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
        requestVector.push_back((uint8)SysExMessageType::editBufferDataRequest);
        outgoingBuffers->addDataMessage(requestVector);
    }

    static void addEditBufferDataMessageToOutgoingMidiBuffers(ExposedParameters* exposedParams, OutgoingMidiBuffers* outgoingBuffers) {
        auto dumpDataVector{ createEditBufferDataMessage(exposedParams) };
        outgoingBuffers->addDataMessage(dumpDataVector);
    }

private:
    static std::vector<uint8> createEditBufferDataMessage(ExposedParameters* exposedParams) {
        const int editBufferDataVectorSize{ 293 };
        auto editBufferDataVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
        editBufferDataVector.push_back((uint8)SysExMessageType::editBufferData);
        auto rawVoiceData{ RawDataTools::extractRawDataFromExposedParameters(exposedParams) };
        for (auto dataByte : rawVoiceData)
            editBufferDataVector.push_back(dataByte);
        for (auto emptyByte = rawVoiceData.size(); emptyByte != editBufferDataVectorSize; ++emptyByte)
            editBufferDataVector.push_back((uint8)0);
        return editBufferDataVector;
    }
};