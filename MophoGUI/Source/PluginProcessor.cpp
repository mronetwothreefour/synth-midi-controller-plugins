#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() : AudioProcessor(BusesProperties())
{
    apvts.reset(new AudioProcessorValueTreeState(*this, nullptr, ID::publicParams, publicParams.createLayout()));
    for (auto* param : getParameters())
        param->addListener(this);
}

PluginProcessor::~PluginProcessor()
{
}

//==============================================================================
void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();

    midiMessages.swapWith(pluginMidiBuf);
    pluginMidiBuf.clear();
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

void PluginProcessor::parameterValueChanged(int parameterIndex, float newValue)
{
    auto numSteps{ getParameters()[parameterIndex]->getNumSteps() };
    auto nrpnIndex{ publicParams.getNRPN(parameterIndex) };
    if (nrpnIndex > -1)
        pluginMidiBuf = MidiRPNGenerator::generate(1, nrpnIndex, roundToInt(newValue * (numSteps - 1)), true, true);
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
