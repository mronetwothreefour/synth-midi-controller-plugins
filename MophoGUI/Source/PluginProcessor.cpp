#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor()
{
    PublicParameters publicParams;
    apvts.reset(new AudioProcessorValueTreeState(*this, nullptr, Identifier{ "publicParams" }, publicParams.createLayout()));
}

PluginProcessor::~PluginProcessor()
{
}

//==============================================================================
const String PluginProcessor::getName() const
{
    return JucePlugin_Name;
}

//==============================================================================
bool PluginProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PluginProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PluginProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

//==============================================================================
int PluginProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PluginProcessor::getCurrentProgram()
{
    return 0;
}

void PluginProcessor::setCurrentProgram(int index)
{
    ignoreUnused(index);
}

const String PluginProcessor::getProgramName(int index)
{
    ignoreUnused(index);
    return {};
}

void PluginProcessor::changeProgramName(int index, const String& newName)
{
    ignoreUnused(index, newName);
}

//==============================================================================
void PluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    ignoreUnused(sampleRate, samplesPerBlock);
}

void PluginProcessor::releaseResources()
{
}

double PluginProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ignoreUnused(buffer, midiMessages);
}

//==============================================================================
bool PluginProcessor::hasEditor() const
{
    return true;
}

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
