#include "midi_IncomingNRPNhandler.h"

#include "midi_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



IncomingNRPNhandler::IncomingNRPNhandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
}

MidiBuffer IncomingNRPNhandler::pullFullyFormedNRPNmessageOutOfBuffer(const MidiBuffer& midiMessages) {
    midiMessagesToPassThrough.clear();
    incompleteNRPN.clear();
    for (auto event : midiMessages) {
        auto globalOptions{ unexposedParams->globalOptions_get() };
        auto midiMessage{ event.getMessage() };
        auto messageChannel{ midiMessage.getChannel() - 1 };
        auto pluginChannel{ globalOptions->transmitChannel() };
        if (midiMessage.isController() && messageChannel == pluginChannel)
            checkIfControllerTypeIsNRPN(midiMessage);
        else {
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        }
    }
    if (nrpnTypeMSBvalueReceived && nrpnTypeLSBvalueReceived && nrpnValueMSBvalueReceived && nrpnValueLSBvalueReceived) {
        auto nrpnType{ nrpnTypeMSBvalue * 128 + nrpnTypeLSBvalue };
        auto newValue{ nrpnValueMSBvalue * 128 + nrpnValueLSBvalue };
        if (nrpnType < 184)
            applyIncomingNRPNvalueToExposedParameter(nrpnType, newValue);
        else
            applyIncomingNRPNvalueToUnexposedParameter(nrpnType, newValue);
    }
    else {
        for (auto nrpnEvent : incompleteNRPN) {
            midiMessagesToPassThrough.addEvent(nrpnEvent.getMessage(), (int)nrpnEvent.getMessage().getTimeStamp());
        }
    }
    nrpnTypeMSBvalueReceived = false;
    nrpnTypeLSBvalueReceived = false;
    nrpnValueMSBvalueReceived = false;
    nrpnValueLSBvalueReceived = false;
    return midiMessagesToPassThrough;
}

void IncomingNRPNhandler::checkIfControllerTypeIsNRPN(MidiMessage midiMessage) {
    auto controllerType{ midiMessage.getControllerNumber() };
    if (controllerType == MIDI::nrpnTypeMSB || controllerType == MIDI::nrpnTypeLSB || controllerType == MIDI::nrpnValueMSB || controllerType == MIDI::nrpnValueLSB)
        handleNRPNcontrollerMessage(midiMessage);
    else
        midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
}

void IncomingNRPNhandler::handleNRPNcontrollerMessage(MidiMessage midiMessage) {
    handleControllerWhichTargetsNRPNtypeMSB(midiMessage);
}

void IncomingNRPNhandler::handleControllerWhichTargetsNRPNtypeMSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnTypeMSB)) {
        nrpnTypeMSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnTypeMSBvalueReceived = true;
    }
    else
        handleControllerWhichTargetsNRPNtypeLSB(midiMessage);
}

void IncomingNRPNhandler::handleControllerWhichTargetsNRPNtypeLSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnTypeLSB)) {
        nrpnTypeLSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnTypeLSBvalueReceived = true;
    }
    else
        handleControllerWhichTargetsNRPNvalueMSB(midiMessage);
}

void IncomingNRPNhandler::handleControllerWhichTargetsNRPNvalueMSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnValueMSB)) {
        nrpnValueMSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnValueMSBvalueReceived = true;
    }
    else
        handleControllerWhichTargetsNRPNvalueLSB(midiMessage);
}

void IncomingNRPNhandler::handleControllerWhichTargetsNRPNvalueLSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(MIDI::nrpnValueLSB)) {
        nrpnValueLSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnValueLSBvalueReceived = true;
    }
}

void IncomingNRPNhandler::applyIncomingNRPNvalueToExposedParameter(int nrpnType, int newValue) {
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
    auto& info{ InfoForExposedParameters::get() };
    auto paramIndex{ info.paramIndexForNRPN((uint8)nrpnType) };
    auto paramID{ info.IDfor(paramIndex) };
    auto normalizedValue{ (float)newValue / (float)info.maxValueFor(paramIndex) };
    exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

void IncomingNRPNhandler::applyIncomingNRPNvalueToUnexposedParameter(int nrpnType, int newValue) {
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
    auto globalOptions{ unexposedParams->globalOptions_get() };
    switch (nrpnType)
    {
    case MIDI::nrpnTypeForGlobalTranspose:
        globalOptions->setGlobalTranspose((uint8)newValue);
        break;
    case MIDI::nrpnTypeForGlobalFineTune:
        globalOptions->setGlobalFineTune((uint8)newValue);
        break;
    default:
        break;
    }
    voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

IncomingNRPNhandler::~IncomingNRPNhandler() {
}
