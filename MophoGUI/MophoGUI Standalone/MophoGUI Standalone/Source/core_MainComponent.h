#pragma once

#include <JuceHeader.h>



class MainComponent :
    public AudioAppComponent,
    public MidiInputCallback
{
public:
    MainComponent();

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    void handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message) override;
    void paint (juce::Graphics& g) override;
    void resized() override;
    ~MainComponent() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};