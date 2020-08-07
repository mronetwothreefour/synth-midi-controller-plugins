#include "midi_IncomingNRPNhandler.h"

#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_UnexposedParameters.h"




IncomingNRPNhandler::IncomingNRPNhandler(AudioProcessorValueTreeState* exposedParams) :
	exposedParams{ exposedParams }
{
}

IncomingNRPNhandler::~IncomingNRPNhandler() {
}

MidiBuffer IncomingNRPNhandler::pullFullyFormedNRPNoutOfBuffer(const MidiBuffer& midiMessages) {
    bool nrpnTypeMSBvalueReceived{ false };
    bool nrpnTypeLSBvalueReceived{ false };
    bool nrpnValueMSBvalueReceived{ false };
    bool nrpnValueLSBvalueReceived{ false };
    auto nrpnTypeMSBvalue{ 0 };
    auto nrpnTypeLSBvalue{ 0 };
    auto nrpnValueMSBvalue{ 0 };
    auto nrpnValueLSBvalue{ 0 };
    MidiBuffer incompleteNRPN;
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto& midiParams{ MidiParameters_Singleton::get() };
        auto midiMessage{ event.getMessage() };
        auto messageChannel{ midiMessage.getChannel() - 1 };
        auto pluginChannel{ midiParams.channel() };
        if (messageChannel != pluginChannel || !messageTargetsOneOfTheNRPNcontrollers(midiMessage))
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        else {
            if (midiMessage.isControllerOfType(nrpnTypeMSB)) {
                nrpnTypeMSBvalue = midiMessage.getControllerValue();
                incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
                nrpnTypeMSBvalueReceived = true;
            }
            if (midiMessage.isControllerOfType(nrpnTypeLSB)) {
                nrpnTypeLSBvalue = midiMessage.getControllerValue();
                incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
                nrpnTypeLSBvalueReceived = true;
            }
            if (midiMessage.isControllerOfType(nrpnValueMSB)) {
                nrpnValueMSBvalue = midiMessage.getControllerValue();
                incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
                nrpnValueMSBvalueReceived = true;
            }
            if (midiMessage.isControllerOfType(nrpnValueLSB)) {
                nrpnValueLSBvalue = midiMessage.getControllerValue();
                incompleteNRPN.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
                nrpnValueLSBvalueReceived = true;
            }
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

bool IncomingNRPNhandler::messageTargetsOneOfTheNRPNcontrollers(MidiMessage midiMessage) {
    if (midiMessage.isControllerOfType(nrpnTypeMSB))
        return true;
    if (midiMessage.isControllerOfType(nrpnTypeLSB))
        return true;
    if (midiMessage.isControllerOfType(nrpnValueMSB))
        return true;
    if (midiMessage.isControllerOfType(nrpnValueLSB))
        return true;
    return false;
}

void IncomingNRPNhandler::applyIncomingNRPNvalueToExposedParameter(int nrpnType, int newValue) {
    auto& midiParams{ MidiParameters_Singleton::get() };
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
