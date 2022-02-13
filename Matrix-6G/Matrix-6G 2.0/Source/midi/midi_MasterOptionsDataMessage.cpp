#include "midi_MasterOptionsDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_GlobalOptions.h"
#include "../params/params_UnexposedParameters_Facade.h"



void MasterOptionsDataMessage::addDataMessageForMasterOptionsToOutgoingMidiBuffers(UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto masterOptionsDataMessage{ createSysExMessageFromCurrentMasterOptions(unexposedParams) };
    outgoingBuffers->addDataMessage(masterOptionsDataMessage);
}

void MasterOptionsDataMessage::addRequestForMasterOptionsDataToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto masterOptionsRequestMessage{ RawSysExDataVector::createMasterOptionsDataRequestMessage() };
    outgoingBuffers->addDataMessage(masterOptionsRequestMessage);
}

std::vector<uint8> MasterOptionsDataMessage::createSysExMessageFromCurrentMasterOptions(UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::initializeMasterOptionsDataMessage() };
    RawDataTools::addCurrentMasterSettingsToDataVector(unexposedParams, dataVector);
    return dataVector;
}
