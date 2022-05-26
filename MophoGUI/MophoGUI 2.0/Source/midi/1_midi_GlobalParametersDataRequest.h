#pragma once

#include <JuceHeader.h>

#include "0_midi_OutgoingMidiBuffers.h"
#include "0_midi_RawDataTools.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;



struct GlobalParametersDataRequest {
    static void addToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
        auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
        requestVector.push_back((uint8)SysExMessageType::globalParametersDataRequest);
        outgoingBuffers->addDataMessage(requestVector);
    }
};