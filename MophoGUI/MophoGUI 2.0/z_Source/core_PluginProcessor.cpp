#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "midi/midi_IncomingNRPNhandler.h"
#include "midi/midi_IncomingSysExHandler.h"
#include "params/params_ExposedParamsLayout_Factory.h"
#include "params/params_ExposedParametersListener.h"
#include "params/params_Identifiers.h"
#include "params/params_UnexposedParameters_Facade.h"



PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    exposedParams{ new AudioProcessorValueTreeState(*this, unexposedParams->undoManager_get(), "exposedParams", ExposedParametersLayoutFactory::build()) },
    exposedParamsListener{ new ExposedParametersListener(exposedParams.get(), unexposedParams.get()) },
    unexposedParams{ new UnexposedParameters() },
    aggregatedOutgoingBuffers{ unexposedParams->aggregatedOutgoingBuffers_get() },
    incomingNRPNhandler{ new IncomingNRPNhandler(exposedParams.get(), unexposedParams.get()) },
    incomingSysExHandler{ new IncomingSysExHandler(exposedParams.get(), unexposedParams.get()) }
{
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
        midiMessagesToPassThrough = incomingNRPNhandler->pullFullyFormedNRPNmessageOutOfBuffer(midiMessagesToPassThrough);
        midiMessages.swapWith(midiMessagesToPassThrough);
    }

    if (!aggregatedOutgoingBuffers->isEmpty()) {
        for (auto event : aggregatedOutgoingBuffers->removeAndReturn(0)) {
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
    return new PluginEditor(*this, exposedParams.get(), unexposedParams.get());
}

void PluginProcessor::getStateInformation(MemoryBlock& destData) {
    createPluginStateXml();
    if (pluginStateXml != nullptr)
        copyXmlToBinary(*pluginStateXml, destData);
}

void PluginProcessor::createPluginStateXml() {
    auto exposedParamsStateTree{ exposedParams->copyState() };
    auto exposedParamsStateXml{ exposedParamsStateTree.createXml() };
    exposedParamsStateXml->setTagName(ID::state_ExposedParams.toString());
    auto unexposedParamsStateXml{ std::make_unique<XmlElement>(unexposedParams->getStateXml()) };
    pluginStateXml.reset(new XmlElement(ID::state_PluginState));
    if (exposedParamsStateXml != nullptr)
        pluginStateXml->addChildElement(exposedParamsStateXml.release());
    if (unexposedParamsStateXml != nullptr)
        pluginStateXml->addChildElement(unexposedParamsStateXml.release());
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes) {
    pluginStateXml = getXmlFromBinary(data, sizeInBytes);
    if (pluginStateXml != nullptr)
        restorePluginStateFromXml(pluginStateXml.get());
}

void PluginProcessor::restorePluginStateFromXml(XmlElement* sourceXml) {
    auto exposedParamsStateXml{ sourceXml->getChildByName(ID::state_ExposedParams.toString()) };
    if (exposedParamsStateXml != nullptr) {
        auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
        voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
        auto exposedParamsStateTree{ ValueTree::fromXml(*exposedParamsStateXml) };
        exposedParams->replaceState(exposedParamsStateTree);
        voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
    }
    auto unexposedParamsStateXml{ sourceXml->getChildByName(ID::state_UnexposedParams.toString()) };
    if (unexposedParamsStateXml != nullptr) {
        auto unexposedParamsStateTree{ ValueTree::fromXml(*unexposedParamsStateXml) };
        unexposedParams->replaceState(unexposedParamsStateTree);
    }
}

PluginProcessor::~PluginProcessor() {
    pluginStateXml = nullptr;
    unexposedParams->undoManager_get()->clearUndoHistory();
    incomingSysExHandler = nullptr;
    incomingNRPNhandler = nullptr;
    exposedParamsListener = nullptr;
    exposedParams = nullptr;
    unexposedParams = nullptr;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}

