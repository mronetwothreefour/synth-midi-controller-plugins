#include "midi_ProgramDump.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"
#include "../banks/banks_ConvertRawProgramDataFormat.h"
#include "../params/params_UnexposedParameters_Facade.h"



void ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::programDumpRequest);
    requestVector.push_back(bank);
    requestVector.push_back(slot);
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(requestVector.data(), (int)requestVector.size()), 0);
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    outgoingBuffers->aggregateOutgoingMidiBuffers(localMidiBuffer);
}

void ProgramDump::addProgramInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto localMidiBuffer{ createProgramDumpForBankAndSlot(bank, slot, unexposedParams) };
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    outgoingBuffers->aggregateOutgoingMidiBuffers(localMidiBuffer);
}

MidiBuffer ProgramDump::createProgramDumpForBankAndSlot(uint8 bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto dumpVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    dumpVector.push_back((uint8)SysExMessageType::programDump);
    dumpVector.push_back(bank);
    dumpVector.push_back(slot);
    auto programBanks{ unexposedParams->pluginProgramBanks_get() };
    auto programDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, slot) };
    auto programDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(programDataHexString) };
    for (auto dataByte : programDataVector)
        dumpVector.push_back(dataByte);
    for (auto emptyByte = dumpVector.size(); emptyByte != 298; ++emptyByte)
        dumpVector.push_back((uint8)0);
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(dumpVector.data(), (int)dumpVector.size()), 0);
    return localMidiBuffer;
}