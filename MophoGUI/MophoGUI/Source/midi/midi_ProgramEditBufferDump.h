#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

struct ProgramEditBufferDump {
    static void addRequestForDumpToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);
    static void addDumpToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers);

private:
    static std::vector<uint8> createProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams);
};