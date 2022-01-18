#include "midi_IncomingSysExHandler.h"

#include "midi_Constants.h"
#include "midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



IncomingSysExHandler::IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
}

MidiBuffer IncomingSysExHandler::pullSysExWithMatchingIDOutOfBuffer(const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (!incomingSysExHasMatchingID(midiMessage))
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

bool IncomingSysExHandler::incomingSysExHasMatchingID(MidiMessage midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        auto sysExDataSize{ midiMessage.getSysExDataSize() };
        if (sysExData[MIDI::sysExByteHolding_ManufacturerID] == MIDI::manufacturerID && MIDI::sysExByteHolding_Opcode == MIDI::opcode_PgmDataDump) {
            handleIncomingPgmDump(midiMessage.getSysExData(), sysExDataSize);
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingPgmDump(const uint8* sysExData, int sysExDataSize) {
    auto pgmNum{ sysExData[MIDI::sysExByteHolding_PgmNum] };
    auto pgmDataVector{ stripHeaderBytesFromPgmDump(sysExData, sysExDataSize) };
    RawDataTools::applyPgmDataVectorToGUI(pgmNum, pgmDataVector, exposedParams,unexposedParams);
    auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
    if (pgmDataOptions->incomingPgmDataDumpShouldBeSavedInStorageBank()) {
        auto pgmDataBank{ unexposedParams->programDataBank_get() };
        auto pgmDataHexString{ RawDataTools::convertPgmDataVectorToHexString(pgmDataVector) };
        pgmDataBank->storePgmDataHexStringInSlot(pgmDataHexString, pgmNum);
        pgmDataOptions->setIncomingPgmDataDumpShouldNotBeSavedInStorageBank();
    }
}

std::vector<uint8> IncomingSysExHandler::stripHeaderBytesFromPgmDump(const uint8* sysExData, int sysExDataSize) {
    std::vector<uint8> pgmDataWithoutHeaderBytes;
    for (auto byteIndex = MIDI::sysExByteHolding_FirstPgmDataNybble; byteIndex != (uint8)sysExDataSize; ++byteIndex)
        pgmDataWithoutHeaderBytes.push_back(*(sysExData + byteIndex));
    return pgmDataWithoutHeaderBytes;
}
