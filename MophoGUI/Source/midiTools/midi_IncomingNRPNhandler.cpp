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
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (!messageTargetsOneOfTheNRPNcontrollers(midiMessage))
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
        else {
            if (midiMessage.isControllerOfType(nrpnTypeMSB)) {
                nrpnTypeMSBvalue = midiMessage.getControllerValue();
                nrpnTypeMSBvalueReceived = true;
            }
            if (midiMessage.isControllerOfType(nrpnTypeLSB)) {
                nrpnTypeLSBvalue = midiMessage.getControllerValue();
                nrpnTypeLSBvalueReceived = true;
            }
            if (midiMessage.isControllerOfType(nrpnValueMSB)) {
                nrpnValueMSBvalue = midiMessage.getControllerValue();
                nrpnValueMSBvalueReceived = true;
            }
            if (midiMessage.isControllerOfType(nrpnValueLSB)) {
                nrpnValueLSBvalue = midiMessage.getControllerValue();
                nrpnValueLSBvalueReceived = true;
            }
        }
        if (nrpnTypeMSBvalueReceived && nrpnTypeLSBvalueReceived && nrpnValueMSBvalueReceived && nrpnValueLSBvalueReceived) {
            auto newValue{ nrpnValueMSBvalue + nrpnValueLSBvalue };
            auto nrpnType{ nrpnTypeMSBvalue + nrpnTypeLSBvalue };
            applyIncomingNRPNvalueToExposedParameter(nrpnType, newValue);
            nrpnTypeMSBvalueReceived = false;
            nrpnTypeLSBvalueReceived = false;
            nrpnValueMSBvalueReceived = false;
            nrpnValueLSBvalueReceived = false;
        }
    }
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
