#pragma once

#include <JuceHeader.h>

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"
#include "../banksWindow/banks_RawProgramData.h"



struct ProgramEditBufferDump {
    static void addRequestForDumpToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
        auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
        requestVector.push_back((uint8)SysExMessageType::programEditBufferDumpRequest);
        MidiBuffer localMidiBuffer;
        localMidiBuffer.addEvent(MidiMessage::createSysExMessage(requestVector.data(), (int)requestVector.size()), 0);
        outgoingBuffers->aggregateOutgoingMidiBuffers(localMidiBuffer);
    }

	static void addDumpToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers) {
        MidiBuffer localMidiBuffer{ createProgramEditBufferDump(exposedParams) };
        outgoingBuffers->aggregateOutgoingMidiBuffers(localMidiBuffer);
    }

private:
	static MidiBuffer createProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams) {
        auto dumpVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
        dumpVector.push_back((uint8)SysExMessageType::programEditBufferDump);
        auto rawProgramData{ RawProgramData::extractFromExposedParameters(exposedParams) };
        for (auto dataByte : rawProgramData)
            dumpVector.push_back(dataByte);
        MidiBuffer localMidiBuffer;
        localMidiBuffer.addEvent(MidiMessage::createSysExMessage(dumpVector.data(), (int)dumpVector.size()), 0);
        return localMidiBuffer;
    }
};