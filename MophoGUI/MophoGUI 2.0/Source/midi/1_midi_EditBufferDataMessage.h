#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

struct EditBufferDataMessage {
    static void addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);
    static void addEditBufferDataMessageToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers);

private:
    static std::vector<uint8> createEditBufferDataMessage(AudioProcessorValueTreeState* exposedParams);
};