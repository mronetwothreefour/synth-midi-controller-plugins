#include "midi_IncomingNRPNhandler.h"

#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_MidiOptions_Singleton.h"




IncomingNRPNhandler::IncomingNRPNhandler(AudioProcessorValueTreeState* exposedParams) :
	exposedParams{ exposedParams }
{
}

IncomingNRPNhandler::~IncomingNRPNhandler() {
}

MidiBuffer IncomingNRPNhandler::pullFullyFormedNRPNoutOfBuffer(const MidiBuffer& midiMessages) {
    midiMessagesToPassThrough.clear();
    incompleteNRPN.clear();
    for (auto event : midiMessages) {
        auto& midiParams{ MidiOptions::get() };
        auto midiMessage{ event.getMessage() };
        auto messageChannel{ midiMessage.getChannel() - 1 };
        auto pluginChannel{ midiParams.channel() };
        if (midiMessage.isController() && messageChannel == pluginChannel)
            handle_If_MessageTargetsOneOfTheNRPNcontrollers(midiMessage);
        else {
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        }
    }
    if (nrpnTypeMSBvalueReceived && nrpnTypeLSBvalueReceived && nrpnValueMSBvalueReceived && nrpnValueLSBvalueReceived) {
        auto newValue{ nrpnValueMSBvalue + nrpnValueLSBvalue };
        auto nrpnType{ nrpnTypeMSBvalue + nrpnTypeLSBvalue };
        applyIncomingNRPNvalueToExposedParameter(nrpnType, newValue);
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

void IncomingNRPNhandler::handle_If_MessageTargetsOneOfTheNRPNcontrollers(MidiMessage midiMessage) {
    auto controllerType{ midiMessage.getControllerNumber() };
    if (controllerType == nrpnTypeMSB || controllerType == nrpnTypeLSB || controllerType == nrpnValueMSB || controllerType == nrpnValueLSB)
        handleNRPNmessage(midiMessage);
    else
        midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
}

void IncomingNRPNhandler::handleNRPNmessage(MidiMessage midiMessage) {
    handle_if_MessageTargetsNRPNtypeMSB(midiMessage);
}

void IncomingNRPNhandler::handle_if_MessageTargetsNRPNtypeMSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(nrpnTypeMSB)) {
        nrpnTypeMSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnTypeMSBvalueReceived = true;
    }
    else
        handle_if_MessageTargetsNRPNtypeLSB(midiMessage);
}

void IncomingNRPNhandler::handle_if_MessageTargetsNRPNtypeLSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(nrpnTypeLSB)) {
        nrpnTypeLSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnTypeLSBvalueReceived = true;
    }
    else
        handle_if_MessageTargetsNRPNvalueMSB(midiMessage);
}

void IncomingNRPNhandler::handle_if_MessageTargetsNRPNvalueMSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(nrpnValueMSB)) {
        nrpnValueMSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnValueMSBvalueReceived = true;
    }
    else
        handle_if_MessageTargetsNRPNvalueLSB(midiMessage);
}

void IncomingNRPNhandler::handle_if_MessageTargetsNRPNvalueLSB(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(nrpnValueLSB)) {
        nrpnValueLSBvalue = midiMessage.getControllerValue();
        incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        nrpnValueLSBvalueReceived = true;
    }
}

void IncomingNRPNhandler::applyIncomingNRPNvalueToExposedParameter(int nrpnType, int newValue) {
    auto& midiParams{ MidiOptions::get() };
    midiParams.setParamChangeEchosAreBlocked();
    auto& info{ InfoForExposedParameters::get() };
    auto param{ info.indexForNRPN((uint8)nrpnType) };
    if (param != 255) {
        auto paramID{ info.IDfor(param) };
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
    midiParams.setParamChangeEchosAreNotBlocked();
}
