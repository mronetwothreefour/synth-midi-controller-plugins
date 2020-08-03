#pragma once

#include <JuceHeader.h>

#include "midi_InternalMidiBuffers_Singleton.h"
#include "midi_SysExHelpers.h"
#include "../banksWindow/banks_RawProgramData.h"



struct ProgramEditBufferDump {
    static void request() {
        auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
        requestVector.push_back((uint8)SysExMessageType::programEditBufferDumpRequest);
        MidiBuffer localMidiBuffer;
        localMidiBuffer.addEvent(MidiMessage::createSysExMessage(requestVector.data(), (int)requestVector.size()), 0);
        InternalMidiBuffers::get().aggregateMidiBuffers(localMidiBuffer);
    }

	static void send(AudioProcessorValueTreeState* exposedParams) {
        MidiBuffer localMidiBuffer{ createProgramEditBufferDump(exposedParams) };
        InternalMidiBuffers::get().aggregateMidiBuffers(localMidiBuffer);
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