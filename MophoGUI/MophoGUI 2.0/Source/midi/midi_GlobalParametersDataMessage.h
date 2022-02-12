#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

struct GlobalParametersDataMessage {
    static void addRequestForDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);
};