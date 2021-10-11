/*
=============================================================================
 THE CODE FOR MATRIX-6G IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL
 WARRANTIES, WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND
 FITNESS FOR PURPOSE, ARE DISCLAIMED.
=============================================================================

The code in the Source folder of this project is open-source and you are free
to use it however you see fit under the GPL v3 license. However, please credit
Mister 1-2-3-4 Programming if you make use of substantial chunks of this code
in your own project(s), and do not redistribute it without permission. Also,
if you find this code useful, please consider making a donation to support
further development at https://programming.mr1234.com/

Proper functioning of this plugin required a few unofficial modifications
to the Juce framework code, specifically to line 91 of juce_PopupMenu.cpp and
to lines 548 & 549 of juce_VST3Common.h. You can see these changes in my
fork off of the Juce repo at https://github.com/mronetwothreefour/JUCE

The build configurations make use of the preprocessor definition
HOST_DOES_NOT_ADD_F0_AND_F7. This needs to be true for the plugin to work
properly in Reaper, and false for the plugin to work properly in Juce's
AudioPluginHost. Either version will function properly in Cubase. These
are the only hosts known to be compatible with Matrix-6G.vst3 at this time.
*/

#pragma once

#include <JuceHeader.h>



class ExposedParametersListener;
class IncomingSysExHandler;
class UnexposedParameters;

class PluginProcessor : public juce::AudioProcessor
{
    std::unique_ptr<UnexposedParameters> unexposedParams;
    std::unique_ptr<AudioProcessorValueTreeState> exposedParams;
    std::unique_ptr<ExposedParametersListener> exposedParamsListener;
    Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers;
    std::unique_ptr<IncomingSysExHandler> incomingSysExHandler;
    std::unique_ptr<XmlElement> pluginStateXml;

public:
    PluginProcessor();

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    double getTailLengthSeconds() const override;

    bool hasEditor() const override;
    juce::AudioProcessorEditor* createEditor() override;

    void getStateInformation(juce::MemoryBlock& destData) override;

private:
    void createPluginStateXml();

public:
    void setStateInformation(const void* data, int sizeInBytes) override;

private:
    void restorePluginStateFromXml(XmlElement* sourceXml);

public:
    ~PluginProcessor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
