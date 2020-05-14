#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor()
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
