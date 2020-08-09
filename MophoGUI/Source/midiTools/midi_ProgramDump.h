#pragma once

#include <JuceHeader.h>

#include "midi_InternalMidiBuffers_Singleton.h"
#include "midi_SysExHelpers.h"
#include "../banksWindow/banks_PluginProgramBanks_Singleton.h"



struct ProgramDump {
    static void requestFromBankAndSlot(uint8 bank, uint8 slot) {
        auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
        requestVector.push_back((uint8)SysExMessageType::programDumpRequest);
        requestVector.push_back(bank);
        requestVector.push_back(slot);
        MidiBuffer localMidiBuffer;
        localMidiBuffer.addEvent(MidiMessage::createSysExMessage(requestVector.data(), (int)requestVector.size()), 0);
        InternalMidiBuffers::get().aggregateMidiBuffers(localMidiBuffer);
    }

    static void sendToBankAndSlot(uint8 bank, uint8 slot) {
        MidiBuffer localMidiBuffer{ createProgramDumpForBankAndSlot(bank, slot) };
        InternalMidiBuffers::get().aggregateMidiBuffers(localMidiBuffer);
    }

private:
    static MidiBuffer createProgramDumpForBankAndSlot(uint8 bank, uint8 slot) {
        auto dumpVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
        dumpVector.push_back((uint8)SysExMessageType::programDump);
        dumpVector.push_back(bank);
        dumpVector.push_back(slot);
        auto& pluginProgramBanks{ PluginProgramBanks::get() };
        auto rawProgramData{ pluginProgramBanks.getProgramDataStoredInBankSlot(bank, slot) };
        for (auto dataByte : rawProgramData)
            dumpVector.push_back(dataByte);
        for (auto emptyByte = dumpVector.size(); emptyByte != 298; ++emptyByte)
            dumpVector.push_back((uint8)0);
        MidiBuffer localMidiBuffer;
        localMidiBuffer.addEvent(MidiMessage::createSysExMessage(dumpVector.data(), (int)dumpVector.size()), 0);
        return localMidiBuffer;
    }
};