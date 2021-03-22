#include "midi_MasterOptionsDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
//#include "../params/params_MasterOptions.h"
#include "../params/params_UnexposedParameters_Facade.h"



void MasterOptionsDataMessage::addDataMessageForMasterOptionsToOutgoingMidiBuffers(UnexposedParameters* unexposedParams) {
}

void MasterOptionsDataMessage::addRequestForMasterOptionsDataToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto masterOptionsRequestMessage{ RawSysExDataVector::createMasterOptionsDataRequestMessage() };
    outgoingBuffers->addDataMessage(masterOptionsRequestMessage);
}

std::vector<uint8> MasterOptionsDataMessage::createSysExMessageFromCurrentMasterOptions(UnexposedParameters* unexposedParams) {
	return std::vector<uint8>();
}
