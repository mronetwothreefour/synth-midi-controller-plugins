#pragma once

#include <JuceHeader.h>



class ExposedParametersListener;
class IncomingNRPNhandler;
class IncomingSysExHandler;
class UnexposedParameters;

class PluginProcessor : public AudioProcessor
{
    std::unique_ptr<UnexposedParameters> unexposedParams;
    std::unique_ptr<AudioProcessorValueTreeState> exposedParams;
    std::unique_ptr<ExposedParametersListener> exposedParamsListener;
    Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers;
    std::unique_ptr<IncomingNRPNhandler> incomingNRPNhandler;
    std::unique_ptr<IncomingSysExHandler> incomingSysExHandler;
    std::unique_ptr<XmlElement> pluginStateXml;

public:
    PluginProcessor();

    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const String getProgramName(int index) override;
    void changeProgramName(int index, const String& newName) override;

    void processBlock(AudioBuffer<float>&, MidiBuffer&) override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    double getTailLengthSeconds() const override;

    bool hasEditor() const override;
    AudioProcessorEditor* createEditor() override;

    void getStateInformation(MemoryBlock& destData) override;

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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginProcessor)
};
