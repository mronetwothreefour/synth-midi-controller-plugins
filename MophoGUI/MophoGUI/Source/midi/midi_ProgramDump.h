#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

struct ProgramDump {
    static void addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams);
    static void addProgramInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams);

private:
    static MidiBuffer createProgramDumpForBankAndSlot(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams);
};