#include "midi_ProgramEditBufferDump.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"
#include "midi_RawDataTools.h"



void ProgramEditBufferDump::addRequestForDumpToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::programEditBufferDumpRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void ProgramEditBufferDump::addDumpToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers) {
    auto dumpDataVector{ createProgramEditBufferDump(exposedParams) };
    outgoingBuffers->addDataMessage(dumpDataVector);
}

std::vector<uint8> ProgramEditBufferDump::createProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams) {
    auto dumpVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    dumpVector.push_back((uint8)SysExMessageType::programEditBufferDump);
    auto rawProgramData{ RawDataTools::extractFromExposedParameters(exposedParams) };
    for (auto dataByte : rawProgramData)
        dumpVector.push_back(dataByte);
    return dumpVector;
}