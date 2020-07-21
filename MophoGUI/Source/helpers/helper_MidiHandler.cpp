#include "helper_MidiHandler.h"

MidiHandler::MidiHandler(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers) :
	exposedParams{ exposedParams },
    internalMidiBuffers{ internalMidiBuffers },
    nrpnOutputIsAllowed{ true },
    nameCharCounter{ 0 },
    millisecondsBtwnParamChanges{ 10 },
    programName{ "Basic Patch     " }
{
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->addParameterListener(info.IDfor(param), this);
}

MidiHandler::~MidiHandler() {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->removeParameterListener(info.IDfor(param), this);
}

void MidiHandler::updateProgramNameOnHardware(String newName) {
    programName = newName;
    nameCharCounter = 0;
    MultiTimer::startTimer(pgmNameTimer, millisecondsBtwnParamChanges);
}

void MidiHandler::parameterChanged(const String& parameterID, float newValue) {
    if (nrpnOutputIsAllowed) {
        auto& info{ InfoForExposedParameters::get() };
        auto param{ info.indexFor(parameterID) };
        auto nrpn{ info.NRPNfor(param) };
        auto outputValue{ (uint8)roundToInt(newValue) };
        outputValue = addAnyParamSpecificOffsetsToOutputValue(param, outputValue);
        addParamChangedMessageToMidiBuffer(nrpn, outputValue);
        if ((param == 98 || param == 100) && outputValue == 1)
            arpeggiatorAndSequencerCannotBothBeOn(param);
    }
    else return;
}

uint8 MidiHandler::addAnyParamSpecificOffsetsToOutputValue(uint8 param, uint8 outputValue) {
    if (param == 95)
        outputValue += 30; // clock tempo parameter range is offset by 30
    if (param > 104 && param < 109 && outputValue > 104) // knob assignment parameters
        outputValue += 15; // offset to account for unassignable Mopho parameters 105..119
    return outputValue;
}

void MidiHandler::addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue) {
    // Send MIDI channel change messages out on all channels
    if (paramNRPN == 386) {
        for (uint8 midiChannel = 0; midiChannel != 16; ++midiChannel) {
            auto nrpnBuffer{ NRPNbufferWithLeadingMSBsGenerator::generateFrom_NRPNindex_NewValue_andChannel(paramNRPN, newValue, midiChannel) };
            combineMidiBuffers(nrpnBuffer);
        }
    }
    else {
        // TODO: get current MIDI channel from global options
        auto midiChannel{ (uint8)1 };
        auto nrpnBuffer{ NRPNbufferWithLeadingMSBsGenerator::generateFrom_NRPNindex_NewValue_andChannel(paramNRPN, newValue, midiChannel) };
        combineMidiBuffers(nrpnBuffer);
    }
}

void MidiHandler::arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
    auto& info{ InfoForExposedParameters::get() };
    auto arpegParam{ exposedParams->getParameter(info.IDfor(98)) };
    auto sequencerParam{ exposedParams->getParameter(info.IDfor(100)) };
    if (paramTurnedOn == 98 && sequencerParam != nullptr)
        if (sequencerParam->getValue() != 0.0f)
            sequencerParam->setValueNotifyingHost(0.0f);
    if (paramTurnedOn == 100 && arpegParam != nullptr)
        if (arpegParam->getValue() != 0.0f)
            arpegParam->setValueNotifyingHost(0.0f);
}

void MidiHandler::combineMidiBuffers(MidiBuffer& midiBuffer) {
    internalMidiBuffer.addEvents(midiBuffer, 0, -1, 0);
    if (!isTimerRunning(midiBufferTimer)) {
        internalMidiBuffers->add(internalMidiBuffer);
        internalMidiBuffer.clear();
        startTimer(midiBufferTimer, 10);
    }
}

void MidiHandler::timerCallback(int timerID) {
    stopTimer(timerID);

    if (timerID == pgmNameTimer) {
        // convert nameChar's ASCII value (0..127) to a normalized value (0.0f..1.0f)
        auto normalizedValue{ (char)programName[nameCharCounter] / 127.0f };
        auto param{ exposedParams->getParameter("nameChar" + (String)(nameCharCounter + 1)) };
        if (param != nullptr)
            param->setValueNotifyingHost(normalizedValue);
        if (nameCharCounter < 16) {
            ++nameCharCounter;
            startTimer(pgmNameTimer, millisecondsBtwnParamChanges);
        }
        else
            nameCharCounter = 0;
    }
}
