#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "midi/midi_IncomingSysExHandler.h"
#include "params/params_ExposedParamsLayout_Factory.h"
#include "params/params_ExposedParametersListener.h"
#include "params/params_UnexposedParameters_Facade.h"



PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    unexposedParams{ new UnexposedParameters() },
    exposedParams{ new AudioProcessorValueTreeState(*this, unexposedParams->undoManager_get(), "exposedParams", ExposedParametersLayoutFactory::build()) },
    exposedParamsListener{ new ExposedParametersListener(exposedParams.get(), unexposedParams.get()) },
    aggregatedOutgoingBuffers{ unexposedParams->aggregatedOutgoingBuffers_get() },
    incomingSysExHandler{ new IncomingSysExHandler(exposedParams.get(), unexposedParams.get()) }
{
}

const juce::String PluginProcessor::getName() const {
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

const juce::String PluginProcessor::getProgramName(int /*index*/) {
    return {};
}

void PluginProcessor::changeProgramName(int /*index*/, const juce::String& /*newName*/) {
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    buffer.clear();

    if (!midiMessages.isEmpty()) {
        MidiBuffer midiMessagesToPassThrough;
        midiMessagesToPassThrough = incomingSysExHandler->pullSysExWithMatchingIDOutOfBuffer(midiMessages);
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

juce::AudioProcessorEditor* PluginProcessor::createEditor() {
    return new PluginEditor(*this, exposedParams.get(), unexposedParams.get());
}

void PluginProcessor::getStateInformation(juce::MemoryBlock& /*destData*/) {
}

void PluginProcessor::setStateInformation(const void* /*data*/, int /*sizeInBytes*/) {
}

PluginProcessor::~PluginProcessor() {
    unexposedParams->undoManager_get()->clearUndoHistory();
    exposedParamsListener = nullptr;
    exposedParams = nullptr;
    unexposedParams = nullptr;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}

