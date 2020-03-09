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
    // midiOutput = nullptr;

    apvts = nullptr;
}

//==============================================================================
void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();

    midiMessages.swapWith(pluginMidiBuf); // use when LegacyMidiOutEvent
    pluginMidiBuf.clear();                // is supported
}

//==============================================================================
AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor(*this, apvts.get());
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

    //auto deviceIdentifier{ MidiOutput::getAvailableDevices()[1].identifier };
    //midiOutput = MidiOutput::openDevice(deviceIdentifier);
    //if (midiOutput != nullptr)
    //    midiOutput->sendBlockOfMessagesNow(pluginMidiBuf);
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
