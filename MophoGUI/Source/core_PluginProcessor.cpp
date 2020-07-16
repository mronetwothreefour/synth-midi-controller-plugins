#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    exposedParams{ new AudioProcessorValueTreeState(*this, UndoManager_Singleton::get(), "exposedParams", ExposedParametersLayoutFactory::build()) },
    internalMidiBuffers{ new Array<MidiBuffer> },
    nrpnOutputIsAllowed{ true }
{
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->addParameterListener(info.IDfor(param), this);
}

PluginProcessor::~PluginProcessor() {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
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

void PluginProcessor::getStateInformation(MemoryBlock& destData) {
    auto pluginStateXml{ saveStateToXML() };
    if (pluginStateXml != nullptr)
        copyXmlToBinary(*pluginStateXml, destData);
}

std::unique_ptr<XmlElement> PluginProcessor::saveStateToXML() {
    auto exposedParamsStateTree{ exposedParams->copyState() };
    auto exposedParamsStateXml{ exposedParamsStateTree.createXml() };
    std::unique_ptr<XmlElement> pluginStateXml{ new XmlElement("pluginStateXml") };
    // TODO: code for saving unexposed parameters state
    if (exposedParamsStateXml != nullptr)
        pluginStateXml->addChildElement(exposedParamsStateXml.release());
    return pluginStateXml;
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes) {
    auto pluginStateXml{ getXmlFromBinary(data, sizeInBytes) };
    if (pluginStateXml != nullptr)
        restoreStateFromXml(pluginStateXml.get());
}

void PluginProcessor::restoreStateFromXml(XmlElement* sourceXml) {
    exposedParams->replaceState(ValueTree::fromXml(*sourceXml->getChildElement(0)));
    // TODO: code for restoring unexposed parameters state
}

void PluginProcessor::parameterChanged(const String& parameterID, float newValue) {
    if (nrpnOutputIsAllowed)
    {
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

uint8 PluginProcessor::addAnyParamSpecificOffsetsToOutputValue(uint8 param, uint8 outputValue) {
    if (param > 104 && param < 109 && outputValue > 104) // knob assignment parameters
        outputValue += 15; // offset to account for unassignable Mopho parameters 105..119
    if (param == 95)
        outputValue += 30; // clock tempo parameter range is offset by 30
    return outputValue;
}

void PluginProcessor::addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue) {
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

void PluginProcessor::arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
    if (paramTurnedOn == 98 && getParameters()[100] != nullptr)
        if (getParameters()[100]->getValue() != 0.0f)
            getParameters()[100]->setValueNotifyingHost(0.0f);
    if (paramTurnedOn == 100 && getParameters()[98] != nullptr)
        if (getParameters()[98]->getValue() != 0.0f)
            getParameters()[98]->setValueNotifyingHost(0.0f);
}

void PluginProcessor::combineMidiBuffers(MidiBuffer& midiBuffer) {
    internalMidiBuf.addEvents(midiBuffer, 0, -1, 0);
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
