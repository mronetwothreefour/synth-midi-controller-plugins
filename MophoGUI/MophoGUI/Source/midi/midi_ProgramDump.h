#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct ProgramDump {
    static void addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers);
    static std::vector<uint8> createProgramDumpForBankAndSlot(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams);
};