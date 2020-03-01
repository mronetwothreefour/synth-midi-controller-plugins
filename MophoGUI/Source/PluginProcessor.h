#pragma once

#include <JuceHeader.h>

#include "helpers/Identifiers.h"

#include "parameters/PublicParameters.h"

class PluginProcessor : public AudioProcessor
{
public:
    PluginProcessor();
    ~PluginProcessor();

    //==============================================================================
    const String getName() const override { return JucePlugin_Name; }

    //==============================================================================
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return true; }
    bool isMidiEffect() const override { return true; }
    
    //==============================================================================
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int index) override { ignoreUnused(index); }
    const String getProgramName(int index) override { ignoreUnused(index); return {}; }
    void changeProgramName(int index, const String& newName) override { ignoreUnused(index, newName); }

    //==============================================================================
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override { ignoreUnused(layouts); return true; }
    void prepareToPlay(double sampleRate, int samplesPerBlock) override { ignoreUnused(sampleRate, samplesPerBlock); }
    void releaseResources() override {}
    double getTailLengthSeconds() const override { return 0.0; }
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    bool hasEditor() const override { return true; }
    AudioProcessorEditor* createEditor() override;

    //==============================================================================
    void getStateInformation(MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

private:
    std::unique_ptr<AudioProcessorValueTreeState> apvts;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};

