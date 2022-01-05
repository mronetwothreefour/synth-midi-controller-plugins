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
        if (sysExData[MIDI::sysExByteHolding_ManufacturerID] == MIDI::manufacturerID && MIDI::sysExByteHolding_Opcode == MIDI::opcode_PgmDataDump) {
            handleIncomingPgmDump(midiMessage.getSysExData());
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingPgmDump(const uint8* sysExData) {
    auto pgmNum{ sysExData[MIDI::sysExByteHolding_PgmNum] };
    std::vector<uint8> pgmDataVector;
    for (auto dataByte = MIDI::sysExByteHolding_FirstPgmDataNybble; dataByte != MIDI::sizeOfPgmDataDumpVector; ++dataByte)
        pgmDataVector.push_back(*(sysExData + dataByte));
    const MessageManagerLock mmLock;
    RawDataTools::applyPgmDataVectorToGUI(pgmNum, pgmDataVector, exposedParams,unexposedParams);
}
