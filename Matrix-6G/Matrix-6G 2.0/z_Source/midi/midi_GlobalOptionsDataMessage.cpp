#include "midi_GlobalOptionsDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_GlobalOptions.h"
#include "../params/params_UnexposedParameters_Facade.h"



void GlobalOptionsDataMessage::addDataMessageForGlobalOptionsToOutgoingMidiBuffers(UnexposedParameters* unexposedParams) {
    auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto globalOptionsDataMessage{ createSysExMessageFromCurrentGlobalOptions(unexposedParams) };
    outgoingBuffers->addDataMessage(globalOptionsDataMessage);
}

void GlobalOptionsDataMessage::addRequestForGlobalOptionsDataToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto globalOptionsRequestMessage{ RawSysExDataVector::createGlobalOptionsDataRequestMessage() };
    outgoingBuffers->addDataMessage(globalOptionsRequestMessage);
}

std::vector<uint8> GlobalOptionsDataMessage::createSysExMessageFromCurrentGlobalOptions(UnexposedParameters* unexposedParams) {
    auto dataVector{ RawSysExDataVector::initializeGlobalOptionsDataMessage() };
    RawDataTools::addCurrentGlobalSettingsToDataVector(unexposedParams, dataVector);
    return dataVector;
}
