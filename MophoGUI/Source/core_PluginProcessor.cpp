#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties() },
    publicParams{ new AudioProcessorValueTreeState(*this, nullptr, ID::publicParams, PublicParametersLayout::get()) }
{
}

PluginProcessor::~PluginProcessor()
{
}

//==============================================================================
void PluginProcessor::processBlock(AudioBuffer<float>& /* buffer */, MidiBuffer& /* midiMessages */)
{
}

//==============================================================================
AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor(*this);
}

//==============================================================================
void PluginProcessor::getStateInformation(MemoryBlock& /* destData */)
{
}

void PluginProcessor::setStateInformation(const void* /* data */, int /* sizeInBytes */)
{
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
