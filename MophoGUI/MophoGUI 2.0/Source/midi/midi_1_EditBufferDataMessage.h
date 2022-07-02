#pragma once

#include <JuceHeader.h>

using ExposedParameters = AudioProcessorValueTreeState;



class OutgoingMidiBuffers;
class UnexposedParameters;

struct EditBufferDataMessage {
    static void addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);
    static void addEditBufferDataMessageToOutgoingMidiBuffers(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
    static std::vector<uint8> createEditBufferDataMessage(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
};