#include "core_PluginProcessor.h"

#include "core_PluginEditor.h"
#include "banksWindow/banks_PluginProgramBanks_Singleton.h"
#include "banksWindow/banks_ProgramNameStrings_Singleton.h"
#include "midiTools/midi_IncomingNRPNhandler.h"
#include "midiTools/midi_IncomingSysExHandler.h"
#include "midiTools/midi_InternalMidiBuffers_Singleton.h"
#include "parameters/params_ExposedParametersLayout.h"
#include "parameters/params_ExposedParametersListener.h"




PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    undoManager{ new UndoManager() },
    exposedParams{ new AudioProcessorValueTreeState(*this, undoManager.get(), "exposedParams", ExposedParametersLayoutFactory::build()) },
    exposedParamsListener{ new ExposedParametersListener(exposedParams.get()) },
    incomingNRPNHandler{ new IncomingNRPNhandler(exposedParams.get()) },
    incomingSysExHandler{ new IncomingSysExHandler(exposedParams.get()) }
{
    PluginProgramBanks::get().resetAllProgramBanksToFactoryDefaults();
    ProgramNameStrings::get().resetAllProgramNameStringsToFactoryDefaults();
}

PluginProcessor::~PluginProcessor() {
    undoManager->clearUndoHistory();
    undoManager = nullptr;
    incomingSysExHandler = nullptr;
    exposedParamsListener = nullptr;
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

    if (!midiMessages.isEmpty()) {
        MidiBuffer midiMessagesToPassThrough;
        midiMessagesToPassThrough = incomingSysExHandler->pullSysExWithMatchingIDOutOfBuffer(midiMessages);
        midiMessagesToPassThrough = incomingNRPNHandler->pullFullyFormedNRPNoutOfBuffer(midiMessagesToPassThrough);
        midiMessages.swapWith(midiMessagesToPassThrough);
    }

    auto& aggregatedBuffers{ InternalMidiBuffers::get().aggregatedBuffers };
    if (!aggregatedBuffers.isEmpty()) {
        for (auto event : aggregatedBuffers.removeAndReturn(0)) {
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

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
