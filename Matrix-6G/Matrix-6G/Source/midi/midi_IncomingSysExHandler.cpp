#include "midi_IncomingSysExHandler.h"

#include "midi_Constants.h"
#include "midi_SysExHelpers.h"
#include "../patches/patches_PatchBanks.h"
#include "../patches/patches_RawPatchData.h"
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
    if (SysExID::matchesHardwareSynthID(midiMessage)) {
        handleIncomingPatchDump(midiMessage.getSysExData());
        return true;
    }
    else
        return false;
}

void IncomingSysExHandler::handleIncomingPatchDump(const uint8* sysExData) {
    if (sysExData[MIDI::sysexMessageOpcodeByte] == MIDI::opcode_PatchData) {
        auto slot{ sysExData[MIDI::patchDumpSlotNumberByte] };
        std::vector<uint8> patchDataVector;
        for (auto dataByte = MIDI::patchDumpFirstDataByte; dataByte != MIDI::sizeOfPatchDataVector; ++dataByte)
            patchDataVector.push_back(*(sysExData + dataByte));
        auto midiOptions{ unexposedParams->midiOptions_get() };
        if (midiOptions->incomingPatchShouldBeSavedInCustomBankA() || midiOptions->incomingPatchShouldBeSavedInCustomBankB()) {
            auto patchBanks{ unexposedParams->patchBanks_get() };
            auto patchDataHexString{ RawPatchData::convertDataVectorToHexString(patchDataVector) };
            if (midiOptions->incomingPatchShouldBeSavedInCustomBankA()) {
                const MessageManagerLock mmLock;
                patchBanks->storePatchDataHexStringInCustomBankSlot(patchDataHexString, PatchBank::customA, slot);
                midiOptions->setIncomingPatchShouldNotBeSavedInCustomBankA();
            }
            if (midiOptions->incomingPatchShouldBeSavedInCustomBankB()) {
                const MessageManagerLock mmLock;
                patchBanks->storePatchDataHexStringInCustomBankSlot(patchDataHexString, PatchBank::customB, slot);
                midiOptions->setIncomingPatchShouldNotBeSavedInCustomBankB();
            }
        }
        const MessageManagerLock mmLock;
        RawPatchData::applyPatchDataVectorToGUI(slot, patchDataVector, exposedParams, unexposedParams);
    }
}
