#include "midi_ProgramDataDump.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"



void ProgramDataDump::addPgmDataDumpForCurrentExposedParamsSettingsToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto pgmDataDump{ createSysExMessageFromCurrentExposedParamsSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(pgmDataDump);
}

void ProgramDataDump::addPgmDataDumpForProgramStoredInSlotToOutgoingMidiBuffers(uint8 slot, UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto pgmDataDump{ createSysExMessageFromProgramDataStoredInSlot(slot, unexposedParams) };
    outgoingBuffers->addDataMessage(pgmDataDump);
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

std::vector<uint8> ProgramDataDump::createSysExMessageFromProgramDataStoredInSlot(uint8 slot, UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::createPgmDataDumpHeader(slot) };
    auto pgmDataBank{ unexposedParams->programDataBank_get() };
    auto pgmDataHexString{ pgmDataBank->getPgmDataHexStringFromSlot(slot) };
    auto pgmDataVector{ RawDataTools::convertPgmDataHexStringToDataVector(pgmDataHexString) };
    for (auto dataByte : pgmDataVector)
        dataVector.push_back(dataByte);
    return dataVector;
}
