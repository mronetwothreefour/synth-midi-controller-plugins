#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "exposedParameters/ep_build_ExposedParamsLayout.h"
#include "unexposedParameters/up_facade_UnexposedParameters.h"


PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    unexposedParams{ new UnexposedParameters() },
    exposedParams{ new AudioProcessorValueTreeState(*this, unexposedParams->getUndoManager(), "exposedParams", ExposedParametersLayout::build()) },
    bundledOutgoingBuffers{ unexposedParams->getBundledOutgoingBuffers() }
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

    if (!bundledOutgoingBuffers->isEmpty()) {
        for (auto event : bundledOutgoingBuffers->removeAndReturn(0)) {
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

void PluginProcessor::getStateInformation(MemoryBlock& /*destData*/) {
}

void PluginProcessor::setStateInformation(const void* /*data*/, int /*sizeInBytes*/) {
}

PluginProcessor::~PluginProcessor() {
    unexposedParams->getUndoManager()->clearUndoHistory();
    exposedParams = nullptr;
    unexposedParams = nullptr;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}

