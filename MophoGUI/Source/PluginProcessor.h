#pragma once

#include <JuceHeader.h>

#include "helpers/Identifiers.h"

#include "parameters/PublicParameters.h"
#include "parameters/PrivateParameters.h"

class PluginProcessor : 
    public AudioProcessor,
    public AudioProcessorParameter::Listener
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

    //==============================================================================
    void parameterValueChanged(int parameterIndex, float newValue) override;
    void parameterGestureChanged(int /*parameterIndex*/, bool /*gestureIsStarting*/) override {}

    //==============================================================================
    // Sends a SysEx message to the hardware requesting a dump of the
    // parameter data currently in the Mopho's program edit buffer
    void sendEditBufferDumpRequest();

private:
    std::unique_ptr<AudioProcessorValueTreeState> apvts;

    std::unique_ptr<PublicParameters> publicParams;

    std::unique_ptr<PrivateParameters> privateParams;

    MidiBuffer pluginMidiBuf;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};

