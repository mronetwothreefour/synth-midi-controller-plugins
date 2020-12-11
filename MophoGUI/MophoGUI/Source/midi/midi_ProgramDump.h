#pragma once

#include <JuceHeader.h>

#include "../banks/banks_ProgramBanks.h"



class OutgoingMidiBuffers;
class UnexposedParameters;

struct ProgramDump {
    static void addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(ProgramBank bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers);
    static std::vector<uint8> createProgramDumpForBankAndSlot(ProgramBank bank, uint8 slot, UnexposedParameters* unexposedParams);
};