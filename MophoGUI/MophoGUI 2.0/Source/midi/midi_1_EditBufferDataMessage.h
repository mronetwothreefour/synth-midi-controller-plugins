#pragma once

#include <JuceHeader.h>

using ExposedParameters = AudioProcessorValueTreeState;



class OutgoingMidiBuffers;

struct EditBufferDataMessage {
    static void addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);
    static void addEditBufferDataMessageToOutgoingMidiBuffers(ExposedParameters* exposedParams, OutgoingMidiBuffers* outgoingBuffers);

private:
    static std::vector<uint8> createEditBufferDataMessage(ExposedParameters* exposedParams);
};