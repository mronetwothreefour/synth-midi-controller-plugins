#include "midi_ProgramDataDump.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"



void ProgramDataDump::addPgmDataDumpForCurrentExposedParamsSettingsToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto patchDataMessage{ createSysExMessageFromCurrentExposedParamsSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(patchDataMessage);
}

void ProgramDataDump::addRequestForPgmDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    auto pgmRequestMessage{ RawSysExDataVector::createPgmDataRequestMessage(slot) };
    outgoingBuffers->addDataMessage(pgmRequestMessage);
}

std::vector<uint8> ProgramDataDump::createSysExMessageFromCurrentExposedParamsSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
    auto currentPgmNumber{ pgmDataOptions->currentProgramNumber() };
    auto dataVector{ RawSysExDataVector::initializePgmDataDumpMessage(currentPgmNumber) };
    RawDataTools::addCurrentExposedParamsSettingsToDataVector(exposedParams, dataVector);
    return dataVector;
}
