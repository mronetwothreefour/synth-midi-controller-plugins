#include "midi_IncomingSysExHandler.h"

#include "midi_SysExHelpers.h"
#include "../banksWindow/banks_PluginProgramBanks_Singleton.h"
#include "../banksWindow/banks_RawProgramData.h"



IncomingSysExHandler::IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams) :
    exposedParams{ exposedParams }
{
}

IncomingSysExHandler::~IncomingSysExHandler() {
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
    if (SysExID::matchesHardwareSynthID(midiMessage)) {
        handleIncomingProgramEditBufferDump(midiMessage.getSysExData());
        return true;
    }
    else 
        return false;
}

void IncomingSysExHandler::handleIncomingProgramEditBufferDump(const uint8* sysExData) {
    if (sysExData[3] == (uint8)SysExMessageType::programEditBufferDump) {
        RawProgramData::applyToExposedParameters(sysExData + 4, exposedParams);
        return;
    }
    else
        handleIncomingProgramDump(sysExData);
}

void IncomingSysExHandler::handleIncomingProgramDump(const uint8* sysExData) {
    if (sysExData[3] == (uint8)SysExMessageType::programDump) {
        auto bank{ sysExData[4] };
        auto slot{ sysExData[5] };
        PluginProgramBanks::get().storeProgramDataInBankSlot(sysExData + 6, bank, slot);
    }
}

