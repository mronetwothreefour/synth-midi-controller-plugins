#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    exposedParams{ new AudioProcessorValueTreeState(*this, UndoManager_Singleton::get(), "exposedParams", ExposedParametersLayoutFactory::build()) },
    internalMidiBuffers{ new Array<MidiBuffer> },
    nrpnOutputIsAllowed{ true }
{
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.numberOfExposedParameters(); ++param)
        exposedParams->addParameterListener(info.IDfor(param), this);
}

PluginProcessor::~PluginProcessor() {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.numberOfExposedParameters(); ++param)
        exposedParams->removeParameterListener(info.IDfor(param), this);
    internalMidiBuffers = nullptr;
    auto undoManager{ UndoManager_Singleton::get() };
    undoManager->clearUndoHistory();
    exposedParams = nullptr;
}

const String PluginProcessor::getName() const {
    return JucePlugin_Name;
}

bool PluginProcessor::acceptsMidi() const {
    return true;
}

bool PluginProcessor::producesMidi() const {
    return true;
}

bool PluginProcessor::isMidiEffect() const {
    return true;
}

int PluginProcessor::getNumPrograms() {
    return 1;
}

int PluginProcessor::getCurrentProgram() {
    return 0;
}

void PluginProcessor::setCurrentProgram(int /*index*/) {
}

const String PluginProcessor::getProgramName(int /*index*/) {
    return {};
}

void PluginProcessor::changeProgramName(int /*index*/, const String& /*newName*/) {
}

void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
    buffer.clear();

    // Handle incoming MIDI messages
    if (!midiMessages.isEmpty()) {
        for (auto event : midiMessages) {
            // TODO : code for handling incoming sysex messages
        }
    }

    // Add internally-generated MIDI messages to output stream
    if (!internalMidiBuffers->isEmpty()) {
        auto internalMidiBuffer{ internalMidiBuffers->removeAndReturn(0) };
        for (auto event : internalMidiBuffer) {
            midiMessages.addEvent(event.getMessage(), event.samplePosition);
        }
    }
}

bool PluginProcessor::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const {
    return true;
}

void PluginProcessor::prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/) {
}

void PluginProcessor::releaseResources() {
}

double PluginProcessor::getTailLengthSeconds() const {
    return 0.0;
}

bool PluginProcessor::hasEditor() const {
    return true;
}

AudioProcessorEditor* PluginProcessor::createEditor() {
    return new PluginEditor(*this, exposedParams.get());
}

void PluginProcessor::getStateInformation(MemoryBlock& /* destData */) {
}

void PluginProcessor::setStateInformation(const void* /* data */, int /* sizeInBytes */) {
}

void PluginProcessor::parameterChanged(const String& parameterID, float newValue) {
    if (nrpnOutputIsAllowed)
    {
        auto& info{ InfoForExposedParameters::get() };
        auto param{ info.getIndexFor(parameterID) };
        auto nrpn{ info.NRPNfor(param) };
        auto outputValue{ (uint8)roundToInt(newValue) };
        if (param > 104 && param < 109 && outputValue > 104) // knob assignment
            outputValue += 15; // offset to account for unassignable Mopho parameters 105..119
        if (param == 95)
            outputValue += 30; // clock tempo parameter range is offset by 30
        addNRPNmessageBuffer(nrpn, (uint8)outputValue);
        // The arpeggiator (#98) and the sequencer (#100) cannot both be on
        if (param == 98 && newValue == 1.0f && getParameters()[100]->getValue() != 0.0f)
            getParameters()[100]->setValueNotifyingHost(0.0f);
        if (param == 100 && newValue == 1.0f && getParameters()[98]->getValue() != 0.0f)
            getParameters()[98]->setValueNotifyingHost(0.0f);
    }
    else return;
}

void PluginProcessor::addNRPNmessageBuffer(uint16 nrpn, uint8 newValue) {
    MidiBuffer nrpnMessageBuf;

    if (nrpn == 386) // Send MIDI channel change messages out on all channels
    {
        for (auto i = 0; i != 16; ++i)
        {
            auto firstByte{ 176 + i };
            MidiMessage nrpnIndexMSB{ firstByte, 99, nrpn / 128 };
            nrpnMessageBuf.addEvent(nrpnIndexMSB, 0);
            MidiMessage nrpnIndexLSB{ firstByte, 98, nrpn % 128 };
            nrpnMessageBuf.addEvent(nrpnIndexLSB, 0);
            MidiMessage nrpnValueMSB{ firstByte, 6, newValue / 128 };
            nrpnMessageBuf.addEvent(nrpnValueMSB, 0);
            MidiMessage nrpnValueLSB{ firstByte, 38, newValue % 128 };
            nrpnMessageBuf.addEvent(nrpnValueLSB, 0);
            internalMidiBuf.addEvents(nrpnMessageBuf, 0, -1, 0);
        }
    }
    else
    {
        auto midiChannel{ 1 };
        if (midiChannel > 0) midiChannel -= 1;
        auto firstByte{ 176 + midiChannel };
        MidiMessage nrpnIndexMSB{ firstByte, 99, nrpn / 128 };
        nrpnMessageBuf.addEvent(nrpnIndexMSB, 0);
        MidiMessage nrpnIndexLSB{ firstByte, 98, nrpn % 128 };
        nrpnMessageBuf.addEvent(nrpnIndexLSB, 0);
        MidiMessage nrpnValueMSB{ firstByte, 6, newValue / 128 };
        nrpnMessageBuf.addEvent(nrpnValueMSB, 0);
        MidiMessage nrpnValueLSB{ firstByte, 38, newValue % 128 };
        nrpnMessageBuf.addEvent(nrpnValueLSB, 0);
        internalMidiBuf.addEvents(nrpnMessageBuf, 0, -1, 0);
    }
    if (!isTimerRunning()) {
        internalMidiBuffers->add(internalMidiBuf);
        internalMidiBuf.clear();
        startTimer(10);
    }
}

void PluginProcessor::timerCallback() {
    stopTimer();
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
