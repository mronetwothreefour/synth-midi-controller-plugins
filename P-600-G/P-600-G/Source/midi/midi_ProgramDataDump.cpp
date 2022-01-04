#include "midi_ProgramDataDump.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"



void ProgramDataDump::addRequestForPgmDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    auto pgmRequestMessage{ RawSysExDataVector::createPgmDataRequestMessage(slot) };
    outgoingBuffers->addDataMessage(pgmRequestMessage);
}
