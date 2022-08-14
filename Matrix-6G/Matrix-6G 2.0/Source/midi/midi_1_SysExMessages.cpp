#include "midi_1_SysExMessages.h"

#include "midi_0_RawDataTools.h"
#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

void SysExMessages::addActivateQuickEditMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto activateQuickEditVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    activateQuickEditVector.push_back((uint8)(int)SysExMessageType::activateQuickEdit);
    outgoingBuffers->addDataMessage(activateQuickEditVector);
}

void SysExMessages::addParamValueChangeMessageToOutgoingBuffers(uint8 paramIndex, uint8 newValue, OutgoingBuffers* outgoingBuffers) {
    auto paramChangeVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    paramChangeVector.push_back((uint8)(int)SysExMessageType::parameterChange);
    paramChangeVector.push_back(paramIndex);
    paramChangeVector.push_back(newValue);
    outgoingBuffers->addDataMessage(paramChangeVector);
}
