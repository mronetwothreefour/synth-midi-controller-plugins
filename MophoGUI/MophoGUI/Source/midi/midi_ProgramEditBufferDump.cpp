#include "midi_ProgramEditBufferDump.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"
#include "../params/params_RawProgramData.h"



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
    auto rawProgramData{ RawProgramData::extractFromExposedParameters(exposedParams) };
    for (auto dataByte : rawProgramData)
        dumpVector.push_back(dataByte);
    return dumpVector;
}