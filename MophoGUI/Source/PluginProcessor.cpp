#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() : AudioProcessor(BusesProperties())
{
    publicParams.reset(new PublicParameters());

    apvts.reset(new AudioProcessorValueTreeState(*this, nullptr, ID::publicParams, publicParams->createLayout()));

    for (auto* param : getParameters()) param->addListener(this);

    privateParams.reset(new PrivateParameters());
}

PluginProcessor::~PluginProcessor()
{
    // midiOutput = nullptr;
    privateParams = nullptr;
    apvts = nullptr;
    publicParams = nullptr;
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
    return new PluginEditor(*this, apvts.get(), privateParams.get());
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
    auto nrpnIndex{ publicParams->getNRPN(parameterIndex) };
    if (nrpnIndex > -1)
    {
        auto outputValue{ roundToInt(newValue * (numSteps - 1)) };

        if (parameterIndex > 104 && parameterIndex < 109) // knob assignment
            if (outputValue > 104) outputValue += 15; // offset to account for unassignable Mopho parameters 105..119

        if (parameterIndex == 95) outputValue += 30; // clock tempo parameter range is offset by 30
        pluginMidiBuf = MidiRPNGenerator::generate(1, nrpnIndex, outputValue, true, true);
    }

    // The arpeggiator (#98) and the sequencer (#100) cannot both be on
    if (parameterIndex == 98 && newValue == 1.0f)
        getParameters()[100]->setValueNotifyingHost(0.0f);
    if (parameterIndex == 100 && newValue == 1.0f)
        getParameters()[98]->setValueNotifyingHost(0.0f);

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
