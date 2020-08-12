#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class ExposedParametersListener;
class IncomingNRPNhandler;
class IncomingSysExHandler;

class PluginProcessor : public AudioProcessor
{
    std::unique_ptr<UndoManager> undoManager;
    std::unique_ptr<AudioProcessorValueTreeState> exposedParams;
    std::unique_ptr<OutgoingMidiBuffers> outgoingBuffers;
    std::unique_ptr<ExposedParametersListener> exposedParamsListener;
    std::unique_ptr<IncomingNRPNhandler> incomingNRPNHandler;
    std::unique_ptr<IncomingSysExHandler> incomingSysExHandler;

public:
    PluginProcessor();
    ~PluginProcessor();

    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const String getProgramName(int index) override;
    void changeProgramName(int index, const String& newName) override;

    void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    double getTailLengthSeconds() const override;

    bool hasEditor() const override;
    AudioProcessorEditor* createEditor() override;

public: void getStateInformation(MemoryBlock& destData) override;
private: std::unique_ptr<XmlElement> saveStateToXML();
public: void setStateInformation(const void* data, int sizeInBytes) override;
private: void restoreStateFromXml(XmlElement* sourceXml);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
