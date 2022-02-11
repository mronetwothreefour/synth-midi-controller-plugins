#include "midi_ProgramDump.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_RawDataTools.h"
#include "midi_SysExHelpers.h"
#include "../params/params_UnexposedParameters_Facade.h"



void ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(ProgramBank bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    jassert(bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3);
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::programDumpRequest);
    switch (bank)
    {
    case ProgramBank::custom1:
        requestVector.push_back(0);
        break;
    case ProgramBank::custom2:
        requestVector.push_back(1);
        break;
    case ProgramBank::custom3:
        requestVector.push_back(2);
        break;
    default:
        requestVector.push_back(0);
        break;
    }
    requestVector.push_back(slot);
    outgoingBuffers->addDataMessage(requestVector);
}

std::vector<uint8> ProgramDump::createProgramDumpForBankAndSlot(ProgramBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto dumpVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    dumpVector.push_back((uint8)SysExMessageType::programDump);
    switch (bank)
    {
    case ProgramBank::factory1:
        dumpVector.push_back(0);
        break;
    case ProgramBank::factory2:
        dumpVector.push_back(1);
        break;
    case ProgramBank::factory3:
        dumpVector.push_back(2);
        break;
    case ProgramBank::custom1:
        dumpVector.push_back(0);
        break;
    case ProgramBank::custom2:
        dumpVector.push_back(1);
        break;
    case ProgramBank::custom3:
        dumpVector.push_back(2);
        break;
    default:
        dumpVector.push_back(0);
        break;
    }
    dumpVector.push_back(slot);
    auto programBanks{ unexposedParams->programBanks_get() };
    auto programDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, slot) };
    auto programDataVector{ RawDataTools::convertHexStringToDataVector(programDataHexString) };
    for (auto dataByte : programDataVector)
        dumpVector.push_back(dataByte);
    for (auto emptyByte = dumpVector.size(); emptyByte != 298; ++emptyByte)
        dumpVector.push_back((uint8)0);
    return dumpVector;
}