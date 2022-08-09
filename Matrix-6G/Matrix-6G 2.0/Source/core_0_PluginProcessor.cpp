#include "core_0_PluginProcessor.h"

#include "core_1_PluginEditor.h"
#include "exposedParameters/ep_3_facade_ExposedParameters.h"

PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties{} },
    exposedParams{ new ExposedParameters{ this/*, unexposedParams.get()*/ } }
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

void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/) {
    buffer.clear();
}

bool PluginProcessor::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const {
    return true;
}

void PluginProcessor::prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/) {
}

double PluginProcessor::getTailLengthSeconds() const {
    return 0.0;
}

void PluginProcessor::releaseResources() {
}

bool PluginProcessor::hasEditor() const {
    return true;
}

AudioProcessorEditor* PluginProcessor::createEditor() {
    return new PluginEditor (*this);
}

void PluginProcessor::getStateInformation(MemoryBlock& /*destData*/) {
}

void PluginProcessor::setStateInformation(const void* /*data*/, int /*sizeInBytes*/) {
    //// You should use this method to restore your parameters from this memory block,
    //// whose contents will have been created by the getStateInformation() call.
}

PluginProcessor::~PluginProcessor() {
    exposedParams->undoManager.clearUndoHistory();
    exposedParams = nullptr;
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}

