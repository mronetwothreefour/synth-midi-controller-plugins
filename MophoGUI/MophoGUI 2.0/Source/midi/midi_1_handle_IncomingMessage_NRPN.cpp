#include "midi_1_handle_IncomingMessage_NRPN.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MIDI.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



IncomingMessageHandler_NRPN::IncomingMessageHandler_NRPN(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	global{ unexposedParams->getGlobalOptions() },
    voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() }
{
}

MidiBuffer IncomingMessageHandler_NRPN::pullFullyFormedMessageOutOfBuffer(const MidiBuffer& midiMessages) {
    midiMessagesToPassThrough.clear();
    incompleteNRPN.clear();
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        auto messageChannel{ midiMessage.getChannel() - 1 };
        auto pluginChannel{ global->transmitChannel() };
        if (midiMessage.isController() && messageChannel == pluginChannel)
            checkIfControllerTypeIsNRPN(midiMessage);
        else {
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        }
    }
    if (receivedType_MSB && receivedType_LSB && receivedValue_MSB && receivedValue_LSB) {
        auto nrpnType{ type_MSB * 128 + type_LSB };
        auto newValue{ value_MSB * 128 + value_LSB };
        const auto numberOf_NRPN_TypesForExposedParams{ 184 };
        if (nrpnType < numberOf_NRPN_TypesForExposedParams)
            applyIncomingValueToExposedParameter(nrpnType, newValue);
        else
            applyIncomingValueToGlobalOption(nrpnType, newValue);
    }
    else {
        for (auto nrpnEvent : incompleteNRPN) {
            midiMessagesToPassThrough.addEvent(nrpnEvent.getMessage(), (int)nrpnEvent.getMessage().getTimeStamp());
        }
    }
    receivedType_MSB = false;
    receivedType_LSB = false;
    receivedValue_MSB = false;
    receivedValue_LSB = false;
    return midiMessagesToPassThrough;
}

void IncomingMessageHandler_NRPN::checkIfControllerTypeIsNRPN(MidiMessage midiMessage) {
    auto controllerType{ midiMessage.getControllerNumber() };
    if (controllerType == MIDI::nrpnType_MSB || controllerType == MIDI::nrpnType_LSB || controllerType == MIDI::nrpnValue_MSB || controllerType == MIDI::nrpnValue_LSB)
        handleControllerMessage(midiMessage);
    else
        midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
}

void IncomingMessageHandler_NRPN::handleControllerMessage(MidiMessage midiMessage) {
    handleControllerMessage_Type_MSB(midiMessage);
}

void IncomingMessageHandler_NRPN::handleControllerMessage_Type_MSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnType_MSB)) {
        type_MSB = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        receivedType_MSB = true;
    }
    else
        handleControllerMessage_Type_LSB(midiMessage);
}

void IncomingMessageHandler_NRPN::handleControllerMessage_Type_LSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnType_LSB)) {
        type_LSB = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        receivedType_LSB = true;
    }
    else
        handleControllerMessage_Value_MSB(midiMessage);
}

void IncomingMessageHandler_NRPN::handleControllerMessage_Value_MSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnValue_MSB)) {
        value_MSB = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        receivedValue_MSB = true;
    }
    else
        handleControllerMessage_Value_LSB(midiMessage);
}

void IncomingMessageHandler_NRPN::handleControllerMessage_Value_LSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnValue_LSB)) {
        value_LSB = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        receivedValue_LSB = true;
    }
}

void IncomingMessageHandler_NRPN::applyIncomingValueToExposedParameter(int nrpnType, int newValue) {
    voiceTransmit->dontTransmitParamChanges();
    auto& info{ InfoForExposedParameters::get() };
    auto paramIndex{ info.paramIndexForNRPN((uint8)nrpnType) };
    auto paramID{ info.IDfor(paramIndex) };
    auto paramPtr{ exposedParams->getParameter(paramID) };
    paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1((float)newValue));
    voiceTransmit->transmitParamChanges();
}

void IncomingMessageHandler_NRPN::applyIncomingValueToGlobalOption(int nrpnType, int newValue) {
    voiceTransmit->dontTransmitParamChanges();
    const int nrpnTypeForGlobalFineTune{ 385 };
    const int nrpnTypeForGlobalTranspose{ 384 };
    switch (nrpnType)
    {
    case nrpnTypeForGlobalTranspose:
        global->setGlobalTranspose((uint8)newValue);
        break;
    case nrpnTypeForGlobalFineTune:
        global->setGlobalFineTune((uint8)newValue);
        break;
    default:
        break;
    }
    voiceTransmit->transmitParamChanges();
}
