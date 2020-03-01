#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() : AudioProcessor(BusesProperties())
{
    PublicParameters publicParams;
    apvts.reset(new AudioProcessorValueTreeState(*this, nullptr, ID::publicParams, publicParams.createLayout()));
}

PluginProcessor::~PluginProcessor()
{
}

//==============================================================================
void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ignoreUnused(buffer, midiMessages);
}

//==============================================================================
AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor(*this);
}

//==============================================================================
void PluginProcessor::getStateInformation(MemoryBlock& destData)
{
    ignoreUnused(destData);
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    ignoreUnused(data, sizeInBytes);
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
