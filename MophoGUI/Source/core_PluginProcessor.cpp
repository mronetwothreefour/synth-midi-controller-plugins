#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    exposedParams{ new AudioProcessorValueTreeState(*this, UndoManager_Singleton::get(), "exposedParams", ExposedParametersLayoutFactory::build()) },
    internalMidiBuffers{ new Array<MidiBuffer> },
    midiHandler{ new MidiHandler(exposedParams.get(), internalMidiBuffers.get()) }
{
}

PluginProcessor::~PluginProcessor() {
    midiHandler = nullptr;
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
        for (auto event : internalMidiBuffers->removeAndReturn(0)) {
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

void PluginProcessor::updateProgramNameOnHardware(String newName) {
    midiHandler->updateProgramNameOnHardware(newName);
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
