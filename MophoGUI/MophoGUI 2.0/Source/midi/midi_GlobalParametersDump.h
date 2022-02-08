#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

struct GlobalParametersDump {
    static void addRequestForDumpToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);
};