#pragma once

#include <JuceHeader.h>

#include "helpers/helper_Identifiers.h"
#include "parameters/parameters_PublicParametersLayout.h"

//#include "helpers/helper_scratchPad.h"

class PluginProcessor : 
    public AudioProcessor
{
    std::unique_ptr<UndoManager> undoManager{ new UndoManager() };

public:
    std::unique_ptr<AudioProcessorValueTreeState> publicParams;

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
    void setCurrentProgram(int /*index*/) override {}
    const String getProgramName(int /*index*/) override { return {}; }
    void changeProgramName(int /*index*/, const String& /*newName*/) override {}

    //==============================================================================
    bool isBusesLayoutSupported(const BusesLayout& /*layouts*/) const override { return true; }
    void prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/) override {}
    void releaseResources() override {}
    double getTailLengthSeconds() const override { return 0.0; }
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;

    //==============================================================================
    bool hasEditor() const override { return true; }
    AudioProcessorEditor* createEditor() override;

    //==============================================================================
    void getStateInformation(MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

private:

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
